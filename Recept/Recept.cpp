#include"Recept.h"

Recept::Recept(std::string ip, int port_num) {
	boost::asio::io_service io_service;
	this->acceptor = boost::asio::ip::tcp::acceptor(io_service, boost::asio::ip::tcp::endpoint(boost::asio::ip::address::from_string(ip), port_num));
	this->socket = boost::asio::ip::tcp::socket(io_service);
	this->port_number = acceptor->local_endpoint().port();
}

void Recept::recept() {
	this->acceptor->accept(*socket); // �����ŃG���[�N�����Ă�
	this->str.reserve(1024);
	boost::system::error_code error;
	while (error != boost::asio::error::eof) {
		std::size_t len = socket->read_some(boost::asio::buffer(this->buf), error);
		this->str.insert(this->str.end(), this->buf.data(), this->buf.data() + len);
	}
}