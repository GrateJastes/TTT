#include <SFML/Graphics.hpp>
#include <SFML/Network/TcpSocket.hpp>
#include <SFML/Network/UdpSocket.hpp>
#include <memory>

#include "Server.hpp"


int main() {
    auto socket = std::make_unique<sf::TcpSocket>();
    return 0;
}
