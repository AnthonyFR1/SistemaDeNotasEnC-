#include <iostream>
#include <stdio.h>
/*#include <stdlib.h>*/
#include <string.h>
#include "biblioteca.h"
#include <conio.h>

#define maxChar 70
#define max 70

using namespace std;

//Integrantes:
//	Figueroa Ruiz, Roberto Anthony
//	Sakamoto Alvarado, Masao

int main() 
{	
	system("color 0a");
	
	struct Alumno
	{	
	char nombre[maxChar];
	char apellidoPat[maxChar];
	char apellidoMat[maxChar];
	char codigo[maxChar];
	float t1;
	float parcial;
	float t2;
	float fin;
	float prom;
	};
	
	struct Alumno datosAlumno[max], aux;
	

	char palabra[25];
	
	//Datos menu
	int op;
	char rpt;

	//Datos para ingreso de alumnos
	int n;
	 int temp;
	 
	 
	 int bandera;
	 bandera=0;
	

	do{
		system("cls");
		aviso();
		menu();
		cout<<"\nIngrese opción:\n "; 
		cin>>op;
		op=validarOpcion(op);
		
		system("cls");
		switch(op)
		{
		case 1:	
			
			
			system("cls");
			system("color 0a");
			cout<<"Ingrese cuantos Alumnos desea Registrar: ";
			cin>>n;
			system("cls");

			for (int i=0; i<n; i++)
			{
				cout<<"\nIngrese el Codigo del # "<<i+1<<" Alumno: "<<endl;
				cin>>datosAlumno[i].codigo;
				cin.ignore(256,'\n');
				cout<<"\t\nIngrese el Nombre del Alumno # "<<i+1<<"\t\n";
				cin.getline(datosAlumno[i].nombre, maxChar,'\n');
				cout<<"\t\nIngrese el Apellido Paterno del Alumno # "<<i+1<<endl;
				cin.getline(datosAlumno[i].apellidoPat, maxChar,'\n'); 
				cout<<"\t\nIngrese el Apellido Materno del Alumno #"<<i+1<<endl;
				cin.getline(datosAlumno[i].apellidoMat, maxChar,'\n');

				system("cls");
			}
				break;
					
			
		case 2:

			system("color 0a"); 
			for (int i=0; i<n; i++)
			{
				cout<<"\t\nIngrese la Nota T1 del Alumno: "<<datosAlumno[i].apellidoPat<<" - "<<datosAlumno[i].apellidoMat<<endl;
				cin>>datosAlumno[i].t1;
				datosAlumno[i].t1=validarNotas(datosAlumno[i].t1);
				datosAlumno[i].t1=validarT1T2(datosAlumno[i].t1);
				
				cout<<"\t\nIngrese la Nota Parcial del Alumno: "<<datosAlumno[i].apellidoPat<<" - "<<datosAlumno[i].apellidoMat<<endl;
				cin>>datosAlumno[i].parcial;
				datosAlumno[i].parcial=validarNotas(datosAlumno[i].parcial);
				datosAlumno[i].parcial=validarParcial(datosAlumno[i].parcial);
				
				cout<<"\t\nIngrese la Nota T2 del Alumno: "<<datosAlumno[i].apellidoPat<<" - "<<datosAlumno[i].apellidoMat<<endl;
				cin>>datosAlumno[i].t2;
				datosAlumno[i].t2=validarNotas(datosAlumno[i].t2);
				datosAlumno[i].t2=validarT1T2(datosAlumno[i].t2);
				
				cout<<"\t\nIngrese la Nota Final del Alumno: "<<datosAlumno[i].apellidoPat<<" - "<<datosAlumno[i].apellidoMat<<endl;
				cin>>datosAlumno[i].fin;
				datosAlumno[i].fin=validarNotas(datosAlumno[i].fin);
				datosAlumno[i].fin=validarFinal(datosAlumno[i].fin);
				
				datosAlumno[i].prom=(datosAlumno[i].t1)+(datosAlumno[i].parcial)+(datosAlumno[i].t2)+(datosAlumno[i].fin);
				system("color 0a"); 
				cout<<"\tPromedio Ponderado "<<datosAlumno[i].prom<<endl;
				cout<<"----------------------------------------------------"<<endl;
			}
				break;
			
		case 3:	
				
			system("color 0e"); 
			//Burbuja para Apellidos
			for(int i=0; i<n; i++){
				bandera=0;        
				for(int j=n-1; j>=i; j--){
					temp=strcmp(datosAlumno[j-1].apellidoPat,datosAlumno[j].apellidoPat);
					if(temp>0){
						aux=datosAlumno[j];
						datosAlumno[j]=datosAlumno[j-1];
						datosAlumno[j-1]=aux;
						bandera=1; //si hubo cambio cambiamos la bandera a 1
					}
				}
			}
			
			cout<<"Lista de Alumnos Ordenados por Apellido Paterno: "<<endl<<endl;
			for(int i=0;i<n;i++)
			{
				cout<<"---------------------------------------------- "<<endl;
				cout<<"\tApellido Paterno: "<<datosAlumno[i].apellidoPat<<endl;
				cout<<"\tApellido Materno: "<<datosAlumno[i].apellidoMat<<endl;
				cout<<"\tNombre: "<<datosAlumno[i].nombre<<endl;
				cout<<"\tCodigo: "<<datosAlumno[i].codigo<<endl;
				cout<<"-----------------------------------------------";
				cout<<endl;
			}
		
	
			break;
			
		case 4: 
			
			system("color 0e"); 
			cout<<"Lista de Promedios Ponderados: "<<endl<<endl;
			for(int i=0;i<n;i++)
			{
				cout<<"------------------------------------------ "<<endl;
				datosAlumno[i].prom=(datosAlumno[i].t1)+(datosAlumno[i].parcial)+(datosAlumno[i].t2)+(datosAlumno[i].fin);
				datosAlumno[i].prom=validarAlumnosAprobados(datosAlumno[i].prom);
				cout<<"\tPromedio Ponderado "<<datosAlumno[i].prom<<endl;
				cout<<"\tT1: "<<datosAlumno[i].t1<<endl;
				cout<<"\tParcial: "<<datosAlumno[i].parcial<<endl;
				cout<<"\tT2: "<<datosAlumno[i].t2<<endl;
				cout<<"\tFinal: "<<datosAlumno[i].fin<<endl;
				cout<<"-------------------------------------------";
				cout<<endl;
			}
			break;
				
				
		case 5:
	
			system("color 0e"); 
			cout<<"Ingresa el Apellido Paterno del Alumno a Buscar su Promedio:\n ";
			cin.ignore(256, '\n'); 
			cin.getline(palabra,25,'\n');
			for(int i=0;i<n;i++)
			{
				if (strcmp(palabra,datosAlumno[i].apellidoPat)==0)
				{
					cout<<"Alumno (Apellido Paterno): "<<datosAlumno[i].apellidoPat<<endl; 
					cout<<"Apellido Materno: "<<datosAlumno[i].apellidoMat<<endl;
					cout<<"\tTiene de Promedio: "<<datosAlumno[i].prom<<endl;
					cout<<"\tT1: "<<datosAlumno[i].t1<<endl;
					cout<<"\tParcial: "<<datosAlumno[i].parcial<<endl;
					cout<<"\tT2: "<<datosAlumno[i].t2<<endl;
					cout<<"\tFinal: "<<datosAlumno[i].fin<<endl;
					getche();
					system("cls");
					bandera=1;
					break;
				}
			}
			if (bandera == 0)
			{
				cout<<"\tEl Apellido Ingresado no esta Registrado ";
				getche();
				system("cls");
			} 
			break;	
	
			
			
			
		case 6:
			
			system("color 0e"); 
			cout<<"\tIngresa el Apellido Paterno del Alumno a Eliminar: "<<endl;
			cin.ignore(256, '\n'); 
			cin.getline(palabra,25,'\n');  
			for(int i=0;i<n;i++)
			{
				if (strcmp(palabra,datosAlumno[i].apellidoPat)==0)
				{
					cout<<"Ingresa '0'  para Eliminar el Alumno\n";
					cin.getline(datosAlumno[i].apellidoPat,10,'\n');
					cout<<"Ingresa '0'  para Eliminar el Alumno\n";
					cin.getline(datosAlumno[i].apellidoMat,10,'\n');
					cout<<"Ingresa '0'  para Eliminar el Alumno\n";
					cin.getline(datosAlumno[i].nombre,10,'\n');
					cout<<"Ingresa '0'  para Eliminar el Alumno\n";
					cin.getline(datosAlumno[i].codigo,10,'\n');
					cout<<"Ingresa '0'  para Eliminar el Alumno\n";
					cin>>datosAlumno[i].t1;
					cout<<"Ingresa '0'  para Eliminar el Alumno\n";
					cin>>datosAlumno[i].parcial;
					cout<<"Ingresa '0'  para Eliminar el Alumno\n";
					cin>>datosAlumno[i].t2;
					cout<<"Ingresa '0'  para Eliminar el Alumno\n";
					cin>>datosAlumno[i].fin;
					cout<<"Ingresa '0'  para Eliminar el Alumno\n";
					cin>>datosAlumno[i].prom;
					bandera=1;
					system("cls");
					break;
				}
			}
			if (bandera == 0)
			{
				cout<<"\tEl Apellido Ingresado no se encontro: ";
				getche();
				system("cls");
			}
			break;
		}		
	
		rpt=decidirRepeticion();
	} while (rpt=='s');
	
	return 0;
}

