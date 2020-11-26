#pragma once
#ifndef _GModel_Entity_Header
#define _GModel_Entity_Header

#include <Global_Indexed.hxx>
#include <Global_Named.hxx>

#include <memory>

namespace tnbLib
{

	class GModel_Entity
		: public Global_Indexed
		, public Global_Named
		, public std::enable_shared_from_this<GModel_Entity>
	{

		/*Private Data*/

	protected:

		GModel_Entity();

		GModel_Entity(const Standard_Integer theIndex);

		GModel_Entity(const Standard_Integer theIndex, const word& theName);

	public:

		virtual ~GModel_Entity()
		{}

		std::shared_ptr<const GModel_Entity> This() const
		{
			return shared_from_this();
		}
	};
}

#endif // !_GModel_Entity_Header
