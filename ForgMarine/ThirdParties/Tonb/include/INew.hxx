#pragma once
#ifndef _INew_Header
#define _INew_Header

#include <autoPtr.hxx>

namespace tnbLib
{

	// Forward declaration of classes
	class Istream;

	/*---------------------------------------------------------------------------*\
							   Class INew Declaration
	\*---------------------------------------------------------------------------*/

	template<class T>
	class INew
	{

	public:

		INew()
		{}

		autoPtr<T> operator()(Istream& is) const
		{
			return T::New(is);
		}

		autoPtr<T> operator()(const word&, Istream& is) const
		{
			return T::New(is);
		}
	};
}

#endif // !_INew_Header
