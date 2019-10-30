#pragma once
#ifndef _Cad3d_TModel_Header
#define _Cad3d_TModel_Header

#include <Global_Named.hxx>
#include <Global_Indexed.hxx>
#include <TModel_EntityManager.hxx>
#include <Entity3d_Box.hxx>
#include <OFstream.hxx>

#include <TopoDS_Shape.hxx>

class TopoDS_Face;
class TopoDS_Shape;

#include <memory>
#include <vector>

namespace AutLib
{

	// Forward Declarations
	class TModel_Vertex;
	class TModel_Edge;
	class TModel_Paired;
	class TModel_Surface;
	class TModel_Shell;

	class Cad3d_TModel
		: public Global_Indexed
		, public Global_Named
	{

		typedef std::shared_ptr<TModel_Shell> shell_ptr;
		typedef std::vector<shell_ptr> shellList;
		typedef TModel_EntityManager entityManager;

		typedef shell_ptr outer;
		typedef std::shared_ptr<shellList> inner;

		/*Private Data*/

		std::shared_ptr<entityManager> theVertices_;
		std::shared_ptr<entityManager> theEdges_;
		std::shared_ptr<entityManager> theSurfaces_;


		outer theOuter_;
		inner theInner_;

		Entity3d_Box theBoundingBox_;

		TopoDS_Shape theShape_;

		//- private functions and operators

		static Entity3d_Box CalcBoundingBox
		(
			const std::vector<std::shared_ptr<TModel_Surface>>& theSurfaces
		);

	protected:

		

	public:

		Cad3d_TModel()
		{}

		const Entity3d_Box& BoundingBox() const
		{
			return theBoundingBox_;
		}

		const std::shared_ptr<entityManager>& Corners() const
		{
			return theVertices_;
		}

		const std::shared_ptr<entityManager>& Segments() const
		{
			return theEdges_;
		}

		const std::shared_ptr<entityManager>& Faces() const
		{
			return theSurfaces_;
		}

		Standard_Integer NbFreeSegment() const;

		Standard_Boolean HasFreeSegment() const;

		Standard_Integer NbCorners() const
		{
			Debug_Null_Pointer(theEdges_);
			return (Standard_Integer)theEdges_->Size();
		}

		Standard_Integer NbSegments() const
		{
			Debug_Null_Pointer(theEdges_);
			return theEdges_->Size();
		}

		Standard_Integer NbFaces() const
		{
			Debug_Null_Pointer(theSurfaces_);
			return theSurfaces_->Size();
		}

		const outer& OuterShell() const
		{
			return theOuter_;
		}

		const inner& InnerShells() const
		{
			return theInner_;
		}

		const TopoDS_Shape& Shape() const
		{
			return theShape_;
		}

		void SetShape(const TopoDS_Shape& theShape)
		{
			theShape_ = theShape;
		}

		void RetrieveFacesTo
		(
			std::vector<std::shared_ptr<TModel_Surface>>& theSurfaces
		) const;

		void RetrieveSegmentsTo(std::vector<std::shared_ptr<TModel_Paired>>& theEdges) const;

		void RetrieveCornersTo(std::vector<std::shared_ptr<TModel_Vertex>>& thevertices) const;


		//- IO functions and operators

		void ExportCornersToPlt(OFstream& File) const;

		void ExportSegmentsToPlt(OFstream& File) const;

		void ExportFacesToPlt(OFstream& File) const;

		void ExportFreeSegmentsToPlt(OFstream& File) const;


		//- Static functions and operators

		static std::shared_ptr<Cad3d_TModel> 
			MakeSolid
			(
				const TopoDS_Shape& theShape, 
				const Standard_Real theTolerance
			);

		static std::shared_ptr<Cad3d_TModel> 
			MakeSolid
			(
				const std::vector<std::shared_ptr<TModel_Surface>>& theSurfaces,
				const Standard_Real theTolerance
			);

		//! returns true if the algorithm unable to construct a shell structure
		static Standard_Boolean 
			MakeShells
			(
				const std::shared_ptr<Cad3d_TModel>& theSolid
			);

		static void SplitByShells
		(
			const std::shared_ptr<Cad3d_TModel>& theSolid
		);
	};
}

#endif // !_Cad3d_TModel_Header
