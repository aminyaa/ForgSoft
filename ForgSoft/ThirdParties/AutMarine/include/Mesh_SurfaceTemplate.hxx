#pragma once
#ifndef _Mesh_SurfaceTemplate_Header
#define _Mesh_SurfaceTemplate_Header

#include <Standard_Handle.hxx>

#include <memory>
#include <vector>

namespace AutLib
{

	// Forward Declarations
	class Numeric_AdaptIntegrationInfo;

	template<class SurfEntity>
	class Mesh_SurfPlane;

	template<class SurfEntity>
	class Mesh_SurfaceTemplate
		: public SurfEntity
	{

		typedef Numeric_AdaptIntegrationInfo intgInfo;

		/*Private Data*/

	public:

		typedef typename SurfEntity::wireType wireType;
		typedef std::vector<std::shared_ptr<wireType>> wireList;

		typedef std::shared_ptr<wireList> inner;
		typedef std::shared_ptr<wireType> outer;

		Mesh_SurfaceTemplate(const SurfEntity& theSurface)
			: SurfEntity(theSurface)
		{}


		virtual std::shared_ptr<Mesh_SurfPlane<SurfEntity>>
			GetPlane() const;

		//- Static functions and operators

		static std::shared_ptr<SurfEntity>
			ReParameterization
			(
				const SurfEntity& theSurface,
				const Standard_Real thsScale
			);

		static std::shared_ptr<SurfEntity>
			ReParameterization
			(
				const SurfEntity& theSurface,
				intgInfo& theInfo
			);
	};
}

#include <Mesh_SurfaceTemplateI.hxx>

#endif // !_Mesh_SurfaceTemplate_Header
