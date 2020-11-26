#pragma once
#ifndef _FrgBase_PrptsVrntFieldVector_Header
#define _FrgBase_PrptsVrntFieldVector_Header

#include <FrgBase_Global.hxx>
#include <FrgBase_PrptsVrntOneValue.hxx>
#include <FrgBase_Serialization_Global.hxx>

#include <QtCore/QMetaType>
#include <QtCore/QObject>

BeginForgBaseLib

class FrgBase_PrptsWdgFieldVector;

class FORGBASE_EXPORT FrgBase_PrptsVrntFieldVector
	: public QObject
	, public FrgBase_PrptsVrntOneValue<std::vector<double>, false>
{
	Q_OBJECT

public:

	explicit FrgBase_PrptsVrntFieldVector
	(
		const QString& displayName = "",
		std::vector<double> values = std::vector<double>(),
		const QString& prefix = "",
		const QString& suffix = ""
	);

	typedef FrgBase_PrptsWdgFieldVector VariantWidget;

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
	void ValueChangedSignal(const std::vector<double>&);
	void PrefixChangedSignal(const QString&);
	void SuffixChangedSignal(const QString&);
};

Q_DECLARE_METATYPE(FrgBase_PrptsVrntFieldVector*)

EndForgBaseLib

BOOST_CLASS_EXPORT_KEY(ForgBaseLib::FrgBase_PrptsVrntFieldVector)

#endif // !_FrgBase_PrptsVrntFieldVector_Header
