#pragma once
#ifndef _Cad_BlockEntity_Header
#define _Cad_BlockEntity_Header

#include <Standard_TypeDef.hxx>
#include <Standard_OStream.hxx>

#include <memory>
#include <vector>
#include <map>
#include <list>

#include "Pln_Edge.hxx"

namespace tnbLib
{

	// Forward Declarations
	template<class EntityType>
	class Cad_EntityManager;

	template<class EntityType>
	class Cad_BlockEntity
		: public Global_Named
	{

		template<class EntityType>
		friend class Cad_EntityManager;

		typedef std::map
			<
			Standard_Integer,
			std::shared_ptr<EntityType>
			> indexedMap;

		/*Private Data*/

		indexedMap theEntities_;


		void Add
		(
			const Standard_Integer theIndex, 
			const std::shared_ptr<EntityType>& theEntity
		);

		std::shared_ptr<EntityType> 
			Remove
			(
				const Standard_Integer theIndex
			);

		void Remove
		(
			const typename indexedMap::const_iterator& theIter
		);

	public:

		Cad_BlockEntity();

		Cad_BlockEntity
		(
			const word& theName, 
			const std::vector<std::shared_ptr<EntityType>>& theEntities
		);

		auto NbEntities() const
		{
			return (Standard_Integer)theEntities_.size();
		}

		const auto& Entities() const
		{
			return theEntities_;
		}

		typename indexedMap::const_iterator
			SelectEntity
			(
				const Standard_Integer theIndex
			) const;

		std::shared_ptr<Cad_BlockEntity<EntityType>> 
			Split
			(
				const std::vector<Standard_Integer>& theIndices
			);

		std::shared_ptr<Cad_BlockEntity<EntityType>>
			Split
			(
				const word& theName,
				const std::vector<Standard_Integer>& theIndices
			);

		std::shared_ptr<Cad_BlockEntity<EntityType>>
			Split
			(
				const std::map
				<
				Standard_Integer,
				std::shared_ptr<EntityType>>&theIndices
			);

		std::shared_ptr<Cad_BlockEntity<EntityType>>
			Split
			(
				const word& theName,
				const std::map
				<
				Standard_Integer,
				std::shared_ptr<EntityType>>&theIndices
			);

		std::shared_ptr<Cad_BlockEntity<EntityType>>
			Split
			(
				const std::vector<typename indexedMap::const_iterator>& theIters
			);

		std::shared_ptr<Cad_BlockEntity<EntityType>>
			Split
			(
				const word& theName,
				const std::vector<typename indexedMap::const_iterator>& theIters
			);

		std::vector<Standard_Integer>
			RetrieveKeys() const;

		std::vector<std::shared_ptr<EntityType>> 
			RetrieveEntities() const;

		void MoveFrom
		(
			Cad_BlockEntity& theBlock
		);

		void ImportFrom
		(
			const Cad_BlockEntity& theBlock
		);

		void RetrieveEntitiesTo
		(
			std::vector<std::shared_ptr<EntityType>>& theEntities
		) const;

		void RetrieveKeysTo
		(
			std::vector<Standard_Integer>& theKeys
		) const;

		void Print
		(
			Standard_OStream& Ostream = cout
		) const;
	};
}

#include <Cad_BlockEntityI.hxx>

#endif // !_Cad_BlockEntity_Header
