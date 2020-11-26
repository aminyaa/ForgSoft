#pragma once
#ifndef _clockTime_Header
#define _clockTime_Header

#include <sys/types.h>

namespace tnbLib
{

	struct timeval
	{
		long    tv_sec;         /* seconds */
		long    tv_usec;        /* and microseconds */
	};

/*---------------------------------------------------------------------------*\
						   Class clockTime Declaration
\*---------------------------------------------------------------------------*/

	class clockTime
	{
		// Private data

		struct timeval startTime_;
		mutable struct timeval lastTime_;
		mutable struct timeval newTime_;

		static void getTime(struct timeval& t);

		static double timeDifference
		(
			const struct timeval& start,
			const struct timeval& end
		);


	public:

		// Constructors

			//- Construct from components
		clockTime();


		// Member Functions

			// Access

				//- Returns CPU time from start of run
		double elapsedTime() const;

		//- Returns CPU time from last call of clockTimeIncrement()
		double timeIncrement() const;
	};


	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //
}

#endif // !_clockTime_Header
