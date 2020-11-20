#pragma once
#ifndef _FrgBase_PrptsVrnt_Include_Header
#define _FrgBase_PrptsVrnt_Include_Header

#include <FrgBase_PrptsVrntBool.hxx>
#include <FrgBase_PrptsVrntDouble.hxx>
#include <FrgBase_PrptsVrntInt.hxx>
#include <FrgBase_PrptsVrntOneValue.hxx>
#include <FrgBase_PrptsVrntSelectTItems.hxx>
#include <FrgBase_PrptsVrntString.hxx>
#include <FrgBase_PrptsVrntCombo.hxx>
#include <FrgBase_PrptsVrntColor.hxx>
#include <FrgBase_PrptsVrntPnt2d.hxx>
#include <FrgBase_PrptsVrntPnt3d.hxx>
#include <FrgBase_PrptsVrntSelectPath.hxx>
#include <FrgBase_PrptsVrntSelectTItem.hxx>
#include <FrgBase_PrptsVrntStringDouble.hxx>
#include <FrgBase_PrptsVrntFieldScalar.hxx>
#include <FrgBase_PrptsVrntFieldVector.hxx>

namespace ForgBaseLib
{
	class FrgBase_PrptsWdgBool;
	class FrgBase_PrptsWdgDouble;
	class FrgBase_PrptsWdgInt;
	class FrgBase_PrptsWdgSelectTItems;
	class FrgBase_PrptsWdgString;
	class FrgBase_PrptsWdgColor;
	class FrgBase_PrptsWdgCombo;
	class FrgBase_PrptsWdgPnt2d;
	class FrgBase_PrptsWdgPnt3d;
	class FrgBase_PrptsWdgSelectPath;
	template<typename Type>
	class FrgBase_PrptsWdgSelectTItem;
	class FrgBase_PrptsVWdgStringDouble;
	class FrgBase_PrptsWdgFieldScalar;
	class FrgBase_PrptsWdgFieldVector;
}

template<typename T>
struct get_widget_type_from_variant
{
	
};

template<>
struct get_widget_type_from_variant<ForgBaseLib::FrgBase_PrptsVrntBool>
{
	typedef ForgBaseLib::FrgBase_PrptsWdgBool type;
};

template<>
struct get_widget_type_from_variant<ForgBaseLib::FrgBase_PrptsVrntDouble>
{
	typedef ForgBaseLib::FrgBase_PrptsWdgDouble type;
};

template<>
struct get_widget_type_from_variant<ForgBaseLib::FrgBase_PrptsVrntInt>
{
	typedef ForgBaseLib::FrgBase_PrptsWdgInt type;
};

template<>
struct get_widget_type_from_variant<ForgBaseLib::FrgBase_PrptsVrntSelectTItems>
{
	typedef ForgBaseLib::FrgBase_PrptsWdgSelectTItems type;
};

template<>
struct get_widget_type_from_variant<ForgBaseLib::FrgBase_PrptsVrntString>
{
	typedef ForgBaseLib::FrgBase_PrptsWdgString type;
};

template<>
struct get_widget_type_from_variant<ForgBaseLib::FrgBase_PrptsVrntCombo>
{
	typedef ForgBaseLib::FrgBase_PrptsWdgCombo type;
};

template<>
struct get_widget_type_from_variant<ForgBaseLib::FrgBase_PrptsVrntColor>
{
	typedef ForgBaseLib::FrgBase_PrptsWdgColor type;
};

template<>
struct get_widget_type_from_variant<ForgBaseLib::FrgBase_PrptsVrntPnt2d>
{
	typedef ForgBaseLib::FrgBase_PrptsWdgPnt2d type;
};

template<>
struct get_widget_type_from_variant<ForgBaseLib::FrgBase_PrptsVrntPnt3d>
{
	typedef ForgBaseLib::FrgBase_PrptsWdgPnt3d type;
};

template<int Type>
struct get_widget_type_from_variant<ForgBaseLib::FrgBase_PrptsVrntSelectPath<Type>>
{
	typedef ForgBaseLib::FrgBase_PrptsWdgSelectPath type;
};

template <typename Type>
struct get_widget_type_from_variant<ForgBaseLib::FrgBase_PrptsVrntSelectTItem<Type>>
{
	typedef ForgBaseLib::FrgBase_PrptsWdgSelectTItem<Type> type;
};

template<>
struct get_widget_type_from_variant<ForgBaseLib::FrgBase_PrptsVrntStringDouble>
{
	typedef ForgBaseLib::FrgBase_PrptsWdgStringDouble type;
};

template<>
struct get_widget_type_from_variant<ForgBaseLib::FrgBase_PrptsVrntFieldScalar>
{
	typedef ForgBaseLib::FrgBase_PrptsWdgFieldScalar type;
};

template<>
struct get_widget_type_from_variant<ForgBaseLib::FrgBase_PrptsVrntFieldVector>
{
	typedef ForgBaseLib::FrgBase_PrptsWdgFieldVector type;
};

#endif // !_FrgBase_PrptsVrnt_Include_header
