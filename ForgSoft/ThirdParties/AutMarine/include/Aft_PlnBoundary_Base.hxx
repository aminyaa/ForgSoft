#pragma once
#ifndef _Aft_PlnBoundary_Base_Header
#define _Aft_PlnBoundary_Base_Header

#include <Global_Indexed.hxx>
#include <Global_Named.hxx>
#include <Global_Done.hxx>

#include <memory>
#include <vector>

namespace AutLib
{

	template<class BndType>
	class Aft_PlnBoundary_Base
		: public Global_Indexed
		, public Global_Named
		, public Global_Done
	{

		/*Private Data*/

		Standard_Boolean SimpleCheck_;
		Standard_Boolean InnerCheck_;
		Standard_Boolean OrientCheck_;
		Standard_Boolean NbPtsCheck_;

	protected:

		Aft_PlnBoundary_Base()
		{}


		Standard_Boolean& ChangeSimpleCheck()
		{
			return SimpleCheck_;
		}

		Standard_Boolean& ChangeInnerCheck()
		{
			return InnerCheck_;
		}

		Standard_Boolean& ChangeOrientCheck()
		{
			return OrientCheck_;
		}

		Standard_Boolean& ChangeNbPtsCheck()
		{
			return NbPtsCheck_;
		}

		static Standard_Boolean CheckWireOrientation
		(
			const std::vector<std::shared_ptr<BndType>>& theEdges,
			const Standard_Boolean ccw
		);

		static Standard_Boolean CheckWireNbPts
		(
			const std::vector<std::shared_ptr<BndType>>& theEdges
		);

		static Standard_Boolean CheckSimplicity
		(
			const std::vector<std::shared_ptr<BndType>>& theEdges
		);

	public:

		Standard_Boolean SimpleCheck() const
		{
			return SimpleCheck_;
		}

		Standard_Boolean InnerCheck() const
		{
			return InnerCheck_;
		}

		Standard_Boolean OrientCheck() const
		{
			return OrientCheck_;
		}

		Standard_Boolean NbPtsCheck() const
		{
			return NbPtsCheck_;
		}
	};
}

#include <Aft_PlnBoundary_BaseI.hxx>

#endif // !_Aft_PlnBoundary_Base_Header
