#pragma once
#ifndef _Traits_Header
#define _Traits_Header

#include <Standard_Handle.hxx>

#include <xtr1common>
#include <memory>

namespace tnbLib
{

	template<int Dim> struct is_two_dimension : std::false_type {};
	template<> struct is_two_dimension<2> : std::true_type {};

	template<int Dim> struct is_three_dimension : std::false_type {};
	template<> struct is_three_dimension<3> : std::true_type {};

	template<bool Cond> struct if_true : std::false_type {};
	template<> struct if_true<true> : std::true_type {};

	template<bool Cond> struct if_false : std::false_type {};
	template<> struct if_false<false> : std::true_type {};

	template<class T> struct remove_pointer { typedef T type; };
	template<class T> struct remove_pointer<T*> { typedef T type; };
	template<class T> struct remove_pointer<T* const> { typedef T type; };
	template<class T> struct remove_pointer<T* volatile> { typedef T type; };
	template<class T> struct remove_pointer<T* const volatile> { typedef T type; };

	template<class T> struct remove_pointer<Handle(T)> { typedef T type; };
	template<class T> struct remove_pointer<std::shared_ptr<T>> { typedef T type; };

	template<class T> struct remove_reference { typedef T type; };
	template<class T> struct remove_reference<T&> { typedef T type; };
	template<class T> struct remove_reference<const T&> { typedef T type; };
}

#endif // !_Traits_Header
