#pragma once
#ifndef _symmTensor4thOrderCoeffField_Header
#define _symmTensor4thOrderCoeffField_Header

#include <CoeffField.hxx>
#include <DecoupledCoeffField.hxx>
#include <symmTensor4thOrder.hxx>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace tnbLib
{

	template<>
	class CoeffField<symmTensor4thOrder>
		:
		public DecoupledCoeffField<symmTensor4thOrder>
	{
	public:

		// Constructors

			//- Construct given size
		explicit CoeffField(const label);

		//- Construct as copy
		CoeffField(const CoeffField<symmTensor4thOrder>&);

		//- Construct as copy of base
		explicit CoeffField(const DecoupledCoeffField<symmTensor4thOrder>&);

		//- Construct as copy of base
		explicit CoeffField
		(
			const tmp<DecoupledCoeffField<symmTensor4thOrder> >&
		);

		//- Construct from Istream
		explicit CoeffField(Istream&);


		// Member operators

		void operator=(const CoeffField<symmTensor4thOrder>&);
		void operator=(const tmp<CoeffField<symmTensor4thOrder> >&);

		void operator=(const scalarTypeField&);
		void operator=(const tmp<scalarTypeField>&);
		void operator=(const linearTypeField&);
		void operator=(const tmp<linearTypeField>&);

		// IOstream operators

		friend Ostream& operator<<
			(
				Ostream&,
				const CoeffField<symmTensor4thOrder>&
				);

		friend Ostream& operator<<
			(
				Ostream&,
				const tmp<CoeffField<symmTensor4thOrder> >&
				);
	};


	/* * * * * * * * * * * * * * * * Global functions  * * * * * * * * * * * * * */

	tmp<CoeffField<symmTensor4thOrder> >
		inv(const CoeffField<symmTensor4thOrder>& f);

	template<>
	void multiply
	(
		Field<symmTensor4thOrder>& f,
		const CoeffField<symmTensor4thOrder>& f1,
		const symmTensor4thOrder& f2
	);

	template<>
	void multiply
	(
		Field<symmTensor4thOrder>& f,
		const CoeffField<symmTensor4thOrder>& f1,
		const Field<symmTensor4thOrder>& f2
	);

	template<>
	void multiply
	(
		Field<symmTensor4thOrder>& f,
		const Field<symmTensor4thOrder>& f1,
		const CoeffField<symmTensor4thOrder>& f2
	);


	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace tnbLib

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif // !_symmTensor4thOrderCoeffField_Header
