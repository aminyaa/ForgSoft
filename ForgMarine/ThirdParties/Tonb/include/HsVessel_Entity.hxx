#pragma once
#ifndef _HsVessel_Entity_Header
#define _HsVessel_Entity_Header

#include <Global_Indexed.hxx>
#include <Global_Named.hxx>

#include <memory>

namespace tnbLib
{

	class HsVessel_Entity
		: public Global_Indexed
		, public Global_Named
		, public std::enable_shared_from_this<HsVessel_Entity>
	{

		/*Private Data*/

	protected:

		HsVessel_Entity();

		HsVessel_Entity(const Standard_Integer theIndex);

		HsVessel_Entity(const Standard_Integer theIndex, const word& theName);

	public:

		virtual ~HsVessel_Entity()
		{}
	};
}

#endif // !_HsVessel_Entity_Header
