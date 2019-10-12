#pragma once
#ifndef _Cad_BlockEntity_Header
#define _Cad_BlockEntity_Header

#include <Standard_TypeDef.hxx>
#include <Standard_OStream.hxx>
#include <Global_Named.hxx>

#include <memory>
#include <vector>
#include <list>
#include <map>

namespace AutLib
{

	// Forward Declarations
	template<class EntityType>
	class Cad_EntityManager;

	template<class EntityType>
	class Cad_BlockEntity
		: /*public std::enable_shared_from_this<EntityType>
		, */public Global_Named
	{

		template<class EntityType>
		friend class Cad_EntityManager;

		typedef std::list<Standard_Integer> labelList;
		typedef std::shared_ptr<EntityType> entity_ptr;
		typedef std::vector<entity_ptr> entityList;

		typedef std::map<Standard_Integer, std::shared_ptr<EntityType>>
			indexedMapOfEntity;

		/*Private Data*/

		indexedMapOfEntity theEntities_;

		mutable labelList theSelected_;

		void SetEntities(const entityList& theEntities);

		void Add(const entity_ptr& theEntity);

		void Remove(const entity_ptr& theEntity);

		std::shared_ptr<Cad_BlockEntity> SplitByPatch();

	public:

		Cad_BlockEntity()
			: Global_Named("Block Entity")
		{}

		Cad_BlockEntity
		(
			const word& theName,
			const entityList& theEntities
		)
			: Global_Named(theName)
		{
			SetEntities(theEntities);
		}

		Standard_Integer NbEntities() const
		{
			return (Standard_Integer)theEntities_.size();
		}

		void SelectEntity(const Standard_Integer theIndex) const;

		void UnSelectAll() const;

		void RetrieveEntitiesTo(entityList& theEntities) const;

		void Print(Standard_OStream& Ostream = cout) const;

		void Clear();
	};
}

#include <Cad_BlockEntityI.hxx>

#endif // !_Cad_BlockEntity_Header