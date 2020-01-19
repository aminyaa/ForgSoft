//#include <FrgBase_PrptsDelegateInt.hxx>
//#include <FrgBase_PrptsEditorInt.hxx>
//#include <FrgBase_PrptsWdgInt.hxx>
//#include <FrgBase_PrptsVrntInt.hxx>
//
//ForgBaseLib::FrgBase_PrptsDelegateInt::FrgBase_PrptsDelegateInt
//(
//	QObject* parent /* = nullptr */,
//	int min,
//	int max,
//	int step
//)
//	: FrgBase_PrptsDelegateBase(parent)
//	, theMinValue_(min)
//	, theMaxValue_(max)
//	, theStep_(step)
//{
//
//}
//
//QWidget* ForgBaseLib::FrgBase_PrptsDelegateInt::createEditor
//(
//	QWidget* parent,
//	const QStyleOptionViewItem& option,
//	const QModelIndex& index
//) const
//{
//	if (index.data(Qt::EditRole).canConvert<FrgBase_PrptsVrntInt>())
//	{
//		/*FrgBase_PrptsEditorInt* editor = new FrgBase_PrptsEditorInt(parent);
//		editor->SetMinimumValue(theMinValue_);
//		editor->SetMaximumValue(theMaxValue_);
//		editor->SetStep(theStep_);*/
//
//		FrgBase_PrptsWdgInt* editor = new FrgBase_PrptsWdgInt(parent, new FrgBase_PrptsVrntInt(2));
//		editor->SetSuffix("[ft]");
//
//		connect(editor, SIGNAL(editingFinished()), this, SLOT(commitAndCloseEditor()));
//		return editor;
//	}
//	else
//		return QStyledItemDelegate::createEditor(parent, option, index);
//}
//
//void ForgBaseLib::FrgBase_PrptsDelegateInt::setEditorData
//(
//	QWidget* editor,
//	const QModelIndex& index
//) const
//{
//	if (index.data(Qt::EditRole).canConvert<FrgBase_PrptsVrntInt>())
//	{
//		FrgBase_PrptsVrntInt value = qvariant_cast<FrgBase_PrptsVrntInt>(index.data(Qt::EditRole));
//		FrgBase_PrptsWdgInt* intEditor = qobject_cast<FrgBase_PrptsWdgInt*>(editor);
//		intEditor->SetVariant(value);
//	}
//	else
//		QStyledItemDelegate::setEditorData(editor, index);
//}
//
//void ForgBaseLib::FrgBase_PrptsDelegateInt::setModelData
//(
//	QWidget* editor,
//	QAbstractItemModel* model,
//	const QModelIndex& index
//) const
//{
//	if (index.data(Qt::EditRole).canConvert<FrgBase_PrptsVrntInt>())
//	{
//		FrgBase_PrptsWdgInt* intEditor = qobject_cast<FrgBase_PrptsWdgInt*>(editor);
//		model->setData(index, QVariant::fromValue(intEditor->GetVariant()));
//	}
//	else
//		QStyledItemDelegate::setModelData(editor, model, index);
//}
//
//void ForgBaseLib::FrgBase_PrptsDelegateInt::commitAndCloseEditor()
//{
//	FrgBase_PrptsWdgInt* intEditor = qobject_cast<FrgBase_PrptsWdgInt*>(sender());
//	if (intEditor)
//	{
//		emit commitData(intEditor);
//		emit closeEditor(intEditor);
//	}
//}
//
//void ForgBaseLib::FrgBase_PrptsDelegateInt::updateEditorGeometry
//(
//	QWidget * editor,
//	const QStyleOptionViewItem & option,
//	const QModelIndex & index
//) const
//{
//	editor->setGeometry(option.rect);
//}