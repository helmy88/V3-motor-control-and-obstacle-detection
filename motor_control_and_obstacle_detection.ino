const int rxPin = 10; // RX pin of Arduino connected to TX pin of Maker Mini Sumo Controller
const int txPin = 11; // TX pin of Arduino connected to RX pin of Maker Mini Sumo Controller

const int sensorPin = A0; // Example sensor pin (analog sensor)

const int leftMotorPin = 3; // Pin for left motor control
const int rightMotorPin = 5; // Pin for right motor control

void setup() {
  Serial.begin(9600); // Initialize Serial Monitor
  Serial1.begin(9600); // Initialize Serial communication with Maker Mini Sumo Controller
  
  pinMode(sensorPin, INPUT); // Set sensor pin as input
  pinMode(leftMotorPin, OUTPUT); // Set left motor pin as output
  pinMode(rightMotorPin, OUTPUT); // Set right motor pin as output
}

void loop() {
  if (Serial1.available()) {
    char data = Serial1.read(); // Read data from Maker Mini Sumo Controller
    
    // Motor Control Logic
    if (data == 'S') {
      stopMotors();
    } else if (data == 'F') {
      moveForward();
    } else if (data == 'B') {
      moveBackward();
    } else if (data == 'L') {
      turnLeft();
    } else if (data == 'R') {
      turnRight();
    }
    
    // Read sensor value and include additional status conditions
    int sensorValue = analogRead(sensorPin);
    if (sensorValue > 800) {
      Serial.println("Obstacle Detected!");
      stopMotors(); // Stop motors if an obstacle is detected
    }
  }
}

// Motor Control Functions
void stopMotors() {
  digitalWrite(leftMotorPin, LOW);
  digitalWrite(rightMotorPin, LOW);
}

void moveForward() {
  digitalWrite(leftMotorPin, HIGH);
  digitalWrite(rightMotorPin, HIGH);
  // Add any specific motor control code for moving forward
}

void moveBackward() {
  digitalWrite(leftMotorPin, LOW);
  digitalWrite(rightMotorPin, LOW);
  // Add motor control code for moving backward
}

void turnLeft() {
  digitalWrite(leftMotorPin, LOW);
  digitalWrite(rightMotorPin, HIGH);
  // Add motor control code for turning left
}

void turnRight() {
  digitalWrite(leftMotorPin, HIGH);
  digitalWrite(rightMotorPin, LOW);
  // Add motor control code for turning right
}
