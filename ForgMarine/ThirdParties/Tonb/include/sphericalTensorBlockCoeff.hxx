#pragma once
#ifndef _sphericalTensorBlockCoeff_Header
#define _sphericalTensorBlockCoeff_Header

#include <BlockCoeff.hxx>
#include <DecoupledBlockCoeff.hxx>
#include <sphericalTensor.hxx>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace tnbLib
{

	/*---------------------------------------------------------------------------*\
							  Class BlockCoeff Declaration
	\*---------------------------------------------------------------------------*/

	template<>
	class BlockCoeff<sphericalTensor>
		: public DecoupledBlockCoeff<sphericalTensor>
	{
	public:

		// Constructors

			//- Construct null
		explicit BlockCoeff();

		//- Construct as copy
		BlockCoeff(const BlockCoeff<sphericalTensor>&);

		//- Construct from Istream
		BlockCoeff(Istream&);
	};


	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace tnbLib

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif // !_sphericalTensorBlockCoeff_Header
