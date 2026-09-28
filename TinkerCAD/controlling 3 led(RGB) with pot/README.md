# Potentiometer Based Traffic Light

## Aim

To control three LEDs using a potentiometer. The potentiometer value is divided into three ranges, which control the **green, yellow, and red LEDs**.

## Components Used

* Arduino Uno
* Potentiometer
* Green LED
* Yellow LED
* Red LED
* Resistors
* Breadboard
* Jumper wires

## Pin Connections

* **Green LED → Pin 3**
* **Yellow LED → Pin 6**
* **Red LED → Pin 11**
* **Potentiometer → A4**

## What is happening?

The potentiometer is connected to analog pin **A4**.

The Arduino reads its value using:

```cpp
int v = analogRead(pot);
```

The analog value can range from:

**0 → 1023**

The program divides this range into **three parts**:

* `0–340` → Green
* `341–680` → Yellow
* `681–1023` → Red

Depending on the potentiometer value, the corresponding LED is turned ON.

## Green Range

When:

```cpp
v >= 0 && v < 341
```

the green LED is selected.

The value is mapped from:

**0–340 → 0–255**

```cpp
v = map(v, 0, 340, 0, 255);
analogWrite(green, v);
```

The green LED brightness changes according to the potentiometer value.

The other two LEDs are turned OFF.

The Serial Monitor prints:

```text
GREEN
```

## Yellow Range

When:

```cpp
v > 340 && v < 681
```

the yellow LED is selected.

The value is mapped from:

**341–680 → 0–255**

```cpp
v = map(v, 341, 680, 0, 255);
analogWrite(yellow, v);
```

The green and red LEDs are turned OFF.

The Serial Monitor prints:

```text
YELLOW
```

## Red Range

For values from approximately **681–1023**, the red LED is selected.

The value is mapped from:

**681–1023 → 0–255**

```cpp
v = map(v, 681, 1023, 0, 255);
analogWrite(red, v);
```

The green and yellow LEDs are turned OFF.

The Serial Monitor prints:

```text
RED
```

## Why is `map()` used?

The potentiometer gives a value from **0 to 1023**, while PWM uses a value from **0 to 255**.

So `map()` converts the potentiometer value into a PWM value.

For example:

```text
0–340 → 0–255
341–680 → 0–255
681–1023 → 0–255
```

This allows the selected LED's **brightness** to change based on the potentiometer position.

## Working Table

| Potentiometer Value | LED    | Action                        |
| ------------------: | ------ | ----------------------------- |
|               0–340 | Green  | Green LED brightness changes  |
|             341–680 | Yellow | Yellow LED brightness changes |
|            681–1023 | Red    | Red LED brightness changes    |

## Example

If the potentiometer value is **200**:

**200 is in the 0–340 range → Green LED turns ON.**

If the value is **500**:

**500 is in the 341–680 range → Yellow LED turns ON.**

If the value is **800**:

**800 is in the 681–1023 range → Red LED turns ON.**

## Working Flow

**Potentiometer → analogRead() → Value 0–1023 → Check range → map() to 0–255 → PWM LED → Display color on Serial Monitor**

## Important Functions

* `analogRead()` → Reads the potentiometer value from 0–1023.
* `map()` → Converts one range of values into another range.
* `analogWrite()` → Gives PWM output from 0–255.
* `digitalWrite()` → Turns the other LEDs OFF.
* `Serial.println()` → Displays the value and selected color.
