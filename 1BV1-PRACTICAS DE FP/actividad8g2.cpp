#include <iostream>
using namespace std;
int main(void)
{
	int hora24, hora12, minutos;
	cout <<"Ingrese las horas en el formato de 24 Hrs (SIN MINUTOS NI SEGUNDOS)\n";
	cin >> hora24;
	cout <<"Ingrese los minutos\n";
	cin >> minutos;
	if(hora24>=13 && hora24<=23){
		hora12=hora24-12;
	} else if (hora24!=0){
		hora12=hora24;
	} else {
		hora12=12;
	}
	cout <<"El horario en formato de 24 horas es:\n";
	cout << hora12 << ":" << minutos;
	return 0;
}