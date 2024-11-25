// connection.h
// Copyright (c) 2024 by Piotr Kmiecik
// e-mail: info@aserio.pl

#ifndef _CONNECTION_H_
#define _CONNECTION_H_

#include <boost/beast/core.hpp>
#include <boost/beast/http.hpp>
#include <boost/beast/version.hpp>
#include <boost/asio.hpp>
#include <memory>

#include "handler.h"

namespace http = boost::beast::http;
using tcp = boost::asio::ip::tcp; 

class connection : public std::enable_shared_from_this<connection>
{
public:
        connection(tcp::socket socket, std::shared_ptr<handler> hnd);
        void run();

private:
        void read();
        void write();
        void check_timeout();

private:
        tcp::socket m_socket;
        http::request<http::dynamic_body> m_request;
        http::response<http::dynamic_body> m_response;

        boost::beast::flat_buffer m_buffer{8192};
        boost::asio::basic_waitable_timer<std::chrono::steady_clock> m_timer {
                m_socket.get_executor(), std::chrono::seconds(15)};
        std::shared_ptr<handler> m_handler;
};

#endif // _CONNECTION_H_