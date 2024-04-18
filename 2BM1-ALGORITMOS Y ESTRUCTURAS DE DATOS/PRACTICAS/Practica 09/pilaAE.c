#include "pilaA.h"
int main(int argc, char** argv){
	int error=0;
	int flag=0;
	Pila *p=crearPila(&error);
	struct NodoP dato;
	// queremos pedir el string del usuario que sera la operacion posfija
    char posfija[100]; 
    printf("\nIngrese su operacion posfija: ");
    fflush(stdin); 
    scanf("%s", posfija);

	int i=0, a,b,c; 
	while (posfija[i] != '\0'){//leo la cadena hasta el final 
		fflush(stdin); 
		dato.valor=((int)posfija[i]); //guardo el ASCII en el NOdo 
			apilar(p,&error,dato);//lo apilo 
			if((int)posfija[i]=='*'){
				desapilar(p,&error,&dato); // desapilo el *
				a=p->cima->valor-48; // deberia de ahora ser el numero en ASCCII y le resto 48 para tenerlo en decimal 
				desapilar(p,&error,&dato); //desapilo el numero 
				b=p->cima->valor-48; //ahora trabajo con el 2do numero 
				desapilar(p,&error,&dato); //desapilo
				c=a*b; //opero los numeros
				dato.valor=c+48; //guardo el resultado en ascii
				apilar(p,&error,dato); //apilo el resultado
			}
			if((int)posfija[i]=='+'){
				desapilar(p,&error,&dato); 
				a=p->cima->valor-48; 
				desapilar(p,&error,&dato); 
				b=p->cima->valor-48; 
				desapilar(p,&error,&dato); 
				c=a+b; 
				dato.valor=c+48; 
				apilar(p,&error,dato); 
			}   
            if((int)posfija[i]=='-'){
				desapilar(p,&error,&dato); 
				a=p->cima->valor-48; 
				desapilar(p,&error,&dato); 
				b=p->cima->valor-48; 
				desapilar(p,&error,&dato); 
				c=a-b; 
				dato.valor=c+48; 
				apilar(p,&error,dato); 
			}
			if((int)posfija[i]=='/'){
                desapilar(p,&error,&dato);
                b=p->cima->valor-48;
                desapilar(p,&error,&dato);
                a=p->cima->valor-48;
                desapilar(p,&error,&dato);
                c=a/b;
                dato.valor=c+48;
                apilar(p,&error,dato);
				}
		i++; //incremento para poder recorrer la operacion 
		
	}  

	printf("La operacion tiene como resultado %d\n", p->cima->valor-48);
	//consultarCima(*p,&error); esta era para comprobar que funcionara la pila
	vaciarPila(p,&error);
	return error;
}