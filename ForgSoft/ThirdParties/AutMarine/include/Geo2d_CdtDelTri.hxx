#pragma once
#ifndef _Geo2d_CdtDelTri_Header
#define _Geo2d_CdtDelTri_Header

#include <Pnt2d.hxx>
#include <Entity_Connectivity.hxx>
#include <Entity2d_Polygon.hxx>

#include <memory>
#include <vector>

namespace AutLib
{

	// Forward Declarations
	template<class Point, class Connectivity, bool NeighbData>
	class Entity_StaticData;

	typedef std::vector<std::shared_ptr<Entity2d_Polygon>> polygonList;

	class Geo2d_CdtDelTri
	{

		typedef Entity_StaticData<Pnt2d, connectivity::triple, false>
			staticData;

		/*Private Data*/

		std::shared_ptr<staticData> theData_;

		const std::vector<Pnt2d>& thePts_;
		const polygonList& theConstraints_;

		Standard_Boolean HandleDegeneracy_;

	public:

		Geo2d_CdtDelTri
		(
			const std::vector<Pnt2d>& thePts, 
			const polygonList& theConstraints
		)
			: thePts_(thePts)
			, theConstraints_(theConstraints)
			, HandleDegeneracy_(Standard_False)
		{}

		const std::shared_ptr<staticData>& Data() const
		{
			return theData_;
		}

		void SetToHandleDegeneracy()
		{
			HandleDegeneracy_ = Standard_True;
		}

		void Perform();
	};
}

#endif // !_Geo2d_CdtDelTri_Header
