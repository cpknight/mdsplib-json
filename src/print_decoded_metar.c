/*
METAR Decoder Software Package Library: Parses Aviation Routine Weather Reports
Copyright (C) 2003  Eric McCarthy

This library is free software; you can redistribute it and/or
modify it under the terms of the GNU Lesser General Public
License as published by the Free Software Foundation; either
version 2.1 of the License, or (at your option) any later version.

This library is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public
License along with this library; if not, write to the Free Software
Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
*/

#include "metar_structs.h"

/* NB this is pretty insecure insofar as it blindly writes into string
 * on the assuption that string can fit it all 
 * */

void sprintf_tornadic_info (char * string, Decoded_METAR *Mptr) {
   char temp[100];
 
   if ( Mptr->TornadicType[0] != '\0' ) {
      sprintf(temp, "  \"TORNADIC ACTVTY TYPE: \"%s\",\n",
         Mptr->TornadicType );
      strcat(string, temp);
   }
 
   if ( Mptr->BTornadicHour != MAXINT ) {
      sprintf(temp, "  \"TORN. ACTVTY BEGHOUR: %d,\n",
         Mptr->BTornadicHour );
      strcat(string, temp);
   }
 
   if ( Mptr->BTornadicMinute != MAXINT ) {
      sprintf(temp, "  \"TORN. ACTVTY BEGMIN : %d,\n",
         Mptr->BTornadicMinute );
      strcat(string, temp);
   }
 
   if ( Mptr->ETornadicHour != MAXINT ) {
      sprintf(temp, "  \"TORN. ACTVTY ENDHOUR: %d,\n",
         Mptr->ETornadicHour );
      strcat(string, temp);
   }
 
   if ( Mptr->ETornadicMinute != MAXINT ) {
      sprintf(temp, "  \"TORN. ACTVTY ENDMIN : %d,\n",
         Mptr->ETornadicMinute );
      strcat(string, temp);
   }
 
   if ( Mptr->TornadicDistance != MAXINT ) {
      sprintf(temp, "  \"TORN. DIST. FROM STN: %d,\n",
         Mptr->TornadicDistance );
      strcat(string, temp);
   }
 
   if ( Mptr->TornadicLOC[0] != '\0' ) {
      sprintf(temp, "  \"TORNADIC LOCATION   : \"%s\",\n",
         Mptr->TornadicLOC );
      strcat(string, temp);
   }
 
   if ( Mptr->TornadicDIR[0] != '\0' ) {
      sprintf(temp, "  \"TORNAD. DIR FROM STN: \"%s\",\n",
         Mptr->TornadicDIR );
      strcat(string, temp);
   }
 
   if ( Mptr->TornadicMovDir[0] != '\0' ) {
      sprintf(temp, "  \"TORNADO DIR OF MOVM.: \"%s\",\n",
         Mptr->TornadicMovDir );
      strcat(string, temp);
   }
}
 

