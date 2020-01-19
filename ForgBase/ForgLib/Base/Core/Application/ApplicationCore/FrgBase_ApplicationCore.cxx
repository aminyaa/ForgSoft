//#include <FrgBase_ApplicationCore.hxx>
//#include <FrgBase_UndoStack.hxx>
//
//ForgBaseLib::FrgBase_ApplicationCore::FrgBase_ApplicationCore
//(
//	int argc,
//	char * argv[],
//	QObject* parent
//)
//	: SuperClass(parent)
//{
//	assert(FrgBase_ApplicationCore::theInstance_ = nullptr);
//}
//
//ForgBaseLib::FrgBase_ApplicationCore* ForgBaseLib::FrgBase_ApplicationCore::instance()
//{
//	return FrgBase_ApplicationCore::theInstance_;
//}
//
//void ForgBaseLib::FrgBase_ApplicationCore::setUndoStack
//(
//	FrgBase_UndoStack * stack
//)
//{
//	if (stack != this->theUndoStack_)
//	{
//		this->theUndoStack_ = stack;
//		if (stack)
//		{
//			stack->setParent(this);
//		}
//		emit this->undoStackChanged(stack);
//	}
//}