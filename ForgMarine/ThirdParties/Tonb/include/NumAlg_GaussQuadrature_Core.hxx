#pragma once
#ifndef _NumAlg_GaussQuadrature_Core_Header
#define _NumAlg_GaussQuadrature_Core_Header

#include <NumAlg_GaussQuadrature_Nodes.hxx>
#include <NumAlg_GaussQuadrature_Weights.hxx>

namespace tnbLib
{

	namespace numLib
	{

		namespace gaussLib
		{

			inline Standard_Real X(const Standard_Real x, const Standard_Real h2, const Standard_Real c)
			{
				return h2 * x + c;
			}


			template<class Fun, int NbPts>
			struct Core {};

			template<class Fun>
			struct Core<Fun, 2>
			{
				static Standard_Real _(const Fun& f, const Standard_Real h2, const Standard_Real c)
				{
					const auto x0 = X(P0_2::value, h2, c);
					const auto x1 = X(P1_2::value, h2, c);

					return
						W0_2::value*f.Value(x0) +
						W1_2::value*f.Value(x1);
				}
			};

			template<class Fun>
			struct Core<Fun, 3>
			{
				static Standard_Real _(const Fun& f, const Standard_Real h2, const Standard_Real c)
				{
					const auto x0 = X(P0_3::value, h2, c);
					const auto x1 = X(P1_3::value, h2, c);
					const auto x2 = X(P2_3::value, h2, c);

					return
						W0_3::value*f.Value(x0) +
						W1_3::value*f.Value(x1) +
						W2_3::value*f.Value(x2);
				}
			};

			template<class Fun>
			struct Core<Fun, 4>
			{
				static Standard_Real _(const Fun& f, const Standard_Real h2, const Standard_Real c)
				{
					const auto x0 = X(P0_4::value, h2, c);
					const auto x1 = X(P1_4::value, h2, c);
					const auto x2 = X(P2_4::value, h2, c);
					const auto x3 = X(P3_4::value, h2, c);

					return
						W0_4::value*f.Value(x0) +
						W1_4::value*f.Value(x1) +
						W2_4::value*f.Value(x2) +
						W3_4::value*f.Value(x3);
				}
			};

			template<class Fun>
			struct Core<Fun, 6>
			{
				static Standard_Real _(const Fun& f, const Standard_Real h2, const Standard_Real c)
				{
					const auto x0 = X(P0_6::value, h2, c);
					const auto x1 = X(P1_6::value, h2, c);
					const auto x2 = X(P2_6::value, h2, c);
					const auto x3 = X(P3_6::value, h2, c);
					const auto x4 = X(P4_6::value, h2, c);
					const auto x5 = X(P5_6::value, h2, c);

					return
						W0_6::value*f.Value(x0) +
						W1_6::value*f.Value(x1) +
						W2_6::value*f.Value(x2) +
						W3_6::value*f.Value(x3) +
						W4_6::value*f.Value(x4) +
						W5_6::value*f.Value(x5);
				}
			};

			template<class Fun>
			struct Core<Fun, 8>
			{
				static Standard_Real _(const Fun& f, const Standard_Real h2, const Standard_Real c)
				{
					const auto x0 = X(P0_8::value, h2, c);
					const auto x1 = X(P1_8::value, h2, c);
					const auto x2 = X(P2_8::value, h2, c);
					const auto x3 = X(P3_8::value, h2, c);
					const auto x4 = X(P4_8::value, h2, c);
					const auto x5 = X(P5_8::value, h2, c);
					const auto x6 = X(P6_8::value, h2, c);
					const auto x7 = X(P7_8::value, h2, c);

					return
						W0_8::value*f.Value(x0) +
						W1_8::value*f.Value(x1) +
						W2_8::value*f.Value(x2) +
						W3_8::value*f.Value(x3) +
						W4_8::value*f.Value(x4) +
						W5_8::value*f.Value(x5) +
						W6_8::value*f.Value(x6) +
						W7_8::value*f.Value(x7);
				}
			};

			template<class Fun>
			struct Core<Fun, 10>
			{
				static Standard_Real _(const Fun& f, const Standard_Real h2, const Standard_Real c)
				{
					const auto x0 = X(P0_10::value, h2, c);
					const auto x1 = X(P1_10::value, h2, c);
					const auto x2 = X(P2_10::value, h2, c);
					const auto x3 = X(P3_10::value, h2, c);
					const auto x4 = X(P4_10::value, h2, c);
					const auto x5 = X(P5_10::value, h2, c);
					const auto x6 = X(P6_10::value, h2, c);
					const auto x7 = X(P7_10::value, h2, c);
					const auto x8 = X(P8_10::value, h2, c);
					const auto x9 = X(P9_10::value, h2, c);

					return
						W0_10::value*f.Value(x0) +
						W1_10::value*f.Value(x1) +
						W2_10::value*f.Value(x2) +
						W3_10::value*f.Value(x3) +
						W4_10::value*f.Value(x4) +
						W5_10::value*f.Value(x5) +
						W6_10::value*f.Value(x6) +
						W7_10::value*f.Value(x7) +
						W8_10::value*f.Value(x8) +
						W9_10::value*f.Value(x9);
				}
			};

