#pragma once
#ifndef _Mesh_LineIntegrand_Header
#define _Mesh_LineIntegrand_Header

#include <Standard_TypeDef.hxx>
#include <iostream>

namespace AutLib
{

	template<class SizeMap>
	class Mesh_LineIntegrand
	{

		typedef typename SizeMap::ptType Point;

		/*Private Data*/

		const Point& theP0_;

		const SizeMap& theSizeMap_;

		Point theVector_;

	public:

		Mesh_LineIntegrand
		(
			const Point& theP0,
			const Point& theP1,
			const SizeMap& theSizeMap
		)
			: theP0_(theP0)
			, theSizeMap_(theSizeMap)
		{
			theVector_ = theP1 - theP0_;
		}

		const SizeMap& Map() const
		{
			return theSizeMap_;
		}

		const Point& Vector() const
		{
			return theVector_;
		}

		const Point& P0() const
		{
			return theP0_;
		}

		Point CalcPoint(const Standard_Real x) const
		{
			return theP0_ + theVector_ * x;
		}

	};

	namespace MeshLib
	{

		template<class SizeMap, bool UnitLength = false>
		struct Integrand
		{
			static Standard_Real _(const Standard_Real x, const Mesh_LineIntegrand<SizeMap>& theIntegrand)
			{
				return theIntegrand.Map().Integrand(theIntegrand.CalcPoint(x), theIntegrand.Vector());
			}
		};

		template<class SizeMap>
		struct Integrand<SizeMap, true>
		{
			static Standard_Real _(const Standard_Real x, const Mesh_LineIntegrand<SizeMap>& theIntegrand)
			{
				return theIntegrand.Map().IntegrandPerSize(theIntegrand.CalcPoint(x), theIntegrand.Vector());
			}
		};
	}
}

#endif // !_Mesh_LineIntegrand_Header