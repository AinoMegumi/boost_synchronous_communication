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

/*template<typename T> T get_data(std::string ip, unsigned short port_num) {
	boost::asio::io_service io_service;
	boost::asio::ip::tcp::acceptor acceptor(io_service, boost::asio::ip::tcp::endpoint(boost::asio::ip::address::from_string(ip), port_num));
	boost::asio::ip::tcp::socket socket(io_service);
	acceptor.accept(socket);
	std::string str;
	str.reserve(1024);
	boost::system::error_code error;
	while (error != boost::asio::error::eof) {
		boost::array<char, 1024> buf;
		std::size_t len = socket.read_some(boost::asio::buffer(buf), error);
		str.insert(str.end(), buf.data(), buf.data() + len);
	}
	std::istringstream istr(str);
	boost::archive::binary_iarchive ia(istr);
	T data;
	istr >> data;
	return data;
}*/

int main() {
	try {
		Recept recept("127.0.0.1", 128);
		recept.recept(asynchro);
		std::string data = recept.get_data<std::string>();
		/*std::string data = get_data<std::string>("127.0.0.1", 256);*/
		std::cout << data << std::endl;
		return 0;
	}
	catch (std::exception &er) {
		return MessageBoxA(NULL, er.what(), "ƒGƒ‰[", MB_OK);
	}
}