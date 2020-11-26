#pragma once
#ifndef _ExpandTensorN_Header
#define _ExpandTensorN_Header

#include <VectorN.hxx>
#include <VectorNFieldTypes.hxx>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#define UNARY_TEMPLATE_FUNCTION(ReturnType, Type, Func)                      \
template<class Cmpt, int length>                                             \
void Func(ReturnType<Cmpt, length>&, const Type<Cmpt, length>&);

#define UNARY_TEMPLATE_FUNCTION_VS(ReturnType, Func)                         \
template<class Cmpt, int length>                                             \
void Func(ReturnType<Cmpt, length>&, const Cmpt&);

#define UNARY_TEMPLATE_FUNCTION_SV(Type, Func)                               \
template<class Cmpt, int length>                                             \
void Func(Cmpt&, const Type<Cmpt, length>&);

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace tnbLib
{

	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

	template<class Cmpt, int length> 
	void contractScalar(Cmpt&, const TensorN<Cmpt, length>&);
		
	template<class Cmpt, int length> 
	void contractScalar(Cmpt&, const DiagTensorN<Cmpt, length>&);
		
	template<class Cmpt, int length> 
	void contractScalar(Cmpt&, const SphericalTensorN<Cmpt, length>&);
		
	template<class Cmpt, int length> 
	void contractScalar(Cmpt&, const VectorN<Cmpt, length>&);

		
	template<class Cmpt, int length> 
	void contractLinear(VectorN<Cmpt, length>&, const TensorN<Cmpt, length>&);
		
	template<class Cmpt, int length> 
	void contractLinear(VectorN<Cmpt, length>&, const DiagTensorN<Cmpt, length>&);
		
	template<class Cmpt, int length> 
	void contractLinear(VectorN<Cmpt, length>&, const SphericalTensorN<Cmpt, length>&);

		
	template<class Cmpt, int length> 
	void expandScalar(VectorN<Cmpt, length>&, const Cmpt&);
		
	template<class Cmpt, int length> 
	void expandScalar(TensorN<Cmpt, length>&, const Cmpt&);
		
	template<class Cmpt, int length> 
	void expandScalar(DiagTensorN<Cmpt, length>&, const Cmpt&);
		
	template<class Cmpt, int length> 
	void expandScalar(SphericalTensorN<Cmpt, length>&, const Cmpt&);

		
	template<class Cmpt, int length> 
	void expandLinear(TensorN<Cmpt, length>&, const VectorN<Cmpt, length>&);
		
	template<class Cmpt, int length> 
	void expandLinear(DiagTensorN<Cmpt, length>&, const VectorN<Cmpt, length>&);
		
	template<class Cmpt, int length> 
	void expandLinear(SphericalTensorN<Cmpt, length>&, const VectorN<Cmpt, length>&);

		
	template<class Cmpt, int length>
	void sumToDiag(VectorN<Cmpt, length>&, const TensorN<Cmpt, length>&);
		
	template<class Cmpt, int length> 
	void sumMagToDiag(VectorN<Cmpt, length>&, const TensorN<Cmpt, length>&);

		// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //
}

#include <ExpandTensorNI.hxx>

#undef UNARY_TEMPLATE_FUNCTION
#undef UNARY_TEMPLATE_FUNCTION_VS
#undef UNARY_TEMPLATE_FUNCTION_SV

#endif // !_ExpandTensorN_Header
