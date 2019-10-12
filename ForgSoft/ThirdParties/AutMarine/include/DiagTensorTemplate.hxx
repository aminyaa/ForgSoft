#pragma once
#ifndef _DiagTensorTemplate_Header
#define _DiagTensorTemplate_Header

#include <VectorSpace.hxx>

namespace AutLib
{

	template <class Cmpt>
	class DiagTensor
		: public VectorSpace<DiagTensor<Cmpt>, Cmpt, 3>
	{

	public:

		// Member constants

		enum
		{
			rank = 2 // Rank of DiagTensor is 2
		};


		// Static data members

		static const char* const typeName;
		static const char* componentNames[];
		static const DiagTensor zero;
		static const DiagTensor one;
		static const DiagTensor max;
		static const DiagTensor min;


		//- Component labeling enumeration
		enum components { XX, YY, ZZ };


		// Constructors

		//- Construct null
		DiagTensor();

		//- Construct given VectorSpace
		DiagTensor(const VectorSpace<DiagTensor<Cmpt>, Cmpt, 3>&);

		//- Construct given three components
		DiagTensor(const Cmpt& txx, const Cmpt& tyy, const Cmpt& tzz);

		//- Construct from Istream
		DiagTensor(Istream&);


		// Member Functions

		// Access

		const Cmpt& xx() const;
		const Cmpt& yy() const;
		const Cmpt& zz() const;

		Cmpt& xx();
		Cmpt& yy();
		Cmpt& zz();
	};
}

#include <DiagTensorTemplateI.hxx>

#endif // !_DiagTensorTemplate_Header
