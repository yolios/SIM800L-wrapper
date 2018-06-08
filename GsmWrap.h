class GsmWrap{
	public:
		GsmWrap();
		GsmWrap(int rxPin, int txPin, int baudrate);
		~GsmWrap();
		
	private:
		int rxPin;
		int txPin;
		int baudrate;
}