# LED Control using Potentiometer as Digital Input

## Aim

To control an LED using the digital value read from a potentiometer.

## Components Used

* Arduino Uno
* Potentiometer
* LED
* Resistor
* Jumper wires
* Breadboard

## Pin Connections

* **LED → Pin 2**
* **Potentiometer → Pin 6**

## What is happening?

In this program, the potentiometer is connected to **digital pin 6** instead of an analog pin.

The pin is configured as an input:

```cpp
pinMode(pmeter, INPUT);
```

The Arduino reads the digital state of the pin using:

```cpp
int p = digitalRead(pmeter);
```

`digitalRead()` gives only two possible values:

* `HIGH` → `1`
* `LOW` → `0`

The value read from the potentiometer is then directly given to the LED:

```cpp
digitalWrite(led, p);
```

Therefore:

* If `p = 1` → LED turns **ON**
* If `p = 0` → LED turns **OFF**

## Important Point

This program is treating the potentiometer connection as a **digital input**, so it is not reading the potentiometer's actual analog value from `0–1023`.

For reading the actual potentiometer position, an **analog pin** such as `A0` would normally be used with:

```cpp
analogRead(A0);
```

But in this program, the idea is simply to read the input as **HIGH or LOW**.

## Working Flow

**Digital Input → `digitalRead()` → HIGH/LOW → `digitalWrite()` → LED ON/OFF**

## Important Functions

* `pinMode()` → Sets the pin as INPUT or OUTPUT.
* `digitalRead()` → Reads HIGH or LOW from the input pin.
* `digitalWrite()` → Turns the LED ON or OFF.

## Output

The LED follows the digital state of the input:

**HIGH → LED ON**

**LOW → LED OFF**
