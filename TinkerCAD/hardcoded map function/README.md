# Ultrasonic Distance Sensor with LED PWM

## Aim

To measure the distance of an object using an ultrasonic sensor and control the brightness of an LED according to the measured distance.

## Components Used

* Arduino Uno
* HC-SR04 Ultrasonic Sensor
* LED
* Resistor
* Jumper wires
* Breadboard

## Pin Connections

### Ultrasonic Sensor

* **TRIG → Pin 6**
* **ECHO → Pin 3**

### LED

* **LED → Pin 9**

## What is happening?

The ultrasonic sensor is used to measure the distance of an object.

The Arduino sends a short pulse through the **TRIG** pin:

```cpp
digitalWrite(trig, LOW);
delay(2);
digitalWrite(trig, HIGH);
delay(10);
digitalWrite(trig, LOW);
```

The sensor sends an ultrasonic wave. When the wave hits an object, it comes back to the sensor.

The **ECHO** pin stays HIGH for the amount of time taken by the sound to travel to the object and come back.

The Arduino measures this time using:

```cpp
duration = pulseIn(echo, HIGH);
```

## Calculating Distance

The time is converted into distance using:

```cpp
distance = (0.034 / 2) * duration;
```

Here:

* `0.034` is approximately the speed of sound in **cm/µs**.
* We divide by `2` because the sound travels **to the object and back**.

So:

**Distance = Time × Speed of Sound / 2**

The calculated distance is printed on the Serial Monitor.

Example:

```text
distance: 50.25
```

## Distance Range

The program uses:

```cpp
int inmin = 20;
int inmax = 200;
```

So the expected useful distance range is:

**20 cm → 200 cm**

If the object is closer than 20 cm or farther than 200 cm:

```cpp
if(distance < 20 || distance > 200)
```

the LED is turned OFF.

```cpp
digitalWrite(led, LOW);
```

## LED Brightness

When the distance is between **20 cm and 200 cm**, the program calculates a value that is intended to control the LED using PWM.

```cpp
analogWrite(led, v);
```

The PWM value can range from:

**0 → 255**

* `0` → LED OFF
* `255` → Maximum PWM output
* Values between 0 and 255 → Different brightness levels

## Main Concept

The basic idea is:

**Ultrasonic Sensor → Measure Distance → Check Distance Range → Calculate PWM Value → LED Brightness**

So the LED brightness is intended to change according to the distance of the object.

## Serial Monitor

The Serial Monitor displays:

```text
distance: ...
mapped value at(0-255): ...
```

This helps us see both the measured distance and the PWM value being generated.

## Important Functions

* `digitalWrite()` → Sends HIGH or LOW to a digital pin.
* `pulseIn()` → Measures how long the ECHO pin remains HIGH.
* `analogWrite()` → Gives PWM output from 0–255.
* `Serial.print()` → Displays information in the Serial Monitor.
* `map()` concept → Used to convert values from one range to another.

## Working Flow

**TRIG sends ultrasonic pulse → Sound reflects from object → ECHO receives reflection → `pulseIn()` measures time → Distance calculated → Check 20–200 cm → Calculate PWM → LED brightness controlled**
