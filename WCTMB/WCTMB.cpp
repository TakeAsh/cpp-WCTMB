// WCTMB.cpp : コンソール アプリケーションのエントリ ポイントを定義します。
//

#include "stdafx.h"
#include <locale>
#include "unicode.h"
#include "strdump.h"

using namespace std;

struct CodePage {
	UINT	id;
	wchar_t	*name;
};

CodePage codePages[] = {
	{ CP_SHIFT_JIS, L"Shift_JIS" },
	{ CP_UTF8,		L"UTF-8" },
};

void convert(wstring wcs, CodePage codepage) {
	auto mbs = w2m(wcs, codepage.id);
	auto errorCode = GetLastError();
	switch (errorCode) {
	case ERROR_SUCCESS:
		wprintf(L"%s:%s\n", codepage.name, dumpW(mbs).c_str());
		break;
	case ERROR_INSUFFICIENT_BUFFER:
		wprintf(L"エラー: バッファが確保できませんでした\n");
		break;
	case ERROR_INVALID_FLAGS:
		wprintf(L"エラー: フラグが正しくありません\n");
		break;
	case ERROR_INVALID_PARAMETER:
		wprintf(L"エラー: パラメータが正しくありません\n");
		break;
	case ERROR_NO_UNICODE_TRANSLATION:
		wprintf(L"エラー: 変換できない文字が含まれていました\n");
		break;
	default:
		wprintf(L"エラー: 変換失敗(%d)\n", errorCode);
		break;
	}
}

int _tmain(int argc, _TCHAR* argv[]) {
	setlocale(LC_ALL, "");

	if (argc < 2) {
		wprintf(L"usage: WCTMB <text>\n");
		return 1;
	}
	wstring wcs(argv[1]);
	wprintf(L"Input: '%s'\nUTF-16:%s\n", wcs.c_str(), dumpW(wcs).c_str());
	for (size_t i = 0; i < _countof(codePages); i++) {
		convert(wcs, codePages[i]);
	}
	return 0;
}

// EOF
