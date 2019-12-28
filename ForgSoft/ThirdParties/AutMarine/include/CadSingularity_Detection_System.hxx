#pragma once
#ifndef _CadSingularity_Detection_System_Header
#define _CadSingularity_Detection_System_Header

#include <memory>

namespace AutLib
{

	// Forward Declarations
	class CadSingularity_Detection_Info;

	namespace cadSingularSys
	{

		extern std::shared_ptr<CadSingularity_Detection_Info> gl_singularity_detection_info;
	}
}

#endif // !_CadSingularity_Detection_System_Header
