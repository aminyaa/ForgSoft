#pragma once
#ifndef _Geo_Graph_Header
#define _Geo_Graph_Header

#include <Global_Macros.hxx>
#include <Global_Indexed.hxx>
#include <Global_Named.hxx>
#include <error.hxx>
#include <OSstream.hxx>

#include <map>
#include <memory>

namespace tnbLib
{

	template<class EdgeType>
	class Geo_Graph
		: public Global_Indexed
		, public Global_Named
	{

	public:

		typedef typename EdgeType::nodeType nodeType;
		typedef EdgeType edgeType;

	private:

		/*Private Data*/

		std::map
			<
			Standard_Integer, 
			std::shared_ptr<EdgeType>
			> theEdges_;
		 

	public:

		Geo_Graph()
		{}

		Geo_Graph
		(
			const Standard_Integer theIndex, 
			const word& theName
		)
			: Global_Indexed(theIndex)
			, Global_Named(theName)
		{}

		Standard_Integer NbEdges() const
		{
			return (Standard_Integer)theEdges_.size();
		}

		const std::map
			<
			Standard_Integer,
			std::shared_ptr<EdgeType>
			>& Edges() const
		{
			return theEdges_;
		}

		std::map
			<
			Standard_Integer,
			std::shared_ptr<EdgeType>
			>& Edges()
		{
			return theEdges_;
		}

		void Remove(const Standard_Integer theIndex)
		{
			auto iter = theEdges_.find(theIndex);
			if (iter IS_EQUAL theEdges_.end())
			{
				FatalErrorIn("void Remove(const Standard_Integer theIndex)")
					<< "the item is not in the tree: " << theIndex << endl
					<< abort(FatalError);
			}

			nodeType::deAttach(theIndex);

			theEdges_.erase(iter);
		}
	};
}

#endif // !_Geo_Graph_Header
