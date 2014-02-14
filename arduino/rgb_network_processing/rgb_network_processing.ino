#include <SPI.h>
#include <Ethernet.h>

// Enter a MAC address for your controller below.
// Newer Ethernet shields have a MAC address printed on a sticker on the shield
byte mac[] = { 
  0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };
// if you don't want to use DNS (and reduce your sketch size)
// use the numeric IP instead of the name for the server:
char server[] = "siminelaki.org";    // name address for the server (using DNS)

// Set the static IP address to use if the DHCP fails to assign
IPAddress ip(192,168,0,178);

// Initialize the Ethernet client library
// with the IP address and port of the server
// that you want to connect to (port 80 is default for HTTP):
EthernetClient client;

void setup() {

  pinMode(3,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);

  // Open serial communications and wait for port to open:
  Serial.begin(115200);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for Leonardo only
  }

  // start the Ethernet connection:
  if (Ethernet.begin(mac) == 0) {
    Serial.println("Failed to configure Ethernet using DHCP");
    // no point in carrying on, so do nothing forevermore:
    // try to congifure using IP address instead of DHCP:
    Ethernet.begin(mac, ip);
  }
  // give the Ethernet shield a second to initialize:
  delay(1000);
  //Serial.println("connecting...");

  // if you get a connection, report back via serial:
  if (client.connect(server, 80)) {
    //Serial.println("connected");
    // Make a HTTP request:
    client.println("GET /noname/arduino-test.php HTTP/1.1");
    client.println("Host: siminelaki.org");
    client.println("Connection: close");
    client.println();
  }
  else {
    // if you didn't get a connection to the server:
    //Serial.println("connection failed");
  }
}

char buffer[200];
int i=0;
int id, value;
int a_color[10];

void loop()
{
  // if there are incoming bytes available
  // from the server, read them and print them:
  while (client.available()) {
    buffer[i] = client.read();
    if( buffer[i] == '\n' )
    {
      buffer[i] = '\0';
      if( i > 0 && buffer[i-1] == ',' )
      {
        buffer[12] = '\0';
        id = atoi(buffer+8);

        buffer[27] = '\0';
        value = atoi(buffer+23);


        if( id==3 || id==5 || id==6 )
        {
          a_color[id]=value;
          analogWrite(id, value);
        }

        Serial.print(a_color[3]);
        Serial.print(",");   
        Serial.print(a_color[5]);
        Serial.print(",");   
        Serial.println(a_color[6]);      
      }
      i = -1;
    }
    i++;
    //Serial.print(c);
  }

  // if the server's disconnected, stop the client:
  if (!client.connected()) {
    //Serial.println();
    //Serial.println("disconnecting.");
    client.stop();
    // do nothing forevermore:
    while(true);
  }
}

