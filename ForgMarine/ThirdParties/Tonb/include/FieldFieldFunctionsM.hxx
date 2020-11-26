#pragma once
// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#define UNARY_FUNCTION(ReturnType, Type1, Func)                               \
                                                                              \
TEMPLATE                                                                      \
void Func                                                                     \
(                                                                             \
    FieldField<Field, ReturnType>& res,                                       \
    const FieldField<Field, Type1>& f                                         \
);                                                                            \
                                                                              \
TEMPLATE                                                                      \
tmp<FieldField<Field, ReturnType> > Func                                      \
(                                                                             \
    const FieldField<Field, Type1>& f                                         \
);                                                                            \
                                                                              \
TEMPLATE                                                                      \
tmp<FieldField<Field, ReturnType> > Func                                      \
(                                                                             \
    const tmp<FieldField<Field, Type1> >& tf                                  \
);


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#define UNARY_OPERATOR(ReturnType, Type1, Op, OpFunc)                         \
                                                                              \
TEMPLATE                                                                      \
void OpFunc                                                                   \
(                                                                             \
    FieldField<Field, ReturnType>& res,                                       \
    const FieldField<Field, Type1>& f                                         \
);                                                                            \
                                                                              \
TEMPLATE                                                                      \
tmp<FieldField<Field, ReturnType> > operator Op                               \
(                                                                             \
    const FieldField<Field, Type1>& f                                         \
);                                                                            \
                                                                              \
TEMPLATE                                                                      \
tmp<FieldField<Field, ReturnType> > operator Op                               \
(                                                                             \
    const tmp<FieldField<Field, Type1> >& tf                                  \
);


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#define BINARY_FUNCTION(ReturnType, Type1, Type2, Func)                       \
                                                                              \
TEMPLATE                                                                      \
void func                                                                     \
(                                                                             \
    FieldField<Field, ReturnType>& f,                                         \
    const FieldField<Field, Type1>& f1,                                       \
    const FieldField<Field, Type2>& f2                                        \
);                                                                            \
                                                                              \
TEMPLATE                                                                      \
tmp<FieldField<Field, ReturnType> > func                                      \
(                                                                             \
    const FieldField<Field, Type1>& f1,                                       \
    const FieldField<Field, Type2>& f2                                        \
);                                                                            \
                                                                              \
TEMPLATE                                                                      \
tmp<FieldField<Field, ReturnType> > func                                      \
(                                                                             \
    const FieldField<Field, Type1>& f1,                                       \
    const tmp<FieldField<Field, Type2> >& tf2                                 \
);                                                                            \
                                                                              \
TEMPLATE                                                                      \
tmp<FieldField<Field, ReturnType> > func                                      \
(                                                                             \
    const tmp<FieldField<Field, Type1> >& tf1,                                \
    const FieldField<Field, Type2>& f2                                        \
);                                                                            \
                                                                              \
TEMPLATE                                                                      \
tmp<FieldField<Field, ReturnType> > func                                      \
(                                                                             \
    const tmp<FieldField<Field, Type1> >& tf1,                                \
    const tmp<FieldField<Field, Type2> >& tf2                                 \
);


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#define BINARY_TYPE_FUNCTION_SF(ReturnType, Type1, Type2, Func)               \
                                                                              \
TEMPLATE                                                                      \
void func                                                                     \
(                                                                             \
    FieldField<Field, ReturnType>& f,                                         \
    const Type1& s1,                                                          \
    const FieldField<Field, Type2>& f2                                        \
);                                                                            \
                                                                              \
TEMPLATE                                                                      \
tmp<FieldField<Field, ReturnType> > func                                      \
(                                                                             \
    const Type1& s1,                                                          \
    const FieldField<Field, Type1>& f2                                        \
);                                                                            \
                                                                              \
TEMPLATE                                                                      \
tmp<FieldField<Field, ReturnType> > func                                      \
(                                                                             \
    const Type1& s1,                                                          \
    const tmp<FieldField<Field, Type1> >& tf2                                 \
);


#define BINARY_TYPE_FUNCTION_FS(ReturnType, Type1, Type2, Func)               \
                                                                              \
TEMPLATE                                                                      \
void func                                                                     \
(                                                                             \
    FieldField<Field, ReturnType>& f,                                         \
    const FieldField<Field, Type1>& f1,                                       \
    const Type2& s                                                            \
);                                                                            \
                                                                              \
