#pragma once
#ifndef _SphericalTensor2DTemplate_Header
#define _SphericalTensor2DTemplate_Header

#include <VectorSpace.hxx>

namespace AutLib
{

	template<class Cmpt>
	class SphericalTensor2D
		: public VectorSpace<SphericalTensor2D<Cmpt>, Cmpt, 1>
	{

	public:

		// Member constants

		enum
		{
			rank = 2 // Rank of SphericalTensor2D is 2
		};


		// Static data members

		static const char* const typeName;
		static const char* componentNames[];
		static const SphericalTensor2D zero;
		static const SphericalTensor2D one;
		static const SphericalTensor2D max;
		static const SphericalTensor2D min;
		static const SphericalTensor2D I;
		static const SphericalTensor2D oneThirdI;
		static const SphericalTensor2D twoThirdsI;


		//- Component labeling enumeration
		enum components
		{
			II
		};


		// Constructors

		//- Construct null
		SphericalTensor2D();

		//- Construct given VectorSpace
		SphericalTensor2D(const VectorSpace<SphericalTensor2D<Cmpt>, Cmpt, 1>&);

		//- Construct given the component
		SphericalTensor2D(const Cmpt& tii);

		//- Construct from Istream
		SphericalTensor2D(Istream&);


		// Member Functions

		// Access

		const Cmpt& ii() const;
		Cmpt& ii();
	};
}

#include <SphericalTensor2DTemplateI.hxx>

#endif // !_SphericalTensor2DTemplate_Header
