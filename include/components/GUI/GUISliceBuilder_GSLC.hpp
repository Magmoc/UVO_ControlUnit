//<File !Start!>
// FILE: [GUISliceBuilder_GSLC.h]
// Created by GUIslice Builder version: [0.17.b24]
//
// GUIslice Builder Generated GUI Framework File
//
// For the latest guides, updates and support view:
// https://github.com/ImpulseAdventure/GUIslice
//
//<File !End!>

#ifndef _GUISLICE_GEN_H
#define _GUISLICE_GEN_H

// ------------------------------------------------
// Headers to include
// ------------------------------------------------
#include "GUIslice.h"
#include "GUIslice_drv.h"

// Include any extended elements
//<Includes !Start!>
//<Includes !End!>

// ------------------------------------------------
// Headers and Defines for fonts
// Note that font files are located within the Adafruit-GFX library folder:
// ------------------------------------------------
//<Fonts !Start!>
#if !defined(DRV_DISP_TFT_ESPI)
  #error E_PROJECT_OPTIONS tab->Graphics Library should be Adafruit_GFX
#endif
#include <TFT_eSPI.h>
#include "Seven_Segment16pt7b.h"
//<Fonts !End!>

// ------------------------------------------------
// Defines for resources
// ------------------------------------------------
//<Resources !Start!>
//<Resources !End!>

// ------------------------------------------------
// Enumerations for pages, elements, fonts, images
// ------------------------------------------------
//<Enum !Start!>
enum {E_PG_BASE,E_PG_SETUP,E_PG_SCREENSAVER,E_PG_MONITOR,E_PG_ERROR};
enum {E_ELEM_BOX1,E_ELEM_ERROR_Error1,E_ELEM_ERROR_Error2
      ,E_ELEM_ERROR_Error3,E_ELEM_ERROR_Error4
      ,E_ELEM_MONITOR_Current_255nm,E_ELEM_MONITOR_Current_275nm
      ,E_ELEM_MONITOR_Current_285nm,E_ELEM_MONITOR_Current_395nm
      ,E_ELEM_MONITOR_Dosis,E_ELEM_MONITOR_Hours
      ,E_ELEM_MONITOR_Intensity,E_ELEM_MONITOR_Minutes
      ,E_ELEM_MONITOR_Pause,E_ELEM_MONITOR_Seconds,E_ELEM_MONITOR_Stop
      ,E_ELEM_MONITOR_Temperature_LED_Bottom
      ,E_ELEM_MONITOR_Temperature_LED_Top
      ,E_ELEM_MONITOR_Temperature_Seed,E_ELEM_SETUP_Dosis_255nm
      ,E_ELEM_SETUP_Dosis_275nm,E_ELEM_SETUP_Dosis_285nm
      ,E_ELEM_SETUP_Dosis_395nm,E_ELEM_SETUP_Hours
      ,E_ELEM_SETUP_Intensity_255nm,E_ELEM_SETUP_Intensity_275nm
      ,E_ELEM_SETUP_Intensity_285nm,E_ELEM_SETUP_Intensity_395nm
      ,E_ELEM_SETUP_Minutes,E_ELEM_SETUP_MotorIntensity
      ,E_ELEM_SETUP_PERCENTAGESIGN_395nm,E_ELEM_SETUP_Seconds
      ,E_ELEM_SETUP_Start,E_ELEM_SETUP_TEXT_255nm
      ,E_ELEM_SETUP_TEXT_275nm,E_ELEM_SETUP_TEXT_285nm
      ,E_ELEM_SETUP_TEXT_395nm,E_ELEM_SETUP_TEXT_DOSIS
      ,E_ELEM_SETUP_TEXT_DURATION,E_ELEM_SETUP_TEXT_MOTORINTENSITY
      ,E_ELEM_SETUP_TEXT_PERCENTAGESIGN_255nm
      ,E_ELEM_SETUP_TEXT_PERCENTAGESIGN_275nm
      ,E_ELEM_SETUP_TEXT_PERCENTAGESIGN_285nm
      ,E_ELEM_SETUP_TEXT_PERCENTSIGN_MOTORINTENSITY
      ,E_ELEM_SETUP_TEXT_TITLE,E_ELEM_SETUP_TEXT_WAVELENGTH
      ,E_ELEM_TEXT103,E_ELEM_TEXT104,E_ELEM_TEXT105,E_ELEM_TEXT106
      ,E_ELEM_TEXT108,E_ELEM_TEXT118,E_ELEM_TEXT119,E_ELEM_TEXT121
      ,E_ELEM_TEXT122,E_ELEM_TEXT124,E_ELEM_TEXT125,E_ELEM_TEXT126
      ,E_ELEM_TEXT127,E_ELEM_TEXT128,E_ELEM_TEXT129,E_ELEM_TEXT130
      ,E_ELEM_TEXT131,E_ELEM_TEXT136,E_ELEM_TEXT137,E_ELEM_TEXT63
      ,E_ELEM_TEXT64,E_ELEM_TEXT73,E_ELEM_TEXT74,E_ELEM_TEXT75
      ,E_ELEM_TEXT76,E_ELEM_TEXT77,E_ELEM_TEXT78,E_ELEM_TEXT80
      ,E_ELEM_TEXT82,E_ELEM_TEXT83,E_ELEM_TEXT85,E_ELEM_TEXT88
      ,E_ELEM_TEXT89,E_ELEM_TEXT90,E_ELEM_TEXT94};
// Must use separate enum for fonts with MAX_FONT at end to use gslc_FontSet.
enum {E_BUILTIN10X16,E_BUILTIN25X40,E_SEVEN_SEGMENT16,MAX_FONT};
//<Enum !End!>

// ------------------------------------------------
// Instantiate the GUI
// ------------------------------------------------

// ------------------------------------------------
// Define the maximum number of elements and pages
// ------------------------------------------------
//<ElementDefines !Start!>
#define MAX_PAGE                5

#define MAX_ELEM_PG_BASE 0 // # Elems total on page
#define MAX_ELEM_PG_BASE_RAM MAX_ELEM_PG_BASE // # Elems in RAM

#define MAX_ELEM_PG_SETUP 31 // # Elems total on page
#define MAX_ELEM_PG_SETUP_RAM MAX_ELEM_PG_SETUP // # Elems in RAM

#define MAX_ELEM_PG_SCREENSAVER 0 // # Elems total on page
#define MAX_ELEM_PG_SCREENSAVER_RAM MAX_ELEM_PG_SCREENSAVER // # Elems in RAM

#define MAX_ELEM_PG_MONITOR 40 // # Elems total on page
#define MAX_ELEM_PG_MONITOR_RAM MAX_ELEM_PG_MONITOR // # Elems in RAM

#define MAX_ELEM_PG_ERROR 10 // # Elems total on page
#define MAX_ELEM_PG_ERROR_RAM MAX_ELEM_PG_ERROR // # Elems in RAM
//<ElementDefines !End!>

// ------------------------------------------------
// Create element storage
// ------------------------------------------------
inline gslc_tsGui                      m_gui;
inline gslc_tsDriver                   m_drv;
inline gslc_tsFont                     m_asFont[MAX_FONT];
inline gslc_tsPage                     m_asPage[MAX_PAGE];

//<GUI_Extra_Elements !Start!>
inline gslc_tsElem                     m_asBasePage1Elem[MAX_ELEM_PG_BASE_RAM];
inline gslc_tsElemRef                  m_asBasePage1ElemRef[MAX_ELEM_PG_BASE];
inline gslc_tsElem                     m_asPage1Elem[MAX_ELEM_PG_SETUP_RAM];
inline gslc_tsElemRef                  m_asPage1ElemRef[MAX_ELEM_PG_SETUP];
inline gslc_tsElem                     m_asPage2Elem[MAX_ELEM_PG_SCREENSAVER_RAM];
inline gslc_tsElemRef                  m_asPage2ElemRef[MAX_ELEM_PG_SCREENSAVER];
inline gslc_tsElem                     m_asPage3Elem[MAX_ELEM_PG_MONITOR_RAM];
inline gslc_tsElemRef                  m_asPage3ElemRef[MAX_ELEM_PG_MONITOR];
inline gslc_tsElem                     m_asPopup1Elem[MAX_ELEM_PG_ERROR_RAM];
inline gslc_tsElemRef                  m_asPopup1ElemRef[MAX_ELEM_PG_ERROR];

#define MAX_STR                 100

//<GUI_Extra_Elements !End!>

// ------------------------------------------------
// Program Globals
// ------------------------------------------------

