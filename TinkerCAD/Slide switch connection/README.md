# LED Blinking using Arduino

## Aim

To make an LED blink continuously using an Arduino Uno.

## Components Used

* Arduino Uno
* LED
* Resistor
* Breadboard
* Jumper wires

## Pin Connection

* **LED → Digital Pin 7**

## What is happening?

The LED is connected to **digital pin 7**.

In the `setup()` function, pin 7 is set as an output:

```cpp
pinMode(7, OUTPUT);
```

Inside the `loop()` function, the Arduino continuously turns the LED ON and OFF.

First:

```cpp
digitalWrite(7, HIGH);
```

`HIGH` turns the LED **ON**.

Then:

```cpp
delay(1000);
```

The Arduino waits for **1000 milliseconds (1 second)**.

After that:

```cpp
digitalWrite(7, LOW);
```

`LOW` turns the LED **OFF**.

The Arduino waits another 1 second:

```cpp
delay(1000);
```

Then the `loop()` starts again.

## Working Flow

**Pin 7 HIGH → LED ON → Wait 1 sec → Pin 7 LOW → LED OFF → Wait 1 sec → Repeat**

## Important Functions

* `pinMode()` → Sets the pin as INPUT or OUTPUT.
* `digitalWrite()` → Gives HIGH or LOW to the pin.
* `delay()` → Waits for the specified time in milliseconds.

## Output

The LED continuously blinks:

**ON for 1 second → OFF for 1 second → ON for 1 second → OFF for 1 second...**
