#pragma once
#include <Global_Macros.hxx>
#include <Global_Message.hxx>
#include <Geo_Tools.hxx>
#include <Cad2d_Plane_System.hxx>
#include <CadPlnModel_Curve.hxx>
#include <CadPlnModel_Segment.hxx>
#include <SingularCurve_Pole.hxx>
#include <SingularCurve_Line.hxx>
#include <SingularZone_Pole_Loop.hxx>
#include <SingularZone_Pole_Corner.hxx>
#include <SingularZone_Pole_PartialSide.hxx>
#include <SingularZone_Pole_WholeSide.hxx>
#include <SingularZone_Line_Corner.hxx>
#include <SingularZone_Line_Dangle.hxx>
#include <SingularZone_Line_Loop.hxx>
#include <SingularZone_Line_TwoSide.hxx>
#include <SingularZone_Line_WholeSide.hxx>
#include <error.hxx>
#include <OSstream.hxx>

#include <Geom2dAPI_ProjectPointOnCurve.hxx>

namespace AutLib
{

	namespace SingularityTools
	{
		Pnt2d FindParametricCoord
		(
			const Entity2d_Polygon& thePoly,
			const Geom_Surface& theSurface, 
			const Standard_Real theLength
		);
	}

	template<class CurveType>
	std::vector<std::shared_ptr<CurveType>> 
		Mesh_SingularDetection_Base<CurveType>::LineHorizonCurves_Dangle
		(
			const Entity2d_Box& theBox,
			const Standard_Integer s0
		)
	{
		const auto& p0 = theBox.P0();
		const auto p1 = theBox.Corner(Box2d_PickAlgorithm_SE);
		const auto& p2 = theBox.P1();
		const auto p3 = theBox.Corner(Box2d_PickAlgorithm_NW);

		std::vector<std::shared_ptr<CurveType>> curves;
		curves.reserve(3);

		if (s0 IS_EQUAL 1)
		{
			curves.push_back(ParametricCurve_Line<CurveType>(p0, p3));
			curves.push_back(ParametricCurve_Pole<CurveType>(p3, p2));
			curves.push_back(ParametricCurve_Line<CurveType>(p2, p1));

			return std::move(curves);
		}
		else if (s0 IS_EQUAL 2)
		{
			curves.push_back(ParametricCurve_Line<CurveType>(p1, p0));
			curves.push_back(ParametricCurve_Pole<CurveType>(p0, p3));
			curves.push_back(ParametricCurve_Line<CurveType>(p3, p2));

			return std::move(curves);
		}
		else if (s0 IS_EQUAL 3)
		{
			curves.push_back(ParametricCurve_Line<CurveType>(p2, p1));
			curves.push_back(ParametricCurve_Pole<CurveType>(p1, p0));
			curves.push_back(ParametricCurve_Line<CurveType>(p0, p3));

			return std::move(curves);
		}
		else if (s0 IS_EQUAL 4)
		{
			curves.push_back(ParametricCurve_Line<CurveType>(p3, p2));
			curves.push_back(ParametricCurve_Pole<CurveType>(p2, p1));
			curves.push_back(ParametricCurve_Line<CurveType>(p1, p0));

			return std::move(curves);
		}

		FatalErrorIn("std::vector<std::shared_ptr<CurveType>> LineHorizonCurves_Dangle(const Entity2d_Box& theBox, const Standard_Integer s0)")
			<< abort(FatalError);
		return std::move(curves);
	}

