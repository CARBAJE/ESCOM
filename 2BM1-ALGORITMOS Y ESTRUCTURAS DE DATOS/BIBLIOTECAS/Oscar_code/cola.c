#include "cola_1.1.h"
/*                Tabla de errores
        Variable        Estado      Descripción
        error           -1          Nodo nulo
        error           -2          Cola nula
        error           -3          Cola vacia
        error           0           Sin errores
*/
Cola* crearCola(int* error){
    Cola* colaAsignacion=(Cola*)malloc(sizeof(Cola));
    if(colaAsignacion==NULL){
        perror("No hay memoria para la cola");
        *error=-2;
        return NULL;
    }
    colaAsignacion->cabe=NULL;
    colaAsignacion->final=NULL;
    colaAsignacion->cursor=0;
    *error=0;
    return colaAsignacion;
}
bool colaIsEmpty(Cola q, int* error){
    if(q.cabe==NULL){
        *error=-3;
        return true;
    } else{
        *error=0;
        return false;   
    }
}
void colaCima(Cola q, int* error){
    if(!colaIsEmpty(q,error) && *error==0){
        printf("Valor en la cima: %d\n", q.cabe->valor);
    }
    *error=0;
}
//@param q Cola donde se alamcenaran los datos
//@param error Variable que gestiona errores
//@param dato Nodo con la información del usuario
void Encolar(Cola *q, int* error, struct Nodo dato){
    struct Nodo* nodoUsuario=(struct Nodo*) malloc(sizeof(struct Nodo));//abrir memoria para los datos del usuario en un auxiliar
    if(nodoUsuario==NULL){//corroborar que haya memoria
        perror("No hay memoria para almacenar tu información");
        *error=-1;
    }
    nodoUsuario->valor=dato.valor;//copar los datos del usuario en el aux
    nodoUsuario->nodoSiguiente=NULL;// el siguiente del auxiliar estara vacio 
    if(colaIsEmpty(*q,error)){//en caso de estar vacia
        q->cabe=nodoUsuario;//la cabecera es igual a los datos del usuario 
        q->final=nodoUsuario; //el final tambien 
        q->cursor++;//aumentar el cursor 
        *error=0;  
    }
    else{//en caso de no ser el primer dato 
        q->final->nodoSiguiente=nodoUsuario;//el ultimo nodo siguiente tiene que apuntar a los nuevos datos del usuario 
        q->final=nodoUsuario;//ahora el final son los datos del usuario 
        q->cursor++;//cursor aumenta
        *error=0;
    }
}
void Desencolar(Cola *q, int* error,struct Nodo *datoExtraido){
    if(!colaIsEmpty(*q,error)){//corroborar que en caso de no estar vacia actue
        struct Nodo* aux=q->cabe; //nodo auxiliar igual a los datos de la cabecera
        datoExtraido->valor=aux->valor;//lo que se vaya a sacar se le da el valor de la cabecera
        if(aux->valor==q->final->valor){//si los valores de la cabecera es igual a los datos del final es por que solo hay un dato
            q->cabe=NULL; //liberar la memoria de la cabecera igualando a null 
            q->final=NULL; //Liberar la memoria del final igualando a null 
            q->cursor--; //el cursor regresa a 0 
            *error=0;  //no hay error y deberia quedar igual de que si iniciaramos la cola por primera vez ya que solo habia un elemento 
        }
        else{// en caso de que no haya solo un dato
            q->cabe=aux->nodoSiguiente; //la cabecera tiene que ser igual al dato siguiente y el final es el ultimo en salir entonces es el mismo
            *error=0;
        }
        free(aux);
    } else{
        *error=-3;
    }
}
void vaciarCola(Cola *q, int* error){
    while(!colaIsEmpty(*q, error)){
        struct Nodo datoExtraido;
        Desencolar(q,error,&datoExtraido);
      //printf("Valor extraido: %d\n",datoExtraido.valor); // solo para ver si se estan extrayendo de manera correcta
        *error=0;
    }
}
void destruirCola(Cola* q, int* error){
    if(colaIsEmpty(*q,error)){
        puts("Destruyendo cola");
        free(q);
    }
    else{
        puts("No se puede destruir la cola debido a que aun contiene informacion");
    }
}
void recorrerCola(Cola *q, int *error){
    if(!colaIsEmpty(*q,error)){//comprobar que no este vacia
        if(q==NULL){ //comprobar que aunque exista no este vacia el primer elemeto 
        perror("Cola nula");
        *error=-2;}
        else{
        struct Nodo* aux; //crear auxiliar
        aux=q->cabe; //copiar los datos de las cabecera
        puts("\ncontenido en cola:");//imprimir
         while(aux!=NULL){//recorrer uno a uno hasta que llegue al final->nodo siguiente=NULL
        
        printf("\n%d", aux->valor);
        aux=aux->nodoSiguiente; 
        }
        *error=0;
        }
    } 
     else{
        *error=-3;
    }
}
void buscarEnCola(Cola *q, int * error, struct Nodo dato){
    if(!colaIsEmpty(*q,error)){//comprobar que no este vacia
        if(q==NULL){ //comprobar que aunque exista no este vacia el primer elemeto 
        perror("Cola nula");
        *error=-2;
        }
        else{
            int flag=0; 
            struct Nodo* aux; //crear auxiliar
            aux=q->cabe; //copiar los datos de las cabecera
            while(aux!=NULL){//recorrer uno a uno hasta que llegue al final->nodo siguiente=NULL
                if(aux->valor==dato.valor){
                    printf("\nValor encontrado %d en la posicion de la cola: %d", aux->valor, flag);//inicia desde el 0 como el cursor 
                    *error=0;
                    break;
                }
                else{
                    flag++;
                    aux=aux->nodoSiguiente;
                      if(aux->nodoSiguiente==NULL){
                        puts("\nValor no encontrado :/");
                        }
                }
            }
      
        }
    } 
    else{
        *error=-3;
    }

}
   
void SelectionSort(Cola *q, int * error){
    if(colaIsEmpty(Cola q , int* error ) == TRUE){
        perror("Cola es nula");
        *error = -2;
    }
    else{
        struct nodo aux1 = q -> cabe;
        struct nodo aux 2 = aux1 -> nodoSiguiente;
        int pivote = -1;
        while(aux1!=NULL){
            while(aux2!=NULL){
                if(aux1 -> valor > q -> valor){
                    pivote = aux1 ->valor;
                    aux1 -> valor = aux2 ->valor;
                    aux2 -> valor = pivote;
                }
                aux2 = aux2 -> nodoSiguiente;
            }
        aux1 = aux1 -> nodoSiguiente;
        }
        q-> cabe = aux1 -> cabe;
    }
}