#pragma once
#ifndef _Merge3d_Chain_Header
#define _Merge3d_Chain_Header

#include <Entity3d_Chain.hxx>
#include <Merge_StaticData.hxx>

namespace AutLib
{

	typedef Merge_StaticData<Entity3d_Chain, Merge_PntAlg_Mean>
		Merge3d_Chain;
}

#endif // !_Merge3d_Chain_Header
