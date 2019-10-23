#pragma once
#ifndef _Marine_Vessel_Header
#define _Marine_Vessel_Header

#include <Marine_VesselEntity.hxx>

#include <memory>
#include <map>

namespace AutLib
{

	// Forward Declarations
	class Marine_VesselDisplacer;
	class Marine_VesselSail;
	class Marine_VesselContainer;

	class Marine_Vessel
	{

		typedef std::map<Standard_Integer, std::shared_ptr<Marine_VesselContainer>> containerTree;
		typedef std::map<Standard_Integer, std::shared_ptr<Marine_VesselSail>> sailTree;
		typedef std::map<Standard_Integer, std::shared_ptr<Marine_VesselDisplacer>> displacerTree;

		/*Private Data*/

		containerTree theContainer_;
		sailTree theSial_;
		displacerTree theDisplacer_;

	public:


	};
}

#endif // !_Marine_Vessel_Header
