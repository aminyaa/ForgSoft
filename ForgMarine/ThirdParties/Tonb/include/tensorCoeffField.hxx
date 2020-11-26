#pragma once
#ifndef _tensorCoeffField_Header
#define _tensorCoeffField_Header

#include <CoeffField.hxx>
#include <DecoupledCoeffField.hxx>
#include <tensor.hxx>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace tnbLib
{

	template<>
	class CoeffField<tensor>
		:
		public DecoupledCoeffField<tensor>
	{
	public:

		// Constructors

			//- Construct given size
		explicit CoeffField(const label);

		//- Construct as copy
		CoeffField(const CoeffField<tensor>&);

		//- Construct as copy of base
		explicit CoeffField(const DecoupledCoeffField<tensor>&);

		//- Construct as copy of base
		explicit CoeffField(const tmp<DecoupledCoeffField<tensor> >&);

		//- Construct from Istream
		explicit CoeffField(Istream&);


		// Member operators

		void operator=(const CoeffField<tensor>&);
		void operator=(const tmp<CoeffField<tensor> >&);

		void operator=(const scalarTypeField&);
		void operator=(const tmp<scalarTypeField>&);
		void operator=(const linearTypeField&);
		void operator=(const tmp<linearTypeField>&);


		// IOstream operators

		friend Ostream& operator<<
			(
				Ostream&,
				const CoeffField<tensor>&
				);

		friend Ostream& operator<<
			(
				Ostream&,
				const tmp<CoeffField<tensor> >&
				);
	};


	/* * * * * * * * * * * * * * * * Global functions  * * * * * * * * * * * * * */

	template<>
	tmp<CoeffField<tensor> > inv(const CoeffField<tensor>& f);

	template<>
	void multiply
	(
		Field<tensor>& f,
		const CoeffField<tensor>& f1,
		const tensor& f2
	);

	template<>
	void multiply
	(
		Field<tensor>& f,
		const CoeffField<tensor>& f1,
		const Field<tensor>& f2
	);

	template<>
	void multiply
	(
		Field<tensor>& f,
		const Field<tensor>& f1,
		const CoeffField<tensor>& f2
	);


	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace tnbLib

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif // !_tensorCoeffField_Header
