#pragma once
// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace tnbLib
{

	// * * * * * * * * * * * * * * * * Constructors  * * * * * * * * * * * * * * //

	template<class Type, class GeoMesh>
	SubDimensionedField<Type, GeoMesh>::SubDimensionedField
	(
		const SubField<Type>& slist
	)
		:
		SubField<Type>(slist)
	{}

	template<class Type, class GeoMesh>
	SubDimensionedField<Type, GeoMesh>::SubDimensionedField
	(
		const UList<Type>& list,
		const label subSize
	)
		:
		SubField<Type>(list, subSize)
	{}


	template<class Type, class GeoMesh>
	SubDimensionedField<Type, GeoMesh>::SubDimensionedField
	(
		const UList<Type>& list,
		const label subSize,
		const label startIndex
	)
		:
		SubField<Type>(list, subSize, startIndex)
	{}


	/*template<class Type, class GeoMesh>
	SubDimensionedField<Type, GeoMesh>::SubDimensionedField
	(
		const SubDimensionedField<Type, GeoMesh>& sfield
	)
		:
		refCount(),
		SubField<Type>(sfield)
	{}*/

	template<class Type, class GeoMesh>
	SubDimensionedField<Type, GeoMesh>::SubDimensionedField
	(
		const SubDimensionedField<cmptType, GeoMesh>& sfield
	)
		: refCount()
		, SubField<Type>(sfield)
	{}


	// * * * * * * * * * * * * * * * Member Functions  * * * * * * * * * * * * * //

	// Return a null Field
	template<class Type, class GeoMesh>
	const SubDimensionedField<Type, GeoMesh>&
		SubDimensionedField<Type, GeoMesh>::null()
	{
		// Dangerous, but no null constructor.  Reconsider.  HJ, 10/Apr/2013
		SubDimensionedField<Type, GeoMesh>* nullPtr
			= reinterpret_cast<SubDimensionedField<Type, GeoMesh>*>(NULL);

		return *nullPtr;
	}


	/*template<class Type, class GeoMesh>
	tmp<Field<typename SubDimensionedField<Type, GeoMesh>::cmptType> >
		SubDimensionedField<Type, GeoMesh>::component
		(
			const direction d
		) const
	{
		return
			(
				reinterpret_cast<const DimensionedField<Type, GeoMesh>&>(*this)
				).component(d);
	}*/

	template<class Type, class GeoMesh>
	tmp<DimensionedField<typename SubDimensionedField<Type, GeoMesh>::cmptType, GeoMesh>> 
		SubDimensionedField<Type, GeoMesh>::component
		(
			const direction d
		) const
	{
		return
			(
				reinterpret_cast<const DimensionedField<Type, GeoMesh>&>(*this)
				).component(d);
	}


	template<class Type, class GeoMesh>
	tmp<DimensionedField<Type, GeoMesh> >
		SubDimensionedField<Type, GeoMesh>::T() const
	{
		return
			(
				reinterpret_cast<const DimensionedField<Type, GeoMesh>&>(*this)
				).T();
	}


	// * * * * * * * * * * * * * * * Member Operators  * * * * * * * * * * * * * //

	/*template<class Type, class GeoMesh>
	void SubDimensionedField<Type, GeoMesh>::operator=
		(
			const SubDimensionedField<Type, GeoMesh>& rhs
			)
	{
		dimensions() = rhs.dimensions();
		SubField<Type>::operator=(rhs);
	}*/


	// Allow cast to a const DimensionedField<Type, GeoMesh>&
	template<class Type, class GeoMesh>
	SubDimensionedField<Type, GeoMesh>::operator
		const DimensionedField<Type, GeoMesh>&() const
	{
		return *(reinterpret_cast<const DimensionedField<Type, GeoMesh>*>(this));
	}


	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace tnbLib

// ************************************************************************* //