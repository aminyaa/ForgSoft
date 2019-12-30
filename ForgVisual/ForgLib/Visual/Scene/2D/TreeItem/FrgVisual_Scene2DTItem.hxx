#pragma once
#ifndef _FrgVisual_Scene2DTItem_Header
#define _FrgVisual_Scene2DTItem_Header

#include <FrgVisual_Global.hxx>
#include <FrgBase_TreeItem.hxx>

BeginForgVisualLib

class FrgVisual_Scene2D;

class FrgVisual_Scene2DTItem
	: public FrgBase_TreeItem
{

private:

	FrgVisual_Scene2D* theScene_ = FrgNullPtr;

};

EndForgVisualLib

#endif // !_FrgVisual_Scene2DTItem_Header
