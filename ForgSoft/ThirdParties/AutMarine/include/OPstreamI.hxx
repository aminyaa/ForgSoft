#pragma once
template<class T>
inline void AutLib::OPstream::writeToBuffer(const T& t)
{
	writeToBuffer(&t, sizeof(T), sizeof(T));
}