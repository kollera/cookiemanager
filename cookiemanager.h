
#ifndef cookiemanager_h
#define cookiemanager_h

#include <Arduino.h>
#include "cookie.h"
#include <stdint.h>


extern "C" {
    #include "Rand.h"
}


template < int MAX_SESSIONS = 3>
class Cookiemanager
{
  public:


Cookiemanager() {
    for (int i = 0; i < MAX_SESSION_COUNT; i++){
            cookies[i].session = NULL;
            cookies[i].value[0] = '\0';
        }

    }

void generateCookie(char* buffer) {
    buffer[COOKIE_LENGTH-1] = '\0';
    getRandomString((COOKIE_LENGTH-2),buffer);
}

Cookie* generateNewCookie(void* session) {

    if(session==NULL) {
        return NULL;
    }
    for (int i = 0; i < MAX_SESSION_COUNT; i++){
       if(cookies[i].session == NULL) {
            cookies[i].session = session;
            generateCookie(cookies[i].value); 
            return &cookies[i];
        }
    }
    return NULL;
}

Cookie* renewCookie(void* session) {

    if(session==NULL) {
        return NULL;
    }
    Cookie* cookie = getSessionCookie(session);

    if(cookie!=NULL) {
        generateCookie(cookie->value); 
        return cookie;
    }

    return NULL;
}


Cookie* getSessionCookie(void* session) {

    if(session==NULL) {
        return NULL;
    }
    for (int i = 0; i < MAX_SESSION_COUNT; i++){
       if(cookies[i].session == session) {
            return &cookies[i];
        }
    }
    return NULL;
}


Cookie* getCookie(char* value) {

    if(value==NULL) {
        return NULL;
    }

    for (int i = 0; i < MAX_SESSION_COUNT; i++){
       if(strcmp(cookies[i].value,value)==0) {
            return &cookies[i];
        }
    }
    return NULL;
}


Cookie* getCookieAt(int index) {
    if(index>=0 && index < MAX_SESSION_COUNT) {
        return &cookies[index];
    }
    return NULL;
}

int getMaxCookies() {
    return MAX_SESSION_COUNT;
}
   
  private:
    const int MAX_SESSION_COUNT = MAX_SESSIONS;
    Cookie cookies[MAX_SESSIONS];

};

#endif
