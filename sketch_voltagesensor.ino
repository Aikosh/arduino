//For Arduino Due 

// input value fctor: (アナログ値:0～4095@12bit)/voltage(3.34V_max) = factor
//double factor = 1226.;
double factor = 1240.;

// output voltage factor: (アナログ値:0～4095@12bit)/voltage(2.75V_max) = factor2
double factor2 = 1488.;

const int analogInPin0 = A0; 
const int analogInPin1 = A5; 

double sensorValue0 = 0.;
double sensorValue1 = 0.;          

double val;

const int np = 20000;
double sensorValue0_meas;
double sensorValue1_meas;

double sum_Value0 = 0.;
double sum_Value1 = 0.;

double ave_Value0 = 0.;
double ave_Value1 = 0.;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  
}

void loop() {

double sum_Value0 = 0.;
double sum_Value1 = 0.;
double ave_Value0 = 0.;
double ave_Value1 = 0.;


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
  

  //double nt = 2000./np;
  for (int i=0; i<np; i++) {

    //delayMicroseconds(nt);
    
    sensorValue0_meas = analogRead(analogInPin0);
    sensorValue1_meas = analogRead(analogInPin1);
    
/*
    Serial.print("sensor1_meas[");
    Serial.print(i);
    Serial.print("]= ");
    Serial.print(sensorValue1_meas);
    Serial.print("\t output1_meas = ");
    Serial.print(sensorValue1_meas/factor);
    Serial.println("[V]");
*/
    sum_Value0 += sensorValue0_meas;
    sum_Value1 += sensorValue1_meas;

    sensorValue0_meas = 0.;
    sensorValue1_meas = 0.;
   
/*
    if (sensorValue0_meas[i] == 4095.) {
      sum_Value0 += 1;
    } else bleak;

    if (sensorValue0_meas[i] != 4095.) {
      sum_Value0 += 0.001;
    } else bleak;
    
*/
    
  }

    
    ave_Value0 = sum_Value0/np;
    ave_Value1 = sum_Value1/np;
    
    Serial.print("average V0: ");
    Serial.print(ave_Value0);
    Serial.print(" , V1: ");
    Serial.println(ave_Value1);

/*
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
  
  analogWrite(DAC0, ave_Value0);
  analogWrite(DAC1, ave_Value1);

  // シリアルモニターに結果をプリントする
  Serial.print("sensor0 = ");
  Serial.print(ave_Value0);
  Serial.print("\t output0 = ");
  Serial.print(ave_Value0/factor2);
  Serial.println("[V]");

  Serial.print("sensor1 = ");
  Serial.print(ave_Value1);
  Serial.print("\t output1 = ");
  Serial.print(ave_Value1/factor2);
  Serial.println("[V]");


/*
  Serial.print("sensor1 = ");
  Serial.print(sensorValue1);
  Serial.print("\t output1 = ");
  Serial.print(sensorValue1/factor);
  Serial.println("[V]");
*/
  //Serial.print("val = ");
  //Serial.println(val);

  // アナログ->デジタル変換のために2ミリ秒のウェイトが必要
//  delay(2);
delay(1000);

}
