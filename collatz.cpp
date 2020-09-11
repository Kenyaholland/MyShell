#include "collatz.hpp"

Collatz::Collatz(int n){
	
	collatzFun(n);
}

int Collatz::collatzFun(int n){

	std::cout << n << std::endl;
	if(n == 1){
		return 1;
	}
	else if(n % 2 == 0){
		return collatzFun(n / 2);
	}
	else{
		return collatzFun(n * 3 + 1);
	}
}
