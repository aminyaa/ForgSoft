#pragma once
#ifndef _SymmTensorTemplate_Header
#define _SymmTensorTemplate_Header

#include <SphericalTensorTemplate.hxx>

namespace AutLib
{

	template<class Cmpt>
	class Tensor;

	template<class Cmpt>
	class SymmTensor
		: public VectorSpace<SymmTensor<Cmpt>, Cmpt, 6>
	{

	public:

		//- Equivalent type of labels used for valid component indexing
		typedef SymmTensor<label> labelType;


		// Member constants

		enum
		{
			rank = 2 // Rank of SymmTensor is 2
		};


		// Static data members

		static const char* const typeName;
		static const char* componentNames[];

		static const SymmTensor zero;
		static const SymmTensor one;
		static const SymmTensor max;
		static const SymmTensor min;
		static const SymmTensor I;


		//- Component labeling enumeration
		enum components
		{
			XX, XY, XZ, YY, YZ, ZZ
		};


		// Constructors

		//- Construct null
		SymmTensor();

		//- Construct given VectorSpace
		SymmTensor(const VectorSpace<SymmTensor<Cmpt>, Cmpt, 6>&);

		//- Construct given SphericalTensor
		SymmTensor(const SphericalTensor<Cmpt>&);

		//- Construct given the six components
		SymmTensor
		(
			const Cmpt txx, 
			const Cmpt txy,
			const Cmpt txz,
			const Cmpt tyy, 
			const Cmpt tyz,
			const Cmpt tzz
		);

		//- Construct from Istream
		SymmTensor(Istream&);


		// Member Functions

		// Access

		const Cmpt& xx() const;
		const Cmpt& xy() const;
		const Cmpt& xz() const;
		const Cmpt& yy() const;
		const Cmpt& yz() const;
		const Cmpt& zz() const;

		Cmpt& xx();
		Cmpt& xy();
		Cmpt& xz();
		Cmpt& yy();
		Cmpt& yz();
		Cmpt& zz();

		//- Transpose
		const SymmTensor<Cmpt>& T() const;


		// Member Operators

		//- Construct given SphericalTensor
		void operator=(const SphericalTensor<Cmpt>&);
	};

	template<class Cmpt>
	class symmTypeOfRank<Cmpt, 2>
	{
	public:

		typedef SymmTensor<Cmpt> type;
	};

	template<class Cmpt>
	Tensor<Cmpt> operator&(const SymmTensor<Cmpt>& st1, const SymmTensor<Cmpt>& st2);
}

#include <SymmTensorTemplateI.hxx>

#endif // !_SymmTensorTemplate_Header
