#pragma once
#ifndef _GeoSizeFun_BackGround_Header
#define _GeoSizeFun_BackGround_Header

#include <Geo_SizeFunction.hxx>
#include <error.hxx>
#include <OSstream.hxx>

#include <memory>

namespace AutLib
{


	template<class GeoBackMesh>
	class GeoSizeFun_BackGround
		: public Geo_SizeFunction<typename GeoBackMesh::ptType>
	{

		/*Private Data*/

		std::shared_ptr<GeoBackMesh> theMesh_;

	public:

		GeoSizeFun_BackGround
		(
			const std::shared_ptr<GeoBackMesh>& theMesh
		)
			: theMesh_(theMesh)
		{}

		GeoSizeFun_BackGround
		(
			const Standard_Integer theIndex,
			const word& theName,
			const std::shared_ptr<GeoBackMesh>& theMesh
		)
			: Geo_SizeFunction<typename GeoBackMesh::ptType>(theIndex, theName)
			, theMesh_(theMesh)
		{}


		const std::shared_ptr<GeoBackMesh>& Mesh() const
		{
			return theMesh_;
		}

		//- override functions

		Standard_Real Value(const typename GeoBackMesh::ptType& theCoord) const
		{
			Debug_Null_Pointer(theMesh_);
			return theMesh_->InterpolateAt(theCoord);
		}
	};
}

#endif // !_GeoSizeFun_BackGround_Header
