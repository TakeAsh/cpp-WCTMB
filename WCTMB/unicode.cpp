#include "stdafx.h"
#include <windows.h>	// WideCharToMultiByte(), SetLastError()
#include <memory>		// std::unique_ptr, std::make_unique
#include "unicode.h"

using namespace std;

std::string w2m(
	const std::wstring &wcs,
	const UINT codepage
) {
	SetLastError(ERROR_SUCCESS);
	unique_ptr<char[]> mbs = NULL;
	int len = WideCharToMultiByte(codepage, 0, wcs.c_str(), -1, NULL, 0, NULL, NULL);
	if (len > 0 && (mbs = make_unique<char[]>(len))) {
		WideCharToMultiByte(codepage, 0, wcs.c_str(), -1, mbs.get(), len, NULL, NULL);
	}
	return string(mbs == NULL ? NULL : mbs.get());
}

std::wstring m2w(
	const std::string &mbs,
	const UINT codepage
) {
	SetLastError(ERROR_SUCCESS);
	unique_ptr<wchar_t[]> wcs = NULL;
	int len = MultiByteToWideChar(codepage, 0, mbs.c_str(), -1, NULL, 0);
	if (len > 0 && (wcs = make_unique<wchar_t[]>(len))) {
		MultiByteToWideChar(codepage, 0, mbs.c_str(), -1, wcs.get(), len);
	}
	return wstring(wcs == NULL ? NULL : wcs.get());
}

// EOF
