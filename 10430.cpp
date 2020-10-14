#include <iostream>
/*
첫째 줄에 (A+B)%C, 둘째 줄에 (A%C + B%C)%C, 셋째 줄에 (A×B)%C, 넷째 줄에 (A%C × B%C)%C를 출력한다.
*/
int main() {
	int a, b, c;
	std::cin >> a >> b >> c;
	std::cout << (a + b) % c << std::endl;
	std::cout << (a % c + b % c) % c << std::endl;
	std::cout << (a * b) % c << std::endl;
	std::cout << (a % c * b % c) % c << std::endl;
}