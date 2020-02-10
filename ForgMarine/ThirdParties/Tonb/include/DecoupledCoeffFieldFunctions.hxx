#pragma once
// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace tnbLib
{

	/* * * * * * * * * * * * * * * * Global functions  * * * * * * * * * * * * * */

	template<class Type>
	tmp<DecoupledCoeffField<Type> > inv
	(
		const DecoupledCoeffField<Type>& f
	);


	template<class Type>
	void multiply
	(
		Field<Type>& f,
		const DecoupledCoeffField<Type>& f1,
		const Type& f2
	);


	template<class Type>
	void multiply
	(
		Field<Type>& f,
		const DecoupledCoeffField<Type>& f1,
		const Field<Type>& f2
	);


	template<class Type>
	void multiply
	(
		Field<Type>& f,
		const Field<Type>& f1,
		const DecoupledCoeffField<Type>& f2
	);


	/* * * * * * * * * * * * * * * * Global operators  * * * * * * * * * * * * * */

#define UNARY_OPERATOR(op, opFunc)                                            \
                                                                              \
template<class Type>                                                          \
void opFunc                                                                   \
(                                                                             \
    DecoupledCoeffField<Type>& f,                                             \
    const DecoupledCoeffField<Type>& f1                                       \
);                                                                            \
                                                                              \
template<class Type>                                                          \
tmp<DecoupledCoeffField<Type> > operator op                                   \
(                                                                             \
    const DecoupledCoeffField<Type>& f1                                       \
);                                                                            \
                                                                              \
template<class Type>                                                          \
tmp<DecoupledCoeffField<Type> > operator op                                   \
(                                                                             \
    const tmp<DecoupledCoeffField<Type> >& tf1                                \
);

	template <class Type>
	void negate(DecoupledCoeffField<Type>& f, const DecoupledCoeffField<Type>& f1);
	template <class Type>
	tmp<DecoupledCoeffField<Type>> operator -(const DecoupledCoeffField<Type>& f1);
	template <class Type>
	tmp<DecoupledCoeffField<Type>> operator -(const tmp<DecoupledCoeffField<Type>>& tf1);

#undef UNARY_OPERATOR


		/* * * * * * * * * * * * * * * * Global operators  * * * * * * * * * * * * * */

#define BINARY_OPERATOR_FF(Type1, Type2, op, opFunc)                          \
                                                                              \
template<class Type>                                                          \
tmp<Field<Type> > operator op                                                 \
(                                                                             \
    const DecoupledCoeffField<Type1>& f1,                                     \
    const Type2& f2                                                           \
);                                                                            \
                                                                              \
                                                                              \
template<class Type>                                                          \
tmp<Field<Type> > operator op                                                 \
(                                                                             \
    const DecoupledCoeffField<Type1>& f1,                                     \
    const Field<Type2>& f2                                                    \
);                                                                            \
                                                                              \
                                                                              \
template<class Type>                                                          \
tmp<Field<Type> > operator op                                                 \
(                                                                             \
    const Field<Type2>& f1,                                                   \
    const DecoupledCoeffField<Type1>& f2                                      \
);


#define BINARY_OPERATOR_FTR(Type1, Type2, op, opFunc)                         \
template<class Type>                                                          \
tmp<Field<Type> > operator op                                                 \
(                                                                             \
    const DecoupledCoeffField<Type1>& f1,                                     \
    const tmp<Field<Type2> >& tf2                                             \
);

#define BINARY_OPERATOR_FT(Type1, Type2, op, opFunc)                          \
template<class Type>                                                          \
tmp<Field<Type> > operator op                                                 \
(                                                                             \
    const Field<Type1>& f1,                                                   \
    const tmp<DecoupledCoeffField<Type2> >& tf2                               \
);

#define BINARY_OPERATOR_TRF(Type1, Type2, op, opFunc)                         \
template<class Type>                                                          \
tmp<Field<Type> > operator op                                                 \
(                                                                             \
    const tmp<Field<Type1> >& tf1,                                            \
    const DecoupledCoeffField<Type2>& f2                                      \
);

#define BINARY_OPERATOR_TF(Type1, Type2, op, opFunc)                          \
template<class Type>                                                          \
tmp<Field<Type> > operator op                                                 \
(                                                                             \
    const tmp<DecoupledCoeffField<Type1> >& tf1,                              \
    const Field<Type2>& f2                                                    \
);

#define BINARY_OPERATOR_TRT(Type1, Type2, op, opFunc)                         \
template<class Type>                                                          \
tmp<Field<Type> > operator op                                                 \
(                                                                             \
    const tmp<DecoupledCoeffField<Type1> >& tf1,                              \
    const tmp<Field<Type2> >& tf2                                             \
);

#define BINARY_OPERATOR_TTR(Type1, Type2, op, opFunc)                         \
template<class Type>                                                          \
tmp<Field<Type> > operator op                                                 \
(                                                                             \
    const tmp<Field<Type1> >& tf1,                                            \
    const tmp<DecoupledCoeffFieldy<Type2> >& tf2                              \
);

#define BINARY_OPERATOR_R(Type1, Type2, op, opFunc)                           \
    BINARY_OPERATOR_FF(Type1, Type2, op, opFunc)                              \
    BINARY_OPERATOR_FTR(Type1, Type2, op, opFunc)                             \
    BINARY_OPERATOR_TRF(Type1, Type2, op, opFunc)                             \
    BINARY_OPERATOR_TRT(Type1, Type2, op, opFunc)

		
	template <class Type>
	tmp<Field<Type>> operator *(const DecoupledCoeffField<Type>& f1, const Type& f2);
	template <class Type>
	tmp<Field<Type>> operator *(const DecoupledCoeffField<Type>& f1, const Field<Type>& f2);
	template <class Type>
	tmp<Field<Type>> operator *(const Field<Type>& f1, const DecoupledCoeffField<Type>& f2);
	template <class Type>
	tmp<Field<Type>> operator *(const DecoupledCoeffField<Type>& f1, const tmp<Field<Type>>& tf2);
	template <class Type>
	tmp<Field<Type>> operator *(const tmp<Field<Type>>& tf1, const DecoupledCoeffField<Type>& f2);
	template <class Type>
	tmp<Field<Type>> operator *(const tmp<DecoupledCoeffField<Type>>& tf1, const tmp<Field<Type>>& tf2);

#undef BINARY_OPERATOR_R
#undef BINARY_OPERATOR_FF
#undef BINARY_OPERATOR_FTR
#undef BINARY_OPERATOR_TF
#undef BINARY_OPERATOR_TTR
#undef BINARY_OPERATOR_FT
#undef BINARY_OPERATOR_TRF
#undef BINARY_OPERATOR_TRT


		// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace tnbLib

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //