
const int outputAPin1  = 3;
const int outputAPin2  = 5;
double voltage1 = 1;
double voltage2 = 2;
double factor  =  51;
double val1     = voltage1 * factor;
double val2     = voltage2 * factor;

void setup() {
  // put your setup code here, to run once:
   Serial.begin(9600);
   
}

void loop() {
  // put your main code here, to run repeatedly:

 

  analogWrite(outputAPin1, 127);
  analogWrite(outputAPin2, val2);
  
  Serial.print("pin1 = ");
  Serial.print(outputAPin1);
  Serial.print("\t output1 = ");
  Serial.print(voltage1);
  Serial.print("[V] value1 = ");
  Serial.println(val1);

  Serial.print("pin2 = ");
  Serial.print(outputAPin2);
  Serial.print("\t output2 = ");
  Serial.print(voltage2);
  Serial.print("[V] value2 = ");
  Serial.println(val2);

  
  // アナログ->デジタル変換のために2ミリ秒のウェイトが必要
  delay(2);
}
