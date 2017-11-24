
#include "Rand.h"
#if defined(ESP8266)
	#include "esp8266_peri.h"
#endif


uint8_t getRandomByte() {

#if defined(ESP8266)
    uint8_t byte = (uint8_t)RANDOM_REG32;
#else
    uint8_t byte = random(65,122);
#endif
    return byte;
}

void getRandomString(int len, char* buffer) {

    uint8_t b = 0;
    for(int i = 0; i < len; i++) {
        b = getRandomByte();
#if defined(ESP8266) 
        b = b % 57;
        b = b + 65;
#endif
        buffer[i] = b;
    }
}
