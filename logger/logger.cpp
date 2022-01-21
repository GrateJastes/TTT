#include <stdio.h>
#include <stdarg.h>
#include <string.h>

#include <sys/time.h>
#include <time.h>

#include "logger.h"

static struct {
    FILE *fp;
    int quiet;
} L;

static const char *levels[] = {
    "TRACE", "DEBUG", "INFO", "WARN", "ERROR", "FATAL"
};

static const char *level_colors[] = {
  "\x1b[94m", "\x1b[36m", "\x1b[32m", "\x1b[33m", "\x1b[31m", "\x1b[35m"
};

void log_set_fp(FILE *fp) {
    L.fp = fp;
}

void log_set_quiet(int enable) {
    L.quiet = enable ? 1 : 0;
}

void log_log(int level, const char *file, int line, const char *fmt, ...) {
    struct timeval tv;

    gettimeofday(&tv, NULL);
    int ms = tv.tv_usec / 1000;
    struct tm *lt = localtime(&tv.tv_sec);
    
    if (!L.quiet) {
        va_list args;
        char buf[16];
        buf[strftime(buf, sizeof(buf), "%H:%M:%S", lt)] = 0;
        fprintf(stderr, "%s.%03d %s%-5s\x1b[0m \x1b[90m%s:%d:\x1b[0m ",
                buf, ms, level_colors[level], levels[level], file, line);
        va_start(args, fmt);

        vfprintf(stderr, fmt, args);
        va_end(args);
        fprintf(stderr, "\n");
        fflush(stderr);
    }

    if (L.fp) {
        va_list args;
        char buf[32];
        buf[strftime(buf, sizeof(buf), "%d-%m-%Y %H:%M:%S", lt)] = 0;
        fprintf(L.fp, "%s.%03d %-5s %s:%d: ", buf, ms, levels[level], file, line);
        va_start(args, fmt);
        vfprintf(L.fp, fmt, args);
        va_end(args);
        fprintf(L.fp, "\n");
        fflush(L.fp);
    }
}
