/**
 *	@file	types.h
 * 	@brief 	types definitions for Signals
 * 	@author	Alexis ROLLAND
 * 	@date	2023-01
 * 
 */

#ifndef	__TYPES_H__
#define	__TYPES_H__

/**
 *	Type SignalPoint 
 */
struct	SignalPoint{
		float	tn;				/**< t (X) coordinates of the point		*/
		float 	sig_tn;			/**< s(t) (Y) coordinates of the point 	*/
	};

/**
 *	Type ComputeParameters
 * 		(Simulation params)
 * 			tStart >= 0
 * 			tStop > tStart
 * 			nbPoints > 0
 */
struct 	ComputeParameters{
		float 			tStart;	 	/**< Start time. In "time units", 0 by default.	*/
		float 			tStop;		/**< Stop time. In "time units", 1 by default. */
		unsigned int	nbPoints;	/**< Simulation step. Defined by (tStop - tStart) / nbPoints. */
}	;


/**
 *	Type DummyParam : Dummy Signal caractéristics
 * 		Value is the only parameter for this signal
 */
struct	DummyParam{
		float 	value;		/**< Signal value 	*/
		
};

struct	SinusParam{
    //
    float 	A0;							/**<  Offset			*/
    float 	Amplitude;					/**<  Amplitude		*/
    float 	Omega;						/**<  Angular frequency  (rad.s-1) */
    float 	Phi0;						/**<  Phase at t=0		*/
};



#endif	/* __TYPES_H__ */


