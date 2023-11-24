#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
//Librerias propias
#include "index.h" //Nuestra página web en HTML 

ESP8266WebServer server(80); //Crea el objeto server en el puerto 80

//Nombre y password del punto WIFI
const char *ssid = "Furia Polar";
const char *password = "12345"; //no usamos password


/** Handle Root
 * @brief Envía el contenido de index.h
 */
void handleRoot() {
 String s = MAIN_page; //Read HTML contents
 server.send(200, "text/html", s); //Send web page
}


/** Handle Button Request
 * @brief Esta función toma los valores enviados desde la página web y según su valor, llama a distintas funciones de motores.
  * Los botones de la página web ejecutan esta funcion -> sendRequest('http://192.168.4.1/B?val=1') 
 * La función sendRequest() crea una instancia de XMLHttpRequest() y la envía a través de WiFi a nuestra ESP8266.
 */
void handleButtonRequest(void) {

  int id = server.arg("val").toInt(); 
  //Avanzar
  if (id == 1) {
    motor_FWBW(true);
    server.send(200, "text/plain", "OK");
  }
  //Girar Izquierda
  if (id == 2) {
    motor_LR(false);   
    server.send(200, "text/plain", "OK");
  }
  
  //Girar Derecha
  if (id == 3) {
    motor_LR(true);   
    server.send(200, "text/plain", "OK");
  }
  //Atras
  if (id == 4) {
    motor_FWBW(false);   
    server.send(200, "text/plain", "OK");
  }
  //Stop 
  if (id == 5) {
    motor_stop();   
    server.send(200, "text/plain", "OK");
  }

  if (id == 6) { 
    motor_vel(true); // duplica la velocidad   
    server.send(200, "text/plain", "OK");
  }

  if (id == 7) {  // divide la velocidad en 2
    motor_vel(false);   
    server.send(200, "text/plain", "OK");
  }

  if (id == 8) {
    motor_arma(true); // se prende el arma  
    server.send(200, "text/plain", "OK");
  }
  
  if (id == 9) {
    motor_arma(false); // se apaga el arma
    server.send(200, "text/plain", "OK");
  }
}




/** Run Web Server
 * @brief Función principal que configura la conección wifi, crea el servidor y conecta las funciones.
 */

void run_web_server(void) {
  // Initialize serial communication
  Serial.begin(115200);
  
  // Create a new SoftAP network
  WiFi.softAP(ssid);


  // Print the IP address of the SoftAP network
  Serial.print("Access Point IP address: ");
  Serial.println(WiFi.softAPIP());
  Serial.println("Copien esta IP y péguenla en su navegador");




  server.on("/Button", HTTP_GET, handleButtonRequest); //Cuando estemos en la página Button, llamamos a la función handleButtonRequest y le 
  server.on("/", handleRoot);      //Which routine to handle at root location
  
  // Set up web server
  server.onNotFound([]() {
    handleRoot();
  });

  server.begin();
  Serial.println("Web server started");
}

void handle_client(void) {
  server.handleClient();
}