	template<class CurveType>
	std::vector<std::shared_ptr<CurveType>> 
		Mesh_SingularDetection_Base<CurveType>::LineHorizonCurves_Corner
		(
			const Entity2d_Box& theBox,
			const Standard_Integer s0,
			const Geom_Surface& theSurface,
			const Standard_Real tol
		)
	{
		const auto& p0 = theBox.P0();
		const auto p1 = theBox.Corner(Box2d_PickAlgorithm_SE);
		const auto& p2 = theBox.P1();
		const auto p3 = theBox.Corner(Box2d_PickAlgorithm_NW);

		std::vector<std::shared_ptr<CurveType>> curves;
		curves.reserve(2);

		if (s0 IS_EQUAL 1)
		{
			const auto d0 = Geo_Tools::CalcSegmentLengthOnSurface(p3, p2, theSurface);
			const auto d1 = Geo_Tools::CalcSegmentLengthOnSurface(p0, p3, theSurface);

			if (d0 <= tol AND d1 <= tol)
			{
				FatalErrorIn(FunctionSIG)
					<< abort(FatalError);
			}

			if (d0 <= tol)
			{
				curves.push_back(ParametricCurve_Pole<CurveType>(p3, p2));
				curves.push_back(ParametricCurve_Line<CurveType>(p0, p3));
			}
			else
			{
				curves.push_back(ParametricCurve_Line<CurveType>(p3, p2));
				curves.push_back(ParametricCurve_Pole<CurveType>(p0, p3));
			}

			return std::move(curves);
		}
		else if (s0 IS_EQUAL 2)
		{
			const auto d0 = Geo_Tools::CalcSegmentLengthOnSurface(p1, p0, theSurface);
			const auto d1 = Geo_Tools::CalcSegmentLengthOnSurface(p0, p3, theSurface);

			if (d0 <= tol AND d1 <= tol)
			{
				FatalErrorIn(FunctionSIG)
					<< abort(FatalError);
			}

			if (d0 <= tol)
			{
				curves.push_back(ParametricCurve_Pole<CurveType>(p1, p0));
				curves.push_back(ParametricCurve_Line<CurveType>(p0, p3));
			}
			else
			{
				curves.push_back(ParametricCurve_Line<CurveType>(p1, p0));
				curves.push_back(ParametricCurve_Pole<CurveType>(p0, p3));
			}

			return std::move(curves);
		}
		else if (s0 IS_EQUAL 3)
		{
			const auto d0 = Geo_Tools::CalcSegmentLengthOnSurface(p2, p1, theSurface);
			const auto d1 = Geo_Tools::CalcSegmentLengthOnSurface(p1, p0, theSurface);

			if (d0 <= tol AND d1 <= tol)
			{
				FatalErrorIn(FunctionSIG)
					<< abort(FatalError);
			}

			if (d0 <= tol)
			{
				curves.push_back(ParametricCurve_Pole<CurveType>(p2, p1));
				curves.push_back(ParametricCurve_Line<CurveType>(p1, p0));
			}
			else
			{
				curves.push_back(ParametricCurve_Line<CurveType>(p2, p1));
				curves.push_back(ParametricCurve_Pole<CurveType>(p1, p0));
			}

			return std::move(curves);
		}
		else if (s0 IS_EQUAL 4)
		{
			const auto d0 = Geo_Tools::CalcSegmentLengthOnSurface(p3, p2, theSurface);
			const auto d1 = Geo_Tools::CalcSegmentLengthOnSurface(p2, p1, theSurface);

			if (d0 <= tol AND d1 <= tol)
			{
				FatalErrorIn(FunctionSIG)
					<< abort(FatalError);
			}

			if (d0 <= tol)
			{
				curves.push_back(ParametricCurve_Pole<CurveType>(p3, p2));
				curves.push_back(ParametricCurve_Line<CurveType>(p2, p1));
			}
			else
			{
				curves.push_back(ParametricCurve_Line<CurveType>(p3, p2));
				curves.push_back(ParametricCurve_Pole<CurveType>(p2, p1));
			}

			return std::move(curves);
		}

		FatalErrorIn(FunctionSIG)
			<< abort(FatalError);
		return std::move(curves);
	}

	template<class CurveType>
	std::vector<std::shared_ptr<CurveType>> 
		Mesh_SingularDetection_Base<CurveType>::LineHorizonCurves_WholeSide
		(
			const Entity2d_Box& theBox, 
			const Standard_Integer s0
		)
	{
		const auto& p0 = theBox.P0();
		const auto p1 = theBox.Corner(Box2d_PickAlgorithm_SE);
		const auto& p2 = theBox.P1();
		const auto p3 = theBox.Corner(Box2d_PickAlgorithm_NW);

		std::vector<std::shared_ptr<CurveType>> curves;
		curves.reserve(1);

		if (s0 IS_EQUAL 1)
		{
			curves.push_back(ParametricCurve_Line<CurveType>(p0, p3));

			return std::move(curves);
		}
		else if (s0 IS_EQUAL 2)
		{
			curves.push_back(ParametricCurve_Line<CurveType>(p1, p0));

			return std::move(curves);
		}
		else if (s0 IS_EQUAL 3)
		{
			curves.push_back(ParametricCurve_Line<CurveType>(p2, p1));

			return std::move(curves);
		}
		else if (s0 IS_EQUAL 4)
		{
			curves.push_back(ParametricCurve_Line<CurveType>(p3, p2));

			return std::move(curves);
		}

		FatalErrorIn(FunctionSIG)
			<< abort(FatalError);
		return std::move(curves);
	}

