#pragma once
#ifndef _Global_Timer_Header
#define _Global_Timer_Header

#include <thread>
#include <chrono>

namespace AutLib
{

	enum Global_TimerInfo
	{
		Global_TimerInfo_ms,
		Global_TimerInfo_s,
		Global_TimerInfo_hour
	};

	extern float global_time_duration;

	class Global_Timer
	{

		std::chrono::time_point<std::chrono::steady_clock> theStart_;
		std::chrono::time_point<std::chrono::steady_clock> theEnd_;

		std::chrono::duration<float> theDuration_;

		Global_TimerInfo theInfo_;

		/*Private Data*/

		void EstimateDuration();

	public:

		Global_Timer();

		~Global_Timer();

		void SetInfo(const Global_TimerInfo theInfo)
		{
			theInfo_ = theInfo;
		}
	};
}

#endif // !_Global_Timer_Header
