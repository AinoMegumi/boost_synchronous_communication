#if !defined( WINVER ) || ( WINVER < 0x0501 )
#undef  WINVER
#define WINVER 0x0501
#endif
#if !defined( _WIN32_WINNT ) || ( _WIN32_WINNT < 0x0501 )
#undef  _WIN32_WINNT
#define _WIN32_WINNT 0x0501
#endif
#include "Recept.h"
#include <iostream>

Recept::Recept(const std::string& ip, const unsigned short port_num) {
	this->acceptor = boost::asio::ip::tcp::acceptor(this->io_service, boost::asio::ip::tcp::endpoint(boost::asio::ip::address::from_string(ip), port_num));
	this->socket = boost::asio::ip::tcp::socket(this->io_service);
	this->port_number = acceptor->local_endpoint().port();
}

Recept::Recept(const unsigned short port_num) {
	this->acceptor = boost::asio::ip::tcp::acceptor(this->io_service, boost::asio::ip::tcp::endpoint(boost::asio::ip::address::from_string("127.0.0.1"), port_num));
	this->socket = boost::asio::ip::tcp::socket(this->io_service);
	this->port_number = acceptor->local_endpoint().port();
}

void Recept::recept(ConnectionType type) {
	if (type == ConnectionType::synchro) this->acceptor->accept(*this->socket);
	else this->acceptor->async_accept(*this->socket, [](const boost::system::error_code& error) {
		std::cout << ((!error) ? "connect success" : error.message()) << std::endl;
	});
	this->str.reserve(1024);
	boost::system::error_code error;
	while (error != boost::asio::error::eof) {
		boost::array<char, 1024> buf;
		std::size_t len = socket->read_some(boost::asio::buffer(buf), error);
		this->str.insert(this->str.end(), buf.data(), buf.data() + len);
	}
}
