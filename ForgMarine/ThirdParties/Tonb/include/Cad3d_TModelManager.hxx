#pragma once
#ifndef _Cad3d_TModelManager_Header
#define _Cad3d_TModelManager_Header

#include <TModel_VertexManager.hxx>
#include <TModel_PairedManager.hxx>
#include <TModel_SurfaceManager.hxx>

namespace tnbLib
{

	class Cad3d_TModelManager
	{

		/*Private Data*/

		std::shared_ptr<TModel_VertexManager> theVertices_;
		std::shared_ptr<TModel_PairedManager> theEdges_;
		std::shared_ptr<TModel_SurfaceManager> theSurfaces_;


	protected:

		Cad3d_TModelManager()
		{}

		auto& ChangeCorners()
		{
			return theVertices_;
		}

		auto& ChangeSegments()
		{
			return theEdges_;
		}

		auto& ChangeFaces()
		{
			return theSurfaces_;
		}

	public:

		Standard_Integer NbCorners() const;

		Standard_Integer NbSegments() const;

		Standard_Integer NbFaces() const;

		const auto& Corners() const
		{
			return theVertices_;
		}

		const auto& Segments() const
		{
			return theEdges_;
		}

		const auto& Faces() const
		{
			return theSurfaces_;
		}

		std::vector<std::shared_ptr<TModel_Vertex>>
			RetrieveCorners() const;

		std::vector<std::shared_ptr<TModel_Paired>>
			RetrieveSegments() const;

		std::vector<std::shared_ptr<TModel_Surface>>
			RetrieveFaces() const;

		void RetrieveCornersTo
		(
			std::vector<std::shared_ptr<TModel_Vertex>>& theVertices
		) const;

		void RetrieveSegmentsTo
		(
			std::vector<std::shared_ptr<TModel_Paired>>& theEdges
		) const;

		void RetrieveFacesTo
		(
			std::vector<std::shared_ptr<TModel_Surface>>& theSurfaces
		) const;
	};
}

#endif // !_Cad3d_TModelManager_Header
