# Switch Based Movement Control

## Aim

To use two switches as inputs and display different movement commands using LEDs and the Serial Monitor.

## Components Used

* Arduino Uno
* 2 Switches
* 3 LEDs
* Resistors
* Breadboard
* Jumper wires

## Pin Connections

### Switches

* **Switch 1 → Pin 12**
* **Switch 2 → Pin 8**

### LEDs

* **LED 1 → Pin 2**
* **LED 2 → Pin 4**
* **LED 3 → Pin 7**

## What is happening?

The two switches are connected to digital input pins.

The Arduino reads their states using:

```cpp
bool s1 = digitalRead(sw1);
bool s2 = digitalRead(sw2);
```

Each switch can have two states:

* `1` → HIGH / ON
* `0` → LOW / OFF

The Arduino checks the switch conditions and decides which LED should turn ON and which movement command should be printed.

## Case 1: Both switches are ON

```cpp
if(s1 == 1 && s2 == 1)
```

When both switches are ON:

* LED 1 → ON
* LED 2 → OFF
* LED 3 → OFF
* Serial Monitor prints **"move forward"**

So this condition represents **moving forward**.

## Case 2: Switch 1 OFF and Switch 2 ON

```cpp
else if(s1 == 0 && s2 == 1)
```

When Switch 1 is OFF and Switch 2 is ON:

* LED 2 → ON
* LED 1 → OFF
* LED 3 → OFF
* Serial Monitor prints **"move backward"**

So this condition represents **moving backward**.

## Case 3: Switch 2 is OFF

```cpp
if(s2 == 0)
```

When Switch 2 is OFF:

* LED 3 → ON
* LED 1 → OFF
* LED 2 → OFF
* Serial Monitor prints **"stop"**

So this condition represents **stopping**.

## Condition Table

| Switch 1 | Switch 2 | LED   | Command       |
| -------- | -------- | ----- | ------------- |
| ON (1)   | ON (1)   | LED 1 | Move Forward  |
| OFF (0)  | ON (1)   | LED 2 | Move Backward |
| Any      | OFF (0)  | LED 3 | Stop          |

## Working Flow

**Read Switch 1 & Switch 2 → Check condition → Turn ON corresponding LED → Print movement command**

## Important Functions

* `digitalRead()` → Reads the state of a switch.
* `digitalWrite()` → Turns an LED ON or OFF.
* `Serial.println()` → Prints the movement command in the Serial Monitor.
* `if / else if` → Checks different switch conditions.
