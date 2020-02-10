#pragma once
#ifndef _Geo_KnitGraph_Header
#define _Geo_KnitGraph_Header

#include <Standard_TypeDef.hxx>
#include <Geo_KnitNodeType.hxx>
#include <Geo_KnitNode.hxx>
#include <Geo_Graph.hxx>
#include <Global_Done.hxx>
#include <RegisterEntityM_Map.hxx>

#include <map>
#include <memory>
#include <vector>

namespace tnbLib
{

	RegisterEntityM_Map(Geo_KnitNode, NodeType);
	RegisterEntityM_Map(Geo_KnitEdge, EdgeType);

	template<class KnitTraits>
	class Geo_KnitGraph_Registry
	{

		typedef typename KnitTraits::nodeType nodeType;
		typedef typename KnitTraits::edgeType edgeType;

		typedef typename edgeType::adaptor::edgeType segmtType;
		typedef typename segmtType::nodeType ptType;

		typedef RegisterGeo_KnitNode<ptType> ptRegistry;
		typedef RegisterGeo_KnitEdge<segmtType> segRegistry;

		/*Private Data*/

		ptRegistry theNodeRegistry_;
		segRegistry theEdgeRegistry_;

	protected:

		Geo_KnitGraph_Registry()
		{}

		const ptRegistry& PtRegistry() const
		{
			return theNodeRegistry_;
		}

		ptRegistry& PtRegistry()
		{
			return theNodeRegistry_;
		}

		const segRegistry& SegRegistry() const
		{
			return theEdgeRegistry_;
		}

		segRegistry& SegRegistry()
		{
			return theEdgeRegistry_;
		}

	public:

		
	};
	

	template<class KnitTraits>
	class Geo_KnitGraph
		: public Global_Done
		, public Geo_KnitGraph_Registry<KnitTraits>
	{

	public:	

		typedef typename KnitTraits::nodeType nodeType;
		typedef typename KnitTraits::edgeType edgeType;

		typedef typename edgeType::adaptor::edgeType segmtType;
		typedef typename segmtType::nodeType ptType;

		typedef std::vector<std::shared_ptr<segmtType>> polygon;

	private:

		typedef Geo_KnitGraph_Registry<KnitTraits> base;

		/*Private Data*/

		std::map<Standard_Integer, std::shared_ptr<nodeType>> theNodes_;
		std::map<Standard_Integer, std::shared_ptr<edgeType>> theEdges_;


		// private functions

		std::shared_ptr<ptType> Next(const std::shared_ptr<ptType>& theNode);

		std::shared_ptr<nodeType> FindStart(const Geo_KnitNodeType type) const;

		std::shared_ptr<polygon> GetPolygon(const std::shared_ptr<ptType>& theStart);

		static Geo_KnitNodeType Type(const ptType& theNode);


	public:

		Geo_KnitGraph()
		{}

		Standard_Integer NbNodes() const
		{
			return (Standard_Integer)theNodes_.size();
		}

		Standard_Integer NbEdges() const
		{
			return (Standard_Integer)theEdges_.size();
		}

		const std::map<Standard_Integer, std::shared_ptr<nodeType>>& Nodes() const
		{
			return theNodes_;
		}

		const std::map<Standard_Integer, std::shared_ptr<edgeType>>& Edges() const
		{
			return theEdges_;
		}

		void Perform();

		void Import(const Geo_Graph<segmtType>& theGraph);
	};
}

#include <Geo_KnitGraphI.hxx>

#endif // !_Geo_KnitGraph_Header
