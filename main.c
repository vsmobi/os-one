#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <math.h>
void swap(int * a, int * b)
{
	int tempt;
	tempt = *a;
	*a = *b;
	*b = tempt;
}
void msort(int * arr, int first, int last)
{
	int f = first, l = last, m = arr[(l+f)/2];
	
	do {
	while( arr[f] < m ) f++;
	while( arr[l] > m ) l--;
	if (f <= l)
	{
		if (l>f) swap(&arr[f], &arr[l]);
		f++;
		l--;
		
	}	
   } while (f <= l);
   
   if ( f < last) msort(arr, f, last);
	
if (first < l) msort(arr, first, l);

}


void main (int argc, char **argv)
{
	int b = 0, n = 10, a[n];

		for(b;b<9; b++)
	{
		scanf("%d", &a[b]);
	}
		msort(a,0,9);
		b =0;
	for(b;b<9; b++)
	{
		printf("%d ", a[b]);
	}
	return 0;
}
