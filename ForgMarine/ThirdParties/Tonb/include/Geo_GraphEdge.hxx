#pragma once
#ifndef _Geo_GraphEdge_Header
#define _Geo_GraphEdge_Header

#include <Global_Indexed.hxx>
#include <Global_AccessMethod.hxx>
#include <Geo_GraphEdgeAdaptor.hxx>

#include <memory>

namespace tnbLib
{

	template<class EdgeTraits>
	class Geo_GraphEdge
		: public Global_Indexed
		, public Geo_GraphEdgeAdaptor<typename EdgeTraits::edgeAdaptType>
	{

	public:

		typedef typename EdgeTraits::nodeType nodeType;
		typedef Geo_GraphEdgeAdaptor<typename EdgeTraits::edgeAdaptType> adaptor;

	private:

		/*Private Data*/

		std::shared_ptr<nodeType> theNode0_;
		std::shared_ptr<nodeType> theNode1_;

	public:

		Geo_GraphEdge(const Standard_Integer theIndex)
			: Global_Indexed(theIndex)
		{}

		Geo_GraphEdge
		(
			const Standard_Integer theIndex,
			const std::shared_ptr<nodeType>& theNode0,
			const std::shared_ptr<nodeType>& theNode1
		)
			: Global_Indexed(theIndex)
			, theNode0_(theNode0)
			, theNode1_(theNode1)
		{}

		static void deAttach(const std::shared_ptr<Geo_GraphEdge>& theEdge);

		//- Macros
		GLOBAL_ACCESS_SINGLE(std::shared_ptr<nodeType>, Node0)
			GLOBAL_ACCESS_SINGLE(std::shared_ptr<nodeType>, Node1)
	};
}

#include <Geo_GraphEdgeI.hxx>

#endif // !_Geo_GraphEdge_Header
