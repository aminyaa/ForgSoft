#pragma once
#ifndef _SphericalTensorN_Header
#define _SphericalTensorN_Header

#include <VectorN.hxx>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace tnbLib
{

	/*---------------------------------------------------------------------------*\
							   Class DiagTensor Declaration
	\*---------------------------------------------------------------------------*/

	template <class Cmpt, int length>
	class SphericalTensorN
		:
		public VectorSpace<SphericalTensorN<Cmpt, length>, Cmpt, 1>
	{

	public:

		// Member constants

		enum
		{
			rank = 2, // Rank of DiagTensor is 2
			rowLength = length
		};


		// Static data members

		static const char* const typeName;
		static const char* componentNames[];
		static const SphericalTensorN zero;
		static const SphericalTensorN one;
		static const SphericalTensorN I;


		// Constructors

			//- Construct null
		SphericalTensorN();

		//- Construct given VectorSpace
		SphericalTensorN(const VectorSpace<SphericalTensorN<Cmpt, length>, Cmpt, 1>&);

		//- Construct from Istream
		SphericalTensorN(Istream&);

		//- Construct given component value.  Special use only!
		explicit SphericalTensorN(const Cmpt& tx);


		// Member Functions

			//- Diagonal
		SphericalTensorN<Cmpt, length> diag() const;

		//- Transpose
		SphericalTensorN<Cmpt, length> T() const;
	};


	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace tnbLib

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#include <SphericalTensorNI.hxx>

#endif // !_SphericalTensorN_Header
