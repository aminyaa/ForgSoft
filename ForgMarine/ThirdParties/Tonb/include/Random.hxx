#pragma once
#ifndef _Random_Header
#define _Random_Header

#include <vector.hxx>
#include <tensor.hxx>
#include <symmTensor4thOrder.hxx>
#include <diagTensor.hxx>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace tnbLib
{

	/*---------------------------------------------------------------------------*\
							   Class Random Declaration
	\*---------------------------------------------------------------------------*/

	class Random
	{
		// Private data

			//- Seed for random numbers
		label Seed;


	public:

		// Constructors

			//- Construct given seed
		Random(const label&);


		// Member functions

			//- Return random bit
		int bit();

		//- scalar [0..1] (so including 0,1)
		scalar scalar01();

		//- vector with every component scalar01
		vector vector01();

		//- sphericalTensor with every component scalar01
		sphericalTensor sphericalTensor01();

		//- symmTensor with every component scalar01
		symmTensor symmTensor01();

		//- symmTensor4thOrder with every component scalar01
		symmTensor4thOrder symmTensor4thOrder01();

		//- diagTensor with every component scalar01
		diagTensor diagTensor01();

		//- tensor with every component scalar01
		tensor tensor01();

		//- label [lower..upper]
		label integer(const label lower, const label upper);

		vector position(const vector&, const vector&);

		void randomise(scalar&);
		void randomise(vector&);
		void randomise(sphericalTensor&);
		void randomise(symmTensor&);
		void randomise(symmTensor4thOrder&);
		void randomise(diagTensor&);
		void randomise(tensor&);

		//- Return a normal Gaussian random number
		//  with zero mean and unit variance N(0, 1)
		scalar GaussNormal();
	};


	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace tnbLib

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif // !_Random_Header
