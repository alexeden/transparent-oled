#include "HyperDisplay_UG2856KLBAG01.h"
#include <Streaming.h>

#define CS 4
#define DC 5

#define W UG2856KLBAG01_WIDTH
#define H UG2856KLBAG01_HEIGHT

UG2856KLBAG01_SPI oled;

void lineTest();
void rectTest();
void circleTest();

void setup() {
	Serial.begin(115200);
	Serial << "Ready" << endl;
	// SPI.begin(SCK, MISO, MOSI, SS);
	SPI.begin();
	oled.begin(CS, DC, SPI);
}

void moveWindow(int8_t x, int8_t y, wind_info_t* pwind) {
	pwind->xMin += x;
	pwind->yMin += y;
	pwind->xMax += x;
	pwind->yMax += y;
}

void loop() {
	oled.windowClear();
	oled.setTextCursor(0, 0);
	oled.print("Hello world");
	delay(3000);
	// oled.
	delay(5000);

	lineTest();
	delay(500);

	rectTest();
	delay(500);

	circleTest();
	delay(500);
}

void lineTest(void) {
	oled.clearDisplay();

	for (hd_hw_extent_t indi = 0; indi < oled.xExt; indi += 5) {
		oled.lineSet(0, 0, indi, oled.yExt - 1, 1);
		delay(10);
	}

	for (hd_hw_extent_t indi = 0; indi < oled.yExt; indi += 5) {
		oled.lineSet(0, oled.yExt - 1, oled.xExt - 1, oled.yExt - indi - 1, 1);
		delay(10);
	}

	for (hd_hw_extent_t indi = 0; indi < oled.xExt; indi += 5) {
		oled.lineSet(oled.xExt - 1, oled.yExt - 1, oled.xExt - indi - 1, 0, 1);
		delay(10);
	}

	for (hd_hw_extent_t indi = 0; indi < oled.yExt; indi += 5) { oled.lineSet(oled.xExt - 1, 0, 0, indi, 1); }
}

void rectTest(void) {
	oled.clearDisplay();

	for (uint8_t indi = 0; indi < oled.yExt / 2; indi += 1) {
		oled
		  .rectangleSet(oled.xExt / 2 - 1 - indi, oled.yExt / 2 - 1 - indi, oled.xExt / 2 + 1 + indi, oled.yExt / 2 + 1 + indi, false);
		delay(50);
	}

	for (uint8_t indi = 0; indi < oled.yExt / 2; indi += 1) {
		oled
		  .rectangleClear(oled.xExt / 2 - 1 - indi, oled.yExt / 2 - 1 - indi, oled.xExt / 2 + 1 + indi, oled.yExt / 2 + 1 + indi, false);
		delay(50);
	}

	for (uint8_t indi = 0; indi < oled.yExt / 2; indi += 1) {
		oled
		  .rectangleSet(oled.xExt / 2 - 1 - indi, oled.yExt / 2 - 1 - indi, oled.xExt / 2 + 1 + indi, oled.yExt / 2 + 1 + indi, false);
		delay(50);
	}
}

void circleTest(void) {
	oled.clearDisplay();

	for (uint8_t indi = 0; indi < (oled.xExt / 2 - 1); indi++) {
		oled.circleSet((oled.xExt / 2 - 1), (oled.yExt / 2 - 1), indi, false);
		delay(10);
	}
	oled.circleSet((oled.xExt / 2 - 1), (oled.yExt / 2 - 1), oled.xExt / 2, true);
}

// void loop() {
// wind_info_t mariosWindow, pipeWindow;
// oled.setWindowDefaults(&mariosWindow);
// oled.setWindowDefaults(&pipeWindow);

// // Make the window just big enough for Mario
// mariosWindow.xMax = 21;
// mariosWindow.yMax = 28;

// pipeWindow.xMax = 24;
// pipeWindow.yMax = 24;

// // Move the windows into the starting position
// moveWindow(0, 34, &mariosWindow);
// moveWindow(W - 24, H - 24, &pipeWindow);

// // Draw Pipe
// oled.pCurrentWindow = &pipeWindow;
// showPipe();

// // Draw Mario at the starting position
// oled.pCurrentWindow = &mariosWindow;
// showMario();
