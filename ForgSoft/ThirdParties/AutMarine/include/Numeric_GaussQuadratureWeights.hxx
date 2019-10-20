#pragma once
#ifndef _Numeric_GaussQuadratureWeights_Header
#define _Numeric_GaussQuadratureWeights_Header

#include <Standard_TypeDef.hxx>

namespace AutLib
{

	namespace numLib
	{

		namespace gaussLib
		{

			template<int Node, int NbNodes>
			struct IntgWeight {};

			template<> struct IntgWeight<0, 2> { static const Standard_Real value; };
			template<> struct IntgWeight<1, 2> { static const Standard_Real value; };

			template<> struct IntgWeight<0, 3> { static const Standard_Real value; };
			template<> struct IntgWeight<1, 3> { static const Standard_Real value; };
			template<> struct IntgWeight<2, 3> { static const Standard_Real value; };

			template<> struct IntgWeight<0, 4> { static const Standard_Real value; };
			template<> struct IntgWeight<1, 4> { static const Standard_Real value; };
			template<> struct IntgWeight<2, 4> { static const Standard_Real value; };
			template<> struct IntgWeight<3, 4> { static const Standard_Real value; };

			template<> struct IntgWeight<0, 6> { static const Standard_Real value; };
			template<> struct IntgWeight<1, 6> { static const Standard_Real value; };
			template<> struct IntgWeight<2, 6> { static const Standard_Real value; };
			template<> struct IntgWeight<3, 6> { static const Standard_Real value; };
			template<> struct IntgWeight<4, 6> { static const Standard_Real value; };
			template<> struct IntgWeight<5, 6> { static const Standard_Real value; };

			template<> struct IntgWeight<0, 8> { static const Standard_Real value; };
			template<> struct IntgWeight<1, 8> { static const Standard_Real value; };
			template<> struct IntgWeight<2, 8> { static const Standard_Real value; };
			template<> struct IntgWeight<3, 8> { static const Standard_Real value; };
			template<> struct IntgWeight<4, 8> { static const Standard_Real value; };
			template<> struct IntgWeight<5, 8> { static const Standard_Real value; };
			template<> struct IntgWeight<6, 8> { static const Standard_Real value; };
			template<> struct IntgWeight<7, 8> { static const Standard_Real value; };


			template<> struct IntgWeight<0, 10> { static const Standard_Real value; };
			template<> struct IntgWeight<1, 10> { static const Standard_Real value; };
			template<> struct IntgWeight<2, 10> { static const Standard_Real value; };
			template<> struct IntgWeight<3, 10> { static const Standard_Real value; };
			template<> struct IntgWeight<4, 10> { static const Standard_Real value; };
			template<> struct IntgWeight<5, 10> { static const Standard_Real value; };
			template<> struct IntgWeight<6, 10> { static const Standard_Real value; };
			template<> struct IntgWeight<7, 10> { static const Standard_Real value; };
			template<> struct IntgWeight<8, 10> { static const Standard_Real value; };
			template<> struct IntgWeight<9, 10> { static const Standard_Real value; };


			template<> struct IntgWeight<0, 12> { static const Standard_Real value; };
			template<> struct IntgWeight<1, 12> { static const Standard_Real value; };
			template<> struct IntgWeight<2, 12> { static const Standard_Real value; };
			template<> struct IntgWeight<3, 12> { static const Standard_Real value; };
			template<> struct IntgWeight<4, 12> { static const Standard_Real value; };
			template<> struct IntgWeight<5, 12> { static const Standard_Real value; };
			template<> struct IntgWeight<6, 12> { static const Standard_Real value; };
			template<> struct IntgWeight<7, 12> { static const Standard_Real value; };
			template<> struct IntgWeight<8, 12> { static const Standard_Real value; };
			template<> struct IntgWeight<9, 12> { static const Standard_Real value; };
			template<> struct IntgWeight<10, 12> { static const Standard_Real value; };
			template<> struct IntgWeight<11, 12> { static const Standard_Real value; };


			template<> struct IntgWeight<0, 14> { static const Standard_Real value; };
			template<> struct IntgWeight<1, 14> { static const Standard_Real value; };
			template<> struct IntgWeight<2, 14> { static const Standard_Real value; };
			template<> struct IntgWeight<3, 14> { static const Standard_Real value; };
			template<> struct IntgWeight<4, 14> { static const Standard_Real value; };
			template<> struct IntgWeight<5, 14> { static const Standard_Real value; };
			template<> struct IntgWeight<6, 14> { static const Standard_Real value; };
			template<> struct IntgWeight<7, 14> { static const Standard_Real value; };
			template<> struct IntgWeight<8, 14> { static const Standard_Real value; };
			template<> struct IntgWeight<9, 14> { static const Standard_Real value; };
			template<> struct IntgWeight<10, 14> { static const Standard_Real value; };
			template<> struct IntgWeight<11, 14> { static const Standard_Real value; };
			template<> struct IntgWeight<12, 14> { static const Standard_Real value; };
			template<> struct IntgWeight<13, 14> { static const Standard_Real value; };


