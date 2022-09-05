#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "biblioteca.h"

#define maxChar 70
#define max 70

using namespace std;


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



void aviso()
{
	cout<<"\t\t\tBienvenido al Curso de Verano de Matematica del Colegio Antonio Torres Araujo\n"<<endl;

}

void menu()
{
	cout<<"\nMenu de Registro de Notas de Alumnos\n";
	cout<<"--------------------------------------\n";
	cout<<"1.Registrar Alumno(s)\n";
	cout<<"2.Registar Notas\n";
	cout<<"3.Mostrar Alumno(s) Ordenados por Apellido Paterno\n";
	cout<<"4.Mostrar Promedio Ponderado de los Alumno(s)\n";
	cout<<"5.Busqueda de Promedio de Alumnos(s)\n";
	cout<<"6.Borrar Alumno(s)\n";
	
}

int validarOpcion(int op)
{
	do{
		if(op<1 || op>6){
			cout<<"\nIngrese un valor entre 1 y 6:\n ";
			cin>>op;
		}
	}while(op<1 || op>6);	
	return op;
}	


char decidirRepeticion()
{
	char rpt;
	do{
		cout<<"\n¿Desea repetir la ejecución? (s/n): ";
		cin>>rpt;
		if(rpt!='s'&&rpt!='n')
			cout<<"\tResponda solo con 's' o 'n'";
	}while(rpt!='s'&&rpt!='n');
	return rpt;
}




float validarNotas(float n)
{
	do
	{
		if (n<0 || n>20)
		{
			cout<<"Ingrese valores entre 0 y 20: ";
			cin>>n;
		}
	}while(n<0 || n>20);
	return n;	
}


float validarT1T2(float t1)
{
	const float porcentaje = 0.15;
	float r;
	r=(t1 * 0.15);
	return r;
}


float validarParcial(float parcial)
{
	const float porcentaje = 0.30;
	float r; 
	r=(parcial * 0.30);
	return r;
}

float validarFinal(float fin)
{
	const float porcentaje = 0.40;
	float r;
	r=(fin * 0.40);
	return r;
}

int validarAlumnosAprobados(int prom)
{
	if(prom>=12)
	{
		cout<<"\tEl Alumno esta Aprobado: "<<endl;
	}
	else
	{
	   cout<<"\tEl Alumno esta Desaprobado"<<endl;
	}
	return prom;
}




	
	





