/* Copyright (c) 2005 by The National Chengchi Univ. All Rights Reserved */

extern "C" {
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
}

#include <string.h>
#include <iostream>
#include <cassert>
#include "Card.h"
#include "SHPlayer.h"
#include "AnsiPrint.h"
#include "CardPattern.h"

using namespace std;


/**
 * Print my ID
 */
void
PrintMyID(const char* studId)
{
    char *str = new char[sizeof(studId) + 5];
    sprintf(str, "ID: %s", studId);
    AnsiPrint(str, yellow, red, true, true);
    cout << endl << endl;
    delete [] str;
}


/**
 * print the usage
 */
void
PrintUsage(const char* progName)
{
    assert(progName);
    cout << "Usage: " << progName << " [Seed] [ShowFirst(0/1)]" << endl;
}

int
main(int argc, char** argv)
{
    bool showFirst = false;
    long seed = 0;

    if( argc > 3 ) {
        PrintUsage(argv[0]);
        exit(-1);
    }
    if( argc == 3 ) {
        showFirst = atoi(argv[2]);      // the third argument shows the first card
    }
    if( argc > 1 ) {
        seed = atoi(argv[1]);
    }
    srand(seed);


    SHPlayer shplayer("Player");

    // put your code here
	
	Card wash[52];

	for(int i=0;i<52;i++){

		wash[i].pip=(i/4)+1;
		wash[i].suit=i%4;

	}

	for(int i=0;i<52;i++){

		Card temp;
		int num;

		num=(rand()%52);

		temp=wash[i];
		wash[i]=wash[num];
		wash[num]=temp;

	}

	for(int i=0;i<5;i++){

		shplayer.sortedCards[i]=wash[i];

	}


	for(int i=0;i<11;i++){
	for(int count=0;count<5;count++){

		char temp1[12];
		strcpy(temp1,card[wash[count].pip-1][i]);
	

		for(int j=0;j<12;j++){

			if(temp1[j]=='x'){

				if(wash[count].suit==0){
				
					temp1[j]='C';

				}


				if(wash[count].suit==1){
				
					temp1[j]='D';

				}



				if(wash[count].suit==2){
				
					temp1[j]='H';

				}


				if(wash[count].suit==3){
				
					temp1[j]='S';

				}
			}
		}

			if(count==0 && showFirst==0){

				for(int y=0;y<11;y++){

					char space[1];
				
					strcpy(space," ");
					AnsiPrint(space,black,white,false,false);
				}
			}
		    else if(wash[count].suit==0 || wash[count].suit==3){

				AnsiPrint(temp1,black,white,false,false);

			}
				
			else if(wash[count].suit==1 || wash[count].suit==2){

				AnsiPrint(temp1,red,white,false,false);

			}

		if(count!=4){	
		
			printf(" ");
		}
	}
	printf("\n");

	}


    int point;

	point=0;

		

	for(int i=0;i<5;i++){

		point=point+shplayer.sortedCards[i].pip;

	}

	
	if(shplayer.isStraightFlush()==true){

		printf("It's Straight flush\n");

	}

	else if(shplayer.isFourOfAKind()==true){

		printf("It's Four of a kind\n");

	}

	else if(shplayer.isFullHouse()==true){

		printf("It's Full house\n");

	}

	else if(shplayer.isFlush()==true){

		printf("It's Flush\n");

	}

	else if(shplayer.isStraight()==true){

		printf("It's Straight\n");

	}
	else if(shplayer.isThreeOfAKind()==true){

		printf("It's Three of a kind\n");

	}

	else if(shplayer.isTwoPair()==true){

		printf("It's Two pair\n");

	}

	else if(shplayer.isOnePair()==true){

		printf("It's One pair\n");

	}

	else

		printf("It's Other\n");

		
		

    printf("Total points: %d\n",point);



    PrintMyID("107703034");

    return 0;
}

