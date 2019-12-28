#pragma once
#ifndef _TModel_Edge_Header
#define _TModel_Edge_Header

#include <TModel_Entity.hxx>
#include <Cad_EntityPrecision.hxx>
#include <Global_AccessMethod.hxx>
#include <Entity3d_ChainFwd.hxx>

#include <TopoDS_Edge.hxx>

#include <memory>

namespace AutLib
{

	// Forward Declarations
	class TModel_Vertex;
	class TModel_Curve;
	class TModel_parCurve;
	class TModel_Paired;
	class TModel_Surface;
	class TModel_Wire;
	class Geo_ApprxCurveInfo;

	class TModel_Edge
		: public TModel_Entity
		, public Cad_EntityPrecision
	{

		/*Private Data*/

		std::shared_ptr<TModel_Vertex> theVtx0_;
		std::shared_ptr<TModel_Vertex> theVtx1_;

		std::shared_ptr<TModel_parCurve> thePar_;

		std::shared_ptr<TModel_Curve> theCurve_;

		mutable std::shared_ptr<Entity3d_Chain> theMesh_;


		std::weak_ptr<TModel_Surface> theSurface_;
		std::weak_ptr<TModel_Paired> thePaired_;
		std::weak_ptr<TModel_Wire> theWire_;
		std::weak_ptr<TModel_Edge> thePairedEdge_;

		Standard_Boolean theSense_;

		TopoDS_Edge theTEdge_;


		std::shared_ptr<Entity3d_Chain>& ChangeMesh() const
		{
			return theMesh_;
		}

	public:

		TModel_Edge
		(
			const std::shared_ptr<TModel_Vertex>& theVtx0,
			const std::shared_ptr<TModel_Vertex>& theVtx1, 
			const std::shared_ptr<TModel_Curve>& theCurve, 
			const std::shared_ptr<TModel_parCurve>& thePar,
			const Standard_Boolean theSense = Standard_True
		)
			: theVtx0_(theVtx0)
			, theVtx1_(theVtx1)
			, theCurve_(theCurve)
			, thePar_(thePar)
			, theSense_(theSense)
		{}

		TModel_Edge
		(
			const std::shared_ptr<TModel_Curve>& theCurve,
			const std::shared_ptr<TModel_parCurve>& thePar,
			const Standard_Boolean theSense = Standard_True
		)
			: theCurve_(theCurve)
			, thePar_(thePar)
			, theSense_(theSense)
		{}

		TModel_Edge
		(
			const Standard_Integer theIndex,
			const std::shared_ptr<TModel_Vertex>& theVtx0,
			const std::shared_ptr<TModel_Vertex>& theVtx1,
			const std::shared_ptr<TModel_Curve>& theCurve,
			const std::shared_ptr<TModel_parCurve>& thePar,
			const Standard_Boolean theSense = Standard_True
		)
			: theVtx0_(theVtx0)
			, theVtx1_(theVtx1)
			, theCurve_(theCurve)
			, thePar_(thePar)
			, theSense_(theSense)
			, TModel_Entity(theIndex)
		{}

		TModel_Edge
		(
			const Standard_Integer theIndex,
			const std::shared_ptr<TModel_Curve>& theCurve,
			const std::shared_ptr<TModel_parCurve>& thePar,
			const Standard_Boolean theSense = Standard_True
		)
			: theCurve_(theCurve)
			, thePar_(thePar)
			, theSense_(theSense)
			, TModel_Entity(theIndex)
		{}

		TModel_Edge
		(
			const Standard_Integer theIndex,
			const word& theName,
			const std::shared_ptr<TModel_Vertex>& theVtx0,
			const std::shared_ptr<TModel_Vertex>& theVtx1,
			const std::shared_ptr<TModel_Curve>& theCurve,
			const std::shared_ptr<TModel_parCurve>& thePar,
			const Standard_Boolean theSense = Standard_True
		)
			: theVtx0_(theVtx0)
			, theVtx1_(theVtx1)
			, theCurve_(theCurve)
			, thePar_(thePar)
			, theSense_(theSense)
			, TModel_Entity(theIndex, theName)
		{}

		TModel_Edge
		(
			const Standard_Integer theIndex,
			const word& theName,
			const std::shared_ptr<TModel_Curve>& theCurve,
			const std::shared_ptr<TModel_parCurve>& thePar,
			const Standard_Boolean theSense = Standard_True
		)
			: theCurve_(theCurve)
			, thePar_(thePar)
			, theSense_(theSense)
			, TModel_Entity(theIndex, theName)
		{}

		Standard_Boolean Sense() const
		{
			return theSense_;
		}

		const std::shared_ptr<TModel_Curve>& Geometry() const
		{
			return theCurve_;
		}

		const std::shared_ptr<TModel_parCurve>& Par() const
		{
			return thePar_;
		}

		const std::shared_ptr<Entity3d_Chain>& Mesh() const
		{
			return theMesh_;
		}

		void Discrete(const std::shared_ptr<Geo_ApprxCurveInfo>& theInfo) const;

		//- virtual functions and operators

		virtual Standard_Boolean IsDegenerated() const
		{
			return Standard_False;
		}

		virtual Standard_Boolean IsRing() const
		{
			return Standard_False;
		}


		//- Static functions and operators

		static Standard_Boolean 
			IsLess
			(
				const std::shared_ptr<TModel_Edge>& theEdge0, 
				const std::shared_ptr<TModel_Edge>& theEdge1
			)
		{
			Debug_Null_Pointer(theEdge0);
			Debug_Null_Pointer(theEdge1);

			return theEdge0->Index() < theEdge1->Index();
		}

		/*static std::shared_ptr<Entity3d_Chain> 
			GetStatic
			(
				const TModel_Edge& theEdge
			);*/

		//- Macros

		GLOBAL_ACCESS_SINGLE(std::weak_ptr<TModel_Surface>, Surface)
			GLOBAL_ACCESS_SINGLE(std::weak_ptr<TModel_Paired>, Paired)
			GLOBAL_ACCESS_SINGLE(std::weak_ptr<TModel_Edge>, PairedEdge)
			GLOBAL_ACCESS_SINGLE(std::weak_ptr<TModel_Wire>, Wire)
			GLOBAL_ACCESS_SINGLE(std::shared_ptr<TModel_Vertex>, Vtx0)
			GLOBAL_ACCESS_SINGLE(std::shared_ptr<TModel_Vertex>, Vtx1)

			GLOBAL_ACCESS_PRIM_SINGLE(TopoDS_Edge, TEdge)
	};
}

#endif // !_TModel_Edge_Header
