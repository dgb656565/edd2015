#include "operaciones.h"

int factorial (int num) 
{
	if ( num ==  0 )
		return 1;

	return num * factorial(num -1);
}

int fibonacci(int num)
{
	if (num > 2)
		return fibonacci(num - 1) + fibonacci(num - 2);
	else if (num == 2)
		return 1;
	else if (num == 1)       
		return 1;
	else if (num == 0)
		return 0;
}

int catalan(int num)
{
	if (num == 0)
		return 1;
	else
		return catalan(2*((2*num)-1))/(num + 1)*catalan(num-1));
}

int ackermann(int m, int n)
{
	if (m == 0)
		return n + 1;
	else if (n == 0)
		return ackermann(m - 1, 1);
	else
		return ackermann(m - 1, ackermann(m, n - 1));
}
