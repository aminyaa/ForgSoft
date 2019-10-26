#pragma once
#include <error.hxx>
#include <OSstream.hxx>
#include <gp.hxx>
#include <Global_Message.hxx>
namespace AutLib
{

	template<class AftMetricPrcsr>
	void Mesh_OptNode_IterativeCorrector<AftMetricPrcsr>::Perform()
	{
		base::ChangeCoord() = base::P0();

		Debug_Null_Pointer(MetricMap());
		const auto& map = *MetricMap();

		Debug_Null_Pointer(Info());
		const auto& info = *Info();

		const auto omega = info.UnderRelaxation();
		const auto tol = info.Tolerance();

		const auto& edge = base::Front();

		Debug_Null_Pointer(edge.Node0());
		Debug_Null_Pointer(edge.Node1());
		const auto& v0 = edge.Node0()->Coord();
		const auto& v1 = edge.Node1()->Coord();

		auto P = base::P0();

		Standard_Integer Iter = 0;
		do
		{
			auto d0 = map.CalcUnitDistance(v0, P);
			auto d1 = map.CalcUnitDistance(v1, P);

			Debug_If_Condition(d0 <= gp::Resolution());
			Debug_If_Condition(d1 <= gp::Resolution());

			auto Pa = v0 + (P - v0) / d0;
			auto Pb = v1 + (P - v1) / d1;

			auto Pn = 0.5*(Pa + Pb);
			auto dP = Pn - P;

			P += omega * dP;

			if (ABS(1.0 - d0) <= tol AND ABS(1.0 - d1) <= tol)
			{
				base::Change_IsConverged() = Standard_True;
				break;
			}
		} while (++Iter <= info.MaxNbIters());

		if (NOT base::IsConverged() AND NOT info.IgnoreNonConvergency())
		{
			FatalErrorIn("void Perform()")
				<< "failed to calculate optimized node" << endl
				<< abort(FatalError);
		}

		if (info.Verbose() AND NOT base::IsConverged())
		{
			GET_MESSAGE << " failed to calculate optimized node" << endl;
			SEND_WARNING;
		}

		base::ChangeCoord() = std::move(P);
		base::Change_IsDone() = Standard_True;
	}
}