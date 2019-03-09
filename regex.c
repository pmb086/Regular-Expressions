// Paiyur Mohan, Balaji.
// bxp6836
// 2019-03-02
// 40194F795

#include <ctype.h>
#include <regex.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *getToken( FILE *fp );
regex_t re1;
regex_t re2;
regex_t re3;

void processToken( char *token )
{
  char* pattern1 = "[0-9]+[)][(][0-9]+";
  char* pattern2 = "[|][0-9A-Z]*[+]";
  char* pattern3 = "[#][0-9r-wR-W]+";
  if(regcomp(&re1,pattern1, REG_EXTENDED|REG_NOSUB) == 0){
    int res1 = regexec(&re1, token, 0,NULL, 0);
	regfree(&re1);
	if(res1 == 0) 
	  printf( ">%s< matches FP.\n", token);  
	else if(regcomp(&re2,pattern2, REG_EXTENDED|REG_NOSUB) == 0){ 
		int res2 = regexec(&re2, token, 0,NULL, 0);
		regfree(&re2);
		if(res2 == 0) 
			printf( ">%s< matches STR.\n", token);  
		else if(regcomp(&re3,pattern3, REG_EXTENDED|REG_NOSUB) == 0) {
			int res3 = regexec(&re3, token, 0,NULL, 0);
			regfree(&re3);
			if(res3 == 0) 
				printf( ">%s< matches INT.\n", token);  
			else
				printf( ">%s< doesn't match.\n", token);
		}
	}
  }
  else if(regcomp(&re2,pattern2, REG_EXTENDED|REG_NOSUB) == 0) {
	int res2 = regexec(&re2, token, 0,NULL, 0);
	regfree(&re2);
	if(res2 == 0) 
		printf( ">%s< matches STR.\n", token);  
	else if(regcomp(&re3,pattern3, REG_EXTENDED|REG_NOSUB) == 0){ 
		int res3 = regexec(&re3, token, 0,NULL, 0);
		regfree(&re3);
		if(res3 == 0) 
			printf( ">%s< matches INT.\n", token); 
		}
	}
  else if(regcomp(&re3,pattern3, REG_EXTENDED|REG_NOSUB) == 0) {
	int res3 = regexec(&re3, token, 0,NULL, 0);
	regfree(&re3);
	if(res3 == 0) 
	  printf( ">%s< matches INT.\n", token);  
	else
	  printf( ">%s< doesn't match.\n", token);
		}
  else
	  printf( ">%s< doesn't match.\n", token);
		
}

int main( int argc, char *argv[] )
{
  // DO NOT CHANGE anything below this line!
  if ( argc > 1 ) {
    printf( "processing tokens from %s ...\n", argv[1] );

    FILE *fp = fopen( argv[1], "r" );
    char *token = NULL;

    if ( fp != NULL ) {
      while ( token = getToken( fp ) ) {
        processToken( token );
        free( token );
      }

      fclose( fp );
    } else {
      printf( "unable to open %s?\n", argv[1] );
    }
  } else {
    printf( "No input file specified.\n" );
  }
}

#define MAX_TOKEN_SIZE (1024)

char *getToken( FILE *fp )
{
  char token[ MAX_TOKEN_SIZE+1 ];
  int  i  = 0;

  while ( i < MAX_TOKEN_SIZE ) {
    int ch = fgetc( fp );

    if ( ch == EOF ) { break; }

    if ( isspace( ch ) ) {
      if ( i == 0 ) { continue; }
      break;
    }

    token[ i++ ] = ch;
  }

  if ( i == 0 ) { return NULL; }

  token[ i ] = '\0';

  return strdup( token );
}
