#include "HyperDisplay_UG2856KLBAG01.h"
#include <Streaming.h>

#define CS A6
#define DC A7
#define W UG2856KLBAG01_WIDTH
#define H UG2856KLBAG01_HEIGHT

UG2856KLBAG01_SPI oled;

void lineTest();
void rectTest();
void circleTest();
// void showMario(void);
// void showPipe(void);

SSD1309_Bite_t wind_mem[W * H];

void setup() {
	Serial.begin(115200);
	Serial << "Ready" << endl;
	SPI.begin(SCK, MISO, MOSI, SS);
	oled.begin(CS, DC, SPI);
}

void moveWindow(int8_t x, int8_t y, wind_info_t* pwind) {
	pwind->xMin += x;
	pwind->yMin += y;
	pwind->xMax += x;
	pwind->yMax += y;
}

void loop() {
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

	// // Move mario to his home
	// for (uint8_t i = 0; i < 15; i++) {
	// 	oled.windowClear();
	// 	moveWindow(1, -1, &mariosWindow);
	// 	showMario();
	// }

	// for (uint8_t i = 0; i < 15; i++) {
	// 	oled.windowClear();
	// 	moveWindow(1, 1, &mariosWindow);
	// 	showMario();
	// }

	// oled.windowClear();
	// moveWindow(13, -15, &mariosWindow);
	// showMario();

	// oled.windowClear();
	// moveWindow(13, 15, &mariosWindow);
	// showMario();

	// oled.windowClear();
	// moveWindow(13, -15, &mariosWindow);
	// showMario();

	// oled.windowClear();
	// moveWindow(13, 15, &mariosWindow);
	// showMario();

	// oled.windowClear();
	// moveWindow(5, -23, &mariosWindow);
	// showMario();

	// oled.windowClear();
	// moveWindow(17, 0, &mariosWindow);
	// showMario();

	// delay(500);

	// oled.windowClear();
// }

// void showMario(void) {
// 	oled.pixelSet(6, 2);
// 	oled.pixelSet(7, 2);
// 	oled.pixelSet(8, 2);
// 	oled.pixelSet(9, 2);
// 	oled.pixelSet(10, 2);
// 	oled.pixelSet(11, 2);
// 	oled.pixelSet(12, 2);
// 	oled.pixelSet(13, 2);
// 	oled.pixelSet(5, 3);
// 	oled.pixelSet(6, 3);
// 	oled.pixelSet(7, 3);
// 	oled.pixelSet(8, 3);
// 	oled.pixelSet(9, 3);
// 	oled.pixelSet(10, 3);
// 	oled.pixelSet(11, 3);
// 	oled.pixelSet(12, 3);
// 	oled.pixelSet(13, 3);
// 	oled.pixelSet(14, 3);
// 	oled.pixelSet(15, 3);
// 	oled.pixelSet(16, 3);
// 	oled.pixelSet(17, 3);
// 	oled.pixelSet(18, 3);
// 	oled.pixelSet(4, 4);
// 	oled.pixelSet(5, 4);
// 	oled.pixelSet(6, 4);
// 	oled.pixelSet(7, 4);
// 	oled.pixelSet(8, 4);
// 	oled.pixelSet(9, 4);
// 	oled.pixelSet(10, 4);
// 	oled.pixelSet(11, 4);
// 	oled.pixelSet(12, 4);
// 	oled.pixelSet(13, 4);
// 	oled.pixelSet(14, 4);
// 	oled.pixelSet(15, 4);
// 	oled.pixelSet(16, 4);
// 	oled.pixelSet(17, 4);
// 	oled.pixelSet(18, 4);
// 	oled.pixelSet(4, 5);
// 	oled.pixelSet(5, 5);
// 	oled.pixelSet(6, 5);
// 	oled.pixelSet(7, 5);
// 	oled.pixelSet(8, 5);
// 	oled.pixelSet(9, 5);
// 	oled.pixelSet(10, 5);
// 	oled.pixelSet(11, 5);
// 	oled.pixelSet(12, 5);
// 	oled.pixelSet(13, 5);
// 	oled.pixelSet(14, 5);
// 	oled.pixelSet(15, 5);
// 	oled.pixelSet(4, 6);
// 	oled.pixelSet(5, 6);
// 	oled.pixelSet(6, 6);
// 	oled.pixelSet(7, 6);
// 	oled.pixelSet(8, 6);
// 	oled.pixelSet(9, 6);
// 	oled.pixelSet(10, 6);
// 	oled.pixelSet(11, 6);
// 	oled.pixelSet(12, 6);
// 	oled.pixelSet(13, 6);
// 	oled.pixelSet(14, 6);
// 	oled.pixelSet(15, 6);
// 	oled.pixelSet(3, 7);
// 	oled.pixelSet(4, 7);
// 	oled.pixelSet(5, 7);
// 	oled.pixelSet(6, 7);
// 	oled.pixelSet(7, 7);
// 	oled.pixelSet(8, 7);
// 	oled.pixelSet(9, 7);
// 	oled.pixelSet(10, 7);
// 	oled.pixelSet(11, 7);
// 	oled.pixelSet(12, 7);
// 	oled.pixelSet(13, 7);
// 	oled.pixelSet(14, 7);
// 	oled.pixelSet(15, 7);
// 	oled.pixelSet(16, 7);
// 	oled.pixelSet(17, 7);
// 	oled.pixelSet(18, 7);
// 	oled.pixelSet(3, 8);
// 	oled.pixelSet(4, 8);
// 	oled.pixelSet(5, 8);
// 	oled.pixelSet(6, 8);
// 	oled.pixelSet(7, 8);
// 	oled.pixelSet(8, 8);
// 	oled.pixelSet(9, 8);
// 	oled.pixelSet(10, 8);
// 	oled.pixelSet(11, 8);
// 	oled.pixelSet(12, 8);
// 	oled.pixelSet(13, 8);
// 	oled.pixelSet(14, 8);
// 	oled.pixelSet(15, 8);
// 	oled.pixelSet(16, 8);
// 	oled.pixelSet(17, 8);
// 	oled.pixelSet(18, 8);
// 	oled.pixelSet(3, 9);
// 	oled.pixelSet(4, 9);
// 	oled.pixelSet(5, 9);
// 	oled.pixelSet(6, 9);
// 	oled.pixelSet(7, 9);
// 	oled.pixelSet(8, 9);
// 	oled.pixelSet(9, 9);
// 	oled.pixelSet(10, 9);
// 	oled.pixelSet(11, 9);
// 	oled.pixelSet(12, 9);
// 	oled.pixelSet(13, 9);
// 	oled.pixelSet(14, 9);
// 	oled.pixelSet(15, 9);
// 	oled.pixelSet(16, 9);
// 	oled.pixelSet(17, 9);
// 	oled.pixelSet(18, 9);
// 	oled.pixelSet(19, 9);
// 	oled.pixelSet(3, 10);
// 	oled.pixelSet(4, 10);
// 	oled.pixelSet(5, 10);
// 	oled.pixelSet(6, 10);
// 	oled.pixelSet(7, 10);
// 	oled.pixelSet(8, 10);
// 	oled.pixelSet(9, 10);
// 	oled.pixelSet(10, 10);
// 	oled.pixelSet(11, 10);
// 	oled.pixelSet(12, 10);
// 	oled.pixelSet(13, 10);
// 	oled.pixelSet(14, 10);
// 	oled.pixelSet(15, 10);
// 	oled.pixelSet(16, 10);
// 	oled.pixelSet(17, 10);
// 	oled.pixelSet(18, 10);
// 	oled.pixelSet(3, 11);
// 	oled.pixelSet(4, 11);
// 	oled.pixelSet(5, 11);
// 	oled.pixelSet(6, 11);
// 	oled.pixelSet(7, 11);
// 	oled.pixelSet(8, 11);
// 	oled.pixelSet(9, 11);
// 	oled.pixelSet(10, 11);
// 	oled.pixelSet(11, 11);
// 	oled.pixelSet(12, 11);
// 	oled.pixelSet(13, 11);
// 	oled.pixelSet(14, 11);
// 	oled.pixelSet(15, 11);
// 	oled.pixelSet(16, 11);
// 	oled.pixelSet(17, 11);
// 	oled.pixelSet(18, 11);
// 	oled.pixelSet(6, 12);
// 	oled.pixelSet(7, 12);
// 	oled.pixelSet(8, 12);
// 	oled.pixelSet(9, 12);
// 	oled.pixelSet(10, 12);
// 	oled.pixelSet(11, 12);
// 	oled.pixelSet(12, 12);
// 	oled.pixelSet(13, 12);
// 	oled.pixelSet(14, 12);
// 	oled.pixelSet(15, 12);
// 	oled.pixelSet(16, 12);
// 	oled.pixelSet(5, 13);
// 	oled.pixelSet(6, 13);
// 	oled.pixelSet(7, 13);
// 	oled.pixelSet(8, 13);
// 	oled.pixelSet(9, 13);
// 	oled.pixelSet(10, 13);
// 	oled.pixelSet(11, 13);
// 	oled.pixelSet(12, 13);
// 	oled.pixelSet(13, 13);
// 	oled.pixelSet(4, 14);
// 	oled.pixelSet(5, 14);
// 	oled.pixelSet(6, 14);
// 	oled.pixelSet(7, 14);
// 	oled.pixelSet(8, 14);
// 	oled.pixelSet(9, 14);
// 	oled.pixelSet(10, 14);
// 	oled.pixelSet(11, 14);
// 	oled.pixelSet(12, 14);
// 	oled.pixelSet(13, 14);
// 	oled.pixelSet(3, 15);
// 	oled.pixelSet(4, 15);
// 	oled.pixelSet(5, 15);
// 	oled.pixelSet(6, 15);
// 	oled.pixelSet(7, 15);
// 	oled.pixelSet(8, 15);
// 	oled.pixelSet(9, 15);
// 	oled.pixelSet(10, 15);
// 	oled.pixelSet(11, 15);
// 	oled.pixelSet(12, 15);
// 	oled.pixelSet(13, 15);
// 	oled.pixelSet(14, 15);
// 	oled.pixelSet(15, 15);
// 	oled.pixelSet(16, 15);
// 	oled.pixelSet(17, 15);
// 	oled.pixelSet(18, 15);
// 	oled.pixelSet(2, 16);
// 	oled.pixelSet(3, 16);
// 	oled.pixelSet(4, 16);
// 	oled.pixelSet(5, 16);
// 	oled.pixelSet(6, 16);
// 	oled.pixelSet(7, 16);
// 	oled.pixelSet(8, 16);
// 	oled.pixelSet(9, 16);
// 	oled.pixelSet(10, 16);
// 	oled.pixelSet(11, 16);
// 	oled.pixelSet(12, 16);
// 	oled.pixelSet(13, 16);
// 	oled.pixelSet(14, 16);
// 	oled.pixelSet(15, 16);
// 	oled.pixelSet(16, 16);
// 	oled.pixelSet(17, 16);
// 	oled.pixelSet(18, 16);
// 	oled.pixelSet(1, 17);
// 	oled.pixelSet(2, 17);
// 	oled.pixelSet(3, 17);
// 	oled.pixelSet(4, 17);
// 	oled.pixelSet(5, 17);
// 	oled.pixelSet(6, 17);
// 	oled.pixelSet(7, 17);
// 	oled.pixelSet(8, 17);
// 	oled.pixelSet(9, 17);
// 	oled.pixelSet(10, 17);
// 	oled.pixelSet(11, 17);
// 	oled.pixelSet(12, 17);
// 	oled.pixelSet(13, 17);
// 	oled.pixelSet(14, 17);
// 	oled.pixelSet(15, 17);
// 	oled.pixelSet(16, 17);
// 	oled.pixelSet(17, 17);
// 	oled.pixelSet(18, 17);
// 	oled.pixelSet(19, 17);
// 	oled.pixelSet(1, 18);
// 	oled.pixelSet(2, 18);
// 	oled.pixelSet(3, 18);
// 	oled.pixelSet(4, 18);
// 	oled.pixelSet(5, 18);
// 	oled.pixelSet(6, 18);
// 	oled.pixelSet(7, 18);
// 	oled.pixelSet(8, 18);
// 	oled.pixelSet(9, 18);
// 	oled.pixelSet(10, 18);
// 	oled.pixelSet(11, 18);
// 	oled.pixelSet(12, 18);
// 	oled.pixelSet(13, 18);
// 	oled.pixelSet(14, 18);
// 	oled.pixelSet(15, 18);
// 	oled.pixelSet(16, 18);
// 	oled.pixelSet(17, 18);
// 	oled.pixelSet(18, 18);
// 	oled.pixelSet(19, 18);
// 	oled.pixelSet(1, 19);
// 	oled.pixelSet(2, 19);
// 	oled.pixelSet(3, 19);
// 	oled.pixelSet(4, 19);
// 	oled.pixelSet(5, 19);
// 	oled.pixelSet(6, 19);
// 	oled.pixelSet(7, 19);
// 	oled.pixelSet(8, 19);
// 	oled.pixelSet(9, 19);
// 	oled.pixelSet(10, 19);
// 	oled.pixelSet(11, 19);
// 	oled.pixelSet(12, 19);
// 	oled.pixelSet(13, 19);
// 	oled.pixelSet(14, 19);
// 	oled.pixelSet(15, 19);
// 	oled.pixelSet(16, 19);
// 	oled.pixelSet(17, 19);
// 	oled.pixelSet(18, 19);
// 	oled.pixelSet(19, 19);
// 	oled.pixelSet(1, 20);
// 	oled.pixelSet(2, 20);
// 	oled.pixelSet(3, 20);
// 	oled.pixelSet(4, 20);
// 	oled.pixelSet(5, 20);
// 	oled.pixelSet(6, 20);
// 	oled.pixelSet(7, 20);
// 	oled.pixelSet(8, 20);
// 	oled.pixelSet(9, 20);
// 	oled.pixelSet(10, 20);
// 	oled.pixelSet(11, 20);
// 	oled.pixelSet(12, 20);
// 	oled.pixelSet(13, 20);
// 	oled.pixelSet(14, 20);
// 	oled.pixelSet(15, 20);
// 	oled.pixelSet(16, 20);
// 	oled.pixelSet(17, 20);
// 	oled.pixelSet(18, 20);
// 	oled.pixelSet(19, 20);
// 	oled.pixelSet(1, 21);
// 	oled.pixelSet(2, 21);
// 	oled.pixelSet(3, 21);
// 	oled.pixelSet(4, 21);
// 	oled.pixelSet(5, 21);
// 	oled.pixelSet(6, 21);
// 	oled.pixelSet(7, 21);
// 	oled.pixelSet(8, 21);
// 	oled.pixelSet(9, 21);
// 	oled.pixelSet(10, 21);
// 	oled.pixelSet(11, 21);
// 	oled.pixelSet(12, 21);
// 	oled.pixelSet(13, 21);
// 	oled.pixelSet(14, 21);
// 	oled.pixelSet(15, 21);
// 	oled.pixelSet(16, 21);
// 	oled.pixelSet(17, 21);
// 	oled.pixelSet(18, 21);
// 	oled.pixelSet(19, 21);
// 	oled.pixelSet(1, 22);
// 	oled.pixelSet(2, 22);
// 	oled.pixelSet(3, 22);
// 	oled.pixelSet(4, 22);
// 	oled.pixelSet(5, 22);
// 	oled.pixelSet(6, 22);
// 	oled.pixelSet(7, 22);
// 	oled.pixelSet(8, 22);
// 	oled.pixelSet(9, 22);
// 	oled.pixelSet(10, 22);
// 	oled.pixelSet(11, 22);
// 	oled.pixelSet(12, 22);
// 	oled.pixelSet(13, 22);
// 	oled.pixelSet(14, 22);
// 	oled.pixelSet(15, 22);
// 	oled.pixelSet(16, 22);
// 	oled.pixelSet(17, 22);
// 	oled.pixelSet(18, 22);
// 	oled.pixelSet(19, 22);
// 	oled.pixelSet(4, 23);
// 	oled.pixelSet(5, 23);
// 	oled.pixelSet(6, 23);
// 	oled.pixelSet(7, 23);
// 	oled.pixelSet(8, 23);
// 	oled.pixelSet(12, 23);
// 	oled.pixelSet(13, 23);
// 	oled.pixelSet(14, 23);
// 	oled.pixelSet(15, 23);
// 	oled.pixelSet(16, 23);
// 	oled.pixelSet(4, 24);
// 	oled.pixelSet(5, 24);
// 	oled.pixelSet(6, 24);
// 	oled.pixelSet(7, 24);
// 	oled.pixelSet(13, 24);
// 	oled.pixelSet(14, 24);
// 	oled.pixelSet(15, 24);
// 	oled.pixelSet(16, 24);
// 	oled.pixelSet(3, 25);
// 	oled.pixelSet(4, 25);
// 	oled.pixelSet(5, 25);
// 	oled.pixelSet(6, 25);
// 	oled.pixelSet(14, 25);
// 	oled.pixelSet(15, 25);
// 	oled.pixelSet(16, 25);
// 	oled.pixelSet(17, 25);
// 	oled.pixelSet(18, 25);
// 	oled.pixelSet(2, 26);
// 	oled.pixelSet(3, 26);
// 	oled.pixelSet(4, 26);
// 	oled.pixelSet(5, 26);
// 	oled.pixelSet(6, 26);
// 	oled.pixelSet(14, 26);
// 	oled.pixelSet(15, 26);
// 	oled.pixelSet(16, 26);
// 	oled.pixelSet(17, 26);
// 	oled.pixelSet(18, 26);
// 	oled.pixelSet(19, 26);
// 	oled.pixelSet(1, 27);
// 	oled.pixelSet(2, 27);
// 	oled.pixelSet(3, 27);
// 	oled.pixelSet(4, 27);
// 	oled.pixelSet(5, 27);
// 	oled.pixelSet(6, 27);
// 	oled.pixelSet(14, 27);
// 	oled.pixelSet(15, 27);
// 	oled.pixelSet(16, 27);
// 	oled.pixelSet(17, 27);
// 	oled.pixelSet(18, 27);
// 	oled.pixelSet(19, 27);
// 	oled.pixelSet(20, 27);
// }

// void showPipe(void) {
// 	oled.pixelSet(2, 2);
// 	oled.pixelSet(3, 2);
// 	oled.pixelSet(4, 2);
// 	oled.pixelSet(5, 2);
// 	oled.pixelSet(6, 2);
// 	oled.pixelSet(7, 2);
// 	oled.pixelSet(8, 2);
// 	oled.pixelSet(9, 2);
// 	oled.pixelSet(10, 2);
// 	oled.pixelSet(11, 2);
// 	oled.pixelSet(12, 2);
// 	oled.pixelSet(13, 2);
// 	oled.pixelSet(14, 2);
// 	oled.pixelSet(15, 2);
// 	oled.pixelSet(16, 2);
// 	oled.pixelSet(17, 2);
// 	oled.pixelSet(18, 2);
// 	oled.pixelSet(19, 2);
// 	oled.pixelSet(20, 2);
// 	oled.pixelSet(21, 2);
// 	oled.pixelSet(22, 2);
// 	oled.pixelSet(2, 3);
// 	oled.pixelSet(22, 3);
// 	oled.pixelSet(2, 4);
// 	oled.pixelSet(12, 4);
// 	oled.pixelSet(13, 4);
// 	oled.pixelSet(14, 4);
// 	oled.pixelSet(15, 4);
// 	oled.pixelSet(16, 4);
// 	oled.pixelSet(22, 4);
// 	oled.pixelSet(2, 5);
// 	oled.pixelSet(12, 5);
// 	oled.pixelSet(13, 5);
// 	oled.pixelSet(14, 5);
// 	oled.pixelSet(15, 5);
// 	oled.pixelSet(16, 5);
// 	oled.pixelSet(17, 5);
// 	oled.pixelSet(22, 5);
// 	oled.pixelSet(2, 6);
// 	oled.pixelSet(4, 6);
// 	oled.pixelSet(5, 6);
// 	oled.pixelSet(9, 6);
// 	oled.pixelSet(12, 6);
// 	oled.pixelSet(13, 6);
// 	oled.pixelSet(14, 6);
// 	oled.pixelSet(15, 6);
// 	oled.pixelSet(16, 6);
// 	oled.pixelSet(22, 6);
// 	oled.pixelSet(2, 7);
// 	oled.pixelSet(12, 7);
// 	oled.pixelSet(13, 7);
// 	oled.pixelSet(14, 7);
// 	oled.pixelSet(15, 7);
// 	oled.pixelSet(16, 7);
// 	oled.pixelSet(17, 7);
// 	oled.pixelSet(22, 7);
// 	oled.pixelSet(2, 8);
// 	oled.pixelSet(12, 8);
// 	oled.pixelSet(13, 8);
// 	oled.pixelSet(14, 8);
// 	oled.pixelSet(15, 8);
// 	oled.pixelSet(16, 8);
// 	oled.pixelSet(22, 8);
// 	oled.pixelSet(2, 9);
// 	oled.pixelSet(12, 9);
// 	oled.pixelSet(13, 9);
// 	oled.pixelSet(14, 9);
// 	oled.pixelSet(15, 9);
// 	oled.pixelSet(16, 9);
// 	oled.pixelSet(22, 9);
// 	oled.pixelSet(2, 10);
// 	oled.pixelSet(12, 10);
// 	oled.pixelSet(13, 10);
// 	oled.pixelSet(14, 10);
// 	oled.pixelSet(15, 10);
// 	oled.pixelSet(16, 10);
// 	oled.pixelSet(17, 10);
// 	oled.pixelSet(22, 10);
// 	oled.pixelSet(2, 11);
// 	oled.pixelSet(4, 11);
// 	oled.pixelSet(5, 11);
// 	oled.pixelSet(9, 11);
// 	oled.pixelSet(12, 11);
// 	oled.pixelSet(13, 11);
// 	oled.pixelSet(14, 11);
// 	oled.pixelSet(15, 11);
// 	oled.pixelSet(16, 11);
// 	oled.pixelSet(17, 11);
// 	oled.pixelSet(18, 11);
// 	oled.pixelSet(22, 11);
// 	oled.pixelSet(2, 12);
// 	oled.pixelSet(3, 12);
// 	oled.pixelSet(4, 12);
// 	oled.pixelSet(5, 12);
// 	oled.pixelSet(6, 12);
// 	oled.pixelSet(7, 12);
// 	oled.pixelSet(8, 12);
// 	oled.pixelSet(9, 12);
// 	oled.pixelSet(10, 12);
// 	oled.pixelSet(11, 12);
// 	oled.pixelSet(12, 12);
// 	oled.pixelSet(13, 12);
// 	oled.pixelSet(14, 12);
// 	oled.pixelSet(15, 12);
// 	oled.pixelSet(16, 12);
// 	oled.pixelSet(17, 12);
// 	oled.pixelSet(18, 12);
// 	oled.pixelSet(19, 12);
// 	oled.pixelSet(20, 12);
// 	oled.pixelSet(21, 12);
// 	oled.pixelSet(22, 12);
// 	oled.pixelSet(3, 13);
// 	oled.pixelSet(6, 13);
// 	oled.pixelSet(7, 13);
// 	oled.pixelSet(11, 13);
// 	oled.pixelSet(13, 13);
// 	oled.pixelSet(14, 13);
// 	oled.pixelSet(15, 13);
// 	oled.pixelSet(16, 13);
// 	oled.pixelSet(17, 13);
// 	oled.pixelSet(20, 13);
// 	oled.pixelSet(21, 13);
// 	oled.pixelSet(3, 14);
// 	oled.pixelSet(6, 14);
// 	oled.pixelSet(14, 14);
// 	oled.pixelSet(20, 14);
// 	oled.pixelSet(21, 14);
// 	oled.pixelSet(3, 15);
// 	oled.pixelSet(6, 15);
// 	oled.pixelSet(14, 15);
// 	oled.pixelSet(15, 15);
// 	oled.pixelSet(20, 15);
// 	oled.pixelSet(21, 15);
// 	oled.pixelSet(3, 16);
// 	oled.pixelSet(6, 16);
// 	oled.pixelSet(14, 16);
// 	oled.pixelSet(15, 16);
// 	oled.pixelSet(20, 16);
// 	oled.pixelSet(21, 16);
// 	oled.pixelSet(3, 17);
// 	oled.pixelSet(6, 17);
// 	oled.pixelSet(14, 17);
// 	oled.pixelSet(15, 17);
// 	oled.pixelSet(20, 17);
// 	oled.pixelSet(21, 17);
// 	oled.pixelSet(3, 18);
// 	oled.pixelSet(6, 18);
// 	oled.pixelSet(14, 18);
// 	oled.pixelSet(15, 18);
// 	oled.pixelSet(20, 18);
// 	oled.pixelSet(21, 18);
// 	oled.pixelSet(3, 19);
// 	oled.pixelSet(6, 19);
// 	oled.pixelSet(14, 19);
// 	oled.pixelSet(20, 19);
// 	oled.pixelSet(21, 19);
// 	oled.pixelSet(3, 20);
// 	oled.pixelSet(6, 20);
// 	oled.pixelSet(14, 20);
// 	oled.pixelSet(15, 20);
// 	oled.pixelSet(20, 20);
// 	oled.pixelSet(21, 20);
// 	oled.pixelSet(3, 21);
// 	oled.pixelSet(6, 21);
// 	oled.pixelSet(14, 21);
// 	oled.pixelSet(15, 21);
// 	oled.pixelSet(20, 21);
// 	oled.pixelSet(21, 21);
// 	oled.pixelSet(3, 22);
// 	oled.pixelSet(6, 22);
// 	oled.pixelSet(14, 22);
// 	oled.pixelSet(15, 22);
// 	oled.pixelSet(20, 22);
// 	oled.pixelSet(21, 22);
// 	oled.pixelSet(3, 23);
// 	oled.pixelSet(6, 23);
// 	oled.pixelSet(14, 23);
// 	oled.pixelSet(15, 23);
// 	oled.pixelSet(20, 23);
// 	oled.pixelSet(21, 23);
// 	oled.pixelSet(3, 24);
// 	oled.pixelSet(6, 24);
// 	oled.pixelSet(14, 24);
// 	oled.pixelSet(20, 24);
// 	oled.pixelSet(21, 24);
// }
