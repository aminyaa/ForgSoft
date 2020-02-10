#pragma once
#ifndef _TModel_System_Header
#define _TModel_System_Header

#include <memory>

namespace tnbLib
{

	// Forward Declarations
	class TModel_FixWire_Info;

	namespace sysLib
	{

		extern std::shared_ptr<TModel_FixWire_Info> tmodel_fix_wire_info;

		void init_tmodel_fix_wire_info();
	}
}

#endif // !_TModel_System_Header
