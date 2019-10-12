#pragma once
#ifndef _dynamicLabelList_Header
#define _dynamicLabelList_Header

#include <label.hxx>
#include <DynamicList.hxx>

namespace AutLib
{
	typedef DynamicList<label> dynamicLabelList;
	typedef List<dynamicLabelList> dynamicLabelListList;
}

#endif // !_dynamicLabelList_Header