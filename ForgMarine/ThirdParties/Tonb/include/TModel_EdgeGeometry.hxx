#pragma once
#ifndef _TModel_EdgeGeometry_Header
#define _TModel_EdgeGeometry_Header

#include <Global_AccessMethod.hxx>
#include <Entity3d_ChainFwd.hxx>

#include <memory>

namespace tnbLib
{

	// Forward Declarations
	class TModel_ParaCurve;
	class TModel_Curve;
	class Geo_ApprxCurve_Info;

	class TModel_EdgeGeometry
	{

		/*Private Data*/

		std::shared_ptr<TModel_Curve> theCurve_;
		std::shared_ptr<TModel_ParaCurve> theParaCurve_;

		mutable std::shared_ptr<Entity3d_Chain> theMesh_;

		Standard_Boolean theSense_;

		auto& ChangeMesh() const
		{
			return theMesh_;
		}

	protected:

		TModel_EdgeGeometry
		(
			const std::shared_ptr<TModel_Curve>& theCurve, 
			const std::shared_ptr<TModel_ParaCurve>& thePara,
			const Standard_Boolean theSense = Standard_True
		)
			: theCurve_(theCurve)
			, theParaCurve_(thePara)
			, theSense_(theSense)
		{}

	public:

		auto Sense() const
		{
			return theSense_;
		}

		const auto& Curve() const
		{
			return theCurve_;
		}

		const auto& ParaCurve() const
		{
			return theParaCurve_;
		}

		const auto& Mesh() const
		{
			return theMesh_;
		}

		void Discrete
		(
			const std::shared_ptr<Geo_ApprxCurve_Info>& theInfo
		) const;

		//- Macros
		
	};
}

#endif // !_TModel_EdgeGeometry_Header
