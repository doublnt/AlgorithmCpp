void del(Str &str, int i, int j){
	if(i < str.length &&i >= 0 && j >= 0){
		for(int k =i+j;k<str.length; ++k){
			str.ch[k-j] = str.ch[k];
		}
		str.length -= (str.length -i<j?str.length-i:j);
		str.ch[str.length] = '\0';
	}
}

int index(Str str, Str subStr){
	int i =1, j =1, k=1,sum =0;
	while(i <= str.length){
		if(str.ch[i] == substr.ch[j]){
			++i;
			++j;
		}
		else{
			j =1;
			i = ++k;
		}
		if(j>substr.length){
			j =1;
			++sum;
		}
	}
	return sum;
}

void getNext(Str substr, int next[]){
	int i = 1, j = 0;
	next[1] = 0;
	while(i < substr.length){
		if(j == 0|| substr.ch[i] == substr.ch[j]){
			++i;
			++j;
		}
		next[i] = j;
	}else{
		j = next[j];
	}
}

void getnextval(Str substr, int nextval[]){
	int i =1, j =0;
	nextval[1]=0;
	while(i<substr.length){
		if(j ==0 || substr.ch[i] == substr.ch[j]){
			++i;
			++j;
			if(substr.ch[i]!=substr.ch[j])
			    nextval[i] = j;
			else
			    nextval[i] = nextval[j];
		}
		else
		{
		    j = nextval[j];	
		}
	}
}

int KMP(Str str, Str substr, int next[]){
	int i =1,j=1;
	while(i<=str.length && j <= substr.length){
		if(j == 0 || str.ch[i] == substr.ch[j]){
			++i;
			++j;
		}
		else
		    j = next[j];
	}
	if(j > substr.length)
	    return i - substr.length;
	else
	    return 0;
}














