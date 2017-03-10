# WCTMB
convert unicode. WideChar To MultiByte / MultiByte to WideChar.

# Functions

## Usage
```cpp
#include "unicode.h"
```

## w2m()
convert WideChar to MultiByte.
```cpp
std::string w2m(
  const std::wstring &wcs,
  const UINT codepage = CP_THREAD_ACP 
)
```

## m2w()
convert MultiByte to WideChar.
```cpp
std::wstring m2w(
  const std::string &mbs,
  const UINT codepage = CP_THREAD_ACP 
)
```

## Error Code
| GetLastError()               | Description                                           |
| ---------------------------- | ------------------------------------------------------------------------------- |
| ERROR_SUCCESS                | The operation completed successfully.                                           |
| ERROR_INSUFFICIENT_BUFFER    | The data area passed to a system call is too small.                             |
| ERROR_INVALID_FLAGS          | Invalid flags.                                                                  |
| ERROR_INVALID_PARAMETER      | The parameter is incorrect.                                                     |
| ERROR_NO_UNICODE_TRANSLATION | No mapping for the Unicode character exists in the target multi-byte code page. |

# Usage sample
```
> WCTMB ABCxyz高髙崎﨑吉𠮷
Input: 'ABCxyz高髙崎﨑吉??'
UTF-16: 0041 0042 0043 0078 0079 007A 9AD8 9AD9 5D0E FA11 5409 D842 DFB7
Shift_JIS: 41 42 43 78 79 7A 8D 82 FB FC 8D E8 FA B1 8B 67 3F 3F
UTF-8: 41 42 43 78 79 7A E9 AB 98 E9 AB 99 E5 B4 8E EF A8 91 E5 90 89 F0 A0 AE B7
```
