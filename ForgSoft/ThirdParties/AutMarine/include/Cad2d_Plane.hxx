#pragma once
#ifndef _Cad2d_Plane_Header
#define _Cad2d_Plane_Header

#include <Entity2d_Box.hxx>
#include <Pln_Entity.hxx>
#include <Cad2d_PlaneInfo.hxx>
#include <Cad_EntityManager.hxx>

#include <memory>
#include <vector>

namespace AutLib
{

	// Forward Declarations
	class Pln_Wire;
	class Pln_Edge;
	class Pln_Curve;
	class Pln_Vertex;


	class Cad2d_Plane
		: public Pln_Entity
	{

		typedef std::shared_ptr<Pln_Wire> wire_ptr;
		typedef std::vector<wire_ptr> wireList;

		typedef wire_ptr outer;
		typedef std::shared_ptr<wireList> inner;

		typedef Cad2d_PlaneInfo info;

		/*Private Data*/

		std::shared_ptr<Cad_EntityManager<Pln_Vertex>> theVertices_;
		std::shared_ptr<Cad_EntityManager<Pln_Edge>> theEdges_;

		outer theOuter_;
		inner theInner_;

		Entity2d_Box theBoundingBox_;

		std::shared_ptr<info> theInfo_;

		void SplitByWires();

		void Make(const std::vector<std::shared_ptr<Pln_Curve>>& theCurves);

	public:

		typedef Pln_Entity entityType;

		Cad2d_Plane(const std::shared_ptr<info>& theInfo)
			: theInfo_(theInfo)
		{}

		Cad2d_Plane
		(
			const Standard_Integer theIndex,
			const std::shared_ptr<info>& theInfo
		)
			: Pln_Entity(theIndex)
			, theInfo_(theInfo)
		{}

		Cad2d_Plane
		(
			const Standard_Integer theIndex,
			const word& theName,
			const std::shared_ptr<info>& theInfo
		)
			: Pln_Entity(theIndex, theName)
			, theInfo_(theInfo)
		{}

		const Entity2d_Box& BoundingBox() const
		{
			return theBoundingBox_;
		}

		const std::shared_ptr<Cad_EntityManager<Pln_Vertex>>& Vertices() const
		{
			return theVertices_;
		}

		const std::shared_ptr<Cad_EntityManager<Pln_Edge>>& Edges() const
		{
			return theEdges_;
		}

		Standard_Integer NbFreeCorners() const;

		Standard_Boolean HasFreeCorner() const;

		Standard_Integer NbCorners() const
		{
			Debug_Null_Pointer(theVertices_);
			return (Standard_Integer)theVertices_->Size();
		}

		Standard_Integer NbEdges() const
		{
			Debug_Null_Pointer(theEdges_);
			return (Standard_Integer)theEdges_->Size();
		}

		Standard_Integer NbHoles() const
		{
			if (NOT theInner_) return 0;
			return (Standard_Integer)theInner_->size();
		}

		const std::shared_ptr<info>& Info() const
		{
			return theInfo_;
		}

		const outer& OuterWire() const
		{
			return theOuter_;
		}

		const inner& InnerWires() const
		{
			return theInner_;
		}

		void OverridePlaneInfo
		(
			const std::shared_ptr<info>& theInfo
		)
		{
			theInfo_ = theInfo;
		}

		void RetrieveEdgesTo(std::vector<std::shared_ptr<Pln_Edge>>& theEdges) const;

		void RetrieveWiresTo(std::vector<std::shared_ptr<Pln_Wire>>& theWires) const;

		void Mirror(const gp_Pnt2d& P);

		void Mirror(const gp_Ax2d& A);

		void Rotate(const gp_Pnt2d& P, const Standard_Real Ang);

		void Scale(const gp_Pnt2d& P, const Standard_Real S);

		void Translate(const gp_Vec2d& V);

		void Translate(const gp_Pnt2d& P1, const gp_Pnt2d& P2);

		void Transform(const gp_Trsf2d& T);

		void Report(Standard_OStream& Ostream = cout) const;

		void ExportToPlt(OFstream& File) const;
	};
}

#endif // !_Cad2d_Plane_Header
