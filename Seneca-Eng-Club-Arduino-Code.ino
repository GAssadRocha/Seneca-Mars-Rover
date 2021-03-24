//Dabble documentation:
//https://thestempedia.com/docs/dabble/getting-started-with-dabble/


/////////////////////////////////////////////////////////////////////////////////////////////
//MODULES
/////////////////////////////////////////////////////////////////////////////////////////////

// Dabble definitions and modules

#define CUSTOM_SETTINGS
#define INCLUDE_GAMEPAD_MODULE
#include <DabbleESP32.h>

/////////////////////////////////////////////////////////////////////////////////////////////
//DC Motor pin - Total 18                                                       (incomplete)
/////////////////////////////////////////////////////////////////////////////////////////////

//DC - Motor 1
const int dc_motor1_digital_pin1 = 1; 
const int dc_motor1_digital_pin2 = 2; 
const int dc_motor1_PWM_pin = 3; 

//DC - Motor 2
const int dc_motor2_digital_pin1 = 4; 
const int dc_motor2_digital_pin2 = 5; 
const int dc_motor2_PWM_pin = 6; 

//DC - Motor 3
// const int dc_motor3_digital_pin1 = 4; 
// const int dc_motor3_digital_pin2 = 5; 
// const int dc_motor3_PWM_pin = 6; 

//DC - Motor 4
// const int dc_motor4_digital_pin1 = 4; 
// const int dc_motor4_digital_pin2 = 5; 
// const int dc_motor4_PWM_pin = 6; 

//DC - Motor 5
// const int dc_motor5_digital_pin1 = 4; 
// const int dc_motor5_digital_pin2 = 5; 
// const int dc_motor5_PWM_pin = 6; 

//DC - Motor 6
// const int dc_motor6_digital_pin1 = 4; 
// const int dc_motor6_digital_pin2 = 5; 
// const int dc_motor6_PWM_pin = 6; 

/////////////////////////////////////////////////////////////////////////////////////////////
//Step Motor pin (incomplete)
/////////////////////////////////////////////////////////////////////////////////////////////

const int step_motor_1_pin = 7; 
const int step_motor_2_pin = 8; 
const int step_motor_3_pin = 9; 
const int step_motor_4_pin = 10; 
const int step_motor_5_pin = 11; 
const int step_motor_6_pin = 12; 


/////////////////////////////////////////////////////////////////////////////////////////////
//GLOBAL variables
/////////////////////////////////////////////////////////////////////////////////////////////
unsigned int power_of_wheel = 100;
int angle_of_wheel = 0;

/////////////////////////////////////////////////////////////////////////////////////////////
//FUNCTION Definitions
/////////////////////////////////////////////////////////////////////////////////////////////

// (Incomplete)
void Turn_on_wheel(int number_of_wheel, char direction = "CW", int power = 100){
    //power value between 0 and 100
    //direction - CW (Clock Wise) or CCW (Counter Clock Wide)
    //number_of_wheel - between 1 and 6

    int digital_pin1;
    int digital_pin2;
    int PWM_pin;

   
    switch (number_of_wheel)
    {
    case 1:
      digital_pin1 = dc_motor1_digital_pin1;
      digital_pin2 = dc_motor1_digital_pin2;
      PWM_pin = dc_motor1_PWM_pin; 
      break;
    
    case 2:
      digital_pin1 = dc_motor2_digital_pin1;
      digital_pin2 = dc_motor2_digital_pin2;
      PWM_pin = dc_motor2_PWM_pin; 
      break;  
    
    case 3:
      digital_pin1 = dc_motor3_digital_pin1;
      digital_pin2 = dc_motor3_digital_pin2;
      PWM_pin = dc_motor3_PWM_pin; 
      break;  
    
    case 4:
      digital_pin1 = dc_motor4_digital_pin1;
      digital_pin2 = dc_motor4_digital_pin2;
      PWM_pin = dc_motor4_PWM_pin; 
      break;  
    
    case 5:
      digital_pin1 = dc_motor5_digital_pin1;
      digital_pin2 = dc_motor5_digital_pin2;
      PWM_pin = dc_motor5_PWM_pin; 
      break;  
    
    case 6:
      digital_pin1 = dc_motor6_digital_pin1;
      digital_pin2 = dc_motor6_digital_pin2;
      PWM_pin = dc_motor6_PWM_pin; 
      break;
    
    default:
      Serial.print("Please specify the number of the wheel to be used");
      break;
    }

    // if (direction == "CW"){
    // analogWrite(PWM_pin, (int)power/100*255);
    // digitalWrite(digital_pin1, HIGH);
    // digitalWrite(digital_pin2, LOW);
    // }

    // if else (direction == "CCW"){
    //   analogWrite(PWM_pin, (int)power/100*255);
    //   digitalWrite(digital_pin1, LOW);
    //   digitalWrite(digital_pin2, HIGH);
    // }

    
  }

