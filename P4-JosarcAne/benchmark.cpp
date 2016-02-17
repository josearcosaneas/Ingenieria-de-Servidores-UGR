#include <iostream>
#include <fstream>
#include <ctime>

using namespace std;


int main(){
    
   clock_t tantes,tdespues;
   double tiempo;
   int puntuacion_cpu, puntuacion_mem;

   cout<<'\n';
   for(int i=0;i<60;i++) cout<<"*";
   cout<<"\n** BENCHMARK 0.1  **\n";
   for(int i=0;i<60;i++) cout<<"*";
   cout<<endl;

   //TEST DE CPU
   
   cout<<"\n### TEST DE CPU ### \n";

   int cantidad=0;
   double cantidad2=1.5;
   
   tantes = clock();
   
   cout<<"\nPasando test de CPU..."<<endl;
   #pragma omp parallel for
   for(int i=0;i<50000000;i++){
      cantidad = cantidad*2;
      cantidad = cantidad/2;
      cantidad++;
      cantidad--;
   }
   for(int i=0;i<5000000;i++)
      cantidad2=cantidad2*1.5;
   for(int i=0;i<5000000;i++)
      cantidad2=cantidad2/1.5;
   #pragma omp end parallel for

   tdespues = clock();
   
   tiempo = static_cast<double>(tdespues - tantes)/CLOCKS_PER_SEC;
   cout<<"\nTiempo empleado: "<<tiempo<<" segundos"<<endl;
   
   puntuacion_cpu = static_cast<int>(10000/tiempo);
   cout<<"\nPuntuacion obtenida: "<<puntuacion_cpu<<" puntos\n"<<endl;
   
  //TEST DE MEMORIA

	cout<<"\n\n### TEST DE MEMORIA ### \n";

	int *vector;
	int aux;
	vector = new int[2500000]; 

	tantes = clock();

	cout<<"\nPasando test de Memoria..."<<endl;
   #pragma omp parallel for
   for(int i=0;i<200;i++){
      //Escritura en vector
      for(int j=0;j<500000;j++)
         for(int k=0;k<2500000;k+=500000)
            vector[k+j]=j;
      //Lectura del vector
      for(int j=0;j<500000;j++)
         for(int k=0;k<2500000;k+=500000)
           aux = vector[j];
   }
   #pragma omp end parallel for

	tdespues = clock();
   
    tiempo = static_cast<double>(tdespues - tantes)/CLOCKS_PER_SEC;
	cout<<"\nTiempo empleado: "<<tiempo<<" segundos"<<endl;

    puntuacion_mem = 10000/tiempo;
	cout<<"\nPuntuacion obtenida: "<<puntuacion_mem<<" puntos\n"<<endl;
}
