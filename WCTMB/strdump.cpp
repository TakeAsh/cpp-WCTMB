#include "stdafx.h"
#include <vector>
#include "strdump.h"

using namespace std;

const int BUFFER_LEN = 8;

std::wstring dumpW(
	std::string mbs
) {
	wstring ret;
	wchar_t buffer[BUFFER_LEN];
	for (size_t i = 0; i < mbs.length(); i++) {
		swprintf_s(buffer, L" %02X", (unsigned char)mbs[i]);
		ret += buffer;
	}
	return ret;
}

std::wstring dumpW(
	std::wstring wcs
) {
	wstring ret;
	wchar_t buffer[BUFFER_LEN];
	for (size_t i = 0; i < wcs.length(); i++) {
		swprintf_s(buffer, L" %04X", wcs[i]);
		ret += buffer;
	}
	return ret;
}

std::string dumpA(
	std::string mbs
) {
	string ret;
	char buffer[BUFFER_LEN];
	for (size_t i = 0; i < mbs.length(); i++) {
		sprintf_s(buffer, " %02X", (unsigned char)mbs[i]);
		ret += buffer;
	}
	return ret;
}

std::string dumpA(
	std::wstring wcs
) {
	string ret;
	char buffer[BUFFER_LEN];
	for (size_t i = 0; i < wcs.length(); i++) {
		sprintf_s(buffer, " %04X", wcs[i]);
		ret += buffer;
	}
	return ret;
}

// EOF
