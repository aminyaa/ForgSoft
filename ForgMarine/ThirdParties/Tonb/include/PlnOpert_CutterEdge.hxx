#pragma once
#ifndef _PlnOpert_CutterEdge_Header
#define _PlnOpert_CutterEdge_Header

#include <Pln_Edge.hxx>

namespace tnbLib
{

	class PlnOpert_CutterEdge
		: public Pln_Edge
	{

		/*Private Data*/

	public:

		PlnOpert_CutterEdge(const Pln_Edge& theEdge)
			: Pln_Edge(theEdge)
		{}


		Standard_Boolean IsCutter() const override
		{
			return Standard_True;
		}
	};
}

#endif // !_PlnOpert_CutterEdge_Header
