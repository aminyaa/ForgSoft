#pragma once
#ifndef _objectHit_Header
#define _objectHit_Header

#include <bool.hxx>
#include <label.hxx>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace tnbLib
{

	// Forward declaration of friend functions and operators

	class objectHit;
	inline bool operator==(const objectHit& a, const objectHit& b);
	inline bool operator!=(const objectHit& a, const objectHit& b);
	inline Ostream& operator<<(Ostream& os, const objectHit& b);


	/*---------------------------------------------------------------------------*\
							   Class objectHit Declaration
	\*---------------------------------------------------------------------------*/

	class objectHit
	{
		// Private data

			//- Hit success
		bool hit_;

		//- Object of hit
		label hitObject_;


	public:

		// Constructors

			//- Construct null
		objectHit()
			:
			hit_(false),
			hitObject_(-1)
		{}

		//- Construct from components
		objectHit(const bool success, const label& obj)
			:
			hit_(success),
			hitObject_(obj)
		{}

		//- Construct from Istream
		objectHit(Istream& is)
			:
			hit_(readBool(is)),
			hitObject_(readLabel(is))
		{}


		// Member Functions

			//- Is there a hit
		bool hit() const
		{
			return hit_;
		}

		//- Return hit object
		label hitObject() const
		{
			return hitObject_;
		}


		// Friend Operators

		friend bool operator==(const objectHit& a, const objectHit& b)
		{
			return ((a.hit_ == b.hit_) && (a.hitObject_ == b.hitObject_));
		}

		friend bool operator!=(const objectHit& a, const objectHit& b)
		{
			return (!(a == b));
		}


		// Ostream operator

		friend Ostream& operator<<(Ostream& os, const objectHit& b)
		{
			return os << b.hit() << token::SPACE << b.hitObject();
		}
	};


	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace tnbLib

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif // !_objectHit_Header
