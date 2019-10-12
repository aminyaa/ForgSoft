#pragma once
#ifndef _TensorTemplate_Header
#define _TensorTemplate_Header

#include <VectorTemplate.hxx>

namespace AutLib
{

	template<class Cmpt>
	class SymmTensor;

	template<class Cmpt>
	class SphericalTensor;

	template<class Cmpt>
	class Tensor
		: public VectorSpace<Tensor<Cmpt>, Cmpt, 9>
	{

	public:

		//- Equivalent type of labels used for valid component indexing
		typedef Tensor<label> labelType;


		// Member constants

		enum
		{
			rank = 2 // Rank of Tensor is 2
		};


		// Static data members

		static const char* const typeName;
		static const char* componentNames[];

		static const Tensor zero;
		static const Tensor one;
		static const Tensor max;
		static const Tensor min;
		static const Tensor I;


		//- Component labeling enumeration
		enum components
		{
			XX, XY, XZ, YX, YY, YZ, ZX, ZY, ZZ
		};


		// Constructors

		//- Construct null
		Tensor();

		//- Construct given VectorSpace of the same rank
		Tensor(const VectorSpace<Tensor<Cmpt>, Cmpt, 9>&);

		//- Construct given SphericalTensor
		Tensor(const SphericalTensor<Cmpt>&);

		//- Construct given SymmTensor
		Tensor(const SymmTensor<Cmpt>&);

		//- Construct given triad
		Tensor(const Vector<Vector<Cmpt> >&);

		//- Construct given the three vector components
		Tensor
		(
			const Vector<Cmpt>& x,
			const Vector<Cmpt>& y,
			const Vector<Cmpt>& z
		);

		//- Construct given the nine components
		Tensor
		(
			const Cmpt txx, 
			const Cmpt txy, 
			const Cmpt txz,
			const Cmpt tyx, 
			const Cmpt tyy,
			const Cmpt tyz,
			const Cmpt tzx, 
			const Cmpt tzy, 
			const Cmpt tzz
		);

		//- Construct from Istream
		Tensor(Istream&);


		// Member Functions

		// Access

		const Cmpt& xx() const;
		const Cmpt& xy() const;
		const Cmpt& xz() const;
		const Cmpt& yx() const;
		const Cmpt& yy() const;
		const Cmpt& yz() const;
		const Cmpt& zx() const;
		const Cmpt& zy() const;
		const Cmpt& zz() const;

		Cmpt& xx();
		Cmpt& xy();
		Cmpt& xz();
		Cmpt& yx();
		Cmpt& yy();
		Cmpt& yz();
		Cmpt& zx();
		Cmpt& zy();
		Cmpt& zz();

		// Access vector components.
		// Note: returning const only to find out lhs usage

		Vector<Cmpt> x() const;
		Vector<Cmpt> y() const;
		Vector<Cmpt> z() const;
		Vector<Cmpt> vectorComponent(const direction) const;

		//- Return (i, j) component.  Consistency with VectorN
		const Cmpt& operator()(const direction i, const direction j) const;

		//- Return access to (i, j) component.  Consistency with VectorN
		Cmpt& operator()(const direction i, const direction j);


		//- Transpose
		Tensor<Cmpt> T() const;


		// Member Operators

		//- Assign to a SphericalTensor
		void operator=(const SphericalTensor<Cmpt>&);

		//- Assign to a SymmTensor
		void operator=(const SymmTensor<Cmpt>&);

		//- Assign to a triad
		void operator=(const Vector<Vector<Cmpt> >&);
	};

	template<class Cmpt>
	class typeOfRank<Cmpt, 2>
	{
	public:

		typedef Tensor<Cmpt> type;
	};
}

#include <TensorTemplateI.hxx>

#endif // !_TensorTemplate_Header
