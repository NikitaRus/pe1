#include <stdio.h>
#include <stdlib.h>

int main()
{
   system("clear");
   //Generales
   int facNum = 0, pagNum, mozNum, mesNum, mesPrs;
   
   //Identidad
   //--Mozo
   //----Cantidad de personas atendidas por mozo
   int mozNum1 = 0, mozNum2 = 0, mozNum3 = 0, mozNum4 = 0, mozNum5 = 0, mozNum6 = 0;
   //----Facturado por cada mozo
   int mozTot1 = 0, mozTot2 = 0, mozTot3 = 0, mozTot4 = 0, mozTot5 = 0, mozTot6 = 0;
   
   //--Mesa
   //----Facturado por cada mesa
   int mesTot1 = 0, mesTot2 = 0, mesTot3 = 0, mesTot4 = 0, mesTot5 = 0, mesTot6 = 0, mesTot7 = 0, mesTot8 = 0, mesTot9 = 0, mesTot10 = 0, mesTot11 = 0, mesTot12 = 0;
   //----Porcentaje de facturacion sobre el total por mesa
   float mozPrc1 = 0.0, mozPrc2 = 0.0, mozPrc3 = 0.0, mozPrc4 = 0.0, mozPrc5 = 0.0, mozPrc6 = 0.0;
   
   //Secundarias
   int facTot = 0, pagTot = 0, mozPrs = 0, mozMas, pagMas = 0, mesMas, prsMas = 0;

   // 1) Introducir facturas
   while(facNum >= 0) {	
      
      //# FACTURA
      printf("Introduce un numero de factura (#0 para finalizar): ");   scanf("%d", &facNum);
      
      if (facNum == 0) {
	 printf("\nFinalizada la introduccion de facturas.\n");
	 break;
      } //Factura #0 como escape del loop
      
      printf("Introduce el numero del mozo: ");   scanf("%d", &mozNum);
      
      //# MOZO
      do {	   
	 if(mozNum >= 1 && mozNum <= 6) {
	    break;
	 } else {	 
	    printf("Solo pueden ir valores entre 1 y 6.\n");
	    printf("Introduce el numero del mozo: ");   scanf("%d", &mozNum);
	 }
	 
      } while(mozNum < 1 || mozNum > 6);
      
      //# MESA
      printf("Introduce el numero de la mesa: ");   scanf("%d", &mesNum);
      do {	   
	 if(mesNum >= 1 && mesNum <= 12) {
	    break;
	 } else {
	    printf("Solo pueden ir valores entre 1 y 12.\n");
	    printf("Introduce el numero de la mesa: ");   scanf("%d", &mesNum);
	 }
      } while(mesNum < 1 || mesNum > 12);
            
      //# PERSONAS
      printf("Introduce la cantidad de personas: ");   scanf("%d", &mesPrs);
      do {
	 if(mesPrs > 0) {
	    break;
	 } else {
	    printf("Solo puedes introducir numeros positivos.\n");
	    printf("Introduce la cantidad de personas: ");   scanf("%d", &mesPrs);
	 }
      } while(mesPrs <= 0);
      
      //# PAGO
      printf("Introduce el pago realizado: ");  scanf("%d", &pagNum);
      do {
	 if(pagNum > 0) {  
	    break;
	 } else {
	    printf("Solo puedes introducir numeros positivos.\n");
	    printf("Introduce el pago realizado: ");  scanf("%d", &pagNum);
	 }
      } while(pagNum <= 0);  
      
      //--Realizar los calculos con los datos
      facTot += 1; //Cantidad de facturas
      pagTot += pagNum; //Facturado en el dia
            
      switch(mozNum) {
       case 1: mozNum1 += mesPrs; break;
       case 2: mozNum2 += mesPrs; break;
       case 3: mozNum3 += mesPrs; break;
       case 4: mozNum4 += mesPrs; break;
       case 5: mozNum5 += mesPrs; break;
       case 6: mozNum6 += mesPrs; break;
      } //Personas atendidas por mozo

      switch(mesNum) {
       case 1: mesTot1 += mesPrs; break;
       case 2: mesTot2 += mesPrs; break;
       case 3: mesTot3 += mesPrs; break;
       case 4: mesTot4 += mesPrs; break;
       case 5: mesTot5 += mesPrs; break;
       case 6: mesTot6 += mesPrs; break;
       case 7: mesTot7 += mesPrs; break;
       case 8: mesTot8 += mesPrs; break;
       case 9: mesTot9 += mesPrs; break;
       case 10: mesTot10 += mesPrs; break;
       case 11: mesTot11 += mesPrs; break;
       case 12: mesTot12 += mesPrs; break;
      } //Cantidad de clientes por mesa
      
      if(mozPrs < mesPrs) {
	 mozMas = mozNum;
	 mozPrs = mesPrs;
      } //Mozo que mas atendio
      
      if(pagNum >= 45) {
	 pagMas += 1;
      } //Cantidad de facturas mayores a 45$
      
      if (prsMas < mesPrs) {
	 mesMas = mesNum;
	 prsMas = mesPrs;
      } //Mesa que mas clientes tuvo

      //Porcentaje de ganancia de cada mozo sobre el total
      mozPrc1 = mozTot1 * 100 / pagTot;
      mozPrc2 = mozTot2 * 100 / pagTot;
      mozPrc3 = mozTot3 * 100 / pagTot;
      mozPrc4 = mozTot4 * 100 / pagTot;
      mozPrc5 = mozTot5 * 100 / pagTot;
      mozPrc6 = mozTot6 * 100 / pagTot;
   }
   
   // 2) Personas atendidas por mozo
   printf("---------------------------------\n");
   printf("El mozo #1 atendio %d personas.\n", mozNum1);
   printf("El mozo #2 atendio %d personas.\n", mozNum2);
   printf("El mozo #3 atendio %d personas.\n", mozNum3);
   printf("El mozo #4 atendio %d personas.\n", mozNum4);
   printf("El mozo #5 atendio %d personas.\n", mozNum5);
   printf("El mozo #6 atendio %d personas.\n", mozNum6);
   
   // 3) Cantidad de facturas realizas
   printf("---------------------------------\n");
   printf("Se realizaron %d facturas en total.\n", facTot);
      
   // 4) Caja diaria realizada
   printf("---------------------------------\n");
   printf("La caja diaria recibio: %d$.\n", pagTot);
   
   // 5) Monto facturado por cada mesa en total
   printf("---------------------------------\n");
   printf("La mesa #1 facturo: %d$.\n", mesTot1);
   printf("La mesa #2 facturo: %d$.\n", mesTot2);
   printf("La mesa #3 facturo: %d$.\n", mesTot3);
   printf("La mesa #4 facturo: %d$.\n", mesTot4);
   printf("La mesa #5 facturo: %d$.\n", mesTot5);
   printf("La mesa #6 facturo: %d$.\n", mesTot6);
   printf("La mesa #7 facturo: %d$.\n", mesTot7);
   printf("La mesa #8 facturo: %d$.\n", mesTot8);
   printf("La mesa #9 facturo: %d$.\n", mesTot9);
   printf("La mesa #10 facturo: %d$.\n", mesTot10);
   printf("La mesa #11 facturo: %d$.\n", mesTot11);
   printf("La mesa #12 facturo: %d$.\n", mesTot12);
   
   // 6) Porcentaje facturado por cada mozo sobre el total
   //printf("El mozo # facturo %d\% sobre el total", mozPrc);
   printf("---------------------------------\n");
   printf("El mozo #1 realizo el %.2f porciento de la facturacion.\n", mozPrc1);
   printf("El mozo #2 realizo el %.2f porciento de la facturacion.\n", mozPrc2);
   printf("El mozo #3 realizo el %.2f porciento de la facturacion.\n", mozPrc3);
   printf("El mozo #4 realizo el %.2f porciento de la facturacion.\n", mozPrc4);
   printf("El mozo #5 realizo el %.2f porciento de la facturacion.\n", mozPrc5);
   printf("El mozo #6 realizo el %.2f porciento de la facturacion.\n", mozPrc6);
   
   // 7) Ganancia por mozo +5%
   // 
   printf("---------------------------------\n");
   printf("TO-DO\n");
   
   // 8) Que mozo atendio a mas gente
   printf("---------------------------------\n");
   printf("El mozo #%d fue el que mas personas atendio con un record de: %d\n", mozMas, mozPrs);
   
   // 9) Cuantas facturas superaron 45$
   printf("---------------------------------\n");
   printf("%d facturas superaron los 45$.\n", pagMas);
   
   // 10) Mesa con mas clientes
   printf("---------------------------------\n");
   printf("La mesa %d recibio mas clientes (un total de %d).\n", mesMas, prsMas);
   
   // Saliendo
   printf("\nTareas finalizadas.\n");
   
   return 0;
}

