#pragma once
#ifndef _FrgBase_Icon_Header
#define _FrgBase_Icon_Header

#include <FrgBase_Global.hxx>
#include <FrgBase_Serialization_Global.hxx>

#include <QIcon>

BeginForgBaseLib

class FORGBASE_EXPORT FrgBase_Icon
	: public QIcon
{

public:

	explicit FrgBase_Icon(const bool isThemeDependent = true);

	explicit FrgBase_Icon(const QString& fileAddress, const bool isThemeDependent = true);

	explicit FrgBase_Icon(const char* fileAddress, const bool isThemeDependent = true);

	explicit FrgBase_Icon(const std::string& fileAddress, const bool isThemeDependent = true);

	explicit FrgBase_Icon(const QPixmap& pixmap, const bool isThemeDependent = true);

	FrgBase_Icon(const FrgBase_Icon& icon);

	QString GetFileAddress() const { return theFileAddress_; }
	void SetFileAddress(const QString& fileAddress) { theFileAddress_ = fileAddress; }

	bool IsThemeDependent() const { return theIsThemeDependent_; }
	void SetThemeDependent(const bool c) { theIsThemeDependent_ = c; }

private:

	DECLARE_SAVE_LOAD_HEADER(FORGBASE_EXPORT)

protected:

	QString theFileAddress_;

	bool theIsThemeDependent_ = true;
};

EndForgBaseLib

BOOST_CLASS_EXPORT_KEY(ForgBaseLib::FrgBase_Icon)

#endif // !_FrgBase_Icon_Header
