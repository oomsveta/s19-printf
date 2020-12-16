# Printf

WIP

## Why is your coding-style so weird? 🤮

I strictly follow the *Norm* enforced by the school. The Norm is a laundry list of coding conventions that students have to follow to the letter on pain of seeing their work sanctioned with a 0. The Norm forbids for instance the use of `goto`, `do while` and `for` loops, requires to declare every variable at the top of a function, and restrains the number of lines, columns and routines. Such restrictions are sometimes leading to the use of obscure code golf tricks 😅

## Notes

Each invocation of va_start() must be matched by a corresponding invocation of va_end() in the same function.

## Formatting specifiers

|Specifier|Supported|Description|
|:---:|:---:|---|
|%|✅|Prints a literal % character|
|c|✅|Prints a char|
|m|❌|Prints the string corresponding to the error code in errno (from GNU extension)|