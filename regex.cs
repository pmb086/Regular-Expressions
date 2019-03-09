// Paiyur Mohan, Balaji.
// bxp6836
// 2019-02-26

using System;
using System.IO;
using System.Text.RegularExpressions;

public class hmwk_03
{
  static public void processToken( string token ) {
    Match match1 = Regex.Match(token, "[0-9]+[)][(][0-9]+");
	Match match2 = Regex.Match(token, "[|][0-9A-Z]*[+]");
	Match match3 = Regex.Match(token, "[#][0-9r-wR-W]+");
    if(match1.Success)
		Console.WriteLine(">" + token + "< matches FP" );
	else if(match2.Success)
		Console.WriteLine(">" + token + "< matches STR" );
	else if(match3.Success)
		Console.WriteLine(">" + token + "< matches INT" );
	else
		Console.WriteLine(">" + token + "< does not match" );
  }

  static public void Main( string[] args )
  {
    Console.WriteLine( "processing tokens from " + args[ 0 ] + " ..." );

    foreach ( string line in File.ReadAllLines( args[ 0 ] ) ) {
      foreach ( string token in line.Split( (char []) null, StringSplitOptions.RemoveEmptyEntries ) ) {
        processToken( token );
      }
    }
  }
}
