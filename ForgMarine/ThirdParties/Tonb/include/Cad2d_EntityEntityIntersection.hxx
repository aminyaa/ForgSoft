#pragma once
#ifndef _Cad2d_EntityEntityIntersection_Header
#define _Cad2d_EntityEntityIntersection_Header

#include <Global_Indexed.hxx>
#include <Global_Named.hxx>
#include <Global_Done.hxx>
#include <Global_AccessMethod.hxx>

#include <memory>
#include <vector>

namespace tnbLib
{

	// Forward Declarations
	class Cad2d_IntsctEntity;
	class Cad2d_IntsctEntity_Pair;

	class Cad2d_EntityEntityIntersection
		: public Global_Indexed
		, public Global_Named
		, public Global_Done
		, public std::enable_shared_from_this<Cad2d_EntityEntityIntersection>
	{

		/*Private Data*/

		std::vector<std::shared_ptr<Cad2d_IntsctEntity_Pair>>
			theEntities_;

		Standard_Real theTolerance_;

	protected:

		Cad2d_EntityEntityIntersection();

		Cad2d_EntityEntityIntersection(const Standard_Integer theIndex);

		Cad2d_EntityEntityIntersection(const Standard_Integer theIndex, const word& theName);


		auto& ChangeEntities()
		{
			return theEntities_;
		}

	public:

		static const Standard_Real DEFAULT_TOLERANCE;

		virtual ~Cad2d_EntityEntityIntersection()
		{}


		auto NbEntities() const
		{
			return (Standard_Integer)theEntities_.size();
		}

		const auto& Entities() const
		{
			return theEntities_;
		}

		virtual Standard_Boolean IsEdgeEdge() const
		{
			return Standard_False;
		}

		virtual Standard_Boolean IsVertexEdge() const
		{
			return Standard_False;
		}

		//- Macros
		GLOBAL_ACCESS_SINGLE(Standard_Real, Tolerance)
	};
}

#endif // !_Cad2d_EntityEntityIntersection_Header
