#pragma once
#ifndef _TModel_VertexAdaptor_Header
#define _TModel_VertexAdaptor_Header

#include <Standard_TypeDef.hxx>

#include <memory>
#include <map>

namespace tnbLib
{

	// Forward Declarations
	class TModel_Edge;
	class TModel_Surface;

	class TModel_VertexAdaptor
	{

		typedef std::map<Standard_Integer, std::weak_ptr<TModel_Edge>>
			edgeRegister;
		typedef std::map<Standard_Integer, std::weak_ptr<TModel_Surface>>
			faceRegister;

		/*Private Data*/

		edgeRegister theEdges_;
		faceRegister theFaces_;

	protected:

		TModel_VertexAdaptor()
		{}

	public:

		Standard_Integer NbEdges() const
		{
			return (Standard_Integer)theEdges_.size();
		}

		Standard_Integer NbFaces() const
		{
			return (Standard_Integer)theFaces_.size();
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
	};
}

#endif // !_TModel_VertexAdaptor_Header
