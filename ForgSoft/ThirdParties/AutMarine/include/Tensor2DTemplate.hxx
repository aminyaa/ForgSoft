#pragma once
#ifndef _Tensor2DTemplate_Header
#define _Tensor2DTemplate_Header

#include <Vector2DTemplate.hxx>

namespace AutLib
{

	template<class Cmpt>
	class SymmTensor2D;

	template<class Cmpt>
	class SphericalTensor2D;

	template<class Cmpt>
	class Tensor2D
		: public VectorSpace<Tensor2D<Cmpt>, Cmpt, 4>
	{

	public:

		// Member constants

		enum
		{
			rank = 2 // Rank of Tensor2D is 2
		};


		// Static data members

		static const char* const typeName;
		static const char* componentNames[];

		static const Tensor2D zero;
		static const Tensor2D one;
		static const Tensor2D max;
		static const Tensor2D min;
		static const Tensor2D I;


		//- Component labeling enumeration
		enum components
		{
			XX, XY, YX, YY
		};


		// Constructors

		//- Construct null
		Tensor2D();

		//- Construct given VectorSpace
		Tensor2D(const VectorSpace<Tensor2D<Cmpt>, Cmpt, 4>&);

		//- Construct given SymmTensor2D
		Tensor2D(const SymmTensor2D<Cmpt>&);

		//- Construct given SphericalTensor2D
		Tensor2D(const SphericalTensor2D<Cmpt>&);

		//- Construct given the two vectors
		Tensor2D
		(
			const Vector2D<Cmpt>& x,
			const Vector2D<Cmpt>& y
		);

		//- Construct given the four components
		Tensor2D
		(
			const Cmpt txx, 
			const Cmpt txy,
			const Cmpt tyx, 
			const Cmpt tyy
		);

		//- Construct from Istream
		Tensor2D(Istream&);


		// Member Functions

		// Access

		const Cmpt& xx() const;
		const Cmpt& xy() const;
		const Cmpt& yx() const;
		const Cmpt& yy() const;

		Cmpt& xx();
		Cmpt& xy();
		Cmpt& yx();
		Cmpt& yy();

		// Access vector components.

		Vector2D<Cmpt> x() const;
		Vector2D<Cmpt> y() const;

		//- Return (i, j) component.  Consistency with VectorN
		const Cmpt& operator()(const direction i, const direction j) const;

		//- Return access to (i, j) component.  Consistency with VectorN
		Cmpt& operator()(const direction i, const direction j);


		//- Transpose
		Tensor2D<Cmpt> T() const;


		// Member Operators

		//- Copy SymmTensor2D
		void operator=(const SymmTensor2D<Cmpt>&);

		//- Copy SphericalTensor2D
		void operator=(const SphericalTensor2D<Cmpt>&);
	};
}

#include <Tensor2DTemplateI.hxx>

#endif // !_Tensor2DTemplate_Header
