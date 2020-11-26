#pragma once
#ifndef _Cad_GeoSketch_Header
#define _Cad_GeoSketch_Header

#include <Global_Indexed.hxx>
#include <Global_Named.hxx>

#include <memory>

namespace tnbLib
{

	class Cad_GeoSketch
		: public Global_Indexed
		, public Global_Named
		, public std::enable_shared_from_this<Cad_GeoSketch>
	{

		/*Private Data*/

	protected:

		Cad_GeoSketch()
		{}

		Cad_GeoSketch(const Standard_Integer theIndex)
			: Global_Indexed(theIndex)
		{}

		Cad_GeoSketch
		(
			const Standard_Integer theIndex,
			const word& theName
		)
			: Global_Indexed(theIndex)
			, Global_Named(theName)
		{}

	public:

		virtual ~Cad_GeoSketch()
		{}

		std::shared_ptr<Cad_GeoSketch> This() const
		{
			return std::const_pointer_cast<Cad_GeoSketch>(shared_from_this());
		}
	};
}

#endif // !_Cad_GeoSketch_Header
