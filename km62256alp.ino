#define CS 50
#define OE 51
#define WE 52

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  
  for( int i = 30 ; i <= 37 ; i++ )
  {
    pinMode(i,OUTPUT);  
  }

  for( int i = 40 ; i <= 42 ; i++ )
  {
    pinMode(i,OUTPUT);  
  }

  for( int i = 50 ; i <= 52 ; i++ )
  {
    pinMode(i,OUTPUT);  
  }

  write_(7,255);
  read_(7);
  write_(6,128);
  read_(6);
  write_(5,192);
  read_(5);
  write_(4,8);
  read_(4);
  write_(3,255);
  read_(3);
  write_(2,64);
  read_(2);
  write_(1,255);
  read_(1);
  write_(0,1);
  read_(0);


  Serial.println("------------");
  read_(7);
  read_(6);
  read_(5);
  read_(4);
  read_(3);
  read_(2);
  read_(1);
  read_(0);
  Serial.println("------------");


  write_(7,0);
  read_(7);
  write_(6,0);
  read_(6);
  write_(5,0);
  read_(5);
  write_(4,0);
  read_(4);
  write_(3,0);
  read_(3);
  write_(2,0);
  read_(2);
  write_(1,0);
  read_(1);
  write_(0,0);
  read_(0);

  Serial.println("------------");
  read_(7);
  read_(6);
  read_(5);
  read_(4);
  read_(3);
  read_(2);
  read_(1);
  read_(0);
  Serial.println("------------");

  write_(7,255);
  read_(7);
  write_(6,255);
  read_(6);
  write_(5,255);
  read_(5);
  write_(4,255);
  read_(4);
  write_(3,255);
  read_(3);
  write_(2,255);
  read_(2);
  write_(1,255);
  read_(1);
  write_(0,255);
  read_(0);

  Serial.println("------------");
  read_(7);
  read_(6);
  read_(5);
  read_(4);
  read_(3);
  read_(2);
  read_(1);
  read_(0);
  Serial.println("------------");
}

void loop() {
  // put your main code here, to run repeatedly:

}

void idal_ ()
{
  for( int i = 30 ; i <= 37 ; i++ )
  {
    pinMode(i,OUTPUT);  
  }

  digitalWrite(CS , HIGH);
  digitalWrite(OE , HIGH);
  digitalWrite(WE , HIGH);
}

void read_ (int address)
{
//  for( int i = 40 ; i <= 42 ; i++ )
//  {
//    digitalWrite( i , 1 ); 
//  }
  
  IO_intput();

  for( int i = 42 ; i >= 40 ; i-- )
  {
    digitalWrite( i , (address >> (i - 40)) & 1 ); 
    Serial.print(address >> (i - 40) & 1); 
  }
  Serial.print(" : ");

  digitalWrite(OE , LOW);
  digitalWrite(CS , LOW);

  Serial.print("Read : ");
  for( int i = 37 ; i >= 30 ; i-- ){
    Serial.print(digitalRead(i));
    Serial.print(" ");   
  }
  Serial.println(); 

  digitalWrite(CS , HIGH);

  idal_();
}

void write_ (int address,int data_in)
{


  IO_output();
  
  for( int i = 42 ; i >= 40 ; i-- )
  {
    digitalWrite( i , (address >> (i - 40)) & 1 ); 
    Serial.print(address >> (i - 40) & 1); 
  }
  Serial.print(" : ");
  
  digitalWrite(WE , LOW);
  digitalWrite(CS , LOW);

  Serial.print("Write : ");
  for( int i = 37 ; i >= 30 ; i--)
  {
      digitalWrite(i,(data_in >> (i - 30)) & 1);
      Serial.print(data_in >> (i - 30) & 1);  
  }
  Serial.println();  
//  digitalWrite(30,0);
//  digitalWrite(31,0);
//  digitalWrite(32,0);
//  digitalWrite(33,0);
//  digitalWrite(34,1);
//  digitalWrite(35,0);
//  digitalWrite(36,1);
//  digitalWrite(37,0);

  digitalWrite(CS , HIGH);

}

void IO_output () 
{
    for( int i = 30 ; i <= 37 ; i++ )
  {
    pinMode(i,OUTPUT);  
  }
}

void IO_intput () 
{
    for( int i = 30 ; i <= 37 ; i++ )
  {
    pinMode(i,INPUT);  
  }
}
