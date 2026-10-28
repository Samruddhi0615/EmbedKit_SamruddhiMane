Embedded Developer Fresher Assessment

Author: Samruddhi Mane

Project: Ring Buffer in C

A fixed-size, 8-byte ring buffer implemented in standard C99. It supports writing and reading bytes in FIFO order, checking the buffer count, and detecting full and empty conditions.

Requirements:
- GCC compiler
- C99-compatible compiler
- Windows, Linux, or another supported platform

Build:
gcc -Wall -std=c99 ring_buf.c -o ring_buf

Run on Windows:
ring_buf.exe

Features:
- Fixed capacity of 8 bytes
- FIFO (First In, First Out) operation
- Rejects writes when the buffer is full
- Rejects reads when the buffer is empty
- Reports the current byte count
- Demonstrates wraparound and buffer boundary conditions

