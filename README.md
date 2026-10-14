# ft_printf

## Introduction

This project was developed at 1337 Coding School, part of the 42 Network. It involves recreating the behavior of the standard C `printf()` function by implementing my own version, called `ft_printf()`.

After working on Libft, this project gave me the opportunity to improve my C programming skills and explore a new concept: **variadic functions**.

One of the things I enjoyed most about ft_printf was figuring out how to handle a variable number of arguments and determine how each argument should be formatted and displayed. It was fun to work on because I had to understand how the arguments were passed to the function and build the formatting logic myself.

## Project Overview

The goal of ft_printf is to implement a simplified version of the standard `printf()` function.

The function must accept a format string followed by a variable number of arguments. It then processes the format string, identifies conversion specifiers, and prints the corresponding values.

For example:

```c
ft_printf("Hello, %s! You are %d years old.\n", "Adil", 21);
```

Output:

```text
Hello, Adil! You are 21 years old.
```

Here, `%s` is replaced with a string, and `%d` is replaced with an integer.

Instead of using the standard `printf()` function to handle the formatting, I had to implement the logic myself.

## What I Learned

### 1. Variadic Functions

One of the most interesting things I learned in this project was how to work with **variadic functions**.

A variadic function is a function that accepts a variable number of arguments. In C, this allows us to pass different numbers of arguments to the same function.

For example, `printf()` can accept just a format string or a format string followed by several values:

```c
printf("Hello!\n");
printf("My age is %d\n", 21);
printf("%s scored %d points\n", "Adil", 100);
```

The number and types of the arguments after the format string can change from one call to another.

To implement this behavior, I learned how to use the following macros and type from `<stdarg.h>`:

- `va_list`: Declares a variable used to access the additional arguments.
- `va_start`: Initializes the argument list.
- `va_arg`: Retrieves the next argument with the specified type.
- `va_end`: Completes the use of the argument list.

These tools helped me understand how to process arguments when their number is not fixed.

### 2. How Variadic Functions Work

To understand variadic functions better, I created a simple example:

```c
#include <stdarg.h>
#include <stdio.h>

void	print_numbers(int count, ...)
{
	va_list	args;
	int		i;
	int		number;

	va_start(args, count);
	i = 0;
	while (i < count)
	{
		number = va_arg(args, int);
		printf("%d\n", number);
		i++;
	}
	va_end(args);
}

int	main(void)
{
	print_numbers(3, 10, 20, 30);
	return (0);
}
```

Output:

```text
10
20
30
```

In this example, `count` tells the function how many additional arguments to read.

The `...` indicates that the function can receive additional arguments. `va_start()` initializes access to those arguments, and each call to `va_arg()` retrieves the next one.

Finally, `va_end()` completes the process.

This example helped me understand the basic mechanism behind variadic functions and gave me the foundation I needed to implement `ft_printf()`.

### 3. Understanding Format Specifiers

Another important part of the project was learning how to interpret format specifiers.

A format string contains ordinary characters and special sequences beginning with `%`. Each sequence tells the function how to interpret and display the corresponding argument.

The main conversion specifiers I worked with were:

| Specifier | Meaning |
|---|---|
| `%c` | Prints a character |
| `%s` | Prints a string |
| `%p` | Prints a pointer address |
| `%d` | Prints a signed decimal integer |
| `%i` | Prints an integer |
| `%u` | Prints an unsigned decimal integer |
| `%x` | Prints an unsigned hexadecimal integer in lowercase |
| `%X` | Prints an unsigned hexadecimal integer in uppercase |
| `%%` | Prints a literal `%` character |

Learning to handle these conversions helped me understand how the same function can process different data types based on instructions contained in a string.

### 4. Parsing the Format String

I learned how to iterate through a string character by character and identify conversion specifiers.

When the function encounters an ordinary character, it prints it directly. When it encounters `%`, it checks the next character to determine which conversion to perform.

For example:

```c
ft_printf("Number: %d\n", 42);
```

The function processes the format string until it encounters `%d`. It then retrieves the corresponding integer argument and prints its value.

This required implementing separate logic for different data types and making sure the arguments were retrieved in the correct order.

### 5. Working with Pointers and Data Types

The project also strengthened my understanding of pointers and C data types.

Each conversion specifier requires the correct argument type when using `va_arg()`. Retrieving an argument using an incompatible type can cause undefined behavior.

I also learned how pointer addresses can be displayed in hexadecimal and how strings can be processed using pointers.

These concepts reinforced the importance of understanding the type of data being handled and how it is represented in memory.

### 6. Return Values and Error Handling

Another important part of the project was understanding the return value of `printf()`.

The function returns the number of characters printed, excluding the terminating null character.

My implementation therefore needed to track the number of characters written and return the appropriate count.

I also needed to consider edge cases, such as empty strings, different conversion specifiers, and format strings containing ordinary characters alongside conversions.

## Conclusion

ft_printf was an enjoyable project because it challenged me to recreate a familiar function without relying on its standard implementation.

The most interesting part was working with variadic functions. I enjoyed learning how to access a variable number of arguments and use the format string to decide how each argument should be processed.

The project also improved my understanding of format specifiers, pointers, data types, string parsing, and return values in C.

Overall, ft_printf helped me become more comfortable with low-level C programming and taught me how to build a useful function from scratch by understanding the mechanisms behind it.
