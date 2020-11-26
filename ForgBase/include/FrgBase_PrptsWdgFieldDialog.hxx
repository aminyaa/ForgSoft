#pragma once
#ifndef _FrgBase_PrptsWdgFieldDialog_Header
#define _FrgBase_PrptsWdgFieldDialog_Header

#include <FrgBase_Global.hxx>
#include <QtWidgets/QDialog>

namespace exprtk
{
	template<typename T>
	class symbol_table;

	template<typename T>
	class expression;

	template<typename T>
	class parser;
}

typedef exprtk::symbol_table<double> symbol_table_t;
typedef exprtk::expression<double>     expression_t;
typedef exprtk::parser<double>             parser_t;

class QCodeEditor;
class QTableWidget;
class QLabel;
class QCheckBox;
class QPushButton;
class QTreeWidget;
class QKeyEvent;

class QExprtkCompleter;

BeginForgBaseLib

class FrgBase_PrptsVrnt;

class FORGBASE_EXPORT FrgBase_PrptsWdgFieldDialog
	: public QDialog
{

	Q_OBJECT

public:
	
	FrgBase_PrptsWdgFieldDialog
	(
		QWidget* parent = nullptr,
		Qt::WindowFlags f = Qt::WindowFlags()
	);

	~FrgBase_PrptsWdgFieldDialog();

	void FormWidget();

	void SetSymbolTableT(symbol_table_t* symbolTableT) { theSymbolTableT_ = symbolTableT; }
	symbol_table_t* GetSymbolTableT() const { return theSymbolTableT_; }

	const std::vector<double>& GetValues() const;
	void SetValues(const std::vector<double>& values);

	bool eventFilter(QObject* watched, QEvent* event) override;

protected slots:
	
	void CodeEditorTextChangedSlot();
	void onOK();
	void ImportCodeButtonClickedSlot();

protected:

	void keyPressEvent(QKeyEvent* event) override;
	void SetGeometry(int PercentageOfScreen);
	void FormParametersTable();
	void FormFunctionsTree();

private:

	QCodeEditor* theCodeEditor_ = nullptr;
	QTreeWidget* theFunctionsTree_ = nullptr;
	QTableWidget* theParametersTable_ = nullptr;
	QLabel* thePreviewLabel_ = nullptr;

	QCheckBox* theRealTimeCompilation_ = nullptr;
	QPushButton* theImportCodeButton_ = nullptr;
	QPushButton* theOKButton_ = nullptr;
	QPushButton* theCancelButton_ = nullptr;
	QPushButton* theHelpButton_ = nullptr;

	symbol_table_t* theSymbolTableT_ = nullptr;

	QExprtkCompleter* theCompleter_ = nullptr;

	std::vector<double> theValues_;
};

EndForgBaseLib

#endif // !_FrgBase_PrptsWdgFieldDialog_Header
