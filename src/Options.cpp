#include "Options.hpp"

void Options::parseLESModelString(string vmKey, string inString, LESModel &currentType){

    if(vm.count(vmKey)){
        if(strcmp(inString.c_str(), "NOMODEL")==0){
            currentType = NOMODEL;
        }else if(strcmp(inString.c_str(), "VREMAN")==0){
            currentType = VREMAN;
        }else if(strcmp(inString.c_str(), "DSM")==0){
            currentType = DSM;
	}else{
            cout << " > UNKNOWN LES MODEL TYPE SPECIFIED: " << inString << endl;
            MPI_Abort(MPI_COMM_WORLD, -10);
        }
        cout << " > " << vmKey << " = " << inString << endl;
    }else{
        cout << " > " << vmKey << " = " << inString << " not specified " << endl;
        MPI_Abort(MPI_COMM_WORLD, -10);
    }
}

void Options::parseStatsAvgTypeString(string vmKey, string inString, StatsAvgType &currentType){

    if(vm.count(vmKey)){
        if(strcmp(inString.c_str(), "NONE")==0){
            currentType = NONE;
        }else if(strcmp(inString.c_str(), "XI1_AVG")==0){
            currentType = XI1_AVG;
        }else if(strcmp(inString.c_str(), "XI2_AVG")==0){
            currentType = XI2_AVG;
        }else if(strcmp(inString.c_str(), "XI3_AVG")==0){
            currentType = XI3_AVG;
        }else if(strcmp(inString.c_str(), "LOCAL")==0){
            currentType = LOCAL;
        }else if(strcmp(inString.c_str(), "GLOBAL")==0){
            currentType = GLOBAL;
	}else{
            cout << " > UNKNOWN AVERAGING TYPE SPECIFIED: " << inString << endl;
            MPI_Abort(MPI_COMM_WORLD, -10);
        }
        cout << " > " << vmKey << " = " << inString << endl;
    }else{
        cout << " > " << vmKey << " = " << inString << " not specified " << endl;
        MPI_Abort(MPI_COMM_WORLD, -10);
    }
}

void Options::parseRKTypeFromString(string vmKey, string inString, RKType &currentType){

    if(vm.count(vmKey)){
        if(strcmp(inString.c_str(), "TVDRK3")==0){
            currentType = TVDRK3;
        }else if(strcmp(inString.c_str(), "RK4")==0){
            currentType = RK4;
        }else if(strcmp(inString.c_str(), "KENRK4")==0){
            currentType = KENRK4;
        }else if(strcmp(inString.c_str(), "LSLDDRK4")==0){
            currentType = LSLDDRK4;
	}else{
            cout << " > UNKNOWN RUNGE-KUTTA TYPE SPECIFIED: " << inString << endl;
            MPI_Abort(MPI_COMM_WORLD, -10);
        }
        cout << " > " << vmKey << " = " << inString << endl;
    }else{
        cout << " > " << vmKey << " = " << inString << " not specified " << endl;
        MPI_Abort(MPI_COMM_WORLD, -10);
    }
}

void Options::parseFilterTypeFromString(string vmKey, string inString, FilterType &currentType){

    if(vm.count(vmKey)){
        if(strcmp(inString.c_str(), "COMPACT8")==0){
            currentType = COMPACT8;
        }else if(strcmp(inString.c_str(), "COMPACT10")==0){
            currentType = COMPACT10;
	}else{
            cout << " > UNKNOWN FILTER TYPE SPECIFIED: " << inString << endl;
            MPI_Abort(MPI_COMM_WORLD, -10);
        }
        cout << " > " << vmKey << " = " << inString << endl;
    }else{
        cout << " > " << vmKey << " = " << inString << " not specified " << endl;
        MPI_Abort(MPI_COMM_WORLD, -10);
    }
}



void Options::parseFDTypeFromString(string vmKey, string inString, FDType &currentType){

    if(vm.count(vmKey)){
        if(strcmp(inString.c_str(), "CD2")==0){
            currentType = CD2;
        }else if(strcmp(inString.c_str(), "PADE6")==0){
            currentType = PADE6;
        }else if(strcmp(inString.c_str(), "PENTA10")==0){
            currentType = PENTA10;
	}else{
            cout << " > UNKNOWN FINITE DIFFERENCE TYPE SPECIFIED: " << inString << endl;
            MPI_Abort(MPI_COMM_WORLD, -10);
        }
        cout << " > " << vmKey << " = " << inString << endl;
    }else{
        cout << " > " << vmKey << " = " << inString << " not specified " << endl;
        MPI_Abort(MPI_COMM_WORLD, -10);
    }
}



void Options::parseTSTypeFromString(string vmKey, string inString, TimeSteppingType &currentType){

    if(vm.count(vmKey)){
        if(strcmp(inString.c_str(), "CONST_CFL")==0){
            currentType = CONST_CFL;
        }else if(strcmp(inString.c_str(), "CONST_DT")==0){
            currentType = CONST_DT;
        }else{
            cout << " > UNKNOWN TIMESTEPPING TYPE SPECIFIED: " << inString << endl;
            MPI_Abort(MPI_COMM_WORLD, -10);
        }
        cout << " > " << vmKey << " = " << inString << endl;
    }else{
        cout << " > " << vmKey << " = " << inString << " not specified " << endl;
        MPI_Abort(MPI_COMM_WORLD, -10);
    }
}

