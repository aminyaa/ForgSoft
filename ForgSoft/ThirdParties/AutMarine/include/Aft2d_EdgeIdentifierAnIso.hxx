#pragma once
#ifndef _Aft2d_EdgeIdentifierAnIso_Header
#define _Aft2d_EdgeIdentifierAnIso_Header

#include <Aft_EntityIdentifier.hxx>
#include <Aft2d_NodeAnIso.hxx>

namespace AutLib
{

	struct Aft2d_EdgeIdentifierAnIsoNodeTraits
	{
		typedef Pnt2d ptType;
	};

	template<>
	class Aft_EntityIdentifier<Aft2d_NodeAnIso, true>
		: public Aft_EntityIdentifier<Aft2d_EdgeIdentifierAnIsoNodeTraits, true>
	{

		typedef Entity2d_Metric1 metric;

		/*Private Data*/

		metric theMetric_;

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

		void SetEffectiveMetric(const metric& theMetric)
		{
			theMetric_ = theMetric;
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

	typedef Aft_EntityIdentifier<Aft2d_NodeAnIso, true>
		Aft2d_EdgeIdentifierAnIso;
}

#endif // !_Aft2d_EdgeIdentifierAnIso_Header