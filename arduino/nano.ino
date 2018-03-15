#include<NewPing.h>
#define TRIGGER_PIN1  12  // Arduino pin tied to trigger pin on the ultrasonic sensor.
#define ECHO_PIN1     11  // Arduino pin tied to echo pin on the ultrasonic sensor.

#define TRIGGER_PIN2  10  // Arduino pin tied to trigger pin on the ultrasonic sensor.
#define ECHO_PIN2     9  // Arduino pin tied to echo pin on the ultrasonic sensor.
#define TRIGGER_PIN3  8  // Arduino pin tied to trigger pin on the ultrasonic sensor.
#define ECHO_PIN3     7  // Arduino pin tied to echo pin on the ultrasonic sensor.

#define MAX_DISTANCE 200 // Maximum distance we want to ping for (in centimeters). Maximum sensor distance is rated at 400-500cm.
#define DISTANCE 150
NewPing sonar1(TRIGGER_PIN1, ECHO_PIN1, MAX_DISTANCE);
NewPing sonar2(TRIGGER_PIN2, ECHO_PIN2, MAX_DISTANCE);
NewPing sonar3(TRIGGER_PIN3, ECHO_PIN3, MAX_DISTANCE);
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
}

void loop() {
  delay(20); // Wait 50ms between pings (about 20 pings/sec). 29ms should be the shortest delay between pings.
    if(sonar1.ping_cm()>10 and sonar1.ping_cm()<DISTANCE){
        Serial.println(1);
    }
    delay(20);
    if(sonar2.ping_cm()>10 and sonar2.ping_cm()<DISTANCE){
        Serial.println(2);
    }
    delay(20);
    if(sonar3.ping_cm()>10 and sonar3.ping_cm()<DISTANCE){
       Serial.println(3);
    }
}
