
void hardwareInput(){
  boton_0();
  boton_1();
  Serial_lecture();
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



////////////////////
// Serial lecture //
////////////////////

void serial_lecture(){





  
}
