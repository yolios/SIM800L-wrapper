#include <SoftwareSerial.h>

#define STD_RX_PIN 4
#define STD_TX_PIN 5
#define STD_BAUD 9600

class GsmWrap{
	public:
		GsmWrap();
		GsmWrap(int rxPin, int txPin, int baud);
		~GsmWrap();
		
		
	private:
		beginSerial();
	
		int rx;
		int tx;
		int baudrate;
		SoftwareSerial ss;
}