#include <SFML/Network/TcpSocket.hpp>

#include "Server.hpp"


int main() {
    Server server(5555);
    server.run();
    return 0;
}
