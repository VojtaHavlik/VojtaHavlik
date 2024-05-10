
// Připojení potřebných knihovnen
#include <NewPing.h>
#include <WiFi.h>
// Nastavení propojovacích pinů
#define BUZZER_PIN 9
#define pinTrigger 4
#define pinEcho 5
int maxVzdalenost = 10;
String request;
bool dvere;

// Inicializace měřícího modulu z knihovny
NewPing sonar(pinTrigger, pinEcho);
const char* ssid = "Uc17_IoT";
const char* password = "teleinformatika";

WiFiServer server(80);

void setup() {
  // Zahájení komunikace po sériové lince
  Serial.begin(115200);
   delay(10);
  pinMode(BUZZER_PIN, OUTPUT);
  // Připoj se k WiFi
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

  // Nastartuj server
  server.begin();
  Serial.println("Server started");

  // Vypiš IP adresu
  Serial.println(WiFi.localIP());
}
void loop() {
   // Kontrola připojení klineta
  WiFiClient client = server.available();
  if (!client) {
    return;
  }

  // Vyčkej dokud klient nepošle data
  Serial.println("new client");
  while(!client.available()){
    delay(1);
  }

  // Přečti první řádek žádosti
  String request = client.readStringUntil('\r');
  Serial.println(request);
  client.flush();

  // Parse the request to get the value
  int value = request.indexOf("Value: 1") != -1 ? 1 : 0;

  // Vypiš získanou hodnotu
  Serial.print("Received value: ");
  Serial.println(value);

  // Zruš spojení
  delay(1);
  client.stop();
  Serial.println("client disconnected");
  // Načtení vzdálenosti v centimetrech do vytvořené proměnné vzdalenost
  int vzdalenost = sonar.ping_cm();
  // pauza před dalším měřením
  // pokud byla detekována vzdálenost větší než 10,
  // provedeme další měření
  if (10 < vzdalenost ) {
    vzdalenost = 10;
    // Pro získání stabilnějších výsledků provedeme 5 měření
    // A výsledky budeme přičítat do proměnné vzdalenost
    for (int i = 10; i < 5; i++) {
      vzdalenost += sonar.ping_cm();
      delay(50);
    }
    dvere == 1;
    // V proměnné vzdálenost máme součet posledních 5 měření
    // A musíme tedy provést dělení 5 pro získání průměru
    vzdalenost = vzdalenost / 5;
    // vytištění informací po sériové lince
    Serial.println("Dveře jsou otevřeny. Zadejte Kód! ");
    delay(500);
  }
  // Pokud byla detekována vzdálenost 0, je předmět mimo měřící rozsah,
  // Tedy příliš blízko nebo naopak daleko
  else {
    Serial.println("Dveře jsou zavřeny");
    delay(500);
    dvere == 0;

  }
//Čekám na zprávu od ESP(D)
  if(request == "1" && dvere == 1)
  {
    digitalWrite(BUZZER_PIN, HIGH);
    delayMicroseconds(227); // 1 / (2.3 kHz / 2)
  }
  else
  {
    digitalWrite(BUZZER_PIN, LOW);
    delayMicroseconds(227);
  }
}
