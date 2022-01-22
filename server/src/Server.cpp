#include "Server.hpp"
#include <cstring>
#include <filesystem>

#include <SFML/Network/TcpSocket.hpp>
#include <SFML/Network/Packet.hpp>
#include <iostream>

#include "UserMessage.pb.h"
#include "packaging.hpp"

Server::Server(unsigned short port)
    : port(port)
    , listener() {
    if (listener.listen(port) != sf::Socket::Done) {
        throw std::runtime_error(std::strerror(errno));
    }

    std::cout << "server listening on port: " << port << std::endl;

    listener.setBlocking(false);
}

int Server::run() {
    while (true) {
        accept_new_user();

        for (auto &session : sessions) {
            session->update();
        }
    }
}

Server::~Server() {
    std::cout << "server stopped working" << std::endl;
    listener.close();
}

void Server::accept_new_user() {
    auto socket = std::make_unique<sf::TcpSocket>();
    if (listener.accept(*socket) != sf::Socket::Done) return;

    sf::Packet packet;
    socket->receive(packet);

    p_UserMessage message;
    packet >> message;

    p_InitMessage init_message = message.init_message();
    switch (init_message.action()) {
        case p_InitMessage_Action_CREATE_LOBBY: {
            auto session = std::make_shared<Session>();
            sessions.push_back(session);
            break;
        }
        case p_InitMessage_Action_JOIN_LOBBY: {
            std::cout << "joined" << std::endl;
            break;
        }
    }
}