void Options::parseBCTypeFromString(string vmKey, string inString, BCType &currentType){
    if(vm.count(vmKey)){
        if(strcmp(inString.c_str(), "PERIODIC_SOLVE")==0){
            currentType = PERIODIC_SOLVE;
        }else if(strcmp(inString.c_str(), "DIRICHLET_SOLVE")==0){
            currentType = DIRICHLET_SOLVE;
        }else{
            cout << " > UNKNOWN BOUNDARY TYPE SPECIFIED: " << inString << endl;
            MPI_Abort(MPI_COMM_WORLD, -10);
        }
        cout << " > " << vmKey << " = " << inString << endl;
    }else{
        cout << " > " << vmKey << " = " << inString << " not specified " << endl;
        MPI_Abort(MPI_COMM_WORLD, -10);
    }
}

void Options::parseBCKindFromString(string vmKey, string inString, BCKind &currentType){

    if(vm.count(vmKey)){
        if(strcmp(inString.c_str(), "INTERNALLY_PERIODIC")==0){
            currentType = INTERNALLY_PERIODIC;
        }else if(strcmp(inString.c_str(), "PERIODIC")==0){
            currentType = PERIODIC;
        }else if(strcmp(inString.c_str(), "ADIABATIC_WALL")==0){
            currentType = ADIABATIC_WALL;
        }else if(strcmp(inString.c_str(), "SPONGE")==0){
            currentType = SPONGE;
        }else if(strcmp(inString.c_str(), "CONST_T_WALL")==0){
            currentType = CONST_T_WALL;
        }else if(strcmp(inString.c_str(), "MOVING_ADIABATIC_WALL")==0){
            currentType = MOVING_ADIABATIC_WALL;
        }else if(strcmp(inString.c_str(), "INLET")==0){
            currentType = INLET;
        }else{
            cout << " > UNKNOWN BOUNDARY TYPE SPECIFIED: " << inString << endl;
            MPI_Abort(MPI_COMM_WORLD, -10);
        }

        cout << " > " << vmKey << " = " << inString << endl;

    }else{
        cout << " > " << vmKey << " = " << inString << " not specified" << endl;
        MPI_Abort(MPI_COMM_WORLD, -10);
    }
}

