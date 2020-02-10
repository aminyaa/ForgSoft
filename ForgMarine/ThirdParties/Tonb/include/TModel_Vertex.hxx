#pragma once
#ifndef _TModel_Vertex_Header
#define _TModel_Vertex_Header

#include <Cad_EntityPrecision.hxx>
#include <Global_AccessMethod.hxx>
#include <TModel_Entity.hxx>
#include <TModel_VertexAdaptor.hxx>
#include <Pnt3d.hxx>

namespace tnbLib
{

	class TModel_Vertex
		: public TModel_Entity
		, public TModel_VertexAdaptor
	{

		/*Private Data*/

		Pnt3d theCoord_;

	public:

		TModel_Vertex
		(
			const Standard_Integer theIndex
		)
			: TModel_Entity(theIndex)
		{}

		TModel_Vertex
		(
			const Standard_Integer theIndex,
			const Pnt3d& theCoord
		)
			: TModel_Entity(theIndex)
			, theCoord_(theCoord)
		{}

		TModel_Vertex
		(
			const Standard_Integer theIndex,
			const word& theName,
			const Pnt3d& theCoord
		)
			: TModel_Entity(theIndex, theName)
			, theCoord_(theCoord)
		{}

		Standard_Integer NbRings() const;

		Standard_Boolean IsOrphan() const;

		//- Macros
		GLOBAL_ACCESS_SINGLE(Pnt3d, Coord)
	};
}

#endif // !_TModel_Vertex_Header
