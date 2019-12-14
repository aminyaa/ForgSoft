#pragma once
#ifndef _Cad_SingularType_Header
#define _Cad_SingularType_Header

namespace AutLib
{

	enum class Cad_SingularType
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

#endif // !_Cad_SingularType_Header
