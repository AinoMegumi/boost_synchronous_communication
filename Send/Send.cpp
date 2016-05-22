#if !defined( WINVER ) || ( WINVER < 0x0501 )
#undef  WINVER
#define WINVER 0x0501
#endif
#if !defined( _WIN32_WINNT ) || ( _WIN32_WINNT < 0x0501 )
#undef  _WIN32_WINNT
#define _WIN32_WINNT 0x0501
#endif
#include "Send.h"
#include <boost/bind.hpp>
#include <regex>
#include <numeric>
#include <stdexcept>
using namespace boost::asio;

Send::Send(ConnectionType type, const std::string& ip, std::ostringstream& ostr, const unsigned short port)
	: type(type), oa(ostr) {
	this->socket = ip::tcp::socket(this->io);
	if (this->is_ipv4_address(ip)) this->endpoint = ip::tcp::endpoint(ip::address_v4::from_string(ip), port);
	else throw std::runtime_error("IPv4ˆÈŠO‚Ì•¶Žš—ñ‚ª“ü—Í‚³‚ê‚Ü‚µ‚½B");
}

Send::Send(ConnectionType type, std::ostringstream& ostr, const unsigned short port) : type(type), oa(ostr) {
	this->socket = ip::tcp::socket(this->io);
	this->endpoint = ip::tcp::endpoint(ip::address::from_string("127.0.0.1"), port);
}

bool Send::is_ipv4_address(const std::string& ip) {
	std::regex reg(R"((\d{ 1,3 })\.(\d{ 1,3 })\.(\d{ 1,3 })\.(\d{ 1,3 }))"); // ‚±‚±‚©‚ç“ä‚ÌException
	std::smatch match;
	std::regex_search(ip, match, reg);
	return (5 == match.size() &&
		std::all_of(match.begin() + 1, match.end(), [](const auto& m) noexcept {
		try {
			const auto i = std::stoi(m.str());
			return (0 <= i && i <= 255);
		}
		catch (const std::exception&) {
			return false;
		}
	}));
}

void Send::send(const std::ostringstream& ostr) {
	this->socket = ip::tcp::socket(this->io);
	std::string buf = ostr.str();
	if (this->type == synchro) {
		this->socket->connect(*this->endpoint);
		this->socket->send(boost::asio::buffer(buf.data(), buf.size()));
	}
	else {
		this->socket->async_connect(*this->endpoint, boost::bind(&Send::on_connect, this, placeholders::error));
		this->socket->async_send(boost::asio::buffer(buf.data(), buf.size()),
			[](const boost::system::error_code& error, std::size_t size) {
				if (!error) std::cout << "send success" << std::endl;
				else std::cout << error.message() << std::endl;
			}
		);
	}
}

void Send::on_connect(const boost::system::error_code& error) {
	if (!error) std::cout << "connect success" << std::endl;
	else std::cout << error.message() << std::endl;
}
