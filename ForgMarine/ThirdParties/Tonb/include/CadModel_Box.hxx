#pragma once
#ifndef _CadModel_Box_Header
#define _CadModel_Box_Header

#include <CadModel_Regular.hxx>

class BRepPrimAPI_MakeBox;

namespace tnbLib
{

	// Forward Declarations
	class Pnt3d;

	class CadModel_Box
		: public CadModel_Regular
	{

		/*Private Data*/

		std::shared_ptr<BRepPrimAPI_MakeBox> theMaker_;


		auto& ChangeMaker()
		{
			return theMaker_;
		}

	public:

		CadModel_Box
		(
			const Pnt3d& theP0,
			const Pnt3d& theP1
		);

		CadModel_Box
		(
			const Pnt3d& theP0,
			const Standard_Real dx,
			const Standard_Real dy,
			const Standard_Real dz
		);

		CadModel_Box
		(
			const gp_Ax2& Axes,
			const Standard_Real dx,
			const Standard_Real dy,
			const Standard_Real dz
		);

		const auto& Maker() const
		{
			return theMaker_;
		}

	};
}

#endif // !_CadModel_Box_Header
