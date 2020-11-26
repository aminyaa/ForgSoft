#pragma once
#ifndef _cellZoneMeshFwd_Header
#define _cellZoneMeshFwd_Header

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace tnbLib
{
	template<class Zone, class MeshType> class ZoneMesh;
	class cellZone;
	class polyMesh;

	typedef ZoneMesh<cellZone, polyMesh> cellZoneMesh;
}

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif // !_cellZoneMeshFwd_Header
