/**
 *	@file	Helper.cpp
 * 	@brief 	Helper class implementation file
 * 	@author	Alexis ROLLAND
 * 	@date	2023-01
 * 
 */
#include "Helper.hpp"
//----------------------------------------------------------------------
std::vector<SignalPoint> DummyHelper::compute(const ComputeParameters &SimulParameters) const noexcept{
	std::vector<SignalPoint> locSignal{};
	SignalPoint	Point{};
	
	float 	dt = (SimulParameters.tStop - SimulParameters.tStart) / static_cast<float>(SimulParameters.nbPoints);	/**< Simulation Step		*/
	
	for (unsigned int t=0 ; t < SimulParameters.nbPoints ; ++t){
		Point.tn = SimulParameters.tStart + (static_cast<float>(t) * dt);
		Point.sig_tn = this->getValue();
		locSignal.push_back(Point);
	}
		
	return locSignal;
}
//----------------------------------------------------------------------
//----------------------------------------------------------------------

