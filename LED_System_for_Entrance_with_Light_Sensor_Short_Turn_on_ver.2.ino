/******************************************
 * LED_System_for_Entrance_with_Light_Sensor
 * 
 * 参考
 * 1. LEDテープの電流値計算
 * http://aurarich.hatenablog.com/entry/20160109/1452345949
 * 
 * 2. FETのスイッチング
 * https://sites.google.com/site/karakuriisys/home/document/how_to_use_fet
 * 
 * 3. ゲート抵抗とスイッチング
 * https://toshiba.semicon-storage.com/content/dam/toshiba-ss/shared/docs/design-support/document/MOSFET-Gate-Drive-Circuit-Application-Notes_JA_36266.pdf
 * ゲート抵抗が大きいとスイッチングスピードが遅くなり、発熱による損失が大きくなる。
 * 
 * ver.2 update
 * LED keeps turned on while someone is in the entrance.
 * 
 * 
 *****************************************/


int Sensor = A0;
int Sensor2 = A1;
int LED = 3;
int s = 0;
int b = 0;

void setup() {
  pinMode(Sensor,INPUT_PULLUP);
  Serial.begin(9600);
}

void loop() {
  
  b = analogRead(Sensor2);
  
//  Serial.print("光センサ：");
//  Serial.println(b);
  
  if( b > 1000 ){          
    
    s = analogRead(Sensor);   

//  Serial.println(" ");
//  Serial.print("PIRモーションセンサ：");
//  Serial.println(s);
    
    if( s > 500 ){   
      analogWrite(LED,200);
      delay(5000);
      
      label:              // もしも消灯中に人を検知したら、プログラムがここからリスタートする
      
      delay(5000);
      s = analogRead(Sensor);
      if( s > 500){
        goto label;
      }else{
        for( int i = 0; i <= 2; i++ ){
          analogWrite(LED,200);
          delay(300);
          analogWrite(LED,0);
          delay(300);
        }
      }
          
    }
  }  
}
