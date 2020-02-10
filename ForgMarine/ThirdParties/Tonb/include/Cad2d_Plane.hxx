#pragma once
#ifndef _Cad2d_Plane_Header
#define _Cad2d_Plane_Header

#include <Global_AccessMethod.hxx>
#include <Pln_Entity.hxx>
#include <Entity2d_Box.hxx>
#include <OFstream.hxx>

#include <vector>

class gp_Ax22d;
class gp_Ax2d;

#include <gp.hxx>
#include <gp_Ax2.hxx>

namespace tnbLib
{

	// Forward Declarations
	template<class EntityType>
	class Cad_EntityManager;

	class Pln_Wire;
	class Pln_Edge;
	class Pln_Curve;
	class Pln_Vertex;

	class Cad2d_Plane_Info;

	class Cad2d_Plane_Manager
	{

		/*private Data*/

		std::shared_ptr<Cad_EntityManager<Pln_Vertex>> theVertices_;
		std::shared_ptr<Cad_EntityManager<Pln_Edge>> theEdges_;

	protected:

		Cad2d_Plane_Manager()
		{}


		auto& ChangeCorners()
		{
			return theVertices_;
		}

		auto& ChangeSegments() 
		{
			return theEdges_;
		}

	public:

		Standard_Integer NbCorners() const;

		Standard_Integer NbSegments() const;

		const auto& Corners() const
		{
			return theVertices_;
		}

		const auto& Segments() const
		{
			return theEdges_;
		}
	};

	class Cad2d_Plane
		: public Pln_Entity
		, public Cad2d_Plane_Manager
	{

		typedef std::vector<std::shared_ptr<Pln_Wire>> wireList;
		typedef std::shared_ptr<Pln_Wire> outer;
		typedef std::shared_ptr<wireList> inner;

		typedef Cad2d_Plane_Info info;

		/*Private Data*/	

		outer theOuter_;
		inner theInner_;

		Entity2d_Box theBoundingBox_;

		std::shared_ptr<info> theInfo_;


		gp_Ax2 theSystem_;



		void Make
		(
			const outer& theOuter,
			const inner& theInners
		);

		static void CheckOuter(const outer& theOuter, const char* theName);

		static void CheckInner(const std::shared_ptr<Pln_Wire>& theInner, const char* theName);

		static void CheckInners(const inner& theInner, const char* theName);

	public:

		Cad2d_Plane
		(
			const std::shared_ptr<info>& theInfo,
			const gp_Ax2& theSystem = gp::XOY()
		);

		Cad2d_Plane
		(
			const Standard_Integer theIndex,
			const std::shared_ptr<info>& theInfo,
			const gp_Ax2& theSystem = gp::XOY()
		);

		Cad2d_Plane
		(
			const Standard_Integer theIndex,
			const word& theName,
			const std::shared_ptr<info>& theInfo,
			const gp_Ax2& theSystem = gp::XOY()
		);

	public:


		const auto& BoundingBox() const
		{
			return theBoundingBox_;
		}

		Standard_Integer NbFreeCorners() const;

		Standard_Integer NbHoles() const;

		Standard_Boolean HasFreeCorner() const;

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

		void OverrideInfo
		(
			const std::shared_ptr<info>& theInfo
		)
		{
			theInfo_ = theInfo;
		}

		void ExportToPlt(OFstream& File) const;

		//- Static functions

		static std::shared_ptr<Cad2d_Plane>
			MakePlane
			(
				const std::shared_ptr<Pln_Wire>& theOuter,
				const std::shared_ptr<std::vector<std::shared_ptr<Pln_Wire>>>& theInners,
				const std::shared_ptr<Cad2d_Plane_Info>& thePlnInfo,
				const gp_Ax2& theSystem = gp::XOY()
			);

		static void SplitByWires
		(
			const std::shared_ptr<Cad2d_Plane>& thePlane
		);

		static const std::shared_ptr<Pln_Wire>& 
			RetrieveOuterWire
			(
				const std::vector<std::shared_ptr<Pln_Wire>>& theWires
			);

		static void CheckOuterWire
		(
			const std::shared_ptr<Pln_Wire>& theOuter,
			const std::vector<std::shared_ptr<Pln_Wire>>& theWires
		);

		static void CheckWires
		(
			const std::vector<std::shared_ptr<Pln_Wire>>& theWires
		);

		static std::shared_ptr<Cad2d_Plane> 
			MakeBox
			(
				const Pnt2d& theCorner, 
				const Standard_Real theDx, 
				const Standard_Real theDy,
				const std::shared_ptr<Cad2d_Plane_Info>& thePlnInfo,
				const gp_Ax2& theSystem = gp::XOY()
			);

		static std::shared_ptr<Cad2d_Plane> 
			MakeBox
			(
				const Pnt2d& theP0, 
				const Pnt2d& theP1,
				const std::shared_ptr<Cad2d_Plane_Info>& thePlnInfo,
				const gp_Ax2& theSystem = gp::XOY()
			);

		static std::shared_ptr<Cad2d_Plane> MakeCircle(const gp_Ax22d& A, const Standard_Real Radius);

		static std::shared_ptr<Cad2d_Plane> MakeCircle(const gp_Ax2d& A, const Standard_Real Radius, const Standard_Boolean Sense = Standard_True);

		//- Macros
		GLOBAL_ACCESS_SINGLE(gp_Ax2, System)
	};
}

#endif // !_Cad2d_Plane_Header
