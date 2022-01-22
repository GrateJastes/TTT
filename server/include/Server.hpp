#pragma once
#include <SFML/Network/TcpListener.hpp>
#include <memory>
#include "Session.hpp"


class Server {
public:
    explicit Server(unsigned short port);
    int run();
    ~Server();

private:
    unsigned short port;
    sf::TcpListener listener;
    std::vector<std::shared_ptr<Session>> sessions;

    void accept_new_user();
};
