#pragma once
#ifndef _Marine_CompoundSectionFwd_Header
#define _Marine_CompoundSectionFwd_Header

namespace AutLib
{

	// Forward Declarations
	template<class SectType>
	class Marine_CompoundSection;

	class Marine_TableCurve;
	class Marine_TableOffsets;

	namespace marineLib
	{

		typedef Marine_CompoundSection<Marine_TableCurve> cmpSectCurve;
		typedef Marine_CompoundSection<Marine_TableOffsets> cmpSectOffsets;
	}
}

#endif // !_Marine_CompoundSectionFwd_Header
