#pragma once
#include <string>
#include <boost/asio.hpp>
#include <boost/array.hpp>
#include <boost/optional.hpp>
#include <boost/serialization/serialization.hpp>
#include <boost/archive/binary_iarchive.hpp>

enum class ConnectionType {
	synchro, asynchro
};

class Recept {
private:
	std::string str;
	boost::asio::io_service io_service;
	boost::optional<boost::asio::ip::tcp::acceptor> acceptor;
	boost::optional<boost::asio::ip::tcp::socket> socket;
public:
	Recept(const std::string& ip, const unsigned short port_num = 0);
	Recept(const unsigned short port_num = 0);
	void recept(ConnectionType type);
	template<typename T> T get_data() {
		std::istringstream istr(this->str);
		boost::archive::binary_iarchive ia(istr);
		T data;
		istr >> data;
		return data;
	}
	unsigned short port_number;
	unsigned short partner_port_number;
};
