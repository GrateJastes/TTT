#pragma once

#include "UserMessage.pb.h"
#include <SFML/Network/Packet.hpp>
#include "packaging.hpp"
#include "common/User.hpp"
#include <string>

class Client {
public:
    Client(const std::string &host, unsigned short port, const std::string &username);

    void create_session();
    void join_to_session(uint32_t session_id);

    int run();

private:
    FILE *log;

    UserPtr user;

    void send_creation_request();
};


