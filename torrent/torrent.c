#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>
#include <assert.h>
#include "debug.h"
#include "torrent.h"

void torrent_init(const char *f_name)
{
    FILE *fp = NULL;
    unsigned char *torrent_buf = NULL;
    struct stat s_buf;
    unsigned int f_len = 0;
    unsigned int read_len = 0;

    DBG_INFO("Start torrent_init ...");
    assert(f_name);
    fp = fopen(f_name, "r");
    if(fp == NULL) {
        DBG_ERRNO(errno, "Open \"%s\" failed.", f_name);
        exit(EXIT_FAILURE);
    }

    memset(&s_buf, 0, sizeof(s_buf));
    stat(f_name, &s_buf);
    if(S_ISDIR(s_buf.st_mode)) {
        DBG_ERR("f_name \"%s\" is a directory", f_name);
        exit(EXIT_FAILURE);
    }
    f_len = (unsigned int)s_buf.st_size;
    DBG_LOG("Malloc %d bytes mem for torrent buf", f_len);
    torrent_buf = (unsigned char *)malloc(f_len);
    DBG_LOG("Malloc torrent buf addr = 0x%p", torrent_buf);
    if(torrent_buf == NULL) {
        DBG_ERRNO(errno, "Malloc failed.");
        exit(EXIT_FAILURE);
    }
    memset(torrent_buf, 0, f_len);

    read_len = fread(torrent_buf, sizeof(unsigned char), f_len, fp);
    DBG_LOG("Read %d bytes from torrent, file len = %d", read_len, f_len);
    if(read_len != f_len) {
        DBG_ERR("Read %d bytes, but torrent is %d bytes", read_len, f_len);
        exit(EXIT_FAILURE);
    }

    fclose(fp);
    //printf("%s", torrent_buf);
    free(torrent_buf);
    DBG_INFO("Torrent_init finish");
}
