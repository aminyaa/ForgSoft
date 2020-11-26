#pragma once
#include <error.hxx>
#include <OSstream.hxx>
namespace tnbLib
{

	template<class EntityType>
	void Cad_BlockEntity<EntityType>::Add
	(
		const Standard_Integer theIndex, 
		const std::shared_ptr<EntityType>& theEntity
	)
	{
		auto insert = 
			theEntities_.insert(std::make_pair(theIndex, theEntity));
		if (insert.second IS_EQUAL Standard_False)
		{
			FatalErrorIn("void Add(const Standard_Integer theIndex, const std::shared_ptr<EntityType>& theEntity)")
				<< "Duplicate Data: unable to insert the data to the map" << endl
				<< abort(FatalError);
		}
	}

	template<class EntityType>
	std::shared_ptr<EntityType>
		Cad_BlockEntity<EntityType>::Remove
	(
		const Standard_Integer theIndex
	)
	{
		auto iter = theEntities_.find(theIndex);
		auto entity = iter->second;

		if (iter IS_EQUAL theEntities_.end())
		{
			FatalErrorIn("void Remove(const entity_ptr& theEntity)")
				<< "Not found the entity"
				<< abort(FatalError);
		}
		theEntities_.erase(iter);

		return std::move(entity);
	}

	template<class EntityType>
	void Cad_BlockEntity<EntityType>::Remove
	(
		const typename indexedMap::const_iterator & theIter
	)
	{
		theEntities_.erase(theIter);
	}

	template<class EntityType>
	Cad_BlockEntity<EntityType>::Cad_BlockEntity()
		: Global_Named("Default Block")
	{
	}

	template<class EntityType>
	Cad_BlockEntity<EntityType>::Cad_BlockEntity
	(
		const word & theName,
		const std::vector<std::shared_ptr<EntityType>>& theEntities
	)
		: Global_Named(theName)
	{
		for (const auto& x : theEntities)
		{
			Debug_Null_Pointer(x);
			Add(x->Index(), x);
		}
	}

	template<class EntityType>
	typename Cad_BlockEntity<EntityType>::indexedMap::const_iterator 
		Cad_BlockEntity<EntityType>::SelectEntity
		(
			const Standard_Integer theIndex
		) const
	{
		auto iter = theEntities_.find(theIndex);
		return std::move(iter);
	}

	template<class EntityType>
	std::shared_ptr<Cad_BlockEntity<EntityType>> 
		Cad_BlockEntity<EntityType>::Split
		(
			const std::vector<Standard_Integer>& theIndices
		)
	{
		if (theIndices.empty())
		{
			return nullptr;
		}

		auto block = std::make_shared<Cad_BlockEntity<EntityType>>();
		Debug_Null_Pointer(block);

		for (const auto& x : theIndices)
		{
			auto iter = theEntities_.find(x);
			if (iter IS_EQUAL theEntities_.end())
			{
				FatalErrorIn("std::shared_ptr<Cad_BlockEntity<EntityType>> Split(const std::list<Standard_Integer>& theIndices)")
					<< "The Entity is not at the map" << endl
					<< abort(FatalError);
			}

			block->Add(iter->first, iter->second);
			theEntities_.erase(iter);
		}
		return std::move(block);
	}

	template<class EntityType>
	std::shared_ptr<Cad_BlockEntity<EntityType>> 
		Cad_BlockEntity<EntityType>::Split
		(
			const word & theName, 
			const std::vector<Standard_Integer>& theIndices
		)
	{
		auto block = Split(theIndices);
		Debug_Null_Pointer(block);

		block->SetName(theName);
		return std::move(block);
	}

	template<class EntityType>
	std::shared_ptr<Cad_BlockEntity<EntityType>> 
		Cad_BlockEntity<EntityType>::Split
		(
			const std::map<Standard_Integer, 
			std::shared_ptr<EntityType>>& theIndices
		)
	{
		if (theIndices.empty())
		{
			return nullptr;
		}

		auto block = std::make_shared<Cad_BlockEntity<EntityType>>();
		Debug_Null_Pointer(block);

		for (const auto& x : theIndices)
		{
			auto id = x.first;
			const auto& item = x.second;

			auto iter = theEntities_.find(id);
			if (iter IS_EQUAL theEntities_.end())
			{
				FatalErrorIn("std::shared_ptr<Cad_BlockEntity<EntityType>> Split(Args...)")
					<< "The Entity is not at the map" << endl
					<< abort(FatalError);
			}

			if (iter->second NOT_EQUAL item)
			{
				FatalErrorIn("std::shared_ptr<Cad_BlockEntity<EntityType>> Split(Args...)")
					<< "contradictory data!" << endl
					<< abort(FatalError);
			}

			block->Add(iter->first, iter->second);
			theEntities_.erase(iter);
		}
		return std::move(block);
	}

