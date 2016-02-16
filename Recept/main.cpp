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
		return MessageBoxA(NULL, er.what(), "�G���[", MB_OK);
	}
}