#pragma once
#ifndef _FrgBase_PrptsVrntSelectTItem_Base_Header
#define _FrgBase_PrptsVrntSelectTItem_Base_Header

#include <FrgBase_Global.hxx>
#include <FrgBase_PrptsVrntOneValue.hxx>

#include <QtCore/QObject>

BeginForgBaseLib

class FrgBase_TreeItem;

class FORGBASE_EXPORT FrgBase_PrptsVrntSelectTItem_Base
	: public QObject
	, public FrgBase_PrptsVrntOneValue<FrgBase_TreeItem*, false>
{
	Q_OBJECT

public:

	explicit FrgBase_PrptsVrntSelectTItem_Base
	(
		const QString& displayName = "",
		FrgBase_TreeItem* tItem = nullptr,
		const QString& prefix = "",
		const QString& suffix = ""
	);

protected:

	void DisplayNameChanged() override;
	void ValueChanged() override;
	void PrefixChanged() override;
	void SuffixChanged() override;

Q_SIGNALS:

	void DisplayNameChangedSignal(const QString&);
	void ValueChangedSignal(FrgBase_TreeItem*);
	void PrefixChangedSignal(const QString&);
	void SuffixChangedSignal(const QString&);
};

EndForgBaseLib

#endif // !_FrgBase_PrptsVrntSelectTItem_Base_Header
