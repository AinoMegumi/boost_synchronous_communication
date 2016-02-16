#pragma once
#include<string>
#include<boost/asio.hpp>
#include<boost/array.hpp>
#include<boost/optional.hpp>
#include<boost/serialization/serialization.hpp>
#include<boost/archive/binary_iarchive.hpp>

class Recept {
private:
	std::string str;
	boost::optional<boost::asio::ip::tcp::acceptor> acceptor;
	boost::optional<boost::asio::ip::tcp::socket> socket;
public:
	Recept(std::string ip, int port_num = 0);
	void recept();
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