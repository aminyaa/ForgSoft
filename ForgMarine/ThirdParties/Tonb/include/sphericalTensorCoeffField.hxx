#pragma once
#ifndef _sphericalTensorCoeffField_Header
#define _sphericalTensorCoeffField_Header

#include <CoeffField.hxx>
#include <DecoupledCoeffField.hxx>
#include <sphericalTensor.hxx>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace tnbLib
{

	template<>
	class CoeffField<sphericalTensor>
		:
		public DecoupledCoeffField<sphericalTensor>
	{
	public:

		// Constructors

			//- Construct given size
		explicit CoeffField(const label);

		//- Construct as copy
		CoeffField(const CoeffField<sphericalTensor>&);

		//- Construct as copy of base
		explicit CoeffField(const DecoupledCoeffField<sphericalTensor>&);

		//- Construct as copy of base
		explicit CoeffField(const tmp<DecoupledCoeffField<sphericalTensor> >&);

		//- Construct from Istream
		explicit CoeffField(Istream&);


		// Member operators

		void operator=(const CoeffField<sphericalTensor>&);
		void operator=(const tmp<CoeffField<sphericalTensor> >&);

		void operator=(const scalarTypeField&);
		void operator=(const tmp<scalarTypeField>&);
		void operator=(const linearTypeField&);
		void operator=(const tmp<linearTypeField>&);


		// IOstream operators

		friend Ostream& operator<<
			(
				Ostream&,
				const CoeffField<sphericalTensor>&
				);

		friend Ostream& operator<<
			(
				Ostream&,
				const tmp<CoeffField<sphericalTensor> >&
				);
	};


	/* * * * * * * * * * * * * * * * Global functions  * * * * * * * * * * * * * */

	tmp<CoeffField<sphericalTensor> > inv(const CoeffField<sphericalTensor>& f);

	template<>
	void multiply
	(
		Field<sphericalTensor>& f,
		const CoeffField<sphericalTensor>& f1,
		const sphericalTensor& f2
	);

	template<>
	void multiply
	(
		Field<sphericalTensor>& f,
		const CoeffField<sphericalTensor>& f1,
		const Field<sphericalTensor>& f2
	);

	template<>
	void multiply
	(
		Field<sphericalTensor>& f,
		const Field<sphericalTensor>& f1,
		const CoeffField<sphericalTensor>& f2
	);


	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace tnbLib

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif // !_sphericalTensorCoeffField_Header
