int p1 = 3; //yellow wire 
int p2 = 10; //green wire 
int p3 = 11; //blue wire 
//====================================
void setup() {

// Пины D3 и D11 - 62.5 кГц
TCCR2B = 0b00000001; // x1
TCCR2A = 0b00000011; // fast pwm
// Пины D9 и D10 - 62.5 кГц
TCCR1A = 0b00000001; // 8bit
TCCR1B = 0b00001001; // x1 fast pwm
}

int a = 1;
int delay_parameter = 1;
unsigned long timestamp =0;
//====================================
void g1(int pwm_duty){
 pinMode(p3, INPUT);
 pinMode(p1, OUTPUT);
 pinMode(p2, OUTPUT);
 digitalWrite(p1, LOW); 
 analogWrite(p2, pwm_duty);
 }
//====================================
void g2(int pwm_duty){
 pinMode(p3, INPUT);
 pinMode(p1, OUTPUT);
 pinMode(p2, OUTPUT); 
 digitalWrite(p2, LOW);
 analogWrite(p1, pwm_duty);
 }
//====================================
void g3(int pwm_duty){
 pinMode(p1, INPUT);
 pinMode(p2, OUTPUT);
 pinMode(p3, OUTPUT); 
 digitalWrite(p2, LOW); 
 analogWrite(p3, pwm_duty);
 }
//====================================
void g4(int pwm_duty){
 pinMode(p1, INPUT);
 pinMode(p2, OUTPUT);
 pinMode(p3, OUTPUT); 
 digitalWrite(p3, LOW);
 analogWrite(p2, pwm_duty); 
 }
//====================================
void g5(int pwm_duty){
 pinMode(p2, INPUT);
 pinMode(p1, OUTPUT);
 pinMode(p3, OUTPUT);
 digitalWrite(p1, LOW);
 analogWrite(p3, pwm_duty); 
 }
//====================================
void g6(int pwm_duty){
 pinMode(p2, INPUT);
 pinMode(p1, OUTPUT);
 pinMode(p3, OUTPUT);
 digitalWrite(p3, LOW);
 analogWrite(p1, pwm_duty); 
 }
//====================================
void off_all(){
 pinMode(p1, INPUT);
 pinMode(p2, INPUT);
 pinMode(p3, INPUT);
}
//====================================
void segment_call(int segment_number, int pwm_duty){
  switch (segment_number)
  {
    case 1: g1(pwm_duty); break;
    case 2: g2(pwm_duty); break;
    case 3: g3(pwm_duty); break;
    case 4: g4(pwm_duty); break;
    case 5: g5(pwm_duty); break;
    case 6: g6(pwm_duty); break;
    //default: break;
  }
}
//====================================
void smooth_blink(int delay_parameter){
  for (int br=20;br<255;br+=a){
    for (int seg=1; seg<=6; seg++){
      segment_call(seg,br); delay(delay_parameter);
    }
  }

  for (int br=255;br>20;br-=a){
    for (int seg=1; seg<=6; seg++){
      segment_call(seg,br); delay(delay_parameter);
    }
  }
}
//====================================
void Snake(int delay_parameter){
   for (int seg=1; seg<=6; seg++){
      for (int br=20;br<255;br+=a){
      segment_call(seg,br); delay(delay_parameter);
    }
     for (int br=255;br>20;br-=a){
      segment_call(seg,br); delay(delay_parameter);
    }
  }


   for (int seg=5; seg>=2; seg--){
      for (int br=20;br<255;br+=a){
      segment_call(seg,br); delay(delay_parameter);
    }
     for (int br=255;br>20;br-=a){
      segment_call(seg,br); delay(delay_parameter);
    }
  }
  

}
//====================================
void Smooth_snake(int delay_parameter){ 
  int next_seg;
   for (int seg=1; seg<=6; seg++){ 
    next_seg = seg+1;
      for (int br=255;br>=0;br-=a){
        segment_call(seg,br); delay(delay_parameter);
          if (next_seg == 7){next_seg=1; }
        segment_call(next_seg,255-br); delay(delay_parameter);
      }
   }
}
//====================================
void Circle(int br, int delay_parameter){
  for (int seg=1; seg<=6; seg++){
      segment_call(seg,br); delay(delay_parameter);
    }
}
//====================================
void Light(int br){
  Circle(br,1);
}
//====================================


void loop() {

//while ( (millis()- timestamp) < 1000 ){
//smooth_blink(1);
//}

//while (((millis()- timestamp) > 1000) && ((millis()- timestamp) < 200000)){
Smooth_snake(2);
//}

//while (((millis()- timestamp) > 200000) && ((millis()- timestamp) < 300000)){
//Circle(180, 200);
//}

//while (((millis()- timestamp) > 300000) && ((millis()- timestamp) < 400000)){
//Light(255);
//}

//timestamp = millis();

}
