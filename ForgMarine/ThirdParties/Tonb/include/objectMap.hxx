#pragma once
#ifndef _objectMap_Header
#define _objectMap_Header

#include <labelList.hxx>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace tnbLib
{

	// Forward declaration of friend functions and operators

	class objectMap;
	inline bool operator==(const objectMap& a, const objectMap& b);
	inline bool operator!=(const objectMap& a, const objectMap& b);
	inline Ostream& operator<<(Ostream&, const objectMap&);
	inline Istream& operator>>(Istream&, objectMap&);


	/*---------------------------------------------------------------------------*\
							   Class objectMap Declaration
	\*---------------------------------------------------------------------------*/

	class objectMap
	{
		// Private data

			//- Object index
		label index_;

		//- Master object index
		labelList masterObjects_;


	public:

		// Constructors

			//- Null constructor for lists
		inline objectMap();

		//- Construct from components
		inline objectMap(const label index, const labelList& master);

		//- Construct from Istream
		inline objectMap(Istream&);


		// Member Functions

			//- Return object index
		inline label& index();
		inline label index() const;

		//- Return master object index
		inline labelList& masterObjects();
		inline const labelList& masterObjects() const;


		// Friend Operators

		friend bool operator==(const objectMap& a, const objectMap& b);
		friend bool operator!=(const objectMap& a, const objectMap& b);


		// IOstream Operators

		friend Ostream& operator<<(Ostream&, const objectMap&);

		friend Istream& operator>>(Istream&, objectMap&);
	};


	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace tnbLib

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#include <objectMapI.hxx>

#endif // !_objectMap_Header
