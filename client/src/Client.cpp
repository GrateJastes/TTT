#include <memory>
#include "client/include/Client.hpp"
#include "logger.h"

#include <SFML/Network/TcpSocket.hpp>
#include <SFML/Network/IpAddress.hpp>

#include <cstring>
#include <filesystem>
#include <utility>

namespace fs = std::filesystem;


Client::Client(const std::string &host, unsigned short port, const std::string &username) {
    auto socket = std::make_unique<sf::TcpSocket>();
    if (socket->connect(sf::IpAddress(host), port) != sf::Socket::Done) {
        throw std::runtime_error(std::strerror(errno));
    }

    user = std::make_shared<User>(username, std::move(socket));

    fs::path workdir = fs::current_path();
    std::string log_file_name = "Client_" + username + ".log";
    fs::create_directory(workdir / "logs");
    const fs::path path_to_log = workdir / "logs" / log_file_name.c_str();

    log = fopen(path_to_log.c_str(), "w");
    log_set_fp(log);
    log_set_quiet(0);

    log_info("Connected to host %s:%d", host.c_str(), port);
}

void Client::create_session() {
    send_creation_request();
}

void Client::join_to_session(uint32_t session_id) {

}

int Client::run() {
    while (true) {}
}

void Client::send_creation_request() {
    p_InitMessage init_message;
    init_message.set_action(p_InitMessage_Action_CREATE_LOBBY);
    init_message.set_username(user->get_username());

    p_UserMessage message;
    *message.mutable_init_message() = init_message;

    sf::Packet packet;
    packet << message;

    user->send_packet(packet);
}
