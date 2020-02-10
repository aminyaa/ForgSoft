#pragma once
#ifndef _TModel_EdgeAdaptor_Header
#define _TModel_EdgeAdaptor_Header

#include <Global_AccessMethod.hxx>

#include <TopoDS_Edge.hxx>

#include <memory>

namespace tnbLib
{

	//- Forward Declarations
	class TModel_Surface;
	class TModel_Paired;
	class TModel_Wire;
	class TModel_Edge;

	class TModel_EdgeAdaptor
	{

		/*Private Data*/

		std::weak_ptr<TModel_Surface> theSurface_;
		std::weak_ptr<TModel_Paired> thePaired_;
		std::weak_ptr<TModel_Wire> theWire_;
		std::weak_ptr<TModel_Edge> thePairedEdge_;

		TopoDS_Edge theTEdge_;

	protected:

		TModel_EdgeAdaptor()
		{}

	public:

		//- Macros
		GLOBAL_ACCESS_SINGLE(std::weak_ptr<TModel_Surface>, Surface)
			GLOBAL_ACCESS_SINGLE(std::weak_ptr<TModel_Paired>, Paired)
			GLOBAL_ACCESS_SINGLE(std::weak_ptr<TModel_Edge>, PairedEdge)
			GLOBAL_ACCESS_SINGLE(std::weak_ptr<TModel_Wire>, Wire)

			GLOBAL_ACCESS_PRIM_SINGLE(TopoDS_Edge, TEdge)
	};
}

#endif // !_TModel_EdgeAdaptor_Header
