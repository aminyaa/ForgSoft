#pragma once
#ifndef _Mesh_SingularType_Header
#define _Mesh_SingularType_Header

namespace AutLib
{

	enum class Mesh_SingularType
	{
		Pole_Corner,
		Pole_Loop,
		Pole_PartialSide,
		Pole_WholeSide,
		Line_Corner,
		Line_Dangle,
		Line_Loop,
		Line_TwoSide,
		Line_WholeSide
	};
}

#endif // !_Mesh_SingularType_Header
