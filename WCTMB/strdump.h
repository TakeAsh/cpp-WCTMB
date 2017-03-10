#pragma once

#include <string>

/**
16進文字列に変換する。
@return	16進文字列
*/
std::wstring dumpW(
	std::wstring wcs	///< [in] 変換元文字列
);

/**
16進文字列に変換する。
@return	16進文字列
*/
std::wstring dumpW(
	std::string mbs	///< [in] 変換元文字列
);

/**
16進文字列に変換する。
@return	16進文字列
*/
std::string dumpA(
	std::wstring wcs	///< [in] 変換元文字列
);

/**
16進文字列に変換する。
@return	16進文字列
*/
std::string dumpA(
	std::string mbs	///< [in] 変換元文字列
);

// EOF
