#pragma once
#ifndef _NihadTree_Header
#define _NihadTree_Header

#include <FrgBaseGlobals.hxx>
#include <FrgBaseTree.hxx>

BeginFrgBaseLib

class NihadTree : public FrgBaseTree
{

	Q_OBJECT

public:

	NihadTree(FrgBaseMainWindow* parent = FrgNullPtr);

	void FormTree() override;

public slots:

	void NewGeometryClickedSlot(bool b);

	void NewSceneClickedSlot(bool b);

};

EndFrgBaseLib

#endif // !_NihadTree_Header