// (Incomplete)
void Turn_off_wheel(int number_of_wheel){
    
  int pin_to_be_used;
  
  switch (number_of_wheel)
  {
  case 1:
    pin_to_be_used = dc_motor1_digital_pin1;
    break;
  
  case 2:
    pin_to_be_used = dc_motor1_digital_pin2;
    break;  
  
  case 3:
    pin_to_be_used = dc_motor1_PWM_pin;
    break;  
  
  case 4:
    pin_to_be_used = dc_motor_4_pin;
    break;  
  
  case 5:
    pin_to_be_used = dc_motor_5_pin; 
    break;  
  
  case 6:
    pin_to_be_used = dc_motor_6_pin;
    break;
  
  default:
    Serial.print("Please specify the number of the wheel to be turned off");
    break;
  }

  analogWrite(pin_to_be_used, 0);
}

// (Incomplete)
void Change_angle_wheel(int number_of_wheel, int angle){
  //This function will make a specific step motor, turn to a specific angle between -90 and 90 degrees.

  int pin_to_be_used;
    
  switch (number_of_wheel)
  {
  case 1:
    pin_to_be_used = step_motor_1_pin;
    break;
  
  case 2:
    pin_to_be_used = step_motor_2_pin;
    break;  
  
  case 3:
    pin_to_be_used = step_motor_3_pin;
    break;  
  
  case 4:
    pin_to_be_used = step_motor_4_pin;
    break;  
  
  case 5:
    pin_to_be_used = step_motor_5_pin;
    break;  
  
  case 6:
    pin_to_be_used = step_motor_6_pin;
    break;
  
  default:
    Serial.print("Please specify the number of the wheel to be used");
    break;
  }

  analogWrite(pin_to_be_used, angle);

}

// (Incomplete)
void Change_angle_wheel_to_0(){
  for(int i = 1 ; i < 7; i++)
  {
    Change_angle_wheel(i, 0);
  }
}

void Turn_off_all_wheels()
{
  for(int i = 1 ; i < 7; i++)
  {
    Turn_off_wheel(i);
  }
}

void Move_Forward(){
  //Makes the robot go forward
  //All motors from the wheels turn. The ones on the right turn CCW, the ones on the left CW. 
  Turn_on_wheel(1, "CW");
  Turn_on_wheel(2, "CW");
  Turn_on_wheel(3, "CW");
  Turn_on_wheel(4, "CCW");
  Turn_on_wheel(5, "CCW");
  Turn_on_wheel(6, "CCW");
}  

void Move_Backward(){
  //all motors from the wheels turn. The ones on the right turn CW, the ones on the left CCW.
  Turn_on_wheel(1, "CCW");
  Turn_on_wheel(2, "CCW");
  Turn_on_wheel(3, "CCW");
  Turn_on_wheel(4, "CW");
  Turn_on_wheel(5, "CW");
  Turn_on_wheel(6, "CW");
} 

void Turn_left_mode1()
{
  for(int i = 1 ; i < 7; i++)
  {
    Turn_on_wheel(i, "CCW");
  }
}

void Turn_right_mode1(){
  for(int i = 1 ; i < 7; i++)
  {
    Turn_on_wheel(i, "CW");
  }
}



