#if !defined( WINVER ) || ( WINVER < 0x0501 )
#undef  WINVER
#define WINVER 0x0501
#endif
#if !defined( _WIN32_WINNT ) || ( _WIN32_WINNT < 0x0501 )
#undef  _WIN32_WINNT
#define _WIN32_WINNT 0x0501
#endif
#include"Send.h"
#include<boost/bind.hpp>

Send::Send(ConnectionType type, const std::string& ip, const unsigned short port) {
	this->type = type;
	this->endpoint = boost::asio::ip::tcp::endpoint(boost::asio::ip::address::from_string(ip), port);
	boost::archive::binary_oarchive oa(this->ostr);
	this->oa = boost::archive::binary_oarchive(this->ostr);
}

Send::Send(ConnectionType type, const unsigned short port) {
	this->type = type;
	this->socket = boost::asio::ip::tcp::socket(this->io);
	this->endpoint = boost::asio::ip::tcp::endpoint(boost::asio::ip::address::from_string("127.0.0.1"), port);
}

template<typename T> void Send::input_data(const T& data) {
	*this->oa << data;
}

void Send::send() {
	this->socket = boost::asio::ip::tcp::socket(this->io);
	std::string buf = this->ostr.str();
	if (this->type == synchro) {
		this->socket->connect(*this->endpoint);
		this->socket->send(boost::asio::buffer(buf.data(), buf.size()));
	}
	else {
		this->socket->async_connect(*this->endpoint, boost::bind(&Send::on_connect, this, boost::asio::placeholders::error));
		this->socket->async_send(buf.data(), buf.size());
	}
}

void Send::on_connect(const boost::system::error_code& error) {
	if (!error) std::cout << "connect success" << std::endl;
	else std::cout << error.message() << std::endl;
}