#if !defined( WINVER ) || ( WINVER < 0x0501 )
#undef  WINVER
#define WINVER 0x0501
#endif
#if !defined( _WIN32_WINNT ) || ( _WIN32_WINNT < 0x0501 )
#undef  _WIN32_WINNT
#define _WIN32_WINNT 0x0501
#endif
#include"Send.h"
#include<iostream>

int main() {
	try {
		std::string str;
		std::cin >> str;
		Send s(asynchro);
		s.input_data<int>(15);
		s.send();
		return 0;
	}
	catch (std::exception &er) {
		return MessageBoxA(NULL, er.what(), "�G���[", MB_OK);
	}
}