	template<class CurveType>
	std::vector<std::shared_ptr<CurveType>> 
		Mesh_SingularDetection_Base<CurveType>::LineHorizonCurves_Loop
		(
			const Entity2d_Box& theBox
		)
	{
		const auto& p0 = theBox.P0();
		const auto p1 = theBox.Corner(Box2d_PickAlgorithm_SE);
		const auto& p2 = theBox.P1();
		const auto p3 = theBox.Corner(Box2d_PickAlgorithm_NW);

		std::vector<std::shared_ptr<CurveType>> curves;
		curves.reserve(4);

		curves.push_back(ParametricCurve_Line<CurveType>(p0, p3));
		curves.push_back(ParametricCurve_Line<CurveType>(p3, p2));
		curves.push_back(ParametricCurve_Line<CurveType>(p2, p1));
		curves.push_back(ParametricCurve_Line<CurveType>(p1, p0));

		return std::move(curves);
	}

	template<class CurveType>
	std::vector<std::shared_ptr<CurveType>> 
		Mesh_SingularDetection_Base<CurveType>::LineHorizonCurves_TwoSided
		(
			const Entity2d_Box& theBox,
			const Standard_Integer s0
		)
	{
		const auto& p0 = theBox.P0();
		const auto p1 = theBox.Corner(Box2d_PickAlgorithm_SE);
		const auto& p2 = theBox.P1();
		const auto p3 = theBox.Corner(Box2d_PickAlgorithm_NW);

		std::vector<std::shared_ptr<CurveType>> curves;
		curves.reserve(2);

		if (s0 IS_EQUAL 1 OR s0 IS_EQUAL 3)
		{
			curves.push_back(ParametricCurve_Line<CurveType>(p0, p3));
			curves.push_back(ParametricCurve_Line<CurveType>(p2, p1));

			return std::move(curves);
		}
		else if (s0 IS_EQUAL 2 OR s0 IS_EQUAL 4)
		{
			curves.push_back(ParametricCurve_Line<CurveType>(p3, p2));
			curves.push_back(ParametricCurve_Line<CurveType>(p1, p0));

			return std::move(curves);
		}

		FatalErrorIn(FunctionSIG)
			<< abort(FatalError);
		return std::move(curves);
	}

