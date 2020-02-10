#pragma once
#ifndef _PointPatchFieldMapperPatchRef_Header
#define _PointPatchFieldMapperPatchRef_Header

#include <PointPatchFieldMapper.hxx>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace tnbLib
{

	/*---------------------------------------------------------------------------*\
					   Class PointPatchFieldMapperPatchRef Declaration
	\*---------------------------------------------------------------------------*/

	template<class PointPatch>
	class PointPatchFieldMapperPatchRef
		:
		public PointPatchFieldMapper
	{
		// Private data

		const PointPatch& sourcePatch_;
		const PointPatch& targetPatch_;


		// Private Member Functions

			//- Disallow default bitwise copy construct
		PointPatchFieldMapperPatchRef(const PointPatchFieldMapperPatchRef&);

		//- Disallow default bitwise assignment
		void operator=(const PointPatchFieldMapperPatchRef&);


	public:

		// Constructors

			//- Construct from components
		PointPatchFieldMapperPatchRef
		(
			const PointPatch& source,
			const PointPatch& target
		)
			:
			sourcePatch_(source),
			targetPatch_(target)
		{}


		// Member functions

		const PointPatch& sourcePatch() const
		{
			return sourcePatch_;
		}

		const PointPatch& targetPatch() const
		{
			return targetPatch_;
		}
	};


	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace tnbLib

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif // !_PointPatchFieldMapperPatchRef_Header
