#include <iostream>
using namespace std;
int main(void)
{
    int num1, num2, num3, signo1, signo2, signo3;
    cout << "Ingrese el primer numero";              
    cin >> num1;
	cout << "Ingrese el segundo numero";              
    cin >> num2;
	cout << "Ingrese el tercer numero";              
    cin >> num3; 
	if(num1<0 && num1 !=0){
		signo1 = -1;
	} else {
		signo1 = 1;
	}
	if(num2<0 && num2 !=0){
		signo2 = -1;
	} else {
		signo2 = 1;
	}
	if(num3<0 && num3 !=0){
		signo3 = -1;
	} else {
		signo3 = 1;
	}
	if((signo1==signo2)&&(signo2==signo3)){
		cout << "Los numeros tienen el mismo signo";
	} else {
		cout <<"Los numeros tienen signos diferentes";
	}
	   return 0;
}