#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

const int MAX_ASSETS = 100;

int main() {
    ifstream input("data.txt");
    ofstream output("result.txt");

    if (!input || !output) {
        cerr << "Errore: impossibile aprire i file." << endl;
        return 1;
    }

    double S;
    int n;
    string testo;
    double w[MAX_ASSETS];
	double r[MAX_ASSETS];

    // Lettura di S
	getline(input, testo, ';');
	input >> S;
	input.ignore();

    // Lettura di n
    getline(input, testo, ';');
	input >> n;
	input.ignore();
	
    // Ignora "w;r"
    input >> testo;
	
	// Lettura di pesi e rendimenti
    for (int i = 0; i < n; i++) {
        char sep;
        input >> w[i] >> sep >> r[i];
		input.ignore();
    }

    // Calcolo del rendimento del portafoglio
    double rendita_portfolio = 0.0;
    for (int i = 0; i < n; i++) {
        rendita_portfolio += w[i] * r[i];
    }

    double V = S * (1 + rendita_portfolio);

    // Scrittura di result.txt
    output << fixed << setprecision(2);
	output << "S=" << S << ", n=" << n << endl;
	output << defaultfloat;

    output << "w=[";
    for (int i = 0; i < n; ++i) {
        output << w[i];
        if (i != n - 1) {
            output << " ";
        }
    }
    output << "]" << endl;

    output << "r=[";
    for (int i = 0; i < n; ++i) {
        output << r[i];
        if (i != n - 1) {
            output << " ";
        }
    }
    output << "]" << endl;

    output << fixed << setprecision(4);
    output << "Rate of return of the portfolio : " << rendita_portfolio << endl;

    output << setprecision(2);
    output << "V:" << V << endl;

    return 0;
}