	template<class EntityType>
	std::shared_ptr<Cad_BlockEntity<EntityType>> 
		Cad_BlockEntity<EntityType>::Split
		(
			const word & theName, 
			const std::map<Standard_Integer, std::shared_ptr<EntityType>>& theIndices
		)
	{
		auto block = Split(theIndices);
		Debug_Null_Pointer(block);

		block->SetName(theName);
		return std::move(block);
	}

	template<class EntityType>
	std::shared_ptr<Cad_BlockEntity<EntityType>> 
		Cad_BlockEntity<EntityType>::Split
		(
			const std::vector<typename indexedMap::const_iterator>& theIters
		)
	{
		if (theIters.empty())
		{
			return nullptr;
		}

		auto block = std::make_shared<Cad_BlockEntity<EntityType>>();
		Debug_Null_Pointer(block);

		for (const auto& iter : theIters)
		{
			const auto& x = *iter;
			block->Add(x.first, x.second);
		}
		return std::move(block);
	}

	template<class EntityType>
	std::shared_ptr<Cad_BlockEntity<EntityType>>
		Cad_BlockEntity<EntityType>::Split
		(
			const word& theName,
			const std::vector<typename indexedMap::const_iterator>& theIters
		)
	{
		auto block = Split(theIters);
		Debug_Null_Pointer(block);

		block->SetName(theName);
		return std::move(block);
	}

	template<class EntityType>
	std::vector<Standard_Integer> 
		Cad_BlockEntity<EntityType>::RetrieveKeys() const
	{
		std::vector<Standard_Integer> keys;
		RetrieveKeysTo(keys);

		return std::move(keys);
	}

	template<class EntityType>
	std::vector<std::shared_ptr<EntityType>> 
		Cad_BlockEntity<EntityType>::RetrieveEntities() const
	{
		std::vector<std::shared_ptr<EntityType>> entities;
		entities.reserve(NbEntities());

		auto iter = theEntities_.begin();
		while (iter NOT_EQUAL theEntities_.end())
		{
			entities.push_back(iter->second);
			iter++;
		}
		return std::move(entities);
	}

	template<class EntityType>
	void Cad_BlockEntity<EntityType>::MoveFrom
	(
		Cad_BlockEntity & theBlock
	)
	{
		auto keys = theBlock.RetrieveKeys();
		for (const auto x : keys)
		{
			auto entity = theBlock.Remove(x);
			Debug_Null_Pointer(entity);

			Add(x, entity);
		}
	}

	template<class EntityType>
	void Cad_BlockEntity<EntityType>::ImportFrom
	(
		const Cad_BlockEntity & theBlock
	)
	{
		const auto& entities = theBlock.Entities();
		for (const auto& x : entities)
		{
			Debug_Null_Pointer(x.second);
			Add(x.first, x.second);
		}
	}

	template<class EntityType>
	void Cad_BlockEntity<EntityType>::RetrieveEntitiesTo
	(
		std::vector<std::shared_ptr<EntityType>>& theEntities
	) const
	{
		theEntities.reserve(NbEntities());

		auto iter = theEntities_.begin();
		while (iter NOT_EQUAL theEntities_.end())
		{
			theEntities.push_back(iter->second);
			iter++;
		}
	}

	template<class EntityType>
	void Cad_BlockEntity<EntityType>::RetrieveKeysTo
	(
		std::vector<Standard_Integer>& theKeys
	) const
	{
		theKeys.reserve(NbEntities());
		for (const auto& x : Entities())
		{
			theKeys.push_back(x.first);
		}
	}

	template<class EntityType>
	void Cad_BlockEntity<EntityType>::Print
	(
		Standard_OStream & Ostream
	) const
	{
		Ostream << " Nb. of Entity = " << NbEntities() << std::endl;
		Ostream << " Entity List: " << std::endl;

		auto iter = theEntities_.begin();
		while (iter NOT_EQUAL theEntities_.end())
		{
			Ostream << iter->first << "  ";
			iter++;
		}
	}
}