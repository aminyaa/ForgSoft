#include <FrgBase_Application.hxx>
#include <FrgBase_MainWindow.hxx>

#include <windows.h>
#include <eh.h>
#include <Psapi.h>
#include <string>
#include <sstream>

namespace ForgBaseLib
{
	class FrgBase_ExceptionString
		: public std::string
	{

	public:

		FrgBase_ExceptionString(std::string str) : std::string(str) {}
	};
}

class InfoFromSE
{
public:
	typedef unsigned int exception_code_t;

	static const char* opDescription(const ULONG opcode)
	{
		switch (opcode) {
		case 0: return "read";
		case 1: return "write";
		case 8: return "user-mode data execution prevention (DEP) violation";
		default: return "unknown";
		}
	}

	static const char* seDescription(const exception_code_t& code)
	{
		switch (code) {
		case EXCEPTION_ACCESS_VIOLATION:         return "EXCEPTION_ACCESS_VIOLATION";
		case EXCEPTION_ARRAY_BOUNDS_EXCEEDED:    return "EXCEPTION_ARRAY_BOUNDS_EXCEEDED";
		case EXCEPTION_BREAKPOINT:               return "EXCEPTION_BREAKPOINT";
		case EXCEPTION_DATATYPE_MISALIGNMENT:    return "EXCEPTION_DATATYPE_MISALIGNMENT";
		case EXCEPTION_FLT_DENORMAL_OPERAND:     return "EXCEPTION_FLT_DENORMAL_OPERAND";
		case EXCEPTION_FLT_DIVIDE_BY_ZERO:       return "EXCEPTION_FLT_DIVIDE_BY_ZERO";
		case EXCEPTION_FLT_INEXACT_RESULT:       return "EXCEPTION_FLT_INEXACT_RESULT";
		case EXCEPTION_FLT_INVALID_OPERATION:    return "EXCEPTION_FLT_INVALID_OPERATION";
		case EXCEPTION_FLT_OVERFLOW:             return "EXCEPTION_FLT_OVERFLOW";
		case EXCEPTION_FLT_STACK_CHECK:          return "EXCEPTION_FLT_STACK_CHECK";
		case EXCEPTION_FLT_UNDERFLOW:            return "EXCEPTION_FLT_UNDERFLOW";
		case EXCEPTION_ILLEGAL_INSTRUCTION:      return "EXCEPTION_ILLEGAL_INSTRUCTION";
		case EXCEPTION_IN_PAGE_ERROR:            return "EXCEPTION_IN_PAGE_ERROR";
		case EXCEPTION_INT_DIVIDE_BY_ZERO:       return "EXCEPTION_INT_DIVIDE_BY_ZERO";
		case EXCEPTION_INT_OVERFLOW:             return "EXCEPTION_INT_OVERFLOW";
		case EXCEPTION_INVALID_DISPOSITION:      return "EXCEPTION_INVALID_DISPOSITION";
		case EXCEPTION_NONCONTINUABLE_EXCEPTION: return "EXCEPTION_NONCONTINUABLE_EXCEPTION";
		case EXCEPTION_PRIV_INSTRUCTION:         return "EXCEPTION_PRIV_INSTRUCTION";
		case EXCEPTION_SINGLE_STEP:              return "EXCEPTION_SINGLE_STEP";
		case EXCEPTION_STACK_OVERFLOW:           return "EXCEPTION_STACK_OVERFLOW";
		default: return "UNKNOWN EXCEPTION";
		}
	}

