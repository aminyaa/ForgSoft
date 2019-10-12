#pragma once
#include <Numeric_Random.hxx>
#include <GeoProcessor.hxx>
#include <Geom_ItemSort.hxx>
namespace AutLib
{

	namespace GeoLib
	{

		struct Segment
		{
			Standard_Real theX0;
			Standard_Real theX1;

			Segment()
			{}

			Segment(const Standard_Real x0, const Standard_Real x1)
				: theX0(x0)
				, theX1(x1)
			{}

			Segment Left() const
			{
				return Segment(theX0, MEAN(theX0, theX1));
			}

			Segment Right() const
			{
				return Segment(MEAN(theX0, theX1), theX1);
			}

			Standard_Real Mean() const
			{
				return MEAN(theX0, theX1);
			}

			static Standard_Boolean IsLess(const Segment& theS1, const Segment& theS2)
			{
				return theS1.Mean() < theS2.Mean();
			}
		};

		typedef std::vector<Segment> segList;

		template<class CurveType, bool RandSamples = true>
		struct CalcApproximate
		{
			static Standard_Real _
			(
				const CurveType& theCurve,
				const Segment& theSeg,
				const Standard_Integer theNbSamples,
				Standard_Real& length
			)
			{
				std::vector<Standard_Real> params(theNbSamples);
				for (auto& x : params)
				{
					x = Random::Randreal(theSeg.theX0, theSeg.theX1);
				}

				const auto P0 = theCurve.Value(theSeg.theX0);
				const auto P1 = theCurve.Value(theSeg.theX1);

				length = P0.SquareDistance(P1);

				Standard_Real maxDis = 0;

				for (const auto x : params)
				{
					const auto Q = theCurve.Value(x);
					const auto dis = Processor::SquareDistance_cgal(Q, P0, P1);

					if (dis > maxDis)
						maxDis = dis;
				}
				return maxDis;
			}
		};

		template<class CurveType>
		struct CalcApproximate<CurveType, false>
		{
			static Standard_Real _
			(
				const CurveType& theCurve,
				const Segment& theSeg,
				const Standard_Integer theNbSamples,
				Standard_Real& length
			)
			{
				std::vector<Standard_Real> params(theNbSamples);
				auto dx = (Standard_Real)1.0 / (Standard_Real)(theNbSamples + 1);
				Standard_Integer K = 1;
				for (auto& x : params)
				{
					x = K * dx;
				}

				const auto P0 = theCurve.Value(theSeg.theX0);
				const auto P1 = theCurve.Value(theSeg.theX1);

				length = P0.SquareDistance(P1);

				Standard_Real maxDis = 0;

				for (const auto x : params)
				{
					const auto Q = theCurve.Value(x);
					const auto dis = Processor::SquareDistance_cgal(Q, P0, P1);

					if (dis > maxDis)
						maxDis = dis;
				}
				return maxDis;
			}
		};

		template<class CurveType>
		Standard_Real CalcAngle
		(
			const CurveType& theCurve,
			const Segment& theSeg
		)
		{
			typename CurveType::ptType pt0, pt1;
			typename CurveType::vtType vec0, vec1;

			theCurve.D1(theSeg.theX0, pt0, vec0);
			theCurve.D1(theSeg.theX1, pt1, vec1);

			typename CurveType::vtType vt(pt0, pt1);

			return MAX(vt.Angle(vec0), vt.Angle(vec1));
		}

