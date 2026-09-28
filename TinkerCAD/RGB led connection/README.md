# LED Blinking using Arduino

## Aim

To make an LED blink continuously using an Arduino Uno.

## Components Used

* Arduino Uno
* LED
* Resistor
* Jumper wires
* Breadboard

## Pin Connection

* **LED → Digital Pin 7**

## What is happening?

The LED is connected to **digital pin 7** of the Arduino.

First, pin 7 is configured as an output:

```cpp
pinMode(7, OUTPUT);
```

Inside the `loop()`, the Arduino continuously turns the LED ON and OFF.

### LED ON

```cpp
digitalWrite(7, HIGH);
```

`HIGH` gives the pin a HIGH output, so the LED turns **ON**.

Then:

```cpp
delay(1000);
```

The Arduino waits for **1000 milliseconds = 1 second**.

### LED OFF

```cpp
digitalWrite(7, LOW);
```

`LOW` turns the LED **OFF**.

Again, the Arduino waits for **1 second**.

After this, the `loop()` starts again.

## Working

The sequence is:

**LED ON → Wait 1 second → LED OFF → Wait 1 second → Repeat**

Therefore, the LED keeps blinking continuously.

## Important Functions

* `pinMode()` → Sets the pin as OUTPUT.
* `digitalWrite()` → Turns the LED ON or OFF.
* `delay()` → Creates a delay in milliseconds.

## Output

The LED continuously:

**Turns ON for 1 second → Turns OFF for 1 second → Repeats**
