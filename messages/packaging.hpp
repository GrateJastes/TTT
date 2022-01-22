#pragma once

#include <SFML/Network/Packet.hpp>
#include <string>
#include <google/protobuf/message.h>

#include "UserMessage.pb.h"

sf::Packet &operator<<(sf::Packet &packet, const p_UserMessage &message);

sf::Packet &operator>>(sf::Packet &packet, p_UserMessage &message);
