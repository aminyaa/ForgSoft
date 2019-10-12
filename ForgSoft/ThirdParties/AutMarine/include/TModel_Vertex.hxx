#pragma once
#ifndef _TModel_Vertex_Header
#define _TModel_Vertex_Header

#include <Global_AccessMethod.hxx>
#include <TModel_Entity.hxx>
#include <Cad_EntityPrecision.hxx>
#include <Pnt3d.hxx>

#include <memory>
#include <map>

namespace AutLib
{

	// Forward Declarations
	class TModel_Edge;
	class TModel_Surface;

	class TModel_Vertex
		: public TModel_Entity
		, public Cad_EntityPrecision
	{

		typedef std::map<Standard_Integer, std::weak_ptr<TModel_Edge>>
			edgeRegister;
		typedef std::map<Standard_Integer, std::weak_ptr<TModel_Surface>>
			faceRegister;

		/*Private Data*/

		Pnt3d theCoord_;

		edgeRegister theEdges_;
		faceRegister theFaces_;

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


		Standard_Integer NbEdges() const
		{
			return (Standard_Integer)theEdges_.size();
		}

		Standard_Integer NbFaces() const
		{
			return (Standard_Integer)theFaces_.size();
		}

		Standard_Integer NbRings() const;

		Standard_Boolean IsOrphan() const
		{
			return (Standard_Boolean)theEdges_.empty();
		}

		const edgeRegister& Edges() const
		{
			return theEdges_;
		}

		const faceRegister& Faces() const
		{
			return theFaces_;
		}

		void ImportToEdges
		(
			const Standard_Integer theIndex,
			const std::weak_ptr<TModel_Edge>& theEdge
		)
		{
			theEdges_.insert(std::make_pair(theIndex, theEdge));
		}

		void ImportToSurfaces
		(
			const Standard_Integer theIndex, 
			const std::weak_ptr<TModel_Surface>& theFace
		)
		{
			theFaces_.insert(std::make_pair(theIndex, theFace));
		}

		void ImportToSurfaces_dup
		(
			const Standard_Integer theIndex,
			const std::weak_ptr<TModel_Surface>& theFace
		);

		void RemoveFromEdges(const Standard_Integer theIndex);

		void RemoveFromFaces(const Standard_Integer theIndex);

		//- Macros

		GLOBAL_ACCESS_SINGLE(Pnt3d, Coord)
	};
}

#endif // !_TModel_Vertex_Header
