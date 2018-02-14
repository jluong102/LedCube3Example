const int DataPin[] = {13, 12, 11, 10, 9, 8, 7, 6, 5};
const byte Layer[] = {A0, A1, A2};



void setup() {
  for (auto i = 0; i < 9 ; i++)
    pinMode(DataPin[i], OUTPUT);
  for (auto i = 0; i < 3 ; i++)
    pinMode(Layer[i], OUTPUT);

}
//////////////////////////////////////////////////////////
void BlinkOn()
{
  for (auto i = 0; i < 9 ; i++)
    digitalWrite(DataPin[i], HIGH);
  for (byte i = 0; i < 3; i++)
    digitalWrite(Layer[i], LOW);
}
void BlinkOff()
{
  for (auto i = 0; i < 9 ; i++)
    digitalWrite(DataPin[i], LOW);
   for (byte i = 0; i < 3; i++)
    digitalWrite(Layer[i], HIGH);
}
void BlinkAll()
{
  BlinkOn();
  delay(1000);
  BlinkOff();
  delay(1000);
}

void Cycle()
{
  for (auto i = 0; i < 9 ; i++)
  {
    digitalWrite(DataPin[i], HIGH);

    for (byte j = 0; j < 3; j++)
    {
      digitalWrite(Layer[j], LOW);
      delay(500);
      digitalWrite(Layer[j], HIGH);
    }
    digitalWrite(DataPin[i], LOW);
  }
}

void LayerRise()
{
  for (auto i = 0; i < 9 ; i++)
    digitalWrite(DataPin[i], HIGH);

  for (byte i = 0; i < 3; i++)
  {
    digitalWrite(Layer[i], LOW);
    delay(750);
    digitalWrite(Layer[i], HIGH);
  }

  for (auto i = 0; i < 9 ; i++)
    digitalWrite(DataPin[i], LOW);
}

void SliceMove()
{
  for (byte i = 0; i < 3; i++)
    digitalWrite(Layer[i], LOW);

  digitalWrite(DataPin[0], HIGH);
  digitalWrite(DataPin[1], HIGH);
  digitalWrite(DataPin[2], HIGH);    //Bad Code since I wrote this really fast for testing
  delay(750);
  digitalWrite(DataPin[0], LOW);
  digitalWrite(DataPin[1], LOW);
  digitalWrite(DataPin[2], LOW);

  digitalWrite(DataPin[3], HIGH);
  digitalWrite(DataPin[4], HIGH);
  digitalWrite(DataPin[5], HIGH);
  delay(750);
  digitalWrite(DataPin[3], LOW);
  digitalWrite(DataPin[4], LOW);
  digitalWrite(DataPin[5], LOW);

  digitalWrite(DataPin[6], HIGH);
  digitalWrite(DataPin[7], HIGH);
  digitalWrite(DataPin[8], HIGH);
  delay(750);
  digitalWrite(DataPin[6], LOW);
  digitalWrite(DataPin[7], LOW);
  digitalWrite(DataPin[8], LOW);

   for (byte i = 0; i < 3; i++)
    digitalWrite(Layer[i], HIGH);
}

void RowMove()
{
   for (byte i = 0; i < 3; i++)
    digitalWrite(Layer[i], LOW);

  digitalWrite(DataPin[0], HIGH);
  digitalWrite(DataPin[3], HIGH);
  digitalWrite(DataPin[6], HIGH);
  delay(750);
  digitalWrite(DataPin[0], LOW);
  digitalWrite(DataPin[3], LOW);
  digitalWrite(DataPin[6], LOW);

  digitalWrite(DataPin[1], HIGH);
  digitalWrite(DataPin[4], HIGH);
  digitalWrite(DataPin[7], HIGH);
  delay(750);
  digitalWrite(DataPin[1], LOW);
  digitalWrite(DataPin[4], LOW);
  digitalWrite(DataPin[7], LOW);

  digitalWrite(DataPin[2], HIGH);
  digitalWrite(DataPin[5], HIGH);
  digitalWrite(DataPin[8], HIGH);
  delay(750);
  digitalWrite(DataPin[2], LOW);
  digitalWrite(DataPin[5], LOW);
  digitalWrite(DataPin[8], LOW);


   for (byte i = 0; i < 3; i++)
    digitalWrite(Layer[i], HIGH);
}
//////////////////////////////////////////////////////////



void loop()
{
  BlinkAll();
  Cycle();
  LayerRise();
  SliceMove();
  RowMove();
  BlinkOff();
}
