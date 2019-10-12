#pragma once
#ifndef _JobInfo_Header
#define _JobInfo_Header

#include <dictionary.hxx>
#include <cpuTime.hxx>

namespace AutLib
{

	class JobInfo
		: public dictionary
	{

		// Private data
		fileName runningJobPath_;
		fileName finishedJobPath_;
		cpuTime  cpuTime_;

		// Private member functions

		bool write(Ostream&) const;
		void end(const word& terminationType);

	public:

		static bool constructed;
		static debug::infoSwitch writeJobInfo;

		// Constructors

		//- Construct null
		JobInfo();


		// Destructor

		~JobInfo();


		// Member Functions

		// Write

		void write() const;

		void end();

		void exit();

		void abort();

		void signalEnd() const;
	};

	extern JobInfo jobInfo;
}

#endif // !_JobInfo_Header
