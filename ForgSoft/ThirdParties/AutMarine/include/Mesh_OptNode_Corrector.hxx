#pragma once
#ifndef _Mesh_OptNode_Corrector_Header
#define _Mesh_OptNode_Corrector_Header

#include <Global_Done.hxx>

namespace AutLib
{

	template<class AftMetricPrcsr>
	class Mesh_OptNode_Corrector
		: public Global_Done
	{

	public:

		typedef typename AftMetricPrcsr::frontType frontType;
		typedef typename AftMetricPrcsr::sizeFun sizeFun;
		typedef typename AftMetricPrcsr::metricFun metricFun;

		typedef typename sizeFun::ptType Point;

	private:

		/*Private Data*/

		Standard_Real theSize_;

		const frontType& theFront_;
		const Point& theP0_;

		Point theCoord_;

		Standard_Boolean IsConverged_;
	

	protected:

		Mesh_OptNode_Corrector
		(
			const Standard_Real theSize,
			const frontType& theFront,
			const Point& theP0
		)
			: theSize_(theSize)
			, theFront_(theFront)
			, theP0_(theP0)
			, IsConverged_(Standard_False)
		{}

		Point& ChangeCoord()
		{
			return theCoord_;
		}

		Standard_Boolean& Change_IsConverged()
		{
			return IsConverged_;
		}

	public:
	

		Standard_Real Size() const
		{
			return theSize_;
		}

		const frontType& Front() const
		{
			return theFront_;
		}

		const Point& Coord() const
		{
			return theCoord_;
		}

		const Point& P0() const
		{
			return theP0_;
		}

		Standard_Boolean IsConverged() const
		{
			return IsConverged_;
		}

		virtual void Perform() = 0;
	};
}

#endif // !_Mesh_OptNode_Corrector_Header
