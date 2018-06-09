GsmWrap::GsmWrap(){
	rx = STD_RX_PIN;
	tx = STD_TX_PIN;
	baudrate = STD_BAUD;
	
	beginSerial();
}

GsmWrap::GsmWrap(int rxPin, int txPin, int baud){
	rx = rxPin;
	tx = txPin;
	baudrate = baud;
	
	beginSerial();
}

GsmWrap::beginSerial(){
	ss = new SoftwareSerial(rx, tx);
	ss.begin(baud);
}

