#pragma once
#ifndef _VectorSpace_Header
#define _VectorSpace_Header

#include <scalar.hxx>

namespace AutLib
{

	template<class Form, class Cmpt, int nCmpt>
	class VectorSpace
	{

	public:

		//- Component type
		typedef Cmpt cmptType;


		// Member constants

		enum
		{
			dim = 3,            // Dimensionality of space
			nComponents = nCmpt // Number of components in this vector space
		};

		// Static data members

		//- The components of this vector space
		Cmpt v_[nCmpt];

		// Constructors

		//- Construct null
		VectorSpace();

		//- Construct from Istream
		VectorSpace(Istream&);

		//- Construct as copy
		VectorSpace(const VectorSpace<Form, Cmpt, nCmpt>&);


		// Member Functions

		//- Return the number of elements in the VectorSpace = nCmpt.
		label size() const;

		const Cmpt& component(const direction) const;
		Cmpt& component(const direction);

		void component(Cmpt&, const direction) const;
		void replace(const direction, const Cmpt&);


		// Member Operators

		const Cmpt& operator[](const direction) const;
		Cmpt& operator[](const direction);

		void operator=(const VectorSpace<Form, Cmpt, nCmpt>&);
		void operator+=(const VectorSpace<Form, Cmpt, nCmpt>&);
		void operator-=(const VectorSpace<Form, Cmpt, nCmpt>&);

		void operator*=(const scalar);
		void operator/=(const scalar);

		template<class Form, class Cmpt, int nCmpt>
		friend Istream& operator>> (Istream&, VectorSpace<Form, Cmpt, nCmpt>&);

		template<class Form, class Cmpt, int nCmpt>
		friend Ostream& operator<<(Ostream&, const VectorSpace<Form, Cmpt, nCmpt>&);
	};

	//- Return a string representation of a VectorSpace
	template<class Form, class Cmpt, int nCmpt>
	word name(const VectorSpace<Form, Cmpt, nCmpt>&);
}

#include <VectorSpaceI.hxx>

#endif // !_VectorSpace_Header