void sprint_metar (char * string, Decoded_METAR *Mptr)
{
   int i;
   char temp[100];
 
   sprintf(string, "{\n");

   if ( Mptr->codeName[ 0 ] != '\0' ) {
      sprintf(temp, "  \"  \"ReportCodeName\": \"%s\",\n",Mptr->codeName);
      strcat(string, temp);
   }
 
   if ( Mptr->stnid[ 0 ] != '\0' ) {
      sprintf(temp, "  \"StationID\": \"%s\",\n",Mptr->stnid);
      strcat(string, temp);
   }
 
   if ( Mptr->ob_date != MAXINT ) {
      sprintf(temp, "  \"ObservationDay\": %d,\n",Mptr->ob_date);
      strcat(string, temp);
   }
 
   if ( Mptr->ob_hour != MAXINT ) {
      sprintf(temp, "  \"ObservationHour\": %d,\n",Mptr->ob_hour);
      strcat(string, temp);
   }
 
   if ( Mptr->ob_minute != MAXINT ) {
      sprintf(temp, "  \"ObservationMinute\": %d,\n",Mptr->ob_minute);
      strcat(string, temp);
   }
 
   if ( Mptr->NIL_rpt ) {
      sprintf(temp, "  \"NilReport\": \"true,\n");
      strcat(string, temp);
   }
 
   if ( Mptr->AUTO ) {
      sprintf(temp, "  \"AutoReport\": true,\n");
      strcat(string, temp);
   }
 
   if ( Mptr->COR ) {
      sprintf(temp, "  \"CorrectedReport\": true,\n");
      strcat(string, temp);
   }
 
   if ( Mptr->winData.windVRB ) {
      sprintf(temp, "  \"WindDirectionVariable\": true,\n");
      strcat(string, temp);
   }
 
   if ( Mptr->winData.windDir != MAXINT ) {
      sprintf(temp, "  \"WindDirection\": %d,\n",Mptr->winData.windDir);
      strcat(string, temp);
   }
 
   if ( Mptr->winData.windSpeed != MAXINT ) {
      sprintf(temp, "  \"WindSpeed\": %d,\n",Mptr->winData.windSpeed);
      strcat(string, temp);
   }
 
   if ( Mptr->winData.windGust != MAXINT ) {
      sprintf(temp, "  \"WindGust\": %d,\n",Mptr->winData.windGust);
      strcat(string, temp);
   }
 
   if ( Mptr->winData.windUnits[ 0 ] != '\0' ) {
      sprintf(temp, "  \"WindUnits\": \"%s\",\n",Mptr->winData.windUnits);
      strcat(string, temp);
   }
 
   if ( Mptr->minWnDir != MAXINT ) {
      sprintf(temp, "  \"WindDirectionMinimum\": %d,\n",Mptr->minWnDir);
      strcat(string, temp);
   }
 
   if ( Mptr->maxWnDir != MAXINT ) {
      sprintf(temp, "  \"WindDirectionMaximum\": %d,\n",Mptr->maxWnDir);
      strcat(string, temp);
   }
 
   if ( Mptr->prevail_vsbyM != (float) MAXINT ) {
      sprintf(temp, "  \"PrevailingVisibilityMiles\": %f,\n",Mptr->prevail_vsbyM);
      strcat(string, temp);
   }
 
   if ( Mptr->prevail_vsbyKM != (float) MAXINT ) {
      sprintf(temp, "  \"PrevailingVisibilityKilometres\": %f,\n",Mptr->prevail_vsbyKM);
      strcat(string, temp);
   }
 
   if ( Mptr->prevail_vsbySM != (float) MAXINT ) {
      sprintf(temp, "  \"PrevailingVisibilityStatuteMiles\": %.3f,\n",Mptr->prevail_vsbySM);
      strcat(string, temp);
   }
/*
   if ( Mptr->charPrevailVsby[0] != '\0' ) {
      sprintf(temp, "  \"PrevailingVisibilityCharacters\": \"%s\",\n",Mptr->charPrevailVsby);
      strcat(string, temp);
   }
*/
   if ( Mptr->vsby_Dir[ 0 ] != '\0' ) {
      sprintf(temp, "  \"VisibilityDirection\": \"%s\",\n",Mptr->vsby_Dir);
      strcat(string, temp);
   }
 
   if ( Mptr->RVRNO ) {
      sprintf(temp, "  \"RVRNO               : true,\n");
      strcat(string, temp);
   }
 
   for ( i = 0; i < MAX_RUNWAYS; i++ )
   {
      if( Mptr->RRVR[i].runway_designator[0] != '\0' ) {
         sprintf(temp, "  \"RUNWAY DESIGNATOR   : \"%s\",\n",
                 Mptr->RRVR[i].runway_designator);
         strcat(string, temp);
      }
 
      if( Mptr->RRVR[i].visRange != MAXINT ) {
         sprintf(temp, "  \"RunwayVisualRangeFeet\": %d,\n",
                 Mptr->RRVR[i].visRange);
         strcat(string, temp);
      }
 
      if ( Mptr->RRVR[i].vrbl_visRange ) {
         sprintf(temp, "  \"VisualRangeVerbal\": true,\n");
         strcat(string, temp);
      }
 
      if ( Mptr->RRVR[i].below_min_RVR ) {
         sprintf(temp, "  \"BelowMinimumRVR\": true,\n");
         strcat(string, temp);
      }
 
      if ( Mptr->RRVR[i].above_max_RVR ) {
         sprintf(temp, "  \"AboveMaximumRVR\": true,\n");
         strcat(string, temp);
      }
 
      if( Mptr->RRVR[i].Max_visRange != MAXINT ) {
         sprintf(temp, "  \"RunwayVisualRangeMaximumFeet\": %d,\n",
                 Mptr->RRVR[i].Max_visRange);
         strcat(string, temp);
      }
 
      if( Mptr->RRVR[i].Min_visRange != MAXINT ) {
         sprintf(temp, "  \"RunwayVisualRangeMinimumFeet\": %d,\n",
                 Mptr->RRVR[i].Min_visRange);
         strcat(string, temp);
      }
 
   }
 
 
   if( Mptr->DVR.visRange != MAXINT ) {
      sprintf(temp, "  \"DispatchVisualRange\": %d,\n",
              Mptr->DVR.visRange);
      strcat(string, temp);
   }
 
   if ( Mptr->DVR.vrbl_visRange ) {
      sprintf(temp, "  \"DispatchVisualRangeVerbal\": true,\n");
      strcat(string, temp);
   }
 
   if ( Mptr->DVR.below_min_DVR ) {
      sprintf(temp, "  \"DispatchVisualRangeBelowMinimum\": true,\n");
      strcat(string, temp);
   }
 
   if ( Mptr->DVR.above_max_DVR ) {
      sprintf(temp, "  \"DispatchVisualRangeAboveMaximum\": true,\n");
      strcat(string, temp);
   }
 
   if( Mptr->DVR.Max_visRange != MAXINT ) {
      sprintf(temp, "  \"DispatchVisualRangeMaximumFeet\": %d,\n",
              Mptr->DVR.Max_visRange);
      strcat(string, temp);
   }
 
   if( Mptr->DVR.Min_visRange != MAXINT ) {
      sprintf(temp, "  \"DispatchVisualRangeMinimumFeet\": %d,\n",
              Mptr->DVR.Min_visRange);
      strcat(string, temp);
   }
 
   for (i = 0; Mptr->WxObstruct[i][0] != '\0' && i < MAXWXSYMBOLS; i++)
   {
      sprintf(temp, "  \"WeatherObstructionVision\": \"%s\",\n",
         Mptr->WxObstruct[i] );
      strcat(string, temp);
   }

   for (i = 0; i < MAX_PARTIAL_OBSCURATIONS; i++) {
       if ( Mptr->PartialObscurationAmt[i][0] != '\0' ) {
	  sprintf(temp, "  \"ObscurationAmount\": \"%s\",\n",
		Mptr->PartialObscurationAmt[i]);
	  strcat(string, temp);
       }
     
       if ( Mptr->PartialObscurationPhenom[i][0] != '\0' ) {
	  sprintf(temp, "  \"ObscurationPhenomenon\": \"%s\",\n",
		Mptr->PartialObscurationPhenom[i]);
	  strcat(string, temp);
       }
    }
 
   sprintf(temp, "  \"CloudLayers\": [\n"); 
   strcat(string, temp);
 
   for (i = 0;  Mptr->cloudGroup[ i ].cloud_type[0] != '\0' &&
                     i < MAX_CLOUD_GROUPS; i++ )
   {
     sprintf(temp, "    {\n"); 
     strcat(string, temp);
     
      if ( Mptr->cloudGroup[ i ].cloud_type[0] != '\0' ) {
         sprintf(temp, "      \"CloudCover\": \"%s\",\n",
            Mptr->cloudGroup[ i ].cloud_type);
         strcat(string, temp);
      }
 
      if ( Mptr->cloudGroup[ i ].cloud_hgt_char[0] != '\0' ) {
         sprintf(temp, "      \"CloudHeightCharacters\": \"%s\",\n",
            Mptr->cloudGroup[ i ].cloud_hgt_char);
         strcat(string, temp);
      }
 
      if ( Mptr->cloudGroup[ i ].cloud_hgt_meters != MAXINT) {
         sprintf(temp, "      \"CloudHeightMetres\": %d,\n",
            Mptr->cloudGroup[ i ].cloud_hgt_meters);
         strcat(string, temp);
      }
 
      if ( Mptr->cloudGroup[ i ].other_cld_phenom[0] != '\0' ) {
         sprintf(temp, "      \"OtherCloudPhenomenon\": \"%s\",\n",
            Mptr->cloudGroup[ i ].other_cld_phenom);
         strcat(string, temp);
      }

     string[strlen(string) - 2] = '\0'; // remove trailing comma and newline
     sprintf(temp, "\n    },\n"); 
     strcat(string, temp);
   }

   if (i > 0)
     string[strlen(string) - 2] = '\0'; // remove trailing comma and newline

   sprintf(temp, "\n  ],\n"); 
   strcat(string, temp);
   
   sprintf(temp, "  \"CloudLayerCount\": %i,\n", i); 
   strcat(string, temp);
 
   if ( Mptr->temp != MAXINT ) {
      sprintf(temp, "  \"TemperatureCelsius\": %d,\n", Mptr->temp);
      strcat(string, temp);
   }
 
   if ( Mptr->dew_pt_temp != MAXINT ) {
      sprintf(temp, "  \"DewpointTemperatureCelsius\": %d,\n", Mptr->dew_pt_temp);
      strcat(string, temp);
   }
 
   if ( Mptr->A_altstng ) {
      sprintf(temp, "  \"AltimeterInchesHg\": %.2f,\n",
         Mptr->inches_altstng );
      strcat(string, temp);
   }
 
   if ( Mptr->Q_altstng ) {
      sprintf(temp, "  \"AltimiterPascals\": %d,\n",
         Mptr->hectoPasc_altstng );
      strcat(string, temp);
   }

    sprintf_tornadic_info (string, Mptr);

   if ( Mptr->autoIndicator[0] != '\0' ) {
         sprintf(temp, "  \"AutomaticIndicator\": \"%s\",\n",
                          Mptr->autoIndicator);
      strcat(string, temp);
   }
 
   if ( Mptr->PKWND_dir !=  MAXINT ) {
      sprintf(temp, "  \"PeakWindDirection\": %d,\n",Mptr->PKWND_dir);
      strcat(string, temp);
   }
   if ( Mptr->PKWND_speed !=  MAXINT ) {
      sprintf(temp, "  \"PeakWindSpeed\": %d,\n",Mptr->PKWND_speed);
      strcat(string, temp);
   }
   if ( Mptr->PKWND_hour !=  MAXINT ) {
      sprintf(temp, "  \"PeakWindHour\": %d,\n",Mptr->PKWND_hour);
      strcat(string, temp);
   }
   if ( Mptr->PKWND_minute !=  MAXINT ) {
      sprintf(temp, "  \"PeakWindMinute\": %d,\n",Mptr->PKWND_minute);
      strcat(string, temp);
   }
 
   if ( Mptr->WshfTime_hour != MAXINT ) {
      sprintf(temp, "  \"HOUR OF WIND SHIFT\": %d,\n",Mptr->WshfTime_hour);
      strcat(string, temp);
   }
   if ( Mptr->WshfTime_minute != MAXINT ) {
      sprintf(temp, "  \"MINUTE OF WIND SHIFT\": %d,\n",Mptr->WshfTime_minute);
      strcat(string, temp);
   }
   if ( Mptr->Wshft_FROPA != FALSE ) {
      sprintf(temp, "  \"FROPA ASSOC. W/WSHFT\": true,\n");
      strcat(string, temp);
   }
 
   if ( Mptr->TWR_VSBY != (float) MAXINT ) {
      sprintf(temp, "  \"TOWER VISIBILITY\": %.2f,\n",Mptr->TWR_VSBY);
      strcat(string, temp);
   }
   if ( Mptr->SFC_VSBY != (float) MAXINT ) {
      sprintf(temp, "  \"SURFACE VISIBILITY\": %.2f,\n",Mptr->SFC_VSBY);
      strcat(string, temp);
   }
 
   if ( Mptr->minVsby != (float) MAXINT ) {
      sprintf(temp, "  \"MIN VRBL_VIS (SM)\": %.4f,\n",Mptr->minVsby);
      strcat(string, temp);
   }
   if ( Mptr->maxVsby != (float) MAXINT ) {
      sprintf(temp, "  \"MAX VRBL_VIS (SM)\": %.4f,\n",Mptr->maxVsby);
      strcat(string, temp);
   }
 
   if( Mptr->VSBY_2ndSite != (float) MAXINT ) {
      sprintf(temp, "  \"VSBY_2ndSite (SM)\": %.4f,\n",Mptr->VSBY_2ndSite);
      strcat(string, temp);
   }
   
   if( Mptr->VSBY_2ndSite_LOC[0] != '\0' ) {
      sprintf(temp, "  \"VSBY_2ndSite LOC.\": \"%s\",\n",
                   Mptr->VSBY_2ndSite_LOC);
      strcat(string, temp);
   }
 
   if ( Mptr->OCNL_LTG ) {
      sprintf(temp, "  \"OCCASSIONAL LTG\": true,\n");
      strcat(string, temp);
   }
 
   if ( Mptr->FRQ_LTG ) {
      sprintf(temp, "  \"FREQUENT LIGHTNING\": true,\n");
      strcat(string, temp);
   }
 
   if ( Mptr->CNS_LTG ) {
      sprintf(temp, "  \"CONTINUOUS LTG\": true,\n");
      strcat(string, temp);
   }
 
   if ( Mptr->CG_LTG ) {
      sprintf(temp, "  \"CLOUD-GROUND LTG\": true,\n");
      strcat(string, temp);
   }
 
   if ( Mptr->IC_LTG ) {
      sprintf(temp, "  \"IN-CLOUD LIGHTNING\": true,\n");
      strcat(string, temp);
   }
 
   if ( Mptr->CC_LTG ) {
      sprintf(temp, "  \"CLD-CLD LIGHTNING\": true,\n");
      strcat(string, temp);
   }
 
   if ( Mptr->CA_LTG ) {
      sprintf(temp, "  \"CLOUD-AIR LIGHTNING\": true,\n");
      strcat(string, temp);
   }
 
   if ( Mptr->AP_LTG ) {
      sprintf(temp, "  \"LIGHTNING AT AIRPORT\": true,\n");
      strcat(string, temp);
   }
 
   if ( Mptr->OVHD_LTG ) {
      sprintf(temp, "  \"LIGHTNING OVERHEAD\": true,\n");
      strcat(string, temp);
   }
 
   if ( Mptr->DSNT_LTG ) {
      sprintf(temp, "  \"DISTANT LIGHTNING\": true,\n");
      strcat(string, temp);
   }
 
   if ( Mptr->LightningVCTS ) {
      sprintf(temp, "  \"L'NING W/I 5-10(ALP)\": true,\n");
      strcat(string, temp);
   }
 
   if ( Mptr->LightningTS ) {
      sprintf(temp, "  \"L'NING W/I 5 (ALP)\": true,\n");
      strcat(string, temp);
   }
 
   if ( Mptr->VcyStn_LTG ) {
      sprintf(temp, "  \"VCY STN LIGHTNING\": true,\n");
      strcat(string, temp);
   }
 
   if ( Mptr->LTG_DIR[0] != '\0' ) {
      sprintf(temp, "  \"DIREC. OF LIGHTNING\": \"%s\",\n", Mptr->LTG_DIR);
      strcat(string, temp);
   }
 
 
 
   i = 0;
   while( i < 3 && Mptr->ReWx[ i ].Recent_weather[0] != '\0' )
   {
      sprintf(temp, "  \"RECENT WEATHER\": %s",
                  Mptr->ReWx[i].Recent_weather);
      strcat(string, temp);
 
      if ( Mptr->ReWx[i].Bhh != MAXINT ) {
         sprintf(temp, "  \" BEG_hh = %d",Mptr->ReWx[i].Bhh);
         strcat(string, temp);
      }
      if ( Mptr->ReWx[i].Bmm != MAXINT ) {
         sprintf(temp, "  \" BEG_mm = %d",Mptr->ReWx[i].Bmm);
         strcat(string, temp);
      }
 
      if ( Mptr->ReWx[i].Ehh != MAXINT ) {
         sprintf(temp, "  \" END_hh = %d",Mptr->ReWx[i].Ehh);
         strcat(string, temp);
      }
      if ( Mptr->ReWx[i].Emm != MAXINT ) {
         sprintf(temp, "  \" END_mm = %d",Mptr->ReWx[i].Emm);
         strcat(string, temp);
      }
 
      strcat(string, "\n");
 
      i++;
   }
 
   if ( Mptr->minCeiling != MAXINT ) {
      sprintf(temp, "  \"MIN VRBL_CIG (FT)\": %d,\n",Mptr->minCeiling);
      strcat(string, temp);
   }
   if ( Mptr->maxCeiling != MAXINT ) {
      sprintf(temp, "  \"MAX VRBL_CIG (FT))\": %d,\n",Mptr->maxCeiling);
      strcat(string, temp);
   }
 
   if ( Mptr->CIG_2ndSite_Meters != MAXINT ) {
      sprintf(temp, "  \"CIG2ndSite (FT)\": %d,\n",Mptr->CIG_2ndSite_Meters);
      strcat(string, temp);
   }
   if ( Mptr->CIG_2ndSite_LOC[0] != '\0' ) {
      sprintf(temp, "  \"CIG @ 2nd Site LOC.\": \"%s\",\n",Mptr->CIG_2ndSite_LOC);
      strcat(string, temp);
   }
 
   if ( Mptr->PRESFR ) {
      sprintf(temp, "  \"PRESFR\": true,\n");
      strcat(string, temp);
   }
   if ( Mptr->PRESRR ) {
      sprintf(temp, "  \"PRESRR\": true,\n");
      strcat(string, temp);
   }
 
   if ( Mptr->SLPNO ) {
      sprintf(temp, "  \"SLPNO\": true,\n");
      strcat(string, temp);
   }
 
   if ( Mptr->SLP != (float) MAXINT ) {
      sprintf(temp, "  \"SeaLevelPressureHPa\": %.1f,\n", Mptr->SLP);
      strcat(string, temp);
   }
 
   if ( Mptr->SectorVsby != (float) MAXINT ) {
      sprintf(temp, "  \"SECTOR VSBY (MILES)\": %.2f,\n", Mptr->SectorVsby );
      strcat(string, temp);
   }
 
   if ( Mptr->SectorVsby_Dir[ 0 ] != '\0' ) {
      sprintf(temp, "  \"SECTOR VSBY OCTANT\": \"%s\",\n", Mptr->SectorVsby_Dir );
      strcat(string, temp);
   }
 
   if ( Mptr->TS_LOC[ 0 ] != '\0' ) {
      sprintf(temp, "  \"THUNDERSTORM LOCAT\": \"%s\",\n", Mptr->TS_LOC );
      strcat(string, temp);
   }
 
   if ( Mptr->TS_MOVMNT[ 0 ] != '\0' ) {
      sprintf(temp, "  \"THUNDERSTORM MOVMNT\": \"%s\",\n", Mptr->TS_MOVMNT);
      strcat(string, temp);
   }
 
   if ( Mptr->GR ) {
      sprintf(temp, "  \"GR (HAILSTONES)\": true,\n");
      strcat(string, temp);
   }
 
   if ( Mptr->GR_Size != (float) MAXINT ) {
      sprintf(temp, "  \"HLSTO SIZE (INCHES)\": %.3f\",\n",Mptr->GR_Size);
      strcat(string, temp);
   }
 
   if ( Mptr->VIRGA ) {
      sprintf(temp, "  \"VIRGA\": true,\n");
      strcat(string, temp);
   }
 
   if ( Mptr->VIRGA_DIR[0] != '\0' ) {
      sprintf(temp, "  \"DIR OF VIRGA FRM STN\": \"%s\",\n", Mptr->VIRGA_DIR);
      strcat(string, temp);
   }
 
   for( i = 0; i < MAX_SURFACE_OBSCURATIONS; i++ ) {
      if( Mptr->SfcObscuration[i][0] != '\0' ) {
         sprintf(temp, "  \"SfcObscuration\": \"%s\",\n",
                   Mptr->SfcObscuration[i]);
         strcat(string, temp);
      }
   }
 
   if ( Mptr->Num8thsSkyObscured != MAXINT ) {
      sprintf(temp, "  \"8ths of SkyObscured\": %d,\n",Mptr->Num8thsSkyObscured);
      strcat(string, temp);
   }
 
   if ( Mptr->CIGNO ) {
      sprintf(temp, "  \"CIGNO\": true,\n");
      strcat(string, temp);
   }
 
   if ( Mptr->Ceiling != MAXINT ) {
      sprintf(temp, "  \"Ceiling (ft)\": %d,\n",Mptr->Ceiling);
      strcat(string, temp);
   }
 
   if ( Mptr->Estimated_Ceiling != MAXINT ) {
      sprintf(temp, "  \"Estimated CIG (ft)\": %d,\n",Mptr->Estimated_Ceiling);
      strcat(string, temp);
   }
 
   if ( Mptr->VrbSkyBelow[0] != '\0' ) {
      sprintf(temp, "  \"VRB SKY COND BELOW\": \"%s\",\n",Mptr->VrbSkyBelow);
      strcat(string, temp);
   }
 
   if ( Mptr->VrbSkyAbove[0] != '\0' ) {
      sprintf(temp, "  \"VRB SKY COND ABOVE\": \"%s\",\n",Mptr->VrbSkyAbove);
      strcat(string, temp);
   }
 
   if ( Mptr->VrbSkyLayerHgt != MAXINT ) {
      sprintf(temp, "  \"VRBSKY COND HGT (FT)\": %d,\n",Mptr->VrbSkyLayerHgt);
      strcat(string, temp);
   }
 
   if ( Mptr->ObscurAloftHgt != MAXINT ) {
      sprintf(temp, "  \"Hgt Obscur Aloft(ft)\": %d,\n",Mptr->ObscurAloftHgt);
      strcat(string, temp);
   }
 
   if ( Mptr->ObscurAloft[0] != '\0' ) {
      sprintf(temp, "  \"Obscur Phenom Aloft\": \"%s\",\n",Mptr->ObscurAloft);
      strcat(string, temp);
   }
 
   if ( Mptr->ObscurAloftSkyCond[0] != '\0' ) {
      sprintf(temp, "  \"Obscur ALOFT SKYCOND\": \"%s\",\n",Mptr->ObscurAloftSkyCond);
      strcat(string, temp);
   }
 
 
   if ( Mptr->NOSPECI ) {
      sprintf(temp, "  \"NOSPECI\": true,\n");
      strcat(string, temp);
   }
 
   if ( Mptr->LAST ) {
      sprintf(temp, "  \"LAST\": true,\n");
      strcat(string, temp);
   }
 
   if ( Mptr->synoptic_cloud_type[ 0 ] != '\0' ) {
      sprintf(temp, "  \"SYNOPTIC CLOUD GROUP\": \"%s\",\n",Mptr->synoptic_cloud_type);
      strcat(string, temp);
   }
 
   if ( Mptr->CloudLow != '\0' ) {
      sprintf(temp, "  \"LOW CLOUD CODE\": %c\",\n",Mptr->CloudLow);
      strcat(string, temp);
   }
 
   if ( Mptr->CloudMedium != '\0' ) {
      sprintf(temp, "  \"MEDIUM CLOUD CODE\": %c\",\n",Mptr->CloudMedium);
      strcat(string, temp);
   }
 
   if ( Mptr->CloudHigh != '\0' ) {
      sprintf(temp, "  \"HIGH CLOUD CODE\": %c\",\n",Mptr->CloudHigh);
      strcat(string, temp);
   }
 
   if ( Mptr->SNINCR != MAXINT ) {
      sprintf(temp, "  \"SNINCR (INCHES)\": %d,\n",Mptr->SNINCR);
      strcat(string, temp);
   }
 
   if ( Mptr->SNINCR_TotalDepth != MAXINT ) {
      sprintf(temp, "  \"SNINCR(TOT. INCHES)\": %d,\n",Mptr->SNINCR_TotalDepth);
      strcat(string, temp);
   }
 
   if ( Mptr->snow_depth_group[ 0 ] != '\0' ) {
      sprintf(temp, "  \"SNOW DEPTH GROUP\": \"%s\",\n",Mptr->snow_depth_group);
      strcat(string, temp);
   }
 
   if ( Mptr->snow_depth != MAXINT ) {
      sprintf(temp, "  \"SNOW DEPTH (INCHES)\": %d,\n",Mptr->snow_depth);
      strcat(string, temp);
   }
 
   if ( Mptr->WaterEquivSnow != (float) MAXINT ) {
      sprintf(temp, "  \"H2O EquivSno(inches)\": %.2f,\n",Mptr->WaterEquivSnow);
      strcat(string, temp);
   }
 
   if ( Mptr->SunshineDur != MAXINT ) {
      sprintf(temp, "  \"SUNSHINE (MINUTES)\": %d,\n",Mptr->SunshineDur);
      strcat(string, temp);
   }
 
   if ( Mptr->SunSensorOut ) {
      sprintf(temp, "  \"SUN SENSOR OUT\": true,\n");
      strcat(string, temp);
   }
 
   if ( Mptr->hourlyPrecip != (float) MAXINT ) {
      sprintf(temp, "  \"HRLY PRECIP (INCHES)\": %.2f,\n",Mptr->hourlyPrecip);
      strcat(string, temp);
   }
 
   if( Mptr->precip_amt != (float) MAXINT) {
      sprintf(temp, "  \"3/6HR PRCIP (INCHES)\": %.2f,\n",
         Mptr->precip_amt);
      strcat(string, temp);
   }
 
   if( Mptr->Indeterminant3_6HrPrecip ) {
      sprintf(temp, "  \"INDTRMN 3/6HR PRECIP\": true,\n");
      strcat(string, temp);
   }
 
   if( Mptr->precip_24_amt !=  (float) MAXINT) {
      sprintf(temp, "  \"24HR PRECIP (INCHES)\": %.2f,\n",
         Mptr->precip_24_amt);
      strcat(string, temp);
   }
 
   if ( Mptr->Indeterminant_24HrPrecip ) {
      sprintf(temp, "  \"INDTRMN 24 HR PRECIP\": true,\n");
      strcat(string, temp);
   }
 
   if ( Mptr->Temp_2_tenths != (float) MAXINT ) {
      sprintf(temp, "  \"TMP2TENTHS (CELSIUS)\": %.1f,\n",Mptr->Temp_2_tenths);
      strcat(string, temp);
   }
 
   if ( Mptr->DP_Temp_2_tenths != (float) MAXINT ) {
      sprintf(temp, "  \"DPT2TENTHS (CELSIUS)\": %.1f,\n",Mptr->DP_Temp_2_tenths);
      strcat(string, temp);
   }
 
   if ( Mptr->maxtemp !=  (float) MAXINT) {
      sprintf(temp, "  \"TemperatureMaximumCelsius\": %.1f,\n",
         Mptr->maxtemp);
      strcat(string, temp);
   }
 
   if ( Mptr->mintemp !=  (float) MAXINT) {
      sprintf(temp, "  \"TemperatureMinimumCelsius\": %.1f,\n",
         Mptr->mintemp);
      strcat(string, temp);
   }
 
   if ( Mptr->max24temp !=  (float) MAXINT) {
      sprintf(temp, "  \"24HourTemperatureMaximumCelsius\": %.1f,\n",
         Mptr->max24temp);
      strcat(string, temp);
   }
 
   if ( Mptr->min24temp !=  (float) MAXINT) {
      sprintf(temp, "  \"24HourTemperatureMinimumCelsius\": %.1f,\n",
         Mptr->min24temp);
      strcat(string, temp);
   }
 
   if ( Mptr->char_prestndcy != MAXINT) {
      sprintf(temp, "  \"PressureTendancy\": %d,\n",
         Mptr->char_prestndcy );
      strcat(string, temp);
   }
 
   if ( Mptr->prestndcy != (float) MAXINT) {
      sprintf(temp, "  \"PressureTendancyHPa\": %.1f,\n",
         Mptr->prestndcy );
      strcat(string, temp);
   }
 
   if ( Mptr->PWINO ) {
      sprintf(temp, "  \"PWINO\": true,\n");
      strcat(string, temp);
   }
 
   if ( Mptr->PNO ) {
      sprintf(temp, "  \"PNO\": true,\n");
      strcat(string, temp);
   }
 
   if ( Mptr->CHINO ) {
      sprintf(temp, "  \"CHINO\": true,\n");
      strcat(string, temp);
   }
 
   if ( Mptr->CHINO_LOC[0] != '\0' ) {
      sprintf(temp, "  \"CHINO_LOC\": \"%s\",\n",Mptr->CHINO_LOC);
      strcat(string, temp);
   }
 
   if ( Mptr->VISNO ) {
      sprintf(temp, "  \"VISNO\": true,\n");
      strcat(string, temp);
   }
 
   if ( Mptr->VISNO_LOC[0] != '\0' ) {
      sprintf(temp, "  \"VISNO_LOC\": \"%s\",\n",Mptr->VISNO_LOC);
      strcat(string, temp);
   }
 
   if ( Mptr->FZRANO ) {
      sprintf(temp, "  \"FZRANO\": true,\n");
      strcat(string, temp);
   }
 
   if ( Mptr->TSNO ) {
      sprintf(temp, "  \"TSNO\": true,\n");
      strcat(string, temp);
   }
 
   if ( Mptr->DollarSign) {
      sprintf(temp, "  \"DollarSignIndicator\": true,\n");
      strcat(string, temp);
   }
 
   if ( Mptr->horiz_vsby[ 0 ] != '\0' ) {
      sprintf(temp, "  \"Horizontal Visibility\": \"%s\",\n",Mptr->horiz_vsby);
      strcat(string, temp);
   }
 
   if ( Mptr->dir_min_horiz_vsby[ 0 ] != '\0' ) {
      sprintf(temp, "  \"HorizontalVisibilityMinimumDirection\": \"%s\",\n",Mptr->dir_min_horiz_vsby);
      strcat(string, temp);
   }
 
   if ( Mptr->CAVOK ) {
      sprintf(temp, "  \"CAVOK\": true,\n");
      strcat(string, temp);
   }
 
 
   if( Mptr->VertVsby != MAXINT ) {
      sprintf(temp, "  \"VerticalVisibilityMetres\": %d,\n",
                  Mptr->VertVsby );
      strcat(string, temp);
   }
 
 /*
   if( Mptr->charVertVsby[0] != '\0' )
      sprintf(temp, "  \"Vert. Vsby (CHAR)   : \"%s\",\n",
                  Mptr->charVertVsby );
 */
 
   if ( Mptr->QFE != MAXINT ) {
      sprintf(temp, "  \"QFE\": %d,\n", Mptr->QFE);
      strcat(string, temp);
   }
 
   if ( Mptr->VOLCASH ) {
      sprintf(temp, "  \"VolcanicAsh\": true,\n");
      strcat(string, temp);
   }
 
   if ( Mptr->min_vrbl_wind_dir != MAXINT ) {
      sprintf(temp, "  \"MinimumVariableWindDirection\": %d,\n",Mptr->min_vrbl_wind_dir);
      strcat(string, temp);
   }
   if ( Mptr->max_vrbl_wind_dir != MAXINT ) {
      sprintf(temp, "  \"MaximumVariableWindDirection\": %d,\n",Mptr->max_vrbl_wind_dir);
      strcat(string, temp);
   }
 
   string[strlen(string) - 2] = '\0'; // remove trailing comma and newline
   sprintf(temp, "\n}\n"); 
   strcat(string, temp);
}

void print_decoded_metar (Decoded_METAR *Mptr)
{
	char string[5000];
	
	sprint_metar(string, Mptr);
	fputs(string, stdout);
}

// vim: set ts=4 sw=4 sts=4 noet :
