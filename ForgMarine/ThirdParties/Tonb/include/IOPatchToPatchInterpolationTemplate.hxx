#pragma once
#ifndef _IOPatchToPatchInterpolationTemplate_Header
#define _IOPatchToPatchInterpolationTemplate_Header

#include <className.hxx>
#include <labelList.hxx>
#include <scalarField.hxx>
#include <pointField.hxx>
#include <FieldFields.hxx>
#include <faceList.hxx>
#include <intersection.hxx>
#include <PatchToPatchInterpolationTemplate.hxx>
#include <regIOobject.hxx>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace tnbLib
{

	/*---------------------------------------------------------------------------*\
					Class IOPatchToPatchInterpolationName Declaration
	\*---------------------------------------------------------------------------*/

	TemplateName(IOPatchToPatchInterpolation);


	/*---------------------------------------------------------------------------*\
					  Class IOPatchToPatchInterpolation Declaration
	\*---------------------------------------------------------------------------*/

	template<class FromPatch, class ToPatch>
	class IOPatchToPatchInterpolation
		: public regIOobject
		, public PatchToPatchInterpolation<FromPatch, ToPatch>
	{
		// Private Member Functions

			//- Disallow default bitwise copy construct
		IOPatchToPatchInterpolation(const IOPatchToPatchInterpolation&);

		//- Disallow default bitwise assignment
		void operator=(const IOPatchToPatchInterpolation&);


	public:

		// Constructors

			//- Construct from components
		IOPatchToPatchInterpolation
		(
			const IOobject& io,
			const FromPatch& fromPatch,
			const ToPatch& toPatch,
			const intersection::algorithm alg = intersection::FULL_RAY,
			const intersection::direction dir = intersection::VECTOR
		);

		// Destructor

		~IOPatchToPatchInterpolation();


		// Member Functions

		bool writeData(Ostream&) const;

	};


	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace tnbLib

#ifdef NoRepository
#   include <IOPatchToPatchInterpolationTemplate.cxx>
#endif

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif // !_IOPatchToPatchInterpolationTemplate_Header
