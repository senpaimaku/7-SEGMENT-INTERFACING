#include <Arduino.h>


#define DP1 12
#define DP2 13

int num = 0;

int pins[] = { 2, 3, 4, 5, 6, 7, 8 };
int numbers[10][7] = {
//  A  B  C  D  E  F  G
  { 1, 1, 1, 1, 1, 1, 0 },
  { 0, 1, 1, 0, 0, 0, 0 },
  { 1, 1, 0, 1, 1, 0, 1 },
  { 1, 1, 1, 1, 0, 0, 1 },
  { 0, 1, 1, 0, 0, 1, 1 },
  { 1, 0, 1, 1, 0, 1, 1 },
  { 1, 0, 1, 1, 1, 1, 1 },
  { 1, 1, 1, 0, 0, 0, 0 },
  { 1, 1, 1, 1, 1, 1, 1 },
  { 1, 1, 1, 1, 0, 1, 1 },
}; 

void setup() {
  for (int i = 0; i <= 6; i++) {
    pinMode(pins[i], OUTPUT);
  }

  pinMode(DP1, OUTPUT);
  pinMode(DP2, OUTPUT);
  Serial.begin(9600);

}

void test(int g, int b) {
  digitalWrite(DP1, 0);
  digitalWrite(DP2, 1);
  delay(10);

  for (int i = 0; i <= 6; i++) {
    digitalWrite(pins[i], numbers[g][i]);
  }
    
  digitalWrite(DP1, 1);
  digitalWrite(DP2, 0);
  delay(10);
  for (int i = 0; i <= 6; i++) {
    digitalWrite(pins[i], numbers[b][i]);
  }
    
}

void loop() {
  
  num++;

  if (num == 99) {
    num = 0;
  }

  int a = num;
  int tens = a / 10;
  int ones = a % 10;


  for (int i = 0; i <= 50; i++) {
    test(tens, ones);
    Serial.println(num);
  }
}
