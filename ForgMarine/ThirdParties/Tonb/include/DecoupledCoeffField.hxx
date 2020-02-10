#pragma once
#ifndef _DecoupledCoeffField_Header
#define _DecoupledCoeffField_Header

#include <VectorSpace.hxx>
#include <primitiveFields.hxx>
#include <blockCoeffs.hxx>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace tnbLib
{

	// * * * * * * Forward declaration of template friend fuctions * * * * * * * //

	template<class Type>
	class DecoupledCoeffField;

	template<class Type>
	Ostream& operator<<(Ostream&, const DecoupledCoeffField<Type>&);

	template<class Type>
	Ostream& operator<<(Ostream&, const tmp<DecoupledCoeffField<Type> >&);


	/*---------------------------------------------------------------------------*\
							  Class DecoupledCoeffField Declaration
	\*---------------------------------------------------------------------------*/

	template<class Type>
	class DecoupledCoeffField
		:
		public refCount
	{
	public:

		// Public data types

			//- Component type
		typedef typename BlockCoeff<Type>::scalarType scalarType;
		typedef typename BlockCoeff<Type>::linearType linearType;

		//- Field type
		typedef typename BlockCoeff<Type>::scalarTypeField scalarTypeField;
		typedef typename BlockCoeff<Type>::linearTypeField linearTypeField;


	private:

		// Private data

			//- Scalar coefficient
		mutable scalarTypeField* scalarCoeffPtr_;

		//- Linear coefficient
		mutable linearTypeField* linearCoeffPtr_;

		//- Number of elements
		label size_;


		// Private Member Functions

			//- Check size for arithmetic operations: resizing is not allowed!
		template<class Type2>
		inline void checkSize(const UList<Type2>&) const;

		//- Promote to scalar
		scalarTypeField& toScalar();

		//- Promote to linear
		linearTypeField& toLinear();


	public:

		// Static data members

		static const char* const typeName;


		// Constructors

			//- Construct given size
		explicit DecoupledCoeffField(const label);

		//- Construct as copy
		DecoupledCoeffField(const DecoupledCoeffField<Type>&);

		//- Construct from Istream
		explicit DecoupledCoeffField(Istream&);

		//- Clone
		tmp<DecoupledCoeffField<Type> > clone() const;


		// Destructor

		~DecoupledCoeffField();

		//- Clear data
		void clear();


		// Member functions

			//- Return size
		inline label size() const;

		//- Return active type
		blockCoeffBase::activeLevel activeType() const;

		//- Check pointers: only one type should be active (debug only)
		void checkActive() const;

		//- Negate this field
		void negate();

		//- Return the field transpose
		tmp<DecoupledCoeffField<Type> > transpose() const;


		// Return as typed.  Fails when asked for the incorrect type

			//- Return as scalar field
		const scalarTypeField& asScalar() const;

		//- Return as linear field
		const linearTypeField& asLinear() const;


		// Return as typed.  Fails when asked for demotion

			//- Return as scalar field
		scalarTypeField& asScalar();

		//- Return as linear field
		linearTypeField& asLinear();


		//- Return component
		tmp<scalarTypeField> component(const direction) const;

		//- Return coefficient as block
		BlockCoeff<Type> getCoeff(const label index) const;

		//- Set coefficient from a block
		void setCoeff(const label index, const BlockCoeff<Type>& coeff);


		// Subset operations

			//- Get subset with offset and size and store in given field
		void getSubset
		(
			DecoupledCoeffField<Type>& f,
			const label start,
			const label size
		) const;

		//- Get subset with addressing and store in given field
		void getSubset
		(
			DecoupledCoeffField<Type>& f,
			const labelList& addr
		) const;


		//- Set subset with offset and size from given field
		void setSubset
		(
			const DecoupledCoeffField<Type>& f,
			const label start,
			const label size
		);

		//- Get subset with addressing and store in target field
		void setSubset
		(
			const DecoupledCoeffField<Type>& f,
			const labelList& addr
		);

		//- Zero out subset with offset and size
		void zeroOutSubset
		(
			const label start,
			const label size
		);

		//- Zero out subset with addressing
		void zeroOutSubset
		(
			const labelList& addr
		);

		//- Add subset with addressing to field
		void addSubset
		(
			const DecoupledCoeffField<Type>& f,
			const labelList& addr
		);


		// Member operators

		void operator=(const DecoupledCoeffField<Type>&);
		void operator=(const tmp<DecoupledCoeffField<Type> >&);

		void operator=(const scalarTypeField&);
		void operator=(const tmp<scalarTypeField>&);
		void operator=(const linearTypeField&);
		void operator=(const tmp<linearTypeField>&);


		void operator+=(const DecoupledCoeffField<Type>&);
		void operator+=(const tmp<DecoupledCoeffField<Type> >&);

		void operator+=(const scalarTypeField&);
		void operator+=(const tmp<scalarTypeField>&);
		void operator+=(const linearTypeField&);
		void operator+=(const tmp<linearTypeField>&);

		void operator-=(const DecoupledCoeffField<Type>&);
		void operator-=(const tmp<DecoupledCoeffField<Type> >&);

		void operator-=(const scalarTypeField&);
		void operator-=(const tmp<scalarTypeField>&);
		void operator-=(const linearTypeField&);
		void operator-=(const tmp<linearTypeField>&);

		void operator*=(const UList<scalar>&);
		void operator*=(const tmp<Field<scalar> >&);
		void operator*=(const scalar&);

		void operator/=(const UList<scalar>&);
		void operator/=(const tmp<Field<scalar> >&);
		void operator/=(const scalar&);


		// IOstream operators

		friend Ostream& operator<< <Type>
			(
				Ostream&,
				const DecoupledCoeffField<Type>&
				);

		friend Ostream& operator<< <Type>
			(
				Ostream&,
				const tmp<DecoupledCoeffField<Type> >&
				);
	};


	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace tnbLib

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#include <DecoupledCoeffFieldFunctions.hxx>

#ifdef NoRepository
#   include <DecoupledCoeffField.cxx>
#endif

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif // !_DecoupledCoeffField_Header
