#pragma once
#ifndef _CadCascade_Cylinder_Header
#define _CadCascade_Cylinder_Header

#include <CadCascade_Regular.hxx>

class BRepPrimAPI_MakeCylinder;

namespace AutLib
{

	// Forward Declarations
	

	class CadCascade_Cylinder
		: public CadCascade_Regular
	{

		/*Private Data*/

		std::shared_ptr<BRepPrimAPI_MakeCylinder> theMaker_;


		std::shared_ptr<BRepPrimAPI_MakeCylinder>& ChangeMaker()
		{
			return theMaker_;
		}

	public:

		CadCascade_Cylinder
		(
			const gp_Ax2& Axes, 
			const Standard_Real R,
			const Standard_Real H
		);

		CadCascade_Cylinder
		(
			const gp_Ax2& Axes,
			const Standard_Real R,
			const Standard_Real H, 
			const Standard_Real Angle
		);


		const std::shared_ptr<BRepPrimAPI_MakeCylinder>& Maker() const
		{
			return theMaker_;
		}
	};
}

#endif // !_CadCascade_Cylinder_Header
