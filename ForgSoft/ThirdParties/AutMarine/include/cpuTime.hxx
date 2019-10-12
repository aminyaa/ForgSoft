#pragma once
#ifndef _cpuTime_Header
#define _cpuTime_Header

#include <ctime>

namespace AutLib
{

	class cpuTime
	{

		// Private data

		std::clock_t startTime_;
		mutable std::clock_t lastTime_;
		mutable std::clock_t newTime_;

		static void getTime(std::clock_t& t);

		static double timeDifference
		(
			const std::clock_t& start,
			const std::clock_t& end
		);

	public:

		// Constructors

		//- Construct from components
		cpuTime();


		// Member Functions

		// Access

		//- Returns CPU time from start of run
		double elapsedCpuTime() const;

		//- Returns CPU time from last call of cpuTimeIncrement()
		double cpuTimeIncrement() const;

	};
}

#endif // !_cpuTime_Header
