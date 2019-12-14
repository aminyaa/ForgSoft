#pragma once
#include <Global_Macros.hxx>
#include <Global_Message.hxx>
#include <GeoMesh2d_Data.hxx>
#include <Geo_Tools.hxx>
#include <Cad_Tools.hxx>
#include <Pln_Curve.hxx>
#include <Cad2d_Plane_System.hxx>
#include <CadPlnModel_Curve.hxx>
#include <CadPlnModel_Segment.hxx>
#include <CadRepair_ApproxSurfMetric.hxx>
#include <CadRepair_ColoringSurfMetric.hxx>
#include <CadSingularity_Horizon.hxx>
#include <CadSingularity_PoleCurve.hxx>
#include <CadSingularity_LineCurve.hxx>
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
#include <Geom_Surface.hxx>

namespace AutLib
{

	namespace singularityTools
	{

		std::vector<std::shared_ptr<Pln_Curve>>
			RetrieveSides(const Entity2d_Box& theBox);

		Pnt2d FindParametricCoord
		(
			const Entity2d_Polygon& thePoly,
			const Geom_Surface& theSurface,
			const Standard_Real theLength
		);

		std::shared_ptr<Pln_Curve>
			GetPlnCurve(const Pnt2d& theP0, const Pnt2d& theP1);

		template<class CurveType>
		std::shared_ptr<CadSingularity_PoleCurve<CurveType>>
			ParametricCurve(const Entity2d_Polygon& thePoly)
		{
			if (thePoly.NbPoints() < 2)
			{
				FatalErrorIn("std::shared_ptr<CadSingularity_PoleCurve<CurveType>> ParametricCurve(const Entity2d_Polygon& thePoly)")
					<< "Invalid polygon" << endl
					<< abort(FatalError);
			}

			if (thePoly.NbPoints() == 2)
			{
				const auto& pts = thePoly.Points();
				auto pcurve = GetPlnCurve(pts[0], pts[1]);

				auto curve = std::make_shared<CadSingularity_PoleCurve<CurveType>>
					(
						Cad_Tools::ConvertToBSpline
						(
							pcurve->Curve()
						),
						pcurve->FirstParam(),
						pcurve->LastParam(),
						sysLib::gl_pln_curve_info
						);
				return std::move(curve);
			}

			auto pcurve = std::make_shared<Pln_Curve>(sysLib::gl_pln_curve_info);

			if (pcurve->Interpolation(thePoly.Points()))
			{
				FatalErrorIn("std::shared_ptr<CadSingularity_PoleCurve<CurveType>> ParametricCurve(const Entity2d_Polygon& thePoly)")
					<< "Failed to interpolate" << endl
					<< abort(FatalError);
			}

			auto curve = std::make_shared<CadSingularity_PoleCurve<CurveType>>
				(
					Cad_Tools::ConvertToBSpline
					(
						pcurve->Curve()
					),
					pcurve->FirstParam(),
					pcurve->LastParam(),
					sysLib::gl_pln_curve_info
					);
			return std::move(curve);
		}
	}
}

namespace AutLib
{

