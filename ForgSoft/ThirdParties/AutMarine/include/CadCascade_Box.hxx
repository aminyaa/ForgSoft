#pragma once
#ifndef _CadCascade_Box_Header
#define _CadCascade_Box_Header

#include <CadCascade_Regular.hxx>

class BRepPrimAPI_MakeBox;

namespace AutLib
{

	// Forward Declarations
	

	class CadCascade_Box
		: public CadCascade_Regular
	{

		/*Private Data*/

		std::shared_ptr<BRepPrimAPI_MakeBox> theMaker_;


		std::shared_ptr<BRepPrimAPI_MakeBox>& ChangeMaker()
		{
			return theMaker_;
		}

	public:

		CadCascade_Box
		(
			const Pnt3d& theP0, 
			const Pnt3d& theP1
		);

		CadCascade_Box
		(
			const Pnt3d& theP0,
			const Standard_Real dx,
			const Standard_Real dy, 
			const Standard_Real dz
		);

		CadCascade_Box
		(
			const gp_Ax2& Axes,
			const Standard_Real dx,
			const Standard_Real dy,
			const Standard_Real dz
		);

		const std::shared_ptr<BRepPrimAPI_MakeBox>& Maker() const
		{
			return theMaker_;
		}
	};
}

#endif // !_CadCascade_Box_Header
