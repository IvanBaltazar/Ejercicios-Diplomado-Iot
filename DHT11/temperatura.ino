//Ivan Baltazar Camacho
//UAM Azcapotzalco
//la libreria DTH.h nos permitira manenjar el sensor DTH11 mas facilmente con funciones ya creadas

 #include "DHT.h"
//Definimos en que pin se recibira la informacion
 #define DHTPIN 13   
//definimos el tipo de sensor DTH usaremos
 #define DHTTYPE DHT11   

//llamamos la funcion dth y mandamos el tipo de sensor y el pin
 DHT dht(DHTPIN, DHTTYPE);
//en la funcion setup asigaremos la frecuencia con la que se trabajara
// y se llevara acabo una prueba de coneccion del sensor
  void setup() {
  	Serial.begin(115200);
  	Serial.println(F("Prueba de coenxion"));
  	dht.begin();
	}
//en la funcion loop determinaremos que haremos con la lectura de informacion
    void loop() {
//con delay determinaremos cada cunto tiempo se ejecutara
  	delay(2000);
//Recibiremos las señales del sensor
  	float t = dht.readTemperature();
  	float f = dht.readTemperature(true);
//En caso de no recibir alguna de las señales
//se notificara que no hay coneccion
  if ( isnan(t) || isnan(f)) {
    Serial.println(F("No hay conexion"));
    return;
  }
//Mostraremos los niveles de la temperatura
 
  Serial.print(F("Temperatura en °C "));
  Serial.print(t);
  Serial.print(F(" Temperatura en °F"));
  Serial.println(f);
  
}