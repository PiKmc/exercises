// server.h
// Copyright (c) 2024 by Piotr Kmiecik
// e-mail: info@aserio.pl

#ifndef _SERVER_H_
#define _SERVER_H_

#include <boost/asio.hpp>
#include <string>
#include <memory>

#include "handler.h"

using tcp = boost::asio::ip::tcp;

class server {
public:
        explicit server(const std::string &ipAddr, unsigned short port, std::shared_ptr<handler> hnd);
        void run();
private:
        void loop(tcp::acceptor& acceptor, tcp::socket& socket);

        std::string m_address;
        unsigned short m_port;
        std::shared_ptr<handler> m_handler;
};

#endif // _SERVER_H_
