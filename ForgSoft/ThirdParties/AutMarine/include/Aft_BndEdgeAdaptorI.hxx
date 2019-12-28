#pragma once
#include <error.hxx>
#include <OSstream.hxx>
namespace AutLib
{

	template<class CurveType, class MetricPrcsr>
	void Aft_BndEdgeAdaptor
		<
		CurveType, void,
		void, MetricPrcsr
		>::SingularityContraction
	(
		const MetricPrcsr & /*thePrcsr*/
	)
	{
		FatalErrorIn("void SingularityContraction(const MetricPrcsr &)")
			<< "not supposed to be called!" << endl
			<< abort(FatalError);
	}
}