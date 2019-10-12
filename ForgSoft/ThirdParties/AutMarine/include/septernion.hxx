#pragma once
#ifndef _septernion_Header
#define _septernion_Header

#include <quaternion.hxx>

namespace AutLib
{

	class septernion
	{
		// private data

		//- Translation vector
		vector t_;

		//- Rotation quaternion
		quaternion r_;


	public:

		// Static data members

		static const char* const typeName;

		static const septernion zero;
		static const septernion I;


		// Constructors

		//- Construct null
		septernion();

		//- Construct given a translation vector and rotation quaternion
		septernion(const vector& t, const quaternion& r);

		//- Construct a pure translation septernion given a translation vector
		explicit septernion(const vector& t);

		//- Construct a pure rotation septernion given a rotation quaternion
		explicit septernion(const quaternion& r);

		//- Construct from Istream
		septernion(Istream&);


		// Member functions

		// Access

		const vector& t() const;
		const quaternion& r() const;


		// Edit

		vector& t();
		quaternion& r();


		// Transform

		//- Transform the given vector
		vector transform(const vector& v) const;

		//- Inverse transform the given vector
		vector invTransform(const vector& v) const;


		// Member operators

		void operator=(const septernion&);
		void operator*=(const septernion&);

		void operator=(const vector&);
		void operator+=(const vector&);
		void operator-=(const vector&);

		void operator=(const quaternion&);
		void operator*=(const quaternion&);
		void operator/=(const quaternion&);

		void operator*=(const scalar);
		void operator/=(const scalar);


		// IOstream operators

		friend Istream& operator>>(Istream& is, septernion&);
		friend Ostream& operator<<(Ostream& os, const septernion& C);
	};

	//- Return the inverse of the given septernion
	inline septernion inv(const septernion& tr);


	//- Return a string representation of a septernion
	word name(const septernion&);


	//- Data associated with septernion type are contiguous
	template<>
	inline bool contiguous<septernion>()
	{
		return true;
	}

	inline bool operator==(const septernion& tr1, const septernion& tr2);
	inline bool operator!=(const septernion& tr1, const septernion& tr2);
	inline septernion operator+(const septernion& tr, const vector& t);
	inline septernion operator+(const vector& t, const septernion& tr);
	inline septernion operator+(const septernion& tr1, const septernion& tr2);
	inline septernion operator-(const septernion& tr, const vector& t);
	inline septernion operator-(const septernion& tr1, const septernion& tr2);
	inline septernion operator*(const quaternion& r, const septernion& tr);
	inline septernion operator*(const septernion& tr, const quaternion& r);
	inline septernion operator/(const septernion& tr, const quaternion& r);
	inline septernion operator*(const septernion& q1, const septernion& q2);
	inline septernion operator/(const septernion& q1, const septernion& q2);
	inline septernion operator*(const scalar s, const septernion& tr);
	inline septernion operator*(const septernion& tr, const scalar s);
	inline septernion operator/(const septernion& tr, const scalar s);
}

#include <septernionI.hxx>

#endif // !_septernion_Header
