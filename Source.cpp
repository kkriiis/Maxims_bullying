#include <iostream>
#include <cmath>
double func(double x, double c) {
	return 0.1 * pow(x, 7) + 0.3 * pow(x, 5) + 0.5 * pow(x, 3) + 0.7 * x + c;
}
double solve_bis(double a, double b, double eps, double c) {
	double Fa, Fb, t;
	t = b;
	do {
		Fa = func(a, c);
		t = (a + b) / 2;
		Fb = func(t, c);
		if (Fb * Fa <= 0) {
			b = t;
		}
		else {
			a = t;
		}
	} while (fabs(b - a) > eps);
	return t;
}
double solve_hord(double a, double b, double eps, double c) {
	double Fa, Fb, t;
	t = b;
	do {
		Fa = func(b, c);
		t = a + (b - a) * func(b, c) / (func(b, c) - func(a, c));
		Fb = func(t, c);
		if (Fb * Fa <= 0) {
			b = t;
		}
		else {
			a = t;
		}
	} while (fabs(b - a) > eps);
	return t;
}
int main() {
	int metod;
	std::cin >> metod;
	double a, b, eps, c;
	std::cin >> a >> b >> eps >> c;
	if (metod == 1) {
		std::cout << solve_bis(a, b, eps, c);
	}
	else if (metod == 2) {
		std::cout << solve_hord(a, b, eps, c);
	}
	else if (metod == 3) {
		std::cout << "solve_bis: " << solve_bis(a, b, eps, c) << std::endl << "solve_hord: " << solve_hord(a, b, eps, c);
	}
	return 0;
}