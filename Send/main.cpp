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
		std::cout << "相手側のIPアドレスを入力してください。" << std::endl;
		std::cin >> str;
		Send s(str, ostr, 120);
		s.input_data<std::string>("Hello World!");
		s.input_data<std::string>("あいうえお");
		s.send(ostr);
		return 0;
	}
	catch (std::exception &er) {
		return MessageBoxA(NULL, er.what(), "エラー", MB_OK);
	}
}