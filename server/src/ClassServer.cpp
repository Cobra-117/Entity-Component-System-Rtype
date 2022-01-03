/*
** EPITECH PROJECT, 2021
** B-CPP-501-LYN-5-1-rtype-timothe.lacheroy
** File description:
** ClassServer.cpp
*/

#include "../include/ClassServer.hpp"

Server::Server() : _socket(_IoContext, udp::endpoint(udp::v4(), SERVPORT)) {
    receive();
}

Server::~Server() {

}

int Server::run() {
    this->_IoContext.run();
    return 0;
}

void clear_data(char *data)
{
    for (int i = 0; data[i] != '\0'; i++) {
        data[i] = 0;
    }
}

int Server::receive() {
    _socket.async_receive_from(boost::asio::buffer(_data, MAX_MEMORY_ALLOCATION), _sender_endpoint,
    [this] (boost::system::error_code ec, std::size_t received_bytes) {
        if (!ec && received_bytes > 0) {
            std::cout << _data << std::endl;
            clear_data(_data);
            send();
        } else
            receive();
    });
    return 0;
}

int Server::send() {
    std::string myStr = boost::json::serialize(this->_json);
    _socket.async_send_to(boost::asio::buffer(myStr.c_str(), myStr.length()), _sender_endpoint,
    [this] (boost::system::error_code ec, std::size_t received_bytes) {
        receive();
    });
    return 0;
}

int Server::modifyJson(boost::json::value newjson)
{
    try {
        this->_json = newjson;
        return 0;
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
        return 84;
    }
    return 0;
}

boost::json::value Server::getJson()
{
    return this->_json;
}