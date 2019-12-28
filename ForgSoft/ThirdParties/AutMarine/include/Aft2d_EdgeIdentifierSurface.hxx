#pragma once
#ifndef _Aft2d_EdgeIdentifierSurface_Header
#define _Aft2d_EdgeIdentifierSurface_Header

#include <Aft_EntityIdentifier.hxx>
#include <Aft2d_NodeSurface.hxx>

namespace AutLib
{

	struct Aft2d_EdgeIdentifierSurface_Traits
	{

		typedef Pnt2d ptType;
	};

	template<>
	class Aft_EntityIdentifier<Aft2d_NodeSurface, true>
		: public Aft_EntityIdentifier<Aft2d_EdgeIdentifierSurface_Traits, true>
	{

		typedef Entity2d_Metric1 metric;

		/*Private Data*/

		metric theMetric_;

		Standard_Real theLength3d_;

	public:

		Aft_EntityIdentifier()
		{}

		const metric& EffectiveMetric() const
		{
			return theMetric_;
		}

		metric& EffectiveMetric()
		{
			return theMetric_;
		}

		Standard_Real Length3D() const
		{
			return theLength3d_;
		}

		Standard_Real& Length3D()
		{
			return theLength3d_;
		}

		void SetEffectiveMetric(const metric& theMetric)
		{
			theMetric_ = theMetric;
		}

		void SetLength3D(const Standard_Real theLength)
		{
			theLength3d_ = theLength;
		}

		virtual Standard_Boolean IsPoleSingular() const
		{
			return Standard_False;
		}

		virtual Standard_Boolean IsLineSingular() const
		{
			return Standard_False;
		}

		virtual Standard_Boolean IsSingular() const
		{
			return Standard_False;
		}
	};

	typedef Aft_EntityIdentifier<Aft2d_NodeSurface, true>
		Aft2d_EdgeIdentifierSurface;
}

#endif // !_Aft2d_EdgeIdentifierSurface_Header
