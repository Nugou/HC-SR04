#ifndef ULTRAX_h
#define ULTRAX_h

class ULTRAX {
	private:
		int pinEcho, pinTrigger, pinBip, pinMotor, pinAlert;
		int ePowerMax, ePowerMin;
		
		unsigned long timeCompute, lastCompute;
		
		double distance;
		double duration;
		double timeM;
		double minDistance, maxDistance;
		
		bool eMotor, eBip, eAlert;
	
	public:
		ULTRAX(int, int);
		void enableMotor(int);
		void enableBip(int);
		void enableAlert(int);
		void setMinDistance(double);
		void setMaxDistance(double);
		void setMinPower(int);
		void setMaxPower(int);
		void disableCOM(int);
		
		double getDistance_MM();
		double getDistance_ME();
		double getDistance_CM();
		double getDistance_IN();
		
		const int MOTOR = 0;
		const int BIP = 1;
		const int ALERT = 2;
		
};
#endif

