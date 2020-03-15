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
	, public FrgBase_PrptsVrntOneValue<const char*, false>
{

	Q_OBJECT

public:

	explicit FrgBase_PrptsVrntCombo
	(
		const char* displayName = "",
		const char* value = "",
		const char* prefix = "",
		const char* suffix = ""
	);

	explicit FrgBase_PrptsVrntCombo
	(
		std::vector<const char*> items,
		const char* displayName = "",
		const char* value = "",
		const char* prefix = "",
		const char* suffix = ""
	);

	typedef FrgBase_PrptsWdgCombo VariantWidget;

	void AddItem(const char* item);

	std::vector<const char*> GetItems() const { return theItems_; }

protected:

	void DisplayNameChanged() override;
	void ValueChanged() override;
	void PrefixChanged() override;
	void SuffixChanged() override;

Q_SIGNALS:

	void DisplayNameChangedSignal(const char*);
	void ValueChangedSignal(const char*);
	void PrefixChangedSignal(const char*);
	void SuffixChangedSignal(const char*);

private:

	std::vector<const char*> theItems_;
};

EndForgBaseLib

#endif // !_FrgBase_PrptsVrntCombo_Header
