function Saludar(){
    alert(Hola);
}
function Pares(n){
    if(n % 2 == 0) alert(n);
}
function SumaNumeros(numero){
    let resultado= (numero * (numero+1)) / 2;
    document.write("La suma de los numeros naturales hasta "+numero+" es: "+resultado+"\n");
}
function ValorMayor(){
    num1 = parseInt(prompt("Ingrese el valor del numero 1"));
    num2 = parseInt(prompt("Ingrese el valor del numero 2"));
    num3 = parseInt(prompt("Ingrese el valor del numero 3"));
    if(num1 == num2 && num1== num3) document.write("El numero: "+num1+" se repite en los tres valores, ergo, es el mayor");
    else if(num1 > num2 && num1 > num3) document.write("El mayor numero es: "+num1);
    else if(num2 > num1 && num2 > num3) document.write("El mayor numero es: "+num2);
    else if(num3 > num2 && num3 > num1) document.write("El mayor numero es: "+num3);
    document.write("\n");
}
function NumerosParesFOR(){
    for(let i = 0 ; i < 100 ; i++){
        if(i%2 == 0) document.write(i+"\t");
    }
    document.write("\n");
}
function NumerosParesWHILE(){
    let i=0;
    while(i<100){
        if(i%2 == 0) document.write(i+"\t");
        i++;
    }
    document.write("\n");
}
function InsertSort(){
    let array = new Array();
    array = [33,55,11,99,1,8,3,4,1]
    let aux = 0;
    for(let i = 1; i < array.length-1; i++){
        let j = i;
        while(j > 0 && array[j]<array[j-1]){
            aux = array[j];
            array[j] = array[j-1];
            array[j-1] = aux;
            j-=1;
        }
    }
    for(let i=0 ; i < array.length-1; i++)
        document.write(array[i]+"\t");
}