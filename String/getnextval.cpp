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