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

for (posl = 0; posl <= 90; posl += 1) { 
    // in steps of 1 degree
    sleft.write(posl);              
    delay(80);

for (posl = 90; posl >= 0; posl -= 1) { 
    sleft.write(posl);              
    delay(80);
  
//  servo_move();
// voice_control();
  
//bluetooth_control();
//distance();
//forward();

}

// WIN22.SEEE-106.1.1 
// Code By Md Mirajul Haque Miraj
// Group 3

void servo_move(){
  while(Serial1.available()){
    c = Serial1.read();
    voice = voice + c;
    Serial.println(c);
  }

  if(voice.length()>0){
    if(voice == "right up"){
      for (posr = 0; posr <= 90; posr += 1) { 
    // in steps of 1 degree
    sright.write(posr);              
    delay(80);                      
  }
    }
    else if(voice == "right down"){
      for (posr = 90; posr >= 0; posr -= 1) { 
    sright.write(posr);              
    delay(80);                       
    }
    else if(voice == "left up"){
      for (posl = 0; posl <= 90; posl += 1) { 
    // in steps of 1 degree
    sleft.write(posl);              
    delay(80);                      
  }
    }
    else if(voice == "left down"){
      for (posl = 90; posl >= 0; posl -= 1) { 
    sleft.write(posl);              
    delay(80);                       
    }
    else if(voice == "right"){
      for (posh = 0; posh <= 90; posh += 1) { 
    // in steps of 1 degree
    shead.write(posh);              
    delay(80);                      
  }
    }
    else if(voice == "left"){
      for (posh = 90; posh >= 0; posh -= 1) { 
    shead.write(pos);              
    delay(80);                       
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


void voice_control(){
  while(Serial1.available()){
    c = Serial1.read();
    voice = voice + c;
    Serial.println(c);
  }

  if(voice.length()>0){
    if(voice == "go"){
      forward();
    }
    else if(voice == "left"){
      left();
    }
    else if(voice == "right"){
      right();
    }
    else if(voice == "back"){
      backward();
    }
    else{
      stop_car();
    }
  voice = "";
  }
 delay(100);
}

void bluetooth_control(){
  if(Serial1.available()){
    b = Serial1.read();
    Serial.println(b);

    if(b=='F'){
      forward();
    }
    else if(b=='B'){
      backward();
    }
    else if(b=='L'){
      left();
    }
    else if(b=='R'){
      right();
    }
    else if(b=='G'){
      forward_left();
    }
    else if(b=='I'){
      forward_right();
    }
    else if(b=='H'){
      backward_left();
    }
    else if(b=='J'){
      backward_right();
    }
    else{
      stop_car();
    }
  }
}



void distance(){
digitalWrite(A1, HIGH);
delay(10);
digitalWrite(A1, LOW);
t = pulseIn(A2, HIGH);
d = 0.0343 * (t/2);
Serial.println(d);

if(d>40){
  forward();
}
if(d<40){
  right();
}
if(d<30){
  left();
}
if(d<20){
  backward();
}
}

void stop_car(){
digitalWrite(2, LOW);
digitalWrite(3, LOW);
digitalWrite(4, LOW);
digitalWrite(5, LOW);
  
}

void forward(){
//digitalWrite(2, HIGH);
analogWrite(2, 209);
digitalWrite(3, LOW);
digitalWrite(4, HIGH);
digitalWrite(5, LOW);
  
}

void forward_left(){
//digitalWrite(2, HIGH);
analogWrite(2, 209);
digitalWrite(3, LOW);
//digitalWrite(4, HIGH);
analogWrite(4, 220);
digitalWrite(5, LOW);
  
}

void forward_right(){
//digitalWrite(2, HIGH);
analogWrite(2, 195);
digitalWrite(3, LOW);
digitalWrite(4, HIGH);
//analogWrite(4, 190);
digitalWrite(5, LOW);
  
}


void right(){
digitalWrite(2, LOW);
digitalWrite(3, LOW);
digitalWrite(4, HIGH);
//analogWrite(4, 110);
digitalWrite(5, LOW);
  
}

void left(){
digitalWrite(2, HIGH);
//analogWrite(2, 110);
digitalWrite(3, LOW);
digitalWrite(4, LOW);
digitalWrite(5, LOW);

}

void backward(){
digitalWrite(2, LOW);
//digitalWrite(3, HIGH);
analogWrite(3, 162);
digitalWrite(4, LOW);
//digitalWrite(5, HIGH);
analogWrite(5, 200);

}

void backward_left(){
digitalWrite(2, LOW);
//digitalWrite(3, HIGH);
analogWrite(3, 162);
digitalWrite(4, LOW);
//digitalWrite(5, HIGH);
analogWrite(5, 180);
}

void backward_right(){
digitalWrite(2, LOW);
//digitalWrite(3, HIGH);
analogWrite(3, 140);
digitalWrite(4, LOW);
//digitalWrite(5, HIGH);
analogWrite(5, 200);

}
//forward();
//delay(3000);
//stop_car();
//delay(2000);
//right();
//delay(500);
//stop_car();
//delay(2000);
//forward();
//delay(2000);
//stop_car();
//delay(2000);
//left();
//delay(500);
//stop_car();
//delay(2000);
//forward();
//delay(2000);
//stop_car();
//delay(2000);
//backward();
//delay(2000);
//stop_car();
//delay(5000);
