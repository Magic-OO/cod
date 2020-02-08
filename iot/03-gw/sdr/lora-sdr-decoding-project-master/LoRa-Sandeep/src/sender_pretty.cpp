#define PIZZA
#ifndef PIZZA // so this file is not compiled

/* main.cpp */

#include <SPI.h>
#include <LoRa.h>

#define RFM95_CS 8
#define RFM95_RST 4
#define RFM95_INT 3

#define RF95_FREQ 915E6

#define LED_WHEN_TRANSMITTING LED_BUILTIN

unsigned long startTransTime;

void setup() {
	pinMode(RFM95_RST, OUTPUT);
	digitalWrite(RFM95_RST, HIGH);

	Serial.begin(9600);

	// manual reset
	digitalWrite(RFM95_RST, LOW);
	delay(10);
	digitalWrite(RFM95_RST, HIGH);
	delay(10);

	// SPI pins setup
	LoRa.setPins(RFM95_CS, RFM95_RST, RFM95_INT);

	if (!LoRa.begin(RF95_FREQ)) {
    	Serial.println("Starting LoRa failed!"); while (1);
  	}
	Serial.println("OK LoRa radio init.");

	LoRa.setSpreadingFactor(8);
	LoRa.setSignalBandwidth(125E3);
	LoRa.setCodingRate4(5); // 5-8, inclusive
	LoRa.setPreambleLength(8);
}

void loop() {

	Serial.print("Sending...");
	digitalWrite(LED_WHEN_TRANSMITTING, HIGH);
	startTransTime = millis();

	LoRa.beginPacket(true); // true for implicit header
	uint8_t pkt[] = {0x12,0x34,0x56,0x9a,0xbc,0x00};
	LoRa.write(pkt, 6);

	bool hadSuccess = LoRa.endPacket();

	Serial.print("Success?: ");
	Serial.println(hadSuccess);

	digitalWrite(LED_WHEN_TRANSMITTING, LOW);
	Serial.print("Done transmitting, ");
	Serial.print((float)(millis() - startTransTime) / 1000);
	Serial.println(" sec. to complete.\n");

	delay(500);
}

#endif
