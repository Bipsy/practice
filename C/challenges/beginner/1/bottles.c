#include <stdio.h>
#include <stdlib.h>


int main(int argc, char** argv) {
	for (int i = atoi(argv[1]); i >= 0; i--) {
		switch (i) {
			case 0:			printf("No more bottles of beer on the wall, " 
									"no more bottles of beer.\nGo to the store "
									"and buy some more, 99 bottles of beer on "
									"the wall.\n");
							break; 	
			case 1:			printf("1 bottle of beer on the wall, " 
									"1 bottle of beer.\nTake one down pass it "
									"around, No more bottles of beer on the " 
									"wall.\n");
							break;
			case 2:			printf("%d bottles of beer on the wall, " 
									"%d bottles of beer.\nTake one down pass " 
									"it around, %d bottle of beer on "
									"the wall.\n", i, i, i-1);
							break;
			default:		printf("%d bottles of beer on the wall, " 
									"%d bottles of beer.\nTake one down pass "
									"it around, %d bottles of beer "
									"on the wall.\n", i, i, i-1);
		}
		printf("\n");
	} 
	return 0;
}
