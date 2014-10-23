#ifndef _DEBUG_H_
#define _DEBUG_H_
#include <stdio.h>
#include <string.h>

typedef enum {
    DEBUG_LEVEL_INFO = 0,
    DEBUG_LEVEL_LOW  = 1,
    DEBUG_LEVEL_MED  = 2,
    DEBUG_LEVEL_HIGH = 3,
    DEBUG_LEVEL_ERR  = 4,
    DEBUG_LEVEL_MAX  = 5,
}debug_level_t;

void log_print(debug_level_t level, const char *fmt, ...);

#define DBG_INFO(fmt, args...) \
    do { \
        log_print(DEBUG_LEVEL_INFO, "[%s:%d](%s)"fmt"\n", \
                __FILE__, __LINE__, __func__, ##args); \
    } while(0)
#define DBG_LOW(fmt, args...) \
    do { \
        log_print(DEBUG_LEVEL_LOW, "[%s:%d](%s)"fmt"\n", \
                __FILE__, __LINE__, __func__, ##args); \
    } while(0)
#define DBG_MED(fmt, args...) \
    do { \
        log_print(DEBUG_LEVEL_MED, "[%s:%d](%s)"fmt"\n", \
                __FILE__, __LINE__, __func__, ##args); \
    } while(0)
#define DBG_HIGH(fmt, args...) \
    do { \
        log_print(DEBUG_LEVEL_HIGH, "[%s:%d](%s)"fmt"\n", \
                __FILE__, __LINE__, __func__, ##args); \
    } while(0)
#define DBG_ERR(fmt, args...) \
    do { \
        log_print(DEBUG_LEVEL_ERR, "[%s:%d](%s)"fmt"\n", \
                __FILE__, __LINE__, __func__, ##args); \
    } while(0)
#define DBG_ERRNO(errno, fmt, args...) \
    do { \
        log_print(DEBUG_LEVEL_ERR, "[%s:%d](%s)"fmt"\n", \
                __FILE__, __LINE__, __func__, ##args); \
        log_print(DEBUG_LEVEL_ERR, "\nReason--->%s\n\n", \
                strerror(errno)); \
    } while(0)
#endif
