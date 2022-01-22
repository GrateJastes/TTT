#include "User.hpp"

#include <utility>

User::User(std::string  username, UserSocket socket) {
    this->username = std::move(username);
    this->socket = std::move(socket);

    this->socket->setBlocking(false);
}

const std::string& User::get_username() const {
    return username;
}

sf::Socket::Status User::send_packet(sf::Packet& packet) {
    sf::Socket::Status status;
    do {
        status = socket->send(packet);
    } while (status == sf::Socket::Partial);

    return status;
}

sf::Socket::Status User::receive_packet(sf::Packet& packet) {
    return socket->receive(packet);
}
