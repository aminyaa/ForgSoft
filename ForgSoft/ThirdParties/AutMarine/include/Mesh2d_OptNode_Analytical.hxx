#pragma once
#ifndef _Mesh2d_OptNode_Analytical_Header
#define _Mesh2d_OptNode_Analytical_Header

#include <Global_Done.hxx>
#include <Mesh_OptNode_Analytical.hxx>
#include <Aft2d_Edge.hxx>

namespace AutLib
{

	class Mesh2d_OptNode_Analytical_Base
	{

		/*Private Data*/

	protected:

		Mesh2d_OptNode_Analytical_Base()
		{}

	public:

		static Pnt2d CalcCoord(const Standard_Real theSize, const Aft2d_Edge& theEdge);
	};

	class Mesh2d_OptNode_Analytical
		: public Mesh2d_OptNode_Analytical_Base
		, public Global_Done
	{

		typedef Aft2d_Edge frontType;
		typedef Pnt2d Point;

		/*Private Data*/

		Standard_Real theSize_;

		const frontType& theFront_;

		Point theCoord_;


		Point& ChangeCoord()
		{
			return theCoord_;
		}

	public:

		Mesh2d_OptNode_Analytical
		(
			const Standard_Real theSize,
			const frontType& theFront
		)
			: theSize_(theSize)
			, theFront_(theFront)
		{}

		Standard_Real ElementSize() const
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

		void Perform();
	};
}

#include <Mesh2d_OptNode_AnalyticalI.hxx>

#endif // !_Mesh2d_OptNode_Analytical_Header
