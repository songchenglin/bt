#include <stdio.h>
#include <stdarg.h>
#include "debug.h"

unsigned int g_debug = 1; //Set debug=True when developping

void debug_log_print(debug_level_t level, const char *fmt, ...)
{
    va_list args;
    unsigned char buf[128];
    if(level >= DEBUG_LEVEL_MAX)
        return;
    va_start(args, fmt);
    vsnprintf(buf, 128, fmt, args);
    printf("%s", buf);
    va_end(args);
}
void debug_dump_hex(const unsigned char *buf, int len)
{
    unsigned int line_count = 0;
    unsigned int line, last_col;
    unsigned int i;
    line_count = len>>4; //16byte per line
    for(line = 0;line < line_count;line++) {
        printf("%04xh: ", line);
        for(i = 0;i < 16;i++) {
            printf("%02X ", *buf);
            buf++;
        }
        printf("\n");
    }
    last_col = len&0x0f;
    if(last_col) {
        printf("%04xh: ", line);
        for(i = 0;i < last_col; i++) {
            printf("%02X ", *buf);
            buf++;
        }
        printf("\n");
    }
}

#ifdef DEBUG_TEST
int main(void)
{
    char buffer[] = "AABCDEFGHIJKLMNOPQRSTUVWXYZbcdefghijklmnopqrstuvwxyz0123456789";
    DBG_INFO("test1");
    DBG_INFO("test2,%d", 1);
    DBG_INFO("test3,%s", "hello");
    DUMP_MEM(buffer, sizeof(buffer));
    DUMP_MEM("abcdefg", sizeof("abcdefg"));
    return 0;
}
#endif
