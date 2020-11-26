#pragma once
#ifndef _FrgBase_PrptsVrntFieldScalar_Header
#define _FrgBase_PrptsVrntFieldScalar_Header

#include <FrgBase_Global.hxx>
#include <FrgBase_PrptsVrntOneValue.hxx>
#include <FrgBase_Serialization_Global.hxx>

#include <QtCore/QMetaType>
#include <QtCore/QObject>

BeginForgBaseLib

class FrgBase_PrptsWdgFieldScalar;

class FORGBASE_EXPORT FrgBase_PrptsVrntFieldScalar
	: public QObject
	, public FrgBase_PrptsVrntOneValue<double, false>
{
	Q_OBJECT

public:

	explicit FrgBase_PrptsVrntFieldScalar
	(
		const QString& displayName = "",
		double value = 0.0,
		const QString& prefix = "",
		const QString& suffix = ""
	);

	typedef FrgBase_PrptsWdgFieldScalar VariantWidget;

	bool ShowNonParentalParameters() const { return theShowNonParentalParameters_; }
	void SetShowNonParentalParameters(bool condition = true) { theShowNonParentalParameters_ = condition; }

private:

	DECLARE_SAVE_LOAD_HEADER(FORGBASE_EXPORT)

protected:

	bool theShowNonParentalParameters_;

protected:

	void DisplayNameChanged() override;
	void ValueChanged() override;
	void PrefixChanged() override;
	void SuffixChanged() override;

Q_SIGNALS:

	void DisplayNameChangedSignal(const QString&);
	void ValueChangedSignal(const double&);
	void PrefixChangedSignal(const QString&);
	void SuffixChangedSignal(const QString&);
};

Q_DECLARE_METATYPE(FrgBase_PrptsVrntFieldScalar*)

EndForgBaseLib

BOOST_CLASS_EXPORT_KEY(ForgBaseLib::FrgBase_PrptsVrntFieldScalar)

#endif // !_FrgBase_PrptsVrntFieldScalar_Header
