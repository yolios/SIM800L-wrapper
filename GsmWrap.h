#ifndef GSMWRAP_H
#define GSMWRAP_H

#include <Arduino.h>
#include <SoftwareSerial.h>

#define BUFFSIZE_IN 256

#define SERIAL_READ_TIMEOUT 5000

#define STD_RX_PIN 4
#define STD_TX_PIN 5
#define STD_BAUD 9600

/*struct GsmWrap_datetime{
	int year;
	int month;
	int day;
	int hour;
	int minute;
	int second;
};

enum GsmWrap_statusSMS {UNREAD, READ, UNSENT, SENT};

struct GsmWrap_sms{
	int index;
	char origin[];
	GsmWrap_statusSMS status;
	GsmWrap_datetime recieveTime;
};*/

class GsmWrap{
	public:
		GsmWrap(SoftwareSerial* softser);
		//~GsmWrap();
		
		void begin(int baud);
		bool serialAvailable();
		int serialRead();
		void serialWrite(const char* message);
		char* getInBuffer();
		void printBuffer();
		
		
		//int countSMS();
		//GsmWrap_sms readSMS(int index);
		//bool sendSMS(char[] number, char[] text);
		
	private:
		void clearInBuffer();
		
		SoftwareSerial* ss;
		char inBuffer[BUFFSIZE_IN];
};

#endif //GSMWRAP_H
