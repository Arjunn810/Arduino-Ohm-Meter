# Arduino Ohm Meter 📟⚡
by Arjun
A simple **Arduino-based Ohm Meter** using a **16×2 LCD & voltage divider circuit** to measure unknown resistance.

## 🛠️ Components Used
- **Arduino Uno**
- **16×2 LCD (Parallel Mode)**
- **1KΩ Reference Resistor**
- **Unknown Resistor (to measure)**
- **10KΩ Potentiometer** (for LCD contrast)
- **Jumper Wires & Breadboard**

## 🔌 Circuit Diagram (wiring for lcd Parellel)
LCD    | Pin Arduino Pin
VSS	   | GND
VDD	   | 5V
VO	   | Middle pin of 10KΩ potentiometer
RS	   | Pin 7
RW	   | GND
E	     | Pin 6
D4	   | Pin 5
D5	   | Pin 4
D6	   | Pin 3
D7	   | Pin 2


**##Check the Resistor Circuit (Voltage Divider)**
Component	          |   Arduino Pin
One side of R1      |  (1KΩ)	5V
Other side of R1	  |  A0 & One side of R2
Other side of R2    | (Unknown Resistor)	GND

## formula used
R2 = R1 * (Vout / (Vin - Vout));
