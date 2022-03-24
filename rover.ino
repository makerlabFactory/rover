#include <IRremote.h>
const int in1 = 2 ;
const int in2 = 3 ;
int M1[] = {in1,in2};
const int in3 = 4 ;
const int in4 = 5 ;
int M2[] = {in3,in4};
const int in5 = 8 ;
const int in6 = 9 ;
int M3[] = {in5,in6};
const int in7 = 6 ;
const int in8 = 7 ;
int M4[] = {in7,in8};
double pauseplay =0xFF02FD;
double volplus =0xFF629D;
double volminus=0xFFA857;
double next=0xFFC23D;
double previous=0xFF22DD;



char command;
int receiver_pin = 10;   //Connect the output pin of IR receiver at pin 4
int statusled = 13;
IRrecv irrecv(receiver_pin);
decode_results results;
void setup() {
  Serial.begin(9600);
  irrecv.enableIRIn();
  pinMode(statusled, OUTPUT);
  digitalWrite(statusled, LOW);
  pinMode(in1,OUTPUT) ;   //Logic pins are also set as output
pinMode(in2,OUTPUT) ;

}

void loop() {
  
  if (irrecv.decode(&results)) {
    digitalWrite(statusled, LOW);
    Serial.println(results.value,HEX);
    irrecv.resume();
    delay(400);
    if(results.value==volplus){
      Serial.println ("power button is pressed");
      forward(M1);
      forward(M2);
      forward(M3);
      forward(M4);
      
     
    

    }
    if(results.value==pauseplay){
      Serial.println ("stop mouvement");   
      brake(M1);
      brake(M2);
      brake(M3);
      brake(M4);
    }
     if(results.value==volminus){
      Serial.println ("stop mouvement");   
      backward(M1);
      backward(M2);
      backward(M3);
      backward(M4);
    }
    if(results.value==next){
       right();
    }
    if(results.value==previous){
       left();
    }
  }
}

 

void forward(int M[]){
  digitalWrite(M[0],HIGH) ;
  digitalWrite(M[1],LOW) ;
}
void brake(int M[]){
  digitalWrite(M[0],LOW) ;
  digitalWrite(M[1],LOW) ;
}
void backward(int M[]){
  digitalWrite(M[0],LOW) ;
  digitalWrite(M[1],HIGH) ;
}
void right(){
 forward(M1);
 forward(M4);
 backward(M2);
 backward(M3);
 delay(2000);
 
 
}
void left(){
 forward(M2);
 forward(M3);
 backward(M1);
 backward(M4);
 delay(2000);
 
}

void forwardAll(){
      forward(M1);
      forward(M2);
      forward(M3);
      forward(M4);
}
