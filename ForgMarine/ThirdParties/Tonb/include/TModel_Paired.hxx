#pragma once
#ifndef _TModel_Paired_Header
#define _TModel_Paired_Header

#include <Global_AccessMethod.hxx>
#include <TModel_Entity.hxx>
#include <TModel_PairedGeometry.hxx>

namespace tnbLib
{

	// Forward Declarations
	class TModel_Edge;

	class TModel_Paired
		: public TModel_Entity
		, public TModel_PairedGeometry
	{

		/*Private Data*/

		std::shared_ptr<TModel_Edge> theEdge0_;
		std::shared_ptr<TModel_Edge> theEdge1_;



	public:

		TModel_Paired
		(
			const std::shared_ptr<TModel_Edge>& theEdge0,
			const std::shared_ptr<TModel_Edge>& theEdge1
		);

		TModel_Paired
		(
			const Standard_Integer theIndex,
			const std::shared_ptr<TModel_Edge>& theEdge0,
			const std::shared_ptr<TModel_Edge>& theEdge1
		);

		TModel_Paired
		(
			const Standard_Integer theIndex,
			const word& theName,
			const std::shared_ptr<TModel_Edge>& theEdge0,
			const std::shared_ptr<TModel_Edge>& theEdge1
		);

		Standard_Boolean IsFree() const;

		const auto& Edge0() const
		{
			return theEdge0_;
		}

		const auto& Edge1() const
		{
			return theEdge1_;
		}

		const std::shared_ptr<TModel_Edge>& Other
		(
			const std::shared_ptr<TModel_Edge>& theEdge
		);

		Standard_Boolean IsPaired() const
		{
			return theEdge0_ && theEdge1_;
		}
	};
}

#endif // !_TModel_Paired_Header
