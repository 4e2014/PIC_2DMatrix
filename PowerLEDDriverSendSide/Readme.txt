
/*******************************************************************************
*  ??????????????????????????                        *
*                                                                              *
*  ??:?????????????????????????                     *
*       LED?RC3(14???)?470???????????????                  *
*       ????????????????????????                       *
*       ????4MHz????????????? 128 ? ((1/4MHz)x4)x128=128us ????         *
*       255?????????????128x255=32640us(32.640ms) ?1????????     *
*       ????1000000/32640=30.637??????????????? ?????  *
*       ((1?/????)/(????????? x(4x1000000 /???????)))?? *
*       195?????????????((1000000/195)/(128*(4*1000000/4000000)))=40.06410*
*       ???40?????????????? 256-195=61 ??????????????   *
* ============================================================================ *
*  VERSION DATE        BY                    CHANGE/COMMENT                    *
* ---------------------------------------------------------------------------- *
*  1.00    2012-06-17  ?????(????)  Create                            *
* ============================================================================ *
*  PIC 16F1938                                                                 *
*  MPLAB IDE(V8.84)                                                            *
*  MPLAB(R) XC8 C Compiler Version 1.00                                        *
*******************************************************************************/


// ???????????????
// CLKOUT????RA6????????(CLKOUTEN_OFF)????????????(INTIO)
// ???????????(FCMEN_OFF)?????????????????????(IESO_OFF)
// ????????????ON(BOREN_ON)???ON??64ms??????????????(PWRTEN_ON)
// ???????????????(WDTE_OFF)?
// ??????????????????????(RE3)??????(MCLRE_OFF)
// ?????????????????(CP_OFF)???????????????(CPD_OFF)



// ???????????????
// ???????32MHz????????(PLLEN_OFF)
// ?????????????????????????????(STVREN_ON)
// ?????????????????(LVP_OFF)
// Flash??????????(WRT_OFF)?????????????(2.5V)??(BORV_HI)
// ??????????????????????(VCAPEN_OFF)




/*
int main(int argc, char** argv) {

    return (EXIT_SUCCESS);
}

*/