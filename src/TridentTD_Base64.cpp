#include "TridentTD_Base64.h"
#include "utils/base64.h"

TridentTD_Base64::TridentTD_Base64() {  
}

String TridentTD_Base64::encode(uint8_t* input, size_t input_len) {
  char encode_data[b64_enc_len(input_len)];
  int  encode_len  = b64_encode( encode_data, (char*) input, input_len);
  return String(encode_data);
}

size_t TridentTD_Base64::getDecodeLength(String base64_str ) {
  return b64_dec_len( (char*) base64_str.c_str(), base64_str.length());
}

size_t TridentTD_Base64::decode( String base64_str, uint8_t* output ) {
  char decode_data[ this->getDecodeLength( base64_str) ];
  int decode_len = b64_decode( (char*) output, (char*) base64_str.c_str(), base64_str.length());
  return decode_len;
}

TridentTD_Base64 TD_BASE64;
