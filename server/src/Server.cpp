#include "Server.hpp"
#include <cstring>
#include <filesystem>

#include <SFML/Network/TcpSocket.hpp>
#include <SFML/Network/Packet.hpp>

Server::Server(unsigned short port)
    : port(port)
    , listener() {
    if (listener.listen(port) != sf::Socket::Done) {
        throw std::runtime_error(std::strerror(errno));
    }

    listener.setBlocking(false);
}

int Server::run() {
    while (true) {
        accept_new_user();

        for (auto &session : sessions) {
            session.update();
        }
    }
}

Server::~Server() {
    listener.close();
}

void Server::accept_new_user() {
    auto socket = std::make_unique<sf::TcpSocket>();
    if (listener.accept(*socket) == sf::Socket::Done) {
        sf::Packet packet;
        socket->receive(packet);
    }
}