	template<class SurfPln>
	std::shared_ptr<typename Mesh_SingularDetection<SurfPln>::singularZone> 
		Mesh_SingularDetection<SurfPln>::TypeDetection
		(
			const Entity2d_Polygon& thePolygon,
			const GeoMesh2d_Data& bMesh, 
			const std::vector<std::shared_ptr<plnCurve>>& theSides, 
			const Geom_Surface& theSurface,
			const sizeFun& theSize
		)
	{
		if (Verbose())
		{
			GET_MESSAGE << " @ singularity type detection: ";
			SEND_INFO;
		}

		const auto& pts = thePolygon.Points();
		if (pts.size() < 2)
		{
			GET_MESSAGE << "  Invalid polygon: must be at least two points in the polygon";
			SEND_ERROR;

			FatalErrorIn("std::shared_ptr<SurfMetric_SingularityHorizon> TypeDetection()")
				<< "Invalid polygon: must be at least two points in the polygon" << endl
				<< abort(FatalError);
		}

		const auto& P0 = pts[0];
		const auto& P1 = pts[pts.size() - 1];

		if (Verbose())
		{
			GET_MESSAGE << "  - Is the polygon closed? " << (thePolygon.IsClosed() ? "YES" : "NO");
			SEND_INFO;
		}

		if (thePolygon.IsClosed())
		{
			const auto length = 
				Geo_Tools::CalcPolyLengthOnSurface(thePolygon, theSurface);

			const auto elmSize = theSize->Value(P0);

			if (Verbose())
			{
				GET_MESSAGE << "  - Length of the polygon: " << length;
				SEND_INFO;

				GET_MESSAGE << "  - Element size = " << elmSize;
				SEND_INFO;

				GET_MESSAGE << "  if the criterion is met then a singularity must be a pole loop ";
				SEND_INFO;
				GET_MESSAGE << "  otherwise the singularity is a line loop";
				SEND_INFO;
			}

			const auto box = Entity2d_Box::BoundingBoxOf(pts);

			auto curves = base::template LineHorizonCurves_Loop<plnCurve>(box);

			if (length < Weight() * elmSize)
			{

				if (Verbose())
				{
					GET_MESSAGE << "  - Creating a POLE LOOP singularity...";
					SEND_INFO;
				}

				auto singularity =
					std::make_shared<SingularZone_Pole_Loop<SurfPln>>
					(
						++theCount_,
						curves[0],
						curves[1], curves[2], curves[3]
						);
				return std::move(singularity);
			}
			else
			{
				if (Verbose())
				{
					GET_MESSAGE << "  - Creating a LINE LOOP singularity..." << length;
					SEND_INFO;
				}

				auto singularity =
					std::make_shared<SingularZone_Line_Loop<SurfPln>>
					(
						++theCount_,
						curves[0],
						curves[1],
						curves[2],
						curves[3]
						);

				return std::move(singularity);
			}
		}
		else
		{
			const auto& e0 = bMesh.TriangleLocation(bMesh.FirstElement(), P0);
			const auto& e1 = bMesh.TriangleLocation(bMesh.FirstElement(), P1);

			const auto s0 = e0->Index();
			const auto s1 = e1->Index();

			const auto& c0 = *theSides[Index_Of(s0)];
			const auto& c1 = *theSides[Index_Of(s1)];

			Geom2dAPI_ProjectPointOnCurve Projector;
			Projector.Init(P0, c0.Curve(), c0.FirstParam(), c0.LastParam());
			const auto d0 = Projector.LowerDistance();

			Projector.Init(P1, c1.Curve(), c1.FirstParam(), c1.LastParam());
			const auto d1 = Projector.LowerDistance();

			if (d0 > EPS6)
			{
				FatalErrorIn("std::shared_ptr<SurfMetric_SingularityHorizon> TypeDetection()")
					<< "Invalid Data" << endl
					<< abort(FatalError);
			}

			if (d1 > EPS6)
			{
				FatalErrorIn("std::shared_ptr<SurfMetric_SingularityHorizon> TypeDetection()")
					<< "Invalid Data" << endl
					<< abort(FatalError);
			}

			const auto size0 = theSize.Value(P0);
			const auto size1 = theSize.Value(P1);
			const auto size = MEAN(size0, size1);

			const auto length = 
				Geo_Tools::CalcPolyLengthOnSurface(thePolygon, theSurface);

			if (Verbose())
			{
				GET_MESSAGE << "  - Length of the polygon: " << length;
				SEND_INFO;
				GET_MESSAGE << "  - Length < weight*Element Size? " << ((length < 1.25 * size) ? "YES" : "NO");
				SEND_INFO;
				GET_MESSAGE << "     Element Size = " << size;
				SEND_INFO;
				GET_MESSAGE << "     if the criterion is met then a singularity must be a POLE type";
				SEND_INFO;
				GET_MESSAGE << "     otherwise the singularity is a LINE type";
				SEND_INFO;
			}

			if (length < Weight() * size)
			{
				if (s0 IS_EQUAL s1)
				{
					const auto curve = base::template ParametricCurve<plnCurve>(thePolygon);

					const auto Pm = SingularityTools::FindParametricCoord(thePolygon, theSurface, 0.5 * length);
					curve->SetMid(Pm);

					if (Verbose())
					{
						GET_MESSAGE << "  - Creating a PARTIALSIDE POLE singularity...";
						SEND_INFO;
					}

					auto singularity = std::make_shared<SingularZone_Pole_PartialSide<SurfPln>>(++theCount_, curve);
					singularity->SetPole(Pm);

					return std::move(singularity);
				}
				else if (ABS(s0 - s1) IS_EQUAL 1)
				{
					const auto curve = base::template ParametricCurve<plnCurve>(thePolygon);

					const auto Pm = SingularityTools::FindParametricCoord(thePolygon, theSurface, 0.5 * length);
					curve->SetMid(Pm);

					if (Verbose())
					{
						GET_MESSAGE << "  - Creating a CORNER POLE singularity...";
						SEND_INFO;
					}

					auto singularity = std::make_shared<SingularZone_Pole_Corner<SurfPln>>(++theCount_, curve);
					singularity->SetPole(Pm);

					return std::move(singularity);
				}
				else if (ABS(s0 - s1) IS_EQUAL 2)
				{
					CadPlnModel_Segment LinSegMaker;
					const auto pcurve = LinSegMaker(P0, P1);
					auto curve = std::make_shared<SingularCurve_Pole<plnCurve, sizeFun, metricFun>>
						(
							Cad_Tools::ConvertToBSpline(pcurve->Curve(), pcurve->FirstParam(), pcurve->LastParam()),
							pcurve->FirstParam(), pcurve->LastParam(),
							sysLib::gl_pln_curve_info
							);

					const auto Pm = MEAN(P0, P1);
					curve->SetMid(Pm);

					if (Verbose())
					{
						GET_MESSAGE << "  - Creating a WHOLESIDE POLE singularity...";
						SEND_INFO;
					}

					auto singularity = std::make_shared<SingularZone_Pole_WholeSide<SurfPln>>(++theCount_, curve);
					singularity->SetPole(Pm);

					return std::move(singularity);
				}
				else
				{
					FatalErrorIn("std::shared_ptr<SurfMetric_SingularityHorizon> TypeDetection()")
						<< "Invalid data!" << endl
						<< abort(FatalError);
				}
			}
			else
			{
				const auto box = Entity2d_Box::BoundingBoxOf(pts);

				if (s0 IS_EQUAL s1)
				{
					auto curves = base::template LineHorizonCurves_Dangle<plnCurve>(box, s0);

					if (Verbose())
					{
						GET_MESSAGE << "  - Creating a DANGLE LINE singularity...";
						SEND_INFO;
					}

					auto singularity =
						std::make_shared<SingularZone_Line_Dangle<SurfPln>>
						(
							++theCount_,
							curves[0],
							curves[1], curves[2]);

					return std::move(singularity);
				}
				else if (ABS(s0 - s1) IS_EQUAL 1)
				{
					auto curves =
						base::template LineHorizonCurves_Corner<plnCurve>
						(
							box,
							s0, theSurface, Weight() * size);

					if (Verbose())
					{
						GET_MESSAGE << "  - Creating a CORNER LINE singularity...";
						SEND_INFO;
					}

					auto singularity =
						std::make_shared<SingularZone_Line_Corner<SurfPln>>(++theCount_, curves[0], curves[1]);

					return std::move(singularity);
				}
				else if (ABS(s0 - s1) IS_EQUAL 2)
				{
					auto curves = base::template LineHorizonCurves_WholeSide<plnCurve>(box, s0);

					if (Verbose())
					{
						GET_MESSAGE << "  - Creating a WHOLESIDE LINE singularity...";
					}

					auto singularity =
						std::make_shared<SingularZone_Line_WholeSide<SurfPln>>(++theCount_, curves[0]);

					return std::move(singularity);
				}

				FatalErrorIn("std::shared_ptr<SurfMetric_SingularityHorizon> TypeDetection()")
					<< "Invalid data!" << endl
					<< abort(FatalError);
			}
		}

		FatalErrorIn("std::shared_ptr<SurfMetric_SingularityHorizon> TypeDetection()")
			<< "Invalid data!" << endl
			<< abort(FatalError);

		return nullptr;
	}

