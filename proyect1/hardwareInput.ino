
void hardwareInput(){
  boton_0();
  boton_1();
  Serial_lecture();
}

////////////////////
// Serial lecture //
////////////////////

/*
Usually for jobs with serial slaves, we have a known format, a payload, with constant headers and a tail, to close the message. 
So the  machine state for lecture of the serial port has to filter the message by the header-body-tail components or the lecture it is going to be all trash

*/

void serial_lecture(){

 if (Serial1.available()){                                 // Serial1 AVAILABLE
    controlChar = Serial1.read();                          // READ ONE CHAR 
    Serial.print(controlChar);                             // Print CHAR 
  }
  switch (State_serial_lecture){


    //////////////////////////////////////
    // E0 : FILTER BY FIRST CHAR HEADER //
    //////////////////////////////////////
    case 0:
    break;

    

    ////////////////////////////////////////
    // E1 : FILTER BY SECOND CHAR HEADER //
    ///////////////////////////////////////
    
    case 1:
    break;


    ////////////////////////////////////////
    // E2 : FILTER BY THIRD CHAR HEADER //
    ///////////////////////////////////////
    
    case 2:
    break;


    /////////////////////////////////////////////////////////////////////////
    // E3 : RECOPILATION OF BODY MSSG - READ UNTIL FIRST TAIL SPECIAL CHAR //
    /////////////////////////////////////////////////////////////////////////
    
    case 3:
    break;

    ///////////////////////////////////////////////
    // E4 : RECOPILATION OF FIRST CHAR OF TAIL  //
    //////////////////////////////////////////////
    
    case 4:
    break;
    

    ///////////////////////////////////////////////
    // E5 : RECOPILATION OF SECOND CHAR OF TAIL  //
    //////////////////////////////////////////////
    
    case 5:
    break;

    
    ///////////////////////////////////////////////
    // E6 : RECOPILATION OF THIRD CHAR OF TAIL  //
    //////////////////////////////////////////////
    
    case 6:
    break;

    ////////////////////////////////////////
    // E7 : END OF MSSG - GO BACK TO E0   //
    ///////////////////////////////////////
    
    case 7:
    break;
    
    
    

    
  }
}




/////////////////////////////////////////
// Activacion de boton 0 (push button) //
/////////////////////////////////////////

void boton_0{
  switch(State_button_0){
    
    /////////////////////////////
    // E0: WAIT FOR ACTIVATION //
    ////////////////////////////
    
    case 0:
      flag_button_0 = 0;
      
    break;

    //////////////////////////////////////////////////////
    // E1: WAIT FOR REAL ACTIVATION (spring phenomenon) //
    /////////////////////////////////////////////////////
    
    case 1:

    break;

    /////////////////
    // E2: FLAG UP //
    /////////////////
    
    case 2:
        flag_button_0 = 1;
    break;
    
    ////////////////////////////////
    // E3: WAIT FOR DE-ACTIVATION //
    ////////////////////////////////
    case 3:
      
    break;

    /////////////////////////////////////
    // E4: WAIT FOR REAL DE-ACTIVATION //
    /////////////////////////////////////
    case 4:
      State_button_0 = 0
    break;

    
    default:
    State_button_0 = 0;
    break;
    
  }


  
}



////////////////////////////////////////////
// Activacion de boton 1 (switch button) //
///////////////////////////////////////////

void boton_1{

  switch(State_button_1){

    /////////////////////////////
    // E0: WAIT FOR ACTIVATION //
    /////////////////////////////
    case 0:

    break;

    //////////////////////////////////////////////////////
    // E1: WAIT FOR REAL ACTIVATION (spring phenomenon) //
    //////////////////////////////////////////////////////
    
    case 1:

    break;
    
    /////////////////
    // E2: FLAG UP //
    /////////////////
    
    case 2:
      
      flag_button_0 = 1;
      State_button_1 = 0;
      
    break;

    default:
    State_button_1 = 0;
    break;

    
  }
}



