#pragma once
#ifndef _Merge2d_Chain_Header
#define _Merge2d_Chain_Header

#include <Entity2d_Chain.hxx>
#include <Merge_StaticData.hxx>

namespace AutLib
{

	typedef Merge_StaticData<Entity2d_Chain, Merge_PntAlg_Mean>
		Merge2d_Chain;
}

#endif // !_Merge2d_Chain_Header
