#pragma once
#ifndef _patchIdentifier_Header
#define _patchIdentifier_Header

#include <word.hxx>
#include <label.hxx>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace tnbLib
{

	class dictionary;

	// Forward declaration of friend functions and operators

	class patchIdentifier;
	Ostream& operator<<(Ostream&, const patchIdentifier&);


	/*---------------------------------------------------------------------------*\
							   Class patchIdentifier Declaration
	\*---------------------------------------------------------------------------*/

	class patchIdentifier
	{
		// Private data

			//- Name of patch
		word name_;

		//- Index of patch in boundary
		label index_;

		//- Optional physical type
		mutable word physicalType_;


	public:

		// Constructors

			//- Construct from components
		patchIdentifier
		(
			const word& name,
			const label index,
			const word& physicalType = word::null
		);

		//- Construct from dictionary
		patchIdentifier
		(
			const word& name,
			const dictionary&,
			const label index
		);

		//- Construct from geometric patch, resetting the index
		patchIdentifier
		(
			const patchIdentifier&,
			const label index
		);


		// Destructor

		virtual ~patchIdentifier();


		// Member Functions

			//- Return name
		const word& name() const
		{
			return name_;
		}

		//- Return name for modification
		word& name()
		{
			return name_;
		}

		//- Return the optional physical type of the patch
		const word& physicalType() const
		{
			return physicalType_;
		}

		//- Return the optional physical type of the patch for modification
		word& physicalType()
		{
			return physicalType_;
		}

		//- Return the index of this patch in the boundaryMesh
		label index() const
		{
			return index_;
		}

		//- Return the index of this patch in the boundaryMesh for modification
		label& index()
		{
			return index_;
		}

		//- Write patchIdentifier as a dictionary
		void write(Ostream&) const;


		// Ostream Operator

		friend Ostream& operator<<(Ostream&, const patchIdentifier&);
	};


	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace tnbLib

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif // !_patchIdentifier_Header
