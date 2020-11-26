#pragma once
#ifndef _CadModel_Cylinder_Header
#define _CadModel_Cylinder_Header

#include <CadModel_Regular.hxx>

class BRepPrimAPI_MakeCylinder;
class gp_Ax2;

namespace tnbLib
{

	class CadModel_Cylinder
		: public CadModel_Regular
	{

		/*Private Data*/

		std::shared_ptr<BRepPrimAPI_MakeCylinder> theMaker_;


		auto& ChangeMaker()
		{
			return theMaker_;
		}

	public:

		CadModel_Cylinder
		(
			const gp_Ax2& Axes,
			const Standard_Real R,
			const Standard_Real H
		);

		CadModel_Cylinder
		(
			const gp_Ax2& Axes,
			const Standard_Real R,
			const Standard_Real H,
			const Standard_Real Angle
		);


		const auto& Maker() const
		{
			return theMaker_;
		}

	};
}

#endif // !_CadModel_Cylinder_Header
