#pragma once
#ifndef _profilingTrigger_Header
#define _profilingTrigger_Header

#include <clockTime.hxx>

namespace AutLib
{

	class profilingInfo;
	class string;

	class profilingTrigger
	{
		// Private data

		clockTime clock_;

		profilingInfo &info_;

		bool running_;

		// Private Member Functions

		//- Disallow default bitwise copy construct
		profilingTrigger(const profilingTrigger&) = delete;

		//- Disallow default bitwise assignment
		void operator=(const profilingTrigger&) = delete;

	protected:

		clockTime &clock()
		{
			return clock_;
		}

		const profilingInfo &info() const
		{
			return info_;
		}

	public:

		// Constructors

		profilingTrigger(const string &name);

		~profilingTrigger();

		void stop();

		friend class profilingPool;
	};
}

#endif // !_profilingTrigger_Header
