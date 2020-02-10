#pragma once
#ifndef _faceZoneMeshFwd_Header
#define _faceZoneMeshFwd_Header

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace tnbLib
{
	template<class Zone, class MeshType> class ZoneMesh;
	class faceZone;
	class polyMesh;

	typedef ZoneMesh<faceZone, polyMesh> faceZoneMesh;
}

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif // !_faceZoneMeshFwd_Header
