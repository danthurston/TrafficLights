int ledCarRed = 11;
int ledCarAmber = 12;
int ledCarGreen = 13;
int ledCarRed2 = 8;
int ledCarAmber2 = 9;
int ledCarGreen2 = 10;
int ledPedGreen = 7;
int ledPedRed = 6;
int incomingByte;

void setup() {
  pinMode(ledCarRed, OUTPUT);
  pinMode(ledCarAmber, OUTPUT);
  pinMode(ledCarGreen, OUTPUT);
  pinMode(ledCarRed2, OUTPUT);
  pinMode(ledCarAmber2, OUTPUT);
  pinMode(ledCarGreen2, OUTPUT);
  pinMode(ledPedGreen, OUTPUT);
  pinMode(ledPedRed, OUTPUT);
  Serial.begin(9600);
}
void set1 (int red, int amber, int green){
  digitalWrite(ledCarRed, red);
  digitalWrite(ledCarAmber, amber);
  digitalWrite(ledCarGreen, green);
}
void set2 (int red2, int amber2, int green2){
  digitalWrite(ledCarRed2, red2);
  digitalWrite(ledCarAmber2, amber2);
  digitalWrite(ledCarGreen2, green2);
}

void ped1 (int pedRed, int pedGreen){
  digitalWrite(ledPedRed, pedRed);
  digitalWrite(ledCarGreen, pedGreen);
}

void loop() {
  if (Serial.available() > 0) {
    incomingByte = Serial.read();
    if (incomingByte == 'X') {
      // pedestrian cross - phase 1
      set1 (LOW, HIGH, LOW);
      set2 (LOW, HIGH, LOW);
      Serial.print("L1: OFF, ON, OFF. L2: OFF, ON, OFF. PED: ON, OFF");
      delay(2000);    // wait for a second.
      
      // pedestrian cross - phase 2
      set1 (HIGH, LOW, LOW);
      set2 (HIGH, LOW, LOW);
      delay(2000);    // safety pause.
      ped1 (LOW, HIGH);
      Serial.print("L1: ON, OFF, OFF. L2: ON, OFF, OFF. PED: OFF, ON");
      delay(2000);    // wait for a second.
      
      // pedestrian cross - phase 3
      Serial.print("L1: ON, OFF, OFF. L2: ON, OFF, OFF. PED: OFF, OFF");
      ped1 (LOW, LOW);
      delay(250);
      Serial.print("L1: ON, OFF, OFF. L2: ON, OFF, OFF. PED: OFF, ON");   
      ped1 (LOW, HIGH);
      delay(250);
      Serial.print("L1: ON, OFF, OFF. L2: ON, OFF, OFF. PED: OFF, OFF");
      ped1 (LOW, LOW);
      delay(250);
      Serial.print("L1: ON, OFF, OFF. L2: ON, OFF, OFF. PED: OFF, ON");
      ped1 (LOW, HIGH);
      delay(250);
      Serial.print("L1: ON, OFF, OFF. L2: ON, OFF, OFF. PED: OFF, OFF");
      ped1 (LOW, LOW);
      delay(250);
      Serial.print("L1: ON, OFF, OFF. L2: ON, OFF, OFF. PED: OFF, ON");
      ped1 (LOW, HIGH);
      delay(250);    // wait for a second.
      
      // pedestrian cross - phase 4
      ped1 (HIGH, LOW);
      set2(HIGH, HIGH, LOW);
      Serial.print("L1: ON, OFF, OFF. L2: ON, ON, OFF. PED: ON, OFF");
      delay(2000);    // wait for a second.
    }
  }
  // phase 1
  ped1(HIGH, LOW);
  set1(HIGH, LOW, LOW);
  set2(LOW, LOW, HIGH);
  Serial.print("L1: ON, OFF, OFF. L2: OFF, OFF, ON. PED: ON, OFF");
  delay(2000);    // wait for a second.
    
  // phase 2
  set1(HIGH, HIGH, LOW);
  set2(LOW, HIGH, LOW);
  Serial.print("L1: ON, ON, OFF. L2: OFF, ON, OFF. PED: ON, OFF");
  delay(2000);    // wait for a second.
  
  // phase 3
  set1(LOW, LOW, HIGH);
  set2(HIGH, LOW, LOW);
  Serial.print("L1: OFF, OFF, ON. L2: ON, OFF, OFF. PED: ON, OFF");
  delay(2000);    // wait for a second.
  
  // phase 4
  set1(LOW, HIGH, LOW);
  set2(HIGH, HIGH, LOW);
  Serial.print("L1: OFF, ON, OFF. L2: ON, ON, OFF. PED: ON, OFF");
  delay(2000);    // wait for a second.
}