			template<> struct IntgWeight<0, 16> { static const Standard_Real value; };
			template<> struct IntgWeight<1, 16> { static const Standard_Real value; };
			template<> struct IntgWeight<2, 16> { static const Standard_Real value; };
			template<> struct IntgWeight<3, 16> { static const Standard_Real value; };
			template<> struct IntgWeight<4, 16> { static const Standard_Real value; };
			template<> struct IntgWeight<5, 16> { static const Standard_Real value; };
			template<> struct IntgWeight<6, 16> { static const Standard_Real value; };
			template<> struct IntgWeight<7, 16> { static const Standard_Real value; };
			template<> struct IntgWeight<8, 16> { static const Standard_Real value; };
			template<> struct IntgWeight<9, 16> { static const Standard_Real value; };
			template<> struct IntgWeight<10, 16> { static const Standard_Real value; };
			template<> struct IntgWeight<11, 16> { static const Standard_Real value; };
			template<> struct IntgWeight<12, 16> { static const Standard_Real value; };
			template<> struct IntgWeight<13, 16> { static const Standard_Real value; };
			template<> struct IntgWeight<14, 16> { static const Standard_Real value; };
			template<> struct IntgWeight<15, 16> { static const Standard_Real value; };


			template<> struct IntgWeight<0, 18> { static const Standard_Real value; };
			template<> struct IntgWeight<1, 18> { static const Standard_Real value; };
			template<> struct IntgWeight<2, 18> { static const Standard_Real value; };
			template<> struct IntgWeight<3, 18> { static const Standard_Real value; };
			template<> struct IntgWeight<4, 18> { static const Standard_Real value; };
			template<> struct IntgWeight<5, 18> { static const Standard_Real value; };
			template<> struct IntgWeight<6, 18> { static const Standard_Real value; };
			template<> struct IntgWeight<7, 18> { static const Standard_Real value; };
			template<> struct IntgWeight<8, 18> { static const Standard_Real value; };
			template<> struct IntgWeight<9, 18> { static const Standard_Real value; };
			template<> struct IntgWeight<10, 18> { static const Standard_Real value; };
			template<> struct IntgWeight<11, 18> { static const Standard_Real value; };
			template<> struct IntgWeight<12, 18> { static const Standard_Real value; };
			template<> struct IntgWeight<13, 18> { static const Standard_Real value; };
			template<> struct IntgWeight<14, 18> { static const Standard_Real value; };
			template<> struct IntgWeight<15, 18> { static const Standard_Real value; };
			template<> struct IntgWeight<16, 18> { static const Standard_Real value; };
			template<> struct IntgWeight<17, 18> { static const Standard_Real value; };


			template<> struct IntgWeight<0, 20> { static const Standard_Real value; };
			template<> struct IntgWeight<1, 20> { static const Standard_Real value; };
			template<> struct IntgWeight<2, 20> { static const Standard_Real value; };
			template<> struct IntgWeight<3, 20> { static const Standard_Real value; };
			template<> struct IntgWeight<4, 20> { static const Standard_Real value; };
			template<> struct IntgWeight<5, 20> { static const Standard_Real value; };
			template<> struct IntgWeight<6, 20> { static const Standard_Real value; };
			template<> struct IntgWeight<7, 20> { static const Standard_Real value; };
			template<> struct IntgWeight<8, 20> { static const Standard_Real value; };
			template<> struct IntgWeight<9, 20> { static const Standard_Real value; };
			template<> struct IntgWeight<10, 20> { static const Standard_Real value; };
			template<> struct IntgWeight<11, 20> { static const Standard_Real value; };
			template<> struct IntgWeight<12, 20> { static const Standard_Real value; };
			template<> struct IntgWeight<13, 20> { static const Standard_Real value; };
			template<> struct IntgWeight<14, 20> { static const Standard_Real value; };
			template<> struct IntgWeight<15, 20> { static const Standard_Real value; };
			template<> struct IntgWeight<16, 20> { static const Standard_Real value; };
			template<> struct IntgWeight<17, 20> { static const Standard_Real value; };
			template<> struct IntgWeight<18, 20> { static const Standard_Real value; };
			template<> struct IntgWeight<19, 20> { static const Standard_Real value; };

			
		}
	}
}

#define INTEG_WEIGHT(INDEX, NBPTS) typedef IntgWeight<INDEX, NBPTS> W##INDEX##_##NBPTS

namespace AutLib
{
	namespace numLib
	{

		namespace gaussLib
		{

			INTEG_WEIGHT(0, 2);
			INTEG_WEIGHT(1, 2);

			INTEG_WEIGHT(0, 3);
			INTEG_WEIGHT(1, 3);
			INTEG_WEIGHT(2, 3);

			INTEG_WEIGHT(0, 4);
			INTEG_WEIGHT(1, 4);
			INTEG_WEIGHT(2, 4);
			INTEG_WEIGHT(3, 4);

