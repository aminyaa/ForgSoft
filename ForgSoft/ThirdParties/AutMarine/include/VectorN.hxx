#pragma once
#ifndef _VectorN_Header
#define _VectorN_Header

#include <VectorSpace.hxx>

namespace AutLib
{

	template <class Cmpt, int length>
	class VectorN
		: public VectorSpace<VectorN<Cmpt, length>, Cmpt, length>
	{

	public:

		// Member constants

		enum
		{
			rank = 1 // Rank of VectorN is 1
		};


		// Static data members

		static const char* const typeName;
		static const VectorN zero;
		static const VectorN one;
		static const VectorN max;
		static const VectorN min;


		// Constructors

			//- Construct null
		VectorN();

		//- Construct given VectorSpace
		VectorN(const VectorSpace<VectorN<Cmpt, length>, Cmpt, length>&);

		//- Construct given component value.  Special use only!
		explicit VectorN(const Cmpt& vx);

		//- Construct from Istream
		VectorN(Istream&);


		// Member Functions

			//- Return ith component
		const Cmpt& operator()(const direction i) const;

		//- Return access to ith component
		Cmpt& operator()(const direction i);

		//- Component-wise multiply
		VectorN<Cmpt, length> cmptMultiply(const VectorN<Cmpt, length>&);
	};
}

#include <VectorNI.hxx>

#endif // !_VectorN_Header
