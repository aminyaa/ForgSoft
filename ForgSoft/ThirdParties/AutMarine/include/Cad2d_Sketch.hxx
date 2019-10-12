#pragma once
#ifndef _Cad2d_Sketch_Header
#define _Cad2d_Sketch_Header

#include <Global_Done.hxx>
#include <Pnt2d.hxx>
#include <Dir2d.hxx>
#include <Entity2d_Box.hxx>
#include <Geom_AdTree.hxx>
#include <Pln_Vertex.hxx>
#include <Cad2d_SketchInfo.hxx>

#include <vector>
#include <map>

namespace AutLib
{

	// Forward Declarations
	class Pln_Vertex;
	class Pln_Edge;
	class Pln_Wire;
	class Cad2d_Plane;

	struct Cad2d_SketchCache
	{

	protected:

		mutable Standard_Boolean PickedUpVertex;
		mutable Standard_Boolean PickedUpEdge;
	};

	class Cad2d_Sketch
		: public Cad2d_SketchCache
		, public Global_Done
	{

		typedef Cad2d_SketchInfo info;

		/*Private Data*/

		Geom_AdTree<std::shared_ptr<Pln_Vertex>> theSearch_;

		std::map<Standard_Integer, std::shared_ptr<Pln_Vertex>> theVertices_;
		std::map<Standard_Integer, std::shared_ptr<Pln_Edge>> theEdges_;
		std::map<Standard_Integer, std::shared_ptr<Pln_Wire>> theWires_;

		Standard_Real theTolerance_;

		Standard_Integer theNbVertices_;
		Standard_Integer theNbEdges_;

		std::shared_ptr<info> theInfo_;

		std::shared_ptr<Pln_Vertex> CheckToInsert(const Pnt2d& theCoord, const Standard_Real theTol) const;

		static std::shared_ptr<Pln_Edge>
			CheckEdge
			(
				const std::shared_ptr<Pln_Vertex>& thePt0,
				const std::shared_ptr<Pln_Vertex>& thePt1
			);

	public:

		static const Standard_Real DEFAULT_TOLERANCE;

		Cad2d_Sketch(const std::shared_ptr<info>& theInfo);

		const std::shared_ptr<info>& Info() const
		{
			return theInfo_;
		}

		Standard_Real Tolerance() const
		{
			return theTolerance_;
		}

		std::shared_ptr<Pln_Vertex> PickUpVertex(const Pnt2d& theCoord);

		std::shared_ptr<Pln_Vertex> PickUpVertex(const Pnt2d& theCoord, const Standard_Real thePrec);

		std::shared_ptr<Pln_Edge> PickUpEdge(const std::shared_ptr<Pln_Vertex>& thePt0, const std::shared_ptr<Pln_Vertex>& thePt1);

		std::vector<std::shared_ptr<Pln_Edge>> CreateRectangle(const std::shared_ptr<Pln_Vertex>& thePt0, const std::shared_ptr<Pln_Vertex>& thePt1);

		Standard_Boolean CraeteCircle(const std::shared_ptr<Pln_Vertex>& theCentre, const std::shared_ptr<Pln_Vertex>& theP0, const Standard_Real theDeg);

		Standard_Boolean CraeteCircle(const std::shared_ptr<Pln_Vertex>& theCentre, const Standard_Real theRadius, const Dir2d& theDir, const Standard_Real theDeg);

		Standard_Boolean CraeteCircle(const Pnt2d& theCentre, const Standard_Real theRadius, const Standard_Real theDeg);

		Standard_Boolean CraeteCircle(const Pnt2d& theCentre, const Standard_Real theRadius);

		Standard_Boolean CraeteCircle(const Pnt2d& theCentre, const Standard_Real theRadius, const Dir2d& theDir);

		Standard_Boolean CreateEllipse(const Pnt2d& theCentre, const Standard_Real theMajorRadius, const Standard_Real theMinorRadius);

		Standard_Boolean CreateEllipse(const Pnt2d& theCentre, const Standard_Real theMajorRadius, const Standard_Real theMinorRadius, const Standard_Real theDeg);

		Standard_Boolean CreateEllipse(const Pnt2d& theCentre, const Standard_Real theMajorRadius, const Standard_Real theMinorRadius, const Dir2d& theMajorDir, const Standard_Real theDeg);

		Standard_Boolean CreatePolygon(const std::vector<Pnt2d>& theQ);

		Standard_Boolean Craeteinterpolation(const std::vector<Pnt2d>& theQ, const Standard_Integer theDeg = 2, const Standard_Real theTolerance = 1.0E-4);


		Standard_Boolean RemoveVertex(const std::shared_ptr<Pln_Vertex>& theVtx);


		std::shared_ptr<Pln_Wire> MakeWire(const std::vector<std::shared_ptr<Pln_Edge>>& theEdges) const;

		std::vector<std::shared_ptr<Pln_Wire>> MakeWire(const gp_Ax22d& A) const;

		std::vector<std::shared_ptr<Pln_Wire>> MakeWire(const gp_Ax2d& A, const Standard_Boolean Sense = Standard_True) const;


		void Clear();

		void ExportToPlt(OFstream& File) const;

	};
}

#endif // !_Cad2d_Sketch_Header