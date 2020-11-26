#pragma once
#include <Global_Macros.hxx>
#include <error.hxx>
#include <OSstream.hxx>
namespace tnbLib
{

	template<class Function>
	void NumAlg_AdaptiveInteg_Core<Function>::Perform()
	{
		if (Upper() <= Lower())
		{
			FatalErrorIn(" void Perform()")
				<< " Invalid Integration bound" << endl
				<< " - Lower: " << Lower() << endl
				<< " - Upper: " << Upper() << endl
				<< abort(FatalError);
		}

		Change_IsDone() = Standard_True;

		auto U0 = Lower();
		auto U1 = Upper();
		auto MaxSize = MaxNbIterations() + 1;

		realList
			tol(MaxSize),
			a(MaxSize),
			h(MaxSize),
			FA(MaxSize),
			FC(MaxSize),
			FB(MaxSize),
			S(MaxSize);

		intList L(MaxSize);

		auto APP = (Standard_Real)0.;
		auto i = (Standard_Integer)1;

		tol[i] = (Standard_Real)10.0 * Tolerance();
		a[i] = U0;
		h[i] = (Standard_Real)0.5 * (U1 - U0);

		FA[i] = fun::Value(U0);
		FC[i] = fun::Value(U0 + h[i]);
		FB[i] = fun::Value(U1);

		S[i] = h[i] * (FA[i] + (Standard_Real)4.0 * FC[i] + FB[i]) / (Standard_Real)3.0;

		L[i] = 1;

		Standard_Real FD, FE, S1, S2;
		Standard_Real v1, v2, v3, v4, v5, v6, v7;
		Standard_Integer v8;
		Standard_Integer k = 0;

		Standard_Real C6 = (Standard_Real)1.0 / (Standard_Real)6.0;

		while (i > 0)
		{
			FD = fun::Value(a[i] + (Standard_Real)0.5 * h[i]);
			FE = fun::Value(a[i] + (Standard_Real)1.5 * h[i]);

			S1 = h[i] * (FA[i] + (Standard_Real)4.0 * FD + FC[i]) * C6;
			S2 = h[i] * (FC[i] + (Standard_Real)4.0 * FE + FB[i]) * C6;

			v1 = a[i];
			v2 = FA[i];
			v3 = FC[i];
			v4 = FB[i];
			v5 = h[i];
			v6 = tol[i];
			v7 = S[i];
			v8 = L[i];

			i--;

			k++;

			if (ABS(S1 + S2 - v7) < v6)
			{
				APP += (S1 + S2);
			}
			else
			{
				if (v8 >= MaxNbIterations() + 1)
				{
					Change_IsConverged() = Standard_False;
					ChangeResult() = APP;

					return;
				}
				else
				{
					i++;

					a[i] = v1 + v5;
					FA[i] = v3;
					FC[i] = FE;
					FB[i] = v4;
					h[i] = (Standard_Real)0.5 * v5;
					tol[i] = MAX((Standard_Real)0.5 * v6, 1.0E-16);
					S[i] = S2;
					L[i] = v8 + 1;

					i++;

					a[i] = v1;
					FA[i] = v2;
					FC[i] = FD;
					FB[i] = v3;
					h[i] = h[i - 1];
					tol[i] = tol[i - 1];
					S[i] = S1;
					L[i] = L[i - 1];
				}
			}
		}

		ChangeResult() = APP;
		Change_IsConverged() = Standard_True;
	}
}