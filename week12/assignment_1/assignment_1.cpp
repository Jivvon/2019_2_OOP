#include <iostream>

int fibo(int i){
	if (i <= 1) return i;
	return fibo(i - 1) + fibo(i - 2);
}

int main()
{
	int i;
	std::cin >> i;
	int val = fibo(i);

	std::cout << val << std::endl;
	return 0;
}
