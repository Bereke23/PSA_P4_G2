#include <Servo.h>          //Servo motor library. This is standard library
 #include <NewPing.h>        //Ultrasonic sensor function library. You must install this library

 #define LeftMotorForward 7
 #define LeftMotorBackward 8
 #define RightMotorForward 4
 #define RightMotorBackward 2 

 #define ENA_m1 3
 #define ENB_m1 5

 //sensor pins
 #define trig_pin A1 //analog input 1
 #define echo_pin A2 //analog input 2
 
 #define IR_LEFT A0
 #define IR_RIGHT A3
 #define maximum_distance 200

 int valueENA_m1=100; // speed motor 1 
 int valueENB_m1=100; // speed motor 2

 int valueWhite = 100; //valor do sensor IR para a cor branca

 boolean goesForward = false;
 int distance = 100;

 int angulo_servo = 0;
