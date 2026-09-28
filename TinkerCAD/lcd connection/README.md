# Hello World using I2C LCD

## Aim

To display **"Hello World"** on a 16x2 I2C LCD using Arduino Uno.

## Components Used

* Arduino Uno
* 16x2 I2C LCD
* Jumper wires

## LCD Connection

The LCD uses **I2C communication**, so it communicates with the Arduino using the SDA and SCL pins.

* **VCC → 5V**
* **GND → GND**
* **SDA → SDA**
* **SCL → SCL**

## What is happening?

The program uses two libraries:

```cpp
#include <LiquidCrystal_I2C.h>
#include <Wire.h>
```

### `Wire.h`

The `Wire` library is used for **I2C communication** between the Arduino and the LCD.

### `LiquidCrystal_I2C.h`

This library provides functions to easily control the I2C LCD.

The LCD is created using:

```cpp
LiquidCrystal_I2C lcd(0x27, 16, 2);
```

Here:

* `0x27` → I2C address of the LCD
* `16` → LCD has 16 columns
* `2` → LCD has 2 rows

So the LCD is a **16×2 LCD**.

## LCD Initialization

Inside `setup()`:

```cpp
lcd.init();
```

This initializes the LCD.

Then:

```cpp
lcd.backlight();
```

turns ON the LCD backlight.

## Displaying Text

The cursor is placed at the first row and first column:

```cpp
lcd.setCursor(0, 0);
```

Then:

```cpp
lcd.print("Hello World");
```

displays:

**Hello World**

on the first row.

The cursor is then moved to the second row:

```cpp
lcd.setCursor(0, 1);
```

Here:

* `0` → first column
* `0` → first row
* `1` → second row

## Output

The LCD displays:

```text
Hello World
```

on the first row.

The second row is currently empty.

## Why is `loop()` empty?

There is nothing that needs to continuously change in this program.

The message only needs to be displayed once, so all the LCD instructions are placed inside `setup()`.

`setup()` runs **once** when the Arduino starts.

`loop()` runs **continuously**, but there is no repeated task in this program.

## Working Flow

**Arduino starts → Initialize I2C → Initialize LCD → Turn ON backlight → Set cursor → Print "Hello World"**

## Important Functions

* `lcd.init()` → Initializes the LCD.
* `lcd.backlight()` → Turns ON the LCD backlight.
* `lcd.setCursor()` → Sets the position where text will be displayed.
* `lcd.print()` → Displays text on the LCD.
