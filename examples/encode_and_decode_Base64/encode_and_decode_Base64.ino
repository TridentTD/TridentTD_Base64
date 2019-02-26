#include <TridentTD_Base64.h>

uint8_t templateBuffer[256];

void setup() {
  Serial.begin(115200); Serial.println();
  memset(templateBuffer, 0xff, 256);  //zero out template buffer

  //จำลองสร้าง ข้อมูลให้ templateBuffer 256 byte
  for(int i=0; i < 256; i++) {  templateBuffer[i] = (uint8_t) random(0x30,0x3A); } templateBuffer[256] = 0;

  Serial.println("-----------------------------------");
  Serial.println("Input Data : ");
  Serial.println((char*) templateBuffer );
  Serial.println("-----------------------------------");

  // เข้ารหัส BASE64
  String encoded_str = TD_BASE64.encode( templateBuffer, 256);

  // ข้อมูลที่แปลงเป็น base64 ที่เตรียมส่งขึั้น Firebase
  Serial.println("Encoded Base64 String : ");
  Serial.println( encoded_str);
  Serial.print("Encoded Base64 String length : ");
  Serial.println( encoded_str.length());
  
  Serial.println("-----------------------------------");

  // ถอดรหัส BASE64

  size_t decode_len = TD_BASE64.getDecodeLength(encoded_str);
  uint8_t decoded_data[decode_len];
  
  TD_BASE64.decode(encoded_str, decoded_data);

  // ค่าที่ถูกถอดรหัส ควรจะต้องตรงกับ ค่าตั้งต้น
  Serial.println("Decoded Base64 String : "); 
  Serial.println( (char*) decoded_data );
  
  Serial.println("-----------------------------------");
}

void loop() {

}

