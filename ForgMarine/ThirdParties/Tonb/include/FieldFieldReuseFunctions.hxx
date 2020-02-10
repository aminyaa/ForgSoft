#pragma once
#ifndef _FieldFieldReuseFunctions_Header
#define _FieldFieldReuseFunctions_Header

#include <tmp.hxx>
#include <FieldField.hxx>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace tnbLib
{

	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

	template<template<class> class Field, class TypeR, class Type1>
	class reuseTmpFieldField
	{
	public:

		static tmp<FieldField<Field, TypeR> > New
		(
			const tmp<FieldField<Field, Type1> >& tf1
		)
		{
			return tmp<FieldField<Field, TypeR> >
				(
					FieldField<Field, TypeR>::NewCalculatedType(tf1())
					);
		}

		static void clear(const tmp<FieldField<Field, Type1> >& tf1)
		{
			tf1.clear();
		}
	};


	template<template<class> class Field, class TypeR>
	class reuseTmpFieldField<Field, TypeR, TypeR>
	{
	public:

		static tmp<FieldField<Field, TypeR> > New
		(
			const tmp<FieldField<Field, TypeR> >& tf1
		)
		{
			if (tf1.isTmp())
			{
				return tf1;
			}
			else
			{
				return tmp<FieldField<Field, TypeR> >
					(
						FieldField<Field, TypeR>::NewCalculatedType(tf1())
						);
			}
		}

		static void clear(const tmp<FieldField<Field, TypeR> >& tf1)
		{
			if (tf1.isTmp())
			{
				tf1.ptr();
			}
		}
	};


	template
		<
		template<class> class Field,
		class TypeR,
		class Type1,
		class Type12,
		class Type2
		>
		class reuseTmpTmpFieldField
	{
	public:

		static tmp<FieldField<Field, TypeR> > New
		(
			const tmp<FieldField<Field, Type1> >& tf1,
			const tmp<FieldField<Field, Type2> >& tf2
		)
		{
			return tmp<FieldField<Field, TypeR> >
				(
					FieldField<Field, TypeR>::NewCalculatedType(tf1())
					);
		}

		static void clear
		(
			const tmp<FieldField<Field, Type1> >& tf1,
			const tmp<FieldField<Field, Type2> >& tf2
		)
		{
			tf1.clear();
			tf2.clear();
		}
	};


	template<template<class> class Field, class TypeR, class Type1, class Type12>
	class reuseTmpTmpFieldField<Field, TypeR, Type1, Type12, TypeR>
	{
	public:

		static tmp<FieldField<Field, TypeR> > New
		(
			const tmp<FieldField<Field, Type1> >& tf1,
			const tmp<FieldField<Field, TypeR> >& tf2
		)
		{
			if (tf2.isTmp())
			{
				return tf2;
			}
			else
			{
				return tmp<FieldField<Field, TypeR> >
					(
						FieldField<Field, TypeR>::NewCalculatedType(tf1())
						);
			}
		}

		static void clear
		(
			const tmp<FieldField<Field, Type1> >& tf1,
			const tmp<FieldField<Field, TypeR> >& tf2
		)
		{
			tf1.clear();
			if (tf2.isTmp())
			{
				tf2.ptr();
			}
		}
	};


	template<template<class> class Field, class TypeR, class Type2>
	class reuseTmpTmpFieldField<Field, TypeR, TypeR, TypeR, Type2>
	{
	public:

		static tmp<FieldField<Field, TypeR> > New
		(
			const tmp<FieldField<Field, TypeR> >& tf1,
			const tmp<FieldField<Field, Type2> >& tf2
		)
		{
			if (tf1.isTmp())
			{
				return tf1;
			}
			else
			{
				return tmp<FieldField<Field, TypeR> >
					(
						FieldField<Field, TypeR>::NewCalculatedType(tf1())
						);
			}
		}

		static void clear
		(
			const tmp<FieldField<Field, TypeR> >& tf1,
			const tmp<FieldField<Field, Type2> >& tf2
		)
		{
			if (tf1.isTmp())
			{
				tf1.ptr();
			}
			tf2.clear();
		}
	};


	template<template<class> class Field, class TypeR>
	class reuseTmpTmpFieldField<Field, TypeR, TypeR, TypeR, TypeR>
	{
	public:

		static tmp<FieldField<Field, TypeR> > New
		(
			const tmp<FieldField<Field, TypeR> >& tf1,
			const tmp<FieldField<Field, TypeR> >& tf2
		)
		{
			if (tf1.isTmp())
			{
				return tf1;
			}
			else if (tf2.isTmp())
			{
				return tf2;
			}
			else
			{
				return tmp<FieldField<Field, TypeR> >
					(
						FieldField<Field, TypeR>::NewCalculatedType(tf1())
						);
			}
		}

		static void clear
		(
			const tmp<FieldField<Field, TypeR> >& tf1,
			const tmp<FieldField<Field, TypeR> >& tf2
		)
		{
			if (tf1.isTmp())
			{
				tf1.ptr();
				tf2.clear();
			}
			else if (tf2.isTmp())
			{
				tf1.clear();
				tf2.ptr();
			}
		}
	};


	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace tnbLib

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif // !_FieldFieldReuseFunctions_Header
