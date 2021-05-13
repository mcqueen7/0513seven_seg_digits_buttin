byte seven_seg_digits[10][7] = { { 0,0,0,0,0,0,1 },  // = 0
                                 { 1,0,0,1,1,1,1 },  // = 1
                                 { 0,0,1,0,0,1,0 },  // = 2
                                 { 0,0,0,0,1,1,0 },  // = 3
                                 { 1,0,0,1,1,0,0 },  // = 4
                                 { 0,1,0,0,1,0,0 },  // = 5
                                 { 0,1,0,0,0,0,0 },  // = 6
                                 { 0,0,0,1,1,1,1 },  // = 7
                                 { 0,0,0,0,0,0,0 },  // = 8
                                 { 0,0,0,1,1,0,0 }   // = 9
                             };

const int buttonPin = 12;
int buttonState = 0;
int num = 0;
int a=0;
void setup() {               
  pinMode(2, OUTPUT);  
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
 pinMode(9, OUTPUT);
  digitalWrite(9, 1);  // 關閉小數點
  digitalWrite(buttonPin,HIGH);
  pinMode(buttonPin,INPUT_PULLUP);
   Serial.begin(9600);
}

void sevenSegWrite(byte digit) {
  byte pin = 2;
  for (byte seg = 0; seg < 7; ++seg) {
    digitalWrite(pin, seven_seg_digits[digit][seg]);
    ++pin;
  }
}

void loop() {
  delay(3);
  buttonState = digitalRead(buttonPin);
  Serial.print(" buttonState =");
   Serial.println(buttonState);
    Serial.print("a=");
     Serial.println(a);
   
    delay(1);
 if(num > 9){
       num = 0;
    }
  if(buttonState==0&&a==1){
     num ++;
     a=0;
  }
 if(buttonState==1){
     a=1;
  }

  sevenSegWrite(num);
 //delay(100);

}

