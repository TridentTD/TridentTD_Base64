#ifndef __TRIDENTTD_BASE64_H__
#define __TRIDENTTD_BASE64_H__

#include <Arduino.h>

class TridentTD_Base64 {
  public:
    TridentTD_Base64();
    String encode(uint8_t* input, size_t input_len);
    size_t getDecodeLength(String base64_str );
    size_t decode( String base64_str, uint8_t* output );
  private:
    
};

extern TridentTD_Base64 TD_BASE64;

#endif
