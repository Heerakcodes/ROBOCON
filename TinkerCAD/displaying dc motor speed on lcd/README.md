# DC Motor Speed Control with LCD Display

## Aim

To control the speed of a DC motor using a potentiometer and display the potentiometer value and PWM value on a 16x2 I2C LCD.

## Components Used

* Arduino Uno
* DC Motor
* Motor Driver
* Potentiometer
* 16x2 I2C LCD
* Battery / Power Supply
* Jumper wires

## Pin Connections

### Motor Driver

* **EN1 → Pin 3**
* **IN1 → Pin 12**
* **IN2 → Pin 8**

### Potentiometer

* **Potentiometer → A1**

### LCD

The LCD uses the **I2C communication**.

* **SDA → Arduino SDA**
* **SCL → Arduino SCL**
* LCD address → `0x27`

## What is happening?

The potentiometer is connected to analog pin **A1**.

The Arduino reads its value using:

```cpp id="m0n4i5"
int v = analogRead(pot);
```

The potentiometer gives an analog value between:

**0 → 1023**

This value is then converted into a PWM value from:

**0 → 255**

using:

```cpp id="7xk3p2"
int s = map(v, 0, 1023, 0, 255);
```

The PWM value is sent to the motor driver's enable pin:

```cpp id="2zq8wb"
analogWrite(en1, s);
```

This controls the speed of the DC motor.

## Motor Direction

The motor direction is set using:

```cpp id="q1j4n8"
digitalWrite(in1, HIGH);
digitalWrite(in2, LOW);
```

This makes the motor rotate in one direction.

The direction remains fixed in this program. Only the **speed changes** according to the potentiometer.

## LCD Display

The LCD is initialized using:

```cpp id="n4t6x2"
lcd.init();
lcd.backlight();
```

The LCD displays two values.

### First Line

```cpp id="w6p2r9"
lcd.print(v);
```

This displays the **potentiometer value (0–1023)**.

### Second Line

```cpp id="k8c3v1"
lcd.setCursor(0,1);
lcd.print(s);
```

This displays the **PWM value (0–255)**.

So the LCD shows something like:

```text id="q5m7d0"
512
127
```

Where:

* `512` → Potentiometer value
* `127` → PWM value

## Why is `map()` used?

The potentiometer gives a value from **0 to 1023**, but PWM uses a range of **0 to 255**.

Therefore:

**Potentiometer: 0–1023 → PWM: 0–255**

For example:

```text id="p1s8ka"
Potentiometer = 0    → PWM = 0
Potentiometer = 512  → PWM ≈ 127
Potentiometer = 1023 → PWM = 255
```

## Why is `delay(500)` used?

```cpp id="b3r5w7"
delay(500);
```

The Arduino waits for **500 milliseconds (0.5 seconds)** before clearing the LCD and updating the values again.

This makes the displayed values update every half second.

## Working Flow

**Potentiometer → analogRead() → Value 0–1023 → map() → PWM 0–255 → Motor Driver → DC Motor**

At the same time:

**Potentiometer value + PWM value → LCD Display**

## Important Functions

* `analogRead()` → Reads the potentiometer value.
* `map()` → Converts 0–1023 into 0–255.
* `analogWrite()` → Sends PWM to control motor speed.
* `digitalWrite()` → Sets motor direction.
* `lcd.print()` → Displays values on the LCD.
* `lcd.setCursor()` → Selects the LCD position.
* `lcd.clear()` → Clears the LCD display.
* `delay()` → Creates a 0.5 second delay.
