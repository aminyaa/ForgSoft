#pragma once
#ifndef _MeshObject_Header
#define _MeshObject_Header

#include <meshObjectBase.hxx>
#include <regIOobject.hxx>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace tnbLib
{

	/*---------------------------------------------------------------------------*\
							   Class MeshObject Declaration
	\*---------------------------------------------------------------------------*/


	template<class Mesh, class Type>
	class MeshObject
		:
		public meshObjectBase,
		public regIOobject
	{
		// Private data

			// Reference to Mesh
		const Mesh& mesh_;


	public:

		// Constructors

		explicit MeshObject(const Mesh& mesh);

		static const Type& New(const Mesh& mesh);

		template<class Data1>
		static const Type& New
		(
			const Mesh& mesh,
			const Data1& d
		);

		template<class Data1, class Data2>
		static const Type& New
		(
			const Mesh& mesh,
			const Data1&,
			const Data2&
		);

		template<class Data1, class Data2, class Data3>
		static const Type& New
		(
			const Mesh& mesh,
			const Data1&,
			const Data2&,
			const Data3&
		);

		template<class Data1, class Data2, class Data3, class Data4>
		static const Type& New
		(
			const Mesh& mesh,
			const Data1&,
			const Data2&,
			const Data3&,
			const Data4&
		);


		// Destructors

		virtual ~MeshObject();

		static bool Delete(const Mesh& mesh);


		// Member Functions

			//- Delete object from database
		virtual bool deleteObject() const;

		//- Return mesh reference
		const Mesh& mesh() const
		{
			return mesh_;
		}

		virtual bool writeData(tnbLib::Ostream&) const
		{
			return true;
		}
	};


	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace tnbLib

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#ifdef NoRepository
#   include <MeshObject.cxx>
#endif

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif // !_MeshObject_Header
