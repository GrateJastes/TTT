#pragma once

#include "logger.h"

class Session {
private:
    size_t id;
    FILE *log;

    static size_t next_id;

public:
    Session();
    ~Session();
    void update();
};


