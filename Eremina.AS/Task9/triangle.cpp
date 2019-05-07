#include <iostream>
#include <cmath>
using namespace std;

#define PI 3.1415926535897932384626433832795

class Triangle {
    double a, b, c;
public:
    void input_sides();
    void output_sides();
    bool check_triangle();
    void classification_triangle();
    void angles_triangle();
    double perimeter();
    double square();
};

void Triangle::input_sides() {
    cout << "Enter sides of triangle: ";
    cin >> a >> b >> c;
}

void Triangle::output_sides() {
    cout << "Sides of triangle: " << a << " " << b << " " << c << "\n";
}

bool Triangle::check_triangle() {
    if ((a + b > c) and (a + c > b) and (b + c > a)) {
        return true;
    } else {
        return false;
    }
}

void Triangle::classification_triangle() {
    if ((a*a == b*b + c*c) or (b*b == a*a + c*c) or (c*c == a*a + b*b)) {
        cout << "Right triangle\n";
    } else if ((a*a < b*b + c*c) or (b*b < a*a + c*c) or (c*c < a*a + b*b)) {
        cout << "Acute triangle\n";
    } else {
        cout << "Obtuse triangle\n";
    }
}

void Triangle::angles_triangle() {
    double alpha, beta, gamma;
    alpha = (acos((b*b + c*c - a*a)/(2*b*c))*180)/PI;
    beta = (acos((a*a + c*c - b*b)/(2*a*c))*180)/PI;
    gamma = 180 - (alpha + beta);
    cout << "Angle between a and b: " << gamma << "\n";
    cout << "Angle between a and c: " << beta << "\n";
    cout << "Angle between b and c: " << alpha << "\n";
}

double Triangle::perimeter() {
    return a+b+c;
}

double Triangle::square() {
    double p;
    p = perimeter() / 2;
    return sqrt(p * (p-a) * (p-b) * (p-c));
}

int main(void) {
    Triangle tr1;
    tr1.input_sides();
    if (tr1.check_triangle()) {
        tr1.classification_triangle();
        tr1.angles_triangle();
        cout << "Perimeter: " << tr1.perimeter() << "\n";
        cout << "Square: " << tr1.square() << "\n";
        tr1.output_sides();
    } else {
        cout << "Error! This triangle doesn't exist!\n";
    }
    getchar();
    getchar();

    return 0;
}
