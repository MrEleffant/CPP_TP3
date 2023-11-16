
#include "Sinus.h"

//----------------------------------------------------------------------
Sinus::Sinus(const SinusParam &SinusParameters, const ComputeParameters &SimulParameters):SimulParams{SimulParameters},Parameters{SinusParameters}{
    if ( this->getOmega() < 0) throw std::domain_error("Omega can’t be negative.") ;
    if ( (this->getPhi0() < (-2*pi)) || (this->getPhi0() > (2*pi)) ) throw std::domain_error("Initial phi0 can’t be outside bounds.");
    if ( this->gettStart() < 0) throw std::domain_error("tStart can't be negative.");
    if ( this->gettStop() <= 0) throw std::domain_error("tStop can’t be negative or null.");
    if ( this->gettStart() >= this->gettStop() ) throw std::overflow_error("tStart can’t be greater or equal than tStop.");
    if ( this->getNbPoints() == 0) throw std::invalid_argument("nbPoints must be greater than 0.");
}
void Sinus::compute() const noexcept{
    SinusHelper help{this->Parameters};

    this->tabSignal = help.do_compute(this->SimulParams);
}
//----------------------------------------------------------------------

//----------------------------------------------------------------------

//----------------------------------------------------------------------


//----------------------------------------------------------------------

//----------------------------------------------------------------------

//----------------------------------------------------------------------