	static ForgBaseLib::FrgBase_ExceptionString information(struct _EXCEPTION_POINTERS* ep, bool has_exception_code = false, exception_code_t code = 0)
	{
		HMODULE hm;
		::GetModuleHandleEx(GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS, static_cast<LPCTSTR>(ep->ExceptionRecord->ExceptionAddress), &hm);
		MODULEINFO mi;
		::GetModuleInformation(::GetCurrentProcess(), hm, &mi, sizeof(mi));
		char fn[MAX_PATH];
		::GetModuleFileNameExA(::GetCurrentProcess(), hm, fn, MAX_PATH);

		std::ostringstream oss;
		oss << "SE " << (has_exception_code ? seDescription(code) : "") << " at address 0x" << std::hex << ep->ExceptionRecord->ExceptionAddress << std::dec
			<< " inside " << fn << " loaded at base address 0x" << std::hex << mi.lpBaseOfDll << "\n";

		if (has_exception_code && (
			code == EXCEPTION_ACCESS_VIOLATION ||
			code == EXCEPTION_IN_PAGE_ERROR)) {
			oss << "Invalid operation: " << opDescription(ep->ExceptionRecord->ExceptionInformation[0]) << " at address 0x" << std::hex << ep->ExceptionRecord->ExceptionInformation[1] << std::dec << "\n";
		}

		if (has_exception_code && code == EXCEPTION_IN_PAGE_ERROR) {
			oss << "Underlying NTSTATUS code that resulted in the exception " << ep->ExceptionRecord->ExceptionInformation[2] << "\n";
		}

		ForgBaseLib::FrgBase_ExceptionString str(oss.str());
		return str;
	}
};

#include <iostream>
#include <exception>

void translator(InfoFromSE::exception_code_t code, struct _EXCEPTION_POINTERS* ep)
{
	auto str = InfoFromSE::information(ep, true, code);
	throw str;
}

void transloatorUnexpected_handler()
{
	ForgBaseLib::FrgBase_ExceptionString str("Unexpected Exception");

	throw str;
}

ForgBaseLib::FrgBase_Application::FrgBase_Application
(
	int& argc,
	char** argv,
	int af
)
	: QApplication(argc, argv, af)
{
	_set_se_translator(translator);
	set_unexpected(transloatorUnexpected_handler);
}

bool ForgBaseLib::FrgBase_Application::notify(QObject* receiver, QEvent* event)
{
	//return QApplication::notify(receiver, event);

	bool done = true;
	try
	{
		done = QApplication::notify(receiver, event);
	}
	catch (const FrgBase_ExceptionString& str)
	{
		if (theParentMainWindow_)
			theParentMainWindow_->PrintErrorToConsole(QString::fromStdString(str));
	}

	return done;
}

ForgBaseLib::FrgBase_Application* ForgBaseLib::FrgBase_Application::Instance()
{
	auto item = dynamic_cast<FrgBase_Application*>(instance());
	if (item)
		return item;

	return nullptr;
}

void ForgBaseLib::FrgBase_Application::CatchAndThrowStdException
(
	const std::function<void()>& func
)
{
	_set_se_translator(translator);
	set_unexpected(transloatorUnexpected_handler);

	std::string baseMessage = "__BaseMessage__";
	std::string message = baseMessage;
	try
	{
		func();
	}
	catch (int i)
	{
		message = "Integer detected \"" + std::to_string(i) + "\"";
	}
	catch (float f)
	{
		message = "Float detected \"" + std::to_string(f) + "\"";
	}
	catch (double d)
	{
		message = "Double detected \"" + std::to_string(d) + "\"";
	}
	catch (const char* s)
	{
		message = s;
	}
	catch (const FrgBase_ExceptionString& str)
	{
		message = str.c_str();
	}
	catch (const std::string& s)
	{
		message = s;
	}
	catch (const std::exception& ex)
	{
		message = ex.what();
	}
	catch (...)
	{
		message = "Unknown Exception...";
	}

	if (message != baseMessage)
		throw std::exception(message.c_str());
}

void ForgBaseLib::FrgBase_Application::CatchAndIgnore
(
	const std::function<void()>& func
)
{
	auto mainWindow = Instance()->theParentMainWindow_;
	const auto condition0 = mainWindow->IsConsoleSilent();
	try
	{
		mainWindow->SetConsoleSilent(true);

		CatchAndThrowStdException(func);
	}
	catch (...)
	{
		// Do nothing
	}

	mainWindow->SetConsoleSilent(condition0);
}