

//////////////////////////////////////////////
//        RemoteXY include library          //
//////////////////////////////////////////////

// RemoteXY select connection mode and include library 
#define REMOTEXY_MODE__ESP8266WIFI_LIB_POINT
#include <ESP8266WiFi.h>

#include <RemoteXY.h>

// RemoteXY connection settings 
#define REMOTEXY_WIFI_SSID "WTC"
#define REMOTEXY_WIFI_PASSWORD "12345678"
#define REMOTEXY_SERVER_PORT 6377


// RemoteXY configurate  
#pragma pack(push, 1)
uint8_t RemoteXY_CONF[] =
  { 255,8,0,0,0,152,0,13,13,1,
  1,0,9,44,12,12,2,31,88,0,
  1,0,45,42,12,12,2,31,88,0,
  2,0,36,22,22,11,2,26,31,31,
  79,78,0,79,70,70,0,129,0,10,
  24,18,6,17,99,117,116,116,101,114,
  0,129,0,7,36,18,6,17,111,112,
  101,110,0,129,0,43,36,18,6,17,
  99,108,111,115,101,0,2,0,36,5,
  22,11,2,26,31,31,79,78,0,79,
  70,70,0,129,0,5,7,18,6,17,
  99,111,110,118,101,121,111,114,0,1,
  0,29,54,12,12,2,31,70,0,1,
  0,9,69,12,12,2,31,76,0,1,
  0,45,70,12,12,2,31,82,0,1,
  0,27,87,12,12,2,31,66,0 };
// this structure defines all the variables and events of your control interface 
struct {

    // input variables
  uint8_t switch_1; // =1 if switch ON and =0 if OFF 
  uint8_t switch_2; // =1 if switch ON and =0 if OFF
  uint8_t button_1; // =1 if button pressed, else =0 
  uint8_t button_2; // =1 if button pressed, else =0 
  uint8_t button_3; // =1 if button pressed, else =0 
  uint8_t button_4; // =1 if button pressed, else =0 
  uint8_t button_5; // =1 if button pressed, else =0 
  uint8_t button_6; // =1 if button pressed, else =0 

    // other variable
  uint8_t connect_flag;  // =1 if wire connected, else =0 

} RemoteXY;
#pragma pack(pop)

/////////////////////////////////////////////
//           END RemoteXY include          //
/////////////////////////////////////////////


#define IN_3  2     /* GPIO2(D4) -> IN3   */
#define IN_1  15   /* GPIO15(D8) -> IN1  */
#define IN_4  0    /* GPIO0(D3) -> IN4   */
#define IN_2 13 /* GPIO13(D7) -> IN2  */
#define ENA 14          /*Enable/speed motors Right   GPIO14(D5)*/      
#define ENB   12          /* Enable/speed motors Left GPIO12(D6)*/


void setup() 
{
  RemoteXY_Init (); 
  
  
  pinMode (IN_1, OUTPUT);
  pinMode (IN_2, OUTPUT);
  pinMode (IN_3 , OUTPUT);
  pinMode (IN_4, OUTPUT);
  
  // TODO you setup code
  
}

void loop() 
{ 
  RemoteXY_Handler ();
  



  if (RemoteXY.button_3 == HIGH){        //forward
       digitalWrite(IN_1, LOW);
      digitalWrite(IN_2, HIGH);
      analogWrite(ENA, 255);

      digitalWrite(IN_3, LOW);
      digitalWrite(IN_4, HIGH);
      analogWrite(ENB, 255);
      }
  else if (RemoteXY.button_6 == HIGH){       //backward
       digitalWrite(IN_1, HIGH);
      digitalWrite(IN_2, LOW);
      analogWrite(ENA, 255);

      digitalWrite(IN_3, HIGH);
      digitalWrite(IN_4, LOW);
      analogWrite(ENB, 255);
      }
  else if (RemoteXY.button_5 == HIGH){        //turn left
     digitalWrite(IN_1, LOW);
      digitalWrite(IN_2, HIGH);
      analogWrite(ENA, 255);

      digitalWrite(IN_3, HIGH);
      digitalWrite(IN_4, LOW);
      analogWrite(ENB, 255);
      }
  else if (RemoteXY.button_4 == HIGH){            //turn right
      digitalWrite(IN_1, HIGH);
      digitalWrite(IN_2, LOW);
      analogWrite(ENA, 255);

      digitalWrite(IN_3, LOW);
      digitalWrite(IN_4, HIGH);
      analogWrite(ENB, 255);
      }
  else {
        digitalWrite(IN_1, LOW);
      digitalWrite(IN_2, LOW);
      analogWrite(ENA, 0);

      digitalWrite(IN_3, LOW);
      digitalWrite(IN_4, LOW);
      analogWrite(ENB, 0);
       }    
      
  
  // TODO you loop code
  // use the RemoteXY structure for data transfer
  // do not call delay() 


}
