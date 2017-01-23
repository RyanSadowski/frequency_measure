 #include <LiquidCrystal.h>
int input=13;

int high_time;
int low_time;
float time_period;
float freq;
float frequency;
LiquidCrystal lcd(0, 1, 3, 4, 5, 6);
void setup()
{
pinMode(input,INPUT);
lcd.begin(16, 2);
}
void loop()
{
lcd.clear();
lcd.setCursor(0,0);
lcd.print("Frequency Meter");

high_time=pulseIn(input,HIGH);
low_time=pulseIn(input,LOW);


time_period=high_time+low_time;
time_period=time_period/1000;
frequency=1000/time_period;
lcd.setCursor(0,1);
lcd.print(frequency);
lcd.print(" Hz");
delay(500);
}
