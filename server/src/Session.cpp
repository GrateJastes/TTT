#include "Session.hpp"
#include <filesystem>

namespace fs = std::filesystem;

void Session::update() {

}

Session::Session() {
    fs::path workdir = fs::current_path();
    std::string logfile_name = std::format
}
