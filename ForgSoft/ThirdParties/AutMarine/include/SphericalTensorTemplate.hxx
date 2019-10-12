#pragma once
#ifndef _SphericalTensorTemplate_Header
#define _SphericalTensorTemplate_Header

#include <VectorSpace.hxx>

namespace AutLib
{

	template<class Cmpt>
	class SphericalTensor
		: public VectorSpace<SphericalTensor<Cmpt>, Cmpt, 1>
	{

	public:

		//- Equivalent type of labels used for valid component indexing
		typedef SphericalTensor<label> labelType;


		// Member constants

		enum
		{
			rank = 2 // Rank of SphericalTensor is 2
		};


		// Static data members

		static const char* const typeName;
		static const char* componentNames[];
		static const SphericalTensor zero;
		static const SphericalTensor one;
		static const SphericalTensor max;
		static const SphericalTensor min;
		static const SphericalTensor I;
		static const SphericalTensor oneThirdI;
		static const SphericalTensor twoThirdsI;


		//- Component labeling enumeration
		enum components
		{
			II
		};


		// Constructors

		//- Construct null
		SphericalTensor();

		//- Construct given VectorSpace
		SphericalTensor
		(
			const VectorSpace<SphericalTensor<Cmpt>, Cmpt, 1>&
		);

		//- Construct given the component
		SphericalTensor(const Cmpt& tii);

		//- Construct from Istream
		SphericalTensor(Istream&);


		// Member Functions

		// Access

		const Cmpt& ii() const;
		Cmpt& ii();


		//- Transpose
		const SphericalTensor<Cmpt>& T() const;
	};
}

#include <SphericalTensorTemplateI.hxx>

#endif // !_SphericalTensorTemplate_Header
