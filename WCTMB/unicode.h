/**
@file	unicode.h

ユニコード(wide character string)とShift_JIS等(multibyte character string)の変換
*/
#pragma once

#include <string>
#include <windows.h>

/**
コードページ識別子

http://msdn.microsoft.com/en-us/library/dd317756.aspx
*/
enum CODE_PAGE_IDENTIFIERS : UINT {
	CP_SHIFT_JIS = 932,	///< ANSI/OEM Japanese; Japanese (Shift-JIS)
	CP_LATIN1 = 1252,	///< ANSI Latin 1; Western European (Windows)
};

/**
Unicodeから指定のコードページへ変換。

@return	マルチバイト文字列。
| GetLastError()               | エラー内容                                           |
| ---------------------------- | ---------------------------------------------------- |
| ERROR_SUCCESS                | 正常終了                                             |
| ERROR_INSUFFICIENT_BUFFER    | バッファが確保できなかった。                         |
| ERROR_INVALID_FLAGS          | フラグが正しくなかった。                             |
| ERROR_INVALID_PARAMETER      | NULLが入力された、またはパラメータが正しくなかった。 |
| ERROR_NO_UNICODE_TRANSLATION | 不正なユニコードが含まれていた。                     |
@attention
スレッドのコードページに該当する文字が無くても、エラー(ERROR_NO_UNICODE_TRANSLATION)にはならない。<br>
単に該当文字が DefaultChar(CP932の場合は'?')に変換される。
*/
std::string w2m(
	const std::wstring &wcs,			///< [in] 変換元の文字列。
	const UINT codepage = CP_THREAD_ACP	///< [in] 変換に使用するコードページ。
);

/**
指定のコードページからUnicodeへ変換。

@return	Unicode文字列。
| GetLastError()               | エラー内容                                           |
| ---------------------------- | ---------------------------------------------------- |
| ERROR_SUCCESS                | 正常終了                                             |
| ERROR_INSUFFICIENT_BUFFER    | バッファが確保できなかった。                         |
| ERROR_INVALID_FLAGS          | フラグが正しくなかった。                             |
| ERROR_INVALID_PARAMETER      | NULLが入力された、またはパラメータが正しくなかった。 |
| ERROR_NO_UNICODE_TRANSLATION | 不正なユニコードが含まれていた。                     |
*/
std::wstring m2w(
	const std::string &mbs,				///< [in] 変換元の文字列。
	const UINT codepage = CP_THREAD_ACP	///< [in] 変換に使用するコードページ。
);

// EOF
