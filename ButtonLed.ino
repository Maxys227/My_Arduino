#define GREEN 7
#define YELLOW 8
#define RED 9
#define BUTTON 4

unsigned short buttonState = 0;

void workLED(int LED)
{
  digitalWrite(LED,HIGH);
}
void offLED(int LED)
{
  digitalWrite(LED,LOW);
}

void setup() {
  Serial.begin(9600);
  pinMode(BUTTON,INPUT);
  pinMode(GREEN,OUTPUT);
  pinMode(BUTTON,OUTPUT);
  pinMode(YELLOW,OUTPUT);
  pinMode(BUTTON,OUTPUT);
  pinMode(RED,OUTPUT);
  pinMode(BUTTON,OUTPUT);
}

void loop() {
  if (digitalRead(BUTTON))
  {
    buttonState++;
    Serial.println("Значение счётчика "+String(buttonState));
    delay(1000);
  }
  switch (buttonState)
    {
      case 1:
      {
        workLED(GREEN);
        break;
      }
      case 2:
      {
        offLED(GREEN);
        workLED(YELLOW);
        break;
      }
      case 3:
      {
        offLED(YELLOW);
        workLED(RED);
        break;
      }
      default:
      {
        offLED(RED);
        Serial.println("Ничего не происходит...");
        break;
      }
    }
  if (buttonState>3)
  {
    buttonState = 0;
    Serial.println("Обнуление счётчика");
    Serial.println("Значение счётчика "+String(buttonState));
  }

}
