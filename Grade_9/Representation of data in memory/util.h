#ifndef UTIL_H
#define UTIL_H

#define MSG_OVERFLOW "Overflow operation"
#define MSG_INPUT_ERROR "Invalid input"

#define ERROR_CHECK(FLAG, MSG) \
    if (FLAG == 1)             \
    {                          \
        printf(MSG);         \
        return 0;              \
    }

#endif