void Options::bcValidation(){

   //do X Direction first
   if(bcXType == PERIODIC_SOLVE){
	
	//If not periodic or internally periodic
	if(!(bcX0 == PERIODIC || bcX0 == INTERNALLY_PERIODIC)){
	    cout << " > bcXType PERIODIC_SOLVE must have bcX0 be PERIODIC or INTERNALLY PERIODIC, currently bcX0 = " << bcX0_str << endl;
            MPI_Abort(MPI_COMM_WORLD, -10);
	}

	//If not periodic or internally periodic
	if(!(bcX1 == PERIODIC || bcX1 == INTERNALLY_PERIODIC)){
	    cout << " > bcXType PERIODIC_SOLVE must have bcX1 be PERIODIC or INTERNALLY PERIODIC, currently bcX1 = " << bcX1_str << endl;
            MPI_Abort(MPI_COMM_WORLD, -10);
	}

	//If periodic and internally periodic at opposite ends
	if((bcX0 == PERIODIC && bcX1 == INTERNALLY_PERIODIC) || (bcX0 == INTERNALLY_PERIODIC && bcX1 == PERIODIC)){
	    cout << " > bcX0 and bcX1 have mismatched periodic conditions: bcX0 = " << bcX0_str << ", bcX1 = " << bcX1_str << endl; 
            MPI_Abort(MPI_COMM_WORLD, -10);
	} 
   }

   if(bcXType == DIRICHLET_SOLVE){
	//If trying to use periodic conditions in dirichlet solve mode
	if(bcX0 == PERIODIC || bcX0 == INTERNALLY_PERIODIC){
	    cout << " > bcXType DIRICHLET_SOLVE cannot have bcX0 be PERIODIC or INTERNALLY PERIODIC, currently bcX0 = " << bcX0_str << endl;
            MPI_Abort(MPI_COMM_WORLD, -10);
	}

	//If trying to use periodic conditions in dirichlet solve mode
	if(bcX1 == PERIODIC || bcX1 == INTERNALLY_PERIODIC){
	    cout << " > bcXType DIRICHLET_SOLVE cannot have bcX1 be PERIODIC or INTERNALLY PERIODIC, currently bcX1 = " << bcX1_str << endl;
            MPI_Abort(MPI_COMM_WORLD, -10);
	}
   }




   //do Y Direction first
   if(bcYType == PERIODIC_SOLVE){
	
	//If not periodic or internally periodic
	if(!(bcY0 == PERIODIC || bcY0 == INTERNALLY_PERIODIC)){
	    cout << " > bcYType PERIODIC_SOLVE must have bcY0 be PERIODIC or INTERNALLY PERIODIC, currently bcY0 = " << bcY0_str << endl;
            MPI_Abort(MPI_COMM_WORLD, -10);
	}

	//If not periodic or internally periodic
	if(!(bcY1 == PERIODIC || bcY1 == INTERNALLY_PERIODIC)){
	    cout << " > bcYType PERIODIC_SOLVE must have bcY1 be PERIODIC or INTERNALLY PERIODIC, currently bcY1 = " << bcY1_str << endl;
            MPI_Abort(MPI_COMM_WORLD, -10);
	}

	//If periodic and internally periodic at opposite ends
	if((bcY0 == PERIODIC && bcY1 == INTERNALLY_PERIODIC) || (bcY0 == INTERNALLY_PERIODIC && bcY1 == PERIODIC)){
	    cout << " > bcY0 and bcY1 have mismatched periodic conditions: bcY0 = " << bcY0_str << ", bcY1 = " << bcY1_str << endl; 
            MPI_Abort(MPI_COMM_WORLD, -10);
	} 
   }

   if(bcYType == DIRICHLET_SOLVE){
	//If trying to use periodic conditions in dirichlet solve mode
	if(bcY0 == PERIODIC || bcY0 == INTERNALLY_PERIODIC){
	    cout << " > bcYType DIRICHLET_SOLVE cannot have bcY0 be PERIODIC or INTERNALLY PERIODIC, currently bcY0 = " << bcY0_str << endl;
            MPI_Abort(MPI_COMM_WORLD, -10);
	}

	//If trying to use periodic conditions in dirichlet solve mode
	if(bcY1 == PERIODIC || bcY1 == INTERNALLY_PERIODIC){
	    cout << " > bcYType DIRICHLET_SOLVE cannot have bcY1 be PERIODIC or INTERNALLY PERIODIC, currently bcY1 = " << bcY1_str << endl;
            MPI_Abort(MPI_COMM_WORLD, -10);
	}
   }


   //do Z Direction first
   if(bcZType == PERIODIC_SOLVE){
	
	//If not periodic or internally periodic
	if(!(bcZ0 == PERIODIC || bcZ0 == INTERNALLY_PERIODIC)){
	    cout << " > bcZType PERIODIC_SOLVE must have bcZ0 be PERIODIC or INTERNALLY PERIODIC, currently bcZ0 = " << bcZ0_str << endl;
            MPI_Abort(MPI_COMM_WORLD, -10);
	}

	//If not periodic or internally periodic
	if(!(bcZ1 == PERIODIC || bcZ1 == INTERNALLY_PERIODIC)){
	    cout << " > bcZType PERIODIC_SOLVE must have bcZ1 be PERIODIC or INTERNALLY PERIODIC, currently bcZ1 = " << bcZ1_str << endl;
            MPI_Abort(MPI_COMM_WORLD, -10);
	}

	//If periodic and internally periodic at opposite ends
	if((bcZ0 == PERIODIC && bcZ1 == INTERNALLY_PERIODIC) || (bcZ0 == INTERNALLY_PERIODIC && bcZ1 == PERIODIC)){
	    cout << " > bcZ0 and bcZ1 have mismatched periodic conditions: bcZ0 = " << bcZ0_str << ", bcZ1 = " << bcZ1_str << endl; 
            MPI_Abort(MPI_COMM_WORLD, -10);
	} 
   }

   if(bcZType == DIRICHLET_SOLVE){
	//If trying to use periodic conditions in dirichlet solve mode
	if(bcZ0 == PERIODIC || bcZ0 == INTERNALLY_PERIODIC){
	    cout << " > bcZType DIRICHLET_SOLVE cannot have bcZ0 be PERIODIC or INTERNALLY PERIODIC, currently bcZ0 = " << bcZ0_str << endl;
            MPI_Abort(MPI_COMM_WORLD, -10);
	}

	//If trying to use periodic conditions in dirichlet solve mode
	if(bcZ1 == PERIODIC || bcZ1 == INTERNALLY_PERIODIC){
	    cout << " > bcZType DIRICHLET_SOLVE cannot have bcZ1 be PERIODIC or INTERNALLY PERIODIC, currently bcZ1 = " << bcZ1_str << endl;
            MPI_Abort(MPI_COMM_WORLD, -10);
	}
   }

}

void Options::parseSpongeFromString(string vmKey, string inString, SpongeKind &spongeKind){

    if(vm.count(vmKey)){
        if(strcmp(inString.c_str(), "RECTILINEAR")==0){
            spongeKind = RECTILINEAR;
        }else if(strcmp(inString.c_str(), "CYLINDRICAL")==0){
            spongeKind = CYLINDRICAL;
        }else{
            cout << " > UNKNOWN SPONGE TYPE SPECIFIED: " << inString << endl;
            MPI_Abort(MPI_COMM_WORLD, -10);
        }

        cout << " > " << vmKey << " = " << inString << endl;

    }else{
        cout << " > " << vmKey << " = " << inString << " not specified" << endl;
        MPI_Abort(MPI_COMM_WORLD, -10);
    }
}


