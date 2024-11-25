#include "server.h"
#include "connection.h"

server::server(const std::string &ipAddr, unsigned short port, std::shared_ptr<handler> hnd)
        : m_address(ipAddr), m_port(port),m_handler(std::move(hnd))
{}

void server::run()
{       
        auto const address = boost::asio::ip::make_address(m_address);

        boost::asio::io_context ioc{1};
        tcp::socket socket{ioc};        
        tcp::acceptor acceptor{ioc, {address, m_port}};
        loop(acceptor, socket);
        ioc.run();
}

void server::loop(tcp::acceptor& acceptor, tcp::socket& socket)
{
        acceptor.async_accept(socket,
                [&](boost::beast::error_code err)
                {
                        if(!err)
                                std::make_shared<connection>(std::move(socket),m_handler)->run();
                        loop(acceptor, socket);
                }
        );
}
