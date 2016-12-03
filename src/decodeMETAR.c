#include <stdio.h>
#include "local.h"
#include "metar_structs.h"

int main(int ArgumentCount, char *ArgumentArray[])
{
    int ReturnCode; 
    Decoded_METAR Metar;
    Decoded_METAR *MetarPointer = &Metar;
   
    if (ArgumentCount < 2)
    {
      printf("Usage: %s \"<METAR>\"\n", ArgumentArray[0]);
      printf("   eg. %s \"CYRV 232351Z AUTO 15003KT 7SM -RA SCT040 OVC070 03/03 A2992 RMK SLP150\"\n", ArgumentArray[0]);
      return -1;
    }
   
    ReturnCode = decode_metar(ArgumentArray[1], MetarPointer);
    
    if (ReturnCode == 0)
      print_decoded_metar(MetarPointer);

    return 1;
}
