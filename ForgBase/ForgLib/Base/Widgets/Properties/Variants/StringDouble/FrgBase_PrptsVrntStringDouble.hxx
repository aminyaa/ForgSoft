#pragma once
#ifndef _FrgBase_PrptsVrntStringDouble_Header
#define _FrgBase_PrptsVrntStringDouble_Header

#include <FrgBase_Global.hxx>
#include <FrgBase_PrptsVrntOneValue.hxx>
#include <FrgBase_Serialization_Global.hxx>

#include <QtCore/QMetaType>
#include <QtCore/QObject>

BeginForgBaseLib

class FrgBase_PrptsWdgStringDouble;

class FORGBASE_EXPORT FrgBase_PrptsVrntStringDouble
	: public QObject
	, public FrgBase_PrptsVrntOneValue<double, false>
{
	Q_OBJECT

public:

	explicit FrgBase_PrptsVrntStringDouble
	(
		const QString& displayName = "",
		double value = 0.0,
		const QString& prefix = "",
		const QString& suffix = ""
	);

	typedef FrgBase_PrptsWdgStringDouble VariantWidget;

	const bool& IsStepped() const { return theIsStepped_; }
	void SetStepped(const bool& stepped) { theIsStepped_ = stepped; }

	const double& GetStepValue() const { return theStepValue_; }
	void SetStepValue(double stepValue) { theStepValue_ = stepValue; }

	const bool& IsLimited() const { return theIsLimited_; }
	void SetLimited(const bool& limited) { theIsLimited_ = limited; emit LimitedChangedSignal(limited); }

	const double& GetMinimumValue() { return theMinimumValue_; }
	void SetMinimumValue(const double& minimumValue) { theMinimumValue_ = minimumValue; emit MinimumValueChangedSignal(minimumValue); }

	const double& GetMaximumValue() { return theMaximumValue_; }
	void SetMaximumValue(const double& maximumValue) { theMaximumValue_ = maximumValue; emit MaximumValueChangedSignal(maximumValue); }

private:

	DECLARE_SAVE_LOAD_HEADER(FORGBASE_EXPORT)

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

	void LimitedChangedSignal(const bool&);
	void MinimumValueChangedSignal(const double&);
	void MaximumValueChangedSignal(const double&);

private:

	bool theIsStepped_;
	double theStepValue_;

	bool theIsLimited_;
	double theMinimumValue_;
	double theMaximumValue_;
};

Q_DECLARE_METATYPE(FrgBase_PrptsVrntStringDouble*)

EndForgBaseLib

BOOST_CLASS_EXPORT_KEY(ForgBaseLib::FrgBase_PrptsVrntStringDouble)

#endif // !_FrgBase_PrptsVrntStringDouble_Header
