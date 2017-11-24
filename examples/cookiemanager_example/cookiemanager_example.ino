
#include "cookiemanager.h"

Cookiemanager<3> manager;

struct demoSession {
  int sessionValue;
};

Cookie* sessioncookie[3];
char sessionvalues[3][COOKIE_LENGTH];

void setup() {
  
  Serial.begin(115200);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for Leonardo only
  }
 
}

boolean run = false;

void loop() {


  if(!run) {
    run = true;
    
    int maxSessions = manager.getMaxCookies();
    Serial.println("\n--------- generate new cookie -----------");
    for(int i = 0; i < maxSessions; i++) {
      Serial.print("nr. ");Serial.println(i);
      //type *pointer = malloc(num_elems * sizeof(*pointer));
      demoSession* session = (demoSession*)malloc(sizeof(demoSession));
      session->sessionValue = i;
      sessioncookie[i] = manager.generateNewCookie(session);
      delay(10);
    }
    Serial.println("\n--------- generate new cookie end -----------");
    Serial.println("\n--------- list cookies -----------");
    for(int i = 0; i < maxSessions; i++) {
      //type *pointer = malloc(num_elems * sizeof(*pointer));
      Cookie* cookie = manager.getCookieAt(i);
      demoSession* session = (struct demoSession*)cookie->session;
      strcpy(sessionvalues[i],cookie->value);
      Serial.print("cookie nr. ");Serial.println(i);
      Serial.print("session element: ");Serial.println(session->sessionValue);
      Serial.print("cookie value: "); Serial.println(cookie->value);
      
    }
    Serial.println("\n--------- list cookies end -----------");
    
    Serial.println("\n--------- get cookie by value -----------");
    for(int i = 0; i < maxSessions; i++) {
      Serial.print("cookie nr. ");Serial.println(i);
      Cookie* byCookieValue = manager.getCookie(sessionvalues[i]);
      if(sessioncookie[i]==byCookieValue) {
        Serial.println("cookie ptr OK");
      } else {
        Serial.println("cookie ptr ERROR");
      }
      
      if(sessioncookie[i]->value==byCookieValue->value) {
        Serial.println("cookie value OK");
      } else {
        Serial.println("cookie value ERROR");
      }
      
      if(sessioncookie[i]->session==byCookieValue->session) {
        Serial.println("cookie session ptr OK");
      } else {
        Serial.println("cookie session prt ERROR");
      }
      Serial.println("---");
    }
    Serial.println("\n--------- get cookie by value end -----------");
    
    
    Serial.println("\n--------- new vs old -----------");
    for(int i = 0; i < maxSessions; i++) {
      Serial.print("cookie nr. ");Serial.println(i);
      Cookie* byCookieValue = manager.getCookie(sessionvalues[i]);
      if(sessioncookie[i]==byCookieValue) {
        Serial.println("cookie ptr OK");
      } else {
        Serial.println("cookie ptr ERROR");
      }
      
      if(sessioncookie[i]->value==byCookieValue->value) {
        Serial.println("cookie value OK");
      } else {
        Serial.println("cookie value ERROR");
      }
      
      if(sessioncookie[i]->session==byCookieValue->session) {
        Serial.println("cookie session ptr OK");
      } else {
        Serial.println("cookie session prt ERROR");
      }
      Serial.println("---");
    }
    Serial.println("\n--------- new vs old end -----------");
    
    
    
    // renew
    Serial.println("\n----- renew cookie ------");
    for(int i = 0; i < maxSessions; i++) {
      Cookie* cookie = manager.getCookieAt(i);
      cookie = manager.renewCookie(cookie->session);
      demoSession* session = (struct demoSession*)cookie->session;
      Serial.print("cookie nr. ");Serial.println(i);
      Serial.print("session element: ");Serial.println(session->sessionValue);
      Serial.print("cookie value: "); Serial.println(cookie->value);
      
      if(strcmp(sessionvalues[i],cookie->value)!=0) {
        Serial.println("OK");
        Serial.print("oldValue: ");Serial.println(sessionvalues[i]);
      } else {
        Serial.println("ERROR");
      }
      Cookie* byCookieValue = manager.getCookie(cookie->value);
      if(cookie==byCookieValue) {
        Serial.println("getCookie(char*) OK");
      } else {
        Serial.println("getCookie(char*)  ERROR");
      }
      Serial.println("---");
    }
    Serial.println("\n----- renew cookie end ------");
    
    // test non-existing
    
    if(manager.getCookie(sessionvalues[0])==NULL) {
      Serial.println("get non-existing cookie: OK");
    } else {
      Serial.println("get non-existing cookie: ERROR");
    }
    /*
    Serial.print("sizeof(byte)=");
    Serial.println(sizeof(byte));
    Serial.println();
    
    Serial.print("sizeof(char)=");
    Serial.println(sizeof(char));
    Serial.println();
    
    Serial.print("sizeof(short)=");
    Serial.println(sizeof(short));
    Serial.println();
    
    Serial.print("sizeof(int)=");
    Serial.println(sizeof(int));
    Serial.println();
    
    Serial.print("sizeof(long)=");
    Serial.println(sizeof(long));
    Serial.println();
    
    Serial.print("sizeof(long long)=");
    Serial.println(sizeof(long long));
    Serial.println();
    
    Serial.print("sizeof(bool)=");
    Serial.println(sizeof(bool));
    Serial.println();
    
    Serial.print("sizeof(boolean)=");
    Serial.println(sizeof(boolean));
    Serial.println();
    
    Serial.print("sizeof(float)=");
    Serial.println(sizeof(float));
    Serial.println();
    
    Serial.print("sizeof(double)=");
    Serial.println(sizeof(double));
    Serial.println();
    
    Serial.print("sizeof(int8_t)=");
    Serial.println(sizeof(int8_t));
    Serial.println();
    
    Serial.print("sizeof(int16_t)=");
    Serial.println(sizeof(int16_t));
    Serial.println();
    
    Serial.print("sizeof(int32_t)=");
    Serial.println(sizeof(int32_t));
    Serial.println();
    
    Serial.print("sizeof(int64_t)=");
    Serial.println(sizeof(int64_t));
    Serial.println();
    
    Serial.print("sizeof(uint8_t)=");
    Serial.println(sizeof(uint8_t));
    Serial.println();
    
    Serial.print("sizeof(uint16_t)=");
    Serial.println(sizeof(uint16_t));
    Serial.println();
    
    Serial.print("sizeof(uint32_t)=");
    Serial.println(sizeof(uint32_t));
    Serial.println();
    
    Serial.print("sizeof(uint64_t)=");
    Serial.println(sizeof(uint64_t));
    Serial.println();
    
    Serial.print("sizeof(char*)=");
    Serial.println(sizeof(char*));
    Serial.println();
    
    Serial.print("sizeof(int*)=");
    Serial.println(sizeof(int*));
    Serial.println();
    
    Serial.print("sizeof(long*)=");
    Serial.println(sizeof(long*));
    Serial.println();
    
    Serial.print("sizeof(float*)=");
    Serial.println(sizeof(float*));
    Serial.println();
    
    Serial.print("sizeof(double*)=");
    Serial.println(sizeof(double*));
    Serial.println();
    
    Serial.print("sizeof(void*)=");
    Serial.println(sizeof(void*));
    Serial.println();
    */
    
  }
  
}
