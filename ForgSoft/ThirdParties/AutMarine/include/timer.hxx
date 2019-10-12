#pragma once
#ifndef _timer_Header
#define _timer_Header

#include <debugSwitch.hxx>

#include <setjmp.h>

//- check it a timeout has occured
//  keep setjmp in same stack frame so no function calls
#define timedOut(x) \
    (((x).newTimeOut_ > 0) ? setjmp(AutLib::timer::envAlarm) : false)

typedef	void(*__p_sig_fn_t)(int);

namespace AutLib
{

	class timer
	{

		// Private data

		//- old signal
		static __p_sig_fn_t oldAction_;

		//- old alarm() value
		static unsigned int oldTimeOut_;


		// Private Member Functions

		//- alarm handler
		static void signalHandler(int);

	public:

		// Public data

		//- Declare name of the class and its debug switch
		static const char* typeName_() { return "timer"; }
		static const word typeName;
		static debug::debugSwitch debug;;

		//- current time out value. Needed by macro timedOut
		unsigned int newTimeOut_;

		//- state for setjmp. Needed by macro timedOut
		static jmp_buf envAlarm;


		// Constructors

		//- Construct from components.
		//  newTimeOut=0 makes it do nothing.
		timer(const unsigned int newTimeOut);


		// Destructor

		~timer();
	};
}

#endif // !_timer_Header
