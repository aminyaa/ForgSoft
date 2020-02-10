#pragma once
#ifndef _symmTensor4thOrderBlockCoeff_Header
#define _symmTensor4thOrderBlockCoeff_Header

#include <BlockCoeff.hxx>
#include <DecoupledBlockCoeff.hxx>
#include <symmTensor4thOrder.hxx>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace tnbLib
{

	/*---------------------------------------------------------------------------*\
							  Class BlockCoeff Declaration
	\*---------------------------------------------------------------------------*/

	template<>
	class BlockCoeff<symmTensor4thOrder>
		: public DecoupledBlockCoeff<symmTensor4thOrder>
	{
	public:

		// Constructors

			//- Construct null
		explicit BlockCoeff();

		//- Construct as copy
		BlockCoeff(const BlockCoeff<symmTensor4thOrder>&);

		//- Construct from Istream
		BlockCoeff(Istream&);
	};


	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace tnbLib

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif // !_symmTensor4thOrderBlockCoeff_Header
