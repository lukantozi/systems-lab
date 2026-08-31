#include <iostream>
#include <string>

class Ball {
    std::string m_c { "white" };
            double m_r { 0.0 };

public:
    Ball(const std::string_view c, const double r)
        : m_c { c }
        , m_r { r }
    {
    }

    std::string& color() { return m_c; }
    double radius() { return m_r; }
};

void print(Ball b) {
    std::cout << "Ball(" << b.color() << ", " << b.radius() << ")\n";
}

int main() {
	Ball blue { "blue", 10.0 };
	print(blue);

	Ball red { "red", 12.0 };
	print(red);

	return 0;
}
