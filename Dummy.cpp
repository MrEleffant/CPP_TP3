#include "Dummy.hpp"


//----------------------------------------------------------------------
void	Dummy::compute() const noexcept{
	
	// Creates Helper, then calls the do_compute method
	DummyHelper myHelper{this->Parameters};
	
	this->tabSignal = myHelper.do_compute(this->SimulParams);
}
//----------------------------------------------------------------------

