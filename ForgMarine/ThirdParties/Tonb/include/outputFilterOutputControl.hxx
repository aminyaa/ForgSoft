#pragma once
#ifndef _outputFilterOutputControl_Header
#define _outputFilterOutputControl_Header

#include <dictionary.hxx>
#include <objectRegistry.hxx>
#include <NamedEnum.hxx>

namespace tnbLib
{

	/*---------------------------------------------------------------------------*\
				  Class outputFilterOutputControl Declaration
\*---------------------------------------------------------------------------*/

	class outputFilterOutputControl
	{
	public:

		enum outputControls
		{
			ocTimeStep,
			ocOutputTime
		};


	private:

		// Private data

			//- Time object
		const Time& time_;

		//- String representation of outputControls enums
		static const NamedEnum<outputControls, 2> outputControlNames_;

		//- Type of output
		outputControls outputControl_;

		//- The execution interval (in time steps) when using TIMESTEP mode
		//  a value <= 1 means execute at every time step
		label outputInterval_;


		// Private Member Functions

			//- Disallow default bitwise copy construct and assignment
		outputFilterOutputControl(const outputFilterOutputControl&);
		void operator=(const outputFilterOutputControl&);


	public:

		// Constructors

			//- Construct from Time object and dictionary
		outputFilterOutputControl(const Time&, const dictionary&);


		// Destructor
		~outputFilterOutputControl();


		// Member Functions

			//- Read from dictionary
		void read(const dictionary&);

		//- Return const access to the Time object
		const Time& time() const
		{
			return time_;
		}

		//- Flag to indicate whether to output
		bool output() const;
	};


	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //
}

#endif // !_outputFilterOutputControl_Header
