#pragma once
#include <Cad_BlockEntity.hxx>
#include <error.hxx>
#include <OSstream.hxx>
namespace tnbLib
{

	template<class EntityType>
	Cad_EntityManager<EntityType>::Cad_EntityManager
	(
		const word & theName, 
		const std::shared_ptr<Cad_BlockEntity<EntityType>>& theBlock
	)
	{
		Import(theName, theBlock);
	}

	template<class EntityType>
	Standard_Integer Cad_EntityManager<EntityType>::Size() const
	{
		Standard_Integer K = 0;
		for (const auto& x : Blocks())
		{
			Debug_Null_Pointer(x.second);
			K += x.second->NbEntities();
		}
		return K;
	}

	template<class EntityType>
	typename Cad_EntityManager<EntityType>::stringMapOfBlocks::const_iterator 
		Cad_EntityManager<EntityType>::Import
		(
			const word & theName, 
			const std::shared_ptr<Cad_BlockEntity<EntityType>>& theBlock
		)
	{
		auto insert = theBlocks_.insert(std::make_pair(theName, theBlock));
		if (insert.second IS_EQUAL Standard_False)
		{
			Debug_Null_Pointer(duplicator);

			auto import = Import(duplicator(theName), theBlock);
			return std::move(import);
		}
		return insert.first;
	}

	template<class EntityType>
	typename Cad_EntityManager<EntityType>::stringMapOfBlocks::const_iterator
		Cad_EntityManager<EntityType>::SelectBlock
		(
			const word & theName
		) const
	{
		auto iter = theBlocks_.find(theName);
		if (iter IS_EQUAL theBlocks_.end())
		{
			FatalErrorIn("iterator Cad_EntityManager<EntityType>::SelectBlock(const word & theName) const")
				<< "the item is not in the map!" << endl
				<< abort(FatalError);
		}
		return std::move(iter);
	}

	template<class EntityType>
	std::shared_ptr<Cad_BlockEntity<EntityType>> 
		Cad_EntityManager<EntityType>::RemoveBlock
		(
			const typename stringMapOfBlocks::const_iterator & theBlock
		)
	{
		theBlocks_.erase(theBlock);
	}

	template<class EntityType>
	Standard_Boolean Cad_EntityManager<EntityType>::HasBlock
	(
		const word & theName
	) const
	{
		auto iter = theBlocks_.find(theName);
		if (iter IS_EQUAL theBlocks_.end())
		{
			return Standard_False;
		}
		return Standard_True;
	}

	template<class EntityType>
	std::vector<std::shared_ptr<Cad_BlockEntity<EntityType>>> 
		Cad_EntityManager<EntityType>::RetrieveBlocks() const
	{
		std::vector<std::shared_ptr<Cad_BlockEntity<EntityType>>> blocks;
		RetrieveBlocksTo(blocks);

		return std::move(blocks);
	}

	template<class EntityType>
	std::vector<std::shared_ptr<EntityType>> 
		Cad_EntityManager<EntityType>::RetrieveEntities() const
	{
		std::vector<std::shared_ptr<EntityType>> entities;
		RetrieveEntitiesTo(entities);

		return std::move(entities);
	}

	template<class EntityType>
	typename Cad_EntityManager<EntityType>::stringMapOfBlocks::const_iterator 
		Cad_EntityManager<EntityType>::ReNameBlock
	(
		const typename stringMapOfBlocks::const_iterator& theBlock,
		const word & theName
	)
	{
		auto block = RemoveBlock(theBlock);

		auto import = Import(theName, block);
		return std::move(import);
	}

	template<class EntityType>
	typename Cad_EntityManager<EntityType>::stringMapOfBlocks::const_iterator
		Cad_EntityManager<EntityType>::CombineBlocks
	(
		const typename stringMapOfBlocks::const_iterator & theBlock0, 
		const typename stringMapOfBlocks::const_iterator & theBlock1, 
		const word & theName
	)
	{
		if (theBlock0 IS_EQUAL theBlock1)
		{
			FatalErrorIn("void Cad_EntityManager<EntityType>::CombineBlocks(Args...)")
				<< "the two blocks are the same!" << endl
				<< abort(FatalError);
		}

		auto b0 = RemoveBlock(theBlock0);
		auto b1 = RemoveBlock(theBlock1);

		Debug_Null_Pointer(b0);
		Debug_Null_Pointer(b1);

		b0->MoveFrom(*b1);

		auto import = Import(theName, b0);
		return std::move(import);
	}

