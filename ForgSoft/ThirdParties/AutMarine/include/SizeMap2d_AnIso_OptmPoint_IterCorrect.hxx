#pragma once
#ifndef _SizeMap2d_AnIso_OptmPoint_IterCorrect_Header
#define _SizeMap2d_AnIso_OptmPoint_IterCorrect_Header

#include <Global_Done.hxx>
#include <Entity2d_Box.hxx>
#include <Aft2d_EdgeAnIsoFwd.hxx>
#include <SizeMap2d_AnIso_OptmPoint_IterCorrectInfo.hxx>

#include <memory>

namespace AutLib
{

	// Forward Declarations
	class SizeMap2d_FullIntAnIso;

	class SizeMap2d_AnIso_OptmPoint_IterCorrect
		: public Global_Done
	{

		typedef SizeMap2d_AnIso_OptmPoint_IterCorrectInfo info;

		typedef Entity2d_Box box;
		typedef Aft2d_EdgeAnIso front;
		typedef SizeMap2d_FullIntAnIso sizeMap;

		/*Private Data*/

		Standard_Boolean IsConverged_;
		Standard_Real theSize_;

		const front& theFront_;
		const box& theBox_;
		const sizeMap& theSizeMap_;
		const Pnt2d& theP0_;

		std::shared_ptr<info> theInfo_;

		Pnt2d theCoord_;


		Pnt2d& ChangeCoord()
		{
			return theCoord_;
		}

		Standard_Boolean& ChangeConverged()
		{
			return IsConverged_;
		}

	public:

		SizeMap2d_AnIso_OptmPoint_IterCorrect
		(
			const Standard_Real theSize,
			const box& theBox,
			const front& theEdge,
			const sizeMap& theSizeMap,
			const Pnt2d& theP0,
			const std::shared_ptr<info>& theInfo
		)
			: theSize_(theSize)
			, theFront_(theEdge)
			, theBox_(theBox)
			, theSizeMap_(theSizeMap)
			, theP0_(theP0)
			, theInfo_(theInfo)
			, IsConverged_(Standard_False)
		{}

		Standard_Boolean IsConverged() const
		{
			return IsConverged_;
		}

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

		const Pnt2d& P0() const
		{
			return theP0_;
		}

		const Pnt2d& Coord() const
		{
			return theCoord_;
		}

		const std::shared_ptr<info>& Info() const
		{
			return theInfo_;
		}

		void Perform();
	};
}

#endif // !_SizeMap2d_AnIso_OptmPoint_IterCorrect_Header