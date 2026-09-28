# Decimal to Binary using 4 LEDs

## Aim

To take a decimal number from the Serial Monitor and display its **4-bit binary representation** using four LEDs.

## Components Used

* Arduino Uno
* 4 LEDs
* Resistors
* Breadboard
* Jumper wires

## Pin Connections

* **LED 1 → Pin 4** → MSB (8)
* **LED 2 → Pin 7** → 4
* **LED 3 → Pin 8** → 2
* **LED 4 → Pin 12** → LSB (1)

## What is happening?

The program asks the user to enter a decimal number between **0 and 15** through the Serial Monitor.

```cpp
Serial.println("enter decimal no. 0-15");
```

The Arduino reads the entered number using:

```cpp
int num = Serial.parseInt();
```

Since 4 binary bits can represent numbers from **0 to 15**, the program checks:

```cpp
if(num >= 0 && num <= 15)
```

If the number is outside this range, it prints an error message.

## Converting Decimal to Binary

The program separates the decimal number into four binary bits using division and remainder.

### Bit 1

```cpp
int bit1 = num / 8;
num = num % 8;
```

This checks whether the **8's place** is present.

### Bit 2

```cpp
int bit2 = num / 4;
num = num % 4;
```

This checks the **4's place**.

### Bit 3

```cpp
int bit3 = num / 2;
num = num % 2;
```

This checks the **2's place**.

### Bit 4

```cpp
int bit4 = num;
```

This gives the **1's place**.

So the four LEDs represent:

**8 → 4 → 2 → 1**

## Example

Suppose we enter:

```text
13
```

13 can be written as:

**8 + 4 + 1 = 13**

Therefore:

```text
13 = 1101
```

The LEDs will show:

| LED   | Value | State |
| ----- | ----: | ----- |
| LED 1 |     8 | ON    |
| LED 2 |     4 | ON    |
| LED 3 |     2 | OFF   |
| LED 4 |     1 | ON    |

The Serial Monitor will print:

```text
binary: 1101
```

## Binary Representation

| Decimal | Binary |
| ------: | :----: |
|       0 |  0000  |
|       1 |  0001  |
|       2 |  0010  |
|       3 |  0011  |
|       4 |  0100  |
|       5 |  0101  |
|       6 |  0110  |
|       7 |  0111  |
|       8 |  1000  |
|       9 |  1001  |
|      10 |  1010  |
|      11 |  1011  |
|      12 |  1100  |
|      13 |  1101  |
|      14 |  1110  |
|      15 |  1111  |

## Working Flow

**Enter decimal number → Check 0–15 → Separate 8, 4, 2, 1 bits → Send bits to LEDs → Display binary in Serial Monitor**

## Important Functions

* `Serial.parseInt()` → Reads the decimal number entered by the user.
* `/` → Used to find whether a particular binary value is present.
* `%` → Gives the remaining value after division.
* `digitalWrite()` → Turns each LED ON or OFF.
* `Serial.print()` → Displays the binary result.

## Output

The user enters a number from **0 to 15**, and the Arduino displays its **4-bit binary equivalent using four LEDs** and also prints the binary value on the Serial Monitor.
