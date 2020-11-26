//#pragma once
//#ifndef _FrgBase_ApplicationCore_Header
//#define _FrgBase_ApplicationCore_Header
//
//#include <FrgBase_Global.hxx>
//#include <FrgBase_Object.hxx>
//#include <QtCore/QObject>
//
//BeginForgBaseLib
//
//class FrgBase_Settings;
//class FrgBase_UndoStack;
//
//class FORGBASE_EXPORT FrgBase_ApplicationCore
//	: public QObject
//	, public FrgBase_Object
//{
//	Q_OBJECT
//	typedef QObject SuperClass;
//
//public:
//
//	FrgBase_ApplicationCore
//	(
//		int argc,
//		char * argv[],
//		QObject* parent = nullptr
//	);
//
//	// Get the global instance for the FrgBase_ApplicationCore.
//	FrgBase_ApplicationCore* instance();
//
//	/**
// * Set/Get the application's central undo stack. By default no undo stack is
// * provided. Applications must set on up as required.
// */
//	void setUndoStack(FrgBase_UndoStack* stack);
//	FrgBase_UndoStack* getUndoStack() const { return this->theUndoStack_; }
//
//signals:
//
//	/**
//  * Fired when the undo stack is set.
//  */
//	void undoStackChanged(FrgBase_UndoStack* stack);
//
//protected:
//
//	FrgBase_Settings* theSettings_ = nullptr;
//	FrgBase_UndoStack* theUndoStack_ = nullptr;
//
//private:
//
//	static FrgBase_ApplicationCore* theInstance_;
//
//};
//
//EndForgBaseLib
//
//#endif // !_FrgBase_ApplicationCore_Header
