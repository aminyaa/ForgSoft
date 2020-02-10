#pragma once
// * * * * * * * * * * * * * * * Global Functions  * * * * * * * * * * * * * //

template<int nVars>
tnbLib::FadOne<nVars> tnbLib::mag(const FadOne<nVars>& u)
{
	FadOne<nVars> r(u.value());

	for (int i = 0; i < nVars; i++)
	{
		if (u.deriv(i) == 0)
		{
			r.deriv(i) = 0;
		}
		else
		{
			if (u.value() > 0)
			{
				r.deriv(i) = u.deriv(i);
			}
			else
			{
				r.deriv(i) = -u.deriv(i);
			}
		}
	}

	return r;
}


template<int nVars>
tnbLib::FadOne<nVars> tnbLib::sin(const FadOne<nVars>& u)
{
	FadOne<nVars> r(tnbLib::sin(u.value()));

	for (int i = 0; i < nVars; i++)
	{
		r.deriv(i) = u.deriv(i)*tnbLib::cos(u.value());
	}

	return r;
}


template<int nVars>
tnbLib::FadOne<nVars> tnbLib::asin(const FadOne<nVars>& u)
{
	const double& x = u.value();

	FadOne<nVars> r(tnbLib::asin(x));

	for (int i = 0; i < nVars; i++)
	{
		const double& d = u.deriv(i);
		r.deriv(i) = d / tnbLib::sqrt(1 - tnbLib::sqr(x));
	}

	return r;
}


template<int nVars>
tnbLib::FadOne<nVars> tnbLib::cos(const FadOne<nVars>& u)
{
	FadOne<nVars> r(tnbLib::cos(u.value()));

	for (int i = 0; i < nVars; i++)
	{
		r.deriv(i) = -u.deriv(i)*tnbLib::sin(u.value());
	}

	return r;
}


template<int nVars>
tnbLib::FadOne<nVars> tnbLib::acos(const FadOne<nVars>& u)
{
	const double& x = u.value();

	FadOne<nVars> r(tnbLib::acos(x));

	for (int i = 0; i < nVars; i++)
	{
		const double& d = u.deriv(i);
		r.deriv(i) = -d / tnbLib::sqrt(1 - tnbLib::sqr(x));
	}

	return r;
}


template<int nVars>
tnbLib::FadOne<nVars> tnbLib::tan(const FadOne<nVars>& u)
{
	FadOne<nVars> r(tnbLib::tan(u.value()));

	for (int i = 0; i < nVars; i++)
	{
		r.deriv(i) = u.deriv(i) / (tnbLib::sqr(tnbLib::cos(u.value())));
	}

	return r;
}


template<int nVars>
tnbLib::FadOne<nVars> tnbLib::atan(const FadOne<nVars>& u)
{
	const double& x = u.value();

	FadOne<nVars> r(tnbLib::atan(x));

	for (int i = 0; i < nVars; i++)
	{
		const double& d = u.deriv(i);
		r.deriv(i) = d / tnbLib::sqrt(1 + tnbLib::sqr(x));
	}

	return r;
}


template<int nVars>
tnbLib::FadOne<nVars> tnbLib::tanh(const FadOne<nVars>& u)
{
	FadOne<nVars> r(tnbLib::tanh(u.value()));

	for (int i = 0; i < nVars; i++)
	{
		r.deriv(i) = u.deriv(i)*(1 - tnbLib::sqr(tnbLib::tanh(u.value())));
	}

	return r;
}


template<int nVars>
tnbLib::FadOne<nVars> tnbLib::exp(const FadOne<nVars>& u)
{
	FadOne<nVars> r(tnbLib::exp(u.value()));

	for (int i = 0; i < nVars; i++)
	{
		r.deriv(i) = u.deriv(i)*tnbLib::exp(u.value());
	}

	return r;
}


template<int nVars>
tnbLib::FadOne<nVars> tnbLib::log(const FadOne<nVars>& u)
{
	FadOne<nVars> r(tnbLib::log(u.value()));

	for (int i = 0; i < nVars; i++)
	{
		r.deriv(i) = u.deriv(i) / u.value();
	}

	return r;
}


template<int nVars>
tnbLib::FadOne<nVars> tnbLib::sqr(const FadOne<nVars>& u)
{
	FadOne<nVars> r(tnbLib::sqr(u.value()));

	for (int i = 0; i < nVars; i++)
	{
		r.deriv(i) = 2 * u.deriv(i)*u.value();
	}

	return r;
}


template<int nVars>
tnbLib::FadOne<nVars> tnbLib::sqrt(const FadOne<nVars>& u)
{
	FadOne<nVars> r(tnbLib::sqrt(u.value()));

	for (int i = 0; i < nVars; i++)
	{
		if (u.deriv(i) > 0)
		{
			r.deriv(i) = 0.5*u.deriv(i) / tnbLib::sqrt(u.value());
		}
		else
		{
			r.deriv(i) = 0;
		}
	}

	return r;
}


template<int nVars>
tnbLib::FadOne<nVars> tnbLib::pow
(
	const FadOne<nVars>& u,
	const FadOne<nVars>& v
)
{
	FadOne<nVars> r(tnbLib::pow(u.value(), v.value()));

	for (int i = 0; i < nVars; i++)
	{
		r.deriv(i) =
			v.deriv(i)*tnbLib::log(u.value())*tnbLib::pow(u.value(), v.value())
			+ v.value()*u.deriv(i)*tnbLib::pow(u.value(), v.value() - 1);
	}

	return r;
}


template<int nVars>
tnbLib::FadOne<nVars> tnbLib::pow
(
	const FadOne<nVars>& u,
	const double v
)
{
	FadOne<nVars> r(tnbLib::pow(u.value(), v));

	for (int i = 0; i < nVars; i++)
	{
		r.deriv(i) = v * u.deriv(i)*tnbLib::pow(u.value(), v - 1);
	}

	return r;
}


template<int nVars>
tnbLib::FadOne<nVars> tnbLib::pow
(
	const double& u,
	const FadOne<nVars>& v
)
{
	FadOne<nVars> r(tnbLib::pow(u, v.value()));

	for (int i = 0; i < nVars; i++)
	{
		r.deriv(i) = v.deriv(i)*tnbLib::log(u)*tnbLib::pow(u, v.value());
	}

	return r;
}


template<int nVars>
tnbLib::label tnbLib::sign(const FadOne<nVars>& u)
{
	return (u.value() >= 0) ? 1 : -1;
}


template<int nVars>
tnbLib::label tnbLib::pos(const FadOne<nVars>& u)
{
	return (u.value() >= 0) ? 1 : 0;
}


template<int nVars>
tnbLib::label tnbLib::neg(const FadOne<nVars>& u)
{
	return (u.value() < 0) ? 1 : 0;
}


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //


// ************************************************************************* //