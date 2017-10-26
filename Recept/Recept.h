#pragma once
#include <string>
#include <boost/asio.hpp>
#include <boost/array.hpp>
#include <boost/optional.hpp>
#include <boost/serialization/serialization.hpp>
#include <boost/archive/text_iarchive.hpp>

class Recept {
private:
	boost::asio::io_service io_service;
	boost::optional<boost::asio::ip::tcp::acceptor> acceptor;
	boost::optional<boost::asio::ip::tcp::socket> socket;
public:
	Recept(const std::string& ip, const unsigned short port_num = 0);
	Recept(const unsigned short port_num = 0);
	void recept();
	std::string GetData();
	unsigned short port_number;
	unsigned short partner_port_number;
};
