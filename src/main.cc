#include <Streaming.h>
#include "HyperDisplay_UG2856KLBAG01.h"

UG2856KLBAG01_SPI oled;

void setup() {
	Serial.begin(115200);
	Serial << "Ready" << endl;


	SPI.begin(SCK, MISO, MOSI, SS);
	oled.begin(A4, A5);
}

void loop() {

}
