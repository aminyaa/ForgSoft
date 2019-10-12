#pragma once
#include <Global_Macros.hxx>
#include <error.hxx>
#include <OSstream.hxx>
template<class EntityType>
void AutLib::Cad_BlockEntity<EntityType>::SetEntities
(
	const entityList & theEntities
)
{
	for (const auto& x : theEntities)
	{
		Add(x);
	}
}

template<class EntityType>
void AutLib::Cad_BlockEntity<EntityType>::Add
(
	const entity_ptr & theEntity
)
{
	auto insert =
		theEntities_.insert(std::make_pair(theEntity->Index(), theEntity));
	if (insert.second IS_EQUAL Standard_False)
	{
		FatalErrorIn("void Add(const entity_ptr& theEntity)")
			<< "Duplicate Data" << endl
			<< abort(FatalError);
	}
}

template<class EntityType>
void AutLib::Cad_BlockEntity<EntityType>::Remove
(
	const entity_ptr & theEntity
)
{
	auto iter = theEntities_.find(theEntity->Index());
	if (iter IS_EQUAL theEntities_.end())
	{
		FatalErrorIn("void Remove(const entity_ptr& theEntity)")
			<< "Not found the entity"
			<< abort(FatalError);
	}
	theEntities_.erase(iter);
}

template<class EntityType>
std::shared_ptr<AutLib::Cad_BlockEntity<EntityType>>
AutLib::Cad_BlockEntity<EntityType>::SplitByPatch()
{
	if (NOT theSelected_.size())
		return nullptr;

	auto block = std::make_shared<Cad_BlockEntity<EntityType>>();
	while (NOT theSelected_.empty())
	{
		auto iter = theEntities_.find(theSelected_.front());
		theSelected_.pop_front();

		if (iter IS_EQUAL theEntities_.end())
		{
			FatalErrorIn("std::shared_ptr<Plane_BlockEntity> SplitByPatch()")
				<< "The Entity is not at list" << endl
				<< abort(FatalError);
		}

		block->Add(iter->second);
		theEntities_.erase(iter);
	}
	return std::move(block);
}

template<class EntityType>
void AutLib::Cad_BlockEntity<EntityType>::SelectEntity
(
	const Standard_Integer theIndex
) const
{
	auto iter = theEntities_.find(theIndex);
	if (iter IS_EQUAL theEntities_.end())
	{
		FatalErrorIn("void SelectEntity(const Standard_Integer theIndex) const")
			<< "The Entity is NOT in the List" << endl
			<< abort(FatalError);
	}

	theSelected_.push_back(theIndex);
}

template<class EntityType>
void AutLib::Cad_BlockEntity<EntityType>::UnSelectAll() const
{
	theSelected_.clear();
}

template<class EntityType>
void AutLib::Cad_BlockEntity<EntityType>::RetrieveEntitiesTo
(
	entityList & theEntities
) const
{
	auto iter = theEntities_.begin();
	while (iter NOT_EQUAL theEntities_.end())
	{
		theEntities.push_back(iter->second);
		iter++;
	}
}

template<class EntityType>
void AutLib::Cad_BlockEntity<EntityType>::Print
(
	Standard_OStream & Ostream
) const
{
	Ostream << " Nb. of Entity = " << NbEntities() << endl;
	Ostream << " Entity List: " << endl;

	auto iter = theEntities_.begin();
	while (iter NOT_EQUAL theEntities_.end())
	{
		Ostream << iter->first << "  ";
		iter++;
	}
}

template<class EntityType>
void AutLib::Cad_BlockEntity<EntityType>::Clear()
{
	theEntities_.clear();
}
