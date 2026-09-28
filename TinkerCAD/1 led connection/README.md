# LED Blinking using Arduino

## Aim

To make an LED blink using an Arduino Uno.

## Components Used

* Arduino Uno
* LED
* Resistor
* Jumper wires
* Breadboard

## What is happening?

In this program, an LED is connected to **digital pin 7** of the Arduino.

First, we set pin 7 as an **OUTPUT** in the `setup()` function.

```cpp
pinMode(led, OUTPUT);
```

Then inside the `loop()` function:

```cpp
digitalWrite(7, HIGH);
```

This turns the LED **ON**.

```cpp
delay(1000);
```

The Arduino waits for **1000 milliseconds = 1 second**.

Then:

```cpp
digitalWrite(7, LOW);
```

This turns the LED **OFF**.

Again, the Arduino waits for **1 second**.

After that, the `loop()` starts again. So the LED keeps turning ON and OFF continuously.

## Working Flow

**Pin 7 HIGH → LED ON → Wait 1 sec → Pin 7 LOW → LED OFF → Wait 1 sec → Repeat**

## Important Functions

* `pinMode()` → Sets a pin as INPUT or OUTPUT.
* `digitalWrite()` → Gives HIGH or LOW to a digital pin.
* `delay()` → Stops the program for a given time.

## Output

The LED will:

**ON for 1 second → OFF for 1 second → ON for 1 second → OFF for 1 second...**

So, the LED keeps blinking continuously.
