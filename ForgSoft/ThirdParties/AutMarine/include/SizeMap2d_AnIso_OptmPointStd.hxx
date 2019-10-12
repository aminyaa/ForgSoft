#pragma once
#ifndef _SizeMap2d_AnIso_OptmPointStd_Header
#define _SizeMap2d_AnIso_OptmPointStd_Header

#include <Global_Done.hxx>
#include <Entity2d_Box.hxx>
#include <Aft2d_EdgeAnIsoFwd.hxx>

#include <memory>

namespace AutLib
{

	// Forward Declarations
	class SizeMap2d_FullIntAnIso;

	class SizeMap2d_AnIso_OptmPointStd
		: public Global_Done
	{

		typedef Entity2d_Box box;
		typedef Aft2d_EdgeAnIso front;
		typedef SizeMap2d_FullIntAnIso sizeMap;

		/*Private Data*/

		Standard_Real theSize_;

		const front& theFront_;
		const box& theBox_;
		const sizeMap& theSizeMap_;

		Pnt2d theCoord_;

	public:

		static const Standard_Real C3;

		SizeMap2d_AnIso_OptmPointStd
		(
			const Standard_Real theSize,
			const box& theBox,
			const front& theFront,
			const sizeMap& theSizeMap
		)
			: theSize_(theSize)
			, theFront_(theFront)
			, theBox_(theBox)
			, theSizeMap_(theSizeMap)
		{}

		Standard_Real ElementSize() const
		{
			return theSize_;
		}

		const front& Front() const
		{
			return theFront_;
		}

		const box& BoundingBox() const
		{
			return theBox_;
		}

		const sizeMap& SizeMap() const
		{
			return theSizeMap_;
		}

		const Pnt2d& Coord() const
		{
			return theCoord_;
		}

		void Perform();
	};
}

#endif // !_SizeMap2d_AnIso_OptmPointStd_Header