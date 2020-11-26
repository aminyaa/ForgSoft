#pragma once
#ifndef _CadModel_Sphere_Header
#define _CadModel_Sphere_Header

#include <Pnt3d.hxx>
#include <CadModel_Regular.hxx>

class BRepPrimAPI_MakeSphere;
class gp_Ax2;

namespace tnbLib
{

	// Forward Declarations
	class Pnt3d;

	class CadModel_Sphere
		: public CadModel_Regular
	{

		/*Private Data*/

		std::shared_ptr<BRepPrimAPI_MakeSphere> theMaker_;


		auto& ChangeMaker()
		{
			return theMaker_;
		}

	public:

		CadModel_Sphere
		(
			const Pnt3d& theCentre,
			const Standard_Real theRadius
		);

		CadModel_Sphere
		(
			const gp_Ax2& Axis,
			const Standard_Real theRadius
		);

		CadModel_Sphere
		(
			const gp_Ax2& Axis,
			const Standard_Real theRadius,
			const Standard_Real angle1
		);

		CadModel_Sphere
		(
			const gp_Ax2& Axis,
			const Standard_Real theRadius,
			const Standard_Real angle1,
			const Standard_Real angle2
		);

		CadModel_Sphere
		(
			const gp_Ax2& Axis,
			const Standard_Real theRadius,
			const Standard_Real angle1,
			const Standard_Real angle2,
			const Standard_Real angle3
		);

		const auto& Maker() const
		{
			return theMaker_;
		}

	};
}

#endif // !_CadModel_Sphere_Header
