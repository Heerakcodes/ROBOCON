# LED Control using Serial Monitor

## Aim

To control two LEDs using numbers entered through the Arduino Serial Monitor.

## Components Used

* Arduino Uno
* 2 LEDs
* Resistors
* Jumper wires
* Breadboard

## What is happening?

In this program, two LEDs are connected to the Arduino:

* **LED1 → Pin 7**
* **LED2 → Pin 4**

We start Serial Communication using:

```cpp
Serial.begin(9600);
```

This allows us to enter numbers through the **Serial Monitor**.

The Arduino reads the number using:

```cpp
int num = Serial.parseInt();
```

The program then checks which number was entered.

### If we enter `1`

```cpp
if(num == 1)
```

LED1 is turned **ON**.

```cpp
digitalWrite(led1, HIGH);
```

The Arduino waits for 1 second.

### If we enter `2`

```cpp
if(num == 2)
```

LED1 is turned **OFF**.

```cpp
digitalWrite(led1, LOW);
```

The Arduino waits for 1 second.

### If we enter `3`

```cpp
if(num == 3)
```

LED2 is first turned **ON**:

```cpp
digitalWrite(led2, HIGH);
delay(1000);
```

After 1 second, LED2 is turned **OFF**:

```cpp
digitalWrite(led2, LOW);
delay(1000);
```

So LED2 blinks once.

## Working

| Serial Monitor Input | Action                      |
| -------------------- | --------------------------- |
| `1`                  | LED1 ON                     |
| `2`                  | LED1 OFF                    |
| `3`                  | LED2 ON for 1 sec, then OFF |

## Important Functions

* `Serial.begin(9600)` → Starts serial communication at 9600 baud.
* `Serial.parseInt()` → Reads an integer entered in the Serial Monitor.
* `digitalWrite()` → Turns an LED ON or OFF.
* `delay(1000)` → Waits for 1 second.

## Working Flow

**Enter number → Arduino reads number → Checks condition → Performs the corresponding LED action**
