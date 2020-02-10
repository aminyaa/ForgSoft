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
	tnbLib::quaternion

Description
	Quaternion class used to perform rotations in 3D space.

SourceFiles
	quaternionI.H
	quaternion.C

\*---------------------------------------------------------------------------*/
#ifndef _quaternion_Header
#define _quaternion_Header

#include <scalar.hxx>
#include <vector.hxx>
#include <tensor.hxx>
#include <word.hxx>
#include <contiguous.hxx>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace tnbLib
{

	// Forward declaration of friend functions and operators

	class quaternion;
	Istream& operator>>(Istream& is, quaternion&);
	Ostream& operator<<(Ostream& os, const quaternion& C);


	/*---------------------------------------------------------------------------*\
							   Class quaternion Declaration
	\*---------------------------------------------------------------------------*/

	class quaternion
	{
		// private data

			//- Scalar part of the quaternion ( = cos(theta/2) for rotation)
		scalar w_;

		//- Vector part of the quaternion ( = axis of rotation)
		vector v_;


		//- Multiply vector v by quaternion as if v is a pure quaternion
		quaternion mulq0v(const vector& v) const;


	public:

		// Static data members

		static const char* const typeName;

		static const quaternion zero;
		static const quaternion I;


		// Constructors

			//- Construct null
		quaternion();

		//- Construct given scalar and vector parts
		quaternion(const scalar w, const vector& v);

		//- Construct a rotation quaternion given the direction d
		//  and angle theta
		quaternion(const vector& d, const scalar theta);

		//- Construct given scalar part, the vector part = vector::zero
		explicit quaternion(const scalar w);

		//- Construct a pure quaternion given the vector part, scalar part = 0
		explicit quaternion(const vector& v);

		//- Construct a quaternion given the three Euler angles
		quaternion
		(
			const scalar angleX,
			const scalar angleY,
			const scalar angleZ
		);

		//- Construct from Istream
		quaternion(Istream&);


		// Member functions

			   // Access

				   //- Scalar part of the quaternion ( = cos(theta/2) for rotation)
		scalar w() const;

		//- Vector part of the quaternion ( = axis of rotation)
		const vector& v() const;

		//- The rotation tensor corresponding the quaternion
		tensor R() const;


		// Edit

			//- Scalar part of the quaternion ( = cos(theta/2) for rotation)
		scalar& w();

		//- Vector part of the quaternion ( = axis of rotation)
		vector& v();

		void normalize();


		// Transform

			//- Rotate the given vector
		vector transform(const vector& v) const;

		//- Rotate the given vector anti-clockwise
		vector invTransform(const vector& v) const;

		//- Rotate the given quaternion (and normalize)
		quaternion transform(const quaternion& q) const;

		//- Rotate the given quaternion anti-clockwise (and normalize)
		quaternion invTransform(const quaternion& q) const;


		// Member operators

		void operator=(const quaternion&);
		void operator+=(const quaternion&);
		void operator-=(const quaternion&);
		void operator*=(const quaternion&);
		void operator/=(const quaternion&);

		void operator=(const scalar);

		void operator=(const vector&);

		void operator*=(const scalar);
		void operator/=(const scalar);


		// IOstream operators

		friend Istream& operator>>(Istream& is, quaternion&);
		friend Ostream& operator<<(Ostream& os, const quaternion& C);
	};


	// * * * * * * * * * * * * * * * Global Functions  * * * * * * * * * * * * * //

	inline scalar magSqr(const quaternion& q);
	inline scalar mag(const quaternion& q);

	//- Return the conjugate of the given quaternion
	inline quaternion conjugate(const quaternion& q);

	//- Return the normailzed (unit) quaternion of the given quaternion
	inline quaternion normalize(const quaternion& q);

	//- Return the inverse of the given quaternion
	inline quaternion inv(const quaternion& q);

	//- Return a string representation of a quaternion
	word name(const quaternion&);

	//- Data associated with quaternion type are contiguous
	template<>
	inline bool contiguous<quaternion>() { return true; }


	// * * * * * * * * * * * * * * * Global Operators  * * * * * * * * * * * * * //

	inline bool operator==(const quaternion& q1, const quaternion& q2);
	inline bool operator!=(const quaternion& q1, const quaternion& q2);
	inline quaternion operator+(const quaternion& q1, const quaternion& q2);
	inline quaternion operator-(const quaternion& q);
	inline quaternion operator-(const quaternion& q1, const quaternion& q2);
	inline scalar operator&(const quaternion& q1, const quaternion& q2);
	inline quaternion operator*(const quaternion& q1, const quaternion& q2);
	inline quaternion operator/(const quaternion& q1, const quaternion& q2);
	inline quaternion operator*(const scalar s, const quaternion& q);
	inline quaternion operator*(const quaternion& q, const scalar s);
	inline quaternion operator/(const quaternion& q, const scalar s);


	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace tnbLib

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#include <quaternionI.hxx>

#endif // !_quaternion_Header
