#pragma once
#include <Geo2d_SizeFunction_Surface.hxx>
#include <SingularZone_Pole_WholeSide.hxx>
#include <CadSingularity_Horizon.hxx>
#include <CadSingularity_Detection.hxx>
#include <CadRepair_DefectPatch_AR.hxx>
#include <CadRepair_DefectPatch_OrderWire.hxx>
#include <CadRepair_DefectPatch_OpenWire.hxx>
#include <CadRepair_DefectPatch_IntersectWire.hxx>
#include <CadRepair_DefectPatch_Metric.hxx>
#include <CadRepair_SingularPatch_Common.hxx>
#include <CadRepair_SingularPatch_Deep.hxx>
#include <CadRepair_RegularPatch.hxx>
#include <CadRepair_ApproxSurfMetric.hxx>
#include <CadRepair_ColoringSurfMetric.hxx>
#include <CadRepair_NormalizeMetric.hxx>
#include <CadAnalys_Model_Info.hxx>

namespace AutLib
{

	template<class SurfType, class SizeFun>
	template<class EntityType>
	Standard_Boolean CadAnalys_Model<SurfType, SizeFun>::CheckRegulars
	(
		const CadSingularity_Detection<EntityType>& detection
	)
	{
		if (NOT detection.NbZones())
		{
			FatalErrorIn(FunctionSIG) << endl
				<< "the singular surface has no singularity zone!" << endl
				<< abort(FatalError);
		}

		const auto& zones = detection.Zones();
		for (const auto& x : zones)
		{
			Debug_Null_Pointer(x);
			if (NOT std::dynamic_pointer_cast<SingularZone_Pole_WholeSide<SurfType>>(x))
			{
				return Standard_True;
			}
		}
		return Standard_False;
	}

