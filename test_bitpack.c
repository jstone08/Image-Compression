#include <stdbool.h>
#include <stdint.h>
#include "bitpack.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>



/*
 * Name: Hazen Breen & Jordan Stone
 *
 * Purpose: This file is a testing routine to test the functionality
 * 	    of our bitpacking and bit manipulation techniques.
 */
int main ()
{
	fprintf(stderr, "Starting testing file: use_bitpack.c \n");

	uint64_t u_corner1 = 15;
	uint64_t u_corner2 = 16;

	int64_t s_corner1 = -15;
	int64_t s_corner2 = -16;

	unsigned width = 4;

	///////////////////////////  test: Bitpack_fitsu with width: 4   //////////////////////////
	if ((Bitpack_fitsu(u_corner1, width) == true) && (Bitpack_fitsu(u_corner2, width) == false)) {
		fprintf(stderr, "Bitpack_fitsu passed. \n");
	} else {
		fprintf(stderr, "Bitpack_fitsu failed. \n");
	}


	///////////////////////////  test: Bitpack_fitss with width: 5   //////////////////////////
	width = 5;
	if ((Bitpack_fitss(s_corner1, width) == true) && (Bitpack_fitss(s_corner2, width) == false)) {
		fprintf(stderr, "Bitpack_fitss test 1: passed. \n");
	} else {
		fprintf(stderr, "Bitpack_fitss test 1: failed. \n");
	}

	
	///////////////////////////  test: Bitpack_fitss with width: 5   //////////////////////////
	s_corner1 = 15;
	s_corner2 = 16;

	if ((Bitpack_fitss(s_corner1, 5) == true) && (Bitpack_fitss(s_corner2, 5) == false)) {
		fprintf(stderr, "Bitpack_fitss test 2: passed. \n");
	} else {
		fprintf(stderr, "Bitpack_fitss test 2: failed. \n");
	}


	///////////////////////////  test: Bitpack_fitss with width: 0   //////////////////////////
	width = 0;
	if ((Bitpack_fitss(s_corner1, width) != true)) {
		fprintf(stderr, "Bitpack_fitss test 3: passed. \n");
	} else {
		fprintf(stderr, "Bitpack_fitss test 3: failed. \n");
	}


	///////////////////////////  test: Bitpack_fitsu with width: 0   //////////////////////////
	width = 0;
	if ((Bitpack_fitsu(u_corner1, width) != true)) {
		fprintf(stderr, "Bitpack_fitsu test 4: passed. \n");
	} else {
		fprintf(stderr, "Bitpack_fitsu test 4: failed. \n");
	}



	///////////////////////////  test: Bitpack_fitsu with width: 1   //////////////////////////
	u_corner1 = 1;
	u_corner2 = 0;
	width = 1;

	if ((Bitpack_fitsu(u_corner1, width) == true) && (Bitpack_fitsu(u_corner2, width) == true)) {
		fprintf(stderr, "Bitpack_fitsu test 5: passed. \n");
	} else {
		fprintf(stderr, "Bitpack_fitsu test 5: failed. \n");
	}


	///////////////////////////  test: Bitpack_fitss with width: 1   //////////////////////////
	s_corner1 = 1;
	s_corner2 = 0;
	width = 1;
	if ((Bitpack_fitss(s_corner1, width) == false) && (Bitpack_fitss(s_corner2, width) == false)) {
		fprintf(stderr, "Bitpack_fitss test 6: passed. \n");
	} else {
		fprintf(stderr, "Bitpack_fitss test 6: failed. \n");
	}



	///////////////////////////  test: Bitpack_fitsu with width: 32   //////////////////////////
	u_corner1 = 4294967295;
	u_corner2 = 4294967296;
	width = 32;

	if ((Bitpack_fitsu(u_corner1, width) == true) && (Bitpack_fitsu(u_corner2, width) == false)) {
		fprintf(stderr, "Bitpack_fitsu test 7: passed. \n");
	} else {
		fprintf(stderr, "Bitpack_fitsu test 7: failed. \n");
	}


	///////////////////////////  test: Bitpack_fitss with width: 32   //////////////////////////
	s_corner1 = 4294967295;
	s_corner2 = 4294967296;
	width = 32;
	if ((Bitpack_fitss(s_corner1, width) == false) && (Bitpack_fitss(s_corner2, width) == false)) {
		fprintf(stderr, "Bitpack_fitss test 8: passed. \n");
	} else {
		fprintf(stderr, "Bitpack_fitss test 8: failed. \n");
	}

	///////////////////////////  test: Bitpack_fitsu with width: 2   //////////////////////////
	u_corner1 = 3;
	u_corner2 = 476;
	width = 2;

	if ((Bitpack_fitsu(u_corner1, width) == true) && (Bitpack_fitsu(u_corner2, width) == false)) {
		fprintf(stderr, "Bitpack_fitsu test 9: passed. \n");
	} else {
		fprintf(stderr, "Bitpack_fitsu test 9: failed. \n");
	}


	///////////////////////////  test: Bitpack_fitss with width: 2   //////////////////////////
	s_corner1 = 1;
	s_corner2 = 476;
	width = 2;
	if ((Bitpack_fitss(s_corner1, width) == true) && (Bitpack_fitss(s_corner2, width) == false)) {
		fprintf(stderr, "Bitpack_fitss test 10: passed. \n");
	} else {
		fprintf(stderr, "Bitpack_fitss test 10: failed. \n");
	}

	///////////////////////////  test: Bitpack_fitsu with width: 2   //////////////////////////
	u_corner1 = 3;
	u_corner2 = 476;
	width = 64;

	if ((Bitpack_fitsu(u_corner1, width) == true) && (Bitpack_fitsu(u_corner2, width) == true)) {
		fprintf(stderr, "Bitpack_fitsu test 11: passed. \n");
	} else {
		fprintf(stderr, "Bitpack_fitsu test 11: failed. \n");
	}

fprintf(stderr, "arith specific tests beginning.....\n");


///////////////////////////////////////////////////////////////////////////
/////////////////////////////// test Bitpack_news ////////////////////////
//////////////////////////////////////////////////////////////////////////
TRY


	uint64_t MAX_VAL = 4294967296; //translate word fields to vals

	uint64_t word;
	int64_t value;
	unsigned lsb;


	word = 0;

	width = 5;
	value = -15;
	lsb = 0;
	word = Bitpack_news(word, width, lsb, value);

	if (word > MAX_VAL) {
		fprintf(stderr, "SIGNED: WARNING: Exceeds 32 bits\n" );
		exit(EXIT_FAILURE);
	}


	fprintf(stderr, "SIGNED: Returned word is: %lu \n", word );

	//word = 0;

	width = 5;
	value = -4;
	lsb = 5;

	word = Bitpack_news(word, width, lsb, value);
	
	if (word > MAX_VAL) {
		fprintf(stderr, "SIGNED: WARNING: Exceeds 32 bits\n" );
		exit(EXIT_FAILURE);
	}
	

	fprintf(stderr, "SIGNED: Returned word is: %lu \n", word );


///////////////////////////////////////////////////////////////////////////
/////////////////////////////// test get_u ////////////////////////
//////////////////////////////////////////////////////////////////////////

	int64_t got_bits_u;
	got_bits_u = Bitpack_gets(word,  5,  0);



	fprintf(stderr, "GET: Returned bits is: %ld \n", got_bits_u );

///////////////////////////////////////////////////////////////////////////
/////////////////////////////// test get_s ////////////////////////
//////////////////////////////////////////////////////////////////////////


	int64_t got_bits_s;
	got_bits_s = Bitpack_gets(word,  5,  5);



	fprintf(stderr, "GET: Returned bits is: %ld \n", got_bits_s );







EXCEPT(Bitpack_Overflow)
	fprintf(stderr, "UNSIGNED: Exited becuase Bitpack_Overflow was raised\n");
	exit(EXIT_FAILURE);


END_TRY;
	return 0;

}

