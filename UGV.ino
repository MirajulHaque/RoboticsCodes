float d, t;

void setup() {
Serial.begin(9600);
pinMode(2, OUTPUT);
pinMode(3, OUTPUT);
pinMode(4, OUTPUT);
pinMode(5, OUTPUT);
pinMode(A1, OUTPUT);
pinMode(A2, INPUT);

}
void loop() {
distance();
//forward();

}



// WIN22.SEEE-106.1.1 
// Code By Md Mirajul Haque Miraj
// Group 3

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
analogWrite(3, 150);
digitalWrite(4, LOW);
//digitalWrite(5, HIGH);
analogWrite(5, 150);

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
