#pragma once
#ifndef _Vector2DTemplate_Header
#define _Vector2DTemplate_Header

#include <VectorSpace.hxx>

namespace AutLib
{

	template <class Cmpt>
	class Vector2D
		: public VectorSpace<Vector2D<Cmpt>, Cmpt, 2>
	{

	public:

		// Member constants

		enum
		{
			rank = 1 // Rank of Vector2D is 1
		};


		// Static data members

		static const char* const typeName;
		static const char* componentNames[];
		static const Vector2D zero;
		static const Vector2D one;
		static const Vector2D max;
		static const Vector2D min;


		//- Component labeling enumeration
		enum components
		{
			X, Y
		};


		// Constructors

		//- Construct null
		Vector2D();

		//- Construct given VectorSpace
		Vector2D(const VectorSpace<Vector2D<Cmpt>, Cmpt, 2>&);

		//- Construct given two components
		Vector2D(const Cmpt& vx, const Cmpt& vy);

		//- Construct from Istream
		Vector2D(Istream&);


		// Member Functions

		// Access

		const Cmpt& x() const;
		const Cmpt& y() const;

		Cmpt& x();
		Cmpt& y();

		//- Return i-th component.  Consistency with VectorN
		const Cmpt& operator()(const direction i) const;

		//- Return i-th component.  Consistency with VectorN
		 Cmpt& operator()(const direction i);


		// Operators

		//- perp dot product (dot product with perpendicular vector)
		scalar perp(const Vector2D<Cmpt>& b) const;
	};
}

#include <Vector2DTemplateI.hxx>

#endif // !_Vector2DTemplate_Header
