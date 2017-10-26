#pragma once
#include <string>
#include <boost/asio.hpp>
#include <boost/array.hpp>
#include <boost/optional.hpp>
#include <boost/serialization/serialization.hpp>
#include <boost/archive/text_oarchive.hpp>

class Send {
private:
	boost::asio::io_service io;
	boost::optional<boost::asio::ip::tcp::socket> socket;
	boost::optional<boost::asio::ip::tcp::endpoint> endpoint;
	boost::optional<boost::archive::text_oarchive> oa;
	bool is_ipv4_address(const std::string& ip);
public:
	Send(const std::string& ip, std::ostringstream& ostr, const unsigned short port = 0);
	Send(std::ostringstream& ostr, const unsigned short port = 0);
	template<typename T> void input_data(const T& data) {
		*this->oa << data;
	}
	void send(const std::ostringstream& ostr);
};
