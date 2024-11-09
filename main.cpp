#include <iostream>
#include <cmath>

using namespace std;

class Point {
private:
    double x;
    double y;

public:
    Point(double x_coord = 0, double y_coord = 0) : x(x_coord), y(y_coord) {}

    double getX() const { return x; }
    double getY() const { return y; }

    //d = √((x₂-x₁)² + (y₂-y₁)²)
    double operator-(const Point& other) const {
        return sqrt(pow(other.x - x, 2) + pow(other.y - y, 2));
    }

    bool operator==(const Point& other) const {
        return (x == other.x && y == other.y);
    }

    bool operator!=(const Point& other) const {
        return !(*this == other);
    }

    Point operator/(const Point& other) const {
        return Point(
            (x + other.x) / 2,
            (y + other.y) / 2
        );
    }

    Point operator*(double constant) const {
        return Point(x * constant, y * constant);
    }

    double operator[](char coord) const {
        if (coord == 'x') return x;
        if (coord == 'y') return y;
        throw runtime_error("Invalid coordinate. Use 'x' or 'y'");
    }

    friend ostream& operator<<(ostream& os, const Point& p) {
        os << "(" << p.x << ", " << p.y << ")";
        return os;
    }
};

Point operator*(double constant, const Point& p) {
    return p * constant;
}

int main() {
    Point p1(3.2, 9.8);
    Point p2(5.5, -1.2);

    cout << "Point p1: " << p1 << endl;
    cout << "Point p2: " << p2 << endl;

    cout << (p1 == p2) << endl; 
    cout << (p1 != p2) << endl; 

    cout << p1 / p2 << endl;

    cout << "p1 * 2: " << p1 * 2 << endl;
    cout << "p1 * 2.0: " << p1 * 2.0 << endl;
    cout << "p1 * -3: " << p1 * -3 << endl;
    cout << "2 * p1: " << 2 * p1 << endl;  

    cout << "p1['x']: " << p1['x'] << endl;
    cout << "p1['y']: " << p1['y'] << endl;

    return 0;
}
