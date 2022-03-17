#include "includes.hpp"

#ifndef NDEBUG
#define ISDEBUG true
#else
#define ISDEBUG false
#endif

#define RIP(format, ... ) { fprintf(stderr, format "\n", ##__VA_ARGS__); exit(EXIT_FAILURE); }

#define LISTENER(name) void listener_##name(wl_listener*, void*); inline wl_listener listen_##name = { .notify = listener_##name };
#define DYNLISTENER(name) wl_listener listen_##name = { .notify = Events::listener_##name };

#define VECINRECT(vec, x1, y1, x2, y2) (vec.x >= (x1) && vec.x <= (x2) && vec.y >= (y1) && vec.y <= (y2))