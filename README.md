# ATtiny85_MouseJiggler

A simple USB Mouse jiggler using the ATtiny85 chip


## Digispark circuit

```
       ┌───────────────────┐
       │              PB5 o│
┌──────┘              PB4 o│
│███████              PB3 o│
|███████     G  V     PB2 o│──────o´¯o──────┐
└──────┐  5  N  C     PB1 o│──[100Ω]──|LED>─┤
       │  V  D  C     PB0 o│                │
       └──o──o──o──────────┘                │
             └──────────────────────────────┘
o´¯o := push button     [xxx] := resistor
```


## Complete circuit

```
VCC  o──[2k2Ω]─┬─────────o 8 VCC
USB- o─────────┼──[68Ω]──o 2 PB3
USB+ o──────┬──╫──[68Ω]──o 3 PB4
GND  o──┐   ╧  ╧      ┌──o 4 GND o────────────────┐
        │   Z  Z      │    6 PB1 o──[100Ω]──|LED>─┤
        │   ┬  ┬      │    7 PB2 o──────o´¯o──────┘
        └───┴──┴──────┘
Z    := Zener 3V6       ╫     := bridging over
o´¯o := push button     [xxx] := resistor
```
