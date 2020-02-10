#pragma once
#ifndef _VectorNFieldTypes_Header
#define _VectorNFieldTypes_Header

#include <vector2.hxx>
#include <vector3.hxx>
#include <vector4.hxx>
#include <Vector6.hxx>
#include <vector8.hxx>

#include <tensor2.hxx>
#include <tensor3.hxx>
#include <tensor4.hxx>
#include <tensor6.hxx>
#include <tensor8.hxx>

#include <diagTensor2.hxx>
#include <diagTensor3.hxx>
#include <diagTensor4.hxx>
#include <diagTensor6.hxx>
#include <diagTensor8.hxx>

#define forAllVectorNTypes(m, args)					\
    m(vector2, Vector2, args)                       \
    m(vector3, Vector3, args)                       \
    m(vector4, Vector4, args)                       \
    m(vector6, Vector6, args)                       \
    m(vector8, Vector8, args)

#define forAllTensorNTypes(m, args)					\
    m(tensor2, Tensor2, args)                       \
    m(tensor3, Tensor3, args)                       \
    m(tensor4, Tensor4, args)                       \
    m(tensor6, Tensor6, args)                       \
    m(tensor8, Tensor8, args)

#define forAllDiagTensorNTypes(m, args)				\
    m(diagTensor2, DiagTensor2, args)               \
    m(diagTensor3, DiagTensor3, args)               \
    m(diagTensor4, DiagTensor4, args)               \
    m(diagTensor6, DiagTensor6, args)               \
    m(diagTensor8, DiagTensor8, args)

#define forAllSphericalTensorNTypes(m, args)		\
    m(sphericalTensor2, SphericalTensor2, args)     \
    m(sphericalTensor3, SphericalTensor3, args)     \
    m(sphericalTensor4, SphericalTensor4, args)     \
    m(sphericalTensor6, SphericalTensor6, args)     \
    m(sphericalTensor8, SphericalTensor8, args)

#define forAllVectorTensorNTypes(m, args)								\
    m(tensor2, diagTensor2, sphericalTensor2, vector2, scalar, args)    \
    m(tensor3, diagTensor3, sphericalTensor3, vector3, scalar, args)    \
    m(tensor4, diagTensor4, sphericalTensor4, vector4, scalar, args)    \
    m(tensor6, diagTensor6, sphericalTensor6, vector6, scalar, args)    \
    m(tensor8, diagTensor8, sphericalTensor8, vector8, scalar, args)

#endif // !_VectorNFieldTypes_Header
