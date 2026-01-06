# Embedded JSON Serializer for Smart Meter Data

## Project Overview
In this project, structured smart meter data is serialized into a predetermined JSON format using an embedded software library.

The assignment simulates a realistic part of a smart-meter / w-M-Bus data pipeline:

Measurement data → internal data structures → JSON serialization → gateway / backend interface

The focus of this project is on:
- Clean software architecture
- Embedded-oriented implementation
- Controlled memory usage
- Clear and simple API design

w-M-Bus communication, OMS, encryption, and real meter interaction are intentionally out of scope.


## Platform and Language Choice
**Platform:** ESP32 using Arduino framework  
**Programming Language:** C / C++

**Justification:**
- Arduino framework is explicitly allowed in the assignment
- ESP32 represents a common embedded gateway-class device
- Arduino allows fast testing while keeping the core logic platform-agnostic
- The serialization library itself contains no hardware- or transport-specific code


## Project Structure
