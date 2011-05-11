#include <stdio.h>

void solve ( int money, int items, int *items_arr, int *itm1, int *itm2){
	int i,k;

	for(i = 0; i < items; i++){
		for(k = 0; k < items; k++) {
			if(items_arr[i] + items_arr[k] == money && i != k) {
				
				*itm1 = i+1;
				*itm2 = k+1;
				return;
			}
		}

	}
}


int main(int argc, char *argv[])
{
	
	int no_test_cases, i, k;
	int money, items, items_arr[2000];
	int itm1, itm2;
       
	if(argc != 1) {
		printf("Usage: cat   <in-file>  | %s > <out-file>  \n" , argv[0]);
		return;
	}

	fscanf(stdin, "%d\n", &no_test_cases);
	

	
	for(i = 0; i < no_test_cases; i++) {
		fscanf(stdin, "%d", &money);
		fscanf(stdin, "%d", &items);

		for(k = 0; k < items; k++) {
			fscanf(stdin, "%d", &items_arr[k]);

		}

		solve( money, items, items_arr, &itm1, &itm2 ); 
		printf("Case #%d: %d %d\n" , i+1, itm1, itm2);
		fprintf(stderr, "%d:%d + %d:%d = %d (%d)\n", itm1, items_arr[itm1-1], itm2, items_arr[itm2-1],money, items_arr[itm1-1] + items_arr[itm2-1]);
	}
	
	
	
}