// Element References for direct access
//<Extern_References !Start!>
extern gslc_tsElemRef* m_pElem_ERROR_Error1;
extern gslc_tsElemRef* m_pElem_ERROR_Error2;
extern gslc_tsElemRef* m_pElem_ERROR_Error3;
extern gslc_tsElemRef* m_pElem_ERROR_Error4;
extern gslc_tsElemRef* m_pElem_MONITOR_Current_255nm;
extern gslc_tsElemRef* m_pElem_MONITOR_Current_275nm;
extern gslc_tsElemRef* m_pElem_MONITOR_Current_285nm;
extern gslc_tsElemRef* m_pElem_MONITOR_Current_395nm;
extern gslc_tsElemRef* m_pElem_MONITOR_Dosis;
extern gslc_tsElemRef* m_pElem_MONITOR_Hours;
extern gslc_tsElemRef* m_pElem_MONITOR_Intensity;
extern gslc_tsElemRef* m_pElem_MONITOR_Intensity127;
extern gslc_tsElemRef* m_pElem_MONITOR_Minutes;
extern gslc_tsElemRef* m_pElem_MONITOR_Pause;
extern gslc_tsElemRef* m_pElem_MONITOR_Seconds;
extern gslc_tsElemRef* m_pElem_MONITOR_Stop;
extern gslc_tsElemRef* m_pElem_MONITOR_Stop136;
extern gslc_tsElemRef* m_pElem_MONITOR_Temperature_LED_Bottom;
extern gslc_tsElemRef* m_pElem_MONITOR_Temperature_LED_Top;
extern gslc_tsElemRef* m_pElem_MONITOR_Temperature_Seed;
extern gslc_tsElemRef* m_pElem_SETUP_Dosis_255nm;
extern gslc_tsElemRef* m_pElem_SETUP_Dosis_275nm;
extern gslc_tsElemRef* m_pElem_SETUP_Dosis_285nm;
extern gslc_tsElemRef* m_pElem_SETUP_Dosis_395nm;
extern gslc_tsElemRef* m_pElem_SETUP_Hours;
extern gslc_tsElemRef* m_pElem_SETUP_Intensity_255nm;
extern gslc_tsElemRef* m_pElem_SETUP_Intensity_275nm;
extern gslc_tsElemRef* m_pElem_SETUP_Intensity_285nm;
extern gslc_tsElemRef* m_pElem_SETUP_Intensity_395nm;
extern gslc_tsElemRef* m_pElem_SETUP_Minutes;
extern gslc_tsElemRef* m_pElem_SETUP_MotorIntensity;
extern gslc_tsElemRef* m_pElem_SETUP_Seconds;
extern gslc_tsElemRef* m_pElem_SETUP_Start;
//<Extern_References !End!>

// Define debug message function
static int16_t DebugOut(char ch);

// ------------------------------------------------
// Callback Methods
// ------------------------------------------------
bool CbBtnCommon(void* pvGui,void *pvElemRef,gslc_teTouch eTouch,int16_t nX,int16_t nY);
bool CbCheckbox(void* pvGui, void* pvElemRef, int16_t nSelId, bool bState);
bool CbDrawScanner(void* pvGui,void* pvElemRef,gslc_teRedrawType eRedraw);
bool CbKeypad(void* pvGui, void *pvElemRef, int16_t nState, void* pvData);
bool CbListbox(void* pvGui, void* pvElemRef, int16_t nSelId);
bool CbSlidePos(void* pvGui,void* pvElemRef,int16_t nPos);
bool CbSpinner(void* pvGui, void *pvElemRef, int16_t nState, void* pvData);
bool CbTickScanner(void* pvGui,void* pvScope);

