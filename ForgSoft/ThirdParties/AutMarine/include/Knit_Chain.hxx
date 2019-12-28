#pragma once
#ifndef _Knit_Chain_Header
#define _Knit_Chain_Header

#include <Global_Done.hxx>
#include <Knit_ChainNode.hxx>
#include <Knit_ChainRegister.hxx>
#include <Entity_Polygon.hxx>
#include <Entity_StaticData.hxx>
#include <Entity_Connectivity.hxx>

#include <memory>
#include <vector>

namespace AutLib
{

	template<class KnitTraits>
	class Knit_Chain
		: public Global_Done
		, public RegisterKnit_ChainNode<typename KnitTraits::nodeType>
		, public RegisterKnit_ChainEdge<typename KnitTraits::edgeType>
	{

	public:

		typedef RegisterKnit_ChainNode<typename KnitTraits::nodeType> nodeRegistery;
		typedef RegisterKnit_ChainEdge<typename KnitTraits::edgeType> edgeRegistery;

		typedef typename KnitTraits::nodeType nodeType;
		typedef typename KnitTraits::edgeType edgeType;
		typedef typename nodeType::ptType ptType;
		typedef ptType Point;

		typedef Entity_Polygon<Point> polygon;
		typedef std::vector<std::shared_ptr<polygon>> polyList;

	private:

		/*Private Data*/

		polyList thePolygons_;



		// private functions

		std::shared_ptr<nodeType> Next(const std::shared_ptr<nodeType>& theNode);

		std::shared_ptr<nodeType> FindStart(const Knit_ChainNode_Type type) const;

		std::shared_ptr<polygon> GetPolygon(const std::shared_ptr<nodeType>& theStart);

		void SetTypes();

	public:

		Knit_Chain()
		{}

		Standard_Integer NbPolygons() const
		{
			return (Standard_Integer)thePolygons_.size();
		}

		const std::shared_ptr<polygon>& Polygon(const Standard_Integer theIndex) const
		{
			return thePolygons_[theIndex];
		}

		void Perform();

		void Import(const Entity_StaticData<Point, connectivity::dual>& theChain);

	};
}

#include <Knit_ChainI.hxx>

#endif // !_Knit_Chain_Header
