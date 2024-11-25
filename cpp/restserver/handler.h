// handler.h
// Copyright (c) 2024 by Piotr Kmiecik
// e-mail: info@aserio.pl

#ifndef _HANDLER_H_
#define _HANDLER_H_

#include <boost/beast/core.hpp>
#include <boost/beast/http.hpp>

namespace http = boost::beast::http;

class handler {
public:
        handler();
        void processRequest(const http::request<http::dynamic_body> &request,
                            http::response<http::dynamic_body> &response);
private:
        void prepareGetResponse(const http::request<http::dynamic_body> &request,
                                http::response<http::dynamic_body> &response);

};

#endif // _HANDLER_H_
