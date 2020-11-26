#pragma once
#ifndef _Mesh_NamedEntity_Header
#define _Mesh_NamedEntity_Header

#include <Global_Indexed.hxx>
#include <word.hxx>

namespace tnbLib
{

	class Mesh_NamedEntity
		: public Global_Indexed
	{

		/*Private Data*/

		word theName_;

	protected:

		Mesh_NamedEntity()
			: theName_("Unknown")
		{}

		Mesh_NamedEntity
		(
			const Standard_Integer theIndex
		)
			: Global_Indexed(theIndex)
			, theName_("Unknown")
		{}

		Mesh_NamedEntity
		(
			const Standard_Integer theIndex,
			const word& theName
		)
			: Global_Indexed(theIndex)
			, theName_(theName)
		{}

	public:

		const word& Name() const
		{
			return theName_;
		}

		void SetName(const word& theName)
		{
			theName_ = theName;
		}
	};
}

#endif // !_Mesh_NamedEntity_Header