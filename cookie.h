

#ifndef cookie_h
#define cookie_h

#ifndef COOKIE_LENGTH
#define COOKIE_LENGTH 33
#endif

struct Cookie {
char value[COOKIE_LENGTH];
void* session;
};

#endif
