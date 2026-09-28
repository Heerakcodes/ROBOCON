# DC Motor Speed Control using Potentiometer

## Aim

To control the speed of a DC motor using a potentiometer and a motor driver.

## Components Used

* Arduino Uno
* DC Motor
* Motor Driver
* Potentiometer
* Battery / Power Supply
* Jumper wires

## Pin Connections

### Motor Driver

* **EN1 → Pin 3**
* **IN1 → Pin 2**
* **IN2 → Pin 4**

### Potentiometer

* **Potentiometer → A0**

## What is happening?

The Arduino controls the DC motor through a motor driver.

The two direction pins are set as:

```cpp id="e3u9c1"
digitalWrite(in1, HIGH);
digitalWrite(in2, LOW);
```

This makes the motor rotate in **one direction**.

The potentiometer is then read using:

```cpp id="0s7x0g"
int v = analogRead(pot);
```

The Arduino gets a potentiometer value between:

**0 → 1023**

But the Arduino's PWM output uses:

**0 → 255**

Therefore, `map()` is used to convert the potentiometer value:

```cpp id="cm3r2k"
map(v, 0, 1023, 0, 255)
```

The converted value is then sent to the motor driver's enable pin:

```cpp id="w4t5r6"
analogWrite(en1, map(v, 0, 1023, 0, 255));
```

This controls the PWM duty cycle and therefore controls the **motor speed**.

## How the Speed Changes

| Potentiometer | PWM Value | Motor        |
| ------------- | --------: | ------------ |
| Minimum       |         0 | OFF          |
| Around middle |      ~127 | Medium speed |
| Maximum       |       255 | Maximum PWM  |

So:

**Turn potentiometer → Arduino reads value → `map()` converts 0–1023 to 0–255 → PWM sent to EN1 → Motor speed changes**

## Why do we use `map()`?

The potentiometer and PWM use different ranges.

* `analogRead()` → **0–1023**
* `analogWrite()` → **0–255**

So we convert:

**0–1023 → 0–255**

This makes the potentiometer position directly control the PWM value.

## Direction Control

The direction is fixed because:

```cpp
in1 = HIGH
in2 = LOW
```

If the two values were reversed:

```cpp
in1 = LOW
in2 = HIGH
```

the motor would rotate in the **opposite direction**.

## Working Flow

**Potentiometer → analogRead() → 0–1023 → map() → 0–255 PWM → Motor Driver EN1 → DC Motor Speed**

## Important Functions

* `analogRead()` → Reads the potentiometer value from 0–1023.
* `map()` → Converts the value from 0–1023 to 0–255.
* `analogWrite()` → Generates PWM output.
* `digitalWrite()` → Sets the motor direction.
