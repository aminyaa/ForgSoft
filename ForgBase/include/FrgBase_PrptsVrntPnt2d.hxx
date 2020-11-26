#pragma once
#ifndef _FrgBase_PrptsVrntPnt2d_Header
#define _FrgBase_PrptsVrntPnt2d_Header

#include <FrgBase_Global.hxx>
#include <FrgBase_PrptsVrntOneValue.hxx>
#include <FrgBase_Serialization_Global.hxx>

#include <QtCore/QMetaType>
#include <QtCore/QObject>

BeginForgBaseLib

class FrgBase_Pnt2d;
class FrgBase_PrptsWdgPnt2d;

class FORGBASE_EXPORT FrgBase_PrptsVrntPnt2d
	: public QObject
	, public FrgBase_PrptsVrntOneValue<FrgBase_Pnt2d*, false>
{
	Q_OBJECT

public:

	explicit FrgBase_PrptsVrntPnt2d
	(
		const QString& displayName = "",
		FrgBase_Pnt2d* value = nullptr,
		const QString& prefix = "",
		const QString& suffix = ""
	);

	void SetXValue(double x);
	void SetYValue(double y);

	const QString& GetXPrefixLabel() const { return theXPrefixLabel_; }
	const QString& GetYPrefixLabel() const { return theYPrefixLabel_; }

	const QString& GetXSuffixLabel() const { return theXSuffixLabel_; }
	const QString& GetYSuffixLabel() const { return theYSuffixLabel_; }

	void SetXPrefixLabel(const QString& xPrefixLabel) { theXPrefixLabel_ = xPrefixLabel; emit XPrefixLabelChangedSignal(xPrefixLabel); }
	void SetYPrefixLabel(const QString& yPrefixLabel) { theYPrefixLabel_ = yPrefixLabel; emit YPrefixLabelChangedSignal(yPrefixLabel); }

	void SetXSuffixLabel(const QString& xSuffixLabel) { theXSuffixLabel_ = xSuffixLabel; emit XSuffixLabelChangedSignal(xSuffixLabel); }
	void SetYSuffixLabel(const QString& ySuffixLabel) { theYSuffixLabel_ = ySuffixLabel; emit YSuffixLabelChangedSignal(ySuffixLabel); }

	typedef FrgBase_PrptsWdgPnt2d VariantWidget;

private:

	DECLARE_SAVE_LOAD_HEADER(FORGBASE_EXPORT)

protected:

	void DisplayNameChanged() override;
	void ValueChanged() override;
	void PrefixChanged() override;
	void SuffixChanged() override;

Q_SIGNALS:

	void DisplayNameChangedSignal(const QString&);
	void ValueChangedSignal(FrgBase_Pnt2d*);
	void PrefixChangedSignal(const QString&);
	void SuffixChangedSignal(const QString&);
	void XPrefixLabelChangedSignal(const QString&);
	void YPrefixLabelChangedSignal(const QString&);
	void XSuffixLabelChangedSignal(const QString&);
	void YSuffixLabelChangedSignal(const QString&);

private:

	QString theXPrefixLabel_;
	QString theYPrefixLabel_;

	QString theXSuffixLabel_;
	QString theYSuffixLabel_;
};

Q_DECLARE_METATYPE(FrgBase_PrptsVrntPnt2d*)

EndForgBaseLib

BOOST_CLASS_EXPORT_KEY(ForgBaseLib::FrgBase_PrptsVrntPnt2d)

#endif // !_FrgBase_PrptsVrntPnt2d_Header
