const int sLM35 = 0;  //sensor de temperatura LM35
const int psLuz = 8;     //indicador de luz acesa
const int pLuz = 13;     //luga luz
float temperatura = 0;
String enviaInformacoes = "";
void setup() {
  Serial.begin(9600);
  pinMode(pLuz, OUTPUT);
  pinMode(psLuz, INPUT_PULLUP);

}

void loop() {
  enviaInformacoes = readTemperatura(sLM35);
  if (digitalRead(psLuz) == LOW) {
    enviaInformacoes = readTemperatura(sLM35);
    enviaInformacoes += "L10";
  } else {
    enviaInformacoes = readTemperatura(sLM35);
    enviaInformacoes += "L11";
  }
  inverteLuz();
  
  //Serial.print("Temperatura: "+enviaInformacoes.substring(2) +" envia-->");
  Serial.println(enviaInformacoes); //Variavel enviada ao sistima com as leituras
}

String readTemperatura(int sensor) {
  delay(100);
  return "T1"+String( int( float(analogRead(sensor)) * 5 / 1023 * 100 ));
}

void inverteLuz() {
    if ( Serial.available()) {
    char c = Serial.read();
    if ( c == 'i' ) {
      digitalWrite(pLuz,!digitalRead(pLuz));
    }
  }
}
