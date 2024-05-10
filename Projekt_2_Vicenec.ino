#include <Keypad.h>
#include <U8glib.h>
#include <WiFi.h>


U8GLIB_SSD1306_128X32 mujOled(U8G_I2C_OPT_NONE);


const byte ROWS = 4;
const byte COLS = 4;


char cislo_jedna = 'E';
char cislo_dva = 'E';
char cislo_tri = 'E';
char cislo_ctyri = 'E';


String zprava;


int dvere = 1; // 1 odkodovane, 0 zakodovane 


long int prepis = 0;
int pozice;
bool smer = 1;


#define ZELENA_LED 14
#define CERVENA_LED 15


char keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};


byte rowPins[ROWS] = {16, 17, 18, 19};
byte colPins[COLS] = {21, 22, 23, 23};


Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);


const char* ssid = "Uc17_IoT";
const char* password = "teleinformatika";


WiFiServer server(80);


void setup() {
  Serial.begin(115200);


  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);


  WiFi.begin(ssid, password);


  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");


  // Start the server
  server.begin();
  Serial.println("Server started");


  // Print the IP address
  Serial.println(WiFi.localIP());
}


void loop() {
  char key = keypad.getKey();


  //--------------------------------------------------------------------------------------------------------------
  // KLAVESNICE A HESLO 
  //--------------------------------------------------------------------------------------------------------------


  
  if (cislo_jedna = 'E') {
    cislo_jedna = key;
    Serial.print(cislo_jedna);
    zprava = "Heslo: ";
    zprava += "*";
  }


  if (cislo_jedna != 'E') {
    cislo_dva = key;
    Serial.print(cislo_jedna);
    Serial.print(cislo_dva);
    zprava += "*";
  }
  
  if (cislo_dva != 'E') {
    cislo_tri = key;
    Serial.print(cislo_jedna);
    Serial.print(cislo_dva);
    Serial.print(cislo_tri);
    zprava += "*";
  }


  if (cislo_tri != 'E') {
    cislo_ctyri = key;
    Serial.print(cislo_jedna);
    Serial.print(cislo_dva);
    Serial.print(cislo_tri);
    Serial.print(cislo_ctyri);
    zprava += "*";
  }


  if ( cislo_jedna == '1' && cislo_dva == '5' && cislo_tri == 'A' && cislo_ctyri == 'D') {


     if (dvere = 1){
      dvere = 0;
      Serial.print("Dveře zakodovane");
      String zprava = "Dveře zakodovane";
     } else {
      dvere = 1;
      Serial.print("Dveře odkodovane");
      String zprava = "Dveře odkodovane";
     }


  } else {
     cislo_jedna = 'E';
     cislo_dva = 'E';
     cislo_tri = 'E';
     cislo_ctyri = 'E';
     Serial.print("špatně zadané heslo, zkuste to znovu později");
     String zprava = "špatně zadané heslo, zkuste to znovu později";
  }


//--------------------------------------------------------------------------------------------------------------
// LEDKY 
//--------------------------------------------------------------------------------------------------------------


  if (dvere = 1){
    digitalWrite(ZELENA_LED, HIGH);
    digitalWrite(CERVENA_LED, LOW);
  } else {
    digitalWrite(ZELENA_LED, LOW);
    digitalWrite(CERVENA_LED, HIGH);
  }


//--------------------------------------------------------------------------------------------------------------
//DISPLEJ
//--------------------------------------------------------------------------------------------------------------


 if (millis()-prepis > 100) {
      mujOled.firstPage();
    do {
      vykresliText(pozice, zprava);
    } while( mujOled.nextPage() );
    prepis = millis();
    if (smer) {
      pozice += 1;
      if (pozice > zprava.length()-15) {
        smer = 0;
      }
    }
    else {
      pozice -= 1;
      if (pozice == 0) {
        smer = 1;
      }
    }
  }
  delay(10);


//--------------------------------------------------------------------------------------------------------------
//ODESÍLÁNÍ HODNOT VOJTOVI
//--------------------------------------------------------------------------------------------------------------


  WiFiClient client = server.available();
  if (!client) {
    return;
  }


  // Wait until the client sends some data
  Serial.println("new client");
  while(!client.available()){
    delay(1);
  }


  // Read the first line of the request
  String request = client.readStringUntil('\r');
  Serial.println(request);
  client.flush();


  // Send a response to the client
  client.println("HTTP/1.1 200 OK");
  client.println("Content-Type: text/plain");
  client.println("");




  int value = dvere;
  client.print("Value: ");
  client.println(value);


  // Close the connection
  delay(1);
  client.stop();
  Serial.println("client disconnected");
}


//--------------------------------------------------------------------------------------------------------------
//DISPLEJ FUNKCE
//--------------------------------------------------------------------------------------------------------------


void vykresliText(int posun, String text) {
  mujOled.setFont(u8g_font_fub14);
  mujOled.setPrintPos(0, 25);
  String vypis;
  vypis = text.substring(posun, posun+15);
  mujOled.print(vypis);
}