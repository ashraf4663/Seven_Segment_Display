/*
 * 30 7 2023
 * Arduino Uno, Common Cathod - Common 7Seg + Display, 74HC595
 *Shift Register Multy Display
 *74HC595 Shift registers to control mulitple 7 segment displays
 */
int DS_Pin = 12;
int STCP_Pin = 11;
int SHCP_Pin = 13;


//int digits [10][8]{                   Decimal     //Binary        Decimal
//      {0,1,1,1,1,1,1,0} , //digit 0   126         //b01111110     1          
//      {0,0,1,1,0,0,0,0} , //digit 1   48          //b00110000     79               
//      {0,1,1,0,1,1,0,1} , //digit 2   109         //b01101101     18                
//      {0,1,1,1,1,0,0,1} , //digit 3   121         //b01111001     6               
//      {0,0,1,1,0,0,1,1} , //digit 4   51          //b00110011     76           
//      {0,1,0,1,1,0,1,1} , //digit 5   91          //b01011011     36           
//      {0,1,0,1,1,1,1,1} , //digit 6   95          //b01011111     36           
//      {0,1,1,1,0,0,0,0} , //digit 7   112         //b01110000     15           
//      {0,1,1,1,1,1,1,1} , //digit 8   127         //b01111111     0          
//      {0,1,1,1,1,0,1,1}   //digit 9   123         //b01111011     4           
//  };

int dec_digits [10] {126, 48, 109, 121, 51, 91, 95, 112, 127, 123};


void setup()
  {
  pinMode(DS_Pin,   OUTPUT);
  pinMode(STCP_Pin, OUTPUT);
  pinMode(SHCP_Pin, OUTPUT);
  }

void loop()
  {
    for(int j=0; j<10; j++)
    {
     for(int i=0; i<10; i++)
      {
      digitalWrite(STCP_Pin,LOW);
      shiftOut(DS_Pin, SHCP_Pin, LSBFIRST, dec_digits[i]);
      shiftOut(DS_Pin, SHCP_Pin, LSBFIRST, dec_digits[j]);
      digitalWrite(STCP_Pin,HIGH);
      delay(100);
      } 
    }
  }
