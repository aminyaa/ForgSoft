#pragma once
#ifndef _readHexLabel_Header
#define _readHexLabel_Header

#include <label.hxx>
#include <ISstream.hxx>

namespace AutLib
{
	//- Read a hex label from an input stream
	label readHexLabel(ISstream&);
}

#endif // !_readHexLabel_Header
