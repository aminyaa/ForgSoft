#pragma once
#ifndef _Geo_xDistb_Header
#define _Geo_xDistb_Header

#include <Global_Done.hxx>
#include <Global_AccessMethod.hxx>
#include <Global_Bound.hxx>

#include <vector>

namespace tnbLib
{

	class Geo_xDistb
		: public Global_Done
		, public Global_Bound<Standard_Real>
	{

		/*Private Data*/

	protected:

		Geo_xDistb()
		{}

	public:

		virtual Standard_Integer Size() const = 0;

		virtual Standard_Real
			Value
			(
				const Standard_Integer theIndex
			) const = 0;

		virtual const std::vector<Standard_Real>&
			Values() const = 0;

		virtual void Perform() = 0;
	};
}

#endif // !_Geo_xDistb_Header
