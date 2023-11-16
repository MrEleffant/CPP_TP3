
#include "Signal.hpp"
//----------------------------------------------------------------------
Signal::Signal(const ComputeParameters &param):SimulParams{param}{
	if (this->gettStart() < 0) throw std::domain_error("tStart can't be negative.");
	if (this->gettStart() >= this->gettStop() ) throw std::overflow_error("tStart can’t be greater or equal than tStop.");
	if (this->gettStop() <= 0) throw std::domain_error("tStop can’t be negative or null.");
	if (this->getNbPoints() == 0) throw std::invalid_argument("nbPoints must be greater than 0.");
}
//----------------------------------------------------------------------
void	Signal::settStart(float _tStart){
	if (_tStart < 0) throw std::domain_error("tStart can't be negative.");
	if (_tStart >= this->gettStop() ) throw std::overflow_error("tStart can’t be greater or equal than tStop.");
	
	this->SimulParams.tStart = _tStart;
	setNeedToRecompute(true);
}
//----------------------------------------------------------------------
void	Signal::settStop(float _tStop){
	if (_tStop <= 0) throw std::domain_error("tStop can’t be negative or null.");
	if (_tStop <= this->gettStart()) throw std::underflow_error("tStop can’t be lesser than tStart.");
	this->SimulParams.tStop = _tStop;
	setNeedToRecompute(true);
}
//----------------------------------------------------------------------
//----------------------------------------------------------------------
unsigned int	Signal::generate(const std::filesystem::path FileName)const{
	if (this->getNeedToRecompute() == true){
		this->compute();
		setNeedToRecompute(false);
	}
	
	// Write to the data file (throws an exception if fails)
	std::ofstream datafile;
	datafile.exceptions ( std::ofstream::failbit | std::ofstream::badbit );
	datafile.open(FileName, std::ofstream::out);
	
	for (unsigned int i=0 ; i<this->getNbPoints() ; ++i){
		SignalPoint	Point = this->tabSignal.at(i);
		std::string data_line = std::to_string(Point.tn)+" "+std::to_string(Point.sig_tn)+"\n";
		datafile << data_line;
	} 
	
	datafile.close();	// Not needed because std::ofstream is an RAII object, but cleaner
	
	return std::filesystem::file_size(FileName);
}
//----------------------------------------------------------------------
//----------------------------------------------------------------------
//----------------------------------------------------------------------
//----------------------------------------------------------------------

