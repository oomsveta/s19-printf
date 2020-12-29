# Printf

WIP

***Printf*** is my third project as a student of the 19 Coding School.

As you've probably guessed, the purpose of this project is to reimplement the `printf` function from scratch. The only way we have so far to print values is to use the `write` syscall to put a sequence of octets into STDOUT. Hence, printing anything else than simple characters becomes really tedious and more sophisticated functions such as `printf` are necessary.

The aim of reimplementing printf is to get used to variadic functions, string parsing and various base conversions.

The project guidelines are available [here](/subjects/en.subject.pdf); note that this repository may NOT be fully-compliant with the requirements, mainly for organizational purposes. Students, be aware, if you steal my code, you'll face the consequences 😈

## Why is your coding-style so weird? 🤮

I strictly follow the *Norm* enforced by the school. The Norm is a laundry list of coding conventions that students have to follow to the letter on pain of seeing their work sanctioned with a 0. The Norm forbids for instance the use of `goto`, `do while` and `for` loops, requires to declare every variable at the top of a function, and restrains the number of lines, columns and routines. Such restrictions are sometimes leading to the use of obscure code golf tricks 😅

## About the printf specification

### Format specification

A format specifier always follows this syntax: `%[flags][width][.precision][size]type`.
Optional fields are in square brackets: that means only the type field is mandatory.
If the syntax is inaccurate, the specifier must be printed as is, without any formatting.

#### Flags

Flags are the first part of a format specifier.
They are optional, but each of them has to appear before the other parts if it is used.

The various flags can occur in any order within this part of the format specifier.
In implementations such as GCC, the same flag can be repeated several times.

Since the flags don't have to be in a certain order, going through the string while the current character is a valid flag and record it somewhere as a boolean property seems to be an easy way to parse every flag and handle the repetitions at the same time.

+ **Mandatory flags for this project**: `-`, `0`
+ **Bonus flags**: `#`, ` `, `+`

|Flags|Supported|Description|
|:---:|:---:|---|
|`-`|✅|Right-pads the value to fit the given field width. Without this flag, the padding is set to the left by default.|
|`+`|✅|Adds the plus sign in front of a positive number.|
|` `|✅|If no sign is going to be written, a space is inserted before the value. This can be helpful to align positive and negative numbers without putting a plus sign in front of positive numbers. Used in combination with the `+` flag, this flag is ignored.|
|`0`|✅|Left-pads the number with zeroes instead of spaces when width is specified. Used in combination with the `-` flag, this flag is ignored.|
|`#`|✅|Used with `o`, `x` or `X` specifiers the value is preceded with 0, 0x or 0X respectively for values different than zero. Used with `a`, `A`, `e`, `E`, `f`, `F`, `g` or `G` it forces the written output to contain a decimal point even if no more digits follow. By default, if no digits follow, no decimal point is written.|
|`I`|❌|(from GNU extension) ???|
|`'`|❌|(from POSIX extension) Groups thousands by separating them with a character defined by the locale.|

In my implementation of printf, unsupported flags are just ignored.

#### Width

The width is the minimal number of characters to be printed. If the value to be printed is shorter than this number, the result is padded with spaces (or zeroes if the `0` flag is used). The value is not truncated even if the result is larger.

You can set the width either literally by specifying it within the format string or by using arguments of the printf function. To set the width using arguments, you have to put the `*` character in the format string, which means the width will be provided as an argument of type `int`.

You cannot use both ways at the same time, and you cannot repeat the `*` modifier.

The max width varies from one implementation to another, but always has to be lower than the INT_MAX. On the 19 School's computers (Mac OS X 10.14.6), the limit is 2,147,483,646. Exceeding the limit leads to printing nothing on any implementation I've tested.

If you provide a negative width using the arguments, then its absolute value will be used and the result will be right-padded, in the same way as if you've enabled the `-` flag.

#### Precision

A precision specification always starts with `.` to separate it from the width field

#### Size

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

#### Type

+ **Mandatory specifiers for this project**: cspdiuxX%
+ **Bonus specifiers**: nfge

|Specifier|Supported|Description|Example|
|:---:|:---:|---|---|
|`%`|🔧‍|Prints a literal % character|`%`|
|`A`|🔧|Prints a hexadecimal floating point (uppercase)|`0X1.4D55554FBDAD7P+9`|
|`a`|🔧|Prints a hexadecimal floating point (lowercase)|`0x1.4d55554fbdad7p+9`|
|`c`|🔧|Prints a character|`c`|
|`d` or `i`|🔧|Prints a signed decimal integer|`512`|
|`E`|🔧|Prints a decimal floating point using the scientific notation (uppercase)|`3.9265E+2`|
|`e`|🔧|Prints a decimal floating point using the scientific notation (lowercase)|`3.9265e+2`|
|`F`|🔧|Prints a decimal floating point (uppercase) ⁽¹⁾|`3.142857`|
|`f`|🔧|Prints a decimal floating point (lowercase) ⁽¹⁾|`1.618033`|
|`G`|🔧|Prints a decimal floating point using the shortest representation: %E or %F|`392.65`|
|`g`|🔧|Prints a decimal floating point using the shortest representation: %e or %f|`392.65`|
|`m`|❌|(from GNU extension) Prints the string corresponding to the error code in errno|`Success`|
|`n`|❌|Stores the number of characters written so far in a variable. The argument corresponding to this specifier must be a pointer to a `signed int`, which will be used to store the number.||
|`o`|🔧|Prints an unsigned octal|`12345670`|
|`p`|🔧|Prints a pointer address ⁽²⁾|`0x201`|
|`s`|🔧|Prints a null-terminated string|`shrek is love`|
|`u`|🔧|Prints an unsigned decimal integer|`4294967295`|
|`X`|🔧|Prints an unsigned hexadecimal integer (uppercase)|`AAAAAAA`|
|`x`|🔧|Prints an unsigned hexadecimal integer (lowercase)|`aaaaaaa`|

##### Notes
1. The `F` and `f` specifiers only differ with special values such as INFINITY and NAN.
2. Formatting NULL with the `p` specifier produces `(nil)`.

### Buffer

pas demandé pour ce projet

réduire le nombre de syscalls et donc être plus rapide

adapter le code pour asprintf et autres

j'utilise des vecteurs pour limiter les allocations de mémoire et facilement récupérer la longueur

Each invocation of va_start() must be matched by a corresponding invocation of va_end() in the same function.

## References

+ http://www.cplusplus.com/reference/cstdio/printf/ about the overall functioning of printf
+ http://www.pixelbeat.org/programming/gcc/format_specs.html about the `I` and `'` flags
+ https://www.gnu.org/software/libc/manual/html_node/Other-Output-Conversions.html about the `m` specifier