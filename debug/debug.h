#ifndef _DEBUG_H_
#define _DEBUG_H_
#include <stdio.h>

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
#endif