	template<class SurfType, class SizeFun>
	void CadAnalys_Model<SurfType, SizeFun>::Perform()
	{
		if (NOT Surfaces().empty())
		{
			FatalErrorIn("void Perform()")
				<< "the model has not been loaded!" << endl
				<< abort(FatalError);
		}

		Debug_Null_Pointer(Info());

		const auto verbose = Info()->Verbose();

		const auto& surfaces = Surfaces();
		const auto& sizeMap = SizeFunction();

		if (verbose)
		{
			GET_MESSAGE << "  - Overriding ParaPlaneAR? " << (Info()->OverrideParaPlaneAR() ? "YES" : "NO");
			SEND_INFO;
		}

		
		for (const auto& x : surfaces)
		{
			Debug_Null_Pointer(x);

			if (verbose)
			{
				GET_MESSAGE << " checking surface nb. " << x->Index() << ";";
				SEND_INFO;

				GET_MESSAGE << " surface's name: " << x->Name() << ";";
				SEND_INFO;
			}
			
			if (verbose)
			{
				GET_MESSAGE << "  checking plane balancing...";
				SEND_INFO;
			}

			auto arInfo = Info()->GlobalParaPlaneAR();
			if (Info()->OverrideParaPlaneAR())
			{
				const auto& arMap = Info()->ParaPlaneAR();
				auto iter = arMap.find(x->Index());

				if (iter NOT_EQUAL arMap.end())
				{
					arInfo = iter->second;
				}
			}

			auto ar = CadRepair_DefectPatch_AR<SurfType>::CalcMaxAR(*x);
			if (ar.second > arInfo->AR())
			{
				base::ChangeDefects().insert
				(
					std::make_pair
					(
						x->Index(),
						std::make_shared
						<
						CadRepair_DefectPatch_AR<SurfType>>(x->Index(), x)));

				continue;
			}

			std::vector<std::shared_ptr<wireType>> wires;
			if (CadRepair_DefectPatch_OrderWire<SurfType>::Check(*x, wires))
			{

				if (verbose)
				{
					GET_MESSAGE << " defect wire has been detected: WIRE ORDER";
					SEND_WARNING;
				}

				base::ChangeDefects().insert
				(
					std::make_pair
					(
						x->Index(),
						std::make_shared
						<
						CadRepair_DefectPatch_OrderWire<SurfType>>(x->Index(), x, wires)));

				continue;
			}

			if (CadRepair_DefectPatch_OpenWire<SurfType>::Check(*x, wires, Info()->OpenWireTolerance()))
			{

				if (verbose)
				{
					GET_MESSAGE << " defect wire has been detected: OPENNED WIRE";
					SEND_WARNING;
				}

				base::ChangeDefects().insert
				(
					std::make_pair
					(
						x->Index(),
						std::make_shared
						<
						CadRepair_DefectPatch_OpenWire<SurfType>>(x->Index(), x, wires)));

				continue;
			}

			std::shared_ptr<wireType> outerWire;
			std::shared_ptr<wireType> innerWire;
			if (CadRepair_DefectPatch_IntersectWire<SurfType>::Check(*x, outerWire, innerWire, Info()->IntersectWireTolerance()))
			{

				if (verbose)
				{
					GET_MESSAGE << " defect wire has been detected: INTERSECTED WIRES";
					SEND_WARNING;
				}

				base::ChangeDefects().insert
				(
					std::make_pair
					(
						x->Index(),
						std::make_shared
						<
						CadRepair_DefectPatch_IntersectWire<SurfType>>(x->Index(), x, outerWire, innerWire)));

				continue;
			}

			auto approxInfo = Info()->GlobalMetricApproximation();
			Debug_Null_Pointer(approxInfo);

			if (Info()->OverrideMetricApproximation())
			{
				const auto& appMap = Info()->MetricApproximation();
				auto iter = appMap.find(x->Index());

				if (iter NOT_EQUAL appMap.end())
				{
					approxInfo = iter->second;
				}
			}

			if (verbose)
			{
				GET_MESSAGE << " - Overriding metric approximation settings? " << (Info()->OverrideMetricApproximation() ? "YES" : "NO");
				SEND_INFO;

				GET_MESSAGE << "  - Min Level: " << approxInfo->MinLevel();
				SEND_INFO;
				GET_MESSAGE << "  - Max Level: " << approxInfo->MaxLevel();
				SEND_INFO;
				GET_MESSAGE << "  - Tolerance: " << approxInfo->Tolerance();
				SEND_INFO;
				GET_MESSAGE << "  - Degeneracy: " << approxInfo->Degeneracy();
				SEND_INFO;
			}

			auto approx =
				std::make_shared<CadRepair_ApproxSurfMetric>
				(
					x->Geometry(),
					x->BoundingBox(), approxInfo);
			Debug_Null_Pointer(approx);

			approx->Perform();
			Debug_If_Condition_Message
			(
				NOT approx->IsDone(),
				"the Geo_ApprxSurfaceMetric has not been performed!");

			if (verbose)
			{
				GET_MESSAGE << "  making an approximation of the surface metric is done!";
				SEND_INFO;
				GET_MESSAGE << "  checking for normalizing the metric...";
				SEND_INFO;
			}

			auto normMetric = Info()->GlobalNormalizeMetric();
			Debug_Null_Pointer(normMetric);

			if (Info()->OverrideNormalizeMetric())
			{
				const auto& appMap = Info()->NormalizeMetric();
				auto iter = appMap.find(x->Index());

				if (iter NOT_EQUAL appMap.end())
				{
					normMetric = iter->second;
				}
			}

			if (approx->MaxDet() > normMetric->MaxDet())
			{

				base::ChangeDefects().insert
				(
					std::make_pair
					(
						x->Index(),
						std::make_shared
						<
						CadRepair_DefectPatch_Metric<SurfType>>(x->Index(), x, approx)));

				continue;
			}

			if (verbose)
			{
				GET_MESSAGE << "  Proceeding to detect the horizons of singularities...";
				SEND_INFO;
			}

			auto horizons =
				std::make_shared<CadSingularity_Horizon>(x->Index(), approx);

			horizons->Perform();
			Debug_If_Condition_Message
			(
				NOT horizons->IsDone(),
				"the Mesh_SingularHorizon has not been performed!");

			if (verbose)
			{
				GET_MESSAGE << "  detecting of horizons has been completed!";
				SEND_INFO;
				GET_MESSAGE << "  - Has been any horizons detected? " << (horizons->HasHorizon() ? "YES" : "NO");
				SEND_INFO;

				if (horizons->HasHorizon())
				{
					GET_MESSAGE << "  - Nb. of horizons: " << horizons->NbHorizons();
					SEND_INFO;
				}
			}

			if (NOT horizons->HasHorizon())
			{

				if (verbose)
				{
					GET_MESSAGE << "  ****registering the surface as a perfection one!****";
					SEND_INFO;

					GET_MESSAGE << "  continue...";
					SEND_INFO;
				}

				base::ChangeRegulars().insert
				(
					std::make_pair
					(
						x->Index(),
						std::make_shared
						<
						CadRepair_RegularPatch<SurfType>>(x->Index(), x)));

				continue;
			}
			else if (horizons->HasHorizon())
			{
				if (verbose)
				{
					GET_MESSAGE << "  Coloring algorithm has been called!";
					SEND_INFO;
				}

				auto colors =
					std::make_shared<CadRepair_ColoringSurfMetric>(approx);

				colors->Perform();
				Debug_If_Condition_Message(NOT colors->IsDone(), "the color algorithm has not been performed");

				if (verbose)
				{
					GET_MESSAGE << "  Coloring the regions has been finished";
					SEND_INFO;

					GET_MESSAGE << "  Proceeding to detect the type of singularities...";
					SEND_INFO;
				}

				auto typeDetecInfo = Info()->GlobalSingularityDetection();
				Debug_Null_Pointer(typeDetecInfo);

				if (Info()->OverrideSingularityDetection())
				{
					const auto& typeMap = Info()->SingularityDetection();
					auto iter = typeMap.find(x->Index());

					if (iter IS_EQUAL typeMap.end())
					{
						typeDetecInfo = iter->second;
					}
				}

				if (verbose)
				{
					GET_MESSAGE << "  - Overriding settings? " << (Info()->OverrideSingularityDetection() ? "YES" : "NO");
					SEND_INFO;

					GET_MESSAGE << "  - Nb. of iterations: " << typeDetecInfo->NbIters();
					SEND_INFO;

					GET_MESSAGE << "  - Omega: " << typeDetecInfo->Omega();
					SEND_INFO;
				}
				
				auto sizeMap2d = std::make_shared<Geo2d_SizeFunction_Surface>(x->Geometry(), sizeMap);

				auto detection = std::make_shared<CadSingularity_Detection<SurfType>>
					(
						horizons, colors,
						sizeMap2d, typeDetecInfo);

				detection->Perform();
				Debug_If_Condition_Message(NOT detection->IsDone(), "the type detection algorithm has not been performed");

				if (verbose)
				{
					GET_MESSAGE << "  type detection has been performed successfully! ";
					SEND_INFO;
				}

				if (CheckRegulars(*detection))
				{
					base::ChangeDeepSingulars().insert
					(
						std::make_pair
						(
							x->Index(),
							std::make_shared
							<
							CadRepair_SingularPatch_Deep<SurfType>>(x->Index(), x, detection)));

					continue;
				}
				else
				{
					base::ChangeCommonSingulars().insert
					(
						std::make_pair
						(
							x->Index(),
							std::make_shared
							<
							CadRepair_SingularPatch_Deep<SurfType>>(x->Index(), x, detection)));

					continue;
				}
			}
		}

		if (verbose)
		{
			GET_MESSAGE << " total nb. of surfaces = " << surfaces.size();
			SEND_INFO;

			GET_MESSAGE << "  - nb. of regular surfaces = " << base::NbRegulars();
			SEND_INFO;

			GET_MESSAGE << "  - nb. of singularities = " << base::NbDeepSingularities();
			SEND_INFO;

			GET_MESSAGE << "  - nb. of common singularities = " << base::NbCommonSingularities();
			SEND_INFO;

			GET_MESSAGE << "  - nb. of defect surfaces = " << base::NbDefects();
			SEND_INFO;
		}

		Change_IsDone() = Standard_True;
	}
}