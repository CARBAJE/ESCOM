#include "P6.h"
int main(int argc, char** argv){
	int error=0;
	int flag=0;
	Pila *p=crearPila(&error);
	struct Nodo dato;
	FILE *archivo=fopen("posfija.txt", "r"); 
	if (archivo==NULL){
		perror("No se pudo leer el archivo"); 
	}
	char caracter=0; 
	int a,b,c; 
	while(feof(archivo)==0){//leo el archivo hasta el final 
		fflush(stdin); 
		caracter=fgetc(archivo);//leo caracter a caracter y lo guardo en un temporal 
		dato.valor=(int)caracter; //guardo el ASCII en el NOdo 
		if(caracter!=-1&&caracter!='\n'){// valido que no  haya llegado al final y que no guarde un salto de linea
			apilar(p,&error,dato);//lo apilo 
			if(caracter=='*'){
				desapilar(p,&error,&dato); // desapilo el *
				a=p->cima->valor-48; // deberia de ahora ser el numero en ASCCII y le resto 48 para tenerlo en decimal 
				desapilar(p,&error,&dato); //desapilo el numero 
				b=p->cima->valor-48; //ahora trabajo con el 2do numero 
				desapilar(p,&error,&dato); //desapilo
				c=a*b; //opero los numeros
				dato.valor=c+48; //guardo el resultado en ascii
				apilar(p,&error,dato); //apilo el resultado
			}
			if(caracter=='+'){
				desapilar(p,&error,&dato); 
				a=p->cima->valor-48; 
				desapilar(p,&error,&dato); 
				b=p->cima->valor-48; 
				desapilar(p,&error,&dato); 
				c=a+b; 
				dato.valor=c+48; 
				apilar(p,&error,dato); 
			}   
            if(caracter=='-'){
				desapilar(p,&error,&dato); 
				a=p->cima->valor-48; 
				desapilar(p,&error,&dato); 
				b=p->cima->valor-48; 
				desapilar(p,&error,&dato); 
				c=a-b; 
				dato.valor=c+48; 
				apilar(p,&error,dato); 
			}      
		}
		if(caracter=='\n'||feof(archivo)!=0){
			flag++; 
			printf("La operacion [%d] tiene como resultado %d\n",flag, p->cima->valor-48);
			vaciarPila(p,&error); 
		}      
	}  
	fclose(archivo);  
	consultarCima(*p,&error);
	vaciarPila(p,&error);
	return error;
}