			template<class Fun>
			struct Core<Fun, 12>
			{
				static Standard_Real _(const Fun& f, const Standard_Real h2, const Standard_Real c)
				{
					const auto x0 = X(P0_12::value, h2, c);
					const auto x1 = X(P1_12::value, h2, c);
					const auto x2 = X(P2_12::value, h2, c);
					const auto x3 = X(P3_12::value, h2, c);
					const auto x4 = X(P4_12::value, h2, c);
					const auto x5 = X(P5_12::value, h2, c);
					const auto x6 = X(P6_12::value, h2, c);
					const auto x7 = X(P7_12::value, h2, c);
					const auto x8 = X(P8_12::value, h2, c);
					const auto x9 = X(P9_12::value, h2, c);
					const auto x10 = X(P10_12::value, h2, c);
					const auto x11 = X(P11_12::value, h2, c);

					return
						W0_12::value*f.Value(x0) +
						W1_12::value*f.Value(x1) +
						W2_12::value*f.Value(x2) +
						W3_12::value*f.Value(x3) +
						W4_12::value*f.Value(x4) +
						W5_12::value*f.Value(x5) +
						W6_12::value*f.Value(x6) +
						W7_12::value*f.Value(x7) +
						W8_12::value*f.Value(x8) +
						W9_12::value*f.Value(x9) +
						W10_12::value*f.Value(x10) +
						W11_12::value*f.Value(x11);
				}
			};

			template<class Fun>
			struct Core<Fun, 14>
			{
				static Standard_Real _(const Fun& f, const Standard_Real h2, const Standard_Real c)
				{
					const auto x0 = X(P0_14::value, h2, c);
					const auto x1 = X(P1_14::value, h2, c);
					const auto x2 = X(P2_14::value, h2, c);
					const auto x3 = X(P3_14::value, h2, c);
					const auto x4 = X(P4_14::value, h2, c);
					const auto x5 = X(P5_14::value, h2, c);
					const auto x6 = X(P6_14::value, h2, c);
					const auto x7 = X(P7_14::value, h2, c);
					const auto x8 = X(P8_14::value, h2, c);
					const auto x9 = X(P9_14::value, h2, c);
					const auto x10 = X(P10_14::value, h2, c);
					const auto x11 = X(P11_14::value, h2, c);
					const auto x12 = X(P12_14::value, h2, c);
					const auto x13 = X(P13_14::value, h2, c);

					return
						W0_14::value*f.Value(x0) +
						W1_14::value*f.Value(x1) +
						W2_14::value*f.Value(x2) +
						W3_14::value*f.Value(x3) +
						W4_14::value*f.Value(x4) +
						W5_14::value*f.Value(x5) +
						W6_14::value*f.Value(x6) +
						W7_14::value*f.Value(x7) +
						W8_14::value*f.Value(x8) +
						W9_14::value*f.Value(x9) +
						W10_14::value*f.Value(x10) +
						W11_14::value*f.Value(x11) +
						W12_14::value*f.Value(x12) +
						W13_14::value*f.Value(x13);
				}
			};

			template<class Fun>
			struct Core<Fun, 16>
			{
				static Standard_Real _(const Fun& f, const Standard_Real h2, const Standard_Real c)
				{
					const auto x0 = X(P0_16::value, h2, c);
					const auto x1 = X(P1_16::value, h2, c);
					const auto x2 = X(P2_16::value, h2, c);
					const auto x3 = X(P3_16::value, h2, c);
					const auto x4 = X(P4_16::value, h2, c);
					const auto x5 = X(P5_16::value, h2, c);
					const auto x6 = X(P6_16::value, h2, c);
					const auto x7 = X(P7_16::value, h2, c);
					const auto x8 = X(P8_16::value, h2, c);
					const auto x9 = X(P9_16::value, h2, c);
					const auto x10 = X(P10_16::value, h2, c);
					const auto x11 = X(P11_16::value, h2, c);
					const auto x12 = X(P12_16::value, h2, c);
					const auto x13 = X(P13_16::value, h2, c);
					const auto x14 = X(P14_16::value, h2, c);
					const auto x15 = X(P15_16::value, h2, c);

					return
						W0_16::value*f.Value(x0) +
						W1_16::value*f.Value(x1) +
						W2_16::value*f.Value(x2) +
						W3_16::value*f.Value(x3) +
						W4_16::value*f.Value(x4) +
						W5_16::value*f.Value(x5) +
						W6_16::value*f.Value(x6) +
						W7_16::value*f.Value(x7) +
						W8_16::value*f.Value(x8) +
						W9_16::value*f.Value(x9) +
						W10_16::value*f.Value(x10) +
						W11_16::value*f.Value(x11) +
						W12_16::value*f.Value(x12) +
						W13_16::value*f.Value(x13) +
						W14_16::value*f.Value(x14) +
						W15_16::value*f.Value(x15);
				}
			};

