#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

// Define the Sensor struct
struct Sensor {
    int id;
    double temperature;
    double voltage;
    char status[20];
};

// Function to print sensor details
void print_sensor(int index, int id, double temperature, double voltage, const char* status) {
    cout << "Sensor[" << index << "]: "
         << "id=" << id << ", "
         << "temperature=" << temperature << ", "
         << "voltage=" << voltage << ", "
         << "status=" << status << "\n";
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

    int num_sensors;
    input >> num_sensors;

    const int MAX_SENSORS = 10;

    // Create an array of Sensor
    Sensor sensors[MAX_SENSORS];

    // Read sensor data from input
    for (int i = 0; i < num_sensors; i++) {
        input >> sensors[i].id;
        input >> sensors[i].temperature;
        input >> sensors[i].voltage;
        input >> sensors[i].status;
    }

    // Iterate using a pointer and print sensor data
    Sensor* sensor_ptr = sensors; // Pointer to the array
    for (int i = 0; i < num_sensors; i++) {
        print_sensor(i, sensor_ptr->id, sensor_ptr->temperature, sensor_ptr->voltage, sensor_ptr->status);
        sensor_ptr++; // Move to the next sensor
    }

    return 0;
}
