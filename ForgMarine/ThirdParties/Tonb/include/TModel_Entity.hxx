#pragma once
#ifndef _TModel_Entity_Header
#define _TModel_Entity_Header

#include <Global_Indexed.hxx>
#include <Global_Named.hxx>

#include <memory>

namespace tnbLib
{

	class TModel_Entity
		: public Global_Indexed
		, public Global_Named
		, public std::enable_shared_from_this<TModel_Entity>
	{


		/*private Data*/

	protected:

		TModel_Entity()
		{}

		TModel_Entity(const Standard_Integer theIndex)
			: Global_Indexed(theIndex)
			, Global_Named("TModel_Entity")
		{}

		TModel_Entity(const Standard_Integer theIndex, const word& theName)
			: Global_Indexed(theIndex)
			, Global_Named(theName)
		{}

	public:

		virtual ~TModel_Entity()
		{}

		std::shared_ptr<const TModel_Entity> This() const
		{
			return shared_from_this();
		}
	};
}

#endif // !_TModel_Entity_Header