#pragma once
#ifndef _TModel_Surface_Header
#define _TModel_Surface_Header

#include <Entity2d_Box.hxx>
#include <Entity3d_Box.hxx>
#include <TModel_Entity.hxx>
#include <TModel_SurfaceGeometry.hxx>
#include <TModel_FaceOrientation.hxx>

#include <vector>
#include <memory>

namespace tnbLib
{

	// Forward Declarations
	class TModel_Wire;
	class TModel_Edge;
	class Entity2d_Metric1;

	class TModel_Surface
		: public TModel_Entity
		, public TModel_SurfaceGeometry
	{

		typedef std::shared_ptr<TModel_Wire> outer;
		typedef std::shared_ptr<std::vector<std::shared_ptr<TModel_Wire>>> inner;

		/*Private Data*/

		outer theOuter_;
		inner theInner_;

		Entity2d_Box theParaBoundingBox_;
		Entity3d_Box theBoundingBox_;

		TModel_FaceOrientation theOrientation_;


		//- Private functions and operators

		Entity2d_Box CalcParametricBoundingBox() const;

		Entity3d_Box CalcBoundingBox() const;


	public:

		TModel_Surface
		(
			const Handle(Geom_Surface)& theGeometry, 
			const outer& theOuter,
			const inner& theInner = nullptr
		);

		TModel_Surface
		(
			const Standard_Integer theIndex,
			const Handle(Geom_Surface)& theGeometry,
			const outer& theOuter,
			const inner& theInner = nullptr
		);

		TModel_Surface
		(
			const Standard_Integer theIndex,
			const word& theName,
			const Handle(Geom_Surface)& theGeometry,
			const outer& theOuter,
			const inner& theInner = nullptr
		);

		Standard_Integer NbHoles() const;

		Standard_Boolean HasHole() const;

		Standard_Boolean IsClamped() const;

		const auto& Outer() const
		{
			return theOuter_;
		}

		const auto& Inner() const
		{
			return theInner_;
		}

		const auto& BoundingBox() const
		{
			return theBoundingBox_;
		}

		const auto& ParaBoundingBox() const
		{
			return theParaBoundingBox_;
		}

		std::vector<std::shared_ptr<TModel_Edge>> 
			RetrieveEdges() const;

		Entity2d_Metric1 MetricAt
			(
				const Pnt2d& theCoord
			) const;

		Pnt3d Value
		(
			const Pnt2d& theCoord
		) const;

		//- static functions and operators

		static Standard_Boolean
			IsLess
			(
				const std::shared_ptr<TModel_Surface>& theS0,
				const std::shared_ptr<TModel_Surface>& theS1
			)
		{
			Debug_Null_Pointer(theS0);
			Debug_Null_Pointer(theS1);

			return theS0->Index() < theS1->Index();
		}
	};
}

#endif // !_TModel_Surface_Header
