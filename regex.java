// Paiyur Mohan, Balaji.
// bxp6836
// 2019-02-26

import java.nio.file.Paths;
import java.nio.file.Files;
import java.util.Arrays;
import java.util.regex.*;

public class hmwk_03 {
  public static void processToken( String token )
  {
    Pattern pattern1 = Pattern.compile("[0-9]+[)][(][0-9]+");
	Pattern pattern2 = Pattern.compile("[|][0-9A-Z]*[+]");
	Pattern pattern3 = Pattern.compile("[#][0-9r-wR-W]+");
	Matcher match1 = pattern1.matcher(token);
	Matcher match2 = pattern2.matcher(token);
	Matcher match3 = pattern3.matcher(token);
	if(match1.matches())
		System.out.println(">" + token + "< matches FP" );
	else if(match2.matches())
		System.out.println(">" + token + "< matches STR" );
	else if(match3.matches())
		System.out.println(">" + token + "< matches INT" );
	else
		System.out.println(">" + token + "< does not match" );
  }

  public static void main( String[] args )
  {
    System.out.println( "processing tokens from " + args[ 0 ] + " ..." );

    try {
      Files.lines( Paths.get( args[ 0 ] ) ).filter(line -> line.length() > 0).forEachOrdered(
        line -> Arrays.stream( line.split( "\\s+" )  )
            .forEachOrdered( token -> processToken( token ) ) );
    } catch ( java.io.IOException e ) {
      e.printStackTrace();
    }
  }
}
