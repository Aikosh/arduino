//For Aruino Mega2560

//出力させるピン番号(PWM出力はディジタルピンのみ出力)
//出力させたい電圧値
//----##### CH1 ##### ------------------------------------
const int outputPin1 = 3;
double voltage1 = 1.6; //Dueで出力したい値（Megaのみで2.5V出力になる[127]）
double Voffset1 = 1.563; // for correction between Mega and Due

//----##### CH2 ##### ------------------------------------
const int outputPin2 = 5;
double voltage2 = 1.;
double Voffset2 = 1.67; // for correction between Mega and Due


double factor  =  51.; // this is 8 bit: 255(2^8-1) / 5V = 51

double val1     = voltage1 * factor * Voffset1 ;
double val2     = voltage2 * factor * Voffset2 ;

double Vdue_th = 3.3;

void setup() {
  // put your setup code here, to run once:
   Serial.begin(9600);
   
}

void loop() {
  // put your main code here, to run repeatedly:

  double Vin1 = voltage1 * Voffset1;
  double Vin2 = voltage2 * Voffset2;
  
  if (Vin1<=Vdue_th) {
    analogWrite(outputPin1, val1);
  } else {analogWrite(outputPin1, 0);}
  
  if (Vin2<=Vdue_th) {
    analogWrite(outputPin2, val2);
  } else {analogWrite(outputPin2, 0);}

  
  Serial.print("pin1 = ");
  Serial.print(outputPin1);
  Serial.print("\t output1 = ");
  Serial.print(voltage1);
  Serial.print("[V] value1 = ");
  Serial.println(val1);

  Serial.print("pin2 = ");
  Serial.print(outputPin2);
  Serial.print("\t output2 = ");
  Serial.print(voltage2);
  Serial.print("[V] value2 = ");
  Serial.println(val2);

  
  // アナログ->デジタル変換のために2ミリ秒のウェイトが必要
  delay(2);
}
