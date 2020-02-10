#pragma once
#ifndef _Marine_Entity_Header
#define _Marine_Entity_Header

#include <Global_Indexed.hxx>
#include <Global_Named.hxx>
#include <Global_AccessMethod.hxx>

#include <memory>

#include <gp_Ax2.hxx>

namespace tnbLib
{

	class Marine_Entity
		: public Global_Indexed
		, public Global_Named
		, public std::enable_shared_from_this<Marine_Entity>
	{

		/*Private Data*/

		gp_Ax2 theCoordinateSystem_;

	protected:

		Marine_Entity()
		{}

		Marine_Entity
		(
			const Standard_Integer theIndex
		)
			: Global_Indexed(theIndex)
		{}

		Marine_Entity
		(
			const Standard_Integer theIndex, 
			const word& theName
		)
			: Global_Indexed(theIndex)
			, Global_Named(theName)
		{}

	public:

		virtual ~Marine_Entity()
		{}

		//- Macros
		GLOBAL_ACCESS_SINGLE(gp_Ax2, CoordinateSystem)
	};
}

#endif // !_Marine_Entity_Header
