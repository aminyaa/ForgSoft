#pragma once
#ifndef _clockTime_Header
#define _clockTime_Header

namespace AutLib
{
	struct Timeval 
	{
		long    tv_sec;         /* seconds */
		long    tv_usec;        /* and microseconds */
	};

	class clockTime
	{
		// Private data

		struct Timeval startTime_;
		mutable struct Timeval lastTime_;
		mutable struct Timeval newTime_;

		static void getTime(struct Timeval& t);

		static double timeDifference
		(
			const struct Timeval& start,
			const struct Timeval& end
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
}

#endif // !_clockTime_Header
