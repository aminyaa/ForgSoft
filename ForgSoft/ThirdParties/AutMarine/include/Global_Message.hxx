#pragma once
#ifndef _Global_Message_Header
#define _Global_Message_Header

#include <iostream>
#include <sstream>
#include <memory>

namespace AutLib
{

	class Global_Message
	{

	public:

		virtual void SendInfo(const std::string& theStream) = 0;

		virtual void SendWarning(const std::string& theStream) = 0;

		virtual void SendError(const std::string& theStream) = 0;

		virtual std::ostringstream& GetMessage() = 0;

		virtual std::string SendMessage() = 0;
	};

	class Global_MessageOstream
		: public Global_Message
	{

		/*Private Data*/

		std::shared_ptr<std::ostringstream> theStream_;

	public:

		Global_MessageOstream()
		{
			theStream_ = std::make_shared<std::ostringstream>();
		}

		void SendInfo(const std::string& theStream) override
		{
			std::cout << " Info: " << theStream << std::endl;
		}

		void SendWarning(const std::string& theStream) override
		{
			std::cout << " Warning: " << theStream << std::endl;
		}

		void SendError(const std::string& theStream) override
		{
			std::cout << " Error: " << theStream << std::endl;
		}

		std::ostringstream& GetMessage() override
		{
			return *theStream_;
		}

		std::string SendMessage() override
		{
			std::string message = theStream_->str();
			theStream_ = std::make_shared<std::ostringstream>();

			return std::move(message);
		}
	};

	extern std::shared_ptr<Global_Message> gl_messenger;
}

#define GET_MESSAGE AutLib::gl_messenger->GetMessage()
#define SEND_MESSAGE AutLib::gl_messenger->SendMessage()

#define SEND_INFO AutLib::gl_messenger->SendInfo(SEND_MESSAGE);
#define SEND_WARNING AutLib::gl_messenger->SendWarning(SEND_MESSAGE);
#define SEND_ERROR AutLib::gl_messenger->SendError(SEND_MESSAGE);

#endif // !_Global_Message_Header
