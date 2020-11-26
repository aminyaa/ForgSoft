#pragma once
#ifndef _Marine_Boundary_Header
#define _Marine_Boundary_Header

#include <Global_Indexed.hxx>
#include <Global_Named.hxx>
#include <Global_AccessMethod.hxx>

#include <memory>
#include <map>
#include <vector>

namespace tnbLib
{

	// Forward Declarations
	template<class EntityType>
	class Cad_BlockEntity;

	class TModel_Surface;

	class Marine_Boundary
		: public Global_Indexed
		, public Global_Named
		, public std::enable_shared_from_this<Marine_Boundary>
	{

		typedef Cad_BlockEntity<TModel_Surface> surfBlock;

		/*Private Data*/

		std::map<Standard_Integer, std::shared_ptr<surfBlock>>
			theSurfaces_;

	protected:

		Marine_Boundary();

		Marine_Boundary
		(
			const Standard_Integer theIndex
		);

		Marine_Boundary
		(
			const Standard_Integer theIndex, 
			const word& theName
		);

	public:

		virtual ~Marine_Boundary()
		{}

		Standard_Integer NbBlocks() const;

		const auto& SurfaceBlocks() const
		{
			return theSurfaces_;
		}

		std::vector<std::shared_ptr<surfBlock>>
			RetrieveBlocks() const;

		void ImportBlock
		(
			const Standard_Integer theIndex,
			const std::shared_ptr<surfBlock>& theBlock
		);

		void RemoveBlock(const Standard_Integer theIndex);

		void RetrieveBlocksTo
		(
			std::vector<std::shared_ptr<surfBlock>>& theBlocks
		) const;
		
		//- Macros
	};
}

#endif // !_Marine_Boundary_Header
