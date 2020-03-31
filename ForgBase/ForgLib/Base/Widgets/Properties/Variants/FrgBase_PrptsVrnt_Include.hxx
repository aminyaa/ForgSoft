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
}

template<typename T>
struct get_widget_type_from_variant {};

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
struct get_widget_type_from_variant<ForgBaseLib::FrgBase_PrptsVrntPnt3d>
{
	typedef ForgBaseLib::FrgBase_PrptsWdgPnt3d type;
};

#endif // !_FrgBase_PrptsVrnt_Include_header
