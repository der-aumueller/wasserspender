int led1=8; //LED 1 an Pin 8
int led2=10; //LED 2 an Pin 10
int trigPin=2; //Trigger Ultraschallsensor Pin 2
int echoPin=4; //Echo Ultraschallsensor Pin 4
int richtungA           =12; //Pin 12 für die Richtung Motor A
int pwmA                =3;  //Pin für die Geschwindigkeit Motor A
int bremseA             =9;  //Pin 9 für die Bremse Motor A 
int geschwindigkeit   =255; //Geschwindigkeit festlegen

void setup() {
  pinMode(led1, OUTPUT); //led1 als output definieren
  pinMode(led2, OUTPUT); //led2 als output definieren
  pinMode(richtungA, OUTPUT); //richtungA als output definieren
  pinMode(bremseA, OUTPUT); //richtungB als output definieren
  analogWrite(pwmA, geschwindigkeit); //geschwindigkeit auf Pin 3 schreiben
  pinMode(trigPin,OUTPUT); //Trigger als output definieren
  pinMode(echoPin,INPUT); //Echo als input definieren

  digitalWrite(bremseA, HIGH); //Bremse A aktiv
  }
void loop() {
  long duration,distance;
  digitalWrite(trigPin,LOW); //Trigger auf Low
  delayMicroseconds(2); //warten
  digitalWrite(trigPin,HIGH); //Trigger auf High
  delayMicroseconds(10); //warten
  digitalWrite(trigPin,LOW); Trigger auf low
  duration = pulseIn(echoPin, HIGH); //Zeit messen bis Schall zurückkehrt
  distance=(duration/2)*0.03432; //Zeit in Entfernung umrechnen

if (distance <=5) { //wenn der Abstand kleiner oder gleich 5cm ist

    digitalWrite(led1, HIGH); //LED 1 und 2 an 
    digitalWrite(led2, HIGH);
    delay(1000); //nach einer Sekunde
    digitalWrite(bremseA, LOW); //Bremse A lösen 
    digitalWrite(richtungA ,HIGH);  //Motor A vorwärts
    delay(5000); // Motor läuft 5 Sekunden
    digitalWrite(bremseA, HIGH); //Motor aus
    delay(1000); // eine Sekunde warten
    digitalWrite(led1, LOW); //LED 1 und 2 aus
    digitalWrite(led2, LOW);
}
else {    //ansonsten
    
    digitalWrite(bremseA, HIGH);     //Motor aus
    
    }
  }
