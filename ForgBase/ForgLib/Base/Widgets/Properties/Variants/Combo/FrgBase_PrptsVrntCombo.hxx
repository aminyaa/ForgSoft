#pragma once
#ifndef _FrgBase_PrptsVrntCombo_Header
#define _FrgBase_PrptsVrntCombo_Header

#include <FrgBase_Global.hxx>
#include <FrgBase_PrptsVrntOneValue.hxx>
#include <QtCore/QMetaType>
#include <QtCore/QObject>

BeginForgBaseLib

class FrgBase_PrptsWdgCombo;

class FORGBASE_EXPORT FrgBase_PrptsVrntCombo
	: public QObject
	, public FrgBase_PrptsVrntOneValue<QString, false>
{

	Q_OBJECT

public:

	explicit FrgBase_PrptsVrntCombo
	(
		const char* displayName = "",
		const QString& value = "",
		const char* prefix = "",
		const char* suffix = ""
	);

	explicit FrgBase_PrptsVrntCombo
	(
		std::vector<QString> items,
		const char* displayName = "",
		const QString& value = "",
		const char* prefix = "",
		const char* suffix = ""
	);

	typedef FrgBase_PrptsWdgCombo VariantWidget;

	void AddItem(const QString& item);

	std::vector<QString> GetItems() const { return theItems_; }

protected:

	void DisplayNameChanged() override;
	void ValueChanged() override;
	void PrefixChanged() override;
	void SuffixChanged() override;

Q_SIGNALS:

	void DisplayNameChangedSignal(const char*);
	void ValueChangedSignal(const QString&);
	void PrefixChangedSignal(const char*);
	void SuffixChangedSignal(const char*);

private:

	std::vector<QString> theItems_;
};

EndForgBaseLib

#endif // !_FrgBase_PrptsVrntCombo_Header
