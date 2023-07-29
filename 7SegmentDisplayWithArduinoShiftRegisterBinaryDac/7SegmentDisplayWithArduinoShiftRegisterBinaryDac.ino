/*
 * 28 7 2023
 * Arduino Uno, Common Cathod + Common 7Seg - Display, 74HC595
 *Shift Register Multy Display
 *74HC595 Shift registers to control mulitple 7 segment displays
 */
int DS_Pin = 12;
int STCP_Pin = 11;
int SHCP_Pin = 13;


//int digits [10][8]{                     //Reverse Binary        Decimal
//      {0,1,1,1,1,1,1,0} , //digit 0     //00000001              1
//      {0,0,1,1,0,0,0,0} , //digit 1     //01001111              79
//      {0,1,1,0,1,1,0,1} , //digit 2     //00010010              18
//      {0,1,1,1,1,0,0,1} , //digit 3     //00000110              6
//      {0,0,1,1,0,0,1,1} , //digit 4     //01001100              76
//      {0,1,0,1,1,0,1,1} , //digit 5     //00100100              36
//      {0,1,0,1,1,1,1,1} , //digit 6     //00100000              32
//      {0,1,1,1,0,0,0,0} , //digit 7     //00001111              15
//      {0,1,1,1,1,1,1,1} , //digit 8     //00000000              0
//      {0,1,1,1,1,0,1,1}   //digit 9     //00000100              4
//  };

int dec_digits [10] {1, 79, 18, 6, 76, 36, 32, 15, 0, 4};

void setup()
  {
  pinMode(DS_Pin,   OUTPUT);
  pinMode(STCP_Pin, OUTPUT);
  pinMode(SHCP_Pin, OUTPUT);
  }

void loop()
  {
  
  for(int i=0; i<10; i++)
    {
      digitalWrite(STCP_Pin,LOW);
      shiftOut(DS_Pin, SHCP_Pin, LSBFIRST, dec_digits[i]);
      digitalWrite(STCP_Pin,HIGH);
      delay(200);
    }
  }
