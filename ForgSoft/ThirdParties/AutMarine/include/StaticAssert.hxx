#pragma once
#ifndef _StaticAssert_Header
#define _StaticAssert_Header

namespace AutLib
{

	//- Forward declaration of StaticAssertionFailed.
	//  Leave as an incomplete class so that sizeof(..) fails
	template<bool Truth> class StaticAssertionFailed;

	/*---------------------------------------------------------------------------*\
	Class StaticAssertionFailed Declaration
	\*---------------------------------------------------------------------------*/

	//- Specialization for successful assertions
	template<>
	class StaticAssertionFailed<true>
	{};


	//- Helper class for handling static assertions
	template<unsigned Test>
	class StaticAssertionTest
	{};
}

// internal use:
// ~~~~~~~~~~~~~
// paste together strings, even if an argument is itself a macro
#define StaticAssertMacro(X,Y)  StaticAssertMacro1(X,Y)
#define StaticAssertMacro1(X,Y) StaticAssertMacro2(X,Y)
#define StaticAssertMacro2(X,Y) X##Y

// external use:
// ~~~~~~~~~~~~~
/**
* @def StaticAssert(Test)
* Assert that some test is true at compile-time
*/
#define StaticAssert(Test)                                                   \
    typedef ::AutLib::StaticAssertionTest                                      \
    <                                                                        \
        sizeof( ::AutLib::StaticAssertionFailed< ((Test) ? true : false) > )   \
    > StaticAssertMacro(StaticAssertionTest, __LINE__)

#endif // !_StaticAssert_Header
