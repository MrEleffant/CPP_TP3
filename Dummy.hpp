/**
 *	@file	Dummy.hpp
 * 	@brief 	"Dummy" class header file - Specializes Signal class
 * 	@details A "Dummy" signal is a simple continous signal.
 * 	@author	Alexis ROLLAND
 * 	@date	2023-01
 * 
 */
#ifndef __DUMMY_H__
#define	__DUMMY_H__

#include "Signal.hpp"
#include "Helper.hpp"

constexpr	float 	DummydefaultValue = 3.3;		/**< Default Value of signal	*/

/**
 * Class Dummy
 * 
 * 	Concrete Singal class - Specializes the Signal class 
 */
class Dummy:public Signal{
	private:
		DummyParam Parameters{DummydefaultValue};	/**< 	Signal Parameters 	(only one for dummy signal : value	*/
		
		/**
		 *	"compute" method
		 * 		Implementation of the pure virtual method
		 * 
		 * 	const : callable with a const object  
		 * 	noexcept : this method throws no exception
		 * 
		 */
		virtual	void	compute() const noexcept;
		
	public:
		/**
		 *	Ctor & Dtor, default versions
		 * 
		 * Default Ctor is the default compiler generated one
		 * Dtor is the default one
		 * 
		 */
		Dummy()	= default ;				
		virtual ~Dummy() = default;				
		
		/**
		 * 	Constructor with Signal parameters 
		 * 
		 * 	@param[in]	Parameter(s) of the dummy signal to create
		 * 
		 * 	noexcept : this method throws no exception 
		 *  explicit : 	the given parameter MUST match the expected
		 * 				parameter. This avoids unintended concversions.
		 * 				cf C++ Core Guidelines C.46 
		 */
		explicit Dummy(const DummyParam &sParam)noexcept:Parameters{sParam}{};	
			
		/**
		 * 	Constructor with Compute parameters 
		 * 
		 * 	@param[in]	Compute Parameter(s) of the dummy signal to create
		 * 
		 * 	explicit : 	the given parameter MUST match the expected
		 * 				parameter. This avoids unintended conversions.
		 * 				cf C++ Core Guidelines C.46 
		 * 
		 * @throw 	std::domain_error("tStart can't be negative.") if the given parameter is negative.
		 * @throw 	std::overflow_error("tStart can’t be greater or equal than tStop.") if the given parameter is >= than tStop.
		 * @throw 	std::domain_error("tStop can’t be negative or null.") if the given parameter is negative or nul.
		 * @throw 	td::invalid_argument("nbPoints must be greater than 0.") if the given parameter is negative or nul.
		 */	
		explicit Dummy(const ComputeParameters &cParam):Signal(cParam){};
		
		/**
		 * 	Constructor with both parameters (signal AND compute) 
		 * 
		 *  @param[in]	Parameter(s) of the dummy signal to create
		 * 	@param[in]	Compute Parameter(s) of the dummy signal to create
		 * 
		 * @throw 	std::domain_error("tStart can't be negative.") if the given parameter is negative.
		 * @throw 	std::overflow_error("tStart can’t be greater or equal than tStop.") if the given parameter is >= than tStop.
		 * @throw 	std::domain_error("tStop can’t be negative or null.") if the given parameter is negative or nul.
		 * @throw 	td::invalid_argument("nbPoints must be greater than 0.") if the given parameter is negative or nul.
		 */
		Dummy(const DummyParam &sParam, const ComputeParameters &cParam):Signal(cParam),Parameters{sParam}{};
			
			
		/**
		 * 	Public accessors for the value parameter of the dummy signal
		 * 
		 *  const : callable with a const object  
		 * 	noexcept : this method throws no exception
		 * 	[[nodiscard]] : the return value should not be discarded (compiler warning)
		 * 
		 * 	@return : (getter) float, the value of the "value" parameter
		 */
		[[nodiscard]] float	getValue() const noexcept{return this->Parameters.value;};
		void	setValue(float Value) noexcept {this->Parameters.value = Value; setNeedToRecompute(true);};
				
};
#endif	/* __DUMMY_H__ */

