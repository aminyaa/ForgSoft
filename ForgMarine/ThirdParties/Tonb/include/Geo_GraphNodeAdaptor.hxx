#pragma once
#ifndef _Geo_GraphNodeAdaptor_Header
#define _Geo_GraphNodeAdaptor_Header

namespace tnbLib
{

	template<class AdaptTraits>
	class Geo_GraphNodeAdaptor
	{

		/*Private Data*/

	protected:

		Geo_GraphNodeAdaptor()
		{}

	public:


	};

	template<>
	class Geo_GraphNodeAdaptor<void> {};
}

#endif // !_Geo_GraphNodeAdaptor_Header
