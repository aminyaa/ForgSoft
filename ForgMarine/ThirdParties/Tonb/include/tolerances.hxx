#pragma once
#ifndef _tolerances_Header
#define _tolerances_Header

#include <IOdictionary.hxx>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace tnbLib
{

	/*---------------------------------------------------------------------------*\
							   Class tolerances Declaration
	\*---------------------------------------------------------------------------*/
	class Time;

	class tolerances
		: public IOdictionary
	{
		// Private data

		dictionary relaxationFactors_;
		dictionary solverTolerances_;
		dictionary solverRelativeTolerances_;


		// Private Member Functions

			//- Disallow default bitwise copy construct and assignment
		tolerances(const tolerances&);
		void operator=(const tolerances&);


	public:

		// Constructors

		//- Construct from time
		tolerances(const Time& t, const fileName& dictName);


		// Member Functions

			// Access

		bool relax(const word& name) const;
		scalar relaxationFactor(const word& name) const;

		scalar solverTolerance(const word& name) const;

		bool solverRelativeTolerances() const;
		scalar solverRelativeTolerance(const word& name) const;


		// Read

			//- Read the tolerances
		bool read();
	};


	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace tnbLib

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif // !_tolerances_Header
