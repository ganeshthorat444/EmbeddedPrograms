// This is the file for library functions
// 1. Addition()
// 2. Substraction()
// 3. Division()
// 4. Multiplication()



int intAddition(int val1, int val2)
{
	return val1 + val2;
}

int intSubstraction(int val1, int val2)
{
	return val1 - val2;
}

int intMultiplication(int val1, int val2)
{
	return val1 * val2;
}

float intDivision(int val1, int val2)
{
	if (( val1 != 0) && (val2 != 0))
		return val1/val2;
	else
		return -1;
}

