# brainfuck-interpreter-c

Simple brainfuck interpreter written in C.

Pre-allocates 30000 bytes.

When trying to decrement pointer below 0 or above 30000, it wraps around.
