#pragma once
#ifndef _typeInfo_Header
#define _typeInfo_Header

#include <error.hxx>

#include <typeinfo>

namespace AutLib
{

	//- Reference type cast template function,
	//  wraps dynamic_cast to handle bad_cast exception and generate a FatalError.
	template<class To, class From>
	inline To& dynamicCast(From& r)
	{
		try
		{
			return dynamic_cast<To&>(r);
		}
		catch (std::bad_cast)
		{
			FatalErrorIn("dynamicCast<To>(From&)")
				<< "Attempt to cast type " << typeid(r).name()
				<< " to type " << typeid(To).name()
				<< abort(FatalError);

			return dynamic_cast<To&>(r);
		}
	}

	//- Reference type cast template function.
	//  As per dynamicCast, but handles type names via the virtual type() method.
	template<class To, class From>
	inline To& refCast(From& r)
	{
		try
		{
			return dynamic_cast<To&>(r);
		}
		catch (std::bad_cast)
		{
			FatalErrorIn("refCast<To>(From&)")
				<< "Attempt to cast type " << r.type()
				<< " to type " << To::typeName
				<< abort(FatalError);

			return dynamic_cast<To&>(r);
		}
	}

	//- Check the typeid
	template<class TestType, class Type>
	inline bool isType(const Type& t)
	{
		return typeid(t) == typeid(TestType);
	}


	//- Check if a dynamic_cast to typeid is possible
	template<class TestType, class Type>
	inline bool isA(const Type& t)
	{
		return dynamic_cast<const TestType*>(&t);
	}
}

#endif // !_typeInfo_Header