	template<class SurfPln>
	std::shared_ptr<typename Mesh_SingularDetection<SurfPln>::singularZone> 
		Mesh_SingularDetection<SurfPln>::TypeDetection
		(
			const Entity2d_Polygon& thePolygon0,
			const Entity2d_Polygon& thePolygon1,
			const GeoMesh2d_Data& bMesh,
			const std::vector<std::shared_ptr<plnCurve>>& theSides,
			const Geom_Surface& theSurface,
			const sizeFun& theSize
		)
	{
		const auto& pts0 = thePolygon0.Points();
		const auto& pts1 = thePolygon1.Points();

		if (pts0.size() < 2)
		{
			FatalErrorIn("std::shared_ptr<SurfMetric_SingularityHorizon> TypeDetection()")
				<< "Invalid polygon: must be at least two points in the polygon" << endl
				<< abort(FatalError);
		}

		if (pts1.size() < 2)
		{
			FatalErrorIn("std::shared_ptr<SurfMetric_SingularityHorizon> TypeDetection()")
				<< "Invalid polygon: must be at least two points in the polygon" << endl
				<< abort(FatalError);
		}

		const auto& P00 = pts0[0];
		const auto& P01 = pts0[pts0.size() - 1];

		const auto& P10 = pts1[0];
		const auto& P11 = pts1[pts1.size() - 1];

		const auto& e00 = bMesh.TriangleLocation(bMesh.FirstElement(), P00);
		const auto& e01 = bMesh.TriangleLocation(bMesh.FirstElement(), P01);

		const auto s00 = e00->Index();
		const auto s01 = e01->Index();

		const auto& c00 = *theSides[Index_Of(s00)];
		const auto& c01 = *theSides[Index_Of(s01)];

		Geom2dAPI_ProjectPointOnCurve Projector;

		Projector.Init(P00, c00.Curve(), c00.FirstParam(), c00.LastParam());
		const auto d00 = Projector.LowerDistance();

		Projector.Init(P01, c01.Curve(), c01.FirstParam(), c01.LastParam());
		const auto d01 = Projector.LowerDistance();

		if (d00 > EPS12)
		{
			FatalErrorIn("std::shared_ptr<SurfMetric_SingularityHorizon> TypeDetection()")
				<< "Invalid Data" << endl
				<< abort(FatalError);
		}

		if (d01 > EPS12)
		{
			FatalErrorIn("std::shared_ptr<SurfMetric_SingularityHorizon> TypeDetection()")
				<< "Invalid Data" << endl
				<< abort(FatalError);
		}

		const auto& e10 = bMesh.TriangleLocation(bMesh.FirstElement(), P10);
		const auto& e11 = bMesh.TriangleLocation(bMesh.FirstElement(), P11);

		const auto s10 = e10->Index();
		const auto s11 = e11->Index();

		const auto& c10 = *theSides[Index_Of(s10)];
		const auto& c11 = *theSides[Index_Of(s11)];

		Projector.Init(P10, c10.Curve(), c10.FirstParam(), c10.LastParam());
		const auto d10 = Projector.LowerDistance();

		Projector.Init(P11, c11.Curve(), c11.FirstParam(), c11.LastParam());
		const auto d11 = Projector.LowerDistance();

		if (d10 > EPS12)
		{
			FatalErrorIn("std::shared_ptr<SurfMetric_SingularityHorizon> TypeDetection()")
				<< "Invalid Data" << endl
				<< abort(FatalError);
		}

		if (d11 > EPS12)
		{
			FatalErrorIn("std::shared_ptr<SurfMetric_SingularityHorizon> TypeDetection()")
				<< "Invalid Data" << endl
				<< abort(FatalError);
		}

		const auto size00 = theSize.Value(P00);
		const auto size01 = theSize.Value(P01);
		const auto size0 = MEAN(size00, size01);

		const auto size10 = theSize.Value(P10);
		const auto size11 = theSize.Value(P11);
		const auto size1 = MEAN(size10, size11);

		const auto box0 = Entity2d_Box::BoundingBoxOf(pts0);
		const auto box1 = Entity2d_Box::BoundingBoxOf(pts1);

		const auto box = Entity2d_Box::Union(box0, box1);

		const auto curves = base::template LineHorizonCurves_TwoSided<plnCurve>(box, s00);

		auto singularity =
			std::make_shared<SingularZone_Line_TwoSide<SurfPln>>
			(
				++theCount_,
				curves[0],
				curves[1]
				);

		return std::move(singularity);
	}

