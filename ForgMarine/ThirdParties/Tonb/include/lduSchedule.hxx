#pragma once
#ifndef _lduSchedule_Header
#define _lduSchedule_Header

#include <List.hxx>
#include <token.hxx>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace tnbLib
{

	// Forward declaration of friend functions and operators

	struct lduScheduleEntry;
	Ostream& operator<<(Ostream& os, const lduScheduleEntry& lb);


	/*---------------------------------------------------------------------------*\
						  Class lduSchedule Declaration
	\*---------------------------------------------------------------------------*/

	struct lduScheduleEntry
	{
		label patch;
		bool init;

		friend bool operator!=
			(
				const lduScheduleEntry& lb1,
				const lduScheduleEntry& lb2
				)
		{
			return true;
		}

		friend Ostream& operator<<(Ostream& os, const lduScheduleEntry& lb)
		{
			os << lb.patch << token::SPACE << lb.init;
			return os;
		}
	};


	typedef List<lduScheduleEntry> lduSchedule;


	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace tnbLib

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif // !_lduSchedule_Header
