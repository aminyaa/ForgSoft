#pragma once
#ifndef _procLduMatrix_Header
#define _procLduMatrix_Header

#include <labelList.hxx>
#include <scalarField.hxx>
#include <FieldField.hxx>
#include <lduInterfaceFieldPtrsList.hxx>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace tnbLib
{

	class procLduInterface;
	class lduMatrix;

	// Forward declaration of friend functions and operators

	class procLduMatrix;

	Ostream& operator<<(Ostream&, const procLduMatrix&);


	/*---------------------------------------------------------------------------*\
							   Class procLduMatrix Declaration
	\*---------------------------------------------------------------------------*/

	class procLduMatrix
	{
		// Private data

		labelList upperAddr_;
		labelList lowerAddr_;
		scalarField diag_;
		scalarField upper_;
		scalarField lower_;
		PtrList<procLduInterface> interfaces_;


		// Private member functions

			//- Dissallow construction as copy
		procLduMatrix(const procLduMatrix&);


	public:

		friend class LUscalarMatrix;


		// Constructors

		procLduMatrix
		(
			const lduMatrix& ldum,
			const FieldField<Field, scalar>& interfaceCoeffs,
			const lduInterfaceFieldPtrsList& interfaces
		);

		procLduMatrix(Istream& is);


		// Member functions

		label size() const
		{
			return diag_.size();
		}


		// Ostream operator

		friend Ostream& operator<<(Ostream&, const procLduMatrix&);
	};


	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace tnbLib

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif // !_procLduMatrix_Header
