#pragma once
#ifndef _Geo_UniDistb_Header
#define _Geo_UniDistb_Header

#include <Geo_xDistb.hxx>

namespace tnbLib
{

	class Geo_UniDistb
		: public Geo_xDistb
	{

		/*Private Data*/

		Standard_Integer theSize_;

		std::vector<Standard_Real> theValues_;


		auto& ChangeValues()
		{
			return theValues_;
		}

	public:

		Geo_UniDistb(const Standard_Integer theSize)
			: theSize_(theSize)
		{}

		Standard_Integer Size() const override
		{
			return theSize_;
		}

		Standard_Real Value
		(
			const Standard_Integer theIndex
		) const override;

		const std::vector<Standard_Real>&
			Values() const override
		{
			return theValues_;
		}

		void Perform() override;


	};
}

#endif // !_Geo_UniDistb_Header
