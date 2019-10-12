#pragma once
#ifndef _profilingStack_Header
#define _profilingStack_Header

#include <LIFOStack.hxx>

namespace AutLib
{

	class clockTime;
	class profilingInfo;

	class profilingStack
		: private LIFOStack<profilingInfo *>
	{

		// Private Member Functions

		//- Disallow default bitwise copy construct
		profilingStack(const profilingStack&) = delete;

		//- Disallow default bitwise assignment
		void operator=(const profilingStack&) = delete;

		//- remember the timers for the correct stack-output
		HashTable<clockTime *, label> timers_;
	protected:
		void writeStackContents(Ostream &) const;

		void addTimer(const profilingInfo &info, clockTime &timer);
	public:

		// Constructors

		//- Construct null
		profilingStack();

		// Destructor

		~profilingStack();


		// Members that encapsulate the original stack-class
		profilingInfo &top() const;

		profilingInfo &bottom() const;

		bool empty() const;

		void push(profilingInfo &);

		profilingInfo &pop();

		friend class profilingPool;
	};
}

#endif // !_profilingStack_Header
