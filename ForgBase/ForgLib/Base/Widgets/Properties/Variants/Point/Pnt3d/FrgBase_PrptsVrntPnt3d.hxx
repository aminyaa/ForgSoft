#pragma once
#ifndef _FrgBase_PrptsVrntPnt3d_Header
#define _FrgBase_PrptsVrntPnt3d_Header

#include <FrgBase_Global.hxx>
#include <FrgBase_PrptsVrntOneValue.hxx>
#include <FrgBase_Serialization_Global.hxx>

#include <QtCore/QMetaType>
#include <QtCore/QObject>

BeginForgBaseLib

class FrgBase_Pnt3d;
class FrgBase_PrptsWdgPnt3d;

class FORGBASE_EXPORT FrgBase_PrptsVrntPnt3d
	: public QObject
	, public FrgBase_PrptsVrntOneValue<FrgBase_Pnt3d*, false>
{
	Q_OBJECT

public:

	explicit FrgBase_PrptsVrntPnt3d
	(
		const QString& displayName = "",
		FrgBase_Pnt3d* value = nullptr,
		const QString& prefix = "",
		const QString& suffix = ""
	);

	void SetXValue(double x);
	void SetYValue(double y);
	void SetZValue(double z);

	const QString& GetXPrefixLabel() const { return theXPrefixLabel_; }
	const QString& GetYPrefixLabel() const { return theYPrefixLabel_; }
	const QString& GetZPrefixLabel() const { return theZPrefixLabel_; }

	const QString& GetXSuffixLabel() const { return theXSuffixLabel_; }
	const QString& GetYSuffixLabel() const { return theYSuffixLabel_; }
	const QString& GetZSuffixLabel() const { return theZSuffixLabel_; }

	void SetXPrefixLabel(const QString& xPrefixLabel) { theXPrefixLabel_ = xPrefixLabel; emit XPrefixLabelChangedSignal(xPrefixLabel); }
	void SetYPrefixLabel(const QString& yPrefixLabel) { theYPrefixLabel_ = yPrefixLabel; emit YPrefixLabelChangedSignal(yPrefixLabel); }
	void SetZPrefixLabel(const QString& zPrefixLabel) { theZPrefixLabel_ = zPrefixLabel; emit ZPrefixLabelChangedSignal(zPrefixLabel); }

	void SetXSuffixLabel(const QString& xSuffixLabel) { theXSuffixLabel_ = xSuffixLabel; emit XSuffixLabelChangedSignal(xSuffixLabel); }
	void SetYSuffixLabel(const QString& ySuffixLabel) { theYSuffixLabel_ = ySuffixLabel; emit YSuffixLabelChangedSignal(ySuffixLabel); }
	void SetZSuffixLabel(const QString& zSuffixLabel) { theZSuffixLabel_ = zSuffixLabel; emit ZSuffixLabelChangedSignal(zSuffixLabel); }

	typedef FrgBase_PrptsWdgPnt3d VariantWidget;

private:

	DECLARE_SAVE_LOAD_HEADER(FORGBASE_EXPORT)

protected:

	void DisplayNameChanged() override;
	void ValueChanged() override;
	void PrefixChanged() override;
	void SuffixChanged() override;

Q_SIGNALS:

	void DisplayNameChangedSignal(const QString&);
	void ValueChangedSignal(FrgBase_Pnt3d*);
	void PrefixChangedSignal(const QString&);
	void SuffixChangedSignal(const QString&);
	void XPrefixLabelChangedSignal(const QString&);
	void YPrefixLabelChangedSignal(const QString&);
	void ZPrefixLabelChangedSignal(const QString&);
	void XSuffixLabelChangedSignal(const QString&);
	void YSuffixLabelChangedSignal(const QString&);
	void ZSuffixLabelChangedSignal(const QString&);

private:

	QString theXPrefixLabel_;
	QString theYPrefixLabel_;
	QString theZPrefixLabel_;

	QString theXSuffixLabel_;
	QString theYSuffixLabel_;
	QString theZSuffixLabel_;
};

Q_DECLARE_METATYPE(FrgBase_PrptsVrntPnt3d*)

EndForgBaseLib

BOOST_CLASS_EXPORT_KEY(ForgBaseLib::FrgBase_PrptsVrntPnt3d)

#endif // !_FrgBase_PrptsVrntPnt3d_Header
