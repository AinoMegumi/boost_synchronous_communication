﻿#if !defined( WINVER ) || ( WINVER < 0x0501 )
#undef  WINVER
#define WINVER 0x0501
#endif
#if !defined( _WIN32_WINNT ) || ( _WIN32_WINNT < 0x0501 )
#undef  _WIN32_WINNT
#define _WIN32_WINNT 0x0501
#endif
#include "Send.h"
#include <iostream>
#include <stdexcept>

int main() {
	try {
		std::ostringstream ostr;
		std::string str;
		std::cin >> str;
		Send s(asynchro, str, ostr, 120);
		s.input_data<int>(15);
		s.send(ostr);
		return 0;
	}
	catch (std::exception &er) {
		return MessageBoxA(NULL, er.what(), "エラー", MB_OK);
	}
}