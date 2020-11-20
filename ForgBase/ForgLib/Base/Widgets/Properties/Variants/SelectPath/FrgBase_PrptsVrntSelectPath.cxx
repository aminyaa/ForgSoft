#include <FrgBase_PrptsVrntSelectPath.hxx>

ForgBaseLib::FrgBase_PrptsVrntSelectPath_Base::FrgBase_PrptsVrntSelectPath_Base
(
	const QString& displayName,
	const QString& value,
	const QString& prefix,
	const QString& suffix
)
	: FrgBase_PrptsVrntOneValue<QString, false>(displayName, value, prefix, suffix)
{

}

template<int T>
template<typename>
ForgBaseLib::FrgBase_PrptsVrntSelectPath<T>::FrgBase_PrptsVrntSelectPath
(
	const QString& displayName,
	const QString& value,
	std::map<QString, StdVector<QString>> titlesAndFileTypes,
	bool open,
	const QString& prefix,
	const QString& suffix
)
	: ForgBaseLib::FrgBase_PrptsVrntSelectPath_Base(displayName, value, prefix, suffix)
	, theMapTitlesAndFileTypes_(titlesAndFileTypes)
	, theIsOpenType_(open)
{

}

template<int T>
template<typename>
ForgBaseLib::FrgBase_PrptsVrntSelectPath<T>::FrgBase_PrptsVrntSelectPath
(
	const QString& displayName,
	const QString& value,
	const QString& prefix,
	const QString& suffix
)
	: ForgBaseLib::FrgBase_PrptsVrntSelectPath_Base(displayName, value, prefix, suffix)
{

}

template<int T>
inline void ForgBaseLib::FrgBase_PrptsVrntSelectPath<T>::DisplayNameChanged()
{
	emit DisplayNameChangedSignal(GetDisplayName());
}

template<int T>
void ForgBaseLib::FrgBase_PrptsVrntSelectPath<T>::ValueChanged()
{
	emit ValueChangedSignal(GetValue());
}

template<int T>
void ForgBaseLib::FrgBase_PrptsVrntSelectPath<T>::PrefixChanged()
{
	emit PrefixChangedSignal(GetPrefix());
}

template<int T>
void ForgBaseLib::FrgBase_PrptsVrntSelectPath<T>::SuffixChanged()
{
	emit SuffixChangedSignal(GetSuffix());
}

template FORGBASE_EXPORT class ForgBaseLib::FrgBase_PrptsVrntSelectPath<ForgBaseLib::PathType::File>;
template FORGBASE_EXPORT class ForgBaseLib::FrgBase_PrptsVrntSelectPath<ForgBaseLib::PathType::Directory>;

template FORGBASE_EXPORT ForgBaseLib::FrgBase_PrptsVrntSelectPath<ForgBaseLib::PathType::File>::FrgBase_PrptsVrntSelectPath(const QString& displayName, const QString& value, std::map<QString, StdVector<QString>> titlesAndFileTypes, bool open, const QString& prefix, const QString& suffix);

template FORGBASE_EXPORT ForgBaseLib::FrgBase_PrptsVrntSelectPath<ForgBaseLib::PathType::Directory>::FrgBase_PrptsVrntSelectPath
(const QString& displayName, const QString& value, const QString& prefix, const QString& suffix);

template FORGBASE_EXPORT const auto& ForgBaseLib::FrgBase_PrptsVrntSelectPath<ForgBaseLib::PathType::File>::GetSelectdFileType() const;

template FORGBASE_EXPORT void ForgBaseLib::FrgBase_PrptsVrntSelectPath<ForgBaseLib::PathType::File>::SetSelectdFileType(const QString& selectedFileType);

template FORGBASE_EXPORT const auto& ForgBaseLib::FrgBase_PrptsVrntSelectPath<ForgBaseLib::PathType::File>::GetTitlesAndFileTypes() const;

template FORGBASE_EXPORT void ForgBaseLib::FrgBase_PrptsVrntSelectPath<ForgBaseLib::PathType::File>::SetTitlesAndFileTypes(std::map<QString, StdVector<QString>> titlesAndFileTypes);

template FORGBASE_EXPORT bool ForgBaseLib::FrgBase_PrptsVrntSelectPath<ForgBaseLib::PathType::File>::IsOpenType() const;

template FORGBASE_EXPORT void ForgBaseLib::FrgBase_PrptsVrntSelectPath<ForgBaseLib::PathType::File>::SetOpenType(bool openType);