		template<class CurveType, bool RandSamples>
		void Subdivide
		(
			const CurveType& theCurve,
			const Segment& theSeg,
			const Standard_Integer theNbSamples,
			const Standard_Real theApprox,
			const Standard_Real theAngle,
			const Standard_Integer theLevel,
			const Standard_Integer theInitlevel,
			const Standard_Integer theMaxlevel,
			segList& theSegments
		)
		{
			if (theLevel < theInitlevel)
			{
				Subdivide<CurveType, RandSamples>
					(
						theCurve, theSeg.Left(),
						theNbSamples,
						theApprox,
						theAngle,
						theLevel + 1, theInitlevel, theMaxlevel, theSegments);
				Subdivide<CurveType, RandSamples>
					(
						theCurve, theSeg.Right(),
						theNbSamples,
						theApprox,
						theAngle,
						theLevel + 1, theInitlevel, theMaxlevel, theSegments);
				return;
			}

			if (theLevel >= theMaxlevel)
			{
				theSegments.push_back(theSeg);
				return;
			}

			Standard_Real sqDis;
			auto approx =
				GeoLib::CalcApproximate<CurveType, RandSamples>::_(theCurve, theSeg, theNbSamples, sqDis);

			if (theApprox*sqDis < approx)
			{
				Subdivide<CurveType, RandSamples>
					(
						theCurve,
						theSeg.Left(),
						theNbSamples,
						theApprox,
						theAngle,
						theLevel + 1, theInitlevel, theMaxlevel, theSegments);
				Subdivide<CurveType, RandSamples>
					(
						theCurve,
						theSeg.Right(),
						theNbSamples,
						theApprox,
						theAngle,
						theLevel + 1, theInitlevel, theMaxlevel, theSegments);
				return;
			}

			auto angle = GeoLib::CalcAngle<CurveType>(theCurve, theSeg);
			if (theAngle < angle)
			{
				Subdivide<CurveType, RandSamples>
					(
						theCurve,
						theSeg.Left(),
						theNbSamples,
						theApprox,
						theAngle,
						theLevel + 1, theInitlevel, theMaxlevel, theSegments);
				Subdivide<CurveType, RandSamples>
					(
						theCurve,
						theSeg.Right(),
						theNbSamples,
						theApprox,
						theAngle,
						theLevel + 1, theInitlevel, theMaxlevel, theSegments);
				return;
			}

			theSegments.push_back(theSeg);
		}
	}

	template<class CurveType, bool RandSamples>
	void Geo_ApprxCurve<CurveType, RandSamples>::Perform(const info& theInfo)
	{
		if (NOT IsLoaded())
		{
			FatalErrorIn("void Perform()") << endl
				<< "the curve has not been loaded!" << endl
				<< abort(FatalError);
		}

		GeoLib::segList Segments;
		GeoLib::Subdivide<typename remove_pointer<CurveType>::type, RandSamples>
			(
				*Curve(),
				GeoLib::Segment(FirstParameter(), LastParameter()),
				theInfo.MaxNbSubdivision(),
				theInfo.Approx()*theInfo.Approx(),
				Processor::DegToRadian(theInfo.Angle()),
				0, theInfo.InitNbSubdivision(), theInfo.MaxNbSubdivision(), Segments
				);

		Geom_ItemSort<GeoLib::Segment> sorting(&GeoLib::Segment::IsLess);
		sorting.Perform(Segments);

		theChain_ = std::make_shared<chain>();
		auto& Pts = theChain_->Points();
		auto& Indices = theChain_->Connectivity();

		Pts.reserve(Segments.size() + 2);
		Indices.resize(Segments.size() + 1);

		const auto& curve = *Curve();
		Pts.push_back(curve.Value(FirstParameter()));

		for (const auto& seg : Segments)
		{
			const auto x = seg.Mean();
			Pts.push_back(curve.Value(x));
		}

		Pts.push_back(curve.Value(LastParameter()));

		Standard_Integer K = 1;
		for (auto& x : Indices)
		{
			x.Value(0) = K;
			x.Value(1) = K + 1;

			++K;
		}

		Change_IsDone() = Standard_True;
	}

	template<class CurveType, bool RandSamples>
	inline void Geo_ApprxCurve<CurveType, RandSamples>::Reset()
	{
		theCurve_ = 0;
		theChain_.reset();
	}
}