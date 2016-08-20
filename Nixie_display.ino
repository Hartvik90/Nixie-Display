/*
 Name:		Sketch1.ino
 Created:	8/20/2016 12:29:15 PM
 Author:	Hartvik
*/


#define BUFFER_SIZE 100;
#include <EEPROM.h>


//Pin layout for 74HC595
int latchPin = 8;
int clockPin = 12;
int sdPin = 4;
int dataPin = 11;



byte byteArray[100];
byte byteArrayFlip[100];


void setup() {
	//set pins to output so you can control the shift register
	pinMode(latchPin, OUTPUT);
	pinMode(clockPin, OUTPUT);
	pinMode(dataPin, OUTPUT);

	// Loading tenMeters

	// Creates an array formatting from 8 bit format to 2*4 bit format.
	int count;
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			byteArray[count] = (j << 4) | i;
			count++;
		}
	}
	//überpro 1337 K0-D
	//N1x13flUsH 2k4r34L
	for (int i = 1; i < 1000; i *= 10) {
		for (int j = 0; j < 10; j++) {
			nixieOut(i*j);
			delay(66);
		}
	}

}
//	Serial.begin(9600);					// Open serialcommunication


void count(byte data, byte data2) {
	// Shift out the bits:
	digitalWrite(latchPin, LOW);
	shiftOut(dataPin, clockPin, MSBFIRST, data);
	shiftOut(dataPin, clockPin, MSBFIRST, data2);
	digitalWrite(latchPin, HIGH);
}



void nixieOut(int treeDig) {
	//Calculates from decimalnvalue to binary sh-reg outputnumeric value out to Nixies. 
	//In = 3 digit int/long.
	count(byteArray[treeDig % 100], byteArray[treeDig / 100]);
}

// the loop function runs over and over again until power down or reset
void loop() {
  
}
