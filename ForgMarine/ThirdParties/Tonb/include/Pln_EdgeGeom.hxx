#pragma once
#ifndef _Pln_EdgeGeom_Header
#define _Pln_EdgeGeom_Header

#include <Standard_TypeDef.hxx>
#include <Entity2d_PolygonFwd.hxx>
#include <Global_AccessMethod.hxx>

#include <memory>

namespace tnbLib
{

	// Forward Declarations
	class Pln_Curve;
	class Geo_ApprxCurve_Info;

	class Pln_EdgeGeom
	{

		/*Private Data*/

		std::shared_ptr<Pln_Curve> theCurve_;

		Standard_Boolean Sense_;

		mutable std::shared_ptr<Entity2d_Polygon> theMesh_;

	protected:

		Pln_EdgeGeom()
			: Sense_(Standard_True)
		{}

		Pln_EdgeGeom
		(
			const std::shared_ptr<Pln_Curve>& theCurve, 
			const Standard_Boolean theSense
		)
			: theCurve_(theCurve)
			, Sense_(theSense)
		{}

		Standard_Boolean& ChangeSense()
		{
			return Sense_;
		}

	public:

		Standard_Boolean Sense() const
		{
			return Sense_;
		}

		std::shared_ptr<Entity2d_Polygon>& Mesh() const
		{
			return theMesh_;
		}

		void Approx
		(
			const std::shared_ptr<Geo_ApprxCurve_Info>& theInfo
		) const;

		void ClearMesh()
		{
			Mesh().reset();
		}

		//- Macros
		GLOBAL_ACCESS_SINGLE(std::shared_ptr<Pln_Curve>, Curve)
	};
}

#endif // !_Pln_EdgeGeom_Header
