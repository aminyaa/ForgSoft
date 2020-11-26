#pragma once
#ifndef _commSchedule_Header
#define _commSchedule_Header

#include <dynamicLabelList.hxx>
#include <labelPair.hxx>
#include <labelList.hxx>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace tnbLib
{

	/*---------------------------------------------------------------------------*\
							   Class commSchedule Declaration
	\*---------------------------------------------------------------------------*/

	class commSchedule
	{
		// Private data

			//- Order in which input communication has been scheduled
		labelList schedule_;

		//- Per processor the order in which communication has been scheduled
		labelListList procSchedule_;

		// Private Member Functions

			//- Count the number of outstanding communications for a single
			//  processor
		label outstandingComms(const labelList&, dynamicLabelList&) const;


	public:

		ClassName("commSchedule");

		// Constructors

			//- Construct from wanted communication. Wanted communication is between
			//  two processors. Can be a one-way communication or
			//  two-way communication, that is up to the caller. This class just
			//  determines an order for it such that any processor is only talking
			//  to one other at a time. After construction:
			//  - schedule is the order in which comms is done.
			//  - procSchedule[procI] is for procI the order in which comms is done.
		commSchedule(const label nProcs, const List<labelPair>& comms);


		// Member Functions

			//- order in which comms is scheduled
		const labelList& schedule() const
		{
			return schedule_;
		}

		//- Per processor the order in which communication has been scheduled
		const labelListList& procSchedule() const
		{
			return procSchedule_;
		}


	};


	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace tnbLib

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif // !_commSchedule_Header
