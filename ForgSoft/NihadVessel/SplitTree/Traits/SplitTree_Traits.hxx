#pragma once
#ifndef _SplitTree_Traits_Header
#define _SplitTree_Traits_Header

#include <FrgBaseGlobals.hxx>
#include <FrgBaseGlobalsICONS.hxx>

namespace AutLib
{
	template <class T>
	class Cad_BlockEntity;

	class TModel_Surface;
	class TModel_Paired;

	template<class T>
	class Cad_EntityManager;
}

BeginFrgBaseLib

template<typename T>
struct Entity_From_BlockEntity {};

template<>
struct Entity_From_BlockEntity<AutLib::Cad_BlockEntity<AutLib::TModel_Surface>> 
{
	typedef AutLib::TModel_Surface type;
	typedef AutLib::Cad_EntityManager<AutLib::TModel_Surface> typeManager;
	static FrgString GetIcon() { return FrgICONTreeItemPartSurface; }
};

template<>
struct Entity_From_BlockEntity<AutLib::Cad_BlockEntity<AutLib::TModel_Paired>>
{
	typedef AutLib::TModel_Paired type;
	typedef AutLib::Cad_EntityManager<AutLib::TModel_Paired> typeManager;
	static FrgString GetIcon() { return FrgICONTreeItemPartCurve; }
};

EndFrgBaseLib

#endif // !_SplitTree_Traits_Header
