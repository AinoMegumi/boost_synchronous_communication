#pragma once
#include <string>
#include <boost/asio.hpp>
#include <boost/array.hpp>
#include <boost/optional.hpp>
#include <boost/serialization/serialization.hpp>
#include <boost/archive/binary_oarchive.hpp>

enum ConnectionType {
	synchro, asynchro
};

class Send {
private:
	ConnectionType type;
	boost::asio::io_service io;
	boost::optional<boost::asio::ip::tcp::socket> socket;
	boost::optional<boost::asio::ip::tcp::endpoint> endpoint;
	boost::optional<boost::archive::binary_oarchive> oa;
	void on_connect(const boost::system::error_code& error);
	bool is_ipv4_address(const std::string& ip);
public:
	Send(ConnectionType type, const std::string& ip, std::ostringstream& ostr, const unsigned short port = 0);
	Send(ConnectionType type, std::ostringstream& ostr, const unsigned short port = 0);
	template<typename T> void input_data(const T& data) {
		*this->oa << data;
	}
	void send(const std::ostringstream& ostr);
};
