#pragma once
#ifndef _TModel_Edge_Header
#define _TModel_Edge_Header

#include <Cad_EntityPrecision.hxx>
#include <TModel_Entity.hxx>
#include <TModel_EdgeAdaptor.hxx>
#include <TModel_EdgeGeometry.hxx>

namespace tnbLib
{

	// Forward Declarations
	class TModel_Vertex;
	class TModel_Curve;
	class TModel_ParaCurve;
	class TModel_Paired;
	class TModel_Surface;
	class TModel_Wire;

	class TModel_Edge
		: public TModel_Entity
		, public TModel_EdgeAdaptor
		, public TModel_EdgeGeometry
		, public Cad_EntityPrecision
	{

		/*Private Data*/

		std::shared_ptr<TModel_Vertex> theVtx0_;
		std::shared_ptr<TModel_Vertex> theVtx1_;

	public:

		TModel_Edge
		(
			const std::shared_ptr<TModel_Vertex>& theVtx0,
			const std::shared_ptr<TModel_Vertex>& theVtx1, 
			const std::shared_ptr<TModel_Curve>& theCurve, 
			const std::shared_ptr<TModel_ParaCurve>& theParaCurve,
			const Standard_Boolean theSense = Standard_True
		);

		TModel_Edge
		(
			const std::shared_ptr<TModel_Curve>& theCurve,
			const std::shared_ptr<TModel_ParaCurve>& theParaCurve,
			const Standard_Boolean theSense = Standard_True
		);

		TModel_Edge
		(
			const Standard_Integer theIndex,
			const std::shared_ptr<TModel_Vertex>& theVtx0,
			const std::shared_ptr<TModel_Vertex>& theVtx1,
			const std::shared_ptr<TModel_Curve>& theCurve,
			const std::shared_ptr<TModel_ParaCurve>& theParaCurve,
			const Standard_Boolean theSense = Standard_True
		);

		TModel_Edge
		(
			const Standard_Integer theIndex,
			const std::shared_ptr<TModel_Curve>& theCurve,
			const std::shared_ptr<TModel_ParaCurve>& theParaCurve,
			const Standard_Boolean theSense = Standard_True
		);

		TModel_Edge
		(
			const Standard_Integer theIndex,
			const word& theName,
			const std::shared_ptr<TModel_Vertex>& theVtx0,
			const std::shared_ptr<TModel_Vertex>& theVtx1,
			const std::shared_ptr<TModel_Curve>& theCurve,
			const std::shared_ptr<TModel_ParaCurve>& theParaCurve,
			const Standard_Boolean theSense = Standard_True
		);

		TModel_Edge
		(
			const Standard_Integer theIndex,
			const word& theName,
			const std::shared_ptr<TModel_Curve>& theCurve,
			const std::shared_ptr<TModel_ParaCurve>& theParaCurve,
			const Standard_Boolean theSense = Standard_True
		);


		//- virtual functions and operators

		virtual Standard_Boolean IsDegenerated() const
		{
			return Standard_False;
		}

		virtual Standard_Boolean IsRing() const
		{
			return Standard_False;
		}


		//- Static functions and operators

		static Standard_Boolean
			IsLess
			(
				const std::shared_ptr<TModel_Edge>& theEdge0,
				const std::shared_ptr<TModel_Edge>& theEdge1
			)
		{
			Debug_Null_Pointer(theEdge0);
			Debug_Null_Pointer(theEdge1);

			return theEdge0->Index() < theEdge1->Index();
		}

		//- Macros
		GLOBAL_ACCESS_SINGLE(std::shared_ptr<TModel_Vertex>, Vtx0)
			GLOBAL_ACCESS_SINGLE(std::shared_ptr<TModel_Vertex>, Vtx1)
	};
}

#endif // !_TModel_Edge_Header
