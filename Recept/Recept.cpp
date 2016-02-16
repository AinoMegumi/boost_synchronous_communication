#include"Recept.h"

Recept::Recept(std::string ip, int port_num) {
	this->acceptor = boost::asio::ip::tcp::acceptor(this->io_service, boost::asio::ip::tcp::endpoint(boost::asio::ip::address::from_string(ip), port_num));
	boost::asio::ip::tcp::socket(this->io_service);
	this->port_number = acceptor->local_endpoint().port();
}

void Recept::recept() {
	this->acceptor->accept(*socket); // ‚±‚±‚ÅƒGƒ‰[‹N‚±‚µ‚Ä‚é
	this->str.reserve(1024);
	boost::system::error_code error;
	while (error != boost::asio::error::eof) {
		std::size_t len = socket->read_some(boost::asio::buffer(this->buf), error);
		this->str.insert(this->str.end(), this->buf.data(), this->buf.data() + len);
	}
}