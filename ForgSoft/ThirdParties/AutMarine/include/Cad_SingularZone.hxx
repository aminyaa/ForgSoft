#pragma once
#ifndef _Cad_SingularZone_Header
#define _Cad_SingularZone_Header

#include <Global_Indexed.hxx>
#include <Entity2d_Box.hxx>
#include <Cad_SingularType.hxx>

#include <memory>
#include <vector>

namespace AutLib
{

	template<class SurfPln>
	class Cad_SingularZone
		: public Global_Indexed
	{

		typedef typename SurfPln::parCurveType plnCurve;

		/*Private Data*/

		std::shared_ptr<SurfPln> thePlane_;

		std::shared_ptr<Entity2d_Box> theBoundingBox_;

		std::vector<std::shared_ptr<plnCurve>> theBoundaries_;

	protected:

		Cad_SingularZone()
		{}

		Cad_SingularZone(const Standard_Integer theIndex)
			: Global_Indexed(theIndex)
		{}

		std::shared_ptr<Entity2d_Box>& ChangeBoundingBox()
		{
			return theBoundingBox_;
		}

		void InsertToBoundaries(const std::shared_ptr<plnCurve>& theCurve)
		{
			theBoundaries_.push_back(theCurve);
		}

	public:

		virtual Cad_SingularType Type() const = 0;

		virtual const word& TypeName() const = 0;

		virtual Standard_Integer NbHorizons() const = 0;

		virtual const std::shared_ptr<plnCurve>& Horizon(const Standard_Integer theIndex) const = 0;

		const std::shared_ptr<SurfPln>& Plane() const
		{
			return thePlane_;
		}

		const std::shared_ptr<Entity2d_Box>& BoundingBox() const
		{
			return theBoundingBox_;
		}

		const std::vector<std::shared_ptr<plnCurve>>& Boundaries() const
		{
			return theBoundaries_;
		}

		void LoadPlane(const std::shared_ptr<SurfPln>& thePlane)
		{
			thePlane_ = thePlane;
		}
	};
}

#endif // !_Cad_SingularZone_Header
