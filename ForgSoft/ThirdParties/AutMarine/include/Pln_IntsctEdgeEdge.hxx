#pragma once
#ifndef _Pln_IntsctEdgeEdge_Header
#define _Pln_IntsctEdgeEdge_Header

#include <Standard_TypeDef.hxx>
#include <Global_Done.hxx>

#include <memory>
#include <vector>

namespace AutLib
{

	// Forward Declarations
	class Pln_IntsctPair;
	class Pln_Edge;
	class Pln_IntsctEdgeEdgeInfo;

	class Pln_IntsctEdgeEdge
		: public Global_Done
	{

		typedef Pln_IntsctEdgeEdgeInfo info;

		/*Private Data*/

		std::shared_ptr<Pln_Edge> theEdge0_;
		std::shared_ptr<Pln_Edge> theEdge1_;

		std::shared_ptr<info> theInfo_;

		std::vector<std::shared_ptr<Pln_IntsctPair>> theEntities_;


		std::vector<std::shared_ptr<Pln_IntsctPair>>& ChangeEntities()
		{
			return theEntities_;
		}

	public:

		Pln_IntsctEdgeEdge()
		{}

		Pln_IntsctEdgeEdge
		(
			const std::shared_ptr<Pln_Edge>& theEdge0,
			const std::shared_ptr<Pln_Edge>& theEdge1,
			const std::shared_ptr<info>& theInfo
		)
			: theEdge0_(theEdge0)
			, theEdge1_(theEdge1)
			, theInfo_(theInfo)
		{}

		const std::shared_ptr<Pln_Edge>& Edge0() const
		{
			return theEdge0_;
		}

		const std::shared_ptr<Pln_Edge>& Edge1() const
		{
			return theEdge1_;
		}

		Standard_Integer NbEntities() const
		{
			return (Standard_Integer)theEntities_.size();
		}

		Standard_Boolean HasIntersection() const
		{
			return (Standard_Boolean)theEntities_.size();
		}

		const std::shared_ptr<info>& Info() const
		{
			return theInfo_;
		}

		const std::vector<std::shared_ptr<Pln_IntsctPair>>& Entities() const
		{
			return theEntities_;
		}

		const std::shared_ptr<Pln_IntsctPair>& 
			Entity
			(
				const Standard_Integer theIndex
			) const;

		void LoadEdges
		(
			const std::shared_ptr<Pln_Edge>& theEdge0,
			const std::shared_ptr<Pln_Edge>& theEdge1,
			const std::shared_ptr<info>& theInfo
		)
		{
			theEdge0_ = theEdge0;
			theEdge1_ = theEdge1;

			theInfo_ = theInfo;
		}

		void Perform();
	};
}

#endif // !_Pln_IntsctEdgeEdge_Header
