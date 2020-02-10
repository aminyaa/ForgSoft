#pragma once
#ifndef _diagTensorCoeffField_Header
#define _diagTensorCoeffField_Header

#include <CoeffField.hxx>
#include <DecoupledCoeffField.hxx>
#include <diagTensor.hxx>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace tnbLib
{

	template<>
	class CoeffField<diagTensor>
		: public DecoupledCoeffField<diagTensor>
	{
	public:

		// Constructors

			//- Construct given size
		explicit CoeffField(const label);

		//- Construct as copy
		CoeffField(const CoeffField<diagTensor>&);

		//- Construct as copy of base
		explicit CoeffField(const DecoupledCoeffField<diagTensor>&);

		//- Construct as copy of base
		explicit CoeffField(const tmp<DecoupledCoeffField<diagTensor> >&);

		//- Construct from Istream
		explicit CoeffField(Istream&);


		// Member operators

		void operator=(const CoeffField<diagTensor>&);
		void operator=(const tmp<CoeffField<diagTensor> >&);

		void operator=(const scalarTypeField&);
		void operator=(const tmp<scalarTypeField>&);
		void operator=(const linearTypeField&);
		void operator=(const tmp<linearTypeField>&);

		// IOstream operators

		friend Ostream& operator<<
			(
				Ostream&,
				const CoeffField<diagTensor>&
				);

		friend Ostream& operator<<
			(
				Ostream&,
				const tmp<CoeffField<diagTensor> >&
				);
	};


	/* * * * * * * * * * * * * * * * Global functions  * * * * * * * * * * * * * */

	tmp<CoeffField<diagTensor> > inv(const CoeffField<diagTensor>& f);

	template<>
	void multiply
	(
		Field<diagTensor>& f,
		const CoeffField<diagTensor>& f1,
		const diagTensor& f2
	);

	template<>
	void multiply
	(
		Field<diagTensor>& f,
		const CoeffField<diagTensor>& f1,
		const Field<diagTensor>& f2
	);

	template<>
	void multiply
	(
		Field<diagTensor>& f,
		const Field<diagTensor>& f1,
		const CoeffField<diagTensor>& f2
	);


	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace tnbLib

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif // !_diagTensorCoeffField_Header
