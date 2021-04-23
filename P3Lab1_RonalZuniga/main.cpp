#include <iostream>
using namespace std;
int menu();
void tablero(int n);
int sumatoria(int n);
double raiz(double n, int t);

int main() {
	int opcion;
	while((opcion = menu()) != 4) {
		switch(opcion) {
			case 1: {
				int n;
				cout << "**Tablero de Ajedrez**" << endl;
				cout << "Ingrese el valor de n: ";
				cin >> n;
				cout << endl;
				while (n <= 0) {
					cout << "El valor de n NO puede ser 0 o negativo" << endl;
					cout << "Ingrese el valor de n: ";
					cin >> n;
					cout << endl;
				}
				tablero(n);
				cout << endl;
				break;
			}

			case 2: {
				int n;
				cout << "**Sumatoria**" << endl;
				cout << "Ingrese el valor de n: ";
				cin >> n;
				cout << endl;
				while (n <= 0) {
					cout << "El valor de n NO puede ser 0 o negativo" << endl;
					cout << "Ingrese el valor de n: ";
					cin >> n;
					cout << endl;
				}
				cout << "El resultado de la sumatoria con n = " << n << " es: " << sumatoria(n) << endl;
				cout << endl;
				break;
			}

			case 3: {
				double n;
				int t;
				cout << "**Raiz Cuadrada**" << endl;
				cout << "Ingrese el valor de n: ";
				cin >> n;
				while (n < 0) {
					cout << "El valor de n NO puede ser negativo" << endl;
					cout << "Ingrese el valor de n: ";
					cin >> n;
					cout << endl;
				}
				cout << "Ingrese el valor de t: ";
				cin >> t;
				while (t <= 10) {
					cout << "t debe ser mayor que 10" << endl;
					cout << "Ingrese el valor de t: ";
					cin >> t;
					cout << endl;
				}
				cout << "La raiz cuadrada de " << n << " es: " << raiz(n,t) << endl;
				cout << endl;
				break;
			}
		}//fin del switch
	}//fin del while
	return 0;
}

int menu() {
	int opcion;
	cout << "----MENU----" << endl;
	cout << "1. Tablero de Ajedrez" << endl;
	cout << "2. Sumatoria" << endl;
	cout << "3. Raiz Cuadrada" << endl;
	cout << "4. Salir" << endl;
	cout << endl;
	cout << "Ingrese la opcion: ";
	cin >> opcion;
	cout << endl;
	while(opcion > 4 || opcion <= 0) {
		cout << "La opcion debe de estar dentro del rango" << endl;
		cout << "Ingrese la opcion: ";
		cin >> opcion;
		cout << endl;
	}
	return opcion;
}

void tablero(int n) {
	cout << endl;
	for(int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if(i % 2 == 0) {
				if(j % 2 == 0) {
					cout << "0";
				} else {
					cout << "1";
				}

			} else {
				if(j % 2 == 0) {
					cout << "1";
				} else {
					cout << "0";
				}
			}
		}
		cout << endl;
	}
	cout << endl;
}

int sumatoria(int n) {
	int total = 0;
	for(int i = 1; i <= n; i++) {
		total += 2*i*(i-1);
	}
	return total;
}

double raiz(double n, int t) {
	double max = n, inicio = 0;
	double mitad = (max + inicio)/2;
	for (int i = 0; i < t; i++) {
		double aux = mitad*mitad;
		if (aux == n) {
			break;
		}
		if(aux > n) {
			max = mitad;
			mitad = (max + inicio)/2;
		}
		if(aux < n) {
			inicio = mitad;
			mitad = (max + inicio)/2;
		}
	}
	return mitad;
}