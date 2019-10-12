#pragma once
namespace AutLib
{

	/*template<class SizeMapTraits>
	Standard_Boolean 
		SizeMap_BoundaryTool<SizeMapTraits>::RemovePatch
		(
			const word & theName
		)
	{
		if (thePatches_.empty())
			return Standard_True;

		auto n0 = NbPatches();
		thePatches_.remove(theName);

		if (n0 IS_EQUAL NbPatches()) return Standard_True;
		return Standard_False;
	}*/

	template<class SizeMapTraits>
	void SizeMap_BoundaryTool<SizeMapTraits>::ImportPatch
	(
		const word & theName
	)
	{
		thePatches_.push_back(theName);
	}
}