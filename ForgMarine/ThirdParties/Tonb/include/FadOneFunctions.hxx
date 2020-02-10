#pragma once
// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace tnbLib
{

	/* * * * * * * * * * * * * * * * Global Functions  * * * * * * * * * * * * * */

	// Return a string representation of a FadOne
	template<int nVars>
	word name(const FadOne<nVars>&);


	// Allow binary writing for arrays of complex
	template<int nVars>
	bool writeBinary(const FadOne<nVars>*)
	{
		return true;
	}


	template<int nVars>
	const FadOne<nVars>& max
	(
		const FadOne<nVars>&,
		const FadOne<nVars>&
	);

	template<int nVars>
	const FadOne<nVars>& min
	(
		const FadOne<nVars>&,
		const FadOne<nVars>&
	);

	template<int nVars>
	FadOne<nVars> limit
	(
		const FadOne<nVars>&,
		const FadOne<nVars>&
	);


	template<int nVars>
	FadOne<nVars>& setComponent(FadOne<nVars>& u, const direction)
	{
		return u;
	}

	template<int nVars>
	FadOne<nVars> component(const FadOne<nVars>& u, const direction)
	{
		return u;
	}

	template<int nVars>
	FadOne<nVars> mag(const FadOne<nVars>& u);

	template<int nVars>
	FadOne<nVars> sin(const FadOne<nVars>& u);

	template<int nVars>
	FadOne<nVars> asin(const FadOne<nVars>& u);

	template<int nVars>
	FadOne<nVars> cos(const FadOne<nVars>& u);

	template<int nVars>
	FadOne<nVars> acos(const FadOne<nVars>& u);

	template<int nVars>
	FadOne<nVars> tan(const FadOne<nVars>& u);

	template<int nVars>
	FadOne<nVars> atan(const FadOne<nVars>& u);

	template<int nVars>
	FadOne<nVars> tanh(const FadOne<nVars>& u);

	template<int nVars>
	FadOne<nVars> exp(const FadOne<nVars>& u);

	template<int nVars>
	FadOne<nVars> log(const FadOne<nVars>& u);

	template<int nVars>
	FadOne<nVars> sqr(const FadOne<nVars>& u);

	template<int nVars>
	FadOne<nVars> sqrt(const FadOne<nVars>& u);

	template<int nVars>
	FadOne<nVars> pow
	(
		const FadOne<nVars>&,
		const FadOne<nVars>&
	);

	template<int nVars>
	FadOne<nVars> pow
	(
		const FadOne<nVars>&,
		const double
	);

	template<int nVars>
	FadOne<nVars> pow
	(
		const double&,
		const FadOne<nVars>&
	);

	template<int nVars>
	label sign(const FadOne<nVars>& u);

	template<int nVars>
	label pos(const FadOne<nVars>& u);

	template<int nVars>
	label neg(const FadOne<nVars>& u);


	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace tnbLib

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //