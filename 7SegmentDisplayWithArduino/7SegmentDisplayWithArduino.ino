/*
 * 28 7 2023
 * Arduino Uno, Common Cathod + Common 7Seg - Display
 *Basic 7Segment
 *Bionary code
 *
 */
int digits [10][7]{
      {1,1,1,1,1,1,0} , //digit 0
      {0,1,1,0,0,0,0} , //digit 1
      {1,1,0,1,1,0,1} , //digit 2
      {1,1,1,1,0,0,1} , //digit 3
      {0,1,1,0,0,1,1} , //digit 4
      {1,0,1,1,0,1,1} , //digit 5
      {1,0,1,1,1,1,1} , //digit 6
      {1,1,1,0,0,0,0} , //digit 7
      {1,1,1,1,1,1,1} , //digit 8
      {1,1,1,1,0,1,1}   //digit 9
  };

void setup()
{
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(6, OUTPUT);
}

void display_digit(int d)
  {
  if(digits[d][0]==1) digitalWrite(13,LOW); else digitalWrite(13,HIGH); //7 SEG A
  if(digits[d][1]==1) digitalWrite(12,LOW); else digitalWrite(12,HIGH); //7 SEG B
  if(digits[d][2]==1) digitalWrite(11,LOW); else digitalWrite(11,HIGH); //7 SEG C
  if(digits[d][3]==1) digitalWrite(10,LOW); else digitalWrite(10,HIGH); //7 SEG D
  if(digits[d][4]==1) digitalWrite( 9,LOW); else digitalWrite( 9,HIGH); //7 SEG E
  if(digits[d][5]==1) digitalWrite( 8,LOW); else digitalWrite( 8,HIGH); //7 SEG F
  if(digits[d][6]==1) digitalWrite( 7,LOW); else digitalWrite( 7,HIGH); //7 SEG G
  }
  
void loop()
  {
  for(int i=0; i<10; i++)
    {
      display_digit(i);
      delay(500);
    }
  }
