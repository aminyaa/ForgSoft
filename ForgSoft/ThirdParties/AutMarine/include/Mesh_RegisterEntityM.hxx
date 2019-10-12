#pragma once
#ifndef _Mesh_RegisterEntityM_Header
#define _Mesh_RegisterEntityM_Header

#include <map>
#include <memory>

#define Mesh_RegisterEntity(EntityName, EntityType)																							\
	template<class EntityType>																												\
	class Mesh_Register##EntityName																											\
	{																																		\
																																			\
		/*Private Data*/																													\
																																			\
		std::map<unsigned, std::shared_ptr<EntityType>> the##EntityName##s_;																\
																																			\
	public:																																	\
																																			\
		Mesh_Register##EntityName()																											\
		{}																																	\
																																			\
		Standard_Integer Nb##EntityName##s() const																							\
		{																																	\
			return (Standard_Integer)the##EntityName##s_.size();																			\
		}																																	\
																																			\
																																			\
		/*Standard_Boolean InsertTo##EntityName##s(const unsigned theIndex, const std::shared_ptr<EntityType>& theEntity)						\
		{																																	\
			auto insert = the##EntityName##s_.insert(std::pair<unsigned, std::shared_ptr<EntityType>>(theIndex, theEntity));				\
			return (Standard_Boolean)!insert.second;																						\																															\
		}*/																																	\
																																			\
																																			\
		Standard_Boolean RemoveFrom##EntityName##s(const unsigned theIndex)																	\
		{																																	\
			auto iter = the##EntityName##s_.find(theIndex);																					\
			if (iter == the##EntityName##s_.end())																							\
			{																																\
				return Standard_True;																										\
			}																																\
			the##EntityName##s_.erase(iter);																								\
			return Standard_False;																											\
		}																																	\
																																			\
		Standard_Boolean IsOn##EntityName##s(const unsigned theIndex) const											\
		{																																	\
			auto iter = the##EntityName##s_.find(theIndex);																					\
			if (iter == the##EntityName##s_.end())																							\
			{																																\
				return Standard_False;																										\
			}																																\
			return Standard_True;																											\
		}																																	\
																																			\
		const std::map<unsigned, std::shared_ptr<EntityType>>& Retrieve##EntityName##s() const												\
		{																																	\
			return the##EntityName##s_;																										\
		}																																	\
																																			\
		void Clear##EntityName##s()																											\
		{																																	\
			the##EntityName##s_.clear();																									\
		}																																	\
																																			\
Standard_Boolean InsertTo##EntityName##s(const unsigned theIndex, const std::shared_ptr<EntityType>& theEntity)\
{auto insert = the##EntityName##s_.insert(std::pair<unsigned, std::shared_ptr<EntityType>>(theIndex, theEntity)); return (Standard_Boolean)!insert.second;}\
	}

#endif // !_Mesh_RegisterEntityM_Header