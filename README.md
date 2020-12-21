# Printf

WIP

## Why is your coding-style so weird? 🤮

I strictly follow the *Norm* enforced by the school. The Norm is a laundry list of coding conventions that students have to follow to the letter on pain of seeing their work sanctioned with a 0. The Norm forbids for instance the use of `goto`, `do while` and `for` loops, requires to declare every variable at the top of a function, and restrains the number of lines, columns and routines. Such restrictions are sometimes leading to the use of obscure code golf tricks 😅

## Notes

Each invocation of va_start() must be matched by a corresponding invocation of va_end() in the same function.

## About the printf specification

### Format specifiers

A format specifier always follows this syntax: `%[flags][width][.precision][length]specifier`.
Optional parts are in square brackets: that means only the specifier is mandatory.
If the syntax is inaccurate, the format specifier must be printed as is, without any formatting.


#### Flags

Flags are the first part of the format specifier.
They are optional, but each of them has to appear before the other parts if it is used.

The various flags can occur in any order within this part of the format specifier.
In implementations such as GCC, the same flag can be repeated several times.

Since the flags don't have to be in a certain order, going through the string while the current character is a valid flag and record it somewhere as a boolean property seems to be an easy way to parse every flag and handle the repetitions at the same time.

|Flags|Supported|Description|
|:---:|:---:|---|
|-|✅|Right-pads the value to fit the given field width. Without this flag, the padding is set to the left by default.|
|+|✅|Add the '+' sign in front of a positive number.|
|space|✅|If no sign is going to be written, a blank space is inserted before the value. This can be helpful to align positive and negative numbers without putting a plus sign in front of positive numbers. Used in combination with the `+` flag, this flag is ignored.|
|0|✅|Left-pads the number with zeroes instead of spaces when width is specified. Used in combination with the `-` flag, this flag is ignored.|
|#|✅|Used with `o`, `x` or `X` specifiers the value is preceeded with 0, 0x or 0X respectively for values different than zero. Used with `a`, `A`, `e`, `E`, `f`, `F`, `g` or `G` it forces the written output to contain a decimal point even if no more digits follow. By default, if no digits follow, no decimal point is written.|

#### Width

#### Precision

#### Length

#### Specifiers

|Specifier|Supported|Description|
|:---:|:---:|---|
|%|✅|Prints a literal % character|
|c|✅|Prints a char|
|s|❌|Prints a null-terminated string|
|m|❌|(from GNU extension) Prints the string corresponding to the error code in errno|