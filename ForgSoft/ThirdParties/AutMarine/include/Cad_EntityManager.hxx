#pragma once
#ifndef _Cad_EntityManager_Header
#define _Cad_EntityManager_Header

#include <Standard_TypeDef.hxx>
#include <Standard_OStream.hxx>
#include <Global_Named.hxx>

#include <vector>
#include <list>
#include <map>
#include <memory>

namespace AutLib
{

	// Forward Declarations
	template<class EntityType>
	class Cad_BlockEntity;

	template<class EntityType>
	class Cad_EntityManager
		: public Global_Named
	{

		typedef std::list<word> wordList;
		typedef std::shared_ptr<Cad_BlockEntity<EntityType>> block_ptr;
		typedef std::vector<block_ptr> blockList;

		typedef std::shared_ptr<EntityType> entity_ptr;
		typedef std::vector<entity_ptr> entityList;

		typedef std::map<word, std::shared_ptr<Cad_BlockEntity<EntityType>>> stringMapOfBlocks;

		/*Private Data*/

		stringMapOfBlocks theBlocks_;

		mutable wordList theSelected_;

		void Import
		(
			const word& theName,
			const block_ptr& theBlock
		);

	public:

		Cad_EntityManager
		(
			const word& theName,
			const block_ptr& theBlock
		)
		{
			Import(theName, theBlock);
		}

		Cad_EntityManager
		(
			const blockList& theBlocks
		);

		Standard_Integer Size() const;

		Standard_Integer NbBlocks() const
		{
			return (Standard_Integer)theBlocks_.size();
		}

		Standard_Boolean GetBlockEntity
		(
			const word& theName,
			block_ptr& theBlock
		) const;

		Standard_Boolean HasBlock
		(
			const word& theName
		) const;

		block_ptr SelectBlockEntity
		(
			const word& theName
		) const;

		block_ptr GetBlockEntity
		(
			const word& theName
		) const;

		void SelectAll();

		void UnSelectAll();

		block_ptr Combine();

		void Combine(const word& Blockname);

		void CompactBlocks(const word& BlockName);

		void Split(const word& BlockName);

		void RenameBlock(const word& theName);

		void RenameBlock(const block_ptr& theBlock, const word& theName);

		void RetrieveTo(entityList& theEntities) const;

		void RetrieveTo(blockList& theBlocks) const;

		void Print
		(
			const Standard_Boolean PrintCurves = Standard_False,
			Standard_OStream& Ostream = cout
		) const;
	};
}

#include <Cad_EntityManagerI.hxx>

#endif // !_Cad_EntityManager_Header