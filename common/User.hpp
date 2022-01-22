#pragma once

#include <SFML/Network/TcpSocket.hpp>
#include <SFML/Network/Packet.hpp>

#include <memory>

using UserSocket = std::unique_ptr<sf::TcpSocket>;

class User {
public:
    User(std::string  username, UserSocket socket);

    const std::string &get_username() const;

    sf::Socket::Status send_packet(sf::Packet& packet);

    sf::Socket::Status receive_packet(sf::Packet& packet);
private:
    std::string username;
    UserSocket socket;
};

using UserPtr = std::shared_ptr<User>;
