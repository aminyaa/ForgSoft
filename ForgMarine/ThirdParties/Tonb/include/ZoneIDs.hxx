#pragma once
#ifndef _ZoneIDs_Header
#define _ZoneIDs_Header

#include <ZoneID.hxx>
#include <pointZone.hxx>
#include <faceZone.hxx>
#include <cellZone.hxx>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace tnbLib
{
	//- tnbLib::pointZoneID
	typedef ZoneID<pointZone> pointZoneID;

	//- tnbLib::faceZoneID
	typedef ZoneID<faceZone> faceZoneID;

	//- tnbLib::cellZoneID
	typedef ZoneID<cellZone> cellZoneID;
}

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif // !_ZoneIDs_Header
