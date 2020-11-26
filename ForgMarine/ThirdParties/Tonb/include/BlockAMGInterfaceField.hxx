#pragma once
#ifndef _BlockAMGInterfaceField_Header
#define _BlockAMGInterfaceField_Header

#include <BlockLduInterfaceField.hxx>
#include <AMGInterface.hxx>
#include <autoPtr.hxx>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace tnbLib
{

	/*---------------------------------------------------------------------------*\
						  Class BlockAMGInterfaceField Declaration
	\*---------------------------------------------------------------------------*/

	template<class Type>
	class BlockAMGInterfaceField
		:
		public BlockLduInterfaceField<Type>
	{
		// Private data

			//- Local reference cast into the interface
		const AMGInterface& interface_;


		// Private Member Functions

			//- Disallow default bitwise copy construct
		BlockAMGInterfaceField(const BlockAMGInterfaceField&);

		//- Disallow default bitwise assignment
		void operator=(const BlockAMGInterfaceField&);


	public:

		//- Runtime type information
		TypeName("BlockAMGInterfaceField");


		// Declare run-time constructor selection tables

		declareRunTimeSelectionTable
		(
			autoPtr,
			BlockAMGInterfaceField,
			lduInterface,
			(
				const AMGInterface& AMGCp,
				const BlockLduInterfaceField<Type>& fineInterface
				),
				(AMGCp, fineInterface)
		);


		// Selectors

			//- Return a pointer to a new interface created on freestore given
			//  the fine interface
		static autoPtr<BlockAMGInterfaceField<Type> > New
		(
			const AMGInterface& AMGCp,
			const BlockLduInterfaceField<Type>& fineInterface
		);


		// Constructors

			//- Construct from AMG interface and fine level interface field
		BlockAMGInterfaceField
		(
			const AMGInterface& AMGCp,
			const BlockLduInterfaceField<Type>&
		)
			:
			BlockLduInterfaceField<Type>(AMGCp),
			interface_(AMGCp)
		{}


		//- Destructor
		virtual ~BlockAMGInterfaceField<Type>()
		{}


		// Member Functions

			// Agglomeration

				// Klas Jareteg: 2013-02-06
				//- Agglomerating for the CoeffField fine-level coefficients
		virtual tmp<CoeffField<Type> > agglomerateBlockCoeffs
		(
			const CoeffField<Type>& fineCoeffs
		) const;
	};


	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace tnbLib

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#ifdef NoRepository
#   include <BlockAMGInterfaceField.cxx>
#   include <newBlockAMGInterfaceField.cxx>
#endif

#define makeBlockAMGInterfaceField(BlockAMGInterfaceFieldType, typeBlockAMGInterfaceFieldType) \
                                                                              \
defineNamedTemplateTypeNameAndDebug(typeBlockAMGInterfaceFieldType, 0);       \
                                                                              \
addToRunTimeSelectionTable(BlockAMGInterfaceFieldType, typeBlockAMGInterfaceFieldType, lduInterface);

#define makeBlockAMGInterfaceFields(blockAMGInterfaceFieldType)               \
                                                                              \
makeBlockAMGInterfaceField(blockScalarAMGInterfaceField, blockAMGInterfaceFieldType##Scalar); \
makeBlockAMGInterfaceField(blockVectorAMGInterfaceField, blockAMGInterfaceFieldType##Vector); \

//HJ, hacked! Needs terminal specialisation.  HJ, 16/Mar/2016
//  makeBlockAMGInterfaceField(blockTensorAMGInterfaceField, blockAMGInterfaceFieldType##Tensor);


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif // !_BlockAMGInterfaceField_Header
