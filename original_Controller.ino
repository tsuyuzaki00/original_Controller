#include <SPI.h> 

const int L3GD20_CS = SS;

const byte L3GD20_ADDR = 0x6a;
const byte L3GD20_WHOAMI = 0x0f;
const byte L3GD20_CTRL_REG1 = 0x20;
const byte L3GD20_OUT_X_L = 0x28;
const byte L3GD20_OUT_X_H = 0x29;
const byte L3GD20_OUT_Y_L = 0x2A;
const byte L3GD20_OUT_Y_H = 0x2B;
const byte L3GD20_OUT_Z_L = 0x2C;
const byte L3GD20_OUT_Z_H = 0x2D;

const byte L3GD20_RW = 0x80;
const byte L3GD20_MS = 0x40;

byte L3GD20_read(byte reg) {
  byte ret = 0;

  digitalWrite(L3GD20_CS, LOW);
  SPI.transfer(reg | L3GD20_RW);
  ret = SPI.transfer(0);
  digitalWrite(L3GD20_CS, HIGH);

  return ret;
}

void setup() {
  
  Serial.begin(9600);
  digitalWrite(SS, HIGH);
  pinMode(SS, OUTPUT);

  SPI.begin();
  SPI.setBitOrder(MSBFIRST);
  SPI.setClockDivider(SPI_CLOCK_DIV8);
  
  while (!Serial) {}

  Serial.println(L3GD20_read(L3GD20_WHOAMI), HEX);
  digitalWrite(L3GD20_CS, LOW);
  SPI.transfer(L3GD20_CTRL_REG1);
  SPI.transfer(B00001111);
  digitalWrite(L3GD20_CS, HIGH);
}

void loop()
{
  short jh, jl;
  float jx, jy, jz;
  long kx , ky , kz ;
  float sx, sy, ss;
  kx = ky = kz = 0 ;

  sx = analogRead(0) ; // 左右スティック
  sy = analogRead(1) ; // 上下スティック
  kx = analogRead(3) ; // Ｘ軸
  ky = analogRead(4) ; // Ｙ軸
  kz = analogRead(5) ; // Ｚ軸
  as = analogRead(6) ; // アナログセンサー

  jl = L3GD20_read(L3GD20_OUT_X_L);
  jh = L3GD20_read(L3GD20_OUT_X_H);
  jx = (jh << 8) | jl;
  jl = L3GD20_read(L3GD20_OUT_Y_L);
  jh = L3GD20_read(L3GD20_OUT_Y_H);
  jy = (jh << 8) | jl;
  jl = L3GD20_read(L3GD20_OUT_Z_L);
  jh = L3GD20_read(L3GD20_OUT_Z_H);
  jz = (jh << 8) | jl;
  
  Serial.print("kx:") ;
  Serial.print(kx) ;
  Serial.print("ky:") ;
  Serial.print(ky) ;
  Serial.print("kz:") ;
  Serial.println(kz) ;

  Serial.print("jx:");
  Serial.print(jx);
  Serial.print("jy:");
  Serial.print(jy);
  Serial.print("jz:");
  Serial.println(jz);

  delay(5);
}
