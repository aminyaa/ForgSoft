#pragma once
#ifndef _TModel_Wire_Header
#define _TModel_Wire_Header

#include <TModel_Entity.hxx>
#include <Entity2d_BoxFwd.hxx>

namespace tnbLib
{

	// Forward Declarations
	class TModel_CmpEdge;

	class TModel_Wire
		: public TModel_Entity
	{

		/*Private Data*/

		std::shared_ptr<TModel_CmpEdge> theEdge_;

	public:

		TModel_Wire
		(
			const std::shared_ptr<TModel_CmpEdge>& theEdge
		);

		TModel_Wire
		(
			const Standard_Integer theIndex,
			const std::shared_ptr<TModel_CmpEdge>& theEdge
		);

		TModel_Wire
		(
			const Standard_Integer theIndex,
			const word& theName,
			const std::shared_ptr<TModel_CmpEdge>& theEdge
		);


		const auto& CmpEdge() const
		{
			return theEdge_;
		}

		Entity2d_Box CalcParametricBoundingBox() const;
	};
}

#endif // !_TModel_Wire_Header
