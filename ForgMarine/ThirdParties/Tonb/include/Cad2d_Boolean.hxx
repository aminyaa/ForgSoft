#pragma once
#ifndef _Cad2d_Boolean_Header
#define _Cad2d_Boolean_Header

#include <Standard_TypeDef.hxx>

#include <memory>
#include <vector>

namespace tnbLib
{

	// Forward Declarations
	class Cad2d_Plane;
	class Pnt2d;

	class Cad2d_Boolean
	{

	public:

		static Standard_Real Tolerance;

		static std::shared_ptr<Cad2d_Plane> 
			Union
			(
				const std::shared_ptr<Cad2d_Plane>& thePlane0, 
				const std::shared_ptr<Cad2d_Plane>& thePlane1
			);

		static std::shared_ptr<Cad2d_Plane>
			Subtract
			(
				const std::shared_ptr<Cad2d_Plane>& thePlane0,
				const std::shared_ptr<Cad2d_Plane>& thePlane1
			);

		static std::vector<std::shared_ptr<Cad2d_Plane>>
			Intersection
			(
				const std::shared_ptr<Cad2d_Plane>& thePlane0,
				const std::shared_ptr<Cad2d_Plane>& thePlane1
			);
	};
}

#endif // !_Cad2d_Boolean_Header
