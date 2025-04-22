/*
Aristas = 14
Vertices = 9
1 2 6
1 7 8
1 4 10
2 3 11
2 8 13
2 5 15
3 8 4
4 5 6
5 6 2
6 7 4
6 9 6
7 9 5
7 8 5
8 9 7
*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <list>
#include<stdio.h>
#include<conio.h>

#define DEBUG
#define REP(i,a)  for(i=0;i<a;i++)
#define FOR(i,a,b) for(i=a;i<b;i++)
#define ii pair<int,int>

using namespace std;
vector<int> pset;
vector<pair<int,ii> >grafo;
void initSet(int size);
int findSet(int i);
void unionSet(int i,int j);
bool isSameSet(int i,int j);
void  kruskal(int N);
int main()
{
	int op, V;	
	do{
		printf("MENU\n");
		printf("1. Calcular un arbol de expansion minima del grafo \n");
		printf("2. Salir \n");
		printf("Opcion: ");
		scanf("%d",&op);
		switch(op)
		{
			case 1: 
			system("CLS");
			printf("Copiar el grafo conexo del primer comentario del programa \n");
			int V,A,i,a,b,w;
			cout<<"Num. de aristas"<<endl;
			cin>>A;
			cout<<"Num. de vertices"<<endl;
			cin>>V;
			cout<<"Insertar desde que vertice a que vertice: "<<endl;
			for(i=0;i<A;i++)
			{
				cout<<"Del vertice: "; cin>>a; cout<<"al vertice: ";cin>>b;
				cout<<"Peso: "; cin>>w;
				grafo.push_back(pair<int,ii>(w,ii(a,b)));
			}
            printf("\n");
            kruskal(V);
			printf("\n");
			system("PAUSE");
			break;			
		}
		system("CLS");
	}while(op != 2);
	system("PAUSE");
	return 0;
}

void initSet(int size)
{
    int i;
    pset.resize(size);
    REP(i,size+1)
    pset[i]=i;
}

int findSet(int i)
{
    return (pset[i]==i)? i:(pset[i]=findSet(pset[i]));
}

void unionSet(int i,int j)
{
    pset[findSet(i)]=findSet(j);
}

bool isSameSet(int i,int j)
{
    if(findSet(i) == findSet(j))
        return true;
    return false;
}

void  kruskal(int N)
{
	int sum=0,i;
	initSet(N);
	sort(grafo.begin(),grafo.end());
	for(i=0;i<grafo.size();i++)
	{      
		pair<int,ii>aux=grafo[i];
	    if(!isSameSet(aux.second.first,aux.second.second))
	    {    
			cout<<"Pasa en: "<<aux.second.first<<","<<aux.second.second<<endl;
	        sum=aux.first+sum;
	        unionSet(aux.second.first,aux.second.second);
	    }
	}
	cout<<"\nPeso:  "<<sum;
	printf("\n");
}
