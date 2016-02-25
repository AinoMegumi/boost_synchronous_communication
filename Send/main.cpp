#if !defined( WINVER ) || ( WINVER < 0x0501 )
#undef  WINVER
#define WINVER 0x0501
#endif
#if !defined( _WIN32_WINNT ) || ( _WIN32_WINNT < 0x0501 )
#undef  _WIN32_WINNT
#define _WIN32_WINNT 0x0501
#endif
#include"Send.h"

int main() {
	try {
		internal_connect(std::string("arikitari_na_world!"), 256);
		return 0;
	}
	catch (std::exception &er) {
		return MessageBoxA(NULL, er.what(), "ƒGƒ‰[", MB_OK);
	}
}