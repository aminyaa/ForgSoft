#pragma once
#ifndef _meshObjectBase_Header
#define _meshObjectBase_Header

#include <typeInfo.hxx>
#include <HashTable.hxx>
#include <objectRegistry.hxx>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace tnbLib
{

	// Class forward declarations
	class mapPolyMesh;

	/*---------------------------------------------------------------------------*\
							 Class meshObjectBase Declaration
	\*---------------------------------------------------------------------------*/

	class meshObjectBase
	{
	public:

		//- Runtime type information
		TypeName("meshObject");


		// Static functions

			//- Update topology on all mesh objects
		template<class Mesh>
		static void allUpdateTopology(const Mesh& mesh, const mapPolyMesh& mpm)
		{
			HashTable<const meshObjectBase*> tbl =
				mesh.objectRegistry::template lookupClass<meshObjectBase>();

			if (Mesh::debug)
			{
				InfoIn
				(
					"static void meshObjectBase::"
					"allUpdateTopology(const Mesh& mesh, "
					"const mapPolyMesh& mpm)"
				) << "Mesh objects to update: " << tbl.toc() << endl;
			}

			for
				(
					HashTable<const meshObjectBase*>::iterator iter =
					tbl.begin();
					iter != tbl.end();
					++iter
					)
			{
				const meshObjectBase& obj = *(iter());

				if (Mesh::debug)
				{
					Info << "Updating object " << obj.type() << endl;
				}

				obj.updateMesh(mpm);
			}

			if (Mesh::debug)
			{
				Info << "Done update topology" << endl;
			}
		}


		//- Move points on all mesh objects
		template<class Mesh>
		static void allMovePoints(const Mesh& mesh)
		{
			if (mesh.moving())
			{
				HashTable<const meshObjectBase*> tbl =
					mesh.objectRegistry::template lookupClass<meshObjectBase>();

				if (Mesh::debug)
				{
					InfoIn
					(
						"static void meshObjectBase::"
						"allMovePoints(const Mesh& mesh)"
					) << "Mesh objects to move: " << tbl.toc() << endl;
				}

				for
					(
						HashTable<const meshObjectBase*>::iterator iter =
						tbl.begin();
						iter != tbl.end();
						++iter
						)
				{
					const meshObjectBase& obj = *(iter());

					if (Mesh::debug)
					{
						Info << "Moving object "
							<< " of type " << obj.type() << endl;
					}

					obj.movePoints();
				}

				if (Mesh::debug)
				{
					Info << "Done moving" << endl;
				}
			}
		}

		//- Move points on all mesh objects
		template<class Mesh>
		static void allDelete(const Mesh& mesh)
		{
			HashTable<const meshObjectBase*> tbl =
				mesh.objectRegistry::template lookupClass<meshObjectBase>();

			for
				(
					HashTable<const meshObjectBase*>::iterator iter =
					tbl.begin();
					iter != tbl.end();
					++iter
					)
			{
				const meshObjectBase& obj = *(iter());

				if (Mesh::debug)
				{
					Info << "Deleting object " << obj.type() << endl;

					obj.deleteObject();
				}
			}
		}


		// Destructor

		virtual ~meshObjectBase()
		{}


		// Member Functions

			//- Update after mesh motion
		virtual bool movePoints() const = 0;

		//- Update after topology change
		virtual bool updateMesh(const mapPolyMesh&) const = 0;

		//- Delete object from database
		virtual bool deleteObject() const = 0;
	};


	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace tnbLib

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif // !_meshObjectBase_Header
