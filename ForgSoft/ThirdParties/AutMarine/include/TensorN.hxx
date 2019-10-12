#pragma once
#ifndef _TensorN_Header
#define _TensorN_Header

#include <VectorSpace.hxx>

namespace AutLib
{

	template <class Cmpt, int length>
	class DiagTensorN;

	template <class Cmpt, int length>
	class SphericalTensorN;

	template <class Cmpt, int length>
	class TensorN
		: public VectorSpace<TensorN<Cmpt, length>, Cmpt, length*length>
	{

	public:

		// Member constants

		enum
		{
			rank = 2,            // Rank of TensorN is 2
			rowLength = length   // Number of components in a row
		};


		// Static data members

		static const char* const typeName;

		static const TensorN zero;
		static const TensorN one;


		// Constructors

		//- Construct null
		TensorN();

		//- Construct given VectorSpace
		TensorN(const VectorSpace<TensorN<Cmpt, length>, Cmpt, length*length>&);

		//- Construct given component value.  Special use only!
		explicit TensorN(const Cmpt& tx);

		//- Construct from Istream
		TensorN(Istream&);


		// Member Functions

		//- Return direction given (i, j) indices
		static direction cmpt(const direction i, const direction j);

		//- Return (i, j) component
		const Cmpt& operator()(const direction i, const direction j) const;

		//- Return access to (i, j) component
		Cmpt& operator()(const direction i, const direction j);

		//- Return diagonal
		DiagTensorN<Cmpt, length> diag() const;

		//- Return transpose
		TensorN<Cmpt, length> T() const;

		//- Negative sum the vertical off-diagonal components
		TensorN<Cmpt, length> negSumDiag() const;


		// Member Operators

		//- Assign to a SphericalTensorN
		void operator=(const SphericalTensorN<Cmpt, length>&);

		//- Assign to a DiagTensorN
		void operator=(const DiagTensorN<Cmpt, length>&);
	};
}

#include <TensorNI.hxx>

#endif // !_TensorN_Header
