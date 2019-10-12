#pragma once
#ifndef _SymmTensor2DTemplate_Header
#define _SymmTensor2DTemplate_Header

#include <VectorSpace.hxx>

namespace AutLib
{

	template<class Cmpt>
	class SphericalTensor2D;

	template<class Cmpt>
	class SymmTensor2D
		: public VectorSpace<SymmTensor2D<Cmpt>, Cmpt, 3>
	{

	public:

		//- Equivalent type of labels used for valid component indexing
		typedef SymmTensor2D<label> labelType;


		// Member constants

		enum
		{
			rank = 2 // Rank of SymmTensor2D is 2
		};


		// Static data members

		static const char* const typeName;
		static const char* componentNames[];

		static const SymmTensor2D zero;
		static const SymmTensor2D one;
		static const SymmTensor2D max;
		static const SymmTensor2D min;
		static const SymmTensor2D I;


		//- Component labeling enumeration
		enum components
		{
			XX, XY, YY
		};


		// Constructors

		//- Construct null
		SymmTensor2D();

		//- Construct given VectorSpace
		SymmTensor2D(const VectorSpace<SymmTensor2D<Cmpt>, Cmpt, 3>&);

		//- Construct given SphericalTensor
		SymmTensor2D(const SphericalTensor2D<Cmpt>&);

		//- Construct given the three components
		SymmTensor2D
		(
			const Cmpt txx, 
			const Cmpt txy,
			const Cmpt tyy
		);

		//- Construct from Istream
		SymmTensor2D(Istream&);


		// Member Functions

		// Access

		const Cmpt& xx() const;
		const Cmpt& xy() const;
		const Cmpt& yy() const;

		Cmpt& xx();
		Cmpt& xy();
		Cmpt& yy();

		//- Transpose
		const SymmTensor2D<Cmpt>& T() const;


		// Member Operators

		//- Construct given SphericalTensor2D
		void operator=(const SphericalTensor2D<Cmpt>&);
	};
}

#include <SymmTensor2DTemplateI.hxx>

#endif // !_SymmTensor2DTemplate_Header
