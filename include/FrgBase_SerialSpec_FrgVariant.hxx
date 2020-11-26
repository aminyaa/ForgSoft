#pragma once
#ifndef _FrgBase_SerialSpec_FrgVariant_Header
#define _FrgBase_SerialSpec_FrgVariant_Header

#include <FrgBase_Global.hxx>
#include <FrgBase_Serialization_Global.hxx>
#include <FrgBase_SerialSpec_QString.hxx>

namespace ForgBaseLib
{
	template <typename Type, bool IsBounded>
	class FrgBase_PrptsVrntOneValue;
}

namespace boost
{
	namespace serialization
	{
		template<class Archive, typename Type, bool IsBounded>
		inline void serialize(Archive& ar, ForgBaseLib::FrgBase_PrptsVrntOneValue<Type, IsBounded>& t, const unsigned int file_version)
		{
			split_free(ar, t, file_version);
		}

		template<class Archive, typename Type, bool IsBounded>
		inline void save(Archive& ar, const ForgBaseLib::FrgBase_PrptsVrntOneValue<Type, IsBounded>& t, const unsigned int file_version)
		{
			QString displayName = t.GetDisplayName();
			Type value = t.GetValue();
			QString prefix = t.GetPrefix();
			QString suffix = t.GetSuffix();

			ar& displayName;
			ar& value;
			ar& prefix;
			ar& suffix;

			if constexpr (IsBounded)
			{
				double min = t.GetMinimumValue();
				double max = t.GetMaximumValue();
				double step = t.GetStepValue();

				ar& min;
				ar& max;
				ar& step;
			}
		}

		template<class Archive, typename Type, bool IsBounded>
		inline void load(Archive& ar, ForgBaseLib::FrgBase_PrptsVrntOneValue<Type, IsBounded>& t, const unsigned int file_version)
		{
			QString displayName;
			Type value;
			QString prefix;
			QString suffix;

			ar& displayName;
			ar& value;
			ar& prefix;
			ar& suffix;

			t.SetDisplayName(displayName);
			t.SetValue(value);
			t.SetPrefix(prefix);
			t.SetSuffix(suffix);

			if constexpr (IsBounded)
			{
				double min, max, step;

				ar& min;
				ar& max;
				ar& step;

				t.SetMinimumValue(min);
				t.SetMaximumValue(max);
				t.SetStepValue(step);
			}
		}
	}
}

#endif // !_FrgBase_SerialSpec_FrgVariant_Header
