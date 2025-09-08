#include <iostream>
#include <cmath>
#include <fstream>

using namespace std;

// Define TaylorTerm struct
struct TaylorTerm {
    int order;      // the power of x in the term
    double coeff;   // coefficient of the term
    double value;   // actual value of the term for given x
};

void print_taylor_term(int index, int order, double coeff, double value) {
    cout << "Term[" << index << "]: "
         << "order=" << order << ", "
         << "coeff=" << coeff << ", "
         << "value=" << value << "\n";
}

void print_taylor_result(const char* function_name, double x,
                         int terms, double approximation) {
    cout << "Approximation of " << function_name
         << "(x) at x=" << x
         << " with " << terms << " terms: "
         << approximation << "\n";
}

// Helper function to compute factorial
double factorial(int n) {
    double fact = 1.0;
    for (int i = 2; i <= n; i++) {
        fact *= i;
    }
    return fact;
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

    double x;
    int terms;
    input >> x >> terms;

    TaylorTerm series[100]; // max 100 terms to be safe
    double approximation = 0.0;

    for (int k = 0; k < terms; k++) {
        int order = 2 * k + 1; // odd powers only
        double coeff = pow(-1, k) / factorial(order);
        double value = coeff * pow(x, order);

        series[k] = {order, coeff, value};

        approximation += value;

        // print each term
        print_taylor_term(k, series[k].order, series[k].coeff, series[k].value);
    }

    // print final approximation
    print_taylor_result("sin", x, terms, approximation);

    return 0;
}
