/*Settings*/


/*Sensor settings*/

    /*Trigger PIN*/
    #define TRIG 1

    /*Echo PIN*/
    #define ECHO 2

    /*Trigger Time (µS)*/
    /*Duration off the HIGH Signal to trigger the sensor*/
    #define TRIG_TIME 15

    /*FACTOR from Time to Distance*/
    /*this value may depend on the sensor*/
    #define CalculationFactor 52


/*General settings*/

    /*Output Unit*/
    /*mm,cm,dm or m*/
    #define UNIT "mm"

    /*Define witch Tank is used for the sensor*/
    /*Selection: North, East, South, West*/
    #define TANK_DIRECTION "North"

    /*TankNumber alternate way to name the tanks*/
    #define TANK_NUMBER "1"


/*WiFi settings*/

    #define SSID "SSID"
    #define PASSWORD "PASSWORD"
    #define HOSTNAME "LIR_Tank"

    /*define if the hostname should end with the direction and Number of the tank*/
    #define HOSTNAME_TANK_DEFINITION true

    
    

/*MQTT settings*/

    /*Broker Address*/
    #define BROKER_ADDR "smarthome.705marc.home"
    #define BROKER_PORT 1883


    /*Topic to send the state*/
    /*you can add as many as needed*/
    #ifdef TANK_DIRECTION "North"
    	#define Topic "/home/room/garden/sensor/level/tankNorth/state"
    #elif TANK_DIRECTION "South"
        #define Topic "/home/room/garden/sensor/level/tankSouth/state"
    #elif TANK_NUMBER "1"
    	#define Topic "/home/room/garden/sensor/level/tankNorth/state"
    #elif TANK_NUMBER "2"
        #define Topic "/home/room/garden/sensor/level/tankSouth/state"
    #endif

