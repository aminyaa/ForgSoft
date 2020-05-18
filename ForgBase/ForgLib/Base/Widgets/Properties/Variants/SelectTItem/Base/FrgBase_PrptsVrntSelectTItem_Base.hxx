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
		const char* displayName = "",
		FrgBase_TreeItem* tItem = nullptr,
		const char* prefix = "",
		const char* suffix = ""
	);

protected:

	void DisplayNameChanged() override;
	void ValueChanged() override;
	void PrefixChanged() override;
	void SuffixChanged() override;

Q_SIGNALS:

	void DisplayNameChangedSignal(const char*);
	void ValueChangedSignal(FrgBase_TreeItem*);
	void PrefixChangedSignal(const char*);
	void SuffixChangedSignal(const char*);
};

EndForgBaseLib

#endif // !_FrgBase_PrptsVrntSelectTItem_Base_Header
