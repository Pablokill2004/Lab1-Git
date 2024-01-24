class let{

    AbstractSymbol var;
    AbstractSymbol Type;
    AbstractSymbol init;
     AbstractSymbol body;

     semant(tablaO, tablaM, tablaC){
        
        init.semant(tablaO, tablaM, tablaC);//<----T0

        O.enterScope(); // <----O[T/x],addId,exit
        O.addId(var, Type);
        
        body.semant(tablaO, tablaM, tablaC);//<----T1

        O.exitScope();

        if(!(isSubtype(init.getType,Type))){
            mensajeError();
        }

        this.setType(body.getType() );


     }

}