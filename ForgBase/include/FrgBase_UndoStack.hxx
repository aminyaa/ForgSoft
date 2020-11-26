#pragma once
#ifndef _FrgBase_UndoStack_Header
#define _FrgBase_UndoStack_Header

#include <FrgBase_Global.hxx>
#include <QtCore/QObject>

BeginForgBaseLib

class FORGBASE_EXPORT FrgBase_UndoStack
	: public QObject
{
	Q_OBJECT

public:

	FrgBase_UndoStack(QObject* parent = nullptr);
};

EndForgBaseLib

#endif // !_FrgBase_UndoStack_Header
