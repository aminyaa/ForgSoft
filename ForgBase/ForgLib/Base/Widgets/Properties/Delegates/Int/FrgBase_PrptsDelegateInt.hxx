//#pragma once
//#ifndef _FrgBase_PrptsDelegateInt_Header
//#define _FrgBase_PrptsDelegateInt_Header
//
//#include <FrgBase_Global.hxx>
//#include <FrgBase_PrptsDelegateBase.hxx>
//
//BeginForgBaseLib
//
//class FORGBASE_EXPORT FrgBase_PrptsDelegateInt
//	: public FrgBase_PrptsDelegateBase
//{
//	Q_OBJECT
//
//public:
//
//	FrgBase_PrptsDelegateInt
//	(
//		QObject* parent = nullptr,
//		int min = 0,
//		int max = 100,
//		int step = 1
//	);
//
//	//void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const override;
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
//	int theMinValue_;
//	int theMaxValue_;
//	int theStep_;
//
//private slots:
//
//	void commitAndCloseEditor();
//};
//
//EndForgBaseLib
//
//#endif // !_FrgBase_PrptsDelegateInt_Header
