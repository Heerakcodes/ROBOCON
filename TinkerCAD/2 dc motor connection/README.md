# Two DC Motor Control using Motor Driver

## Aim

To control two DC motors using an Arduino and a motor driver by setting their direction and speed.

## Components Used

* Arduino Uno
* 2 DC Motors
* Motor Driver
* Battery / Power Supply
* Jumper wires

## Pin Connections

### Motor 1

* EN1 → Pin 5
* IN1 → Pin 2
* IN2 → Pin 4

### Motor 2

* EN2 → Pin 3
* IN3 → Pin 7
* IN4 → Pin 8

## What is happening?

There are two motors connected to a motor driver.

The **IN pins** are used to control the **direction** of the motor, while the **EN pins** are used to control the **speed using PWM**.

### Motor 1

```cpp
digitalWrite(in1, HIGH);
digitalWrite(in2, LOW);
```

This combination tells the motor driver to rotate Motor 1 in **one direction**.

Then:

```cpp
analogWrite(en1, 100);
```

gives a PWM value of **100 out of 255** to the enable pin.

So Motor 1 runs at a certain speed.

### Motor 2

Similarly:

```cpp
digitalWrite(in3, HIGH);
digitalWrite(in4, LOW);
```

sets Motor 2 to rotate in **one direction**.

Then:

```cpp
analogWrite(en2, 100);
```

gives a PWM value of **100 out of 255**.

So Motor 2 also runs at a certain speed.

## PWM

Arduino PWM values range from:

**0 → 255**

* `0` → Motor OFF
* `255` → Maximum PWM duty cycle
* `100` → Medium-low PWM value

The PWM controls the **average voltage/power supplied to the motor**, which is used to control its speed.

## Direction Control

For a motor:

| IN1  | IN2  | Motor              |
| ---- | ---- | ------------------ |
| LOW  | LOW  | Stop               |
| HIGH | LOW  | One direction      |
| LOW  | HIGH | Opposite direction |
| HIGH | HIGH | Stop/Brake*        |

*The exact braking behavior depends on the motor driver.

## Working Flow

**Arduino → Motor Driver → H-Bridge → DC Motors**

The Arduino sends direction signals through the IN pins and PWM signals through the EN pins. The motor driver uses these signals to control the two motors.

## Output

Both motors rotate in the same selected direction at a PWM value of **100**.
