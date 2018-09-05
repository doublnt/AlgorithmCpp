#include<stdlib.h>
#include<iostream>

#define maxSize 100

using namespace std;

typedef struct{
	char str[maxSize+1];
	int length;
}Str;

typedef struct{
	char *ch;
	int length;
}DynamicStr;

int strassign(DynamicStr &str, char *ch);
int concat(DynamicStr &str, DynamicStr str1, DynamicStr str2);

int strassign(DynamicStr& str, char* ch){
	if(str.ch)
		free(str.ch);
	int len = 0;
	char *c = ch;
	while(*c){//count the string ch length
		++ len;
		++ c;
	}
	if(len == 0){
		str.ch = NULL;
		str.length = 0;
		return 1;
	}
	else{
		str.ch = (char*)malloc(sizeof(char)*(len+1));
		if(str.ch == NULL)
		    return 0;
		else{
			c = ch;
			for(int i = 0; i <= len; ++i, ++c)
			    str.ch[i] =* c;
			str.length = len;
			return 1;
		}
	}
}

int strcompare(DynamicStr s1, DynamicStr s2){
	for(int i=0;i<s1.length && i < s2.length;++i){
		if(s1.ch[i] != s2.ch[i])
		    return s1.ch[i] - s2.ch[i];
	}
	return s1.length - s2.length;
}

int concat(DynamicStr &str, DynamicStr str1, DynamicStr str2){
	if(str.ch){
		free(str.ch);
		str.ch = NULL; 
	}
	str.ch = (char*)malloc(sizeof(char)*(str1.length + str2.length + 1));// +1ÊÇÎªÁË '\0' 
	if(str.ch == NULL)
	    return 0;
	int i = 0;
	while(i < str1.length){
		str.ch[i] = str1.ch[i];
		++i;
	}
	int j =0;
	while(j <= str2.length){
		str.ch[i+j] = str2.ch[j];
		++j;
	}
	str.length = str1.length + str2.length;
	return 1;
}

int subString(DynamicStr &substr, DynamicStr str, int pos, int len){
	if(pos < 0 || pos >= str.length || len < 0 || len > str.length-pos){
		return 0;
	}
	if(substr.ch){
		free(substr.ch);
		substr.ch = NULL;
	}
	if(len == 0){
		substr.ch = NULL;
		substr.length = 0;
		return 1;
	}
	else{
		substr.ch = (char*)malloc(sizeof(char)*(len+1));
		int i = pos;
		int j = 0;
		while(i < pos + len){
			substr.ch[j] = str.ch[i];
			++i;
			++j;
		}
		substr.ch[j] = '\0';
		substr.length = len;
		return 1;
	}
}

int main(){
	DynamicStr str,str1,str2;
	strassign(str,"cur input");
	strassign(str1,"robert is the most handsome boy");
	strassign(str2,"alougth he has some bad habit that he proves delighted to help others");
	
	concat(str,str1,str2); 
	for(int i = 0;i<str.length; ++i){
		cout << str.ch[i] << "";
	}
	cout << "\nThe length is \t" << str.length << endl;
}

