#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <getopt.h>
#include <string.h>
#include "main.h"
#include "debug.h"
#include "torrent.h"


int main(const int argc, const char **argv)
{
    parase_cmd_line_arguments(argc, argv);
    return 0;
}
void print_usage(void)
{
    char usage[] = "BT downloader\n"
        "-f Torrent file name\n"
        "-p Path to save file(s)\n"
        "-h help\n";
    fprintf(stderr, "%s", usage);
    exit(EXIT_SUCCESS);
}
void parase_cmd_line_arguments(const int argc, const char *argv[])
{
    int opt;
    DBG_INFO("%d", argc);
    if(argc < 1) {
        print_usage();
    }
    while((opt = getopt((int)argc, (char *const *)argv, "f:p:h")) != -1) {
        switch(opt) {
        case 'f':
            printf("-f %d",(int)strlen(optarg));
            break;
        case 'p':
            break;
        case 'h':
        default:
            print_usage();
            break;
        }
    }
}
