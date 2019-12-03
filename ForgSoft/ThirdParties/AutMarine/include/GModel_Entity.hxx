#pragma once
#ifndef _GModel_Entity_Header
#define _GModel_Entity_Header

#include <Global_Indexed.hxx>
#include <Global_Named.hxx>

#include <memory>

namespace AutLib
{

	class GModel_Entity
		: public Global_Named
		, public Global_Indexed
		, public std::enable_shared_from_this<GModel_Entity>
	{

		/*Private Data*/

	protected:

		GModel_Entity()
		{}

		GModel_Entity(const Standard_Integer theIndex)
			: Global_Indexed(theIndex)
		{}

		GModel_Entity(const Standard_Integer theIndex, const word& theName)
			: Global_Indexed(theIndex)
			, Global_Named(theName)
		{}

	public:

		
		virtual ~GModel_Entity()
		{}

	};
}

#endif // !_GModel_Entity_Header
