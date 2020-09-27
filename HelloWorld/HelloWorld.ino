void setup()
{
  Serial.begin(9600);
	Serial.println("Hello world!");
}

int count = 0;

void loop()
{
  count++;
  Serial.print("Hello again x");
  Serial.print(count);
  Serial.println("!");
  delay(100);
}
