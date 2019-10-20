#pragma once
#ifndef _Pln_Edge_Header
#define _Pln_Edge_Header

#include <Entity2d_ChainFwd.hxx>
#include <Entity2d_Polygon.hxx>
#include <Geo_ApprxCurveInfo.hxx>
#include <Pln_Entity.hxx>
#include <error.hxx>
#include <OSstream.hxx>

#include <gp_Trsf2d.hxx>

#include <memory>

namespace AutLib
{

	// Forward Declarations
	class Pln_Vertex;
	class Pln_Curve;
	class Pln_Wire;

	class Pln_Edge
		: public Pln_Entity
	{

		typedef Geo_ApprxCurveInfo info;

		/*Private Data*/

		std::shared_ptr<Pln_Vertex> theVtx0_;
		std::shared_ptr<Pln_Vertex> theVtx1_;

		std::shared_ptr<Pln_Curve> theCurve_;

		std::weak_ptr<Pln_Wire> theWire_;

		Standard_Boolean SameSense_;

		mutable std::shared_ptr<Entity2d_Polygon> thePoly_;


		void Discretize() const;

	public:

		Pln_Edge
		(
			const std::shared_ptr<Pln_Vertex>& theV0,
			const std::shared_ptr<Pln_Vertex>& theV1,
			const std::shared_ptr<Pln_Curve>& theCurve,
			const Standard_Boolean Sense = Standard_True,
			const Standard_Boolean Discrete = Standard_False
		)
			: theVtx0_(theV0)
			, theVtx1_(theV1)
			, theCurve_(theCurve)
			, SameSense_(Sense)
		{
			if (Discrete) Discretize();
		}

		Pln_Edge
		(
			const Standard_Integer theIndex,
			const std::shared_ptr<Pln_Vertex>& theV0,
			const std::shared_ptr<Pln_Vertex>& theV1,
			const std::shared_ptr<Pln_Curve>& theCurve,
			const Standard_Boolean Sense = Standard_True,
			const Standard_Boolean Discrete = Standard_False
		)
			: Pln_Entity(theIndex)
			, theVtx0_(theV0)
			, theVtx1_(theV1)
			, theCurve_(theCurve)
			, SameSense_(Sense)
		{
			if (Discrete) Discretize();
		}

		Pln_Edge
		(
			const Standard_Integer theIndex,
			const word& theName,
			const std::shared_ptr<Pln_Vertex>& theV0,
			const std::shared_ptr<Pln_Vertex>& theV1,
			const std::shared_ptr<Pln_Curve>& theCurve,
			const Standard_Boolean Sense = Standard_True,
			const Standard_Boolean Discrete = Standard_False
		)
			: Pln_Entity(theIndex, theName)
			, theVtx0_(theV0)
			, theVtx1_(theV1)
			, theCurve_(theCurve)
			, SameSense_(Sense)
		{
			if (Discrete) Discretize();
		}

		Standard_Boolean SameSense() const
		{
			return SameSense_;
		}

		const std::shared_ptr<Pln_Vertex>& Vtx0() const
		{
			return theVtx0_;
		}

		const std::shared_ptr<Pln_Vertex>& Vtx1() const
		{
			return theVtx1_;
		}

		const std::shared_ptr<Pln_Curve>& Curve() const
		{
			return theCurve_;
		}

		const std::weak_ptr<Pln_Wire>& Wire() const
		{
			return theWire_;
		}

		const std::shared_ptr<Entity2d_Polygon>& Approx() const
		{
			return thePoly_;
		}

		void Transform(const gp_Trsf2d& transform, const Standard_Boolean ApplyToMesh = Standard_True);

		void Reverse(const Standard_Boolean ApplyToMesh = Standard_True);

		void Approx(const info& theInfo) const;

		void Split
		(
			const Standard_Real x,
			std::shared_ptr<Pln_Vertex>& theVertex,
			std::shared_ptr<Pln_Edge>& theLeft,
			std::shared_ptr<Pln_Edge>& theRight
		) const;

		void Split
		(
			const std::vector<Standard_Real>& theParameters,
			std::vector<std::shared_ptr<Pln_Vertex>>& theVertices,
			std::vector<std::shared_ptr<Pln_Edge>>& theEdges
		) const;

		void SetVtx0(const std::shared_ptr<Pln_Vertex>& theVtx0)
		{
			theVtx0_ = theVtx0;
		}

		void SetVtx1(const std::shared_ptr<Pln_Vertex>& theVtx1)
		{
			theVtx1_ = theVtx1;
		}

		void SetCurve(const std::shared_ptr<Pln_Curve>& theCurve)
		{
			theCurve_ = theCurve;
		}

		void SetWire(const std::weak_ptr<Pln_Wire>& theWire)
		{
			theWire_ = theWire;
		}

		//- virtual functions and operators

		virtual Standard_Boolean IsRing() const
		{
			return Standard_False;
		}

		//- Static functions and operators

		static void Discretize(const Pln_Edge& theEdge);

		static std::vector<std::shared_ptr<Pln_Edge>>
			MakeEdges
			(
				const std::vector<std::shared_ptr<Pln_Curve>>& theCurves,
				const Standard_Real theTol
			);

		static std::vector<std::shared_ptr<Pln_Curve>>
			RetrieveCurves
			(
				const std::vector<std::shared_ptr<Pln_Edge>>& theEdges
			);

		static std::vector<std::shared_ptr<Pln_Vertex>>
			RetrieveVertices
			(
				const std::vector<std::shared_ptr<Pln_Edge>>& theEdges
			);

		static Standard_Boolean IsLess
		(
			const std::shared_ptr<Pln_Edge>& theEdge0,
			const std::shared_ptr<Pln_Edge>& theEdge1
		)
		{
			Debug_Null_Pointer(theEdge0);
			Debug_Null_Pointer(theEdge1);
			return theEdge0->Index() < theEdge1->Index();
		}

		static Standard_Boolean IsLess
		(
			const std::weak_ptr<Pln_Edge>& theEdge0,
			const std::weak_ptr<Pln_Edge>& theEdge1
		)
		{
			Debug_Null_Pointer(theEdge0.lock());
			Debug_Null_Pointer(theEdge1.lock());
			return theEdge0.lock()->Index() < theEdge1.lock()->Index();
		}
	};
}

#endif // !_Pln_Edge_Header