	template<class EntityType>
	const typename Cad_EntityManager<EntityType>::stringMapOfBlocks::const_iterator&
		Cad_EntityManager<EntityType>::CombineBlocks
	(
		const typename stringMapOfBlocks::const_iterator & theBlock0,
		const typename stringMapOfBlocks::const_iterator & theBlock1,
		const PrimBlock theSelect
	)
	{
		if (theSelect IS_EQUAL PrimBlock::Second)
		{
			auto iter = CombineBlocks(theBlock1, theBlock0);
			return std::move(iter);
		}

		auto b1 = RemoveBlock(theBlock1);
		Debug_Null_Pointer(b1);

		theBlock0->second->MoveFrom(*b1);

		return theBlock0;
	}

	template<class EntityType>
	typename Cad_EntityManager<EntityType>::stringMapOfBlocks::const_iterator
		Cad_EntityManager<EntityType>::CombineBlocks
		(
			const std::vector<typename stringMapOfBlocks::const_iterator>& theBlocks,
			const word & theName
		)
	{
		if (theBlocks.size() < 2)
		{
			FatalErrorIn("void CombineBlocks(...)")
				<< "the size of the select list is < 2" << endl
				<< abort(FatalError);
		}

		std::vector<std::shared_ptr<Cad_BlockEntity<EntityType>>> entities;
		entities.reserve(theBlocks.size());
		for (const auto& x : theBlocks)
		{
			auto ent = RemoveBlock(x);
			entities.push_back(std::move(ent));
		}

		auto& ent0 = entities[0];
		for (int i = 1; i < entities.size(); i++)
		{
			ent0->MoveFrom(*entities[i]);
		}

		auto iter = Import(theName, ent0);
		return std::move(iter);
	}

	template<class EntityType>
	void Cad_EntityManager<EntityType>::CompactBlocks
	(
		const word & theName
	)
	{
		auto iter = theBlocks_.begin();
		CompactBlocksWith(iter);

		ReNameBlock(iter, theName);
	}

	template<class EntityType>
	void Cad_EntityManager<EntityType>::CompactBlocksWith
	(
		const typename stringMapOfBlocks::const_iterator & theBlock
	)
	{
		auto iter = theBlocks_.begin();
		while (iter NOT_EQUAL theBlocks_.end())
		{
			if (iter NOT_EQUAL theBlock)
			{
				CombineBlocks(theBlock, iter);
			}
		}
	}

	template<class EntityType>
	void Cad_EntityManager<EntityType>::RetrieveBlocksTo
	(
		std::vector<std::shared_ptr<Cad_BlockEntity<EntityType>>>& theEntities
	) const
	{
		theEntities.reserve(NbBlocks());
		for (const auto& x : Blocks())
		{
			Debug_Null_Pointer(x.second);
			theEntities.push_back(x.second);
		}
	}

	template<class EntityType>
	void Cad_EntityManager<EntityType>::RetrieveEntitiesTo
	(
		std::vector<std::shared_ptr<EntityType>>& theEntities
	) const
	{
		for (const auto& x : Blocks())
		{
			Debug_Null_Pointer(x.second);
			const auto& entities = x.second->Entities();

			for (const auto& ent : entities)
			{
				Debug_Null_Pointer(ent.second);
				theEntities.push_back(ent.second);
			}
		}
	}

	template<class EntityType>
	void Cad_EntityManager<EntityType>::Print
	(
		const Standard_Boolean PrintEntities,
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
			if (PrintEntities)
			{
				Iter->second->Print(Ostream);
			}
			Iter++;
		}

		Ostream << std::endl;
		Ostream << "-----------------{ End of Entities Blocks Informations }-----------------\n";
	}

	inline word add_copy_duplicator(const word& theName)
	{
		auto w = theName + "(copy)";
		return std::move(w);
	}
}