// RemoteXY select connection mode and include library 
#define REMOTEXY_MODE__ESP8266_HARDSERIAL_POINT

#include <RemoteXY.h>

// RemoteXY connection settings 
#define REMOTEXY_SERIAL Serial
#define REMOTEXY_SERIAL_SPEED 115200
#define REMOTEXY_WIFI_SSID "WiFi RoBot"
#define REMOTEXY_WIFI_PASSWORD "123456789"
#define REMOTEXY_SERVER_PORT 6377
#define REMOTEXY_ACCESS_PASSWORD "123456789"


// RemoteXY configurate  
#pragma pack(push, 1)
uint8_t RemoteXY_CONF[] =
  { 255,2,0,0,0,12,0,10,13,0,
  5,54,35,21,30,30,2,26,31 };
  
// this structure defines all the variables and events of your control interface 
struct {

    // input variables
  int8_t joystick_1_x; // =-100..100 x-coordinate joystick position 
  int8_t joystick_1_y; // =-100..100 y-coordinate joystick position 

    // other variable
  uint8_t connect_flag;  // =1 if wire connected, else =0 

} RemoteXY;
#pragma pack(pop)

/////////////////////////////////////////////
//           END RemoteXY include          //
/////////////////////////////////////////////

//define MOTOR Controlling pins
#define robot_LEFT_motor1 4
#define robot_LEFT_motor2 5
#define LEFT_motor_speed 10

//define RIGHT Motor pins
#define robot_RIGHT_motor1 6
#define robot_RIGHT_motor2 7
#define RIGHT_motor_speed 11

//define two arrays with list of pins each other

uint8_t Right_Motor[3] = {robot_RIGHT_motor1,robot_RIGHT_motor2,RIGHT_motor_speed};
uint8_t LEFT_Motor [3]= {robot_LEFT_motor1,robot_LEFT_motor2,LEFT_motor_speed };

//Speed control of motors
void Wheel (uint8_t * motor,int v)// v=motor speed control=pointer to an array of pins
{
  if (v > 100) v=100;
  if (v <-100) v=100;
  if (v > 0)
  {
    digitalWrite (motor [0],HIGH);
    digitalWrite (motor [1],LOW);
    analogWrite (motor [2],v * 2.55);
    
  }
  else if(v<0)
  {
    digitalWrite (motor [0],LOW);
    digitalWrite (motor [1],HIGH);
    analogWrite (motor [2], (-v) * 2.55);
    
    
  }
else
{
   digitalWrite (motor [0],LOW);
    digitalWrite (motor [1],LOW);
    analogWrite (motor [2],0);
    
}
}

void setup() 
{
  RemoteXY_Init (); 
  
//initialization pins
pinMode (robot_LEFT_motor1,OUTPUT);
pinMode (robot_LEFT_motor2,OUTPUT);
pinMode (robot_RIGHT_motor1,OUTPUT);
pinMode (robot_RIGHT_motor2,OUTPUT);
  
  // TODO you setup code
  
}

void loop() 
{ 
  RemoteXY_Handler ();
  
  
//manage the motor
 Wheel (Right_Motor, RemoteXY.joystick_1_y - RemoteXY.joystick_1_x);
 Wheel (LEFT_Motor, RemoteXY.joystick_1_y + RemoteXY.joystick_1_x);

}
