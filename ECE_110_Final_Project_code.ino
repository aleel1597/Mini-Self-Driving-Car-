//low numbers = white
//high numbers = black
int PWMpin0 = 9;
int PWMpin1 = 3;

int sensorpin0 = A0;
int sensorpin1 = A1;

float White0 = 110;
float White1 = 110;

float Black0 = 970;
float Black1 = 930;

void setup(){
  pinMode(A0, INPUT); // set pin A1 as input
  pinMode(A1, INPUT); // set pin A2 as input
  pinMode(9, OUTPUT); // set pin A1 as input
  pinMode(3, OUTPUT); // set pin A2 as input
  Serial.begin(9600);
}

boolean white(float QRE_Value){
  if (QRE_Value < 800) return true; // white is 650-750
  else 
    return false;
}

void loop(){
  int QRE_Value0 = analogRead(A0); // sensor pin 1
  int QRE_Value1 = analogRead(A1); // sensor pin 2

  Serial.print(QRE_Value0);
  Serial.print("  ");
  Serial.println(QRE_Value1);

  if (white(QRE_Value1)) {analogWrite(9, 160); analogWrite(3, 30);}
  
  else if (white(QRE_Value0)) {analogWrite(3, 140); analogWrite(9,50);}
  
  else {
    analogWrite(9, 110); analogWrite(3, 80);
  }
}


