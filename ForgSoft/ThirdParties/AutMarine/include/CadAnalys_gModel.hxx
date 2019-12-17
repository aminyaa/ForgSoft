#pragma once
#ifndef _CadAnalys_gModel_Header
#define _CadAnalys_gModel_Header

#include <Geo3d_SizeFunction.hxx>
#include <GModel_Surface.hxx>
#include <GModel_Wire.hxx>
#include <CadAnalys_Model.hxx>

namespace AutLib
{

	typedef CadAnalys_Model<GModel_Surface, Geo3d_SizeFunction>
		CadAnalys_gModel;
}

#endif // !_CadAnalys_gModel_Header
