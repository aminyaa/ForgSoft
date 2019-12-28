#pragma once
#ifndef _Aft_CorrOptNode_Iterative_Tools_Header
#define _Aft_CorrOptNode_Iterative_Tools_Header

#include <Standard_TypeDef.hxx>
#include <Geo_MetricPrcsr.hxx>
#include <error.hxx>
#include <OSstream.hxx>

#include <gp.hxx>

namespace AutLib
{

	class Aft_CorrOptNode_Iterative_Tools
	{

	public:

		template<class FrontType, class SizeFun, class MetricFun, class InfoType>
		static Standard_Boolean Correct
		(
			const Geo_MetricPrcsr<SizeFun, MetricFun>& theMap,
			typename SizeFun::ptType& theP0,
			const FrontType& theEdge, 
			const InfoType& theInfo
		)
		{
			auto P = theP0;

			const auto& map = theMap;
			const auto& info = theInfo;

			const auto omega = info.UnderRelaxation();
			const auto tol = info.Tolerance();

			const auto& edge = theEdge;

			Debug_Null_Pointer(edge.Node0());
			Debug_Null_Pointer(edge.Node1());
			const auto& v0 = edge.Node0()->Coord();
			const auto& v1 = edge.Node1()->Coord();

			Standard_Boolean cond = Standard_True;
			Standard_Integer Iter = 0;
			do
			{
				auto d0 = map.CalcUnitDistance(v0, P);
				auto d1 = map.CalcUnitDistance(v1, P);

				Debug_If_Condition(d0 <= gp::Resolution());
				Debug_If_Condition(d1 <= gp::Resolution());

				auto Pa = v0 + (P - v0) / d0;
				auto Pb = v1 + (P - v1) / d1;

				auto Pn = 0.5 * (Pa + Pb);
				auto dP = Pn - P;

				P += omega * dP;

				if (ABS(1.0 - d0) <= tol AND ABS(1.0 - d1) <= tol)
				{
					cond = Standard_False;
					break;
				}
			} while (++Iter <= info.MaxNbIters());

			theP0 = std::move(P);
			return cond;
		}
	};

	

}

#endif // !_Aft_CorrOptNode_Iterative_Tools_Header

