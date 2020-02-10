#pragma once
#ifndef _tensorBlockMatrixAgglomeration_Header
#define _tensorBlockMatrixAgglomeration_Header

#include <blockMatrixCoarsenings.hxx>
#include <blockMatrixAgglomerations.hxx>
#include <BlockMatrixAgglomeration.hxx>
#include <runTimeSelectionTables.hxx>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace tnbLib
{

	/*---------------------------------------------------------------------------*\
					   Class BlockMatrixAgglomeration Declaration
	\*---------------------------------------------------------------------------*/

	//- Restrict matrix

	template<>
	inline autoPtr<BlockAMGLevel<tensor> >
		BlockMatrixAgglomeration<tensor>::restrictMatrix
		() const
	{
		FatalErrorIn
		(
			"autoPtr<BlockAMGLevel<tensor> > "
			"BlockMatrixAgglomeration<Type>::"
			"restrictMatrix() const"
		) << "Function not implemented for Type=tensor. " << endl
			<< abort(FatalError);

		// Dummy return to keep compiler happy
		return autoPtr<BlockAMGLevel<tensor> >(NULL);
	}



	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace tnbLib

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif // !_tensorBlockMatrixAgglomeration_Header