// ------------------------------------------------
// Create page elements
// ------------------------------------------------
inline void InitGUIslice_gen()
{
  gslc_tsElemRef* pElemRef = NULL;

  if (!gslc_Init(&m_gui,&m_drv,m_asPage,MAX_PAGE,m_asFont,MAX_FONT)) { return; }

  // ------------------------------------------------
  // Load Fonts
  // ------------------------------------------------
//<Load_Fonts !Start!>
    if (!gslc_FontSet(&m_gui,E_BUILTIN10X16,GSLC_FONTREF_PTR,NULL,2)) { return; }
    if (!gslc_FontSet(&m_gui,E_BUILTIN25X40,GSLC_FONTREF_PTR,NULL,5)) { return; }
    if (!gslc_FontSet(&m_gui,E_SEVEN_SEGMENT16,GSLC_FONTREF_PTR,&Seven_Segment16pt7b,1)) { return; }
//<Load_Fonts !End!>

//<InitGUI !Start!>
  gslc_PageAdd(&m_gui,E_PG_BASE,m_asBasePage1Elem,MAX_ELEM_PG_BASE_RAM,m_asBasePage1ElemRef,MAX_ELEM_PG_BASE);
  gslc_PageAdd(&m_gui,E_PG_SETUP,m_asPage1Elem,MAX_ELEM_PG_SETUP_RAM,m_asPage1ElemRef,MAX_ELEM_PG_SETUP);
  gslc_PageAdd(&m_gui,E_PG_SCREENSAVER,m_asPage2Elem,MAX_ELEM_PG_SCREENSAVER_RAM,m_asPage2ElemRef,MAX_ELEM_PG_SCREENSAVER);
  gslc_PageAdd(&m_gui,E_PG_MONITOR,m_asPage3Elem,MAX_ELEM_PG_MONITOR_RAM,m_asPage3ElemRef,MAX_ELEM_PG_MONITOR);
  gslc_PageAdd(&m_gui,E_PG_ERROR,m_asPopup1Elem,MAX_ELEM_PG_ERROR_RAM,m_asPopup1ElemRef,MAX_ELEM_PG_ERROR);

  // Now mark E_PG_BASE as a "base" page which means that it's elements
  // are always visible. This is useful for common page elements.
  gslc_SetPageBase(&m_gui, E_PG_BASE);


  // NOTE: The current page defaults to the first page added. Here we explicitly
  //       ensure that the main page is the correct page no matter the add order.
  gslc_SetPageCur(&m_gui,E_PG_SETUP);
  
  // Set Background to a flat color
  gslc_SetBkgndColor(&m_gui,((gslc_tsColor){191,205,224}));

  // -----------------------------------
  // PAGE: E_PG_BASE
  

  // -----------------------------------
  // PAGE: E_PG_SETUP
  
  
  // Create E_ELEM_SETUP_TEXT_255nm text label
  pElemRef = gslc_ElemCreateTxt(&m_gui,E_ELEM_SETUP_TEXT_255nm,E_PG_SETUP,(gslc_tsRect){50,80,60,16},
    (char*)"255nm",0,E_BUILTIN10X16);
  gslc_ElemSetFillEn(&m_gui,pElemRef,false);
  gslc_ElemSetTxtCol(&m_gui,pElemRef,((gslc_tsColor){0,0,5}));
  
  // Create E_ELEM_SETUP_Intensity_275nm runtime modifiable text
  static char m_sDisplayText38[4] = "0";
  pElemRef = gslc_ElemCreateTxt(&m_gui,E_ELEM_SETUP_Intensity_275nm,E_PG_SETUP,(gslc_tsRect){130,110,36,16},
    (char*)m_sDisplayText38,4,E_BUILTIN10X16);
  gslc_ElemSetTxtAlign(&m_gui,pElemRef,GSLC_ALIGN_MID_RIGHT);
  gslc_ElemSetFillEn(&m_gui,pElemRef,false);
  gslc_ElemSetTxtCol(&m_gui,pElemRef,((gslc_tsColor){0,0,5}));
  gslc_ElemSetCol(&m_gui,pElemRef,((gslc_tsColor){59,51,85}),((gslc_tsColor){93,93,129}),GSLC_COL_BLACK);
  m_pElem_SETUP_Intensity_275nm = pElemRef;
  
  // Create E_ELEM_SETUP_Dosis_275nm runtime modifiable text
  static char m_sDisplayText39[6] = "0";
  pElemRef = gslc_ElemCreateTxt(&m_gui,E_ELEM_SETUP_Dosis_275nm,E_PG_SETUP,(gslc_tsRect){250,110,60,16},
    (char*)m_sDisplayText39,6,E_BUILTIN10X16);
  gslc_ElemSetFillEn(&m_gui,pElemRef,false);
  gslc_ElemSetTxtCol(&m_gui,pElemRef,((gslc_tsColor){0,0,5}));
  m_pElem_SETUP_Dosis_275nm = pElemRef;
  
  // Create E_ELEM_SETUP_TEXT_275nm text label
  pElemRef = gslc_ElemCreateTxt(&m_gui,E_ELEM_SETUP_TEXT_275nm,E_PG_SETUP,(gslc_tsRect){50,110,60,16},
    (char*)"275nm",0,E_BUILTIN10X16);
  gslc_ElemSetFillEn(&m_gui,pElemRef,false);
  gslc_ElemSetTxtCol(&m_gui,pElemRef,((gslc_tsColor){0,0,5}));
  
  // Create E_ELEM_SETUP_Intensity_285nm runtime modifiable text
  static char m_sDisplayText41[4] = "0";
  pElemRef = gslc_ElemCreateTxt(&m_gui,E_ELEM_SETUP_Intensity_285nm,E_PG_SETUP,(gslc_tsRect){130,140,36,16},
    (char*)m_sDisplayText41,4,E_BUILTIN10X16);
  gslc_ElemSetTxtAlign(&m_gui,pElemRef,GSLC_ALIGN_MID_RIGHT);
  gslc_ElemSetFillEn(&m_gui,pElemRef,false);
  gslc_ElemSetTxtCol(&m_gui,pElemRef,((gslc_tsColor){0,0,5}));
  gslc_ElemSetCol(&m_gui,pElemRef,((gslc_tsColor){59,51,85}),((gslc_tsColor){93,93,129}),GSLC_COL_BLACK);
  m_pElem_SETUP_Intensity_285nm = pElemRef;
  
  // Create E_ELEM_SETUP_Dosis_285nm runtime modifiable text
  static char m_sDisplayText42[6] = "0";
  pElemRef = gslc_ElemCreateTxt(&m_gui,E_ELEM_SETUP_Dosis_285nm,E_PG_SETUP,(gslc_tsRect){250,140,60,16},
    (char*)m_sDisplayText42,6,E_BUILTIN10X16);
  gslc_ElemSetFillEn(&m_gui,pElemRef,false);
  gslc_ElemSetTxtCol(&m_gui,pElemRef,((gslc_tsColor){0,0,5}));
  m_pElem_SETUP_Dosis_285nm = pElemRef;
  
  // Create E_ELEM_SETUP_TEXT_285nm text label
  pElemRef = gslc_ElemCreateTxt(&m_gui,E_ELEM_SETUP_TEXT_285nm,E_PG_SETUP,(gslc_tsRect){50,140,60,16},
    (char*)"285nm",0,E_BUILTIN10X16);
  gslc_ElemSetFillEn(&m_gui,pElemRef,false);
  gslc_ElemSetTxtCol(&m_gui,pElemRef,((gslc_tsColor){0,0,5}));
  
  // Create E_ELEM_SETUP_Intensity_395nm runtime modifiable text
  static char m_sDisplayText44[4] = "0";
  pElemRef = gslc_ElemCreateTxt(&m_gui,E_ELEM_SETUP_Intensity_395nm,E_PG_SETUP,(gslc_tsRect){130,170,36,16},
    (char*)m_sDisplayText44,4,E_BUILTIN10X16);
  gslc_ElemSetTxtAlign(&m_gui,pElemRef,GSLC_ALIGN_MID_RIGHT);
  gslc_ElemSetFillEn(&m_gui,pElemRef,false);
  gslc_ElemSetTxtCol(&m_gui,pElemRef,((gslc_tsColor){0,0,5}));
  gslc_ElemSetCol(&m_gui,pElemRef,((gslc_tsColor){59,51,85}),((gslc_tsColor){93,93,129}),GSLC_COL_BLACK);
  m_pElem_SETUP_Intensity_395nm = pElemRef;
  
  // Create E_ELEM_SETUP_Dosis_395nm runtime modifiable text
  static char m_sDisplayText45[6] = "0";
  pElemRef = gslc_ElemCreateTxt(&m_gui,E_ELEM_SETUP_Dosis_395nm,E_PG_SETUP,(gslc_tsRect){250,170,60,16},
    (char*)m_sDisplayText45,6,E_BUILTIN10X16);
  gslc_ElemSetFillEn(&m_gui,pElemRef,false);
  gslc_ElemSetTxtCol(&m_gui,pElemRef,((gslc_tsColor){0,0,5}));
  m_pElem_SETUP_Dosis_395nm = pElemRef;
  
  // Create E_ELEM_SETUP_TEXT_395nm text label
  pElemRef = gslc_ElemCreateTxt(&m_gui,E_ELEM_SETUP_TEXT_395nm,E_PG_SETUP,(gslc_tsRect){50,170,60,16},
    (char*)"395nm",0,E_BUILTIN10X16);
  gslc_ElemSetFillEn(&m_gui,pElemRef,false);
  gslc_ElemSetTxtCol(&m_gui,pElemRef,((gslc_tsColor){0,0,5}));
  
  // Create E_ELEM_SETUP_TEXT_WAVELENGTH text label
  pElemRef = gslc_ElemCreateTxt(&m_gui,E_ELEM_SETUP_TEXT_WAVELENGTH,E_PG_SETUP,(gslc_tsRect){10,60,120,16},
    (char*)"Wavelength",0,E_BUILTIN10X16);
  gslc_ElemSetFillEn(&m_gui,pElemRef,false);
  gslc_ElemSetTxtCol(&m_gui,pElemRef,((gslc_tsColor){0,0,5}));
  
  // Create E_ELEM_SETUP_Hours runtime modifiable text
  static char m_sDisplayText48[3] = "00";
  pElemRef = gslc_ElemCreateTxt(&m_gui,E_ELEM_SETUP_Hours,E_PG_SETUP,(gslc_tsRect){150,230,24,16},
    (char*)m_sDisplayText48,3,E_BUILTIN10X16);
  gslc_ElemSetTxtAlign(&m_gui,pElemRef,GSLC_ALIGN_MID_RIGHT);
  gslc_ElemSetFillEn(&m_gui,pElemRef,false);
  gslc_ElemSetTxtCol(&m_gui,pElemRef,((gslc_tsColor){0,0,5}));
  gslc_ElemSetCol(&m_gui,pElemRef,((gslc_tsColor){59,51,85}),((gslc_tsColor){93,93,129}),GSLC_COL_BLACK);
  m_pElem_SETUP_Hours = pElemRef;
  
  // Create E_ELEM_SETUP_TEXT_DURATION text label
  pElemRef = gslc_ElemCreateTxt(&m_gui,E_ELEM_SETUP_TEXT_DURATION,E_PG_SETUP,(gslc_tsRect){20,230,96,16},
    (char*)"Duration",0,E_BUILTIN10X16);
  gslc_ElemSetFillEn(&m_gui,pElemRef,false);
  gslc_ElemSetTxtCol(&m_gui,pElemRef,((gslc_tsColor){0,0,5}));
  
  // Create E_ELEM_SETUP_MotorIntensity runtime modifiable text
  static char m_sDisplayText52[4] = "0";
  pElemRef = gslc_ElemCreateTxt(&m_gui,E_ELEM_SETUP_MotorIntensity,E_PG_SETUP,(gslc_tsRect){220,260,36,16},
    (char*)m_sDisplayText52,4,E_BUILTIN10X16);
  gslc_ElemSetTxtAlign(&m_gui,pElemRef,GSLC_ALIGN_MID_RIGHT);
  gslc_ElemSetFillEn(&m_gui,pElemRef,false);
  gslc_ElemSetTxtCol(&m_gui,pElemRef,((gslc_tsColor){0,0,5}));
  gslc_ElemSetCol(&m_gui,pElemRef,((gslc_tsColor){59,51,85}),((gslc_tsColor){93,93,129}),GSLC_COL_BLACK);
  m_pElem_SETUP_MotorIntensity = pElemRef;
  
  // Create E_ELEM_SETUP_TEXT_MOTORINTENSITY text label
  pElemRef = gslc_ElemCreateTxt(&m_gui,E_ELEM_SETUP_TEXT_MOTORINTENSITY,E_PG_SETUP,(gslc_tsRect){20,260,180,16},
    (char*)"Motor Intensity",0,E_BUILTIN10X16);
  gslc_ElemSetFillEn(&m_gui,pElemRef,false);
  gslc_ElemSetTxtCol(&m_gui,pElemRef,((gslc_tsColor){0,0,5}));
  
  // Create E_ELEM_SETUP_Intensity_255nm runtime modifiable text
  static char m_sDisplayText54[4] = "0";
  pElemRef = gslc_ElemCreateTxt(&m_gui,E_ELEM_SETUP_Intensity_255nm,E_PG_SETUP,(gslc_tsRect){130,80,36,16},
    (char*)m_sDisplayText54,4,E_BUILTIN10X16);
  gslc_ElemSetTxtAlign(&m_gui,pElemRef,GSLC_ALIGN_MID_RIGHT);
  gslc_ElemSetFillEn(&m_gui,pElemRef,false);
  gslc_ElemSetTxtCol(&m_gui,pElemRef,((gslc_tsColor){0,0,5}));
  gslc_ElemSetCol(&m_gui,pElemRef,((gslc_tsColor){59,51,85}),((gslc_tsColor){93,93,129}),GSLC_COL_BLACK);
  m_pElem_SETUP_Intensity_255nm = pElemRef;
  
  // Create E_ELEM_SETUP_TEXT_DOSIS text label
  pElemRef = gslc_ElemCreateTxt(&m_gui,E_ELEM_SETUP_TEXT_DOSIS,E_PG_SETUP,(gslc_tsRect){220,60,168,16},
    (char*)"Dosis [J/cm^2]",0,E_BUILTIN10X16);
  gslc_ElemSetFillEn(&m_gui,pElemRef,false);
  gslc_ElemSetTxtCol(&m_gui,pElemRef,((gslc_tsColor){0,0,5}));
  gslc_ElemSetCol(&m_gui,pElemRef,((gslc_tsColor){254,252,253}),GSLC_COL_BLACK,GSLC_COL_BLACK);
  
  // Create E_ELEM_SETUP_Dosis_255nm runtime modifiable text
  static char m_sDisplayText59[6] = "0";
  pElemRef = gslc_ElemCreateTxt(&m_gui,E_ELEM_SETUP_Dosis_255nm,E_PG_SETUP,(gslc_tsRect){250,80,60,16},
    (char*)m_sDisplayText59,6,E_BUILTIN10X16);
  gslc_ElemSetFillEn(&m_gui,pElemRef,false);
  gslc_ElemSetTxtCol(&m_gui,pElemRef,((gslc_tsColor){0,0,5}));
  m_pElem_SETUP_Dosis_255nm = pElemRef;
  
  // Create E_ELEM_SETUP_Minutes runtime modifiable text
  static char m_sDisplayText62[3] = "00";
  pElemRef = gslc_ElemCreateTxt(&m_gui,E_ELEM_SETUP_Minutes,E_PG_SETUP,(gslc_tsRect){180,230,24,16},
    (char*)m_sDisplayText62,3,E_BUILTIN10X16);
  gslc_ElemSetFillEn(&m_gui,pElemRef,false);
  gslc_ElemSetTxtCol(&m_gui,pElemRef,((gslc_tsColor){0,0,5}));
  gslc_ElemSetCol(&m_gui,pElemRef,((gslc_tsColor){59,51,85}),((gslc_tsColor){93,93,129}),GSLC_COL_BLACK);
  m_pElem_SETUP_Minutes = pElemRef;
  
  // Create E_ELEM_TEXT63 text label
  pElemRef = gslc_ElemCreateTxt(&m_gui,E_ELEM_TEXT63,E_PG_SETUP,(gslc_tsRect){170,230,12,16},
    (char*)":",0,E_BUILTIN10X16);
  gslc_ElemSetFillEn(&m_gui,pElemRef,false);
  gslc_ElemSetTxtCol(&m_gui,pElemRef,((gslc_tsColor){0,0,5}));
  
  // Create E_ELEM_TEXT64 text label
  pElemRef = gslc_ElemCreateTxt(&m_gui,E_ELEM_TEXT64,E_PG_SETUP,(gslc_tsRect){200,230,12,16},
    (char*)":",0,E_BUILTIN10X16);
  gslc_ElemSetFillEn(&m_gui,pElemRef,false);
  gslc_ElemSetTxtCol(&m_gui,pElemRef,((gslc_tsColor){0,0,5}));
  
  // Create E_ELEM_SETUP_Seconds runtime modifiable text
  static char m_sDisplayText65[3] = "00";
  pElemRef = gslc_ElemCreateTxt(&m_gui,E_ELEM_SETUP_Seconds,E_PG_SETUP,(gslc_tsRect){210,230,24,16},
    (char*)m_sDisplayText65,3,E_BUILTIN10X16);
  gslc_ElemSetFillEn(&m_gui,pElemRef,false);
  gslc_ElemSetTxtCol(&m_gui,pElemRef,((gslc_tsColor){0,0,5}));
  gslc_ElemSetCol(&m_gui,pElemRef,((gslc_tsColor){59,51,85}),((gslc_tsColor){93,93,129}),GSLC_COL_BLACK);
  m_pElem_SETUP_Seconds = pElemRef;
  
  // Create E_ELEM_SETUP_TEXT_PERCENTAGESIGN_255nm text label
  pElemRef = gslc_ElemCreateTxt(&m_gui,E_ELEM_SETUP_TEXT_PERCENTAGESIGN_255nm,E_PG_SETUP,(gslc_tsRect){170,80,12,16},
    (char*)"%",0,E_BUILTIN10X16);
  gslc_ElemSetFillEn(&m_gui,pElemRef,false);
  gslc_ElemSetTxtCol(&m_gui,pElemRef,((gslc_tsColor){0,0,5}));
  
  // Create E_ELEM_SETUP_TEXT_PERCENTAGESIGN_275nm text label
  pElemRef = gslc_ElemCreateTxt(&m_gui,E_ELEM_SETUP_TEXT_PERCENTAGESIGN_275nm,E_PG_SETUP,(gslc_tsRect){170,110,12,16},
    (char*)"%",0,E_BUILTIN10X16);
  gslc_ElemSetFillEn(&m_gui,pElemRef,false);
  gslc_ElemSetTxtCol(&m_gui,pElemRef,((gslc_tsColor){0,0,5}));
  
  // Create E_ELEM_SETUP_TEXT_PERCENTAGESIGN_285nm text label
  pElemRef = gslc_ElemCreateTxt(&m_gui,E_ELEM_SETUP_TEXT_PERCENTAGESIGN_285nm,E_PG_SETUP,(gslc_tsRect){170,140,12,16},
    (char*)"%",0,E_BUILTIN10X16);
  gslc_ElemSetFillEn(&m_gui,pElemRef,false);
  gslc_ElemSetTxtCol(&m_gui,pElemRef,((gslc_tsColor){0,0,5}));
  
  // Create E_ELEM_SETUP_PERCENTAGESIGN_395nm text label
  pElemRef = gslc_ElemCreateTxt(&m_gui,E_ELEM_SETUP_PERCENTAGESIGN_395nm,E_PG_SETUP,(gslc_tsRect){170,170,12,16},
    (char*)"%",0,E_BUILTIN10X16);
  gslc_ElemSetFillEn(&m_gui,pElemRef,false);
  gslc_ElemSetTxtCol(&m_gui,pElemRef,((gslc_tsColor){0,0,5}));
  
  // Create E_ELEM_SETUP_TEXT_TITLE text label
  pElemRef = gslc_ElemCreateTxt(&m_gui,E_ELEM_SETUP_TEXT_TITLE,E_PG_SETUP,(gslc_tsRect){88,10,296,22},
    (char*)"SEED DISINFECTOR 9000!",0,E_SEVEN_SEGMENT16);
  gslc_ElemSetFillEn(&m_gui,pElemRef,false);
  gslc_ElemSetTxtCol(&m_gui,pElemRef,((gslc_tsColor){0,0,5}));
  
  // Create E_ELEM_SETUP_TEXT_PERCENTSIGN_MOTORINTENSITY text label
  pElemRef = gslc_ElemCreateTxt(&m_gui,E_ELEM_SETUP_TEXT_PERCENTSIGN_MOTORINTENSITY,E_PG_SETUP,(gslc_tsRect){260,260,12,16},
    (char*)"%",0,E_BUILTIN10X16);
  gslc_ElemSetFillEn(&m_gui,pElemRef,false);
  gslc_ElemSetTxtCol(&m_gui,pElemRef,((gslc_tsColor){0,0,5}));
  
  // Create E_ELEM_TEXT73 text label
  pElemRef = gslc_ElemCreateTxt(&m_gui,E_ELEM_TEXT73,E_PG_SETUP,(gslc_tsRect){160,300,144,16},
    (char*)"SETUP SCREEN",0,E_BUILTIN10X16);
  gslc_ElemSetFillEn(&m_gui,pElemRef,false);
  gslc_ElemSetTxtCol(&m_gui,pElemRef,((gslc_tsColor){0,0,5}));
  
  // Create E_ELEM_SETUP_Start runtime modifiable text
  static char m_sDisplayText87[6] = "START";
  pElemRef = gslc_ElemCreateTxt(&m_gui,E_ELEM_SETUP_Start,E_PG_SETUP,(gslc_tsRect){390,280,60,16},
    (char*)m_sDisplayText87,6,E_BUILTIN10X16);
  gslc_ElemSetTxtAlign(&m_gui,pElemRef,GSLC_ALIGN_MID_RIGHT);
  gslc_ElemSetFillEn(&m_gui,pElemRef,false);
  gslc_ElemSetTxtCol(&m_gui,pElemRef,((gslc_tsColor){0,0,5}));
  gslc_ElemSetCol(&m_gui,pElemRef,((gslc_tsColor){59,51,85}),((gslc_tsColor){93,93,129}),GSLC_COL_BLACK);
  m_pElem_SETUP_Start = pElemRef;
  
  // Create E_ELEM_TEXT125 text label
  pElemRef = gslc_ElemCreateTxt(&m_gui,E_ELEM_TEXT125,E_PG_SETUP,(gslc_tsRect){10,300,96,16},
    (char*)"TEAM UVO",0,E_BUILTIN10X16);
  gslc_ElemSetFillEn(&m_gui,pElemRef,false);
  gslc_ElemSetTxtCol(&m_gui,pElemRef,((gslc_tsColor){0,0,5}));

  // -----------------------------------
  // PAGE: E_PG_SCREENSAVER
  

  // -----------------------------------
  // PAGE: E_PG_MONITOR
  
  
  // Create E_ELEM_TEXT74 text label
  pElemRef = gslc_ElemCreateTxt(&m_gui,E_ELEM_TEXT74,E_PG_MONITOR,(gslc_tsRect){50,80,60,16},
    (char*)"255nm",0,E_BUILTIN10X16);
  gslc_ElemSetFillEn(&m_gui,pElemRef,false);
  gslc_ElemSetTxtCol(&m_gui,pElemRef,((gslc_tsColor){0,0,5}));
  
  // Create E_ELEM_TEXT75 text label
  pElemRef = gslc_ElemCreateTxt(&m_gui,E_ELEM_TEXT75,E_PG_MONITOR,(gslc_tsRect){50,110,60,16},
    (char*)"275nm",0,E_BUILTIN10X16);
  gslc_ElemSetFillEn(&m_gui,pElemRef,false);
  gslc_ElemSetTxtCol(&m_gui,pElemRef,((gslc_tsColor){0,0,5}));
  
  // Create E_ELEM_TEXT76 text label
  pElemRef = gslc_ElemCreateTxt(&m_gui,E_ELEM_TEXT76,E_PG_MONITOR,(gslc_tsRect){50,140,60,16},
    (char*)"285nm",0,E_BUILTIN10X16);
  gslc_ElemSetFillEn(&m_gui,pElemRef,false);
  gslc_ElemSetTxtCol(&m_gui,pElemRef,((gslc_tsColor){0,0,5}));
  
  // Create E_ELEM_TEXT77 text label
  pElemRef = gslc_ElemCreateTxt(&m_gui,E_ELEM_TEXT77,E_PG_MONITOR,(gslc_tsRect){50,170,60,16},
    (char*)"395nm",0,E_BUILTIN10X16);
  gslc_ElemSetFillEn(&m_gui,pElemRef,false);
  gslc_ElemSetTxtCol(&m_gui,pElemRef,((gslc_tsColor){0,0,5}));
  
  // Create E_ELEM_TEXT78 text label
  pElemRef = gslc_ElemCreateTxt(&m_gui,E_ELEM_TEXT78,E_PG_MONITOR,(gslc_tsRect){10,60,120,16},
    (char*)"Wavelength",0,E_BUILTIN10X16);
  gslc_ElemSetFillEn(&m_gui,pElemRef,false);
  gslc_ElemSetTxtCol(&m_gui,pElemRef,((gslc_tsColor){0,0,5}));
  
  // Create E_ELEM_MONITOR_Hours runtime modifiable text
  static char m_sDisplayText79[3] = "00";
  pElemRef = gslc_ElemCreateTxt(&m_gui,E_ELEM_MONITOR_Hours,E_PG_MONITOR,(gslc_tsRect){152,273,24,16},
    (char*)m_sDisplayText79,3,E_BUILTIN10X16);
  gslc_ElemSetTxtAlign(&m_gui,pElemRef,GSLC_ALIGN_MID_RIGHT);
  gslc_ElemSetFillEn(&m_gui,pElemRef,false);
  gslc_ElemSetTxtCol(&m_gui,pElemRef,((gslc_tsColor){0,0,5}));
  gslc_ElemSetCol(&m_gui,pElemRef,((gslc_tsColor){59,51,85}),((gslc_tsColor){93,93,129}),GSLC_COL_BLACK);
  m_pElem_MONITOR_Hours = pElemRef;
  
  // Create E_ELEM_TEXT80 text label
  pElemRef = gslc_ElemCreateTxt(&m_gui,E_ELEM_TEXT80,E_PG_MONITOR,(gslc_tsRect){22,273,96,16},
    (char*)"Duration",0,E_BUILTIN10X16);
  gslc_ElemSetFillEn(&m_gui,pElemRef,false);
  gslc_ElemSetTxtCol(&m_gui,pElemRef,((gslc_tsColor){0,0,5}));
  
  // Create E_ELEM_MONITOR_Minutes runtime modifiable text
  static char m_sDisplayText81[3] = "00";
  pElemRef = gslc_ElemCreateTxt(&m_gui,E_ELEM_MONITOR_Minutes,E_PG_MONITOR,(gslc_tsRect){182,273,24,16},
    (char*)m_sDisplayText81,3,E_BUILTIN10X16);
  gslc_ElemSetFillEn(&m_gui,pElemRef,false);
  gslc_ElemSetTxtCol(&m_gui,pElemRef,((gslc_tsColor){0,0,5}));
  gslc_ElemSetCol(&m_gui,pElemRef,((gslc_tsColor){59,51,85}),((gslc_tsColor){93,93,129}),GSLC_COL_BLACK);
  m_pElem_MONITOR_Minutes = pElemRef;
  
  // Create E_ELEM_TEXT82 text label
  pElemRef = gslc_ElemCreateTxt(&m_gui,E_ELEM_TEXT82,E_PG_MONITOR,(gslc_tsRect){172,273,12,16},
    (char*)":",0,E_BUILTIN10X16);
  gslc_ElemSetFillEn(&m_gui,pElemRef,false);
  gslc_ElemSetTxtCol(&m_gui,pElemRef,((gslc_tsColor){0,0,5}));
  
  // Create E_ELEM_TEXT83 text label
  pElemRef = gslc_ElemCreateTxt(&m_gui,E_ELEM_TEXT83,E_PG_MONITOR,(gslc_tsRect){202,273,12,16},
    (char*)":",0,E_BUILTIN10X16);
  gslc_ElemSetFillEn(&m_gui,pElemRef,false);
  gslc_ElemSetTxtCol(&m_gui,pElemRef,((gslc_tsColor){0,0,5}));
  
  // Create E_ELEM_MONITOR_Seconds runtime modifiable text
  static char m_sDisplayText84[3] = "00";
  pElemRef = gslc_ElemCreateTxt(&m_gui,E_ELEM_MONITOR_Seconds,E_PG_MONITOR,(gslc_tsRect){212,273,24,16},
    (char*)m_sDisplayText84,3,E_BUILTIN10X16);
  gslc_ElemSetFillEn(&m_gui,pElemRef,false);
  gslc_ElemSetTxtCol(&m_gui,pElemRef,((gslc_tsColor){0,0,5}));
  gslc_ElemSetCol(&m_gui,pElemRef,((gslc_tsColor){59,51,85}),((gslc_tsColor){93,93,129}),GSLC_COL_BLACK);
  m_pElem_MONITOR_Seconds = pElemRef;
  
  // Create E_ELEM_TEXT85 text label
  pElemRef = gslc_ElemCreateTxt(&m_gui,E_ELEM_TEXT85,E_PG_MONITOR,(gslc_tsRect){88,10,296,22},
    (char*)"SEED DISINFECTOR 9000!",0,E_SEVEN_SEGMENT16);
  gslc_ElemSetFillEn(&m_gui,pElemRef,false);
  gslc_ElemSetTxtCol(&m_gui,pElemRef,((gslc_tsColor){0,0,5}));
  
  // Create E_ELEM_TEXT88 text label
  pElemRef = gslc_ElemCreateTxt(&m_gui,E_ELEM_TEXT88,E_PG_MONITOR,(gslc_tsRect){320,80,60,16},
    (char*)"Seeds",0,E_BUILTIN10X16);
  gslc_ElemSetFillEn(&m_gui,pElemRef,false);
  gslc_ElemSetTxtCol(&m_gui,pElemRef,((gslc_tsColor){0,0,5}));
  
  // Create E_ELEM_TEXT89 text label
  pElemRef = gslc_ElemCreateTxt(&m_gui,E_ELEM_TEXT89,E_PG_MONITOR,(gslc_tsRect){300,110,96,16},
    (char*)"LEDs Top",0,E_BUILTIN10X16);
  gslc_ElemSetFillEn(&m_gui,pElemRef,false);
  gslc_ElemSetTxtCol(&m_gui,pElemRef,((gslc_tsColor){0,0,5}));
  
  // Create E_ELEM_TEXT90 text label
  pElemRef = gslc_ElemCreateTxt(&m_gui,E_ELEM_TEXT90,E_PG_MONITOR,(gslc_tsRect){270,140,132,16},
    (char*)"LEDs Bottom",0,E_BUILTIN10X16);
  gslc_ElemSetFillEn(&m_gui,pElemRef,false);
  gslc_ElemSetTxtCol(&m_gui,pElemRef,((gslc_tsColor){0,0,5}));
  
  // Create E_ELEM_TEXT94 text label
  pElemRef = gslc_ElemCreateTxt(&m_gui,E_ELEM_TEXT94,E_PG_MONITOR,(gslc_tsRect){140,300,168,16},
    (char*)"MONITOR SCREEN",0,E_BUILTIN10X16);
  gslc_ElemSetFillEn(&m_gui,pElemRef,false);
  gslc_ElemSetTxtCol(&m_gui,pElemRef,((gslc_tsColor){0,0,5}));
  
  // Create E_ELEM_MONITOR_Stop runtime modifiable text
  static char m_sDisplayText95[6] = "STOP";
  pElemRef = gslc_ElemCreateTxt(&m_gui,E_ELEM_MONITOR_Stop,E_PG_MONITOR,(gslc_tsRect){390,280,60,16},
    (char*)m_sDisplayText95,6,E_BUILTIN10X16);
  gslc_ElemSetTxtAlign(&m_gui,pElemRef,GSLC_ALIGN_MID_RIGHT);
  gslc_ElemSetFillEn(&m_gui,pElemRef,false);
  gslc_ElemSetTxtCol(&m_gui,pElemRef,((gslc_tsColor){0,0,5}));
  gslc_ElemSetCol(&m_gui,pElemRef,((gslc_tsColor){59,51,85}),((gslc_tsColor){93,93,129}),GSLC_COL_BLACK);
  m_pElem_MONITOR_Stop = pElemRef;
  
  // Create E_ELEM_MONITOR_Current_275nm runtime modifiable text
  static char m_sDisplayText99[4] = "0";
  pElemRef = gslc_ElemCreateTxt(&m_gui,E_ELEM_MONITOR_Current_275nm,E_PG_MONITOR,(gslc_tsRect){130,110,36,16},
    (char*)m_sDisplayText99,4,E_BUILTIN10X16);
  gslc_ElemSetTxtAlign(&m_gui,pElemRef,GSLC_ALIGN_MID_RIGHT);
  gslc_ElemSetFillEn(&m_gui,pElemRef,false);
  gslc_ElemSetTxtCol(&m_gui,pElemRef,((gslc_tsColor){0,0,5}));
  gslc_ElemSetCol(&m_gui,pElemRef,((gslc_tsColor){59,51,85}),((gslc_tsColor){93,93,129}),GSLC_COL_BLACK);
  m_pElem_MONITOR_Current_275nm = pElemRef;
  
  // Create E_ELEM_MONITOR_Current_285nm runtime modifiable text
  static char m_sDisplayText100[4] = "0";
  pElemRef = gslc_ElemCreateTxt(&m_gui,E_ELEM_MONITOR_Current_285nm,E_PG_MONITOR,(gslc_tsRect){130,140,36,16},
    (char*)m_sDisplayText100,4,E_BUILTIN10X16);
  gslc_ElemSetTxtAlign(&m_gui,pElemRef,GSLC_ALIGN_MID_RIGHT);
  gslc_ElemSetFillEn(&m_gui,pElemRef,false);
  gslc_ElemSetTxtCol(&m_gui,pElemRef,((gslc_tsColor){0,0,5}));
  gslc_ElemSetCol(&m_gui,pElemRef,((gslc_tsColor){59,51,85}),((gslc_tsColor){93,93,129}),GSLC_COL_BLACK);
  m_pElem_MONITOR_Current_285nm = pElemRef;
  
  // Create E_ELEM_MONITOR_Current_395nm runtime modifiable text
  static char m_sDisplayText101[4] = "0";
  pElemRef = gslc_ElemCreateTxt(&m_gui,E_ELEM_MONITOR_Current_395nm,E_PG_MONITOR,(gslc_tsRect){130,170,36,16},
    (char*)m_sDisplayText101,4,E_BUILTIN10X16);
  gslc_ElemSetTxtAlign(&m_gui,pElemRef,GSLC_ALIGN_MID_RIGHT);
  gslc_ElemSetFillEn(&m_gui,pElemRef,false);
  gslc_ElemSetTxtCol(&m_gui,pElemRef,((gslc_tsColor){0,0,5}));
  gslc_ElemSetCol(&m_gui,pElemRef,((gslc_tsColor){59,51,85}),((gslc_tsColor){93,93,129}),GSLC_COL_BLACK);
  m_pElem_MONITOR_Current_395nm = pElemRef;
  
  // Create E_ELEM_MONITOR_Current_255nm runtime modifiable text
  static char m_sDisplayText102[4] = "0";
  pElemRef = gslc_ElemCreateTxt(&m_gui,E_ELEM_MONITOR_Current_255nm,E_PG_MONITOR,(gslc_tsRect){130,80,36,16},
    (char*)m_sDisplayText102,4,E_BUILTIN10X16);
  gslc_ElemSetTxtAlign(&m_gui,pElemRef,GSLC_ALIGN_MID_RIGHT);
  gslc_ElemSetFillEn(&m_gui,pElemRef,false);
  gslc_ElemSetTxtCol(&m_gui,pElemRef,((gslc_tsColor){0,0,5}));
  gslc_ElemSetCol(&m_gui,pElemRef,((gslc_tsColor){59,51,85}),((gslc_tsColor){93,93,129}),GSLC_COL_BLACK);
  m_pElem_MONITOR_Current_255nm = pElemRef;
  
  // Create E_ELEM_TEXT103 text label
  pElemRef = gslc_ElemCreateTxt(&m_gui,E_ELEM_TEXT103,E_PG_MONITOR,(gslc_tsRect){170,80,24,16},
    (char*)"mA",0,E_BUILTIN10X16);
  gslc_ElemSetFillEn(&m_gui,pElemRef,false);
  gslc_ElemSetTxtCol(&m_gui,pElemRef,((gslc_tsColor){0,0,5}));
  
  // Create E_ELEM_TEXT104 text label
  pElemRef = gslc_ElemCreateTxt(&m_gui,E_ELEM_TEXT104,E_PG_MONITOR,(gslc_tsRect){170,110,24,16},
    (char*)"mA",0,E_BUILTIN10X16);
  gslc_ElemSetFillEn(&m_gui,pElemRef,false);
  gslc_ElemSetTxtCol(&m_gui,pElemRef,((gslc_tsColor){0,0,5}));
  
  // Create E_ELEM_TEXT105 text label
  pElemRef = gslc_ElemCreateTxt(&m_gui,E_ELEM_TEXT105,E_PG_MONITOR,(gslc_tsRect){170,140,24,16},
    (char*)"mA",0,E_BUILTIN10X16);
  gslc_ElemSetFillEn(&m_gui,pElemRef,false);
  gslc_ElemSetTxtCol(&m_gui,pElemRef,((gslc_tsColor){0,0,5}));
  
  // Create E_ELEM_TEXT106 text label
  pElemRef = gslc_ElemCreateTxt(&m_gui,E_ELEM_TEXT106,E_PG_MONITOR,(gslc_tsRect){170,170,24,16},
    (char*)"mA",0,E_BUILTIN10X16);
  gslc_ElemSetFillEn(&m_gui,pElemRef,false);
  gslc_ElemSetTxtCol(&m_gui,pElemRef,((gslc_tsColor){0,0,5}));
  
  // Create E_ELEM_MONITOR_Intensity runtime modifiable text
  static char m_sDisplayText107[5] = "0";
  pElemRef = gslc_ElemCreateTxt(&m_gui,E_ELEM_MONITOR_Intensity,E_PG_MONITOR,(gslc_tsRect){170,210,48,16},
    (char*)m_sDisplayText107,5,E_BUILTIN10X16);
  gslc_ElemSetTxtAlign(&m_gui,pElemRef,GSLC_ALIGN_MID_RIGHT);
  gslc_ElemSetFillEn(&m_gui,pElemRef,false);
  gslc_ElemSetTxtCol(&m_gui,pElemRef,((gslc_tsColor){0,0,5}));
  gslc_ElemSetCol(&m_gui,pElemRef,((gslc_tsColor){59,51,85}),((gslc_tsColor){93,93,129}),GSLC_COL_BLACK);
  m_pElem_MONITOR_Intensity = pElemRef;
  
  // Create E_ELEM_TEXT108 text label
  pElemRef = gslc_ElemCreateTxt(&m_gui,E_ELEM_TEXT108,E_PG_MONITOR,(gslc_tsRect){20,210,144,16},
    (char*)"UV Intensity",0,E_BUILTIN10X16);
  gslc_ElemSetFillEn(&m_gui,pElemRef,false);
  gslc_ElemSetTxtCol(&m_gui,pElemRef,((gslc_tsColor){0,0,5}));
  
  // Create E_ELEM_MONITOR_Temperature_LED_Top runtime modifiable text
  static char m_sDisplayText110[4] = "0";
  pElemRef = gslc_ElemCreateTxt(&m_gui,E_ELEM_MONITOR_Temperature_LED_Top,E_PG_MONITOR,(gslc_tsRect){415,112,36,16},
    (char*)m_sDisplayText110,4,E_BUILTIN10X16);
  gslc_ElemSetTxtAlign(&m_gui,pElemRef,GSLC_ALIGN_MID_RIGHT);
  gslc_ElemSetFillEn(&m_gui,pElemRef,false);
  gslc_ElemSetTxtCol(&m_gui,pElemRef,((gslc_tsColor){0,0,5}));
  gslc_ElemSetCol(&m_gui,pElemRef,((gslc_tsColor){59,51,85}),((gslc_tsColor){93,93,129}),GSLC_COL_BLACK);
  m_pElem_MONITOR_Temperature_LED_Top = pElemRef;
  
  // Create E_ELEM_MONITOR_Temperature_LED_Bottom runtime modifiable text
  static char m_sDisplayText111[4] = "0";
  pElemRef = gslc_ElemCreateTxt(&m_gui,E_ELEM_MONITOR_Temperature_LED_Bottom,E_PG_MONITOR,(gslc_tsRect){415,142,36,16},
    (char*)m_sDisplayText111,4,E_BUILTIN10X16);
  gslc_ElemSetTxtAlign(&m_gui,pElemRef,GSLC_ALIGN_MID_RIGHT);
  gslc_ElemSetFillEn(&m_gui,pElemRef,false);
  gslc_ElemSetTxtCol(&m_gui,pElemRef,((gslc_tsColor){0,0,5}));
  gslc_ElemSetCol(&m_gui,pElemRef,((gslc_tsColor){59,51,85}),((gslc_tsColor){93,93,129}),GSLC_COL_BLACK);
  m_pElem_MONITOR_Temperature_LED_Bottom = pElemRef;
  
  // Create E_ELEM_MONITOR_Temperature_Seed runtime modifiable text
  static char m_sDisplayText113[4] = "0";
  pElemRef = gslc_ElemCreateTxt(&m_gui,E_ELEM_MONITOR_Temperature_Seed,E_PG_MONITOR,(gslc_tsRect){415,82,36,16},
    (char*)m_sDisplayText113,4,E_BUILTIN10X16);
  gslc_ElemSetTxtAlign(&m_gui,pElemRef,GSLC_ALIGN_MID_RIGHT);
  gslc_ElemSetFillEn(&m_gui,pElemRef,false);
  gslc_ElemSetTxtCol(&m_gui,pElemRef,((gslc_tsColor){0,0,5}));
  gslc_ElemSetCol(&m_gui,pElemRef,((gslc_tsColor){59,51,85}),((gslc_tsColor){93,93,129}),GSLC_COL_BLACK);
  m_pElem_MONITOR_Temperature_Seed = pElemRef;
  
  // Create E_ELEM_TEXT118 text label
  pElemRef = gslc_ElemCreateTxt(&m_gui,E_ELEM_TEXT118,E_PG_MONITOR,(gslc_tsRect){290,60,180,16},
    (char*)"Temperature [C]",0,E_BUILTIN10X16);
  gslc_ElemSetFillEn(&m_gui,pElemRef,false);
  gslc_ElemSetTxtCol(&m_gui,pElemRef,((gslc_tsColor){0,0,5}));
  
  // Create E_ELEM_TEXT119 text label
  pElemRef = gslc_ElemCreateTxt(&m_gui,E_ELEM_TEXT119,E_PG_MONITOR,(gslc_tsRect){220,210,72,16},
    (char*)"mW/cm2",0,E_BUILTIN10X16);
  gslc_ElemSetFillEn(&m_gui,pElemRef,false);
  gslc_ElemSetTxtCol(&m_gui,pElemRef,((gslc_tsColor){0,0,5}));
  
  // Create E_ELEM_MONITOR_Dosis runtime modifiable text
  static char m_sDisplayText120[5] = "0";
  pElemRef = gslc_ElemCreateTxt(&m_gui,E_ELEM_MONITOR_Dosis,E_PG_MONITOR,(gslc_tsRect){170,240,48,16},
    (char*)m_sDisplayText120,5,E_BUILTIN10X16);
  gslc_ElemSetTxtAlign(&m_gui,pElemRef,GSLC_ALIGN_MID_RIGHT);
  gslc_ElemSetFillEn(&m_gui,pElemRef,false);
  gslc_ElemSetTxtCol(&m_gui,pElemRef,((gslc_tsColor){0,0,5}));
  gslc_ElemSetCol(&m_gui,pElemRef,((gslc_tsColor){59,51,85}),((gslc_tsColor){93,93,129}),GSLC_COL_BLACK);
  m_pElem_MONITOR_Dosis = pElemRef;
  
  // Create E_ELEM_TEXT121 text label
  pElemRef = gslc_ElemCreateTxt(&m_gui,E_ELEM_TEXT121,E_PG_MONITOR,(gslc_tsRect){19,239,96,16},
    (char*)"UV Dosis",0,E_BUILTIN10X16);
  gslc_ElemSetFillEn(&m_gui,pElemRef,false);
  gslc_ElemSetTxtCol(&m_gui,pElemRef,((gslc_tsColor){0,0,5}));
  
  // Create E_ELEM_TEXT122 text label
  pElemRef = gslc_ElemCreateTxt(&m_gui,E_ELEM_TEXT122,E_PG_MONITOR,(gslc_tsRect){220,240,72,16},
    (char*)"mJ/cm2",0,E_BUILTIN10X16);
  gslc_ElemSetFillEn(&m_gui,pElemRef,false);
  gslc_ElemSetTxtCol(&m_gui,pElemRef,((gslc_tsColor){0,0,5}));
  
  // Create E_ELEM_MONITOR_Pause runtime modifiable text
  static char m_sDisplayText123[6] = "PAUSE";
  pElemRef = gslc_ElemCreateTxt(&m_gui,E_ELEM_MONITOR_Pause,E_PG_MONITOR,(gslc_tsRect){330,280,60,16},
    (char*)m_sDisplayText123,6,E_BUILTIN10X16);
  gslc_ElemSetTxtAlign(&m_gui,pElemRef,GSLC_ALIGN_MID_RIGHT);
  gslc_ElemSetFillEn(&m_gui,pElemRef,false);
  gslc_ElemSetTxtCol(&m_gui,pElemRef,((gslc_tsColor){0,0,5}));
  gslc_ElemSetCol(&m_gui,pElemRef,((gslc_tsColor){59,51,85}),((gslc_tsColor){93,93,129}),GSLC_COL_BLACK);
  m_pElem_MONITOR_Pause = pElemRef;
  
  // Create E_ELEM_TEXT124 text label
  pElemRef = gslc_ElemCreateTxt(&m_gui,E_ELEM_TEXT124,E_PG_MONITOR,(gslc_tsRect){10,300,96,16},
    (char*)"TEAM UVO",0,E_BUILTIN10X16);
  gslc_ElemSetFillEn(&m_gui,pElemRef,false);
  gslc_ElemSetTxtCol(&m_gui,pElemRef,((gslc_tsColor){0,0,5}));
  
  // Create E_ELEM_TEXT126 text label
  pElemRef = gslc_ElemCreateTxt(&m_gui,E_ELEM_TEXT126,E_PG_MONITOR,(gslc_tsRect){320,210,60,16},
    (char*)"Ozone",0,E_BUILTIN10X16);
  gslc_ElemSetFillEn(&m_gui,pElemRef,false);
  gslc_ElemSetTxtCol(&m_gui,pElemRef,((gslc_tsColor){0,0,5}));
  
  // Create E_ELEM_TEXT127 runtime modifiable text
  static char m_sDisplayText127[5] = "0";
  pElemRef = gslc_ElemCreateTxt(&m_gui,E_ELEM_TEXT127,E_PG_MONITOR,(gslc_tsRect){380,210,48,16},
    (char*)m_sDisplayText127,5,E_BUILTIN10X16);
  gslc_ElemSetTxtAlign(&m_gui,pElemRef,GSLC_ALIGN_MID_RIGHT);
  gslc_ElemSetFillEn(&m_gui,pElemRef,false);
  gslc_ElemSetTxtCol(&m_gui,pElemRef,((gslc_tsColor){0,0,5}));
  gslc_ElemSetCol(&m_gui,pElemRef,((gslc_tsColor){59,51,85}),((gslc_tsColor){93,93,129}),GSLC_COL_BLACK);
  m_pElem_MONITOR_Intensity127 = pElemRef;
  
  // Create E_ELEM_TEXT128 text label
  pElemRef = gslc_ElemCreateTxt(&m_gui,E_ELEM_TEXT128,E_PG_MONITOR,(gslc_tsRect){430,210,36,16},
    (char*)"ppm",0,E_BUILTIN10X16);
  gslc_ElemSetFillEn(&m_gui,pElemRef,false);
  gslc_ElemSetTxtCol(&m_gui,pElemRef,((gslc_tsColor){0,0,5}));

  // -----------------------------------
  // PAGE: E_PG_ERROR
  
   
  // Create E_ELEM_BOX1 box
  pElemRef = gslc_ElemCreateBox(&m_gui,E_ELEM_BOX1,E_PG_ERROR,(gslc_tsRect){10,10,350,100});
  // Set the callback function to handle all drawing for the element
  gslc_ElemSetDrawFunc(&m_gui,pElemRef,&CbDrawScanner);
  gslc_ElemSetCol(&m_gui,pElemRef,GSLC_COL_GRAY,GSLC_COL_RED_LT4,GSLC_COL_RED_LT4);
  
  // Create E_ELEM_TEXT129 text label
  pElemRef = gslc_ElemCreateTxt(&m_gui,E_ELEM_TEXT129,E_PG_ERROR,(gslc_tsRect){30,30,270,40},
    (char*)"Whoops...",0,E_BUILTIN25X40);
  gslc_ElemSetFillEn(&m_gui,pElemRef,false);
  gslc_ElemSetTxtCol(&m_gui,pElemRef,((gslc_tsColor){0,0,5}));
  gslc_ElemSetCol(&m_gui,pElemRef,GSLC_COL_RED,GSLC_COL_BLACK,GSLC_COL_BLACK);
  
  // Create E_ELEM_TEXT130 text label
  pElemRef = gslc_ElemCreateTxt(&m_gui,E_ELEM_TEXT130,E_PG_ERROR,(gslc_tsRect){20,80,324,16},
    (char*)"An unexpected error occured",0,E_BUILTIN10X16);
  gslc_ElemSetFillEn(&m_gui,pElemRef,false);
  gslc_ElemSetTxtCol(&m_gui,pElemRef,((gslc_tsColor){0,0,5}));
  
  // Create E_ELEM_TEXT131 text label
  pElemRef = gslc_ElemCreateTxt(&m_gui,E_ELEM_TEXT131,E_PG_ERROR,(gslc_tsRect){20,170,72,16},
    (char*)"Error:",0,E_BUILTIN10X16);
  gslc_ElemSetFillEn(&m_gui,pElemRef,false);
  gslc_ElemSetTxtCol(&m_gui,pElemRef,((gslc_tsColor){0,0,5}));
  
  // Create E_ELEM_ERROR_Error1 runtime modifiable text
  static char m_sDisplayText132[25] = "Default Error Message";
  pElemRef = gslc_ElemCreateTxt(&m_gui,E_ELEM_ERROR_Error1,E_PG_ERROR,(gslc_tsRect){100,170,288,16},
    (char*)m_sDisplayText132,25,E_BUILTIN10X16);
  gslc_ElemSetFillEn(&m_gui,pElemRef,false);
  gslc_ElemSetTxtCol(&m_gui,pElemRef,((gslc_tsColor){0,0,5}));
  m_pElem_ERROR_Error1 = pElemRef;
  
  // Create E_ELEM_ERROR_Error2 runtime modifiable text
  static char m_sDisplayText133[25] = "Default Error Message";
  pElemRef = gslc_ElemCreateTxt(&m_gui,E_ELEM_ERROR_Error2,E_PG_ERROR,(gslc_tsRect){100,190,288,16},
    (char*)m_sDisplayText133,25,E_BUILTIN10X16);
  gslc_ElemSetFillEn(&m_gui,pElemRef,false);
  gslc_ElemSetTxtCol(&m_gui,pElemRef,((gslc_tsColor){0,0,5}));
  m_pElem_ERROR_Error2 = pElemRef;
  
  // Create E_ELEM_ERROR_Error3 runtime modifiable text
  static char m_sDisplayText134[25] = "Default Error Message";
  pElemRef = gslc_ElemCreateTxt(&m_gui,E_ELEM_ERROR_Error3,E_PG_ERROR,(gslc_tsRect){100,210,288,16},
    (char*)m_sDisplayText134,25,E_BUILTIN10X16);
  gslc_ElemSetFillEn(&m_gui,pElemRef,false);
  gslc_ElemSetTxtCol(&m_gui,pElemRef,((gslc_tsColor){0,0,5}));
  m_pElem_ERROR_Error3 = pElemRef;
  
  // Create E_ELEM_ERROR_Error4 runtime modifiable text
  static char m_sDisplayText135[25] = "Default Error Message";
  pElemRef = gslc_ElemCreateTxt(&m_gui,E_ELEM_ERROR_Error4,E_PG_ERROR,(gslc_tsRect){100,230,288,16},
    (char*)m_sDisplayText135,25,E_BUILTIN10X16);
  gslc_ElemSetFillEn(&m_gui,pElemRef,false);
  gslc_ElemSetTxtCol(&m_gui,pElemRef,((gslc_tsColor){0,0,5}));
  m_pElem_ERROR_Error4 = pElemRef;
  
  // Create E_ELEM_TEXT136 runtime modifiable text
  static char m_sDisplayText136[9] = "CONTINUE";
  pElemRef = gslc_ElemCreateTxt(&m_gui,E_ELEM_TEXT136,E_PG_ERROR,(gslc_tsRect){360,270,96,16},
    (char*)m_sDisplayText136,9,E_BUILTIN10X16);
  gslc_ElemSetTxtAlign(&m_gui,pElemRef,GSLC_ALIGN_MID_RIGHT);
  gslc_ElemSetFillEn(&m_gui,pElemRef,false);
  gslc_ElemSetTxtCol(&m_gui,pElemRef,((gslc_tsColor){0,0,5}));
  gslc_ElemSetCol(&m_gui,pElemRef,((gslc_tsColor){59,51,85}),((gslc_tsColor){93,93,129}),GSLC_COL_BLACK);
  m_pElem_MONITOR_Stop136 = pElemRef;
  
  // Create E_ELEM_TEXT137 text label
  pElemRef = gslc_ElemCreateTxt(&m_gui,E_ELEM_TEXT137,E_PG_ERROR,(gslc_tsRect){10,300,96,16},
    (char*)"TEAM UVO",0,E_BUILTIN10X16);
  gslc_ElemSetFillEn(&m_gui,pElemRef,false);
  gslc_ElemSetTxtCol(&m_gui,pElemRef,((gslc_tsColor){0,0,5}));
//<InitGUI !End!>

//<Startup !Start!>
  gslc_GuiRotate(&m_gui, 1);
//<Startup !End!>

}

#endif // end _GUISLICE_GEN_H