TEMPLATE                                                                      \
tmp<FieldField<Field, ReturnType> > func                                      \
(                                                                             \
    const FieldField<Field, Type1>& f1,                                       \
    const Type2& s                                                            \
);                                                                            \
                                                                              \
TEMPLATE                                                                      \
tmp<FieldField<Field, ReturnType> > func                                      \
(                                                                             \
    const tmp<FieldField<Field, Type1> >& tf1,                                \
    const Type2& s                                                            \
);


#define BINARY_TYPE_FUNCTION(ReturnType, Type1, Type2, Func)                  \
    BINARY_TYPE_FUNCTION_SF(ReturnType, Type1, Type2, Func)                   \
    BINARY_TYPE_FUNCTION_FS(ReturnType, Type1, Type2, Func)


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#define BINARY_OPERATOR(ReturnType, Type1, Type2, Op, OpFunc)                 \
                                                                              \
TEMPLATE                                                                      \
void OpFunc                                                                   \
(                                                                             \
    FieldField<Field, ReturnType>& f,                                         \
    const FieldField<Field, Type1>& f1,                                       \
    const FieldField<Field, Type2>& f2                                        \
);                                                                            \
                                                                              \
TEMPLATE                                                                      \
tmp<FieldField<Field, ReturnType> > operator Op                               \
(                                                                             \
    const FieldField<Field, Type1>& f1,                                       \
    const FieldField<Field, Type2>& f2                                        \
);                                                                            \
                                                                              \
TEMPLATE                                                                      \
tmp<FieldField<Field, ReturnType> > operator Op                               \
(                                                                             \
    const FieldField<Field, Type1>& f1,                                       \
    const tmp<FieldField<Field, Type2> >& tf2                                 \
);                                                                            \
                                                                              \
TEMPLATE                                                                      \
tmp<FieldField<Field, ReturnType> > operator Op                               \
(                                                                             \
    const tmp<FieldField<Field, Type1> >& tf1,                                \
    const FieldField<Field, Type2>& f2                                        \
);                                                                            \
                                                                              \
TEMPLATE                                                                      \
tmp<FieldField<Field, ReturnType> > operator Op                               \
(                                                                             \
    const tmp<FieldField<Field, Type1> >& tf1,                                \
    const tmp<FieldField<Field, Type2> >& tf2                                 \
);


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#define BINARY_TYPE_OPERATOR_SF(ReturnType, Type1, Type2, Op, OpFunc)         \
                                                                              \
TEMPLATE                                                                      \
void OpFunc                                                                   \
(                                                                             \
    FieldField<Field, ReturnType>& f,                                         \
    const Type1& s1,                                                          \
    const FieldField<Field, Type2>& f2                                        \
);                                                                            \
                                                                              \
TEMPLATE                                                                      \
tmp<FieldField<Field, ReturnType> > operator Op                               \
(                                                                             \
    const Type1& s1,                                                          \
    const FieldField<Field, Type2>& f2                                        \
);                                                                            \
                                                                              \
TEMPLATE                                                                      \
tmp<FieldField<Field, ReturnType> > operator Op                               \
(                                                                             \
    const Type1& s1,                                                          \
    const tmp<FieldField<Field, Type2> >& tf2                                 \
);


#define BINARY_TYPE_OPERATOR_FS(ReturnType, Type1, Type2, Op, OpFunc)         \
                                                                              \
TEMPLATE                                                                      \
void OpFunc                                                                   \
(                                                                             \
    FieldField<Field, ReturnType>& f,                                         \
    const FieldField<Field, Type1>& f1,                                       \
    const Type2& s2                                                           \
);                                                                            \
                                                                              \
TEMPLATE                                                                      \
tmp<FieldField<Field, ReturnType> > operator Op                               \
(                                                                             \
    const FieldField<Field, Type1>& f1,                                       \
    const Type2& s2                                                           \
);                                                                            \
                                                                              \
TEMPLATE                                                                      \
tmp<FieldField<Field, ReturnType> > operator Op                               \
(                                                                             \
    const tmp<FieldField<Field, Type1> >& tf1,                                \
    const Type2& s2                                                           \
);


#define BINARY_TYPE_OPERATOR(ReturnType, Type1, Type2, Op, OpFunc)            \
    BINARY_TYPE_OPERATOR_SF(ReturnType, Type1, Type2, Op, OpFunc)             \
    BINARY_TYPE_OPERATOR_FS(ReturnType, Type1, Type2, Op, OpFunc)


// ************************************************************************* //