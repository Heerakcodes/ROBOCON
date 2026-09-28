# Ultrasonic Distance Sensor with Green and Red LED

## Aim

To measure the distance of an object using an **HC-SR04 ultrasonic sensor** and indicate the distance using **green and red LEDs**.

## Components Used

* Arduino Uno
* HC-SR04 Ultrasonic Sensor
* Green LED
* Red LED
* Resistors
* Breadboard
* Jumper wires

## Pin Connections

| Component       | Arduino Pin    |
| --------------- | -------------- |
| Ultrasonic Trig | Digital Pin 6  |
| Ultrasonic Echo | Digital Pin 5  |
| Green LED       | Digital Pin 8  |
| Red LED         | Digital Pin 12 |

## What is happening?

The ultrasonic sensor sends an ultrasonic sound wave and waits for the wave to come back after hitting an object.

The Arduino measures the time taken by the sound wave using:

```cpp
duration = pulseIn(echo, HIGH);
```

The distance is then calculated using:

```cpp
distance = duration * 0.034 / 2;
```

The `0.034` represents the approximate speed of sound in **cm/µs**.

We divide by `2` because the sound travels:

**Sensor → Object → Sensor**

So the measured time represents the **round trip**.

## Working Conditions

The code checks whether the object is more than **10 cm** away.

### If distance > 10 cm

* Green LED → **ON**
* Red LED → **OFF**

This means the object is at a safe distance.

### If distance ≤ 10 cm

* Green LED → **OFF**
* Red LED → **ON**

This means the object is too close.

## Ultrasonic Sensor Trigger

The sensor is triggered using:

```cpp
digitalWrite(trig, LOW);
delayMicroseconds(2);

digitalWrite(trig, HIGH);
delayMicroseconds(10);

digitalWrite(trig, LOW);
```

A **10 microsecond HIGH pulse** is given to the trigger pin to start the measurement.

## Serial Monitor

The measured distance is also printed on the Serial Monitor:

```cpp
Serial.print("distance: ");
Serial.print(distance);
Serial.println(" cm");
```

Example:

```text
distance: 25 cm
distance: 18 cm
distance: 8 cm
```

## Important Functions

* `digitalWrite()` → Turns pins HIGH or LOW.
* `delayMicroseconds()` → Creates a very short delay in microseconds.
* `pulseIn()` → Measures how long the Echo pin stays HIGH.
* `Serial.print()` → Displays information on the Serial Monitor.
* `delay()` → Adds a delay in milliseconds.

## Working Flow

**Trigger Ultrasonic Sensor → Send Sound Wave → Receive Echo → Measure Time → Calculate Distance → Check Distance → Green/Red LED**

### Simple Logic

**Distance > 10 cm → Green LED ON**

**Distance ≤ 10 cm → Red LED ON**

## Output

The system continuously measures the distance.

* **Object farther than 10 cm → 🟢 Green LED**
* **Object at or closer than 10 cm → 🔴 Red LED**
