#pragma once
#ifndef _pointZoneMeshFwd_Header
#define _pointZoneMeshFwd_Header

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace tnbLib
{
	template<class Zone, class MeshType> class ZoneMesh;
	class pointZone;
	class polyMesh;

	typedef ZoneMesh<pointZone, polyMesh> pointZoneMesh;
}

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif // !_pointZoneMeshFwd_Header
