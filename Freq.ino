 #include <LiquidCrystal.h>
int hallEffectsPin=13;
int RPMpin=12;

int high_time;
int low_time;
float mph;
float circumfrence;
float time_period;
float freq;
float frequency;
LiquidCrystal lcd(0, 1, 3, 4, 5, 6);
void setup()
{
pinMode(hallEffectsPin,INPUT);
pinMode(RPMpin,INPUT);
lcd.begin(16, 2);
circumfrence = 74.186; //find yours @ http://www.csgnetwork.com/tiresizescalc.html
}
void loop()
{
lcd.clear();
lcd.setCursor(0,0);
 
rpm_high=pulseIn(RPMpin,HIGH);
rpm_low=pulseIn(RPMpin,LOW);
 
rpm_period=rpm_high+rpm_low;
rpm_period=rpm_period/1000;
tach=(1000/rpm_period) * 60;
lcd.print(String(tach) + " RPM");

high_time=pulseIn(hallEffectsPin,HIGH);
low_time=pulseIn(hallEffectsPin,LOW);


time_period=high_time+low_time;
time_period=time_period/1000;
frequency=1000/time_period;
mph=frequency * 3600 * (circumfrence * 0.000015783);
lcd.setCursor(0,1);
lcd.print(mph);
lcd.print(" mph");
delay(500);
}
