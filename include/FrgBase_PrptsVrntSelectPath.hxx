#pragma once
#ifndef _FrgBase_PrptsVrntSelectPath_Header
#define _FrgBase_PrptsVrntSelectPath_Header

#include <FrgBase_Global.hxx>
#include <FrgBase_PrptsVrntOneValue.hxx>
#include <FrgBase_Serialization_Global.hxx>

#include <QtCore/QMetaType>
#include <QtCore/QObject>

#include <type_traits>

BeginForgBaseLib

class FORGBASE_EXPORT FrgBase_PrptsVrntSelectPath_Base
	: public QObject
	, public FrgBase_PrptsVrntOneValue<QString, false>
{

	Q_OBJECT

public:

	explicit FrgBase_PrptsVrntSelectPath_Base
	(
		const QString& displayName = "",
		const QString& value = "",
		const QString& prefix = "",
		const QString& suffix = ""
	);

Q_SIGNALS:

	void DisplayNameChangedSignal(const QString&);
	void ValueChangedSignal(const QString&);
	void PrefixChangedSignal(const QString&);
	void SuffixChangedSignal(const QString&);
};

enum PathType
{
	File = 0x1200,
	Directory = 0x1201
};

class FrgBase_PrptsWdgSelectPath;

template<int T>
class FORGBASE_EXPORT FrgBase_PrptsVrntSelectPath
	: public FrgBase_PrptsVrntSelectPath_Base
{

public:

	template <typename = typename std::enable_if_t<T == PathType::File>>
	explicit FrgBase_PrptsVrntSelectPath
	(
		const QString& displayName = "",
		const QString& value = "",
		std::map<QString, StdVector<QString>> titlesAndFileTypes = { {QString(""), {QString("")}} },
		bool open = true,
		const QString& prefix = "",
		const QString& suffix = ""
	);

	template <typename = typename std::enable_if_t<T == PathType::Directory>>
	explicit FrgBase_PrptsVrntSelectPath
	(
		const QString& displayName = "",
		const QString& value = "",
		const QString& prefix = "",
		const QString& suffix = ""
	);

	template <typename = typename std::enable_if_t<T == PathType::File>>
	const auto& GetSelectdFileType() const { return theSelectedFileType_; }

	template <typename = typename std::enable_if_t<T == PathType::File>>
	void SetSelectdFileType(const QString& selectedFileType) { theSelectedFileType_ = selectedFileType; }

	template <typename = typename std::enable_if_t<T == PathType::File>>
	const auto& GetTitlesAndFileTypes() const { return theMapTitlesAndFileTypes_; }

	template <typename = typename std::enable_if_t<T == PathType::File>>
	void SetTitlesAndFileTypes(std::map<QString, StdVector<QString>> titlesAndFileTypes) { theMapTitlesAndFileTypes_ = titlesAndFileTypes; }

	template <typename = typename std::enable_if_t<T == PathType::File>>
	bool IsOpenType() const { return theIsOpenType_; }

	template <typename = typename std::enable_if_t<T == PathType::File>>
	void SetOpenType(bool openType = true) { theIsOpenType_ = openType; }

	typedef FrgBase_PrptsWdgSelectPath VariantWidget;

protected:

	void DisplayNameChanged() override;
	void ValueChanged() override;
	void PrefixChanged() override;
	void SuffixChanged() override;

protected:

	QString theSelectedFileType_;
	std::map<QString, StdVector<QString>> theMapTitlesAndFileTypes_;
	bool theIsOpenType_;
};

EndForgBaseLib

#endif // !_FrgBase_PrptsVrntSelectPath_Header
