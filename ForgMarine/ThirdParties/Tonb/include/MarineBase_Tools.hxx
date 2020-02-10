#pragma once
#ifndef _MarineBase_Tools_Header
#define _MarineBase_Tools_Header

#include <Standard_TypeDef.hxx>

#include <memory>

class gp_Pln;

namespace tnbLib
{

	// Forward Declarations
	class Marine_CmpSection;
	class Cad3d_TModel;

	class MarineBase_Tools
	{

	public:

		static std::shared_ptr<Marine_CmpSection>
			CreateSection
			(
				const Cad3d_TModel& theModel, 
				const gp_Pln& thePlane,
				const Standard_Boolean ParallelFalg = Standard_False
			);


	};
}

#endif // !_MarineBase_Tools_Header
