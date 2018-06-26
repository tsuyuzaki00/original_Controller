int inPin1 = 1;
int inPin2 = 2;
int inPin3 = 3;
int inPin4 = 4;
int inPin5 = 5;
int inPin6 = 6;

int UpButton;
int DownButton;
int RightButton;
int LeftButton;
int analogPin1;
int analogPin2;

void setup()
{
  Serial.begin(9600);
  pinMode(inPin3, INPUT);
  pinMode(inPin4, INPUT);
  pinMode(inPin5, INPUT);
  pinMode(inPin6, INPUT);
}

void loop()
{
  float XAxis = analogRead(0);
  float YAxis = analogRead(1);
  float Xsenser = analogRead(2);
  float Ysenser = analogRead(3);
  float Zsenser = analogRead(4);
  UpButton = digitalRead(inPin3);
  DownButton = digitalRead(inPin4);
  RightButton = digitalRead(inPin5);
  LeftButton = digitalRead(inPin6);
  
  Serial.println(XAxis);
  Serial.println(YAxis);
  Serial.println(Xsenser);
  Serial.println(Ysenser);
  Serial.println(Zsenser);
  Serial.println(UpButton);
  Serial.println(DownButton);
  Serial.println(RightButton);
  Serial.println(LeftButton);
}
