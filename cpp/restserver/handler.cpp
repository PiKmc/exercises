#include "handler.h"

#include <nlohmann/json.hpp>

handler::handler()
{}

void handler::processRequest(const http::request<http::dynamic_body> &req,
                              http::response<http::dynamic_body> &resp)
{
        resp.version(req.version());
        resp.keep_alive(false);        

        switch(req.method())
        {
        case http::verb::get:
            resp.set(http::field::server, "REST");
            resp.result(http::status::ok);
            prepareGetResponse(req,resp);
            break;
        default:            
            resp.set(http::field::content_type, "text/plain");
            resp.result(http::status::bad_request);
            boost::beast::ostream(resp.body()) << "Bad request";
            break;
        }
}

// Do not edit this function.
// It is generated automatically based on "api.json" file.
void handler::prepareGetResponse(const http::request<http::dynamic_body> &req,
                                 http::response<http::dynamic_body> &resp)
{
        if(req.target() == "/ZXone") {
                nlohmann::json j = {{"message", "Response to get request 1"}};
                resp.set(http::field::content_type, "application/json");
                boost::beast::ostream(resp.body()) << j.dump();
                resp.prepare_payload();
        }
        else if(req.target() == "/two") {
                nlohmann::json j = {{"message", "Response to get request 2"}};
                resp.set(http::field::content_type, "application/json");
                boost::beast::ostream(resp.body()) << j.dump();
                resp.prepare_payload();
        }
        else if(req.target() == "/three") {
                nlohmann::json j = {{"message", "Response to get request 3"}};
                resp.set(http::field::content_type, "application/json");
                boost::beast::ostream(resp.body()) << j.dump();
                resp.prepare_payload();
        }
        else if(req.target() == "/four") {
                nlohmann::json j = {{"message", "Response to get request 4"}};
                resp.set(http::field::content_type, "application/json");
                boost::beast::ostream(resp.body()) << j.dump();
                resp.prepare_payload();
        }
        else if(req.target() == "/five") {
                nlohmann::json j = {{"message", "Response to get request 5"}};
                resp.set(http::field::content_type, "application/json");
                boost::beast::ostream(resp.body()) << j.dump();
                resp.prepare_payload();
        }
        else if(req.target() == "/six") {
                nlohmann::json j = {{"message", "Response to get request 6"}};
                resp.set(http::field::content_type, "application/json");
                boost::beast::ostream(resp.body()) << j.dump();
                resp.prepare_payload();
        }
        else if(req.target() == "/seven") {
                nlohmann::json j = {{"message", "Response to get request 7"}};
                resp.set(http::field::content_type, "application/json");
                boost::beast::ostream(resp.body()) << j.dump();
                resp.prepare_payload();
        }
        else if(req.target() == "/eight") {
                nlohmann::json j = {{"message", "Response to get request 8"}};
                resp.set(http::field::content_type, "application/json");
                boost::beast::ostream(resp.body()) << j.dump();
                resp.prepare_payload();
        }
        else if(req.target() == "/nine") {
                nlohmann::json j = {{"message", "Response to get request 9"}};
                resp.set(http::field::content_type, "application/json");
                boost::beast::ostream(resp.body()) << j.dump();
                resp.prepare_payload();
        }
        else if(req.target() == "/ten") {
                nlohmann::json j = {{"message", "Response to get  request 10"}};
                resp.set(http::field::content_type, "application/json");
                boost::beast::ostream(resp.body()) << j.dump();
                resp.prepare_payload();
        }
        else {
                resp.result(http::status::not_found);
                resp.set(http::field::content_type, "text/plain");
                boost::beast::ostream(resp.body()) << "File not found";
        }
}
