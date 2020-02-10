#pragma once
#ifndef _RodriguesRotation_Header
#define _RodriguesRotation_Header

#include <tmp.hxx>
#include <vector.hxx>
#include <tensor.hxx>
#include <tensorField.hxx>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace tnbLib
{

	// Compute rotation tensor using Rodrigues' Rotation Formula
	// Formulation taken from:
	// http://mathworld.wolfram.com/RodriguesRotationFormula.html
	//
	// Requires: rotation axis + rotation angle
	tensor RodriguesRotation
	(
		const vector& rotationAxis,
		const scalar& rotationAngle,
		const bool inDegrees = true
	);

	// Compute rotation tensor using Rodrigues' Rotation Formula
	// Slightly different formulation taken from:
	// http://en.wikipedia.org/wiki/Rodrigues%27_rotation_formula
	//
	// Requires: rotation axis + rotation angle
	tensor RodriguesRotation2
	(
		const vector& rotationAxis,
		const scalar& rotationAngle,
		const bool inDegrees = true
	);

	// Compute rotation tensor using Rodrigues' Rotation Formula
	// http://en.wikipedia.org/wiki/Rodrigues%27_rotation_formula
	//
	// Requires: rotation axis + initial vector + final vector

	tensor RodriguesRotation
	(
		const vector& rotationAxis,
		const vector& vi,
		const vector& vf
	);

	// Compute rotation tensorField using Rodrigues' Rotation Formula
	// http://en.wikipedia.org/wiki/Rodrigues%27_rotation_formula
	//
	// Requires: rotation axis + initial vectorField + final vectorField
	tnbLib::tensorField RodriguesRotation
	(
		const vector& rotationAxis,
		const vectorField& vi,
		const vectorField& vf
	);


	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace tnbLib

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif // !_RodriguesRotation_Header