void setup() {
  // put your setup code here, to run once:

  //Dabble 
  Serial.begin(115200);       // make sure your Serial Monitor is also set at this baud rate.
  Dabble.begin("Rover10!");   // set bluetooth name of your device

  /////////////////////////////////////////////////////////////////////////////////////////////
  // Motor pin modes (incomplete)
  /////////////////////////////////////////////////////////////////////////////////////////////

  //DC - Motor 1
  pinMode(dc_motor1_digital_pin1, OUTPUT);
  pinMode(dc_motor1_digital_pin2, OUTPUT);
  pinMode(dc_motor1_PWM_pin, OUTPUT);
  
  //DC - Motor 2
  pinMode(dc_motor2_digital_pin1, OUTPUT);
  pinMode(dc_motor2_digital_pin2, OUTPUT);
  pinMode(dc_motor2_PWM_pin, OUTPUT);

  //DC - Motor 3
  pinMode(dc_motor3_digital_pin1, OUTPUT);
  pinMode(dc_motor3_digital_pin2, OUTPUT);
  pinMode(dc_motor3_PWM_pin, OUTPUT);

  //DC - Motor 4
  pinMode(dc_motor4_digital_pin1, OUTPUT);
  pinMode(dc_motor4_digital_pin2, OUTPUT);
  pinMode(dc_motor4_PWM_pin, OUTPUT);

  //DC - Motor 5
  pinMode(dc_motor5_digital_pin1, OUTPUT);
  pinMode(dc_motor5_digital_pin2, OUTPUT);
  pinMode(dc_motor5_PWM_pin, OUTPUT);

  //DC - Motor 6
  pinMode(dc_motor6_digital_pin1, OUTPUT);
  pinMode(dc_motor6_digital_pin2, OUTPUT);
  pinMode(dc_motor6_PWM_pin, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:

  Dabble.processInput();//This function is used to refresh data obtained from smartphone.
                        //Hence calling this function is mandatory in order to get data properly from your mobile.

  if (GamePad.isUpPressed())
  {
    if(power_of_wheel<100){
      power_of_wheel = power_of_wheel + 5;
    }
    else{
      Serial.print("Max power already");
    }

    Serial.print("Up");
  }

  if (GamePad.isDownPressed())
  {
    if(power_of_wheel>0){
      power_of_wheel = power_of_wheel - 5;
    }
    else{
      Serial.print("Min power already");
    }

    Serial.print("Down");
  }

  if (GamePad.isLeftPressed())
  {
    if(angle_of_wheel>-90 && angle_of_wheel<90)
    {
      angle_of_wheel = angle_of_wheel - 5;
        for(int i = 1 ; i < 7; i++)
        {
          Change_angle_wheel(i, angle_of_wheel);
        }
    }
    else
    {
      Serial.print("Min angle already");
    }
    
    Serial.print("Left");
  }

  if (GamePad.isRightPressed())
  {
    if(angle_of_wheel>-90 && angle_of_wheel<90)
    {
      angle_of_wheel = angle_of_wheel + 5;
      for(int i = 1 ; i < 7; i++)
        {
          Change_angle_wheel(i, angle_of_wheel);
        }
    }
    else
    {
      Serial.print("Min angle already");
    }
    Serial.print("Right");
  }

  if (GamePad.isSquarePressed())
  {
    Turn_left_mode1();
    Serial.print("Square");
  }

  if (GamePad.isCirclePressed())
  {
    Turn_right_mode1();
    Serial.print("Circle");
  }

  if (GamePad.isCrossPressed())
  {
    Move_Forward();
    Serial.print("Cross");
  }

  if (GamePad.isTrianglePressed())
  {
    Move_Forward();
    Serial.print("Triangle");
  }

  if (GamePad.isStartPressed())
  {
    Serial.print("Start");
  }

  if (GamePad.isSelectPressed())
  {
    Serial.print("Select");
  }
  else{
    Turn_off_all_wheels();
  }
  Serial.print('\t');

  //This function returns the angle value between the x-axis and the line joining the dot and the center of the joystick.
  //The value varies form 0 to 360 degrees with a step of 15 degrees.
  int a = GamePad.getAngle();
  Serial.print("Angle: ");
  Serial.print(a);
  Serial.print('\t');

  //The function returns the distance between the center of the joystick and the dot.	The value varies from 0 to 7.
  int b = GamePad.getRadius();
  Serial.print("Radius: ");
  Serial.print(b);
  Serial.print('\t');

  //The fuction returns the x postion of the dot on the joystick.	The value varies from -7 to 7.
  float c = GamePad.getXaxisData();
  Serial.print("x_axis: ");
  Serial.print(c);
  Serial.print('\t');

  //The fuction returns the y postion of the dot on the joystick.	The value varies from -7 to 7
  float d = GamePad.getYaxisData();
  Serial.print("y_axis: ");
  Serial.println(d);
  Serial.println();

  

  Serial.print("test");

}
