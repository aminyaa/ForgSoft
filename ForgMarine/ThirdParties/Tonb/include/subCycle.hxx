#pragma once
#ifndef _subCycle_Header
#define _subCycle_Header

#include <subCycleTime.hxx>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace tnbLib
{

	/*---------------------------------------------------------------------------*\
							  Class subCycleField Declaration
	\*---------------------------------------------------------------------------*/

	template<class GeometricField>
	class subCycleField
	{
		// Private data

			//- Reference to the field being sub-cycled
		GeometricField& gf_;

		//- Reference to the field old-time field being sub-cycled
		//  Needed to avoid calls to oldTime() which may cause
		//  unexpected updates of the old-time field
		GeometricField& gf0_;

		//- Copy of the "real" old-time value of the field
		GeometricField gf_0_;


	public:

		// Constructors

			//- Construct field and number of sub-cycles
		subCycleField(GeometricField& gf)
			:
			gf_(gf),
			gf0_(gf.oldTime()),
			gf_0_(gf0_.name() + "_", gf0_)
		{}


		//- Destructor
		~subCycleField()
		{
			// Reset the old-time field
			gf0_ = gf_0_;

			// Correct the time index of the field to correspond to the global time
			gf_.timeIndex() = gf_.time().timeIndex();
			gf0_.timeIndex() = gf_.time().timeIndex();
		}


		//- Correct the time index of the field to correspond to
		//  the sub-cycling time.
		//
		//  The time index is incremented to protect the old-time value from
		//  being updated at the beginning of the time-loop in the case of
		//  outer iteration
		void updateTimeIndex()
		{
			gf_.timeIndex() = gf_.time().timeIndex() + 1;
			gf0_.timeIndex() = gf_.time().timeIndex() + 1;
		}
	};


	/*---------------------------------------------------------------------------*\
							  Class subCycle Declaration
	\*---------------------------------------------------------------------------*/

	template<class GeometricField>
	class subCycle
		:
		public subCycleField<GeometricField>,
		public subCycleTime
	{
		// Private Member Functions

			//- Disallow default bitwise copy construct
		subCycle(const subCycle<GeometricField>&);

		//- Disallow default bitwise assignment
		void operator=(const subCycle<GeometricField>&);


	public:

		// Constructors

			//- Construct field and number of sub-cycles
		subCycle(GeometricField& gf, const label nSubCycles)
			:
			subCycleField<GeometricField>(gf),
			subCycleTime(const_cast<Time&>(gf.time()), nSubCycles)
		{
			// Update the field time index to correspond to the sub-cycle time
			this->updateTimeIndex();
		}


		//- Destructor
		//  End the subCycleTime, which restores the time state
		~subCycle()
		{
			endSubCycle();
		}
	};


	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace tnbLib

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif // !_subCycle_Header
