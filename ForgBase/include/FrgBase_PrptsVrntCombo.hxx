#pragma once
#ifndef _FrgBase_PrptsVrntCombo_Header
#define _FrgBase_PrptsVrntCombo_Header

#include <FrgBase_Global.hxx>
#include <FrgBase_PrptsVrntOneValue.hxx>
#include <FrgBase_Serialization_Global.hxx>

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
		const QString& displayName = "",
		const QString& value = "",
		const QString& prefix = "",
		const QString& suffix = ""
	);

	explicit FrgBase_PrptsVrntCombo
	(
		std::vector<QString> items,
		const QString& displayName = "",
		const QString& value = "",
		const QString& prefix = "",
		const QString& suffix = ""
	);

	typedef FrgBase_PrptsWdgCombo VariantWidget;

	void AddItem(const QString& item);

	std::vector<QString> GetItems() const { return theItems_; }

private:

	DECLARE_SAVE_LOAD_HEADER(FORGBASE_EXPORT)

protected:

	void DisplayNameChanged() override;
	void ValueChanged() override;
	void PrefixChanged() override;
	void SuffixChanged() override;

Q_SIGNALS:

	void DisplayNameChangedSignal(const QString&);
	void ValueChangedSignal(const QString&);
	void PrefixChangedSignal(const QString&);
	void SuffixChangedSignal(const QString&);

private:

	std::vector<QString> theItems_;
};

EndForgBaseLib

BOOST_CLASS_EXPORT_KEY(ForgBaseLib::FrgBase_PrptsVrntCombo)

#endif // !_FrgBase_PrptsVrntCombo_Header