	template<class SurfPln>
	std::shared_ptr<typename CadSingularity_Detection<SurfPln>::singularZone>
		CadSingularity_Detection<SurfPln>::TypeDetection
		(
			const Entity2d_Polygon& thePolygon,
			const GeoMesh2d_Data& bMesh,
			const std::vector<std::shared_ptr<Pln_Curve>>& theSides,
			const Geom_Surface& theSurface,
			const sizeFun& theSize
		)
	{
		if (Info()->Verbose())
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

		if (Info()->Verbose())
		{
			GET_MESSAGE << "  - Is the polygon closed? " << (thePolygon.IsClosed() ? "YES" : "NO");
			SEND_INFO;
		}

		if (thePolygon.IsClosed())
		{
			const auto length =
				Geo_Tools::CalcPolyLengthOnSurface(thePolygon, theSurface);

			const auto elmSize = theSize.Value(P0);

			if (Info()->Verbose())
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

			auto curves = base::LineHorizonCurves_Loop(box);

			if (length < Weight() * elmSize)
			{

				if (Info()->Verbose())
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
				if (Info()->Verbose())
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

			if (Info()->Verbose())
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
					const auto curve = singularityTools::template ParametricCurve<plnCurve>(thePolygon);

					const auto Pm = singularityTools::FindParametricCoord(thePolygon, theSurface, 0.5 * length);
					curve->SetMid(Pm);

					if (Info()->Verbose())
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
					const auto curve = singularityTools::template ParametricCurve<plnCurve>(thePolygon);

					const auto Pm = singularityTools::FindParametricCoord(thePolygon, theSurface, 0.5 * length);
					curve->SetMid(Pm);

					if (Info()->Verbose())
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
					const auto pcurve = singularityTools::GetPlnCurve(P0, P1);
					auto curve = std::make_shared<CadSingularity_PoleCurve<plnCurve>>
						(
							Cad_Tools::ConvertToBSpline(pcurve->Curve()),
							pcurve->FirstParam(), pcurve->LastParam(),
							sysLib::gl_pln_curve_info
							);

					const auto Pm = MEAN(P0, P1);
					curve->SetMid(Pm);

					if (Info()->Verbose())
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
					auto curves = base::LineHorizonCurves_Dangle(box, s0);

					if (Info()->Verbose())
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
						base::LineHorizonCurves_Corner
						(
							box,
							s0, theSurface, Weight() * size);

					if (Info()->Verbose())
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
					auto curves = base::LineHorizonCurves_WholeSide(box, s0);

					if (Info()->Verbose())
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
	std::shared_ptr<typename CadSingularity_Detection<SurfPln>::singularZone>
		CadSingularity_Detection<SurfPln>::TypeDetection
		(
			const Entity2d_Polygon& thePolygon0,
			const Entity2d_Polygon& thePolygon1,
			const GeoMesh2d_Data& bMesh,
			const std::vector<std::shared_ptr<Pln_Curve>>& theSides,
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

		const auto curves = base::LineHorizonCurves_TwoSided(box, s00);

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
	const std::shared_ptr<typename CadSingularity_Detection<SurfPln>::singularZone>&
		CadSingularity_Detection<SurfPln>::Zone
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
	Standard_Boolean CadSingularity_Detection<SurfPln>::IsHorizonsLoaded() const
	{
		return (Standard_Boolean)theHorizons_;
	}

	template<class SurfPln>
	Standard_Boolean CadSingularity_Detection<SurfPln>::IsColorsLoaded() const
	{
		return (Standard_Boolean)theColors_;
	}

	template<class SurfPln>
	Standard_Boolean CadSingularity_Detection<SurfPln>::IsSizeFunLoaded() const
	{
		return (Standard_Boolean)theSizeFun_;
	}

	template<class SurfPln>
	Standard_Boolean CadSingularity_Detection<SurfPln>::IsInfoLoaded() const
	{
		return (Standard_Boolean)theInfo_;
	}

	template<class SurfPln>
	void CadSingularity_Detection<SurfPln>::Perform()
	{
		if (NOT Horizons())
		{
			FatalErrorIn("void CadSingularity_Detection<SurfPln>::Perform()")
				<< "Found no metric approximation" << endl
				<< abort(FatalError);
		}

		if (NOT Horizons()->Metric())
		{
			FatalErrorIn("void CadSingularity_Detection<SurfPln>::Perform()")
				<< "Found no metric approximation" << endl
				<< abort(FatalError);
		}

		if (NOT Colors())
		{
			FatalErrorIn("void CadSingularity_Detection<SurfPln>::Perform()")
				<< "No coloring has not been loaded!" << endl
				<< abort(FatalError);
		}

		if (NOT Horizons()->HasHorizon())
		{
			Change_IsDone() = Standard_True;
			return;
		}

		const auto& approx = *Horizons()->Metric();
		const auto& surface = *approx.Surface();
		const auto& box = approx.Domain();

		const auto& color = *Colors();

		std::map
			<
			Standard_Integer,
			std::shared_ptr<std::list<std::shared_ptr<Entity2d_Polygon>>>
			>
			IndexToHorizon;

		if (Info()->Verbose())
		{
			GET_MESSAGE << "  Nb. of Horizons: " << Horizons()->NbHorizons();
			SEND_INFO;
		}

		forThose
		(
			Index,
			0,
			Horizons()->NbHorizons() - 1
		)
		{
			if (Info()->Verbose())
			{
				GET_MESSAGE << " horizon no. " << Index + 1;
				SEND_INFO;
			}

			const auto& horizon = *Horizons()->Horizon(Index);

			const auto i = color.Value(horizon.GetPoint(horizon.NbPoints() / 2));

			if (Info()->Verbose())
			{
				GET_MESSAGE << "  color no. " << i;
				SEND_INFO;
			}

			auto iter = IndexToHorizon.find(i);

			if (iter IS_EQUAL IndexToHorizon.end())
			{
				IndexToHorizon.insert
				(
					std::make_pair
					(
						i,
						std::make_shared<std::list<std::shared_ptr<Entity2d_Polygon>>>()
					)
				);
			}

			IndexToHorizon[i]->push_back(Horizons()->Horizon(Index));
		}

		const auto triangulation = Geo_Tools::Triangulation(box);
		const auto sides = singularityTools::RetrieveSides(box);

		if (Info()->Verbose())
		{
			GET_MESSAGE << "  constructing topological background mesh... ";
			SEND_INFO;
		}

		GeoMesh2d_Data bmesh;
		bmesh.Construct(*triangulation);

		if (Info()->Verbose())
		{
			GET_MESSAGE << "  topological background mesh has been constructed! ";
			SEND_INFO;
		}

		auto& zones = ChangeZones();
		zones.reserve(IndexToHorizon.size());

		auto iter = IndexToHorizon.begin();
		while (iter NOT_EQUAL IndexToHorizon.end())
		{
			Debug_Null_Pointer(iter->second);
			const auto& l = *iter->second;

			if (l.empty())
			{
				FatalErrorIn("void AutLib::SingularityZone_TypeDetection::Perform()")
					<< "empty list" << endl
					<< abort(FatalError);
			}

			if (l.size() IS_EQUAL 1)
			{
				auto type =
					TypeDetection
					(
						*l.front(), bmesh, sides,
						surface, *theSizeFun_);
				type->SetIndex(iter->first);

				zones.push_back(type);
			}

			if (l.size() IS_EQUAL 2)
			{
				std::shared_ptr<Entity2d_Polygon> v[2];
				Standard_Integer K = 0;
				for (const auto& x : l)
				{
					v[K++] = x;
				}

				auto type =
					TypeDetection
					(
						*v[0], *v[1], bmesh,
						sides, surface, *theSizeFun_);
				type->SetIndex(iter->first);

				zones.push_back(type);
			}

			if (l.size() > 2)
			{
				FatalErrorIn("void AutLib::SingularityZone_TypeDetection::Perform()")
					<< "Invalid Data" << endl
					<< abort(FatalError);
			}
			iter++;
		}

		Change_IsDone() = Standard_True;
	}
}