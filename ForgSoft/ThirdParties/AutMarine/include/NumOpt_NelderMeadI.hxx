#pragma once
namespace AutLib
{

	template<class Function>
	Standard_Real NumOpt_NelderMead<Function>::Size() const
	{
		auto norm = (Standard_Real)0.0;
		auto best = Variable(caches::Lo);
		for (int i = 0; i <= NbVariables(); i++)
		{
			//auto s = fun::SquareTwoNorm(best, Variable(i));
			auto s = (Standard_Real)0.0;
			for (int k = 1; k <= NbVariables(); k++)
			{
				auto d = fun::V(k, Variable(caches::Lo)) - fun::V(k, Variable(i));
				s += d * d;
			}
			if (s > norm) norm = s;
		}
		return sqrt(norm);
	}

	template<class Function>
	void NumOpt_NelderMead<Function>::Order()
	{
		caches::Lo = 0;
		caches::Hi = 0;
		for (int i = 1; i <= NbVariables(); i++)
		{
			if (Y(i) < Y(caches::Lo)) caches::Lo = i;
			if (Y(i) > Y(caches::Hi)) caches::Hi = i;
		}
		caches::Li = caches::Hi;
		caches::Ho = caches::Lo;

		for (int i = 0; i <= NbVariables(); i++)
		{
			if (i NOT_EQUAL caches::Lo AND Y(i) < Y(caches::Li)) caches::Li = i;
			if (i NOT_EQUAL caches::Hi AND Y(i) > Y(caches::Ho)) caches::Ho = i;
		}
	}

	template<class Function>
	void NumOpt_NelderMead<Function>::NewPoints()
	{
		for (int k = 1; k <= NbVariables(); k++)
		{
			auto s = (Standard_Real)0.0;
			for (int j = 0; j <= NbVariables(); j++)
			{
				s += fun::V(k, Variable(j));
			}
			fun::SetV(k, (s - fun::V(k, Variable(caches::Hi))) / (Standard_Real)NbVariables(), caches::M);
		}

		for (int k = 1; k <= NbVariables(); k++)
		{
			fun::SetV(k, coeff::ExpansionCoeff() * fun::V(k, caches::M) - fun::V(k, Variable(caches::Hi)), caches::R);
		}

		caches::YR = fun::Value(caches::R);
	}

	template<class Function>
	void NumOpt_NelderMead<Function>::Shrink()
	{
		for (int j = 0; j <= NbVariables(); j++)
		{
			if (j NOT_EQUAL caches::Lo)
			{
				for (int k = 1; k <= NbVariables(); k++)
				{
					fun::SetV(k, coeff::ShrinkCoeff()*(fun::V(k, Variable(j)) + fun::V(k, Variable(caches::Lo))), ChangeVariable(j));
				}
				ChangeY(j) = fun::Value(Variable(j));
			}
		}
	}

	template<class Function>
	void NumOpt_NelderMead<Function>::Replace()
	{
		auto& var = ChangeVariable(caches::Hi);
		for (int k = 1; k <= NbVariables(); k++)
		{
			fun::SetV(k, fun::V(k, caches::R), var);
		}
		ChangeY(caches::Hi) = caches::YR;
	}

	template<class Function>
	void AutLib::NumOpt_NelderMead<Function>::Improve()
	{
		if (caches::YR < Y(caches::Ho))
		{
			if (Y(caches::Li) < caches::YR)
			{
				Replace();
			}
			else
			{
				for (int k = 1; k <= NbVariables(); k++)
					fun::SetV(k, coeff::ExpansionCoeff() * fun::V(k, caches::R) - fun::V(k, caches::M), caches::E);
				caches::YE = fun::Value(caches::E);

				if (caches::YE < Y(caches::Li))
				{
					for (int k = 1; k <= NbVariables(); k++)
						fun::SetV(k, fun::V(k, caches::E), ChangeVariable(caches::Hi));
					ChangeY(caches::Hi) = caches::YE;
				}
				else
				{
					Replace();
				}
			}
		}
		else
		{
			if (caches::YR < Y(caches::Hi))
			{
				Replace();
			}

			for (int k = 1; k <= NbVariables(); k++)
				fun::SetV(k, coeff::ContractionCoeff()*(fun::V(k, Variable(caches::Hi)) + fun::V(k, caches::M)), caches::C);

			caches::YC = fun::Value(caches::C);

			if (caches::YC < Y(caches::Hi))
			{
				for (int k = 1; k <= NbVariables(); k++)
					fun::SetV(k, fun::V(k, caches::C), ChangeVariable(caches::Hi));
				ChangeY(caches::Hi) = caches::YC;
			}
			else
			{
				Shrink();
			}
		}
	}

	template<class Function>
	void NumOpt_NelderMead<Function>::Perform()
	{
		fun::Initial(theVariables_);

		for (int j = 0; j <= NbVariables(); j++)
			ChangeY(j) = fun::Value(Variable(j));

		Order();

		Standard_Integer Iter = 0;
		IsConv = Standard_False;
		/*while (Y(caches::Hi) > Y(caches::Lo) + Tolerance() AND Iter < MaxNbIterations())
		{
			NewPoints();

			Improve();

			Order();

			Iter++;
		}*/

		while (NOT fun::IsConverged() AND Iter < MaxNbIterations())
		{
			NewPoints();
			
			Improve();

			Order();

			Iter++;
		}

		if (Iter < MaxNbIterations())
		{
			IsConv = Standard_True;
		}

		//Size();
	}
}