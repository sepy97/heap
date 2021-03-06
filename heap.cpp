#include <cstdio>
#include <cmath>
#include <string>

using namespace std;

typedef unsigned long long llu;

llu numOfHeaps 	(const unsigned int N);			//function counts number of heaps of size N

llu choose 	(const unsigned int N, const unsigned int k);	//function calculates a number of ways to choose k elements of N

llu fact 	(const unsigned int N, const unsigned int k);	//function calculates N! / k!

double probability (const unsigned int N);

int main (int argc, char* argv [])
{
//	printf ("%d \n", choose (5, 3));

	if (argc <= 2)
	{
		printf ("You should enter the opcode ('p' or 'n') and the size of a heap!\n");
		return -1;
	}

	if (!strcmp (argv[1], "n"))
	{
		unsigned int size = atoi (argv[2]);
		printf ("Number of heap-ordered trees of size %d: %llu \n", size, numOfHeaps (size));
	}
	else if (!strcmp (argv[1], "p"))
	{
		llu power = 1;
		// TODO: check size boundaries (size >= 3)
		unsigned int size = atoi (argv[2]);
		/*	
		double result = double (numOfHeaps (size)) / 2.0;
		for (int i = 3; i <= size; i++)
		{
			result /= double(i);
		}
		printf ("%.21f \n", result);
		*/
		printf ("%.21f \n", probability (size));
	}
	else
	{	
		printf ("Incorrect opcode\n");
	}
}

double probability (const unsigned int N)
{
	if (N == 1) return 1.0;
	double result = 1.0;
	result /= double (N);
        result *= probability ((N-1)/2) * probability ((N-1)/2);
	return result;
}

llu numOfHeaps (const unsigned int N)
{
//	printf ("now calculating heaps of size %d\n", N);
	if (N <= 1) return 1;

	llu result = 0;
	for (int i = 1; i < N-1; i++)
	{
		result += choose (N, i) * numOfHeaps (i) * numOfHeaps (N-i-1);
	}
	return result;
}

llu choose (const unsigned int N, const unsigned int k)
{
	if (2*k > N)
	{
		return fact (N, k) / fact (N-k, 1);
	}
	else 
	{
		return fact (N, N-k) / fact (k, 1);
	}
	return 0;
}

llu fact (const unsigned int N, const unsigned int k)
{
	llu result = 1;
	for (int i = k; i < N; i++)
	{
		result *= (i+1);
	}
	return result;
}
