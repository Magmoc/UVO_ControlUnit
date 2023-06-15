#ifndef _GUISLICE_REFERENCES_CONTENT_HPP
#define _GUISLICE_REFERENCES_CONTENT_HPP
// ------------------------------------------------
// Program Globals
// ------------------------------------------------

// Save some element references for direct access
//<Save_References !Start!>
gslc_tsElemRef* m_pElem_ERROR_Error1= NULL;
gslc_tsElemRef* m_pElem_ERROR_Error2= NULL;
gslc_tsElemRef* m_pElem_ERROR_Error3= NULL;
gslc_tsElemRef* m_pElem_ERROR_Error4= NULL;
gslc_tsElemRef* m_pElem_MONITOR_Current_255nm= NULL;
gslc_tsElemRef* m_pElem_MONITOR_Current_275nm= NULL;
gslc_tsElemRef* m_pElem_MONITOR_Current_285nm= NULL;
gslc_tsElemRef* m_pElem_MONITOR_Current_395nm= NULL;
gslc_tsElemRef* m_pElem_MONITOR_Dosis= NULL;
gslc_tsElemRef* m_pElem_MONITOR_Hours= NULL;
gslc_tsElemRef* m_pElem_MONITOR_Intensity= NULL;
gslc_tsElemRef* m_pElem_MONITOR_Intensity127= NULL;
gslc_tsElemRef* m_pElem_MONITOR_Minutes= NULL;
gslc_tsElemRef* m_pElem_MONITOR_Pause= NULL;
gslc_tsElemRef* m_pElem_MONITOR_Seconds= NULL;
gslc_tsElemRef* m_pElem_MONITOR_Stop= NULL;
gslc_tsElemRef* m_pElem_MONITOR_Stop136= NULL;
gslc_tsElemRef* m_pElem_MONITOR_Temperature_LED_Bottom= NULL;
gslc_tsElemRef* m_pElem_MONITOR_Temperature_LED_Top= NULL;
gslc_tsElemRef* m_pElem_MONITOR_Temperature_Seed= NULL;
gslc_tsElemRef* m_pElem_SETUP_Dosis_255nm= NULL;
gslc_tsElemRef* m_pElem_SETUP_Dosis_275nm= NULL;
gslc_tsElemRef* m_pElem_SETUP_Dosis_285nm= NULL;
gslc_tsElemRef* m_pElem_SETUP_Dosis_395nm= NULL;
gslc_tsElemRef* m_pElem_SETUP_Hours= NULL;
gslc_tsElemRef* m_pElem_SETUP_Intensity_255nm= NULL;
gslc_tsElemRef* m_pElem_SETUP_Intensity_275nm= NULL;
gslc_tsElemRef* m_pElem_SETUP_Intensity_285nm= NULL;
gslc_tsElemRef* m_pElem_SETUP_Intensity_395nm= NULL;
gslc_tsElemRef* m_pElem_SETUP_Minutes= NULL;
gslc_tsElemRef* m_pElem_SETUP_MotorIntensity= NULL;
gslc_tsElemRef* m_pElem_SETUP_Seconds= NULL;
gslc_tsElemRef* m_pElem_SETUP_Start= NULL;
//<Save_References !End!>

// Define debug message function
static int16_t DebugOut(char ch) { if (ch == (char)'\n') Serial.println(""); else Serial.write(ch); return 0; }

// ------------------------------------------------
// Callback Methods
// ------------------------------------------------
//<Button Callback !Start!>
//<Button Callback !End!>
//<Checkbox Callback !Start!>
//<Checkbox Callback !End!>
//<Keypad Callback !Start!>
//<Keypad Callback !End!>
//<Spinner Callback !Start!>
//<Spinner Callback !End!>
//<Listbox Callback !Start!>
//<Listbox Callback !End!>
 
// Scanner drawing callback function
// - This is called when E_ELEM_SCAN is being rendered
bool CbDrawScanner(void* pvGui,void* pvElemRef,gslc_teRedrawType eRedraw)
{
  int nInd;

  // Typecast the parameters to match the GUI and element types
  gslc_tsGui*     pGui     = (gslc_tsGui*)(pvGui);
  gslc_tsElemRef* pElemRef = (gslc_tsElemRef*)(pvElemRef);
  gslc_tsElem*    pElem    = gslc_GetElemFromRef(pGui,pElemRef); 

  // Create shorthand variables for the origin
  int16_t  nX = pElem->rElem.x;
  int16_t  nY = pElem->rElem.y;

  // Draw the background
  gslc_tsRect rInside = pElem->rElem;
  rInside = gslc_ExpandRect(rInside,-1,-1);
  gslc_DrawFillRect(pGui,rInside,pElem->colElemFill);

  // Enable localized clipping
  gslc_SetClipRect(pGui,&rInside);

  //TODO - Add your drawing graphic primitives

  // Disable clipping region
  gslc_SetClipRect(pGui,NULL);

  // Draw the frame
  gslc_DrawFrameRect(pGui,pElem->rElem,pElem->colElemFrame);

  // Clear the redraw flag
  gslc_ElemSetRedraw(&m_gui,pElemRef,GSLC_REDRAW_NONE);

  return true;
}
//<Slider Callback !Start!>
//<Slider Callback !End!>
//<Tick Callback !Start!>

#endif