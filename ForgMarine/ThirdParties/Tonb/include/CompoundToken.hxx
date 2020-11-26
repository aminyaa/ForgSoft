#pragma once
#ifndef _CompoundToken_Header
#define _CompoundToken_Header

#include <refCount.hxx>
#include <typeInfo.hxx>
#include <autoPtr.hxx>
#include <runTimeSelectionTables.hxx>

namespace tnbLib
{

	// Forward declaration of friend functions and operators

	class CompoundToken;
	Ostream& operator<<(Ostream&, const CompoundToken&);


	/*---------------------------------------------------------------------------*\
							   Class CompoundToken Declaration
	\*---------------------------------------------------------------------------*/

	class CompoundToken
		:
		public refCount
	{
		// Private Member Functions

			//- Disallow default bitwise copy construct
		CompoundToken(const CompoundToken&);

		//- Disallow default bitwise assignment
		void operator=(const CompoundToken&);


	public:

		//- Runtime type information
		virtual const word& type() const = 0;


		// Declare run-time constructor selection tables

		declareRunTimeSelectionTable
		(
			autoPtr,
			CompoundToken,
			Istream,
			(const word& type, Istream& is),
			(type, is)
		);


		// Constructors

			//- Construct null
		CompoundToken()
		{}

		//- Return the clone as this and increment reference count
		virtual autoPtr<CompoundToken> clone() const = 0;


		// Selectors

			//- Select null constructed
		static autoPtr<CompoundToken> New(const word& type, Istream& is);


		// Destructor

		virtual ~CompoundToken();


		// Member Functions

			// Access

			// Check

			// Edit

			// Write

		virtual void write(Istream&) = 0;


		// IOstream Operators

		friend Ostream& operator<<(Ostream&, const CompoundToken&);
	};


	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //
}

#endif // !_CompoundToken_Header
