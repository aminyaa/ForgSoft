#pragma once
#ifndef _Mesh2d_OptNodeAnIso_Analytical_Header
#define _Mesh2d_OptNodeAnIso_Analytical_Header

#include <Global_Done.hxx>
#include <Mesh_OptNode_Analytical.hxx>
#include <Aft2d_EdgeAnIso.hxx>

namespace AutLib
{

	class Mesh2d_OptNodeAnIso_Analytical_Base
	{

		/*Private Data*/

	protected:

		Mesh2d_OptNodeAnIso_Analytical_Base()
		{}

	public:

		static const Standard_Real C3;

		static Pnt2d CalcCoord
		(
			const Standard_Real theSize,
			const Aft2d_EdgeAnIso& theEdge,
			const Entity2d_Metric1& theMetric
		);
	};

	class Mesh2d_OptNodeAnIso_Analytical
		: public Mesh2d_OptNodeAnIso_Analytical_Base
		, public Global_Done
	{

		typedef Entity2d_Metric1 metric;
		typedef Aft2d_EdgeAnIso frontType;
		typedef Pnt2d Point;

		/*Private Data*/

		Standard_Real theSize_;

		const frontType& theFront_;
		const metric& theMap_;

		Point theCoord_;


		Point& ChangeCoord()
		{
			return theCoord_;
		}

	public:


		Mesh2d_OptNodeAnIso_Analytical
		(
			const Standard_Real theSize,
			const frontType& theFront,
			const metric& theMap
		)
			: theSize_(theSize)
			, theFront_(theFront)
			, theMap_(theMap)
		{}


		Standard_Real ElementSize() const
		{
			return theSize_;
		}

		const frontType& Front() const
		{
			return theFront_;
		}

		const metric& MetricMap() const
		{
			return theMap_;
		}

		const Point& Coord() const
		{
			return theCoord_;
		}

		void Perform();
	};
}

#include <Mesh2d_OptNodeAnIso_AnalyticalI.hxx>

#endif // !_Mesh2d_OptNodeAnIso_Analytical_Header
