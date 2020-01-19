//#include <FrgBase_PrptsDelegateDouble.hxx>
//#include <FrgBase_PrptsEditorDouble.hxx>
//
//ForgBaseLib::FrgBase_PrptsDelegateDouble::FrgBase_PrptsDelegateDouble
//(
//	QObject* parent /* = nullptr */,
//	double min,
//	double max,
//	double step
//)
//	: FrgBase_PrptsDelegateBase(parent)
//	, theMinValue_(min)
//	, theMaxValue_(max)
//	, theStep_(step)
//{
//
//}
//
//QWidget* ForgBaseLib::FrgBase_PrptsDelegateDouble::createEditor
//(
//	QWidget* parent,
//	const QStyleOptionViewItem& option,
//	const QModelIndex& index
//) const
//{
//	if (index.data().canConvert<double>())
//	{
//		FrgBase_PrptsEditorDouble* editor = new FrgBase_PrptsEditorDouble(parent);
//		editor->SetMinimumValue(theMinValue_);
//		editor->SetMaximumValue(theMaxValue_);
//		editor->SetStep(theStep_);
//
//		connect(editor, SIGNAL(editingFinished()), this, SLOT(commitAndCloseEditor()));
//	}
//	else
//		return QStyledItemDelegate::createEditor(parent, option, index);
//}
//
//void ForgBaseLib::FrgBase_PrptsDelegateDouble::setEditorData
//(
//	QWidget* editor,
//	const QModelIndex& index
//) const
//{
//	if (index.data().canConvert<double>())
//	{
//		double value = qvariant_cast<double>(index.data());
//		FrgBase_PrptsEditorDouble* doubleEditor = qobject_cast<FrgBase_PrptsEditorDouble*>(editor);
//		doubleEditor->SetValue(value);
//	}
//	else
//		QStyledItemDelegate::setEditorData(editor, index);
//}
//
//void ForgBaseLib::FrgBase_PrptsDelegateDouble::setModelData
//(
//	QWidget* editor,
//	QAbstractItemModel* model,
//	const QModelIndex& index
//) const
//{
//	if (index.data().canConvert<double>())
//	{
//		FrgBase_PrptsEditorDouble* doubleEditor = qobject_cast<FrgBase_PrptsEditorDouble*>(editor);
//		model->setData(index, QVariant::fromValue(doubleEditor->GetValue()));
//	}
//	else
//		QStyledItemDelegate::setModelData(editor, model, index);
//}
//
//void ForgBaseLib::FrgBase_PrptsDelegateDouble::commitAndCloseEditor()
//{
//	FrgBase_PrptsEditorDouble* editor = qobject_cast<FrgBase_PrptsEditorDouble*>(sender());
//	if (editor)
//	{
//		emit commitData(editor);
//		emit closeEditor(editor);
//	}
//}
//
//void ForgBaseLib::FrgBase_PrptsDelegateDouble::updateEditorGeometry
//(
//	QWidget * editor,
//	const QStyleOptionViewItem & option,
//	const QModelIndex & index
//) const
//{
//	editor->setGeometry(option.rect);
//}