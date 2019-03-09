// Paiyur Mohan, Balaji.
// bxp6836
// 2019-03-02
// 40194F795

#include <fstream>
#include <iostream>
#include <regex>

using namespace std;

void processToken( string token )
{
  regex pattern1("[0-9]+[)][(][0-9]+");
  regex pattern2("[|][0-9A-Z]*[+]");
  regex pattern3("[#][0-9r-wR-W]+");
  if ( regex_match(token, pattern1) )
	cout<< ">" << token << "< matches FP.\n";
  else if ( regex_match(token, pattern2) )
	cout<<">" << token << "< matches STR.\n"; 
  else if ( regex_match(token, pattern3) )
	cout<<">" << token << "< matches INT.\n";
  else
	cout<<">" << token << "< doesn't match.\n";
}

int main( int argc, char *argv[] )
{
  if ( argc > 1 ) {
    cout << "processing tokens from " << argv[ 1 ] << " ...\n";

    ifstream inputFile;
    string   token;
    inputFile.open( argv[ 1 ] );

    if ( inputFile.is_open() ) {
      while ( inputFile >> token ) {
        processToken( token );
      }
      inputFile.close();
    } else {
      cout << "unable to open " << argv[ 1 ] << "?\n";
    }
  } else {
    cout << "No input file specified.\n";
  }
}
