#include <Wire.h>               // library for connection

char inData[82];       //  array of input values (CHARACTERS)
int PCdata[20];        // array of numeric values read from the computer
byte index = 0;
String string_convert;
bool isDataExist = false;
int cpu;
int mem;
int gpu;

void setup() {
   Serial.begin(9600);
}

void loop() {
  parsing();
  led(); //for those who want to connect backlighting

  cpu = PCdata[4];
  cpu = map(cpu, 0, 100, 0, 255);
  cpu = constrain(cpu, 0, 255);
  analogWrite(9, cpu);

  gpu= PCdata[5];
  gpu = map(gpu, 0, 100, 0, 255);
  gpu = constrain(gpu, 0, 255);
  analogWrite(3, gpu);

  mem= PCdata[6];
  mem = map(mem, 0, 100, 0, 255);
  mem = constrain(mem, 0, 255);
  analogWrite(5, mem);
}

void parsing() {
  while (Serial.available() > 0) {
    char aChar = Serial.read();
    if (aChar != 'E') {
      inData[index] = aChar;
      index++;
      inData[index] = '\0';
    } else {
      char *p = inData;
      char *str;
      index = 0;
      String value = "";
      while ((str = strtok_r(p, ";", &p)) != NULL) {
        string_convert = str;
        PCdata[index] = string_convert.toInt();
        index++;
      }
      index = 0;
      isDataExist = true;
    }
   }
  }
  
void led()
   {
   if (PCdata[4] < 20 ) 
         {
    digitalWrite (6, HIGH); //  for example, the green leg of the RGB is connected to this pin
         }
  else{
   digitalWrite (6, LOW);
      }
   if (PCdata[4] > 20 && PCdata[4] < 60 ); //  remember, these are percentage values, not PWM values
         {
    digitalWrite(5, HIGH);//the blue leg is connected to this pin
         }
    //and so on for all the LEDs
  }
  
