#pragma once
#ifndef _PlnOpert_IntsctPair_Header
#define _PlnOpert_IntsctPair_Header

#include <Global_Indexed.hxx>
#include <Global_AccessMethod.hxx>

#include <memory>

namespace tnbLib
{

	// Forward Declarations
	class PlnOpert_IntsctEntity;

	class PlnOpert_IntsctPair
		: public Global_Indexed
	{

		/*Private Data*/

		std::shared_ptr<PlnOpert_IntsctEntity> theEntity0_;
		std::shared_ptr<PlnOpert_IntsctEntity> theEntity1_;

		Standard_Boolean SameDirection_;

	public:

		PlnOpert_IntsctPair
		(
			const Standard_Integer theIndex, 
			const std::shared_ptr<PlnOpert_IntsctEntity>& theE0, 
			const std::shared_ptr<PlnOpert_IntsctEntity>& theE1
		);

		Standard_Boolean IsPoint() const;

		Standard_Boolean IsSegment() const;

		const std::shared_ptr<PlnOpert_IntsctEntity>& Entity0() const
		{
			return theEntity0_;
		}

		const std::shared_ptr<PlnOpert_IntsctEntity>& Entity1() const
		{
			return theEntity1_;
		}

		Standard_Boolean SameDirection() const
		{
			return SameDirection_;
		}

		void SetSameDirection(const Standard_Boolean theSame)
		{
			SameDirection_ = theSame;
		}

		//- Macros

	};
}

#endif // !_PlnOpert_IntsctPair_Header
