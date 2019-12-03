#pragma once
#ifndef _Aft_OptNode_Corrector_Header
#define _Aft_OptNode_Corrector_Header

#include <Global_Done.hxx>
#include <Geo_MetricPrcsr.hxx>
#include <Aft_OptNode_Corrector_Type.hxx>

namespace AutLib
{

	// Forward Declarations
	template<class SizeFun, class MetricFun>
	class Geo_MetricPrcsr;

	template<Aft_OptNode_Corrector_Type Type, class FrontType, class InfoType, class SizeFun, class MetricFun = void>
	class Aft_OptNode_Corrector
		: public Global_Done
	{

		typedef typename SizeFun::ptType Point;
		typedef Geo_MetricPrcsr<SizeFun, MetricFun> metricMap;

		/*Private Data*/

		Standard_Real theSize_;

		const metricMap& theMap_;
		const FrontType& theFront_;
		const Point& theP0_;

		Point theCoord_;

		Standard_Boolean IsConverged_;

	protected:


		Point& ChangeCoord()
		{
			return theCoord_;
		}

		Standard_Boolean& Change_IsConverged()
		{
			return IsConverged_;
		}

	public:


		Aft_OptNode_Corrector
		(
			const metricMap& theMap,
			const FrontType& theFront,
			const Point& theP0,
			const Standard_Real theSize
		)
			: theMap_(theMap)
			, theFront_(theFront)
			, theP0_(theP0)
			, theSize_(theSize)
			, IsConverged_(Standard_False)
		{}

		Standard_Real Size() const
		{
			return theSize_;
		}

		const metricMap& MetricMap() const
		{
			return theMap_;
		}

		const FrontType& Front() const
		{
			return theFront_;
		}

		const Point& Coord() const
		{
			return theCoord_;
		}

		const Point& P0() const
		{
			return theP0_;
		}

		Standard_Boolean IsConverged() const
		{
			return IsConverged_;
		}

		void Perform(const InfoType& theInfo);

	};
}

#endif // !_Aft_OptNode_Corrector_Header
