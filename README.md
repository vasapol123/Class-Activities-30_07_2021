# Class Activities on 30 july 2021
This class activities is prepared in partial fulfillment of the requirements for the Software Development Practice I subject which is a part of computer engineering curriculum in King Mongkut’s University of Technology North Bangkok—KMUTNB—Thailand.

## Task 7
Write a C program that
* creates a new file named 'data.txt' (or overwrites it if there exists a file with the same name),
* randomizes up to N integer numbers (e.g. N=1000), 
* saves the numbers to the file (one number per line),
* closes the file and exits the program.

## Task 8
Write a C program that
* reads integer numbers from the text file 'data.txt' up to N numbers. 
* sorts the numbers using the Quicksort algorithm.
* saves the stored list of integers to the output file named 'data_sorted.txt'.
**Note:** Write C code for the quicksort algorithm in the source file 'qsort.c'
and include it to your C project.

##Task 9
Write a C program that behaves and produces the same output as the Python script given below:
```
# convert an integer to a hex string
def to_hex( value ):
    HEX_DIGITS = '0123456789abcdef'
    s = ''
    if (value < 0):
        value += (1 << 32)  # 32-bit value
    while True:
        d = HEX_DIGITS[ value & 0xf ]
        s = d + s
        value >>= 4
        if value == 0:
            break
    s = '0x' + s
    return s

if __name__ == "__main__": # some test code
    print (to_hex(33))  # 0x21
    print (to_hex(-1))  # 0xffffffff
```
