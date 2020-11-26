#pragma once
#ifndef _Aft_FrontGlobalData_Header
#define _Aft_FrontGlobalData_Header

#include <Aft_CavityData.hxx>

namespace tnbLib
{

	Mesh_RegisterEntity(CurrentFront, FrontEntity);
	Mesh_RegisterEntity(NextFront, FrontEntity);

	template
		<
		class FrontEntity,
		template<class> class GeomSearch,
		template<class> class PriorityList
		>
		class Aft_FrontGlobalData
		: public GeomSearch<std::shared_ptr<typename FrontEntity::nodeType>>
		//- container of the front
		, public PriorityList<std::shared_ptr<FrontEntity>>
		, public Mesh_CavityData<FrontEntity>
		//- a list contains the new entity that belong to the current level
		, public Mesh_RegisterCurrentFront<FrontEntity>
		//- a list contains the new entity that belong to the next level
		, public Mesh_RegisterNextFront<FrontEntity>
	{

		/*Private Data*/

		//- the current level number
		Standard_Integer theLevelNb_;

		//- maximum index entity in the front
		Standard_Integer theLevelMaxIndex_;

		//DisallowBitWiseCopy(Aft_FrontGlobalData);

	public:

		Aft_FrontGlobalData()
			: theLevelNb_(0)
			, theLevelMaxIndex_(0)
		{}

		auto LevelNumber() const
		{
			return theLevelNb_;
		}

		auto LevelMaxIndex() const
		{
			return theLevelMaxIndex_;
		}

		Standard_Boolean IsCurrentLevelEmpty() const
		{
			return !Mesh_RegisterCurrentFront<FrontEntity>::NbCurrentFronts();
		}

		Standard_Boolean IsNextLevelEmpty() const
		{
			return !Mesh_RegisterNextFront<FrontEntity>::NbNextFronts();
		}

		void SetLevelNumber(const Standard_Integer theNumber)
		{
			theLevelNb_ = theNumber;
		}

		void SetLevelMaxIndex(const Standard_Integer theMaxLevel)
		{
			theLevelMaxIndex_ = theMaxLevel;
		}

	};
}

#endif // !_Aft_FrontGlobalData_Header