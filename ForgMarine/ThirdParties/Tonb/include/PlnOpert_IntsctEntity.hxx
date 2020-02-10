#pragma once
#ifndef _PlnOpert_IntsctEntity_Header
#define _PlnOpert_IntsctEntity_Header

#include <Global_Indexed.hxx>
#include <PlnOpert_IntsctEntityAdaptor.hxx>
#include <error.hxx>
#include <OSstream.hxx>

#include <memory>
#include <vector>
#include <list>

namespace tnbLib
{

	// Forward Declarations
	class Pln_Curve;
	class Pln_Edge;
	class Pln_Vertex;

	class PlnOpert_IntsctEntity
		: public PlnOpert_IntsctEntityAdaptor
		, public Global_Indexed
		, public std::enable_shared_from_this<PlnOpert_IntsctEntity>
	{

		/*Private Data*/

		std::shared_ptr<Pln_Curve> theParentCurve_;
		std::shared_ptr<Pln_Edge> theParentEdge_;

		std::list<std::shared_ptr<Pln_Vertex>> theVertices_;

	protected:

		PlnOpert_IntsctEntity(const Standard_Integer theIndex)
			: Global_Indexed(theIndex)
		{}

		PlnOpert_IntsctEntity
		(
			const Standard_Integer theIndex,
			const std::shared_ptr<Pln_Curve>& theCurve
		)
			: Global_Indexed(theIndex)
			, theParentCurve_(theCurve)
		{}

	public:

		auto This() const
		{
			return std::const_pointer_cast<PlnOpert_IntsctEntity>(shared_from_this());
		}

		const std::list<std::shared_ptr<Pln_Vertex>>& Vertices() const
		{
			return theVertices_;
		}

		std::list<std::shared_ptr<Pln_Vertex>>& Vertices()
		{
			return theVertices_;
		}

		void PushToVertices
		(
			const std::shared_ptr<Pln_Vertex>& theVertex
		)
		{
			theVertices_.push_back(theVertex);
		}

		//- virtual functions

		virtual Standard_Boolean IsPoint() const
		{
			return Standard_False;
		}

		virtual Standard_Boolean IsSegment() const
		{
			return Standard_False;
		}

		virtual Standard_Real CharParameter() const = 0;


		//- static functions

		static Standard_Boolean IsLess
		(
			const std::shared_ptr<PlnOpert_IntsctEntity>& theE0,
			const std::shared_ptr<PlnOpert_IntsctEntity>& theE1
		)
		{
			Debug_Null_Pointer(theE0);
			Debug_Null_Pointer(theE1);
			return theE0->CharParameter() < theE1->CharParameter();
		}

		//- Macros
		GLOBAL_ACCESS_SINGLE(std::shared_ptr<Pln_Curve>, ParentCurve)
			GLOBAL_ACCESS_SINGLE(std::shared_ptr<Pln_Edge>, ParentEdge)
			
	};
}

#endif // !_PlnOpert_IntsctEntity_Header
