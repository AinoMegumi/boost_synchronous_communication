#include"Send.h"

int main() {
	try {
		internal_connect<int>(1, 128);
		return 0;
	}
	catch (std::exception &er) {
		return MessageBoxA(NULL, er.what(), "�G���[", MB_OK);
	}
}