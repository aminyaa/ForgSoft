#pragma once
#ifndef _VectorTemplate_Header
#define _VectorTemplate_Header

#include <VectorSpace.hxx>

namespace AutLib
{

	template <class Cmpt>
	class Vector
		: public VectorSpace<Vector<Cmpt>, Cmpt, 3>
	{

	public:

		//- Equivalent type of labels used for valid component indexing
		typedef Vector<label> labelType;


		// Member constants

		enum
		{
			rank = 1 // Rank of Vector is 1
		};


		// Static data members

		static const char* const typeName;
		static const char* componentNames[];
		static const Vector zero;
		static const Vector one;
		static const Vector max;
		static const Vector min;


		//- Component labeling enumeration
		enum components
		{
			X, Y, Z
		};


		// Constructors

		//- Construct null
		Vector();

		//- Construct given VectorSpace
		Vector(const VectorSpace<Vector<Cmpt>, Cmpt, 3>&);

		//- Construct given three components
		Vector(const Cmpt& vx, const Cmpt& vy, const Cmpt& vz);

		//- Construct from Istream
		Vector(Istream&);


		// Member Functions

		// Access

		const Cmpt& x() const;
		const Cmpt& y() const;
		const Cmpt& z() const;

		Cmpt& x();
		Cmpt& y();
		Cmpt& z();

		//- Return i-th component.  Consistency with VectorN
		const Cmpt& operator()(const direction i) const;

		//- Return i-th component.  Consistency with VectorN
		 Cmpt& operator()(const direction i);


		//- Return *this (used for point which is a typedef to Vector<scalar>.
		/*const Vector<Cmpt>& centre
		(
			const AutLib::List<Vector<Cmpt> >&
		) const;*/

		const Vector<Cmpt>& centre(const List<Vector<Cmpt> >&) const;
	};

	template<class Cmpt>
	class typeOfRank<Cmpt, 1>
	{
	public:

		typedef Vector<Cmpt> type;
	};


	template<class Cmpt>
	class symmTypeOfRank<Cmpt, 1>
	{
	public:

		typedef Vector<Cmpt> type;
	};
}

#include <VectorTemplateI.hxx>

#endif // !_VectorTemplate_Header
