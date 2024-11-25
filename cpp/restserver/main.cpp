// main.cpp
// Copyright (c) 2024 by Piotr Kmiecik
// e-mail: info@aserio.pl

#include <iostream>
#include <memory>
#include <string>

#include "handler.h"
#include "server.h"

int main(int argc, char* argv[])
{
    try {
        std::shared_ptr<handler> h = std::make_shared<handler>();
        server srv = server("127.0.0.1", (unsigned short)7654, h);
        srv.run();
    }
    catch(std::exception const& err) {
        std::cerr << "Error: " << err.what() << std::endl;
        return EXIT_FAILURE;
    }
}
