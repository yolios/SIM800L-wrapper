#include "GsmWrap.h"

GsmWrap::GsmWrap(SoftwareSerial* softser){
	ss = softser;
}

//-------------------PUBliC---------------------

void GsmWrap::begin(int baud){
	ss->begin(baud);
}

bool GsmWrap::serialAvailable(){
	if(ss->available() > 0){
		return true;
	}
	else{
		return false;
	}
}

void GsmWrap::serialWrite(const char* message){
	Serial.print("serialWrite: ");
	Serial.println(message);
	ss->print(message);
}

int GsmWrap::serialRead(){
	clearInBuffer();
	
	char input;
	char* buffPtr = inBuffer;
	
	unsigned long int timeout = millis() + SERIAL_READ_TIMEOUT;
	while((millis() < timeout) && (buffPtr < (inBuffer + sizeof(inBuffer) - 1))){
		input = ss->read();
		//Serial.println((int)input);
		if(input != -1){
			*buffPtr = (char)input;
			buffPtr++;
			timeout = millis() + SERIAL_READ_TIMEOUT;
		}
	}
	//*buffPtr = '\0'; not needed due to memset with '\0'
	return buffPtr - inBuffer;
}

char* GsmWrap::getInBuffer(){
	return inBuffer;
}

void GsmWrap::printBuffer(){
	for(int i=0; i<BUFFSIZE_IN; i++){
		//Serial.print(i);
		//Serial.print(": ");
		Serial.write(inBuffer[i]);
	}
}

//----------------PRIVATE-------------------

void GsmWrap::clearInBuffer(){
	//std::memset(inBuffer, '\0', sizeof(inBuffer));
	for(char* i=inBuffer; i < (inBuffer + sizeof(inBuffer)); i++){
		*i = '\0';
	}
}
