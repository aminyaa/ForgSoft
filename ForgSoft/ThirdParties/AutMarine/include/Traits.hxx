#pragma once
#ifndef _Traits_Header
#define _Traits_Header

#include <handle.hxx>
#include <Standard_Handle.hxx>
#include <Pnt2d.hxx>
#include <Pnt3d.hxx>
#include <Entity_Connectivity.hxx>

#include <xtr1common>
#include <memory>

namespace AutLib
{

	template<int Dim> struct is_two_dimension : std::false_type {};
	template<> struct is_two_dimension<2> : std::true_type {};

	template<int Dim> struct is_three_dimension : std::false_type {};
	template<> struct is_three_dimension<3> : std::true_type {};

	template<bool Cond> struct if_true : std::false_type {};
	template<> struct if_true<true> : std::true_type {};

	template<bool Cond> struct if_false : std::false_type {};
	template<> struct if_false<false> : std::true_type {};

	template<class Point> struct background_connectivity {};
	template<> struct background_connectivity<Pnt2d> { typedef connectivity::triple type; };
	template<> struct background_connectivity<Pnt3d> { typedef connectivity::quadruple type; };

	template<class T> struct remove_pointer { typedef T type; };
	template<class T> struct remove_pointer<T*> { typedef T type; };
	template<class T> struct remove_pointer<T* const> { typedef T type; };
	template<class T> struct remove_pointer<T* volatile> { typedef T type; };
	template<class T> struct remove_pointer<T* const volatile> { typedef T type; };

	template<class T> struct remove_pointer<pHandle(T)> { typedef T type; };
	template<class T> struct remove_pointer<Handle(T)> { typedef T type; };
	template<class T> struct remove_pointer<std::shared_ptr<T>> { typedef T type; };

	template<class T> struct remove_reference { typedef T type; };
	template<class T> struct remove_reference<T&> { typedef T type; };
	template<class T> struct remove_reference<const T&> { typedef T type; };

	template<class Point> struct down_cast_point {};
	template<> struct down_cast_point<gp_Pnt2d> { typedef Pnt2d type; };
	template<> struct down_cast_point<gp_Pnt> { typedef Pnt3d type; };

	template<class Point> struct transform_point_type {};
	template<> struct transform_point_type<Pnt2d> { typedef gp_Trsf2d type; };
	template<> struct transform_point_type<Pnt3d> { typedef gp_Trsf type; };
}

#endif // !_Traits_Header
