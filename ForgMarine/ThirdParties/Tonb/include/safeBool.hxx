#pragma once
#ifndef _safeBool_Header
#define _safeBool_Header

namespace tnbLib
{

	/*---------------------------------------------------------------------------*\
						Class safeBool_base Declaration
\*---------------------------------------------------------------------------*/

	class safeBoolBase
	{
	public:
		typedef void (safeBoolBase::*boolType)() const;
		void thisTypeDoesNotSupportComparisons() const {}

	protected:

		safeBoolBase() {}
		safeBoolBase(const safeBoolBase&) {}
		safeBoolBase& operator=(const safeBoolBase&) { return *this; }
		~safeBoolBase() {}
	};


	/*---------------------------------------------------------------------------*\
							Class safeBool Declaration
	\*---------------------------------------------------------------------------*/

	template <typename T = void>
	class safeBool
		: private safeBoolBase
	{
		// private or protected inheritance is very important here as it triggers the
		// access control violation in main.

	public:

		operator boolType() const
		{
			return (static_cast<const T*>(this))->test()
				? &safeBoolBase::thisTypeDoesNotSupportComparisons : 0;
		}

	protected:

		//- Destructor
		~safeBool()
		{}
	};


	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //
}

#include <safeBoolI.hxx>

#endif // !_safeBool_Header
