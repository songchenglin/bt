#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <getopt.h>
#include <string.h>
#include "main.h"
#include "debug.h"
#include "torrent.h"


static main_argument_t main_arg;
int main(const int argc, const char **argv)
{
    parase_cmd_line_arguments(argc, argv);
    torrent_init(main_arg.torrent_name);
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
void print_version(void)
{
    char version[] = "BT downloader\n"
        "Version 1.0\n"
        "Author by Songchenglin\n";
    fprintf(stderr, "%s", version);
    exit(EXIT_SUCCESS);
}
void parase_cmd_line_arguments(const int argc, const char *argv[])
{
    int opt;
    int len;
    DBG_LOG("Get  %d  argument(s) from cmd line", argc);
    if(argc < 2) {
        print_usage();
    }
    while((opt = getopt((int)argc, (char *const *)argv, "hf:p:v")) != -1) {
        switch(opt) {
        case 'f':
            len = strlen(optarg);
            main_arg.torrent_name = (unsigned char *)malloc(len+1);
            memcpy(main_arg.torrent_name, optarg, len+1);
            DBG_INFO("Torrent: %s", main_arg.torrent_name);
            break;
        case 'p':
            len = strlen(optarg);
            main_arg.path = (unsigned char *)malloc(len+1);
            memcpy(main_arg.path, optarg, len+1);
            DBG_INFO("Save to path: %s", main_arg.path);
            break;
        case 'v':
            print_version();
            break;
        case 'h':
        default:
            print_usage();
            break;
        }
    }
    if(main_arg.torrent_name == NULL) {
        DBG_ERR("No torrent input");
        print_usage();
    }
    if(main_arg.path == NULL) {
        DBG_INFO("No save path input, use default");
        main_arg.path = "./";
    }
}
