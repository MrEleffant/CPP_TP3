# How To add a new signal

## Define the signal caractéristics
1. What defines the signal ? Amplitude ? Low/high Levels ? Offset ? Frequency ? Period ? High/Low time(s) ? Rise/fall time(s) ? etc...
2. Identiffy possible constraints (Period can't be negative or nul, ton can't be greater than period, etc...)
3. Create a struct for the caracteristics, add it to the types.h file. Postfix with "Param" (exple : SinusParam, DummyParam, RectangleParam...).

## Prepare the files
1. Create the header (.hpp) and the source (.cpp) "concrete signal"  files. The .hpp int the include directory, the .cpp in the src directory
2. The .hpp should include at least : Signal.hpp and Helper.hpp

## Set up the default concrete signal and basic class structure
1. Create default params for each parameter oh the concrete signal. Make it constexpr (exple : constexpr float defaultAmplitude = 3.3; ).
2.[ Define the concrete signal class, derivying the Signal class. Add a parameter struct as private member. Initialize this member with default values. 
	exple : class Sinus:public Signal{
			private:
				SinusParam Parameters{defaultA0, defaultAmplitude, defaultOmega, defaultPhi0};	/**< Sinus parameters */
				...
				};]
3. Add defaulted default Constructor and default Destructor :
	Sinus()	= default ;				
	virtual ~Sinus() = default;	
	
4. Add the parametrized contructors. These constructors take as parameters :
		a) a constant reference to a "concrete" signal parameter struct. As this Ctor has only one parameter, make it explicit. 
				In this case, the Compute parameters are the default ones
				Example : explicit Dummy(const DummyParam &param)noexcept:Parameters{param}{};	 
		b) a constant reference to a "concrete" signal compute parameter struct. As this Ctor has only one parameter, make it explicit. 
				In this case, the "signal" parameters are the default ones
				Example : explicit Dummy(const ComputeParameters &param)noexcept:SimulParams{param}{};	
		c) both parameters
	

5. Add a private empty compute (virtual) function member : virtual	void	compute() const noexcept;	
	The class should now compile and becomes instanciable. 
6. Add the accessors for all the signal parameters. Ensure that an exception is thrown if a constraint isn't respected.
	Each setter must set the "NeedToRecompute" flag to true : setNeedToRecompute(true);
	Each getter should be const and [[nodiscard]]
	If the accessor doesn't throw any exception, make it noexcep

7. You should now test the creation of default const and non const objects and the accessors.

8. [In the Helper.hpp file, add a new concrete Helper class for the new signal. This class derives from the abstract helper
	A struct parameter is a private member of the helper.
	example : class	NoiseHelper:public Helper{
					private:
						NoiseParam Parameters{};		/**<	Signal parameters. 		 */
						...
						};]
9.	Explicitly delete defaults Ctor and Dtor. Add an explicit parametrized Ctor. Example : explicit SinusHelper(const SinusParam &Params); 
		This Ctor MUST ensures the correctness of the given parameters. Exception(s) MUST be thrown if bad values are submitted.
10. Add private getters for all the paramters :
				[[nodiscard]]	float 	getA0() const noexcept {return this->Parameters.A0;};
				[[nodiscard]]	float 	getAmplitude() const noexcept {return this->Parameters.Amplitude;};
				[[nodiscard]]	float 	getOmega() const noexcept {return this->Parameters.Omega;};
				[[nodiscard]]	float 	getPhi0() const noexcept {return this->Parameters.Phi0;};
11. Add the declaration compute method (private). Example: [[nodiscard]] virtual	std::vector<SignalPoint> compute(const ComputeParameters &SimulParameters) const noexcept;
12. Define the concrete compute method for the signal

13. In the concrete signal cpp, define the compute method. Basicly, this method creates a new helper and calls the public do_compute interface.
