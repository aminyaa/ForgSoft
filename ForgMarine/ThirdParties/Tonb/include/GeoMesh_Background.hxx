#pragma once
#ifndef _GeoMesh_Background_Header
#define _GeoMesh_Background_Header

#include <GeoMesh_Background_Info.hxx>
#include <Entity_Box.hxx>
#include <error.hxx>
#include <OSstream.hxx>
#include <IFstream.hxx>

#include <memory>
#include <vector>

//#include <GeoMesh2d_Data.hxx>

namespace tnbLib
{

	template<class ElementType>
	struct GeoMesh_Background_Cache
	{
		mutable std::shared_ptr<ElementType> Current;
	};

	template<class MeshData>
	class GeoMesh_Background_Base
		: public GeoMesh_Background_Cache<typename MeshData::elementType>
	{

		typedef typename MeshData::elementType elementType;
		typedef typename elementType::nodeType::ptType Point;

		typedef Entity_Box<Point> box;
		typename GeoMesh_Background_Cache<typename MeshData::elementType> base;

		/*Private Data*/

		std::shared_ptr<MeshData> theMesh_;

		Entity_Box<Point> theBoundingBox_;



	public:

		GeoMesh_Background_Base()
		{}

		GeoMesh_Background_Base
		(
			const std::shared_ptr<MeshData>& theMesh
		)
			: theMesh_(theMesh)
		{}

		Standard_Boolean IsLoaded() const
		{
			return (Standard_Boolean)theMesh_;
		}

		const std::shared_ptr<MeshData>& Mesh() const
		{
			return theMesh_;
		}

		const std::shared_ptr<elementType>& CurrentElement() const
		{
			return base::Current;
		}

		void LoadData
		(
			const std::shared_ptr<MeshData>& theMesh
		)
		{
			theMesh_ = theMesh;
		}

		void SetCurrent
		(
			const std::shared_ptr<elementType>& theElement
		)
		{
			base::Current = theElement;
		}

		void InitiateCurrentElement() const
		{
			if (!theMesh_)
			{
				FatalErrorIn("void InitiateCurrentElement() const")
					<< " Null pointer has been encountered!" << endl
					<< abort(FatalError);
			}
			base::Current = theMesh_->Elements()[0];
		}
	};


	template<class MeshData, class Type>
	class GeoMesh_Background
		: public GeoMesh_Background_Base<MeshData>
	{

	public:

		typedef std::vector<Type> sources;

		typedef typename MeshData::elementType elementType;
		typedef typename elementType::nodeType::ptType Point;
		typedef typename elementType::nodeType nodeType;

		typedef GeoMesh_Background_Base<MeshData> base;
		typedef GeoMesh_Background_SmoothingHvCorrection_Info hvInfo;
		//typedef GeoMesh_Background_SmoothingLaplacianInfo laplacianInfo;

	private:

		/*Private Data*/

		mutable std::shared_ptr<sources> theSources_;

		void HvCorrection
		(
			const std::vector<std::shared_ptr<nodeType>>& nodes,
			const Standard_Real Factor,
			const Standard_Integer MaxInnerIteration
		);

		/*void LaplacianSmoothing
		(
			const std::vector<std::shared_ptr<nodeType>>& nodes,
			const Standard_Integer NbIterations,
			const Standard_Real Factor
		);*/

	public:



		GeoMesh_Background()
		{}

		GeoMesh_Background
		(
			const std::shared_ptr<MeshData>& theMesh,
			const std::shared_ptr<sources>& theSources
		)
			: base(theMesh)
			, theSources_(theSources)
		{
			if (NOT theSources_)
			{
				FatalErrorIn("GeoMesh_Background()")
					<< "Null pointer has been encountered!"
					<< abort(FatalError);
			}
		}

		Type InterpolateAt(const Point& theCoord) const;

		Type InterpolateAt(const Point& theCoord, Standard_Boolean& Sense) const;

		std::shared_ptr<sources>& Sources() const
		{
			return theSources_;
		}

		void HvCorrection(const std::shared_ptr<hvInfo> theInfo);
		//void LaplacianSmoothing(const std::shared_ptr<laplacianInfo>& theInfo);

		// - IO functions and operators

		void ExportToPlt(OFstream & File) const;

		void ReadBackMeshFrom(IFstream& File);

		template<class Type, class MeshData>
		friend Istream& operator>>
			(
				Istream& is,
				GeoMesh_Background& theBack
				);
	};
}

#include <GeoMesh_BackgroundI.hxx>

#endif // !_GeoMesh_Background_Header