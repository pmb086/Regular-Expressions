# Paiyur Mohan, Balaji.
# bxp6836
# 2019-02-26
#--------------------------------------------------
import re
import sys

#--------------------------------------------------
def processToken( token ) :
  reg1 = re.match('[0-9]+[)][(][0-9]+', token)
  reg2 = re.match('[|][0-9A-Z]*[+]', token)
  reg3 = re.match('[#][0-9r-wR-W]+', token)
  if reg1:
      print('>%s< match FP'% ( token ))
  elif reg2:
      print('>%s< match STR'% ( token ))  
  elif reg3:
      print('>%s< match INT'% ( token ))  
  else:
      print('>%s< does not match'% ( token ))

#--------------------------------------------------
def main() :
  fName = sys.argv[ 1 ]
  print( 'processing tokens from ' + fName + ' ...' )

  with open( fName, 'r' ) as fp :
    lines = fp.read().replace( '\r', '' ).split( '\n' )

  for line in lines :
    for token in line.split() :
      processToken( token )

#--------------------------------------------------
if ( __name__ == '__main__' ) :
  main()

#--------------------------------------------------
