#include <LiquidCrystal_I2C.h>
#include <Servo.h>
#include <AceWire.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);

Servo myservo;

#define ir_enter  A0
#define ir_back   A1

#define ir_car1  A2
#define ir_car2  A3
#define ir_car3  A4
#define ir_car4  A5
#define ir_car5  2

int S1=0,S2=0,S3=0,S4=0,S5=0;
int flag1=0,flag2=0; 
int slot = 5;


void setup()
{
  lcd.init(); // initialize the lcd
  lcd.backlight();
  
  
  pinMode(ir_car1, INPUT);
  pinMode(ir_car2, INPUT);
  pinMode(ir_car3, INPUT);
  pinMode(ir_car4, INPUT);
  pinMode(ir_car5, INPUT);
  
  pinMode(ir_enter, INPUT);
  pinMode(ir_back, INPUT);
  
  myservo.attach(3);
  myservo.write(0);
  
  lcd.setCursor(3, 0);
  lcd.print("Smart Car");
  lcd.setCursor(1, 1);
  lcd.print("Parking System");
  delay(4000);
  
  lcd.clear();
  lcd.setCursor(1, 0);
  lcd.print("By Ect 3rd year");
  lcd.setCursor(4, 1);
  lcd.print("Students");
  delay(2000);

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("SASI SATISH GOPI");
  lcd.setCursor(0, 1);
  lcd.print("MOHINI MANJU");
  delay(2000);
  
 Read_Sensor();

  int total = S1+S2+S3+S4+S5;
  slot = slot-total;
 
}

void loop() 
{
 
  Read_Sensor();
  
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Full:");
  lcd.setCursor(0, 1);
  lcd.print("Free:");
  myservo.write(0);
  delay(1);
  
     if(S1==1)
      {
       lcd.setCursor (6,0);   
       lcd.print("1");
       lcd.setCursor (6,1);   
       lcd.print("0");
      }
      else
      {
       lcd.setCursor (6,0);   
       lcd.print("0");
       lcd.setCursor (6,1);   
       lcd.print("1");
      }
  
  
    if(S2==1)
      {
       lcd.setCursor (8,0);   
       lcd.print("2");
       lcd.setCursor (8,1);   
       lcd.print("0");
      }
      else
      {
       lcd.setCursor (8,0);   
       lcd.print("0");
       lcd.setCursor (8,1);   
       lcd.print("2");
      }

    if(S3==1)
      {
       lcd.setCursor (10,0);   
       lcd.print("3");
       lcd.setCursor (10,1);   
       lcd.print("0");
      }
      else
      {
       lcd.setCursor (10,0);   
       lcd.print("0");
       lcd.setCursor (10,1);   
       lcd.print("3");
      }
  
     if(S4==1)
      {
       lcd.setCursor (12,0);   
       lcd.print("4");
       lcd.setCursor (12,1);   
       lcd.print("0");
      }
      else
      {
       lcd.setCursor (12,0);   
       lcd.print("0");
       lcd.setCursor (12,1);   
       lcd.print("4");
      }
          
    if(S5==1)
      {
       lcd.setCursor (14,0);   
       lcd.print("5");
       lcd.setCursor (14,1);   
       lcd.print("0");
      }
      else
      {
       lcd.setCursor (14,0);   
       lcd.print("0");
       lcd.setCursor (14,1);   
       lcd.print("5");
      }


  
    int space = S1+S2+S3+S4+S5 ;
    delay(100);

   
   if(digitalRead (ir_enter) == 0 && space !=5 )
   {
    myservo.write(100);
    delay(1000);
    
   }

    if(digitalRead (ir_enter) == 0 && space ==5 )
     {
      lcd.clear();
      lcd.setCursor (0,0);
      lcd.print("  Sorry Parking  ");  
      lcd.setCursor(6, 1);
      lcd.print("Full");
      myservo.write(0);
      delay(1500);
     }
  if(digitalRead (ir_back) == 0)
  {
   myservo.write(100);
   delay(2000);
    
  }
  
}


void Read_Sensor()
{
S1=0, S2=0, S3=0, S4=0, S5=0;

if(digitalRead(ir_car1) == 0){S1=1;}
if(digitalRead(ir_car2) == 0){S2=1;}
if(digitalRead(ir_car3) == 0){S3=1;}
if(digitalRead(ir_car4) == 0){S4=1;}
if(digitalRead(ir_car5) == 0){S5=1;}
}