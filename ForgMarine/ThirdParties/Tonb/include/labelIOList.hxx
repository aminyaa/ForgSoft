#pragma once
#ifndef _labelIOList_Header
#define _labelIOList_Header

#include <labelList.hxx>
#include <IOList.hxx>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace tnbLib
{
	typedef IOList<label> labelIOList;
	typedef IOList<labelList> labelListIOList;
}

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif // !_labelIOList_Header
