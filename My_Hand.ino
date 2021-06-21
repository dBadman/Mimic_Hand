#include <Servo.h>

Servo servo_thumb;
Servo servo_index;   //initialize servo object for connected servo
Servo servo_middle;
Servo servo_ring;
Servo servo_pinky;
Servo servo_wrist;

int counter = 0;
int reverse = 0;
int max_angle = 150;
int min_angle = 30;
int angle_range = max_angle - min_angle;
int angle_step = 2;
int angle_delay = 5;
int angle = min_angle;
int Run = true;

int pinky_max = 0;
int ring_max = 0;
int middle_max = 0;
int index_max = 0;
int thumb_max = 0;

int pinky_min = 600;
int ring_min = 600;
int middle_min = 600;
int index_min = 600;
int thumb_min = 600;

int pinky_ave = (pinky_min+pinky_max)/2;
int ring_ave = (ring_min+ring_max)/2;
int middle_ave = (middle_min+middle_max)/2;
int index_ave = (index_min+index_max)/2;
int thumb_ave = (thumb_min+thumb_max)/2;

int pinky_conv = (pinky_max - pinky_min)/(angle_range);
int ring_conv = (ring_max - ring_min)/(angle_range);
int middle_conv = (middle_max - middle_min)/(angle_range);
int index_conv = (index_max - index_min)/(angle_range);
int thumb_conv = (thumb_max - thumb_min)/(angle_range);

int p;
int r;
int m;
int i;
int t;

int pinky_in = 0;
int ring_in = 1;
int middle_in = 2;
int index_in = 3;
int thumb_in = 4;

int pinky_flex = 0;
int ring_flex = 0;
int middle_flex = 0;
int index_flex = 0;
int thumb_flex = 0;

void setup() 
{

int thumb = 3;
int index = 5;
int middle = 6;
int ring = 9;
int pinky = 10;
int wrist = 11;

servo_thumb.attach(thumb);   //attach signal pin of servo
servo_index.attach(index);   //attach signal pin of servo
servo_middle.attach(middle);   //attach signal pin of servo
servo_ring.attach(ring);   //attach signal pin of servo
servo_pinky.attach(pinky);   //attach signal pin of servo
servo_wrist.attach(wrist);   //attach signal pin of servo

Serial.begin(115200);

}

void loop() 
{
  while (Run)
  {
    if (Serial.available() )
    {
      char userData = Serial.read();
      Serial.println((char)userData);
      switch ((char)userData) 
      {
      case 'T':
        if (angle > min_angle - 1 && reverse == 1)
          {
            servo_thumb.write(angle);
            angle--;
            delay(angle_delay);
            if (angle == min_angle)
              reverse = 0;
          }
        else if (angle < max_angle + 1 && reverse == 0)
          {
            servo_thumb.write(angle);
            angle++;
            delay(angle_delay); 
            if (angle == max_angle)
              reverse = 1;
          }
        break;

      case 'I':
        if (angle > min_angle - 1 && reverse == 1)
          {
            servo_index.write(angle);
            angle--;
            delay(angle_delay);
            if (angle == min_angle)
              reverse = 0;
          }
        else if (angle < max_angle + 1 && reverse == 0)
          {
            servo_index.write(angle);
            angle++;
            delay(angle_delay);  
            if (angle == max_angle)
              reverse = 1;
          }
        break;

      case 'M':
        if (angle > min_angle - 1 && reverse == 1)
          {
            servo_middle.write(angle);
            angle--;
            delay(angle_delay);
            if (angle == min_angle)
              reverse = 0;
          }
        else if (angle < max_angle + 1 && reverse == 0)
          {
            servo_middle.write(angle);
            angle++;
            delay(angle_delay);  
            if (angle == max_angle)
              reverse = 1;
          }
        break;

      case 'R':
        if (angle > min_angle - 1 && reverse == 1)
          {
            servo_ring.write(angle);
            angle--;
            delay(angle_delay);
            if (angle == min_angle)
              reverse = 0;
          }
        else if (angle < max_angle + 1 && reverse == 0)
          {
            servo_ring.write(angle);
            angle++;
            delay(angle_delay);  
            if (angle == max_angle)
              reverse = 1;
          }
        break;

      case 'P':
        if (angle > min_angle - 1 && reverse == 1)
          {
            servo_pinky.write(angle);
            angle--;
            delay(angle_delay);
            if (angle == min_angle)
              reverse = 0;
          }
        else if (angle < max_angle + 1 && reverse == 0)
          {
            servo_pinky.write(angle);
            angle++;
            delay(angle_delay);  
            if (angle == max_angle)
              reverse = 1;
          }
        break;

      case 'W':
        if (angle > min_angle - 1 && reverse == 1)
          {
            servo_wrist.write(angle);
            angle--;
            delay(angle_delay);
            if (angle == min_angle)
              reverse = 0;
          }
        else if (angle < max_angle + 1 && reverse == 0)
          {
            servo_wrist.write(angle);
            angle++;
            delay(angle_delay);  
            if (angle == max_angle)
              reverse = 1;
          }
        break;

      case 'C':
        servo_thumb.write(90);    //command to rotate servo to specified angle
        delay(1000);
        servo_index.write(90);    //command to rotate servo to specified angle
        delay(1000);
        servo_middle.write(90);    //command to rotate servo to specified angle
        delay(1000);
        servo_ring.write(90);    //command to rotate servo to specified angle
        delay(1000);
        servo_pinky.write(90);    //command to rotate servo to specified angle
        delay(1000);
        servo_wrist.write(90);    //command to rotate servo to specified angle
        delay(1000);
        break;

      case 'S':
        Serial.println("Opa!");
        delay(1000);
        Run = false;
        break;    
      }
    }

    counter++;
    
    pinky_flex = analogRead(pinky_in);
    ring_flex = analogRead(ring_in);
    middle_flex = analogRead(middle_in);
    index_flex = analogRead(index_in);
    thumb_flex = analogRead(thumb_in);

    if (pinky_flex > pinky_max){
        pinky_max = pinky_flex;
    }
    else if (pinky_flex < pinky_min){
        pinky_min = pinky_flex;
    }
    if (index_flex > index_max){
        index_max = index_flex;
    }
    else if (index_flex < index_min){
        index_min = index_flex;
    }
    if (middle_flex > middle_max){
        middle_max = middle_flex;
    }
    else if (middle_flex < middle_min){
        middle_min = middle_flex;
    }
    if (ring_flex > ring_max){
        ring_max = ring_flex;
    }
    else if (ring_flex < ring_min){
        ring_min = ring_flex;
    }
    if (thumb_flex > thumb_max){
        thumb_max = thumb_flex;
    }
    else if (thumb_flex < thumb_min){
        thumb_min = thumb_flex;
    }
    
    if (counter >= 10000) {
        Serial.print("Pinky Min: ");
        Serial.println(pinky_min);
        Serial.print("Ring Min: ");
        Serial.println(ring_min);
        Serial.print("Middle Min: ");
        Serial.println(middle_min);
        Serial.print("Index Min: ");
        Serial.println(index_min);
        Serial.print("Thumb Min: ");
        Serial.println(thumb_min);

        Serial.print("Pinky Max: ");
        Serial.println(pinky_max);
        Serial.print("Ring Max: ");
        Serial.println(ring_max);
        Serial.print("Middle Max: ");
        Serial.println(middle_max);
        Serial.print("Index Max: ");
        Serial.println(index_max);
        Serial.print("Thumb Max: ");
        Serial.println(thumb_max);
    } 
  }
}
