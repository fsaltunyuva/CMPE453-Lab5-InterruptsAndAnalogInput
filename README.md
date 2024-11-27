# CMPE453 Embedded Systems

## Lab 5 - Interrupts and Analog Input

In this lab, you will use

![Figure 1](placeholder.png)

1) Connect Arduino Base Shield to Arduino Uno.
2) Grove Button should be connected to any digital interface of base shield.
3) Grove LCD Screen communicates with Arduino Uno via I2C.
4) Grove Light Sensor should be connected to an Analog Input.
5) Grove Buzzer should connected to digital interface.

> [!TIP]
> [Code snippet for the Grove LCD](https://wiki.seeedstudio.com/Grove-LCD_RGB_Backlight/), [code snippet for the Grove Button](https://wiki.seeedstudio.com/Grove-Button/), [code snippet for the Grove Buzzer](https://wiki.seeedstudio.com/Grove-Buzzer/), and [code snippet for the Grove Light Sensor](https://wiki.seeedstudio.com/Grove-Light_Sensor/) can be useful.

Program	the	microcontroller	by using C programming on Arduino IDE. When	your program runs, it should do	the	following task.

1) Display the light sensor value on LCD. When the day light is change on the light sensor your light sensor value should be change	and	so the numbers should be change	on the LCD according to	light sensor.

2) When	the	button is pressed, an interrupt	is sent	to AVR which makes the buzzer rings	for	2 seconds. As button is	released or	not, the microcontroller will	
continue doing (I) after delay.