#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

// Define the Rectangle struct
struct Rectangle {
    double width;
    double height;
    double thickness;
    double density;
    string material;
    double mass;
};

void print_plate(int index, double width, double height,
                 double density, double mass, const char* material) {
    cout << "Plate[" << index << "]: "
         << "width=" << width << ", "
         << "height=" << height << ", "
         << "density=" << density << ", "
         << "mass=" << mass << ", "
         << "material=" << material << "\n";
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

    int num_plates;
    input >> num_plates;
    input.ignore(); // skip newline after number

    const int MAX_PLATES = 10;
    Rectangle plates[MAX_PLATES];

    // Read plate data
    for (int i = 0; i < num_plates; i++) {
        input >> plates[i].width;
        input >> plates[i].height;
        input >> plates[i].thickness;
        input >> plates[i].density;
        input.ignore(); // skip newline before material
        getline(input, plates[i].material);

        // Compute mass
        plates[i].mass = plates[i].width * plates[i].height *
                         plates[i].thickness * plates[i].density;
    }

    // Print results
    for (int i = 0; i < num_plates; i++) {
        print_plate(i,
                    plates[i].width,
                    plates[i].height,
                    plates[i].density,
                    plates[i].mass,
                    plates[i].material.c_str());
    }

    return 0;
}
