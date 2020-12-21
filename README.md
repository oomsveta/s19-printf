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
|`-`|✅|Right-pads the value to fit the given field width. Without this flag, the padding is set to the left by default.|
|`+`|✅|Adds the plus sign in front of a positive number.|
|` `|✅|If no sign is going to be written, a space is inserted before the value. This can be helpful to align positive and negative numbers without putting a plus sign in front of positive numbers. Used in combination with the `+` flag, this flag is ignored.|
|`0`|✅|Left-pads the number with zeroes instead of spaces when width is specified. Used in combination with the `-` flag, this flag is ignored.|
|`#`|✅|Used with `o`, `x` or `X` specifiers the value is preceeded with 0, 0x or 0X respectively for values different than zero. Used with `a`, `A`, `e`, `E`, `f`, `F`, `g` or `G` it forces the written output to contain a decimal point even if no more digits follow. By default, if no digits follow, no decimal point is written.|
|`I`|❌|(from GNU extension) ???|
|`'`|❌|(from POSIX extension) Groups thousands by separating them with a character defined by the locale.|

In my implementation of printf, unsupported flags are just ignored.

#### Width

#### Precision

#### Length

|Modifier|Supported|Description|
|:---:|:---:|---|
|`hh`|?|???|
|`h`|?|???|
|`l`|?|???|
|`ll`|?|???|
|`j`|?|???|
|`t`|?|???|
|`z`|?|???|
|`q`|?|???|

#### Specifiers

|Specifier|Supported|Description|Example|
|:---:|:---:|---|---|
|`%`|👷‍|Prints a literal % character|`%`|
|`A`|👷|Prints a hexadecimal floating point (uppercase)|`0X1.4D55554FBDAD7P+9`|
|`a`|👷|Prints a hexadecimal floating point (lowercase)|`0x1.4d55554fbdad7p+9`|
|`c`|👷|Prints a character|`c`|
|`d` or `i`|👷|Prints a signed decimal integer|`512`|
|`F`|👷|Prints a decimal floating point (uppercase) ⁽¹⁾|`3.142857`|
|`f`|👷|Prints a decimal floating point (lowercase) ⁽¹⁾|`1.618033`|
|`E`|👷|Prints a decimal floating point using the scientific notation (uppercase)|`3.9265E+2`|
|`e`|👷|Prints a decimal floating point using the scientific notation (lowercase)|`3.9265e+2`|
|`G`|👷|Prints a decimal floating point using the shortest representation: %E or %F|`392.65`|
|`g`|👷|Prints a decimal floating point using the shortest representation: %e or %f|`392.65`|
|`s`|👷|Prints a null-terminated string|`shrek`|
|`m`|❌|(from GNU extension) Prints the string corresponding to the error code in errno|`Succes`|
|`n`|❌|Stores the number of characters written so far in a variable. The argument corresponding to this specifier must to be a pointer to a `signed int`, which will be used to store the number.||
|`o`|👷|Prints an unsigned octal|`12345670`|
|`p`|👷|Prints a pointer address ⁽²⁾|`0x201`|
|`u`|👷|Prints an unsigned decimal integer|`4294967295`|
|`X`|👷|Prints an unsigned hexadecimal integer (uppercase)|`AAAAAAA`|
|`x`|👷|Prints an unsigned hexadecimal integer (lowercase)|`aaaaaaa`|

##### Notes
1. The `F` and `f` specifiers only differ with special values such as INFINITY and NAN.
2. Formatting NULL with the `p` specifier produces `(nil)`.

## References

+ http://www.cplusplus.com/reference/cstdio/printf/ about the overall functioning of printf
+ http://www.pixelbeat.org/programming/gcc/format_specs.html about the `I` and `'` flags
+ https://www.gnu.org/software/libc/manual/html_node/Other-Output-Conversions.html about the `m` specifier