#pragma once
#include <Global_Macros.hxx>
#include <Cad_BlockEntity.hxx>
#include <error.hxx>
#include <OSstream.hxx>
template<class EntityType>
void AutLib::Cad_EntityManager<EntityType>::Import
(
	const word & theName,
	const block_ptr & theBlock
)
{
	auto insert = theBlocks_.insert(std::make_pair(theName, theBlock));
	if (insert.second IS_EQUAL Standard_False)
	{
		Import(theName + "(1)", theBlock);
		return;
	}
	else
		theBlock->SetName(theName);
}

template<class EntityType>
Standard_Integer AutLib::Cad_EntityManager<EntityType>::Size() const
{
	Standard_Integer K = 0;

	auto iter = theBlocks_.begin();
	while (iter NOT_EQUAL theBlocks_.end())
	{
		K += iter->second->NbEntities();
		iter++;
	}
	return K;
}

template<class EntityType>
Standard_Boolean AutLib::Cad_EntityManager<EntityType>::GetBlockEntity
(
	const word & theName,
	block_ptr & theBlock
) const
{
	auto iter = theBlocks_.find(theName);
	if (iter IS_EQUAL theBlocks_.end())
		return Standard_True;
	theBlock = iter->second;
	return Standard_False;
}

template<class EntityType>
Standard_Boolean AutLib::Cad_EntityManager<EntityType>::HasBlock
(
	const word & theName
) const
{
	auto iter = theBlocks_.find(theName);
	if (iter IS_EQUAL theBlocks_.end())
		return Standard_False;
	return Standard_True;
}

template<class EntityType>
typename AutLib::Cad_EntityManager<EntityType>::block_ptr
AutLib::Cad_EntityManager<EntityType>::SelectBlockEntity
(
	const word & theName
) const
{
	auto iter = theBlocks_.find(theName);
	if (iter NOT_EQUAL theBlocks_.end())
	{
		theSelected_.push_back(theName);
		return iter->second;
	}
	return nullptr;
}

template<class EntityType>
typename AutLib::Cad_EntityManager<EntityType>::block_ptr
AutLib::Cad_EntityManager<EntityType>::GetBlockEntity
(
	const word & theName
) const
{
	auto iter = theBlocks_.find(theName);
	if (iter IS_EQUAL theBlocks_.end())
		return nullptr;
	return iter->second;
}

template<class EntityType>
void AutLib::Cad_EntityManager<EntityType>::SelectAll()
{
	auto iter = theBlocks_.begin();
	while (iter NOT_EQUAL theBlocks_.end())
	{
		theSelected_.push_back(iter->first);
		iter++;
	}
}

template<class EntityType>
void AutLib::Cad_EntityManager<EntityType>::UnSelectAll()
{
	while (NOT theSelected_.empty())
	{
		auto String = theSelected_.front();
		auto block = GetBlockEntity(String);
		if (block) block->UnSelectAll();

		theSelected_.pop_front();
	}
}

template<class EntityType>
typename AutLib::Cad_EntityManager<EntityType>::block_ptr 
AutLib::Cad_EntityManager<EntityType>::Combine()
{
	if (theSelected_.size() < 2)
	{
		FatalErrorIn("block_ptr combine()")
			<< "Invalid data" << endl
			<< abort(FatalError);
	}

	auto blockName = theSelected_.front();
	theSelected_.pop_front();

	auto block = theBlocks_.find(blockName);
	Debug_If_Condition(block IS_EQUAL theBlocks_.end());

	while (NOT theSelected_.empty())
	{
		blockName = theSelected_.front();
		theSelected_.pop_front();

		auto iter = theBlocks_.find(blockName);
		Debug_If_Condition(iter IS_EQUAL theBlocks_.end());

		entityList entities;
		iter->second->RetrieveEntitiesTo(entities);

		for (const auto& x : entities)
			block->second->Add(x);

		theBlocks_.erase(iter);
	}
	return std::move(block->second);
}

template<class EntityType>
void AutLib::Cad_EntityManager<EntityType>::Combine
(
	const word & Blockname
)
{
	auto block = Combine();

	//SelectBlockEntity(block->Name());
	RenameBlock(block, Blockname);
}

template<class EntityType>
void AutLib::Cad_EntityManager<EntityType>::CompactBlocks
(
	const word & BlockName
)
{
	SelectAll();

	Combine(BlockName);
}

template<class EntityType>
void AutLib::Cad_EntityManager<EntityType>::Split
(
	const word & BlockName
)
{
	if (theSelected_.size() NOT_EQUAL 1)
	{
		UnSelectAll();
		return;
	}

	auto String = theSelected_.front();
	theSelected_.pop_front();

	auto block = GetBlockEntity(String);
	if (block)
	{
		auto newBlock = block->SplitByPatch();
		Debug_Null_Pointer(newBlock);

		newBlock->SetName(BlockName);

		Import(newBlock->Name(), newBlock);
	}
}

template<class EntityType>
void AutLib::Cad_EntityManager<EntityType>::RenameBlock
(
	const word & theName
)
{
	if (theSelected_.size() NOT_EQUAL 1)
	{
		UnSelectAll();
		return;
	}

	auto String = theSelected_.front();
	theSelected_.pop_front();

	auto block = GetBlockEntity(String);

	if (block)
	{
		theBlocks_.erase(String);
		block->SetName(theName);

		Import(block->Name(), block);
	}
}

template<class EntityType>
void AutLib::Cad_EntityManager<EntityType>::RenameBlock(const block_ptr& theBlock, const word& theName)
{
	if (theBlock)
	{
		theBlocks_.erase(theBlock->Name());
		theBlock->SetName(theName);

		Import(theBlock->Name(), theBlock);
	}
}

template<class EntityType>
void AutLib::Cad_EntityManager<EntityType>::RetrieveTo
(
	entityList & theEntities
) const
{
	auto iter = theBlocks_.begin();
	while (iter NOT_EQUAL theBlocks_.end())
	{
		entityList edges;
		iter->second->RetrieveEntitiesTo(edges);
		iter++;

		for (const auto& x : edges)
			theEntities.push_back(x);
	}
}

template<class EntityType>
void AutLib::Cad_EntityManager<EntityType>::RetrieveTo
(
	blockList & theBlocks
) const
{
	theBlocks.reserve(theBlocks_.size());

	auto iter = theBlocks_.begin();
	while (iter NOT_EQUAL theBlocks_.end())
	{
		theBlocks.push_back(iter->second);
		iter++;
	}
}

template<class EntityType>
void AutLib::Cad_EntityManager<EntityType>::Print
(
	const Standard_Boolean PrintCurves,
	Standard_OStream & Ostream
) const
{
	Ostream << "-----------------{ Entities Blocks Informations }-----------------\n";
	Ostream << " Nb. of Blocks: " << theBlocks_.size() << std::endl;
	Ostream << " Block List: " << std::endl;

	auto Iter = theBlocks_.begin();
	while (Iter NOT_EQUAL theBlocks_.end())
	{
		Ostream << std::endl;
		Ostream << "  - " << Iter->first;
		if (PrintCurves)
		{
			Iter->second->Print(Ostream);
		}
		Iter++;
	}

	Ostream << std::endl;
	Ostream << "-----------------{ End of Entities Blocks Informations }-----------------\n";
}