#include "FrgBase_Icon.hxx"

#include <FrgBase_SerialSpec_QString.hxx>

ForgBaseLib::FrgBase_Icon::FrgBase_Icon(const bool isThemeDependent)
	: QIcon()
	, theIsThemeDependent_(isThemeDependent)
{

}

ForgBaseLib::FrgBase_Icon::FrgBase_Icon(const QString& fileAddress, const bool isThemeDependent)
	: QIcon(fileAddress)
	, theFileAddress_(fileAddress)
	, theIsThemeDependent_(isThemeDependent)
{

}

ForgBaseLib::FrgBase_Icon::FrgBase_Icon(const char* fileAddress, const bool isThemeDependent)
	: FrgBase_Icon(std::string(fileAddress), isThemeDependent)
{

}

ForgBaseLib::FrgBase_Icon::FrgBase_Icon(const std::string& fileAddress, const bool isThemeDependent)
	: FrgBase_Icon(QString::fromStdString(fileAddress), isThemeDependent)
{

}

ForgBaseLib::FrgBase_Icon::FrgBase_Icon(const QPixmap& pixmap, const bool isThemeDependent)
	: QIcon(pixmap)
	, theIsThemeDependent_(isThemeDependent)
{

}

ForgBaseLib::FrgBase_Icon::FrgBase_Icon(const FrgBase_Icon& icon)
	: QIcon(icon)
{
	theFileAddress_ = icon.theFileAddress_;
	theIsThemeDependent_ = icon.theIsThemeDependent_;
}

DECLARE_SAVE_IMP(ForgBaseLib::FrgBase_Icon)
{
	ar& theFileAddress_;
	ar& theIsThemeDependent_;
}

DECLARE_LOAD_IMP(ForgBaseLib::FrgBase_Icon)
{
	ar& theFileAddress_;
	ar& theIsThemeDependent_;
}

BOOST_CLASS_EXPORT_CXX(ForgBaseLib::FrgBase_Icon)