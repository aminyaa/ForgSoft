#pragma once
#ifndef _Geo2d_SizeFunction_Surface_Header
#define _Geo2d_SizeFunction_Surface_Header

#include <Entity2d_Box.hxx>
#include <Geo2d_SizeFunction.hxx>
#include <Geo3d_SizeFunction.hxx>

#include <Standard_Handle.hxx>

class Geom_Surface;

#include <memory>

namespace tnbLib
{

	class Geo2d_SizeFunction_Surface
		: public Geo2d_SizeFunction
	{

		/*Private Data*/

		Handle(Geom_Surface) theSurface_;

		std::shared_ptr<Geo3d_SizeFunction> theSize3d_;

	public:

		Geo2d_SizeFunction_Surface(const Entity2d_Box& theBox)
			: Geo2d_SizeFunction(theBox)
		{}

		Geo2d_SizeFunction_Surface
		(
			const Handle(Geom_Surface)& theSurface,
			const std::shared_ptr<Geo3d_SizeFunction>& theSize3d,
			const Entity2d_Box& theBox
		)
			: Geo2d_SizeFunction(theBox)
			, theSurface_(theSurface)
			, theSize3d_(theSize3d)
		{}

		const Handle(Geom_Surface)& Surface() const
		{
			return theSurface_;
		}

		const std::shared_ptr<Geo3d_SizeFunction>& Size3d() const
		{
			return theSize3d_;
		}

		Standard_Real Value(const Pnt2d& theCoord) const override;

		void LoadSurface(const Handle(Geom_Surface)& theSurface)
		{
			theSurface_ = theSurface;
		}

		void LoadSize3d(const std::shared_ptr<Geo3d_SizeFunction>& theSize3d)
		{
			theSize3d_ = theSize3d;
		}
	};
}

#endif // !_Geo2d_SizeFunction_Surface_Header