#pragma once
#ifndef _Geo2d_DelTri_Header
#define _Geo2d_DelTri_Header

#include <Pnt2d.hxx>
#include <Entity_Connectivity.hxx>

#include <memory>
#include <vector>

namespace AutLib
{

	// Forward Declarations
	template<class Point, class Connectivity, bool NeighbData>
	class Entity_StaticData;

	class Geo2d_DelTriInfo
	{

		/*Private Data*/

		Standard_Integer theNbTriangles_;
		Standard_Integer theNbPoints_;

	protected:

		void IncrementTri()
		{
			theNbTriangles_++;
		}

		void IncrementPts()
		{
			theNbPoints_++;
		}

		Standard_Integer& ChangeNbTriangles()
		{
			return theNbTriangles_;
		}

		Standard_Integer& ChangeNbPts()
		{
			return theNbPoints_;
		}

	public:

		Geo2d_DelTriInfo()
			: theNbTriangles_(0)
			, theNbPoints_(0)
		{}

		Standard_Integer NbTriangles() const
		{
			return theNbTriangles_;
		}

		Standard_Integer NbPoints() const
		{
			return theNbPoints_;
		}
	};

	class Geo2d_DelTri
		: public Geo2d_DelTriInfo
	{

		typedef Entity_StaticData<Pnt2d, connectivity::triple, true>
			staticData;

		/*Private Data*/

		std::shared_ptr<staticData> theData_;

		Standard_Integer Edge
		(
			const Standard_Integer L,
			const Standard_Integer
		) const;

		Standard_Integer TriLoc
		(
			const Pnt2d& theCoord
		) const
		{
			return TriLoc(theCoord, NbTriangles());
		}

		Standard_Integer TriLoc
		(
			const Pnt2d& theCoord,
			const Standard_Integer i
		) const;

		void Delaunay();

	public:

		Geo2d_DelTri()
		{}

		Geo2d_DelTri(const std::vector<Pnt2d>& thePts);

		const std::shared_ptr<staticData>& Data() const
		{
			return theData_;
		}

		void Triangulate();

		void Import(const std::vector<Pnt2d>& thePts);
	};
}

#include <Geo2d_DelTriI.hxx>

#endif // !_Geo2d_DelTri_Header
