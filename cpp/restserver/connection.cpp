// connection.cpp
// Copyright (c) 2024 by Piotr Kmiecik
// e-mail: info@aserio.pl

#include "connection.h"
#include <memory>

connection::connection(tcp::socket socket, std::shared_ptr<handler> hnd)             
        : m_socket(std::move(socket)),
          m_handler(hnd)
{}

void connection::run()
{
        read();
        check_timeout();
}

void connection::read()
{
        auto self = shared_from_this();
        http::async_read (m_socket, m_buffer, m_request,        
                [self](boost::beast::error_code err, std::size_t rd) {                        
                        boost::ignore_unused(rd);
                        if(!err) {
                                self->m_handler->processRequest(self->m_request,self->m_response);                                
                                self->write();
                        }
                });
}

void connection::write()
{
        auto self = shared_from_this();

        m_response.content_length(m_response.body().size());
        http::async_write(m_socket, m_response,
                [self](boost::beast::error_code err, std::size_t) {
                        self->m_socket.shutdown(tcp::socket::shutdown_send, err);
                        self->m_timer.cancel();
                });
}

void connection::check_timeout()
{
        auto self = shared_from_this();

        m_timer.async_wait(
                [self](boost::beast::error_code err) {
                        if(!err)                                
                                self->m_socket.close(err);
                });
}
