#pragma once
#ifndef _HsEntity_Vessel_Header
#define _HsEntity_Vessel_Header

#include <Global_Indexed.hxx>
#include <Global_Named.hxx>

#include <memory>

#include <gp_Ax2.hxx>

namespace tnbLib
{

	class HsEntity_Vessel
		: public Global_Indexed
		, public Global_Named
		, public std::enable_shared_from_this<HsEntity_Vessel>
	{

		/*Private Data*/

		const gp_Ax2& theSystem_;

	protected:

		HsEntity_Vessel();

		HsEntity_Vessel(const Standard_Integer theIndex);

		HsEntity_Vessel(const Standard_Integer theIndex, const word& theName);

	public:

		virtual ~HsEntity_Vessel()
		{}


		const auto& System() const
		{
			return theSystem_;
		}
	};
}

#endif // !_HsEntity_Vessel_Header
