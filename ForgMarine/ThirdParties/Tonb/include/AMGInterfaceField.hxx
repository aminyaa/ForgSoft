#pragma once
#ifndef _AMGInterfaceField_Header
#define _AMGInterfaceField_Header

#include <lduInterfaceField.hxx>
#include <AMGInterface.hxx>
#include <autoPtr.hxx>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace tnbLib
{

	/*---------------------------------------------------------------------------*\
						  Class AMGInterfaceField Declaration
	\*---------------------------------------------------------------------------*/

	class AMGInterfaceField
		:
		public lduInterfaceField
	{
		// Private data

			//- Local reference cast into the interface
		const AMGInterface& interface_;


		// Private Member Functions

			//- Disallow default bitwise copy construct
		AMGInterfaceField(const AMGInterfaceField&);

		//- Disallow default bitwise assignment
		void operator=(const AMGInterfaceField&);


	public:

		//- Runtime type information
		TypeName("AMGInterfaceField");


		// Declare run-time constructor selection tables

		declareRunTimeSelectionTable
		(
			autoPtr,
			AMGInterfaceField,
			lduInterface,
			(
				const AMGInterface& AMGCp,
				const lduInterfaceField& fineInterface
				),
				(AMGCp, fineInterface)
		);


		// Selectors

			//- Return a pointer to a new interface created on freestore given
			//  the fine interface
		static autoPtr<AMGInterfaceField> New
		(
			const AMGInterface& AMGCp,
			const lduInterfaceField& fineInterface
		);


		// Constructors

			//- Construct from AMG interface and fine level interface field
		AMGInterfaceField
		(
			const AMGInterface& AMGCp,
			const lduInterfaceField&
		)
			:
			lduInterfaceField(AMGCp),
			interface_(AMGCp)
		{}
	};


	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace tnbLib

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif // !_AMGInterfaceField_Header
