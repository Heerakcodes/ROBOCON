# Adjustable Ultrasonic Distance Warning System

## Aim

To measure the distance of an object using an ultrasonic sensor and use three LEDs to show whether the object is **safe, getting close, or too close**.

The warning distance can be adjusted using a potentiometer.

## Components Used

* Arduino Uno
* HC-SR04 Ultrasonic Sensor
* Potentiometer
* Green LED
* Yellow LED
* Red LED
* Resistors
* Breadboard
* Jumper wires

## Pin Connections

### LEDs

* **Green LED → Pin 9**
* **Yellow LED → Pin 10**
* **Red LED → Pin 11**

### Ultrasonic Sensor

* **TRIG → Pin 6**
* **ECHO → Pin 5**

### Potentiometer

* **Potentiometer → A2**

## What is happening?

The system has two main inputs:

1. **Potentiometer** → Sets the warning distance.
2. **Ultrasonic sensor** → Measures the actual distance of the object.

The Arduino compares these two values and decides which LED should turn ON.

## Setting the Warning Distance

The potentiometer is read using:

```cpp
int v = analogRead(pot);
```

The potentiometer gives a value from:

**0 → 1023**

This value is converted into a warning distance between:

**10 cm → 50 cm**

using:

```cpp
int warningdistance = map(v, 0, 1023, 10, 50);
```

So:

* Potentiometer minimum → warning distance ≈ 10 cm
* Potentiometer maximum → warning distance ≈ 50 cm

This means the user can adjust how far away an object should be before the warning starts.

## Measuring Distance

The ultrasonic sensor sends a pulse through the TRIG pin:

```cpp
digitalWrite(trig, HIGH);
delayMicroseconds(10);
digitalWrite(trig, LOW);
```

The ECHO pin is then measured using:

```cpp
duration = pulseIn(echo, HIGH);
```

The time is converted into distance:

```cpp
distance = duration * 0.034 / 2;
```

The `/2` is used because the ultrasonic wave travels **to the object and back**.

## Warning Conditions

The Arduino compares the measured distance with the warning distance.

### 1. SAFE — Green LED

```cpp
if(distance > warningdistance)
```

If the object is farther away than the warning distance:

* Green LED → ON
* Yellow LED → OFF
* Red LED → OFF
* Serial Monitor → **SAFE**

Example:

```text
Distance = 40 cm
Warning distance = 30 cm

40 > 30 → SAFE
```

### 2. GETTING CLOSE — Yellow LED

```cpp
else if(distance > warningdistance/2)
```

If the object is closer than the warning distance but still more than half of it:

* Green LED → OFF
* Yellow LED → ON
* Red LED → OFF
* Serial Monitor → **GETTING CLOSE**

Example:

```text
Distance = 20 cm
Warning distance = 30 cm

20 > 15 → GETTING CLOSE
```

### 3. TOO CLOSE — Red LED

If neither of the above conditions is true:

* Green LED → OFF
* Yellow LED → OFF
* Red LED → ON
* Serial Monitor → **TOO CLOSE**

Example:

```text
Distance = 10 cm
Warning distance = 30 cm

10 is not greater than 15 → TOO CLOSE
```

## Condition Table

| Actual Distance                             | Condition                      | LED       | Message       |
| ------------------------------------------- | ------------------------------ | --------- | ------------- |
| Greater than warning distance               | `distance > warningdistance`   | 🟢 Green  | SAFE          |
| Between half and full warning distance      | `distance > warningdistance/2` | 🟡 Yellow | GETTING CLOSE |
| Less than or equal to half warning distance | Otherwise                      | 🔴 Red    | TOO CLOSE     |

## Serial Monitor

The Serial Monitor displays both:

```text
distance: 25cm
warning distance: 40cm
GETTING CLOSE
```

This helps us see the actual distance, selected warning distance, and current status.

## Working Flow

**Potentiometer → Set warning distance (10–50 cm)**

**Ultrasonic Sensor → Measure actual distance**

**Actual distance + Warning distance → Compare → Green / Yellow / Red LED**

## Important Functions

* `analogRead()` → Reads the potentiometer value from 0–1023.
* `map()` → Converts the potentiometer value into a warning distance from 10–50 cm.
* `pulseIn()` → Measures the time taken for the ultrasonic echo.
* `delayMicroseconds()` → Creates very small delays for the ultrasonic pulse.
* `digitalWrite()` → Controls the LEDs and ultrasonic TRIG pin.
* `Serial.print()` → Displays information on the Serial Monitor.

## Main Concept

This project is basically a **distance warning system** where the user can decide the warning distance using the potentiometer.

**Potentiometer = Set the limit**

**Ultrasonic sensor = Measure the actual distance**

**LEDs = Show the warning level**
