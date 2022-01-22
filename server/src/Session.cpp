#include "Session.hpp"
#include <filesystem>
#include <iostream>
#include "UserMessage.pb.h"

#include "logger.h"

namespace fs = std::filesystem;

size_t Session::next_id = 0;

void Session::update() {

}

Session::Session(): id(next_id++) {
    fs::path workdir = fs::current_path();
    std::string logfile_name = "Session_" + std::to_string(id) + ".log";
    fs::create_directory(workdir / "logs");

    const fs::path path_to_log = workdir / "logs" / logfile_name.c_str();

    std::cout << "logfile created: " << path_to_log.c_str() << std::endl;

    log = fopen(path_to_log.c_str(), "w");
    log_set_fp(log);
    log_set_quiet(0);
    log_info("Session created...");
}

Session::~Session() {
    log_warn("Session ended.");
    fclose(log);
}
