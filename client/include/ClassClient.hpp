/*
** EPITECH PROJECT, 2021
** B-CPP-501-LYN-5-1-rtype-timothe.lacheroy
** File description:
** ClassClient.hpp
*/

#ifndef CLASSSCLIENT_HPP_
#define CLASSSCLIENT_HPP_

#include <iostream>
#include <boost/asio.hpp>
#include <boost/json.hpp>

#define SERVPORT 1234
#define HOSTPORT 1235
#define MAX_MEMORY_ALLOCATION 2048

using udp = boost::asio::ip::udp;

class Client {
  public:
    Client(char *serv, char *port);
    ~Client();

    int receive(bool debugMode);
    int send();

    int SetServer(char *serv);
    std::string GetServer(void);

    int SetValue(boost::json::value newVal);
    boost::json::value GetValue();

  private:
    std::string _server;
    boost::json::value _json =  {
      { "response", "200" },
      "Player", {"transform", {
                              {"posx", 50},
                              {"posy", -2},
                              {"speed", 0}}
                              }
      };
    char _receive[MAX_MEMORY_ALLOCATION];
    boost::asio::io_context _io_context;
    udp::socket _socket;
    udp::endpoint _receiver_endpoint;
    udp::endpoint _sender_endpoint;
};

#endif