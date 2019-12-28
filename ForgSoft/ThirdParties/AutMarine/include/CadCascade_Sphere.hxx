#pragma once
#ifndef _CadCascade_Sphere_Header
#define _CadCascade_Sphere_Header

#include <CadCascade_Regular.hxx>

class BRepPrimAPI_MakeSphere;

namespace AutLib
{

	class CadCascade_Sphere
		: public CadCascade_Regular
	{

		/*Private Data*/

		std::shared_ptr<BRepPrimAPI_MakeSphere> theMaker_;


		std::shared_ptr<BRepPrimAPI_MakeSphere>& ChangeMaker()
		{
			return theMaker_;
		}

	public:

		CadCascade_Sphere
		(
			const Pnt3d& theCentre, 
			const Standard_Real theRadius
		);

		CadCascade_Sphere
		(
			const gp_Ax2& Axis, 
			const Standard_Real theRadius
		);

		CadCascade_Sphere
		(
			const gp_Ax2& Axis, 
			const Standard_Real theRadius, 
			const Standard_Real angle1
		);

		CadCascade_Sphere
		(
			const gp_Ax2& Axis,
			const Standard_Real theRadius,
			const Standard_Real angle1,
			const Standard_Real angle2
		);

		CadCascade_Sphere
		(
			const gp_Ax2& Axis,
			const Standard_Real theRadius, 
			const Standard_Real angle1,
			const Standard_Real angle2, 
			const Standard_Real angle3
		);

		const std::shared_ptr<BRepPrimAPI_MakeSphere>& Maker() const
		{
			return theMaker_;
		}
	};
}

#endif // !_CadCascade_Sphere_Header
