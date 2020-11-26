#pragma once
#ifndef _NumAlg_GaussQuadrature_Nodes_Header
#define _NumAlg_GaussQuadrature_Nodes_Header

#include <Standard_TypeDef.hxx>

namespace tnbLib
{

	namespace numLib
	{

		namespace gaussLib
		{

			template<int Node, int NbNodes>
			struct IntgNode {};

			template<> struct IntgNode<0, 2> { static const Standard_Real value; };
			template<> struct IntgNode<1, 2> { static const Standard_Real value; };

			template<> struct IntgNode<0, 3> { static const Standard_Real value; };
			template<> struct IntgNode<1, 3> { static const Standard_Real value; };
			template<> struct IntgNode<2, 3> { static const Standard_Real value; };

			template<> struct IntgNode<0, 4> { static const Standard_Real value; };
			template<> struct IntgNode<1, 4> { static const Standard_Real value; };
			template<> struct IntgNode<2, 4> { static const Standard_Real value; };
			template<> struct IntgNode<3, 4> { static const Standard_Real value; };

			template<> struct IntgNode<0, 6> { static const Standard_Real value; };
			template<> struct IntgNode<1, 6> { static const Standard_Real value; };
			template<> struct IntgNode<2, 6> { static const Standard_Real value; };
			template<> struct IntgNode<3, 6> { static const Standard_Real value; };
			template<> struct IntgNode<4, 6> { static const Standard_Real value; };
			template<> struct IntgNode<5, 6> { static const Standard_Real value; };

			template<> struct IntgNode<0, 8> { static const Standard_Real value; };
			template<> struct IntgNode<1, 8> { static const Standard_Real value; };
			template<> struct IntgNode<2, 8> { static const Standard_Real value; };
			template<> struct IntgNode<3, 8> { static const Standard_Real value; };
			template<> struct IntgNode<4, 8> { static const Standard_Real value; };
			template<> struct IntgNode<5, 8> { static const Standard_Real value; };
			template<> struct IntgNode<6, 8> { static const Standard_Real value; };
			template<> struct IntgNode<7, 8> { static const Standard_Real value; };


			template<> struct IntgNode<0, 10> { static const Standard_Real value; };
			template<> struct IntgNode<1, 10> { static const Standard_Real value; };
			template<> struct IntgNode<2, 10> { static const Standard_Real value; };
			template<> struct IntgNode<3, 10> { static const Standard_Real value; };
			template<> struct IntgNode<4, 10> { static const Standard_Real value; };
			template<> struct IntgNode<5, 10> { static const Standard_Real value; };
			template<> struct IntgNode<6, 10> { static const Standard_Real value; };
			template<> struct IntgNode<7, 10> { static const Standard_Real value; };
			template<> struct IntgNode<8, 10> { static const Standard_Real value; };
			template<> struct IntgNode<9, 10> { static const Standard_Real value; };


			template<> struct IntgNode<0, 12> { static const Standard_Real value; };
			template<> struct IntgNode<1, 12> { static const Standard_Real value; };
			template<> struct IntgNode<2, 12> { static const Standard_Real value; };
			template<> struct IntgNode<3, 12> { static const Standard_Real value; };
			template<> struct IntgNode<4, 12> { static const Standard_Real value; };
			template<> struct IntgNode<5, 12> { static const Standard_Real value; };
			template<> struct IntgNode<6, 12> { static const Standard_Real value; };
			template<> struct IntgNode<7, 12> { static const Standard_Real value; };
			template<> struct IntgNode<8, 12> { static const Standard_Real value; };
			template<> struct IntgNode<9, 12> { static const Standard_Real value; };
			template<> struct IntgNode<10, 12> { static const Standard_Real value; };
			template<> struct IntgNode<11, 12> { static const Standard_Real value; };


			template<> struct IntgNode<0, 14> { static const Standard_Real value; };
			template<> struct IntgNode<1, 14> { static const Standard_Real value; };
			template<> struct IntgNode<2, 14> { static const Standard_Real value; };
			template<> struct IntgNode<3, 14> { static const Standard_Real value; };
			template<> struct IntgNode<4, 14> { static const Standard_Real value; };
			template<> struct IntgNode<5, 14> { static const Standard_Real value; };
			template<> struct IntgNode<6, 14> { static const Standard_Real value; };
			template<> struct IntgNode<7, 14> { static const Standard_Real value; };
			template<> struct IntgNode<8, 14> { static const Standard_Real value; };
			template<> struct IntgNode<9, 14> { static const Standard_Real value; };
			template<> struct IntgNode<10, 14> { static const Standard_Real value; };
			template<> struct IntgNode<11, 14> { static const Standard_Real value; };
			template<> struct IntgNode<12, 14> { static const Standard_Real value; };
			template<> struct IntgNode<13, 14> { static const Standard_Real value; };


