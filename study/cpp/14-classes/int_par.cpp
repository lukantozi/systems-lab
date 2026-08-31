#include <iostream>

/* Provide the definition for IntPair and the print()
 * member function here */
struct IntPair {
    int val1 {};
    int val2 {};

    void print() {
        std::cout << "Pair(" << val1 << ", " << val2 << ")\n";
    }

    bool isEqual(IntPair& p) {
        return val1 == p.val1 && val2 == p.val2;
    }
};

int main() {
	IntPair p1 {1, 2};
	IntPair p2 {3, 4};

	std::cout << "p1: ";
	p1.print();

	std::cout << "p2: ";
	p2.print();

	std::cout << "p1 and p1 " << (p1.isEqual(p1) ? "are equal\n" : "are not equal\n");
	std::cout << "p1 and p2 " << (p1.isEqual(p2) ? "are equal\n" : "are not equal\n");
	return 0;
}
