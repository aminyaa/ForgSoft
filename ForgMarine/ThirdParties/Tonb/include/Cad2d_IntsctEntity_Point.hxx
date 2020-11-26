#pragma once
#ifndef _Cad2d_IntsctEntity_Point_Header
#define _Cad2d_IntsctEntity_Point_Header

#include <Cad2d_IntsctEntity.hxx>

namespace tnbLib
{

	// Forward Declarations
	class Pln_Vertex;

	class Cad2d_IntsctEntity_Point
		: public Cad2d_IntsctEntity
	{

		/*Private Data*/

		std::shared_ptr<Pln_Vertex> theVertex_;

	public:

		Cad2d_IntsctEntity_Point();

		Cad2d_IntsctEntity_Point(const Standard_Integer theIndex);

		Cad2d_IntsctEntity_Point(const Standard_Integer theIndex, const word& theName);

		const auto& ParentVertex() const
		{
			return theVertex_;
		}

		Standard_Boolean IsPoint() const override
		{
			return Standard_True;
		}

		void SetParentVertex(const std::shared_ptr<Pln_Vertex>& theVtx)
		{
			theVertex_ = theVtx;
		}

		//- Macros
		//GLOBAL_ACCESS_ONLY_SINGLE(std::shared_ptr<Pln_Vertex>, Vertex)

	};
}

#endif // !_Cad2d_IntsctEntity_Point_Header
