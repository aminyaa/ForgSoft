//#pragma once
//#ifndef _MapPointField_Header
//#define _MapPointField_Header
//
//#include <Field.hxx>
//#include <pointMesh.hxx>
//
//// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //
//
//namespace tnbLib
//{
//
//	template<class Type, class MeshMapper>
//	class MapInternalField<Type, MeshMapper, pointMesh>
//	{
//	public:
//
//		MapInternalField()
//		{}
//
//		void operator()
//			(
//				Field<Type>& field,
//				const MeshMapper& mapper
//				) const;
//	};
//
//
//	template<class Type, class MeshMapper>
//	void MapInternalField<Type, MeshMapper, pointMesh>::operator()
//		(
//			Field<Type>& field,
//			const MeshMapper& mapper
//			) const
//	{
//		if (field.size() != mapper.pointMap().sizeBeforeMapping())
//		{
//			FatalErrorIn
//			(
//				"void MapInternalField<Type, MeshMapper, pointMesh>::operator()\n"
//				"(\n"
//				"    Field<Type>& field,\n"
//				"    const MeshMapper& mapper\n"
//				") const"
//			) << "Incompatible size before mapping.  Field size: " << field.size()
//				<< " map size: " << mapper.pointMap().sizeBeforeMapping()
//				<< abort(FatalError);
//		}
//
//		field.autoMap(mapper.pointMap());
//	}
//
//
//	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //
//
//} // End namespace tnbLib
//
//// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //
//
//#endif // !_MapPointField_Header
