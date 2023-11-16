/**
 *	@file	Signal.hpp
 * 	@brief 	Signal class header file
 * 	@author	Alexis ROLLAND
 * 	@date	2023-01
 * 
 */
#ifndef __SIGNAL_H__
#define	__SIGNAL_H__

#include <iostream>
#include <vector>
#include <fstream>
#include <filesystem>

#include "types.h"
#include "Helper.hpp"

constexpr	unsigned int	defaultNbPoints = 100;	/**< Default number of points : 100	*/
constexpr	float 			defaulttStart = 0;		/**< Default start time : 0 (sec)	*/
constexpr	float 			defaulttStop = 1;		/**< Default stop time : 1 (sec)	*/

constexpr	std::string_view	defaultFileName{"signal.data"};	/**< Default File name	 */

/**
 * Class Signal
 * 
 * 	Abstract class - cannot be instanciated directly 
 */
class Signal{
	private:
		mutable	bool	needToRecompute{true};											/**< Flag set if the signal needs to be "recomputed" (change of params)	*/ 
		
		/**
		 *	"compute" method
		 * 		pure virtual (virtual AND =0)
		 * 		 
		 * 	const : callable with a const object  
		 * 	noexcept : this method throws no exception
		 */
		virtual	void	compute() const noexcept = 0;
		
	protected:
		mutable std::vector<SignalPoint>	tabSignal{};	/**< Vector containing the signal data (points)	- mutable because needs to be calculated, even with const objects	*/
		ComputeParameters	SimulParams{defaulttStart, defaulttStop, defaultNbPoints};	/**< Simulation parameters */	
		
		/**
		 * private accessors for needToCompute member
		 * 
		 * 	const : callable with a const object  
		 * 	noexcept : this method throws no exception
		 * 	[[nodiscard]] : the return value should not be discarded (compiler warning)
		 */
		[[nodiscard]] bool	getNeedToRecompute() const noexcept {return this->needToRecompute;};
		void	setNeedToRecompute(bool value) const noexcept {this->needToRecompute = value;};
		
	public:
		/**
		 *	default ctor & dtor : real default version 
		 */
		 Signal() = default;
		 ~Signal() = default;
		 
		 /**
		  * Paramatrized Ctor
		  * 
		  * @param[in param : constant reference to a filly configured ComputeParameters Structure
		  * 
		  * explicit : 	the given parameter MUST match the expected
		  * 				parameter. This avoids unintended concersions.
		  * 				cf C++ Core Guidelines C.46 
		  * 
		  * @throw 	std::domain_error("tStart can't be negative.") if the given parameter is negative.
		  * @throw 	std::overflow_error("tStart can’t be greater or equal than tStop.") if the given parameter is >= than tStop.
		  * @throw 	std::domain_error("tStop can’t be negative or null.") if the given parameter is negative or nul.
		  * @throw 	td::invalid_argument("nbPoints must be greater than 0.") if the given parameter is negative or nul.
		  */
		  explicit Signal(const ComputeParameters &param);
		  
	
		/**
		 * getter (public) for the tStart parameter 
		 * 
		 * const : callable with a const object  
		 * noexcept : this method throws no exception
		 * 
		 * @return value of tStart parameter (inside the SimulParams structure)
		 * [[nodiscard]] : the return value should not be discarded (compiler warning)
		 */	
		[[nodiscard]] float	gettStart() const noexcept {return this->SimulParams.tStart;};
		
		/**
		 * setter (public) for the tStart parameter (inside the SimulParams structure)
		 * 		tStart must be >= 0 and < tStop. 
		 * 
		 * @param[in]	_tStart		Value of tStart
		 * 
		 * @throw 	std::domain_error("tStart can't be negative.") if the given parameter is negative.
		 * @throw 	std::overflow_error("tStart can’t be greater or equal than tStop.") if the given parameter is >= than tStop 
		 */
		void	settStart(float _tStart); 
		
		/**
		 * getter (public) for the tStop parameter 
		 * 
		 * const : callable with a const object  
		 * noexcept : this method throws no exception
		 * 
		 * @return value of tStop parameter (inside the SimulParams structure)
		 * [[nodiscard]] : the return value should not be discarded (compiler warning)
		 */	
		[[nodiscard]] float 	gettStop()const  noexcept {return this->SimulParams.tStop;};
		
		/**
		 * setter (public) for the tStop parameter (inside the SimulParams structure)
		 * 		tStop must be > 0 and > tStart
		 * 	  
		 * @param[in]	_tStop		Value of tStop
		 * 
		 * @throw 	std::domain_error("tStop can’t be negative or null.") if the given parameter is negative or nul.
		 * @throw 	std::underflow_error("tStop can’t be lesser than tStart.") if the given parameter is < than tStart 
		 */
		void	settStop(float _tStop);
			
		/**
		 * getter (public) for the nbPoints parameter 
		 * 
		 * const : callable with a const object  
		 * noexcept : this method throws no exception
		 * 
		 * @return value of nbPoints (inside the SimulParams structure)
		 * [[nodiscard]] : the return value should not be discarded (compiler warning)
		 */		
		[[nodiscard]] unsigned int	getNbPoints()const  noexcept  {return this->SimulParams.nbPoints;};
		
		/**
		 * setter (public) for the nbPoints parameter (inside the SimulParams structure)
		 * 		nbPoints must be > 0
		 * 	  
		 * @param[in]	_nbPoints		Value of tStop
		 * 
		 * @throw 	td::invalid_argument("nbPoints must be greater than 0.") if the given parameter is negative or nul.
		 */
		void	setNbPoints(unsigned int _nbPoints) {if (_nbPoints == 0) throw std::invalid_argument("nbPoints must be greater than 0.");this->SimulParams.nbPoints = _nbPoints;setNeedToRecompute(true);};
		
		/**
		 * 	generate method
		 * 		
		 * 	@param[in] 	FileName(=defaultFileName)	The complete path of the data file to write.	
		 * 
		 * 	@return : Size of the generated file (bytes)
		 * 
		 * @throw  std::ios::exceptions 
		 */
		unsigned int	generate(const std::filesystem::path FileName=defaultFileName)const;	
};
#endif	/* __SIGNAL_H__ */


