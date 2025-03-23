#define CALI_SIGNAL 7   // Pin to read signal from
// #define CALI_PIN 13    // LED pin (built-in LED)

#define trigPin 9
#define echoPin 10
#define BUZZER_PIN 8
#define ledPin 13

// defines variables
float duration;
float distance;
float safetyDistance;

int race;

int bad();

int checkrace();


void setup() {
    pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
    pinMode(echoPin, INPUT); // Sets the echoPin as an Input
    pinMode(BUZZER_PIN, OUTPUT);
    
    pinMode(CALI_SIGNAL, INPUT);   // Set pin 7 as input
    pinMode(ledPin, OUTPUT);    // Set pin 13 as output
    race = 0;
    Serial.begin(9600);
}


void loop() {
    // bad();
    checkrace();
    if(race){
        float song[] = {622.25, 0, 0, 622.25, 0, 0, 622.25, 0, 0, 622.25, 0, 0, 554.37, 0,0, 0, 0, 0, 0, 0, 0, 554.37, 0,  0, 0, 0, 0, 0, 0, 0, 466.16, 0, 0, 0, 0, 0, 0, 0, 0, 466.16, 0, 0, 0, 0, 0, 0, 0, 0, 554.37, 554.37, 554.37, 554.37, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
        for(int i = 0; i<sizeof(song)/sizeof(float); i++){
            if(!bad()){
            noTone(BUZZER_PIN);
            return;
            }
            tone(BUZZER_PIN, song[i]);
            if(song[i]==0) delay(20);
            else delay(100);
        }
    }
    else{
        float song[] = {554.37, 554.37, 622.25, 0, 622.25, 0, 0, 0, 0, 0, 622.25, 0, 622.25, 0, 0, 0, 0, 0, 622.25, 0, 622.25, 0, 0, 0, 0, 0, 622.25, 0, 0, 0};
        for(int j = 0; j<2; j++){
        for(int i = 0; i<sizeof(song)/sizeof(float); i++){
            if(!bad()){
            noTone(BUZZER_PIN);
            return;
            }
            tone(BUZZER_PIN, song[i]);
            if(song[i]==0) delay(20);
            else delay(100);
        }
        }
        
        float song2[] = {554.37, 554.37, 622.25, 0, 622.25, 0, 0, 0, 0, 0, 622.25, 0, 659.25, 0, 0, 0, 0, 0, 659.25, 0, 659.25, 0, 0, 0, 0, 0, 622.25, 0, 0, 0, 554.37, 554.37, 622.25, 0, 622.25, 0, 0, 0, 0, 659.25, 659.25, 659.25, 0, 659.25, 0, 659.25, 0, 622.25, 622.25};
        for(int i = 0; i<sizeof(song2)/sizeof(float); i++){
            if(!bad()){
            noTone(BUZZER_PIN);
            return;
            }
            tone(BUZZER_PIN, song2[i]);
            if(song2[i]==0) delay(20);
            else delay(100);
        }
    }
    
}

int checkrace(){
    int signal = digitalRead(CALI_SIGNAL);
    if(signal) race = !race;
}


int bad(){
    // Clears the trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);

  // Calculating the distance
  distance= duration*0.034/2;

  if(distance>0){
    Serial.print("Distance: ");
    Serial.println(distance);
  }

  if (distance<=20 & distance>0){ // Enter the Distance
    digitalWrite(ledPin, HIGH);
    return 1;
  }
  else{
    digitalWrite(ledPin, LOW);
    return 0;
  }

}
