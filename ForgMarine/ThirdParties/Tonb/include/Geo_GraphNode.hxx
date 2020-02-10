#pragma once
#ifndef _Geo_GraphNode_Header
#define _Geo_GraphNode_Header

#include <Global_Macros.hxx>
#include <Global_Indexed.hxx>
#include <Global_AccessMethod.hxx>
#include <Geo_GraphNodeAdaptor.hxx>
#include <error.hxx>
#include <OSstream.hxx>

#include <memory>
#include <map>

namespace tnbLib
{

	template<class NodeTraits>
	class Geo_GraphNode
		: public Global_Indexed
		, public Geo_GraphNodeAdaptor<typename NodeTraits::nodeAdaptType>
	{

	public:

		typedef typename NodeTraits::edgeType edgeType;
		typedef Geo_GraphNodeAdaptor<typename NodeTraits::nodeAdaptType> adaptor;
		typedef typename NodeTraits::ptType Point;

	private:

		/*Private Data*/

		Point theCoord_;

		std::map
			<
			Standard_Integer,
			std::weak_ptr<edgeType>
			> theEdges_;

	public:

		Geo_GraphNode(const Standard_Integer theIndex)
			: Global_Indexed(theIndex)
		{}

		Standard_Integer NbEdges() const
		{
			return (Standard_Integer)theEdges_.size();
		}

		const std::map
			<
			Standard_Integer,
			std::weak_ptr<edgeType>
			>& Edges() const
		{
			return theEdges_;
		}

		std::map
			<
			Standard_Integer,
			std::weak_ptr<edgeType>
			>& Edges()
		{
			return theEdges_;
		}

		void RemoveFromEdges(const Standard_Integer theIndex)
		{
			auto iter = theEdges_.find(theIndex);
			if (iter IS_EQUAL theEdges_.end())
			{
				FatalErrorIn("void Remove(const Standard_Integer theIndex)")
					<< "the item is not in the tree: " << theIndex << endl
					<< abort(FatalError);
			}

			theEdges_.erase(iter);
		}

		//- Macros
		GLOBAL_ACCESS_SINGLE(Point, Coord)
	};
}

#endif // !_Geo_GraphNode_Header
