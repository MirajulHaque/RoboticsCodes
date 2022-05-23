#include <Servo.h>

Servo sright, sleft, shead;
int posr = 0;
int posl = 0;
int posh = 0;
float d, t;
char b, c;
String voice = "";

void setup() {
Serial.begin(9600);
Serial1.begin(9600);
pinMode(2, OUTPUT);
pinMode(3, OUTPUT);
pinMode(4, OUTPUT);
pinMode(5, OUTPUT);
sright.attach(7);
sleft.attach(8);
shead.attach(9);
pinMode(A1, OUTPUT);
pinMode(A2, INPUT);

}
void loop() {
 
  servo_move();

}


// WIN22.SEEE-106.1.1 
// Code By Md Mirajul Haque Miraj
// Group 3
//


void servo_move(){
  while(Serial1.available()){
    c = Serial1.read();
    voice = voice + c;
    Serial.println(c);
  }

  if(voice.length()>0){
    if(voice == "right up"){
      for (posr = 0; posr <= 90; posr++) { 
    // in steps of 1 degree
    sright.write(posr);              
    delay(80);                      
  }
    }
    else if(voice == "right down"){
      for (posr = 90; posr >= 0; posr--) { 
    sright.write(posr);              
    delay(80);                       
    }
    }
    else if(voice == "left up"){
      for(posl = 90; posl >= 0; posl--){ 
    // in steps of 1 degree
    sleft.write(posl);              
    delay(80);                      
  }
    }
    else if(voice == "left down"){
      for(posl = 0; posl <= 90; posl++){ 
    sleft.write(posl);              
    delay(80);                       
    }
    }
    else if(voice == "front"){
      if(posh==0){
        for(posh=0; posh<=90; posh++){
          shead.write(posh);
          delay(80);
        }
      }
      else if(posh==180){
        for(posh=180; posh>=90; posh--){
          shead.write(posh);
          delay(80);
        }
      }
      else{
        
      }
    }
    else if(voice == "right"){
      if(posh==90){
        for(posh=90; posh <= 180; posh++){
        shead.write(posh);  
        delay(80);
        }
        
      }
      else if(posh == 0){
        for(posh=0; posh <= 180; posh++){
        shead.write(posh);  
        delay(80);
        }
        
      }
      else{
        
      }

    }
    else if(voice == "left"){
      if(posh == 90){
        for(posh=90; posh>=0; posh--){
          shead.write(posh);
          delay(80);         
        }
    }
    else if(posh == 180){
      for(posh=180;posh>=0;posh--){
        shead.write(posh);
        delay(80);
      }
    }
    else{
      
    }
//    else if(voice == "right"){
//      right();
//    }
//    else if(voice == "back"){
//      backward();
    }
    else{
//      stop_car();
    }
  voice = "";
  }
 delay(100);
}
 
