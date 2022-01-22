#include "packaging.hpp"

#include <string>
#include <SFML/Network/Packet.hpp>


sf::Packet &operator<<(sf::Packet &packet, const p_UserMessage &message) {
    std::string data;
    message.SerializeToString(&data);

    return packet << data;
}

sf::Packet &operator>>(sf::Packet &packet, p_UserMessage &message) {
    std::string data;
    packet >> data;
    message.ParseFromString(data);

    return packet;
}
