const int AOUTpinMQ2 = 0;  //imposto il numero del pin per il sensore MQ2
const int AOUTpinMQ3 = 1;  //imposto il numero del pin per il sensore MQ5
const int AOUTpinMQ5 = 2;  //imposto il numero del pin per il sensore MQ5
const int AOUTpinMQ135 = 3; //imposto il numero del pin per il sensore MQ135

int limit = 300;
// You can change this value to make the device more sensitive
int value2;
int value3;
int value5;
int value135;

int portarossa = 9; // porta 11 da collegare all’anodo “rosso” del modulo RGB
int portaverde = 10; // porta 10 da collegare all’anodo “verde” del modulo RGB
int portablu = 11; // porta 9 da collegare all’anodo “blu” del modulo RBG

void colore (unsigned char rosso, unsigned char verde, unsigned char blu)
{
 analogWrite(portarossa, rosso); //attiva il led rosso con l’intensita’ definita nella variabile rosso
 analogWrite(portablu, blu); //attiva il led blu con l’intensita’ definita nella variabile blu
 analogWrite(portaverde, verde); //attiva il led verde con l’intensita’ definita nella variabile verde
}
void leggiRicerca(){
  for(int i = 0; i<20; i++){
    value2 = analogRead(AOUTpinMQ2);  //legge i dati analogi del sensore MQ-2
    value3 = analogRead(AOUTpinMQ3);  //legge i dati analogi del sensore MQ-3
    value5 = analogRead(AOUTpinMQ5);  //legge i dati analogi del sensore MQ-5
    value135 = analogRead(AOUTpinMQ135);  // legge i dati anologici del sensore MQ-135
    Serial.print(value2);
    Serial.print(",");
    Serial.print(value3);
    Serial.print(",");
    Serial.print(value5);
    Serial.print(",");
    Serial.println(value135);
    //Serial.println("#"); //prints the methane value
    delay(1000);
  }
}

void setup() {
  Serial.begin(9600);  //imposto la banda di rete del seriale
  Serial.println("CLEARDATA");
  Serial.println("MQ2,MQ3,MQ5,MQ135");
}

void loop()
{
  leggiRicerca();
  colore(22,155,22);
  delay(1000);
}
