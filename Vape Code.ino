/*VAPE HOME MADE VERSI LOW BUDGET WITH HIGH PEFORMANCE
BY GHOZI YUSUF MATDOAN
WHATSSAPP : 08=57-7625-4687
INTAGRAM : @ghozi.ym
EMAIL : ghoziyusuf1@gmail.com*/

int mosfet = PB3;//Pin 
int tombol = PB1; //Pin
int trimpot_pin = PB0;//Pin

int baca_tombol=0;
int kunci=0;
float trimpot =0;
unsigned long waktu_sekarang =0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(tombol, INPUT_PULLUP);
  pinMode(mosfet, OUTPUT);

}

void loop() {
millis();
baca_tombol= digitalRead(tombol);
trimpot = analogRead(trimpot_pin);
delay(3);
trimpot = (trimpot/1024)*255; //membuat nilai PWM
delay(10);

safety();
delay(5);
 if(baca_tombol == HIGH){ //Kondisi tidak dipencet
  Serial.println("Mati");
  analogWrite(mosfet, 0);
  kunci=0;
 }else if (baca_tombol == LOW && kunci <= 5){
  Serial.println("Aktif");
  analogWrite(mosfet, trimpot);
 }
 delay(30);
}

void safety(){
  if(millis()- waktu_sekarang >=1000 && baca_tombol == LOW){
    waktu_sekarang = millis();
    kunci++;
    return kunci;
    } 
  }
