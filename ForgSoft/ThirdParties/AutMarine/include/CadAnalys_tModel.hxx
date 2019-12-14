#pragma once
#ifndef _CadAnalys_tModel_Header
#define _CadAnalys_tModel_Header

#include <Geo3d_SizeFunction.hxx>
#include <TModel_Surface.hxx>
#include <CadAnalys_Model.hxx>

namespace AutLib
{

	typedef CadAnalys_Model<TModel_Surface, Geo3d_SizeFunction>
		CadAnalys_tModel;
}

#endif // !_CadAnalys_tModel_Header
