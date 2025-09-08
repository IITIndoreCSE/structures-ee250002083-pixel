#include <iostream>
#include <cmath>
#include <fstream>

using namespace std;

// Define Point struct
struct Point {
    double x;
    double y;
};

// Print before and after rotation
void print_point_rotation(double x_before, double y_before,
                          double theta, double x_after, double y_after) {
    cout << "Before rotation: (x=" << x_before << ", y=" << y_before << ")\n";
    cout << "After rotation (θ=" << theta << " rad): "
         << "(x=" << x_after << ", y=" << y_after << ")\n";
}

// Function to rotate a point (p) around pivot (pivot) by angle theta
Point rotate_point(const Point& p, const Point& pivot, double theta) {
    Point result;
    double dx = p.x - pivot.x;
    double dy = p.y - pivot.y;

    result.x = pivot.x + dx * cos(theta) - dy * sin(theta);
    result.y = pivot.y + dx * sin(theta) + dy * cos(theta);

    return result;
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        cerr << "Usage: " << argv[0] << " <input_file>" << endl;
        return 1;
    }

    ifstream input(argv[1]);
    if (!input) {
        cerr << "Error opening " << argv[1] << endl;
        return 1;
    }

    Point p, pivot;
    double theta;

    // Read: x, y, theta, px, py
    input >> p.x >> p.y >> theta >> pivot.x >> pivot.y;

    // Rotate point
    Point rotated = rotate_point(p, pivot, theta);

    // Print result
    print_point_rotation(p.x, p.y, theta, rotated.x, rotated.y);

    return 0;
}
