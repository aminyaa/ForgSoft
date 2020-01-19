//#pragma once
//#ifndef _FrgBase_DelegateDouble_Header
//#define _FrgBase_DelegateDouble_Header
//
//#include <FrgBase_Global.hxx>
//#include <FrgBase_PrptsDelegateBase.hxx>
//
//BeginForgBaseLib
//
//class FORGBASE_EXPORT FrgBase_PrptsDelegateDouble
//	: public FrgBase_PrptsDelegateBase
//{
//	Q_OBJECT
//
//public:
//
//	FrgBase_PrptsDelegateDouble
//	(
//		QObject* parent = nullptr,
//		double min = 0.0,
//		double max = 1.0,
//		double step = 0.01
//	);
//
//	QWidget* createEditor
//	(
//		QWidget* parent,
//		const QStyleOptionViewItem& option,
//		const QModelIndex& index
//	) const override;
//
//	void setEditorData
//	(
//		QWidget* editor,
//		const QModelIndex &index
//	) const override;
//
//	void setModelData
//	(
//		QWidget* editor,
//		QAbstractItemModel* model,
//		const QModelIndex& index
//	) const override;
//
//	void updateEditorGeometry
//	(
//		QWidget *editor,
//		const QStyleOptionViewItem &option,
//		const QModelIndex &index
//	) const override;
//
//private:
//
//	double theMinValue_;
//	double theMaxValue_;
//	double theStep_;
//
//private slots:
//
//	void commitAndCloseEditor();
//};
//
//EndForgBaseLib
//
//#endif // !_FrgBase_DelegateDouble_Header
