#pragma once
#ifndef _Geo_GraphEdgeAdaptor_Header
#define _Geo_GraphEdgeAdaptor_Header

namespace tnbLib
{

	template<class AdaptTraits>
	class Geo_GraphEdgeAdaptor
	{

		/*Private Data*/

	protected:

		Geo_GraphEdgeAdaptor()
		{}

	public:

	};


	template<>
	class Geo_GraphEdgeAdaptor<void> {};
}

#endif // !_Geo_GraphEdgeAdaptor_Header
