# LED Brightness Control using Potentiometer

## Aim

To control the **brightness of an LED using a potentiometer**.

## Components Used

* Arduino Uno
* LED
* Potentiometer
* Resistor
* Breadboard
* Jumper wires

## Pin Connections

* **LED → Digital Pin 11**
* **Potentiometer → Analog Pin A4**

## What is happening?

The potentiometer gives an analog value between **0 and 1023**.

The Arduino reads this value using:

```cpp
int v = analogRead(pot);
```

But `analogWrite()` uses a PWM value between **0 and 255**.

So, we need to convert the potentiometer value from:

**0–1023 → 0–255**

For this, a custom `mymap()` function is used.

## `mymap()` Function

```cpp
float mymap(float value, float inmin, float inmax,
            float outmin, float outmax)
{
  return (value-inmin)*(outmax-outmin) /
         (inmax-inmin) + outmin;
}
```

This function converts a value from one range to another.

Here:

```cpp
float brightness = mymap(v, 0, 1023, 0, 255);
```

So:

* Potentiometer = **0** → Brightness = **0**
* Potentiometer ≈ **512** → Brightness ≈ **127**
* Potentiometer = **1023** → Brightness = **255**

## How PWM controls brightness?

Pin 11 supports PWM.

`analogWrite()` takes a value from **0 to 255**:

* `0` → LED OFF
* `127` → Around 50% PWM
* `255` → Maximum PWM duty cycle

```cpp
analogWrite(led, brightness);
```

Therefore, when the potentiometer is rotated, the LED brightness changes.

## Working Flow

**Potentiometer → analogRead() → 0–1023 → mymap() → 0–255 → PWM → LED Brightness**

## Important Functions

* `analogRead()` → Reads the potentiometer value from **0–1023**.
* `mymap()` → Converts the value from **0–1023 to 0–255**.
* `analogWrite()` → Generates PWM on the LED pin.
* `pinMode()` → Sets the pin as INPUT or OUTPUT.

## Output

Rotating the potentiometer changes the LED brightness.

**Potentiometer low → LED dim/off**

**Potentiometer high → LED bright**
