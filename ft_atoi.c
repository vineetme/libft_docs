/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmeharia <vmeharia@student.42berlin.d>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/14 23:57:24 by vmeharia          #+#    #+#             */
/*   Updated: 2026/05/15 00:01:11 by vmeharia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Function Signature: int ft_atoi(const char *str)

Parameters:

str (const char *): A pointer to a null-terminated string representing a number. 
The const qualifier ensures you only read the string.

Mechanics:
The function performs a three-stage sweep of the string:

The Skip: Bypasses all whitespace characters (spaces and tabs).

The Sign: Detects a single optional + or - to determine if the result should be 
positive or negative.

The Math: Iterates through numeric characters, converting each ASCII digit into 
its mathematical equivalent and accumulating the total.

Returns:

The converted int.

Returns 0 if no digits were found or if the string is empty.

2. The Traps & Gotchas
The "One-Sign" Rule: The standard atoi only handles one sign. If the string 
is --42 or +-42, it is considered invalid and returns 0. Your code handles 
this correctly by using an if for the sign rather than a while.

The White-Space Gauntlet: ASCII characters 9 through 13 are the "Invisible 
Five": Horizontal Tab (\t), Line Feed (\n), Vertical Tab (\v), Form Feed (\f), 
and Carriage Return (\r). You correctly targeted these using their decimal IDs.

Integer Overflow: This is the "Ghost in the Machine." A standard int can only
 hold values up to 2,147,483,647. If the input string is "9999999999999999", 
 your code will overflow, causing the bits to wrap around and produce a strange 
 result. (The official libc version often uses long internally to handle this, 
but for basic libft, your logic is standard).

The Logic (Pseudo-code)

1. Initialize an index (i), a sign multiplier (1), and a result (n = 0).
2. Skip "Whitespaces": While str[i] is a space or ASCII 9-13, increment i.
3. Check Sign: 
   - If str[i] is '-', set sign to -1.
   - If str[i] is '-' OR '+', increment i exactly once.
4. Convert Digits: While str[i] is between '0' and '9':
   - Multiply existing n by 10 (to shift digits to the left).
   - Subtract ASCII '0' (48) from the current char to get its raw value.
   - Add that value to n.
   - Increment i.
5. Return (n * sign).

The Theory: ASCII to Math

The character '0' is physically stored as the integer 48.

The character '1' is physically stored as the integer 49.

When your code does (str[i] - '0'), it is performing hardware subtraction:

If str[i] is '5' (ASCII 53): 53 - 48 = 5.

You have successfully extracted the mathematical 5 from the symbolic '5'.

The Base-10 Shift:
n = (n * 10) + digit;
Every time you find a new digit, the previous digits must move one "place" 
to the left (from the ones column to the tens column, etc.). In binary 
hardware, the CPU does this by multiplying the current total by 10 before 
adding the new unit.

5. Line-by-Line Breakdown
while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))

Clears the "noise" from the start of the string.

if (str[i] == '-' || str[i] == '+')

The fork in the road. You check for a sign but only advance the index once, 

n = (n * 10) + (str[i] - '0');

The Engine: This converts the "Symbol" into "Quantity."*/

int	ft_atoi(const char *c)
{
	int	result;
	int	i;
	int	sign;

	i = 0;
	result = 0;
	sign = 1;
	while (c[i] == ' ' || (c[i] >= 9 && c[i] <= 12))
		i++;
	if (c[i] == '+' || c[i] == '-')
		if (c[i] == '-')
			sign = -1;
	i++;
	while (c[i] >= '0' && c[i] <= '9')
	{
		result = (result * 10) + (str[i] - '0');
		i++;
	}
	return (sign * result);
}

/* int	main(void)
{
	char num[] = "50";
	printf("func: %d\n", atoi(num));
	printf("myfunc: %d\n", ft_atoi(num));
} */