			template<> struct IntgNode<0, 16> { static const Standard_Real value; };
			template<> struct IntgNode<1, 16> { static const Standard_Real value; };
			template<> struct IntgNode<2, 16> { static const Standard_Real value; };
			template<> struct IntgNode<3, 16> { static const Standard_Real value; };
			template<> struct IntgNode<4, 16> { static const Standard_Real value; };
			template<> struct IntgNode<5, 16> { static const Standard_Real value; };
			template<> struct IntgNode<6, 16> { static const Standard_Real value; };
			template<> struct IntgNode<7, 16> { static const Standard_Real value; };
			template<> struct IntgNode<8, 16> { static const Standard_Real value; };
			template<> struct IntgNode<9, 16> { static const Standard_Real value; };
			template<> struct IntgNode<10, 16> { static const Standard_Real value; };
			template<> struct IntgNode<11, 16> { static const Standard_Real value; };
			template<> struct IntgNode<12, 16> { static const Standard_Real value; };
			template<> struct IntgNode<13, 16> { static const Standard_Real value; };
			template<> struct IntgNode<14, 16> { static const Standard_Real value; };
			template<> struct IntgNode<15, 16> { static const Standard_Real value; };


			template<> struct IntgNode<0, 18> { static const Standard_Real value; };
			template<> struct IntgNode<1, 18> { static const Standard_Real value; };
			template<> struct IntgNode<2, 18> { static const Standard_Real value; };
			template<> struct IntgNode<3, 18> { static const Standard_Real value; };
			template<> struct IntgNode<4, 18> { static const Standard_Real value; };
			template<> struct IntgNode<5, 18> { static const Standard_Real value; };
			template<> struct IntgNode<6, 18> { static const Standard_Real value; };
			template<> struct IntgNode<7, 18> { static const Standard_Real value; };
			template<> struct IntgNode<8, 18> { static const Standard_Real value; };
			template<> struct IntgNode<9, 18> { static const Standard_Real value; };
			template<> struct IntgNode<10, 18> { static const Standard_Real value; };
			template<> struct IntgNode<11, 18> { static const Standard_Real value; };
			template<> struct IntgNode<12, 18> { static const Standard_Real value; };
			template<> struct IntgNode<13, 18> { static const Standard_Real value; };
			template<> struct IntgNode<14, 18> { static const Standard_Real value; };
			template<> struct IntgNode<15, 18> { static const Standard_Real value; };
			template<> struct IntgNode<16, 18> { static const Standard_Real value; };
			template<> struct IntgNode<17, 18> { static const Standard_Real value; };


			template<> struct IntgNode<0, 20> { static const Standard_Real value; };
			template<> struct IntgNode<1, 20> { static const Standard_Real value; };
			template<> struct IntgNode<2, 20> { static const Standard_Real value; };
			template<> struct IntgNode<3, 20> { static const Standard_Real value; };
			template<> struct IntgNode<4, 20> { static const Standard_Real value; };
			template<> struct IntgNode<5, 20> { static const Standard_Real value; };
			template<> struct IntgNode<6, 20> { static const Standard_Real value; };
			template<> struct IntgNode<7, 20> { static const Standard_Real value; };
			template<> struct IntgNode<8, 20> { static const Standard_Real value; };
			template<> struct IntgNode<9, 20> { static const Standard_Real value; };
			template<> struct IntgNode<10, 20> { static const Standard_Real value; };
			template<> struct IntgNode<11, 20> { static const Standard_Real value; };
			template<> struct IntgNode<12, 20> { static const Standard_Real value; };
			template<> struct IntgNode<13, 20> { static const Standard_Real value; };
			template<> struct IntgNode<14, 20> { static const Standard_Real value; };
			template<> struct IntgNode<15, 20> { static const Standard_Real value; };
			template<> struct IntgNode<16, 20> { static const Standard_Real value; };
			template<> struct IntgNode<17, 20> { static const Standard_Real value; };
			template<> struct IntgNode<18, 20> { static const Standard_Real value; };
			template<> struct IntgNode<19, 20> { static const Standard_Real value; };

		}
	}
}

#define INTEG_POINT(INDEX, NBPTS) typedef IntgNode<INDEX, NBPTS> P##INDEX##_##NBPTS

namespace tnbLib
{

	namespace numLib
	{

		namespace gaussLib
		{

			INTEG_POINT(0, 2);
			INTEG_POINT(1, 2);

