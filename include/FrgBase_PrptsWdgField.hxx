#pragma once
#ifndef _FrgBase_PrptsWdgField_Header
#define _FrgBase_PrptsWdgField_Header

#include <FrgBase_PrptsWdgStringDouble.hxx>

namespace exprtk
{
	template<typename T>
	class symbol_table;
}

typedef exprtk::symbol_table<double> symbol_table_t;

class QToolButton;

BeginForgBaseLib

class FORGBASE_EXPORT FrgBase_PrptsWdgField
	: public ForgBaseLib::FrgBase_PrptsWdgStringDouble
{

	Q_OBJECT

public:

	FrgBase_PrptsWdgField
	(
		QWidget* parent = nullptr,
		FrgBase_PrptsVrnt* variant = nullptr
	);

	~FrgBase_PrptsWdgField();

	void FormWidget() override;

	const QString& GetValueString() const { return theValueString_; }
	void SetValueString(const QString& valueString) { theValueString_ = valueString; }

	void SetSymbolTableT(symbol_table_t* symbolTableT) { theSymbolTableT_ = symbolTableT; }
	symbol_table_t* GetSymbolTableT() { return theSymbolTableT_; }

	bool eventFilter(QObject* watched, QEvent* event) override;

	void SetButtonHidden(bool condition = true);

	void SetLineEditValueForPreview();
	void UpdateAllParameters() const;

	QToolButton* GetButton() const { return theButton_; }

	bool IsButtonHidden() const;

protected slots:
	
	virtual void ButtonClickedSlot();

protected:

	QToolButton* theButton_ = nullptr;

	symbol_table_t* theSymbolTableT_ = nullptr;
	QString theValueString_;
};

EndForgBaseLib

#endif // !_FrgBase_PrptsWdgField_Header
