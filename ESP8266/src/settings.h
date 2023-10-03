/*Settings*/


/*Sensor settings*/

    /*Trigger PIN*/
    #define TRIG 4

    /*Echo PIN*/
    #define ECHO 5

    /*Trigger Time (mS)*/
    /*Duration off the HIGH Signal to trigger the sensor*/
    #define TRIG_TIME 5

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

    /*SleepTime in Minutes*/
    #define SLEEP_TIME 20



/*WiFi settings*/

    #define SSID "SSID"
    #define PASSWORD "PASSWORD"


    
    

/*MQTT settings*/

    /*Broker Address*/
    #define BROKER_ADDR "BROKER ADDRESS"
    #define BROKER_PORT 1883

    #define TOPIC "/home/room/garden/sensor/level/tankSouth/state"

