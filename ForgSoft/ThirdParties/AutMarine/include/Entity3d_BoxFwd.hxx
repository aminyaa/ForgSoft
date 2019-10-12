#pragma once
#ifndef _Entity3d_BoxFwd_Header
#define _Entity3d_BoxFwd_Header

namespace AutLib
{

	// Forward Declarations
	class Pnt3d;
	template<class Point> class Entity_Box;

	typedef Entity_Box<Pnt3d> Entity3d_Box;
}

#endif // !_Entity3d_BoxFwd_Header
