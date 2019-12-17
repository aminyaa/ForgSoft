#pragma once
#ifndef _CadAnalys_Model_System_Header
#define _CadAnalys_Model_System_Header

#include <memory>

namespace AutLib
{

	// Forward Declarations
	class CadAnalys_Model_Info;

	namespace cadAnalysSys
	{

		extern std::shared_ptr<CadAnalys_Model_Info> gl_model_analysis_info;

		void init_model_analysis_info();
	}
}

#endif // !_CadAnalys_Model_System_Header
