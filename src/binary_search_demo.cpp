#include <stdio.h>
#include <time.h>
#include <stdint.h>
#include <exception>
#include <iostream>
#include "BST.h"

using namespace std;
using namespace myalgo;

#define MAX_ELEMENTS 10
int main()
{
	int key[MAX_ELEMENTS];
	int value[MAX_ELEMENTS];
	
	BST<int,int> t;
	
	srand(time(NULL));
	for(int i = 0; i < MAX_ELEMENTS ; i++ )
	{
		key[i] = rand()%100;
		value[i] = rand()%1000;
		cout << "["<<key[i] <<":"<<value[i] <<"]"<< endl;
		t.insert(key[i],value[i]);
	}
	
	t.print();
	
	for(int i = 0; i < MAX_ELEMENTS ; i++ )
	{
		cout << "getting ... "<<key[i] <<"->"<<t.find(key[i])<< endl;
	}
	
	for(int i = 0; i < MAX_ELEMENTS ; i++ )
	{
		cout << "deleting ... "<<key[i] <<endl;
		t.Delete(key[i]);
		t.print();
	}
	
	return 0;
}
