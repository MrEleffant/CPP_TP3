/**
 *	@file	Helper.hpp
 * 	@brief 	Helper class header file
 * 	@author	Alexis ROLLAND
 * 	@date	2023-01
 * 
 */
#ifndef	__HELPER_H__
#define	__HELPER_H__

#include <vector>
#include <stdexcept>

#include "types.h"

/**
 * Class Helper
 * 
 * 	Abstract class - cannot be instanciated directly 
 *  Can be considered as an interface
 */
class	Helper{
	private:
		/**
		 *	compute method
		 * 		pure virtual (virtual AND =0)
		 * 		This will be the only computation method
		 * 
		 * 	const : callable with a const object  
		 * 	noexcept : this method throws no exception
		 * 	
		 *	@param[in] ComputeParameters &SimulParameters : reference to the simulation parameters (ComputeParameters structure)
		 * 
		 * 	@return SignalPoint vector, filled with the calculated data points 
		 * 
		 */
		[[nodiscard]] virtual std::vector<SignalPoint> compute(const ComputeParameters &SimulParameters) const noexcept = 0;
	public:
		/**
		 *	Ctor & Dtor, default versions
		 */
		Helper() = default;
		virtual ~Helper() = default;
		
		/**
		 * do_compute
		 * 		Public interface to the virtual compute method
		 * 		cf guideline #? : No virtual public member function
		 * 
		 * 	const : callable with a const object  
		 * 	noexcept : this method throws no exception
		 * 	[[nodiscard]] : the return value should not be discarded (compiler warning)
		 * 	
		 *	@param[in] ComputeParameters &SimulParameters : reference to the simulation parameters (ComputeParameters structure)
		 * 
		 * 	@return SignalPoint vector, filled with the calculated data points 
		 */
		std::vector<SignalPoint> do_compute(const ComputeParameters &SimulParameters) const noexcept{return this->compute(SimulParameters);};
	
};

/**
 * Class DummyHelper
 * 
 * 	Concrete class - implements the Helper Interface 
 */
class	DummyHelper:public Helper{
	private:
		DummyParam Parameters{};		/**<	Signal (Dummy) parameters. For a Dummy signal, only one : value */
		/**
		 * 	getValue()
		 * 		Accessor (must be private) for the value parameter (inside the DummyParam structure)
		 * 
		 * 	const : callable with a const object  
		 * 	noexcept : this method throws no exception
		 * 	[[nodiscard]] : the return value should not be discarded (compiler warning)
		 * 
		 * 	@return : float, the value of the "value" parameter
		 **/
		[[nodiscard]]	float 	getValue() const noexcept {return this->Parameters.value;};
			 
		/**
		 *	compute method
		 * 		Implementation of the pure virtual method
		 * 		This is the only computation method
		 * 
		 * 	const : callable with a const object  
		 * 	noexcept : this method throws no exception
		 * 	[[nodiscard]] : the return value should not be discarded (compiler warning)
		 * 	
		 *	@param[in] ComputeParameters &SimulParameters : reference to the simulation parameters (ComputeParameters structure)
		 * 
		 * 	@return SignalPoint vector, filled with the calculated data points 
		 * 
		 */ 
		[[nodiscard]] virtual	std::vector<SignalPoint> compute(const ComputeParameters &SimulParameters) const noexcept;
	public:
		/**
		 * Default constructor (no params) explicitly DELETED - This avoids construction of Dummy Signal without parameter 
		 * Default destructor
		 */
		DummyHelper() = delete;	
		virtual ~DummyHelper() = default;
		
		/**
		 * 	Contructor with parameter
		 * 
		 *	explicit : Force to use explicitly a DummyParam typed parameter. Avoids implicit conversions between types 
		 * 				cf C++ Core Guidelines C.46 
		 * 
		 * 	@param[in] DummyParam &Params :  Reference to a Dummy Signal parameter (DummyParam) structure.
		 */
		explicit DummyHelper(const DummyParam &Params):Parameters{Params}{};
};


#endif	/* __HELPER_H__ */
