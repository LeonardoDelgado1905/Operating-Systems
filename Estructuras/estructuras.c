#include <stdlib.h>
#include <stdio.h>

struct vector{
	int len;
	int currentLen;
	int *elements;
} myVector;

void init(int len){
	myVector.len = len;
	myVector.elements = malloc(len*sizeof(int));
}

void add(int el){
	if(myVector.len==myVector.currentLen){
		int *aux = malloc(myVector.len*2*sizeof(int));
		for(int i = 0; i < myVector.len; i++){
			*(aux+i) = *(myVector.elements+i);
		}
		*(aux + myVector.currentLen) = el;
		myVector.len*=2;
		myVector.currentLen += 1;
		free(myVector.elements);
		myVector.elements = aux;
	}else{
		*(myVector.elements + myVector.currentLen) = el;
		myVector.currentLen+=1
	}
}

void pop_back(){
	if(myVector.currentLen == 0){
		return;
	}
	myVector.currentLen--;
}

int getEl(int idx){
	if(idx >= myVector.currentLen)
		return -1;
	return *(myVector.elements+idx);
}
int main(){
	
	return 0;
}
