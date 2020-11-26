#pragma once
#ifndef _Marine_ModelMaker_Header
#define _Marine_ModelMaker_Header

#include <Marine_Entity.hxx>
#include <Global_Done.hxx>
#include <Global_Macros.hxx>

#include <gp_Ax2.hxx>

namespace tnbLib
{

	// Forward Declarations
	class Marine_Model;
	
	class Marine_ModelMaker
		: /*public Marine_Entity
		, */public Global_Done
	{

		/*Private Data*/

		Standard_Real theMinTolerance_;
		Standard_Real theMaxTolerance_;

		std::shared_ptr<Marine_Model> theModel_;

		gp_Ax2 theSystem_;

	protected:

		Marine_ModelMaker();

		Marine_ModelMaker(const Standard_Integer theIndex, const word& theName);

		auto& ChangeModel()
		{
			return theModel_;
		}

	public:

		const auto& Model() const
		{
			return theModel_;
		}

		//- Macros
		GLOBAL_ACCESS_ONLY_SINGLE(gp_Ax2, System)

			GLOBAL_ACCESS_PRIM_SINGLE(Standard_Real, MinTolerance)
			GLOBAL_ACCESS_PRIM_SINGLE(Standard_Real, MaxTolerance)
	};
}

#endif // !_Marine_ModelMaker_Header
