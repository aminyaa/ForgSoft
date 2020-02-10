#pragma once
#ifndef _symmTensorCoeffField_Header
#define _symmTensorCoeffField_Header

#include <CoeffField.hxx>
#include <DecoupledCoeffField.hxx>
#include <symmTensor.hxx>


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace tnbLib
{

	template<>
	class CoeffField<symmTensor>
		:
		public DecoupledCoeffField<symmTensor>
	{
	public:

		// Constructors

			//- Construct given size
		explicit CoeffField(const label);

		//- Construct as copy
		CoeffField(const CoeffField<symmTensor>&);

		//- Construct as copy of base
		explicit CoeffField(const DecoupledCoeffField<symmTensor>&);

		//- Construct as copy of base
		explicit CoeffField(const tmp<DecoupledCoeffField<symmTensor> >&);

		//- Construct from Istream
		explicit CoeffField(Istream&);


		// Member operators

		void operator=(const CoeffField<symmTensor>&);
		void operator=(const tmp<CoeffField<symmTensor> >&);

		void operator=(const scalarTypeField&);
		void operator=(const tmp<scalarTypeField>&);
		void operator=(const linearTypeField&);
		void operator=(const tmp<linearTypeField>&);

		// IOstream operators

		friend Ostream& operator<<
			(
				Ostream&,
				const CoeffField<symmTensor>&
				);

		friend Ostream& operator<<
			(
				Ostream&,
				const tmp<CoeffField<symmTensor> >&
				);
	};


	/* * * * * * * * * * * * * * * * Global functions  * * * * * * * * * * * * * */

	tmp<CoeffField<symmTensor> > inv(const CoeffField<symmTensor>& f);

	template<>
	void multiply
	(
		Field<symmTensor>& f,
		const CoeffField<symmTensor>& f1,
		const symmTensor& f2
	);

	template<>
	void multiply
	(
		Field<symmTensor>& f,
		const CoeffField<symmTensor>& f1,
		const Field<symmTensor>& f2
	);

	template<>
	void multiply
	(
		Field<symmTensor>& f,
		const Field<symmTensor>& f1,
		const CoeffField<symmTensor>& f2
	);


	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace tnbLib

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif // !_symmTensorCoeffField_Header
