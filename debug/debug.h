#ifndef _DEBUG_H_
#define _DEBUG_H_
#include <stdio.h>
#include <string.h>

typedef enum {
    DEBUG_LEVEL_INFO = 0, //Common info
    DEBUG_LEVEL_LOG  = 1, //Debug info
    DEBUG_LEVEL_ERR  = 2, //Fatal error, pirnt to stderr
    DEBUG_LEVEL_MAX  = 3, //Invalid value
}debug_level_t;
extern unsigned int g_debug;

void debug_log_print(debug_level_t level, const char *fmt, ...);
void debug_dump_hex(const unsigned char *buf, int len);

#define DBG_INFO(fmt, args...) \
    do { \
        debug_log_print(DEBUG_LEVEL_INFO, "[%s:%d](%s)"fmt"\n", \
                __FILE__, __LINE__, __func__, ##args); \
    } while(0)
#define DBG_LOG(fmt, args...) \
    do { \
        debug_log_print(DEBUG_LEVEL_LOG, "[%s:%d](%s)"fmt"\n", \
                __FILE__, __LINE__, __func__, ##args); \
    } while(0)
#define DBG_ERR(fmt, args...) \
    do { \
        debug_log_print(DEBUG_LEVEL_ERR, "[%s:%d](%s)"fmt"\n", \
                __FILE__, __LINE__, __func__, ##args); \
    } while(0)
#define DBG_ERRNO(errno, fmt, args...) \
    do { \
        debug_log_print(DEBUG_LEVEL_ERR, "[%s:%d](%s)"fmt"\n", \
                __FILE__, __LINE__, __func__, ##args); \
        debug_log_print(DEBUG_LEVEL_ERR, "\nReason--->%s\n\n", \
                strerror(errno)); \
    } while(0)
#define DUMP_MEM(buf, len) \
    do { \
        DBG_LOG("Dump Memery<%s> Addr=0x%p, len=%d", \
                #buf, buf, len); \
        debug_dump_hex((unsigned char *)buf, len); \
    } while(0)
#endif
