#include <stdio.h>
#include <stdarg.h>
#include "debug.h"

void log_print(debug_level_t level, const char *fmt, ...)
{
    va_list args;
    va_start(args, fmt);
    vprintf(fmt, args);
    va_end(args);
}

#ifdef DEBUG_TEST
int main(void)
{
    DBG_INFO("test1");
    DBG_INFO("test2,%d", 1);
    DBG_INFO("test3,%s", "hello");
    return 0;
}
#endif
