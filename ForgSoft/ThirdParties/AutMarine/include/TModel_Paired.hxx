#pragma once
#ifndef _TModel_Paired_Header
#define _TModel_Paired_Header

#include <Global_AccessMethod.hxx>
#include <TModel_Entity.hxx>
#include <Entity3d_PolygonFwd.hxx>
#include <OFstream.hxx>

namespace AutLib
{

	// Forward Declarations
	class TModel_Edge;

	class TModel_Paired
		: public TModel_Entity
	{

		/*Private Data*/

		std::shared_ptr<TModel_Edge> theEdge0_;
		std::shared_ptr<TModel_Edge> theEdge1_;


		std::shared_ptr<Entity3d_Polygon> theMesh_;

	public:

		TModel_Paired
		(
			const std::shared_ptr<TModel_Edge>& theEdge0, 
			const std::shared_ptr<TModel_Edge>& theEdge1
		)
			: theEdge0_(theEdge0)
			, theEdge1_(theEdge1)
		{}

		TModel_Paired
		(
			const Standard_Integer theIndex,
			const std::shared_ptr<TModel_Edge>& theEdge0,
			const std::shared_ptr<TModel_Edge>& theEdge1
		)
			: theEdge0_(theEdge0)
			, theEdge1_(theEdge1)
			, TModel_Entity(theIndex)
		{}

		TModel_Paired
		(
			const Standard_Integer theIndex,
			const word& theName,
			const std::shared_ptr<TModel_Edge>& theEdge0,
			const std::shared_ptr<TModel_Edge>& theEdge1
		)
			: theEdge0_(theEdge0)
			, theEdge1_(theEdge1)
			, TModel_Entity(theIndex, theName)
		{}


		const std::shared_ptr<TModel_Edge>& Edge0() const
		{
			return theEdge0_;
		}

		const std::shared_ptr<TModel_Edge>& Edge1() const
		{
			return theEdge1_;
		}

		const std::shared_ptr<TModel_Edge>& Other
		(
			const std::shared_ptr<TModel_Edge>& theEdge
		) const;

		Standard_Boolean IsPaired() const
		{
			return theEdge0_ && theEdge1_;
		}


		//- Io functions and operators

		void ExportToPlt(OFstream& File) const;


		//- Macros

		GLOBAL_ACCESS_SINGLE(std::shared_ptr<Entity3d_Polygon>, Mesh)
	};
}

#endif // !_TModel_Paired_Header
