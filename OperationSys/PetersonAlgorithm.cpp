/***
Peterson Algorithm.
***/

boolean flag[2];
int turn = 0;
flag[0] = false; flag[1] = false;

void Po()
{
	while(true)
	{
		flag[0] = true;
		turn = 1;
		while(flag[1] && turn == 1);
		
		临界区
		
		flag[0] = false;
	}
}

void P1()
{
	while(true)
	{
		flag[1] = true;
		turn = 0;
		while(flag[0] && turn == 0);
		
		临界区
		
		flag[1] = false;
	}
}