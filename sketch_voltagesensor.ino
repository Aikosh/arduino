
// sensorValue(アナログ値:0～4095)/voltage(0.55～2.75V) = factor
double factor = 1226;

const int analogInPin0 = A0; 
const int analogInPin1 = A5; 

double sensorValue0 = 0;
double sensorValue1 = 0;          

double val;
double sensorValue0_meas1, sensorValue0_meas2;
double sensorValue1_meas1, sensorValue1_meas2;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  
}

void loop() {
  // put your main code here, to run repeatedly:

  val = digitalRead(analogInPin0);
  
  analogReadResolution(12);
  analogWriteResolution(12);

  // アナログ入力の値を読む
  sensorValue0 = analogRead(analogInPin0);
  sensorValue1 = analogRead(analogInPin1);
  
  // アナログ入力の0～4095の値を、アナログ出力の使用範囲0～255に変換する
  //outputValue = map(sensorValue, 0, 4095, 0, 255);
  
  // アナログ出力値を変更する
  // analogWrite(analogOutPin, outputValue);
  
/*

  //電圧測定１回目
  sensorValue0_meas1 = analogRead(analogInPin0);
  sensorValue1_meas1 = analogRead(analogInPin1);
  delay(2);  
  
  //電圧測定２回目
  sensorValue0_meas2 = analogRead(analogInPin0);
  sensorValue1_meas2 = analogRead(analogInPin1);
  delay(10); 

  //電圧測定結果検証A0
  if (sensorValue0_meas1 == sensorValue0_meas2) {
    sensorValue0 = sensorValue0_meas1;
    analogWrite(DAC0, sensorValue0);
  } else {analogWrite(DAC0, 0);
    }

  //電圧測定結果検証A5
   if (sensorValue1_meas1 == sensorValue1_meas2) {
    sensorValue1 = sensorValue1_meas1;
    analogWrite(DAC1, sensorValue1);
  } else {analogWrite(DAC1, 0);
    }
*/
  
  //analogWrite(DAC0, sensorValue0);
  //analogWrite(DAC1, sensorValue1);

  // シリアルモニターに結果をプリントする
  Serial.print("sensor0 = ");
  Serial.print(sensorValue0);
  Serial.print("\t output0 = ");
  Serial.print(sensorValue0/factor);
  Serial.println("[V]");

  Serial.print("sensor1 = ");
  Serial.print(sensorValue1);
  Serial.print("\t output1 = ");
  Serial.print(sensorValue1/factor);
  Serial.println("[V]");

  Serial.print("val = ");
  Serial.println(val);

  // アナログ->デジタル変換のために2ミリ秒のウェイトが必要
  delay(1000);

}
