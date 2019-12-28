#pragma once
#ifndef _CadAnalys_Edge_Header
#define _CadAnalys_Edge_Header

#include <Global_Done.hxx>

#include <Standard_Handle.hxx>
#include <TopoDS_Edge.hxx>

class Geom_Curve;
class Geom_Surface;

namespace AutLib
{

	class CadAnalys_Edge
		: public Global_Done
	{

		/*Private Data*/

		TopoDS_Edge theEdge_;

		Standard_Boolean SameParameter_;
		Standard_Boolean SameRange_;
		Standard_Boolean Degenerated_;
		Standard_Boolean Geometric_;

		Standard_Real theTolerance_;

	public:

		CadAnalys_Edge()
		{}

		CadAnalys_Edge(const TopoDS_Edge& theEdge)
			: theEdge_(theEdge)
		{}

		const TopoDS_Edge& Edge() const
		{
			return theEdge_;
		}

		Standard_Boolean SameParameter() const
		{
			return SameParameter_;
		}

		Standard_Boolean SameRange() const
		{
			return SameRange_;
		}

		Standard_Boolean Degenerated() const
		{
			return Degenerated_;
		}

		Standard_Real Tolerance() const
		{
			return theTolerance_;
		}

		void Perform();

		void LoadEdge(const TopoDS_Edge& theEdge)
		{
			theEdge_ = theEdge;
		}
	};
}

#endif // !_CadAnalys_Edge_Header
