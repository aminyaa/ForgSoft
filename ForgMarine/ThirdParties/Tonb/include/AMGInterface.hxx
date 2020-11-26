#pragma once
/*---------------------------------------------------------------------------*\
  =========                 |
  \\      /  F ield         | foam-extend: Open Source CFD
   \\    /   O peration     | Version:     4.0
	\\  /    A nd           | Web:         http://www.foam-extend.org
	 \\/     M anipulation  | For copyright notice see file Copyright
-------------------------------------------------------------------------------
License
	This file is part of foam-extend.

	foam-extend is free software: you can redistribute it and/or modify it
	under the terms of the GNU General Public License as published by the
	Free Software Foundation, either version 3 of the License, or (at your
	option) any later version.

	foam-extend is distributed in the hope that it will be useful, but
	WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
	General Public License for more details.

	You should have received a copy of the GNU General Public License
	along with foam-extend.  If not, see <http://www.gnu.org/licenses/>.

Class
	tnbLib::AMGInterface

Description
	Abstract base class for AMG agglomerated interfaces.

	For complex (interpolative) agglomeration, a single fine-level coefficient
	may be agglomerated into several coarse level coefficients.
	The basic functionality has been rewritten to account for this, using
	three addressing arrays and weights:
	faceCells_: contains coarse interface-to-matrix addressing

	The following three arrays are all of the same size
	fineAddressing_: contains addressing into the fine coefficient array
	restrictAddressing_: contains addressing into the coarse coefficient array
	restrictWeights_: contains restriction factor weights

Author
	Hrvoje Jasak, Wikki Ltd.  All rights reserved.

SourceFiles
	AMGInterface.C
	newAmgInterface.C

\*---------------------------------------------------------------------------*/
#ifndef _AMGInterface_Header
#define _AMGInterface_Header

#include <lduInterface.hxx>
#include <autoPtr.hxx>
#include <lduPrimitiveMesh.hxx>
#include <coeffFields.hxx>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace tnbLib
{

	/*---------------------------------------------------------------------------*\
						  Class AMGInterface Declaration
	\*---------------------------------------------------------------------------*/

	class AMGInterface
		:
		public lduInterface
	{
		// Private data

			//- Reference to ldu addressing
		const lduPrimitiveMesh& lduMesh_;


	protected:

		// Protected data

			//- Face-cell addressing.  Contains coarse level addressing
		labelField faceCells_;

		//- Fine addressing
		labelField fineAddressing_;

		//- Restrict addressing
		labelField restrictAddressing_;

		//- Fine level agglomeration weights
		scalarField restrictWeights_;


	private:

		// Private Member Functions

			//- Disallow default bitwise copy construct
		AMGInterface(const AMGInterface&);

		//- Disallow default bitwise assignment
		void operator=(const AMGInterface&);


	public:

		//- Runtime type information
		TypeName("AMGInterface");


		// Declare run-time constructor selection tables

		declareRunTimeSelectionTable
		(
			autoPtr,
			AMGInterface,
			lduInterface,
			(
				const lduPrimitiveMesh& lduMesh,
				const lduInterface& fineInterface,
				const labelField& localRestrictAddressing,
				const labelField& neighbourRestrictAddressing
				),
				(
					lduMesh,
					fineInterface,
					localRestrictAddressing,
					neighbourRestrictAddressing
					)
		);


		// Selectors

			//- Return a pointer to a new interface created on freestore given
			//  the fine interface
		static autoPtr<AMGInterface> New
		(
			const lduPrimitiveMesh& lduMesh,
			const lduInterface& fineInterface,
			const labelField& localRestrictAddressing,
			const labelField& neighbourRestrictAddressing
		);


		// Constructors

			//- Construct from fine-level interface,
			//  local and neighbour restrict addressing
		AMGInterface(const lduPrimitiveMesh& lduMesh)
			:
			lduMesh_(lduMesh)
		{}


		// Member Functions

			// Access

				//- Return reference to addressing
		const lduMesh& ldu() const
		{
			return lduMesh_;
		}

		//- Return size
		virtual label size() const
		{
			return faceCells_.size();
		}

		//- Return faceCell addressing
		virtual const unallocLabelList& faceCells() const
		{
			return faceCells_;
		}

		//- Return fine addressing
		const labelField& fineAddressing() const
		{
			return fineAddressing_;
		}

		//- Return restrict addressing
		const labelField& restrictAddressing() const
		{
			return restrictAddressing_;
		}

		//- Return fine level agglomeration weights
		const scalarField& restrictWeights() const
		{
			return restrictWeights_;
		}

		//- Return the interface internal field of the given field
		template<class Type>
		tmp<Field<Type> > interfaceInternalField
		(
			const UList<Type>& internalData
		) const;

		//- Return the values of the given internal data adjacent to
		//  the interface as a field
		virtual tmp<labelField> interfaceInternalField
		(
			const unallocLabelList& internalData
		) const;


		// Agglomeration

			//- Merge the next level with this level
			//  combining the face-restrict addressing
			//  and copying the face-cell addressing
		void combine(const AMGInterface&);

		//- Agglomerating the given fine-level coefficients and return
		virtual tmp<scalarField> agglomerateCoeffs
		(
			const scalarField& fineCoeffs
		) const;

		// Coefficient agglomeration functions for block coefficients
		// moved to BlockAMGInterfaceField to allow
		// templating on virtual functions in block matrix agglomeration
		// HJ, 16/Mar/2016
	};


	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace tnbLib

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#ifdef NoRepository
#   include <AMGInterfaceTemplates.cxx>
#endif

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif // !_AMGInterface_Header
