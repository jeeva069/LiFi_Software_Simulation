# LiFi_Software_Simulation
LIVE DEMO : https://wokwi.com/projects/470968108227772417

# Li-Fi Software Simulation

A Wokwi-based Li-Fi software simulation using Arduino to demonstrate
data transmission through visible light.

## Project Overview

This project simulates a basic Li-Fi communication system where a
user enters a message through the Serial Monitor. The Arduino converts
each character into an 8-bit binary stream and transmits the data by
controlling an LED.

The transmitted bit stream is then decoded back into the original
message and verified at the receiver side.

## Features

- Custom message input through Serial Monitor
- Character-to-binary encoding
- LED-based bit transmission simulation
- Binary bit-stream generation
- Bit-stream decoding
- Original and decoded message comparison
- Transmission success/error status

## Components Used

- Arduino
- LED
- Serial Monitor
- Resistor

## Software & Tools

- C++
- Arduino
- Wokwi Simulator

## Working Principle

1. User enters a message through the Serial Monitor.
2. Arduino reads the message.
3. Each character is converted into an 8-bit binary sequence.
4. The LED represents the transmitted bits using ON/OFF states.
5. The complete bit stream is stored for simulation.
6. The receiver decodes the bit stream back into characters.
7. The decoded message is compared with the original message.
8. The system displays the transmission status.

## Example

Input:
Hello

The system converts the characters into a binary bit stream,
transmits them through LED ON/OFF states, and decodes the
received bits back to:

## Note

This is a software-based Li-Fi simulation for educational purposes.
It demonstrates the basic concept of data transmission using
visible light without representing a physical Li-Fi communication system.