			INTEG_WEIGHT(0, 6);
			INTEG_WEIGHT(1, 6);
			INTEG_WEIGHT(2, 6);
			INTEG_WEIGHT(3, 6);
			INTEG_WEIGHT(4, 6);
			INTEG_WEIGHT(5, 6);

			INTEG_WEIGHT(0, 8);
			INTEG_WEIGHT(1, 8);
			INTEG_WEIGHT(2, 8);
			INTEG_WEIGHT(3, 8);
			INTEG_WEIGHT(4, 8);
			INTEG_WEIGHT(5, 8);
			INTEG_WEIGHT(6, 8);
			INTEG_WEIGHT(7, 8);

			INTEG_WEIGHT(0, 10);
			INTEG_WEIGHT(1, 10);
			INTEG_WEIGHT(2, 10);
			INTEG_WEIGHT(3, 10);
			INTEG_WEIGHT(4, 10);
			INTEG_WEIGHT(5, 10);
			INTEG_WEIGHT(6, 10);
			INTEG_WEIGHT(7, 10);
			INTEG_WEIGHT(8, 10);
			INTEG_WEIGHT(9, 10);

			INTEG_WEIGHT(0, 12);
			INTEG_WEIGHT(1, 12);
			INTEG_WEIGHT(2, 12);
			INTEG_WEIGHT(3, 12);
			INTEG_WEIGHT(4, 12);
			INTEG_WEIGHT(5, 12);
			INTEG_WEIGHT(6, 12);
			INTEG_WEIGHT(7, 12);
			INTEG_WEIGHT(8, 12);
			INTEG_WEIGHT(9, 12);
			INTEG_WEIGHT(10, 12);
			INTEG_WEIGHT(11, 12);

			INTEG_WEIGHT(0, 14);
			INTEG_WEIGHT(1, 14);
			INTEG_WEIGHT(2, 14);
			INTEG_WEIGHT(3, 14);
			INTEG_WEIGHT(4, 14);
			INTEG_WEIGHT(5, 14);
			INTEG_WEIGHT(6, 14);
			INTEG_WEIGHT(7, 14);
			INTEG_WEIGHT(8, 14);
			INTEG_WEIGHT(9, 14);
			INTEG_WEIGHT(10, 14);
			INTEG_WEIGHT(11, 14);
			INTEG_WEIGHT(12, 14);
			INTEG_WEIGHT(13, 14);

			INTEG_WEIGHT(0, 16);
			INTEG_WEIGHT(1, 16);
			INTEG_WEIGHT(2, 16);
			INTEG_WEIGHT(3, 16);
			INTEG_WEIGHT(4, 16);
			INTEG_WEIGHT(5, 16);
			INTEG_WEIGHT(6, 16);
			INTEG_WEIGHT(7, 16);
			INTEG_WEIGHT(8, 16);
			INTEG_WEIGHT(9, 16);
			INTEG_WEIGHT(10, 16);
			INTEG_WEIGHT(11, 16);
			INTEG_WEIGHT(12, 16);
			INTEG_WEIGHT(13, 16);
			INTEG_WEIGHT(14, 16);
			INTEG_WEIGHT(15, 16);

			INTEG_WEIGHT(0, 18);
			INTEG_WEIGHT(1, 18);
			INTEG_WEIGHT(2, 18);
			INTEG_WEIGHT(3, 18);
			INTEG_WEIGHT(4, 18);
			INTEG_WEIGHT(5, 18);
			INTEG_WEIGHT(6, 18);
			INTEG_WEIGHT(7, 18);
			INTEG_WEIGHT(8, 18);
			INTEG_WEIGHT(9, 18);
			INTEG_WEIGHT(10, 18);
			INTEG_WEIGHT(11, 18);
			INTEG_WEIGHT(12, 18);
			INTEG_WEIGHT(13, 18);
			INTEG_WEIGHT(14, 18);
			INTEG_WEIGHT(15, 18);
			INTEG_WEIGHT(16, 18);
			INTEG_WEIGHT(17, 18);

			INTEG_WEIGHT(0, 20);
			INTEG_WEIGHT(1, 20);
			INTEG_WEIGHT(2, 20);
			INTEG_WEIGHT(3, 20);
			INTEG_WEIGHT(4, 20);
			INTEG_WEIGHT(5, 20);
			INTEG_WEIGHT(6, 20);
			INTEG_WEIGHT(7, 20);
			INTEG_WEIGHT(8, 20);
			INTEG_WEIGHT(9, 20);
			INTEG_WEIGHT(10, 20);
			INTEG_WEIGHT(11, 20);
			INTEG_WEIGHT(12, 20);
			INTEG_WEIGHT(13, 20);
			INTEG_WEIGHT(14, 20);
			INTEG_WEIGHT(15, 20);
			INTEG_WEIGHT(16, 20);
			INTEG_WEIGHT(17, 20);
			INTEG_WEIGHT(18, 20);
			INTEG_WEIGHT(19, 20);
		}
	}
}

#undef INTEG_WEIGHT

#endif // !_Numeric_GaussQuadratureWeights_Header
