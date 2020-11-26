#pragma once
#ifndef _CadModel_Entity_Header
#define _CadModel_Entity_Header

#include <Global_Indexed.hxx>
#include <Global_Named.hxx>
#include <Global_Done.hxx>

#include <memory>

#include <TopoDS_Shape.hxx>

namespace tnbLib
{

	class CadModel_Entity
		: public Global_Indexed
		, public Global_Named
		, public Global_Done
		, public std::enable_shared_from_this<CadModel_Entity>
	{

		/*Private Data*/

		TopoDS_Shape theEntity_;

		TopoDS_Shape thePreview_;

	protected:

		CadModel_Entity()
		{}

		CadModel_Entity
		(
			const Standard_Integer theIndex
		)
			: Global_Indexed(theIndex)
		{}

		CadModel_Entity
		(
			const Standard_Integer theIndex,
			const word& theName
		)
			: Global_Indexed(theIndex)
			, Global_Named(theName)
		{}


		auto& ChangeEntity()
		{
			return theEntity_;
		}

		auto& ChangePreviewEntity()
		{
			return thePreview_;
		}

	public:

		virtual ~CadModel_Entity()
		{}

		const auto& Entity() const
		{
			return theEntity_;
		}

		const auto& PreviewEntity() const
		{
			return thePreview_;
		}

		virtual void PerformToPreview() = 0;
	};
}

#endif // !_CadModel_Entity_Header
