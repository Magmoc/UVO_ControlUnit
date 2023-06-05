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
enum {E_PG_BASE,E_PG_SETUP};
enum {E_ELEM_SETUP_Dosis_255nm,E_ELEM_SETUP_Dosis_275nm
      ,E_ELEM_SETUP_Dosis_285nm,E_ELEM_SETUP_Dosis_395nm
      ,E_ELEM_SETUP_Hours,E_ELEM_SETUP_Intensity_255nm
      ,E_ELEM_SETUP_Intensity_275nm,E_ELEM_SETUP_Intensity_285nm
      ,E_ELEM_SETUP_Intensity_395nm,E_ELEM_SETUP_Minutes
      ,E_ELEM_SETUP_MotorIntensity,E_ELEM_SETUP_PERCENTAGESIGN_395nm
      ,E_ELEM_SETUP_Seconds,E_ELEM_SETUP_TEXT_255nm
      ,E_ELEM_SETUP_TEXT_275nm,E_ELEM_SETUP_TEXT_285nm
      ,E_ELEM_SETUP_TEXT_395nm,E_ELEM_SETUP_TEXT_DOSIS
      ,E_ELEM_SETUP_TEXT_DURATION,E_ELEM_SETUP_TEXT_MOTORINTENSITY
      ,E_ELEM_SETUP_TEXT_PERCENTAGESIGN_255nm
      ,E_ELEM_SETUP_TEXT_PERCENTAGESIGN_275nm
      ,E_ELEM_SETUP_TEXT_PERCENTAGESIGN_285nm
      ,E_ELEM_SETUP_TEXT_PERCENTSIGN_MOTORINTENSITY
      ,E_ELEM_SETUP_TEXT_TITLE,E_ELEM_SETUP_TEXT_WAVELENGTH
      ,E_ELEM_TEXT63,E_ELEM_TEXT64};
// Must use separate enum for fonts with MAX_FONT at end to use gslc_FontSet.
enum {E_BUILTIN10X16,E_SEVEN_SEGMENT16,MAX_FONT};
//<Enum !End!>

// ------------------------------------------------
// Instantiate the GUI
// ------------------------------------------------

// ------------------------------------------------
// Define the maximum number of elements and pages
// ------------------------------------------------
//<ElementDefines !Start!>
#define MAX_PAGE                2

#define MAX_ELEM_PG_BASE 0 // # Elems total on page
#define MAX_ELEM_PG_BASE_RAM MAX_ELEM_PG_BASE // # Elems in RAM

#define MAX_ELEM_PG_SETUP 28 // # Elems total on page
#define MAX_ELEM_PG_SETUP_RAM MAX_ELEM_PG_SETUP // # Elems in RAM
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

#define MAX_STR                 100

//<GUI_Extra_Elements !End!>

// ------------------------------------------------
// Program Globals
// ------------------------------------------------

// Element References for direct access
//<Extern_References !Start!>
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
    if (!gslc_FontSet(&m_gui,E_SEVEN_SEGMENT16,GSLC_FONTREF_PTR,&Seven_Segment16pt7b,1)) { return; }
//<Load_Fonts !End!>

//<InitGUI !Start!>
  gslc_PageAdd(&m_gui,E_PG_BASE,m_asBasePage1Elem,MAX_ELEM_PG_BASE_RAM,m_asBasePage1ElemRef,MAX_ELEM_PG_BASE);
  gslc_PageAdd(&m_gui,E_PG_SETUP,m_asPage1Elem,MAX_ELEM_PG_SETUP_RAM,m_asPage1ElemRef,MAX_ELEM_PG_SETUP);

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
  m_pElem_SETUP_Intensity_255nm = pElemRef;
  
  // Create E_ELEM_SETUP_TEXT_DOSIS text label
  pElemRef = gslc_ElemCreateTxt(&m_gui,E_ELEM_SETUP_TEXT_DOSIS,E_PG_SETUP,(gslc_tsRect){220,60,168,16},
    (char*)"Dosis [J/cm^2]",0,E_BUILTIN10X16);
  gslc_ElemSetFillEn(&m_gui,pElemRef,false);
  gslc_ElemSetTxtCol(&m_gui,pElemRef,((gslc_tsColor){0,0,5}));
  
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
  pElemRef = gslc_ElemCreateTxt(&m_gui,E_ELEM_SETUP_TEXT_TITLE,E_PG_SETUP,(gslc_tsRect){88,10,304,22},
    (char*)"SEED DESINFECTOR 9000!",0,E_SEVEN_SEGMENT16);
  gslc_ElemSetFillEn(&m_gui,pElemRef,false);
  gslc_ElemSetTxtCol(&m_gui,pElemRef,((gslc_tsColor){0,0,5}));
  
  // Create E_ELEM_SETUP_TEXT_PERCENTSIGN_MOTORINTENSITY text label
  pElemRef = gslc_ElemCreateTxt(&m_gui,E_ELEM_SETUP_TEXT_PERCENTSIGN_MOTORINTENSITY,E_PG_SETUP,(gslc_tsRect){260,260,12,16},
    (char*)"%",0,E_BUILTIN10X16);
  gslc_ElemSetFillEn(&m_gui,pElemRef,false);
  gslc_ElemSetTxtCol(&m_gui,pElemRef,((gslc_tsColor){0,0,5}));
//<InitGUI !End!>

//<Startup !Start!>
  gslc_GuiRotate(&m_gui, 1);
//<Startup !End!>

}

#endif // end _GUISLICE_GEN_H
