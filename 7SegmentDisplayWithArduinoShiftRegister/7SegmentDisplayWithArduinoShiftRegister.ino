/*
 * 28 7 2023
 * Arduino Uno, Common Cathod + Common 7Seg - Display, 74HC595
 *Shift Register Multy Display
 *74HC595 Shift registers to control mulitple 7 segment displays
 */
int DS_Pin = 12;
int STCP_Pin = 11;
int SHCP_Pin = 13;


int digits [10][8]{
      {0,1,1,1,1,1,1,0} , //digit 0
      {0,0,1,1,0,0,0,0} , //digit 1
      {0,1,1,0,1,1,0,1} , //digit 2
      {0,1,1,1,1,0,0,1} , //digit 3
      {0,0,1,1,0,0,1,1} , //digit 4
      {0,1,0,1,1,0,1,1} , //digit 5
      {0,1,0,1,1,1,1,1} , //digit 6
      {0,1,1,1,0,0,0,0} , //digit 7
      {0,1,1,1,1,1,1,1} , //digit 8
      {0,1,1,1,1,0,1,1}   //digit 9
  };

void setup()
  {
  pinMode(DS_Pin,   OUTPUT);
  pinMode(STCP_Pin, OUTPUT);
  pinMode(SHCP_Pin, OUTPUT);
  }

void display_digit(int digit)
  {
  digitalWrite(STCP_Pin, LOW);
  for(int i=7; i>=0; i--)
    {
      digitalWrite(SHCP_Pin,LOW);
      if(digits[digit][i]==1) digitalWrite(DS_Pin,LOW); 
      if(digits[digit][i]==0) digitalWrite(DS_Pin,HIGH); 
      digitalWrite(SHCP_Pin,HIGH);
    }
  digitalWrite(STCP_Pin, HIGH);
  }
  
void loop()
  {
    //display_digit(1);
  
  for(int i=0; i<10; i++)
    {
      display_digit(i);
      delay(300);
    }
  }
