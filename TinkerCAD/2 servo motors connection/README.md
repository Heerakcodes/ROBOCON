# Two Servo Control using Potentiometer

## Aim

To control two servo motors using a single potentiometer, where both servos move in opposite directions.

## Components Used

* Arduino Uno
* 2 Servo Motors
* Potentiometer
* Jumper wires
* Breadboard

## Pin Connections

* **Servo 1 signal → Pin 3**
* **Servo 2 signal → Pin 5**
* **Potentiometer → A0**

## What is happening?

A potentiometer is connected to analog pin **A0**.

The Arduino reads the potentiometer value using:

```cpp
int v = analogRead(pot);
```

The analog value from the potentiometer is between:

**0 → 1023**

This value is then mapped to the servo's angle range:

**0° → 180°**

### Servo 1

```cpp
s1.write(map(v, 0, 1023, 0, 180));
```

For Servo 1:

* Potentiometer = 0 → Servo = 0°
* Potentiometer = 1023 → Servo = 180°

So when the potentiometer is rotated, Servo 1 moves from **0° to 180°**.

### Servo 2

```cpp
s2.write(map(v, 0, 1023, 180, 0));
```

For Servo 2, the mapping is reversed:

* Potentiometer = 0 → Servo = 180°
* Potentiometer = 1023 → Servo = 0°

So Servo 2 moves in the **opposite direction** to Servo 1.

## Why do we use `map()`?

The potentiometer gives a value from **0 to 1023**, but the servo needs an angle from **0° to 180°**.

So `map()` converts the potentiometer value into a suitable servo angle.

For Servo 1:

**0–1023 → 0–180°**

For Servo 2:

**0–1023 → 180–0°**

## Working Example

If the potentiometer value is approximately **512**:

* Servo 1 → approximately **90°**
* Servo 2 → approximately **90°**

If the potentiometer is rotated towards the maximum:

* Servo 1 → moves towards **180°**
* Servo 2 → moves towards **0°**

## Working Flow

**Potentiometer → Arduino A0 → Read value (0–1023) → map() → Servo angles → Two servos move in opposite directions**

## Important Functions

* `analogRead()` → Reads the potentiometer value.
* `map()` → Converts one range of values into another range.
* `Servo.attach()` → Connects the servo to an Arduino pin.
* `Servo.write()` → Sets the servo angle.
