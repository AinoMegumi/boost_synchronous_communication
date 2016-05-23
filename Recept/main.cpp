#if !defined( WINVER ) || ( WINVER < 0x0501 )
#undef  WINVER
#define WINVER 0x0501
#endif
#if !defined( _WIN32_WINNT ) || ( _WIN32_WINNT < 0x0501 )
#undef  _WIN32_WINNT
#define _WIN32_WINNT 0x0501
#endif
#include <iostream>
#include "Recept.h"

int main() {
	try {
		std::string ip;
		std::cout << "相手側のIPアドレスを入力してください。" << std::endl;
		std::cin >> ip;
		Recept recept(ip, 120);
		recept.recept(ConnectionType::asynchro);
		std::string data = recept.get_data<std::string>();
		std::cout << data << std::endl;
		return 0;
	}
	catch (std::exception &er) {
		return MessageBoxA(NULL, er.what(), "エラー", MB_OK);
	}
}