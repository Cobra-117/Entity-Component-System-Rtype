/*
** EPITECH PROJECT, 2021
** B-CPP-501-LYN-5-1-rtype-timothe.lacheroy
** File description:
** ClassClient.cpp
*/

#include "../include/ClassClient.hpp"

void clear_data(char *data)
{
    for (int i = 0; data[i] != '\0'; i++) {
        data[i] = 0;
    }
}

Client::Client(char *serv, char *port) : _socket(_io_context, udp::endpoint(udp::v4(), atoi(port))) {
    this->_server = std::string(serv);
    clear_data(_receive);

    udp::resolver resolver(_io_context);
    _receiver_endpoint = *resolver.resolve(udp::v4(), _server, "1234").begin();
}

Client::~Client() {
    _socket.close();
}

int Client::SetServer(char *serv) {
    try {
        this->_server = std::string(serv);
        return 0;
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}

std::string Client::GetServer() {
    return this->_server;
}

int Client::receive(bool debugMode) {
    try {
        _socket.receive_from(boost::asio::buffer(_receive, MAX_MEMORY_ALLOCATION), _sender_endpoint);
        if (debugMode == true)
            std::cout << _receive << std::endl;
        clear_data(_receive);
        return 0;
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
        return 84;
    }
    return 0;
}

int Client::send() {
    try {
        std::string myStr = boost::json::serialize(_json);
        _socket.send_to(boost::asio::buffer(myStr), _receiver_endpoint);
        return 0;
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
        return 84;
    }
    return 0;
}

int Client::SetValue(boost::json::value newVal)
{
    try {
        this->_json = newVal;
        return 0;
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
        return 84;
    }
    return 0;
}

boost::json::value Client::GetValue()
{
    return this->_json;
}