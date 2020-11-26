#pragma once
#ifndef _Mesh_OptNode_Analytical_Header
#define _Mesh_OptNode_Analytical_Header

#include <Global_Done.hxx>
#include <Standard_TypeDef.hxx>

namespace tnbLib
{

	template<class FrontType, class MetricType = void>
	class Aft_OptNode_Analytical
		: public Global_Done
	{

		typedef typename FrontType::nodeType::ptType Point;

		/*Private Data*/

		Standard_Real theSize_;

		const MetricType& theMetric_;
		const FrontType& theFront_;

		Point theCoord_;


		Point& ChangeCoord()
		{
			return theCoord_;
		}

	public:

		Aft_OptNode_Analytical
		(
			const Standard_Real theSize,
			const MetricType& theMetric,
			const FrontType& theFront
		)
			: theSize_(theSize)
			, theMetric_(theMetric)
			, theFront_(theFront)
		{}

		auto ElementSize() const
		{
			return theSize_;
		}

		const auto& Metric() const
		{
			return theMetric_;
		}

		const auto& Front() const
		{
			return theFront_;
		}

		const auto& Coord() const
		{
			return theCoord_;
		}

		void Perform();
	};

	template<class FrontType>
	class Aft_OptNode_Analytical<FrontType, void>
		: public Global_Done
	{

		typedef typename FrontType::nodeType::ptType Point;

		/*Private Data*/

		Standard_Real theSize_;

		const FrontType& theFront_;

		Point theCoord_;


		Point& ChangeCoord()
		{
			return theCoord_;
		}

	public:

		Aft_OptNode_Analytical
		(
			const Standard_Real theSize,
			const FrontType& theFront
		)
			: theSize_(theSize)
			, theFront_(theFront)
		{}

		auto ElementSize() const
		{
			return theSize_;
		}

		const auto& Front() const
		{
			return theFront_;
		}

		const auto& Coord() const
		{
			return theCoord_;
		}

		void Perform();
	};
}

#endif // !_Mesh_OptNode_Analytical_Header