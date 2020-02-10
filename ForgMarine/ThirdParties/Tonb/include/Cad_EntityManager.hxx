#pragma once
#ifndef _Cad_EntityManager_Header
#define _Cad_EntityManager_Header

#include <Standard_TypeDef.hxx>
#include <Standard_OStream.hxx>
#include <Global_Named.hxx>

#include <memory>
#include <vector>
#include <list>
#include <map>

#include "Pln_Edge.hxx"

namespace tnbLib
{

	// Forward Declarations
	template<class EntityType>
	class Cad_BlockEntity;

	struct Cad_EntityManager_Duplicator
	{

		word(*duplicator)(const word& theName);

	protected:

		Cad_EntityManager_Duplicator();
	};

	template<class EntityType>
	class Cad_EntityManager
		: public Global_Named
		, public Cad_EntityManager_Duplicator
	{

		typedef std::map<word, std::shared_ptr<Cad_BlockEntity<EntityType>>> stringMapOfBlocks;

		/*Private Data*/

		stringMapOfBlocks theBlocks_;
	

	public:

		Cad_EntityManager
		(
			const word& theName, 
			const std::shared_ptr<Cad_BlockEntity<EntityType>>& theBlock
		);


		enum class PrimBlock
		{
			First = 0,
			Second
		};


		Standard_Integer Size() const;

		auto NbBlocks() const
		{
			return (Standard_Integer)theBlocks_.size();
		}

		const auto& Blocks() const
		{
			return theBlocks_;
		}

		typename stringMapOfBlocks::const_iterator
			Import
			(
				const word& theName, 
				const std::shared_ptr<Cad_BlockEntity<EntityType>>& theBlock
			);

		typename stringMapOfBlocks::const_iterator
			SelectBlock
			(
				const word& theName
			) const;

		std::shared_ptr<Cad_BlockEntity<EntityType>> 
			RemoveBlock
			(
				const typename stringMapOfBlocks::const_iterator& theBlock
			);

		Standard_Boolean 
			HasBlock
			(
				const word& theName
			) const;

		std::vector<std::shared_ptr<Cad_BlockEntity<EntityType>>>
			RetrieveBlocks() const;

		std::vector<std::shared_ptr<EntityType>>
			RetrieveEntities() const;

		typename stringMapOfBlocks::const_iterator
			ReNameBlock
		(
			const typename stringMapOfBlocks::const_iterator& theBlock,
			const word& theName
		);

		typename stringMapOfBlocks::const_iterator
			CombineBlocks
		(
			const typename stringMapOfBlocks::const_iterator& theBlock0, 
			const typename stringMapOfBlocks::const_iterator& theBlock1, 
			const word& theName
		);

		const typename stringMapOfBlocks::const_iterator&
			CombineBlocks
		(
			const typename stringMapOfBlocks::const_iterator& theBlock0,
			const typename stringMapOfBlocks::const_iterator& theBlock1,
			const PrimBlock theSelect = PrimBlock::First
		);

		typename stringMapOfBlocks::const_iterator
			CombineBlocks
		(
			const std::vector<typename stringMapOfBlocks::const_iterator>& theBlocks,
			const word& theName
		);

		void CompactBlocks
		(
			const word& theName
		);

		void CompactBlocksWith
		(
			const typename stringMapOfBlocks::const_iterator& theBlock
		);

		void RetrieveBlocksTo
		(
			std::vector<std::shared_ptr<Cad_BlockEntity<EntityType>>>& theEntities
		) const;

		void RetrieveEntitiesTo
		(
			std::vector<std::shared_ptr<EntityType>>& theEntities
		) const;

		void Print
		(
			const Standard_Boolean PrintEntities = Standard_False,
			Standard_OStream& Ostream = cout
		) const;
	};
}

#include <Cad_EntityManagerI.hxx>

#endif // !_Cad_EntityManager_Header
