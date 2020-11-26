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
	BlockCoeffComponentNorm

Description
	Class for BlockCoeff norm based on a specified component.

Author
	Klas Jareteg, 2013-03-07

SourceFiles
	BlockCoeffComponentNorm.C

\*---------------------------------------------------------------------------*/
#ifndef _BlockCoeffComponentNorm_Header
#define _BlockCoeffComponentNorm_Header

#include <blockCoeffs.hxx>
#include <blockCoeffNorms.hxx>
#include <BlockCoeffNorm.hxx>
#include <CoeffField.hxx>
#include <runTimeSelectionTables.hxx>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace tnbLib
{

	// * * * * * * Forward declaration of template friend fuctions * * * * * * * //


	/*---------------------------------------------------------------------------*\
							Class BlockCoeffComponentNorm Declaration
	\*---------------------------------------------------------------------------*/

	template<class Type>
	class BlockCoeffComponentNorm
		:
		public BlockCoeffNorm<Type>
	{
		// Private data

			//- Control data dictionary
		dictionary dict_;

		//- Component from which the norm is determined
		const direction cmpt_;


	protected:

		// Protected Member Functions

			//- Return dictionary
		const dictionary& dict() const
		{
			return dict_;
		}


	public:

		//- Runtime type information
		TypeName("componentNorm");


		// Constructors

			//- Construct from dictionary
		BlockCoeffComponentNorm
		(
			const dictionary& dict
		);

		// Destructor

		virtual ~BlockCoeffComponentNorm()
		{}


		// Member functions

			//- Solve
		virtual scalar normalize
		(
			const BlockCoeff<Type>& a
		);

		virtual void coeffMag
		(
			const CoeffField<Type>& a,
			Field<scalar>& b
		);
	};


	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace tnbLib

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#ifdef NoRepository
#   include <BlockCoeffComponentNorm.cxx>
#endif

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif // !_BlockCoeffComponentNorm_Header
