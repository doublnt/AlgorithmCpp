#include<stdlib.h>
#define maxSize 50
#include<iostream>

using namespace std;

typedef struct {
    int elem[maxSize];
    int top[2];
} SqStack;

int push(SqStack &st, int stNo, int x) {
    if(st.top[0] + 1 < st.top[1]) {
        if(stNo == 0) {
            ++(st.top[0]);
            st.elem[st.top[0]] = x;
            return 1;
        } else if(stNo == 1) {
            --(st.top[1]);
            st.elem[st.top[1]] = x;
            return 1;
        } else return -1;
    } else return 0;
}

int pop(SqStack &st, int stNo. int &x){
	if(stNo == 0){
		if(st.top[0] != -1)
		{
			x = st.elem[st.top[0]];
			--(st.top[0]]);
			return 1;
		}
		else return 0;
	}else if(stN0 == 1){
		if(st.top[1] != maxSize){
			x = st.elem[st.top[1]];
			++(st.top[1]);
			return 1;
		}
		else return 0;
	}
	else return -1;
}





