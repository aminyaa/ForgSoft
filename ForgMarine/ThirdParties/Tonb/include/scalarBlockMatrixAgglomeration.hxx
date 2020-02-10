#pragma once
#ifndef _scalarBlockMatrixAgglomeration_Header
#define _scalarBlockMatrixAgglomeration_Header

#include <blockMatrixCoarsenings.hxx>
#include <BlockMatrixAgglomeration.hxx>
#include <blockMatrixAgglomerations.hxx>
#include <runTimeSelectionTables.hxx>
#include <scalarBlockLduMatrix.hxx>
#include <scalarBlockConstraint.hxx>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace tnbLib
{

	// * * * * * * Forward declaration of template friend fuctions * * * * * * * //


	/*---------------------------------------------------------------------------*\
							Class BlockMatrixAgglomeration Declaration
	\*---------------------------------------------------------------------------*/

	//- Restrict matrix

	template<>
	inline autoPtr<BlockAMGLevel<scalar>>
		BlockMatrixAgglomeration<scalar>::restrictMatrix() const
	{
		FatalErrorIn
		(
			"autoPtr<BlockAMGLevel<scalar> > "
			"BlockMatrixAgglomeration<Type>::restrictMatrix() const"
		) << "Function not implemented for Type=scalar. " << endl
			<< abort(FatalError);

		// Dummy return to keep compiler happy
		return autoPtr<BlockAMGLevel<scalar> >(NULL);
	}


	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace tnbLib

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif // !_scalarBlockMatrixAgglomeration_Header
