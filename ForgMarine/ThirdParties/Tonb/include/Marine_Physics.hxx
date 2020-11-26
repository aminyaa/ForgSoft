#pragma once
#ifndef _Marine_Physics_Header
#define _Marine_Physics_Header

#include <Global_Indexed.hxx>
#include <Global_Named.hxx>

#include <memory>

namespace tnbLib
{

	class Marine_Physics
		: public Global_Indexed
		, public Global_Named
		, public std::enable_shared_from_this<Marine_Physics>
	{

		/*Private Data*/

	protected:

		Marine_Physics();

		Marine_Physics(const Standard_Integer theIndex);

		Marine_Physics(const Standard_Integer theIndex, const word& theName);

	public:

		virtual ~Marine_Physics()
		{}
	};
}

#endif // !_Marine_Physics_Header
