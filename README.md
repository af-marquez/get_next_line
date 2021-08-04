# Get next line
### A 42 Lisboa project


With get_next_line it will be possible to read a line ending with a newline character from a file descriptor. This project will allow to learn about static variables and deepen my knowledge about file descriptors, better understanding of allocations of memory, the life cycle and manipulation of a buffer.

Basically, calling this function in a loop will then enable to read the text available on a file descriptor one line at a time until the EOF. Get_next_line will return an integer that will be taken to evaluate all the lines until the file ends. The functions read(), malloc() and free() were the only external functions used.
