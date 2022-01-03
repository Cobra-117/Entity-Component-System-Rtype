/*
** EPITECH PROJECT, 2021
** B-CPP-501-LYN-5-1-rtype-timothe.lacheroy
** File description:
** ClassServer.hpp
*/

#ifndef CLASSSERVER_HPP_
#define CLASSSERVER_HPP_

#include <iostream>
#include <string>
#include <boost/asio.hpp>
#include <boost/json.hpp>

#define SERVPORT 1234
#define MAX_MEMORY_ALLOCATION 2048

using udp = boost::asio::ip::udp;

class Server {
  public:
    Server();
    ~Server();

    int run();
    int receive();
    int send();

    int modifyJson(boost::json::value newjson);
    boost::json::value getJson();

  private:
    boost::json::value _json = {
      { "response", "200" },
      "Player", {"transform", {
                              {"posx", 3},
                              {"posy", 4},
                              {"speed", 4}}
                              }
      };
    boost::asio::io_context _IoContext;
    udp::socket _socket;
    udp::endpoint _sender_endpoint;
    char _data[MAX_MEMORY_ALLOCATION];
};

#endif