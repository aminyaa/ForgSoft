#pragma once
#ifndef _MetricMap2d_Surface_Header
#define _MetricMap2d_Surface_Header

#include <Mesh_MetricMap.hxx>
#include <Entity2d_Box.hxx>

#include <Standard_Handle.hxx>

class Geom_Surface;

namespace AutLib
{

	class MetricMap2d_Surface
		: public Mesh_MetricMap<Pnt2d>
	{

		/*Private Data*/

	protected:

		MetricMap2d_Surface()
		{}

		MetricMap2d_Surface
		(
			const Entity2d_Box& theBoundingBox
		)
			: Mesh_MetricMap<Pnt2d>(theBoundingBox)
		{}

	public:

		virtual Standard_Real MaxDim() const = 0;

		virtual const Handle(Geom_Surface)& Patch() const = 0;

		virtual void Reset() = 0;
	};
}

#endif // !_MetricMap2d_Surface_Header