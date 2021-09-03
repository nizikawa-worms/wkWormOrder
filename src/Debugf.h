
#ifndef WKWORMORDER_DEBUGF_H
#define WKWORMORDER_DEBUGF_H
#define debugf(fmt, ...) printf("%s:%d: " fmt, __FUNCTION__ , __LINE__, __VA_ARGS__);
#endif //WKWORMORDER_DEBUGF_H