			template<class Fun>
			struct Core<Fun, 18>
			{
				static Standard_Real _(const Fun& f, const Standard_Real h2, const Standard_Real c)
				{
					const auto x0 = X(P0_18::value, h2, c);
					const auto x1 = X(P1_18::value, h2, c);
					const auto x2 = X(P2_18::value, h2, c);
					const auto x3 = X(P3_18::value, h2, c);
					const auto x4 = X(P4_18::value, h2, c);
					const auto x5 = X(P5_18::value, h2, c);
					const auto x6 = X(P6_18::value, h2, c);
					const auto x7 = X(P7_18::value, h2, c);
					const auto x8 = X(P8_18::value, h2, c);
					const auto x9 = X(P9_18::value, h2, c);
					const auto x10 = X(P10_18::value, h2, c);
					const auto x11 = X(P11_18::value, h2, c);
					const auto x12 = X(P12_18::value, h2, c);
					const auto x13 = X(P13_18::value, h2, c);
					const auto x14 = X(P14_18::value, h2, c);
					const auto x15 = X(P15_18::value, h2, c);
					const auto x16 = X(P16_18::value, h2, c);
					const auto x17 = X(P17_18::value, h2, c);

					return
						W0_18::value*f.Value(x0) +
						W1_18::value*f.Value(x1) +
						W2_18::value*f.Value(x2) +
						W3_18::value*f.Value(x3) +
						W4_18::value*f.Value(x4) +
						W5_18::value*f.Value(x5) +
						W6_18::value*f.Value(x6) +
						W7_18::value*f.Value(x7) +
						W8_18::value*f.Value(x8) +
						W9_18::value*f.Value(x9) +
						W10_18::value*f.Value(x10) +
						W11_18::value*f.Value(x11) +
						W12_18::value*f.Value(x12) +
						W13_18::value*f.Value(x13) +
						W14_18::value*f.Value(x14) +
						W15_18::value*f.Value(x15) +
						W16_18::value*f.Value(x16) +
						W17_18::value*f.Value(x17);
				}
			};

			template<class Fun>
			struct Core<Fun, 20>
			{
				static Standard_Real _(const Fun& f, const Standard_Real h2, const Standard_Real c)
				{
					const auto x0 = X(P0_20::value, h2, c);
					const auto x1 = X(P1_20::value, h2, c);
					const auto x2 = X(P2_20::value, h2, c);
					const auto x3 = X(P3_20::value, h2, c);
					const auto x4 = X(P4_20::value, h2, c);
					const auto x5 = X(P5_20::value, h2, c);
					const auto x6 = X(P6_20::value, h2, c);
					const auto x7 = X(P7_20::value, h2, c);
					const auto x8 = X(P8_20::value, h2, c);
					const auto x9 = X(P9_20::value, h2, c);
					const auto x10 = X(P10_20::value, h2, c);
					const auto x11 = X(P11_20::value, h2, c);
					const auto x12 = X(P12_20::value, h2, c);
					const auto x13 = X(P13_20::value, h2, c);
					const auto x14 = X(P14_20::value, h2, c);
					const auto x15 = X(P15_20::value, h2, c);
					const auto x16 = X(P16_20::value, h2, c);
					const auto x17 = X(P17_20::value, h2, c);
					const auto x18 = X(P18_20::value, h2, c);
					const auto x19 = X(P19_20::value, h2, c);

					return
						W0_20::value*f.Value(x0) +
						W1_20::value*f.Value(x1) +
						W2_20::value*f.Value(x2) +
						W3_20::value*f.Value(x3) +
						W4_20::value*f.Value(x4) +
						W5_20::value*f.Value(x5) +
						W6_20::value*f.Value(x6) +
						W7_20::value*f.Value(x7) +
						W8_20::value*f.Value(x8) +
						W9_20::value*f.Value(x9) +
						W10_20::value*f.Value(x10) +
						W11_20::value*f.Value(x11) +
						W12_20::value*f.Value(x12) +
						W13_20::value*f.Value(x13) +
						W14_20::value*f.Value(x14) +
						W15_20::value*f.Value(x15) +
						W16_20::value*f.Value(x16) +
						W17_20::value*f.Value(x17) +
						W18_20::value*f.Value(x18) +
						W19_20::value*f.Value(x19);
				}
			};
		}
	}
}

#endif // !_NumAlg_GaussQuadrature_Core_Header
