#ifndef _MAIN_H_
#define _MAIN_H_
#include "debug.h"

typedef struct {
    unsigned char *torrent_name;
    unsigned char *path;
    debug_level_t dbg_level; 
}__attribute__((packed)) main_argument_t;

__attribute__((noreturn))void print_usage(void);
__attribute__((noreturn))void print_version(void);
void parase_cmd_line_arguments(const int argc, const char *argv[]);
#endif
