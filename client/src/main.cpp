#include <string>
#include <iostream>
#include "client/include/Client.hpp"

static void usage() {
    std::cerr << "Usage: ./client <username> <host> <port> (create | join <lobby_num>)" << std::endl;
}

int main(int argc, char** argv) {
    auto username = std::string(argv[1]);
    auto host = std::string(argv[2]);
    auto port = static_cast<unsigned short>(std::stoul(std::string(argv[3])));

    Client client(host, port, username);

    auto cmd = std::string(argv[4]);
    if (cmd == "create") {
        client.create_session();
    } else if (cmd == "join") {
        auto session_id = static_cast<uint32_t>(std::stoul(std::string(argv[5])));
        client.join_to_session(session_id);
    } else {
        usage();
        return -1;
    }

    return client.run();
}

//class A {
//public:
//    std::unique_ptr<int> local;
//
//
//    A(int a, std::unique_ptr<int> b) : local(std::move(b)){
//        std::cout << a+*local << std::endl;
//    }
//    void tpe() const {
//        std::cout << *local;
//    }
//
//};
//
//
//int main() {
//    std::shared_ptr<A> a;
//    auto b = std::make_unique<int>(42);
//
//    a = std::make_shared<A>(5, std::move(b));
//    a->tpe();
//
//    return 0;
//}
