#include <LiquidCrystal_I2C.h>
#include <Servo.h>
#include <Keypad.h>

#define PASSWORD 1234

LiquidCrystal_I2C lcd(0x27, 16, 2); // I2C address 0x27, 16 column and 2 rows
Servo servo;

const byte ROWS = 4; //four rows
const byte COLS = 4; //four columns
char keys[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};
byte rowPins[ROWS] = {9, 8, 7, 6}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {5, 4, 3, 2}; //connect to the column pinouts of the keypad

Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

int counter = 0;
int userInput = 0;

void setup() {
  lcd.init();                      // Initialize the LCD
  lcd.backlight();                 // Turn on backlight
  servo.attach(10);                // Attach servo to pin 10
}

void loop() {
  char key = keypad.getKey();
  if (key) {
    int currentUserInput = key - '0'; // Convert char to integer
    userInput = userInput * 10 + currentUserInput;
    Serial.print("userInput: ");
    Serial.println(userInput);
    counter++;
    if (counter >= 4) {
      counter = 0;
      if (userInput == PASSWORD) {
        // Display message on LCD
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Welcome");
        // RGB LED is green
        setColor(0, 255, 0);
        // Move servo motor for 90 degrees to the right
        servo.write(90);
        // Wait for 5 seconds
        delay(5000);
        // Move servo motor for 90 degrees to the left
        servo.write(0);
        // RGB LED is blue
        setColor(0, 0, 255);
        lcd.clear();
        lcd.setCursor(0, 0);
      } else {
        // Display message on LCD
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Forbidden access");
        // RGB LED is red
        setColor(255, 0, 0);
        // Wait for 3 seconds
        delay(3000);
        // RGB LED is blue
        setColor(0, 0, 255);
        lcd.clear();
        lcd.setCursor(0, 0);
      }
      userInput = 0;
    }
  }
}

void setColor(int red, int green, int blue) {
  analogWrite(6, red);   // Set RGB LED pin for red color
  analogWrite(5, green); // Set RGB LED pin for green color
  analogWrite(3, blue);  // Set RGB LED pin for blue color
}

