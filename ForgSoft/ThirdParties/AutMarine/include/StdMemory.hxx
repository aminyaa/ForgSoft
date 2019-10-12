#pragma once
#ifndef _StdMemory_Header
#define _StdMemory_Header

#include <memory>

#define Global_Handle(CLASS) std::shared_ptr<CLASS>

#define Global_Dangle(CLASS) std::weak_ptr<CLASS>

#define MakeHandle(CLASS) std::make_shared<CLASS>

#endif // !_StdMemory_Header
