#include <stdio.h>
#include <iostream>
#include <stdlib.h>

int function1(int mesGan, int totGan);
int function2(int mozPerc);

int main() 
{
    
   int mozCant1 = 0, mozCant2 = 0, mozCant3 = 0, mozCant4 = 0, mozCant5 = 0, mozCant6 = 0;
   int mozPrec1 = 0, mozPrec2 = 0, mozPrec3 = 0, mozPrec4 = 0, mozPrec5 = 0, mozPrec6 = 0;
   
   int mesGan1 = 0, mesGan2 = 0, mesGan3 = 0, mesGan4 = 0, mesGan5 = 0, mesGan6 = 0, mesGan7 = 0, mesGan8 = 0, mesGan9 = 0, mesGan10 = 0, mesGan11 = 0, mesGan12 = 0;
   
   int totFact = 0;
   int totGan = 0;
   int mozMas = 0;
   int perMas = 0;
   int fact45 = 0;
   int mesMas = 0;
   
   
   int menu_item = 0;

   
     while (menu_item != 11){	
      
	
	//system("clear");
	
	system("clear");
	printf("\
Seleccione el INPUT>\n\
1.- Introducir facturas\n\
2.- Personas atendidas por mozo\n\
3.- Cantidad de facturas realizadas\n\
4.- Caja diaria realizada\n\
5.- Monto facturado por cada mesa en total\n\
6.- Porcentual facturado por cada mozo sobre el total\n\
7.- Ganancia *mozo +5% venta\n\
8.- Cual mozo atendio mas personas en total\n\
9.- Cuantas facturas superaron 45$\n\
10.- Mesa que mas clientes tuvo\n\
11.- Salir\n\
 ");
	
	printf("INPUT> ");
	scanf("%d", &menu_item);
	
	switch(menu_item)
	  {
	   case 1:
	     printf("Item: %d\n", menu_item);
	     
	     
	     //Variables temporales de instancia
	     int factNum;
	     
	     int mozNum;
	     int mesNum;
	     
	     int cant;
	     int cost;
	    
	     //--------------------
	     
	     do { // Factura
		printf("Numero de factura: ");
		scanf("%d", &factNum);
		
		if (factNum == 0) 
		  {
		     break;
		  }
		
		
		printf("#MOZO: ");
		scanf("%d", &mozNum);
		printf("#MESA: ");
		scanf("%d", &mesNum);
		printf("#PERS: ");
		scanf("%d", &cant);
		printf("#COST: ");
		scanf("%d", &cost);
		
		//Agregar los datos solo si estan en los rangos validos
		if (mozNum > 0 && mozNum <= 6 && mesNum > 0 && mesNum <= 12) 
		  {     
		     totFact++; //Sumamos la cantidad de facturas
		     totGan += cost; //Sumamos toda la ganancia obtenida
		     
		     if (cant > perMas) 
		       {
			  mozMas = mozNum;
			  perMas = cant;
			  mesMas = mesNum;
		       }
		     
		     if (cost > 45)
		       {
			  fact45++;
		       }
		     		    		     
		     switch(mesNum)
		       {
			case 1:	 mesGan1 += cost;
			  break;			  
			case 2:	 mesGan2 += cost;
			  break;
			case 3:	 mesGan3 += cost;
			  break;			  
			case 4:	 mesGan4 += cost;
			  break;			  
			case 5:	 mesGan5 += cost;
			  break;			  
			case 6:	 mesGan6 += cost;
			  break;			  
			case 7:	 mesGan7 += cost;
			  break;			 
			case 8:  mesGan8 += cost;
			  break;		    
			case 9:	 mesGan9 += cost;
			  break;			  
			case 10: mesGan10 += cost;
			  break;			  
			case 11: mesGan11 += cost;
			  break;			  
			case 12: mesGan12 += cost;
			  break;			 
		       }
        
		     switch(mozNum) 
		       {
			case 1:
			  mozCant1 += cant;
			  mozPrec1 += cost;
			  break;
			case 2:
			  mozCant2 += cant;
			  mozPrec2 += cost;
			  break;
			case 3:
			  mozCant3 += cant;
			  mozPrec3 += cost;
			  break;
			case 4:
			  mozCant4 += cant;
			  mozPrec4 += cost;
			  break;
			case 5:
			  mozCant5 += cant;
			  mozPrec6 += cost;
			  break;
			case 6:
			  mozCant6 += cant;
			  mozPrec6 += cost;
			  break;
		       }
		     
		  }	
		else
		  {
		     printf("Fuera del rango de mozos[1-6] y mesas[1-12] permitido.\n");
		  }
	     } while (factNum != 0);
	     
	     break;
	     
	     
	      //Realizamos esto hasta que 'factNum' sea distinto de 0
	     
	     
	     
	   case 2:

	     printf("MOZO: 1 ATENDIO: %d\n", mozCant1);
	     printf("MOZO: 2 ATENDIO: %d\n", mozCant2);
	     printf("MOZO: 3 ATENDIO: %d\n", mozCant3);
	     printf("MOZO: 4 ATENDIO: %d\n", mozCant4);
	     printf("MOZO: 5 ATENDIO: %d\n", mozCant5);
	     printf("MOZO: 6 ATENDIO: %d\n", mozCant6);
	     
	     printf("Presione enter para volver al menu");
	     getchar();
	     getchar();	     	     
	     break;
	     
	   case 3:
	     
	     printf("TOTAL FACTURAS: %d\n", totFact);
	     printf("Presione enter para volver al menu");
	     getchar();
	     getchar();
	     break;
	     
	   case 4:
	     
	     printf("GANANCIA TOTAL: %d\n", totGan);
	     printf("Presione enter para volver al menu");
	     getchar();
	     getchar();
	     break;
	     
	   case 5:
	     
	     printf("MESA: 1 GANANCIA: %d\n", mesGan1);
	     printf("MESA: 2 GANANCIA: %d\n", mesGan2);
	     printf("MESA: 3 GANANCIA: %d\n", mesGan3);
	     printf("MESA: 4 GANANCIA: %d\n", mesGan4);
	     printf("MESA: 5 GANANCIA: %d\n", mesGan5);
	     printf("MESA: 6 GANANCIA: %d\n", mesGan6);
	     printf("MESA: 7 GANANCIA: %d\n", mesGan7);
	     printf("MESA: 8 GANANCIA: %d\n", mesGan8);
	     printf("MESA: 9 GANANCIA: %d\n", mesGan9);
	     printf("MESA: 10 GANANCIA: %d\n", mesGan10);
	     printf("MESA: 11 GANANCIA: %d\n", mesGan11);
	     printf("MESA: 12 GANANCIA: %d\n", mesGan12);
	     printf("Presione enter para volver al menu");
	     getchar();
	     getchar();
	     break;
	     
	   case 6:
	     
	     
	    
	     float porcTot;
	     porcTot = totGan / mozPrec1 * 100;
	     
	     printf("El MOZO gano  %0.2f\n",  porcTot);
	       
	     
	     
	     
	     printf("Presione enter para volver al menu");
	     getchar();
	     getchar();
	     break;
	     
	   case 7:	     
	     
	     printf("Presione enter para volver al menu");
	     getchar();
	     getchar();
	     break;
	     
	   case 8:
	     
	     printf("MOZO: %d ATENDIO: %d\n", mozMas, perMas);
	     printf("Presione enter para volver al menu");
	     getchar();
	     getchar();
	     break;
	     
	   case 9:	  
	     
	     printf("FACTURADO >45: %d\n", fact45);
	     printf("Presione enter para volver al menu");
	     getchar();
	     getchar();
	     break;
	     
	   case 10:
	     	     
	     printf("MESA POPULAR: %d\n", mesMas);
	     printf("Presione enter para volver al menu");
	     getchar();
	     getchar();
	     break;
	   
	   case 11:
	     printf("Cerrando programa!\n");
	     break;
	     
	   default: printf("Opcion equivocada\n");
	   
	  }
   
     }
   
   
   return 0;
}

