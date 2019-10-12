#pragma once
#ifndef _INew_Header
#define _INew_Header

#include <autoPtr.hxx>

namespace AutLib
{

	// Forward declaration of classes
	class Istream;

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
