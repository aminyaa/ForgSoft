#pragma once
#ifndef _DiagTensorN_Header
#define _DiagTensorN_Header

#include <VectorSpace.hxx>

namespace AutLib
{

	template <class Cmpt, int length>
	class SphericalTensorN;

	template <class Cmpt, int length>
	class DiagTensorN
		: public VectorSpace<DiagTensorN<Cmpt, length>, Cmpt, length>
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
		static const DiagTensorN zero;
		static const DiagTensorN one;
		static const DiagTensorN I;


		// Constructors

		//- Construct null
		DiagTensorN();

		//- Construct given VectorSpace
		DiagTensorN(const VectorSpace<DiagTensorN<Cmpt, length>, Cmpt, length>&);

		//- Construct from Istream
		DiagTensorN(Istream&);

		//- Construct given component value.  Special use only!
		explicit DiagTensorN(const Cmpt& tx);


		// Member Functions

			//- Diagonal
		DiagTensorN<Cmpt, length> diag() const;

		//- Transpose
		DiagTensorN<Cmpt, length> T() const;

		// Member Operators

			//- Assign to a SphericalTensorN
		void operator=(const SphericalTensorN<Cmpt, length>&);
	};
}

#include <DiagTensorNI.hxx>

#endif // !_DiagTensorN_Header