			INTEG_POINT(0, 3);
			INTEG_POINT(1, 3);
			INTEG_POINT(2, 3);

			INTEG_POINT(0, 4);
			INTEG_POINT(1, 4);
			INTEG_POINT(2, 4);
			INTEG_POINT(3, 4);

			INTEG_POINT(0, 6);
			INTEG_POINT(1, 6);
			INTEG_POINT(2, 6);
			INTEG_POINT(3, 6);
			INTEG_POINT(4, 6);
			INTEG_POINT(5, 6);

			INTEG_POINT(0, 8);
			INTEG_POINT(1, 8);
			INTEG_POINT(2, 8);
			INTEG_POINT(3, 8);
			INTEG_POINT(4, 8);
			INTEG_POINT(5, 8);
			INTEG_POINT(6, 8);
			INTEG_POINT(7, 8);

			INTEG_POINT(0, 10);
			INTEG_POINT(1, 10);
			INTEG_POINT(2, 10);
			INTEG_POINT(3, 10);
			INTEG_POINT(4, 10);
			INTEG_POINT(5, 10);
			INTEG_POINT(6, 10);
			INTEG_POINT(7, 10);
			INTEG_POINT(8, 10);
			INTEG_POINT(9, 10);

			INTEG_POINT(0, 12);
			INTEG_POINT(1, 12);
			INTEG_POINT(2, 12);
			INTEG_POINT(3, 12);
			INTEG_POINT(4, 12);
			INTEG_POINT(5, 12);
			INTEG_POINT(6, 12);
			INTEG_POINT(7, 12);
			INTEG_POINT(8, 12);
			INTEG_POINT(9, 12);
			INTEG_POINT(10, 12);
			INTEG_POINT(11, 12);

			INTEG_POINT(0, 14);
			INTEG_POINT(1, 14);
			INTEG_POINT(2, 14);
			INTEG_POINT(3, 14);
			INTEG_POINT(4, 14);
			INTEG_POINT(5, 14);
			INTEG_POINT(6, 14);
			INTEG_POINT(7, 14);
			INTEG_POINT(8, 14);
			INTEG_POINT(9, 14);
			INTEG_POINT(10, 14);
			INTEG_POINT(11, 14);
			INTEG_POINT(12, 14);
			INTEG_POINT(13, 14);

			INTEG_POINT(0, 16);
			INTEG_POINT(1, 16);
			INTEG_POINT(2, 16);
			INTEG_POINT(3, 16);
			INTEG_POINT(4, 16);
			INTEG_POINT(5, 16);
			INTEG_POINT(6, 16);
			INTEG_POINT(7, 16);
			INTEG_POINT(8, 16);
			INTEG_POINT(9, 16);
			INTEG_POINT(10, 16);
			INTEG_POINT(11, 16);
			INTEG_POINT(12, 16);
			INTEG_POINT(13, 16);
			INTEG_POINT(14, 16);
			INTEG_POINT(15, 16);

			INTEG_POINT(0, 18);
			INTEG_POINT(1, 18);
			INTEG_POINT(2, 18);
			INTEG_POINT(3, 18);
			INTEG_POINT(4, 18);
			INTEG_POINT(5, 18);
			INTEG_POINT(6, 18);
			INTEG_POINT(7, 18);
			INTEG_POINT(8, 18);
			INTEG_POINT(9, 18);
			INTEG_POINT(10, 18);
			INTEG_POINT(11, 18);
			INTEG_POINT(12, 18);
			INTEG_POINT(13, 18);
			INTEG_POINT(14, 18);
			INTEG_POINT(15, 18);
			INTEG_POINT(16, 18);
			INTEG_POINT(17, 18);

			INTEG_POINT(0, 20);
			INTEG_POINT(1, 20);
			INTEG_POINT(2, 20);
			INTEG_POINT(3, 20);
			INTEG_POINT(4, 20);
			INTEG_POINT(5, 20);
			INTEG_POINT(6, 20);
			INTEG_POINT(7, 20);
			INTEG_POINT(8, 20);
			INTEG_POINT(9, 20);
			INTEG_POINT(10, 20);
			INTEG_POINT(11, 20);
			INTEG_POINT(12, 20);
			INTEG_POINT(13, 20);
			INTEG_POINT(14, 20);
			INTEG_POINT(15, 20);
			INTEG_POINT(16, 20);
			INTEG_POINT(17, 20);
			INTEG_POINT(18, 20);
			INTEG_POINT(19, 20);
		}
	}
}

#undef INTEG_POINT

#endif // !_NumAlg_GaussQuadrature_Nodes_Header
