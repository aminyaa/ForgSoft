#pragma once
#ifndef _DimensionedFieldReuseFunctions_Header
#define _DimensionedFieldReuseFunctions_Header

#include <tmp.hxx>
#include <DimensionedField.hxx>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace tnbLib
{

	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

	template<class TypeR, class Type1, class GeoMesh>
	class reuseTmpDimensionedField
	{
	public:

		static tmp<DimensionedField<TypeR, GeoMesh> > New
		(
			const tmp<DimensionedField<Type1, GeoMesh> >& tdf1,
			const word& name,
			const dimensionSet& dimensions
		)
		{
			const DimensionedField<Type1, GeoMesh>& df1 = tdf1();

			return tmp<DimensionedField<TypeR, GeoMesh> >
				(
					new DimensionedField<TypeR, GeoMesh>
					(
						IOobject
						(
							name,
							df1.instance(),
							df1.db()
						),
						df1.mesh(),
						dimensions
						)
					);
		}

		static void clear(const tmp<DimensionedField<Type1, GeoMesh> >& tdf1)
		{
			tdf1.clear();
		}
	};


	template<class TypeR, class GeoMesh>
	class reuseTmpDimensionedField<TypeR, TypeR, GeoMesh>
	{
	public:

		static tmp<DimensionedField<TypeR, GeoMesh> > New
		(
			const tmp<DimensionedField<TypeR, GeoMesh> >& tdf1,
			const word& name,
			const dimensionSet& dimensions
		)
		{
			DimensionedField<TypeR, GeoMesh>& df1 =
				const_cast<DimensionedField<TypeR, GeoMesh>&>(tdf1());

			if (tdf1.isTmp())
			{
				df1.rename(name);
				df1.dimensions().reset(dimensions);
				return tdf1;
			}
			else
			{
				return tmp<DimensionedField<TypeR, GeoMesh> >
					(
						new DimensionedField<TypeR, GeoMesh>
						(
							IOobject
							(
								name,
								df1.instance(),
								df1.db()
							),
							df1.mesh(),
							dimensions
							)
						);
			}
		}

		static void clear(const tmp<DimensionedField<TypeR, GeoMesh> >& tdf1)
		{
			if (tdf1.isTmp())
			{
				tdf1.ptr();
			}
		}
	};


	template<class TypeR, class Type1, class Type12, class Type2, class GeoMesh>
	class reuseTmpTmpDimensionedField
	{
	public:

		static tmp<DimensionedField<TypeR, GeoMesh> > New
		(
			const tmp<DimensionedField<Type1, GeoMesh> >& tdf1,
			const tmp<DimensionedField<Type2, GeoMesh> >& tdf2,
			const word& name,
			const dimensionSet& dimensions
		)
		{
			const DimensionedField<Type1, GeoMesh>& df1 = tdf1();

			return tmp<DimensionedField<TypeR, GeoMesh> >
				(
					new DimensionedField<TypeR, GeoMesh>
					(
						IOobject
						(
							name,
							df1.instance(),
							df1.db()
						),
						df1.mesh(),
						dimensions
						)
					);
		}

		static void clear
		(
			const tmp<DimensionedField<Type1, GeoMesh> >& tdf1,
			const tmp<DimensionedField<Type2, GeoMesh> >& tdf2
		)
		{
			tdf1.clear();
			tdf2.clear();
		}
	};


	template<class TypeR, class Type1, class Type12, class GeoMesh>
	class reuseTmpTmpDimensionedField<TypeR, Type1, Type12, TypeR, GeoMesh>
	{
	public:

		static tmp<DimensionedField<TypeR, GeoMesh> > New
		(
			const tmp<DimensionedField<Type1, GeoMesh> >& tdf1,
			const tmp<DimensionedField<TypeR, GeoMesh> >& tdf2,
			const word& name,
			const dimensionSet& dimensions
		)
		{
			const DimensionedField<Type1, GeoMesh>& df1 = tdf1();
			DimensionedField<TypeR, GeoMesh>& df2 =
				const_cast<DimensionedField<TypeR, GeoMesh>&>(tdf2());

			if (tdf2.isTmp())
			{
				df2.rename(name);
				df2.dimensions().reset(dimensions);
				return tdf2;
			}
			else
			{
				return tmp<DimensionedField<TypeR, GeoMesh> >
					(
						new DimensionedField<TypeR, GeoMesh>
						(
							IOobject
							(
								name,
								df1.instance(),
								df1.db()
							),
							df1.mesh(),
							dimensions
							)
						);
			}
		}

		static void clear
		(
			const tmp<DimensionedField<Type1, GeoMesh> >& tdf1,
			const tmp<DimensionedField<TypeR, GeoMesh> >& tdf2
		)
		{
			tdf1.clear();
			if (tdf2.isTmp())
			{
				tdf2.ptr();
			}
		}
	};


	template<class TypeR, class Type2, class GeoMesh>
	class reuseTmpTmpDimensionedField<TypeR, TypeR, TypeR, Type2, GeoMesh>
	{
	public:

		static tmp<DimensionedField<TypeR, GeoMesh> > New
		(
			const tmp<DimensionedField<TypeR, GeoMesh> >& tdf1,
			const tmp<DimensionedField<Type2, GeoMesh> >& tdf2,
			const word& name,
			const dimensionSet& dimensions
		)
		{
			DimensionedField<TypeR, GeoMesh>& df1 =
				const_cast<DimensionedField<TypeR, GeoMesh>&>(tdf1());

			if (tdf1.isTmp())
			{
				df1.rename(name);
				df1.dimensions().reset(dimensions);
				return tdf1;
			}
			else
			{
				return tmp<DimensionedField<TypeR, GeoMesh> >
					(
						new DimensionedField<TypeR, GeoMesh>
						(
							IOobject
							(
								name,
								df1.instance(),
								df1.db()
							),
							df1.mesh(),
							dimensions
							)
						);
			}
		}

		static void clear
		(
			const tmp<DimensionedField<TypeR, GeoMesh> >& tdf1,
			const tmp<DimensionedField<Type2, GeoMesh> >& tdf2
		)
		{
			if (tdf1.isTmp())
			{
				tdf1.ptr();
			}
			tdf2.clear();
		}
	};


	template<class TypeR, class GeoMesh>
	class reuseTmpTmpDimensionedField<TypeR, TypeR, TypeR, TypeR, GeoMesh>
	{
	public:

		static tmp<DimensionedField<TypeR, GeoMesh> > New
		(
			const tmp<DimensionedField<TypeR, GeoMesh> >& tdf1,
			const tmp<DimensionedField<TypeR, GeoMesh> >& tdf2,
			const word& name,
			const dimensionSet& dimensions
		)
		{
			DimensionedField<TypeR, GeoMesh>& df1 =
				const_cast<DimensionedField<TypeR, GeoMesh>&>(tdf1());
			DimensionedField<TypeR, GeoMesh>& df2 =
				const_cast<DimensionedField<TypeR, GeoMesh>&>(tdf2());

			if (tdf1.isTmp())
			{
				df1.rename(name);
				df1.dimensions().reset(dimensions);
				return tdf1;
			}
			else if (tdf2.isTmp())
			{
				df2.rename(name);
				df2.dimensions().reset(dimensions);
				return tdf2;
			}
			else
			{
				return tmp<DimensionedField<TypeR, GeoMesh> >
					(
						new DimensionedField<TypeR, GeoMesh>
						(
							IOobject
							(
								name,
								df1.instance(),
								df1.db()
							),
							df1.mesh(),
							dimensions
							)
						);
			}
		}

		static void clear
		(
			const tmp<DimensionedField<TypeR, GeoMesh> >& tdf1,
			const tmp<DimensionedField<TypeR, GeoMesh> >& tdf2
		)
		{
			if (tdf1.isTmp())
			{
				tdf1.ptr();
				tdf2.clear();
			}
			else if (tdf2.isTmp())
			{
				tdf1.clear();
				tdf2.ptr();
			}
		}
	};


	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace tnbLib

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif // !_DimensionedFieldReuseFunctions_Header