	template<class SurfPln>
	const std::shared_ptr<typename Mesh_SingularDetection<SurfPln>::singularZone>& 
		Mesh_SingularDetection<SurfPln>::Zone
		(
			const Standard_Integer theIndex
		) const
	{
		if (NOT INSIDE(theIndex, 0, NbZones() - 1))
		{
			FatalErrorIn("const std::shared_ptr<singularZone>& Zone(const Standard_Integer theIndex) const")
				<< "Invalid index: " << endl
				<< " - index: " << theIndex << endl
				<< " - nb. of zones: " << NbZones() << endl
				<< abort(FatalError);
		}
		return theZones_[theIndex];
	}

	template<class SurfPln>
	Standard_Boolean Mesh_SingularDetection<SurfPln>::IsHorizonsLoaded() const
	{
		return (Standard_Boolean)theHorizons_;
	}

	template<class SurfPln>
	Standard_Boolean Mesh_SingularDetection<SurfPln>::IsColorsLoaded() const
	{
		return (Standard_Boolean)theColors_;
	}

	template<class SurfPln>
	Standard_Boolean Mesh_SingularDetection<SurfPln>::IsSizeFunLoaded() const
	{
		return (Standard_Boolean)theSizeFun_;
	}

	template<class SurfPln>
	Standard_Boolean Mesh_SingularDetection<SurfPln>::IsInfoLoaded() const
	{
		return (Standard_Boolean)theInfo_;
	}

	template<class SurfPln>
	void Mesh_SingularDetection<SurfPln>::Perform()
	{

	}
}