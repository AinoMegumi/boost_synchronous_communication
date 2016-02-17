#if !defined( WINVER ) || ( WINVER < 0x0501 )
#undef  WINVER
#define WINVER 0x0501
#endif
#if !defined( _WIN32_WINNT ) || ( _WIN32_WINNT < 0x0501 )
#undef  _WIN32_WINNT
#define _WIN32_WINNT 0x0501
#endif
#include<iostream>
#include"Recept.h"

int main() {
	try {
		Recept recept("127.0.0.1", 128);
		recept.recept();
		std::string data = recept.get_data<std::string>();
		std::cout << data << std::endl;
		return 0;
	}
	catch (std::exception &er) {
		return MessageBoxA(NULL, er.what(), "ƒGƒ‰[", MB_OK);
	}
}