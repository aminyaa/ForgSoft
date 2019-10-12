#pragma once
#ifndef _labelList_Header
#define _labelList_Header

#include <label.hxx>
#include <List.hxx>

namespace AutLib
{
	typedef List<label> labelList;
	typedef List<labelList> labelListList;
	typedef List<labelListList> labelListListList;

	typedef UList<label> unallocLabelList;
}

#endif // !_labelList_Header