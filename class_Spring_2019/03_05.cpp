/* this is about recursion

int recursiveFactorial(int n) {
	if(n==0){return 1;}
	else return x*recursiveFactorial(n-1);
}


3.5.1 Linear Recursion
Summing the Elements of an Array Recursively.

Algorithm LinearSum(A,n):
	Input: A integer array A and an integer n>=1, such that A has at least n elements
	Output: The sum of the first n integers in A

if n=1 then
	returnA[0]
else
	return LinearSum(A,n-1) = A[n-1]



3.5.2 Binary Recursion
When an algorithm makes two recursive calls, we say that it uses binary recursion. 

Algorithm: BinarySum(A,i,n):
	Input: An array A and integers i and n
	Output: The sum of the n integers in A starting at index i
	if n=1 then
		return A[i]
	return BinarySub(A,i,[n/2]) + BinarySum(A, i+[n/2], n/2)

See Figure 3.20 explaining.


