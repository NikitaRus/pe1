#include <stdio.h>
#include <string.h>
#include <stdlib.h> //#include <conio> /*en windows...*/
#include <unistd.h> /*no se si esta en windows, buscar y borrar "sleep(2)"*/
//#include <windows.h>


#define LOGIN "Nikita"
#define PASSWORD "1234"

#define LEGAJO 81
#define CATEGORIA 7
#define DESCRIPCION 64
#define MES 12
#define EMPLEADOS 80

#define SALIDA 100


//
bool login_request();
bool login_validator(char *, char *);
void menu_data(bool *, int *, int *, int *, int *, int *, int *);
short int menu_items();
void data_processing(int, int *, int *);
//

int main() 
{
   int SueldoAnualProfesional[LEGAJO] = {0}; 
   int SueldoMes[MES] = {0};
   int SueldoLegajo[LEGAJO] = {0};
   int TotalHorasExtra[LEGAJO] = {0};

   char DescripcionCategoria[CATEGORIA][DESCRIPCION] = 
     { {"Descr1"}, {"Descr2"}, {"Descr3"}, {"Descr4"}, {"Descr5"}, {"Descr6"} };

   int SalarioCategoria[CATEGORIA] =
     { 1000, 2000, 3000, 4000, 5000, 6000 };

   int CostoHoraExtraCategoria[CATEGORIA] = 
     { 10, 20, 30, 40, 50, 60 };
   
   bool data = false;
   int menu_item;

   system("clear"); //system("cls")
   if(login_request()) // nos logeamos
     {	
	while(menu_item != 5) // repetimos el switch hasta salir del menu
	  {	    
	     menu_item = menu_items(); // llamamos al menu para introducir items
	     
	     if(data == false && menu_item == 0) // opcion 0 usable solo si no introducimos nada
	       {
		  system("clear"); //system("cls");
		  menu_data(&data, SueldoAnualProfesional, SueldoMes, SueldoLegajo, SalarioCategoria, CostoHoraExtraCategoria, TotalHorasExtra); // introducimos datos
	       }
	     else if(data == true) // si ya introducimos datos habilitamos las otras opciones
	       {
		  switch(menu_item) // opciones despues de introducir datos
		    {
		     case 0:
		       system("clear"); //system("cls");
		       printf("Solo se puede introducir los datos una vez\n");
               getchar();
		       break;
		       
		     case 1:
		      system("clear");
			   data_processing(menu_item, SueldoAnualProfesional, 0);
		       break;
		     case 2:
		       system("clear");
               data_processing(menu_item, SueldoMes, 0);
                
		       break;
		     case 3:
		       system("clear");
               
		       break;
		     case 4:
		       data_processing(menu_item, SueldoAnualProfesional, TotalHorasExtra);
               
		       break;
		    }
	       }
	     else if(menu_item == 5) // terminamos el loop
	       {
		  return 0;
	       }
	     else // si tratamos de usar el menu sin introducir datos nos tira error
	       {
		  system("clear"); //system("cls");
		  printf("Debes introducir los datos antes de usar el menu\n");
	       }
	  }
     }
   return 0;
}



bool login_request() {
   short int r_times = 3; //Cuantas veces repetir el inicio de sesion	
   
   printf("Ingrese sus datos de usuario: \n");
   for(int r = 1; r <= r_times; r++) {		
      //Almacenamiento temporal
      char tmp_login[16];
      char tmp_paswd[32];
      
      //Pedimos los datos
      printf("Username: "); fflush(stdin); gets(tmp_login); // Compilador de Linux tirando warnings de que 'gets' no apto para el uso
      printf("Password: "); fflush(stdin); gets(tmp_paswd);
      
      if(login_validator(tmp_login, tmp_paswd)) {
	 printf("Logeado\n"); system("clear"); //system("cls")
	 return true;
	 break;
	 
      } else if(r == r_times) {
	 printf("Autentificacion fallida.\n");
	 return false;
	 break;
	 
      } else {
	 printf("Datos equivocados. Intento %d/%d\n", r, r_times);
      }
   }
}

bool login_validator(char *tmp_login, char *tmp_paswd) {
    //Separado del resto de login_request para poder implementar en el futuro la lectura de datos
    //de una fuente externa o desencriptacion de contrasena como funciones separadas.

    //Lo correcto seria mudar los usuarios a .ini/.dat/DB y leerlos de ahi encriptados
    char login[16] = LOGIN;
    char paswd[32] = PASSWORD;
   
    //!strcmp parte de string.h para comparar arrays de chars de manera que devuelven true o false y se autoverifican
    if(!strcmp(login, tmp_login) && !strcmp(paswd, tmp_paswd)) {
        return true; //Logeado
    } else {
        return false; //Fallo
    }
}

void menu_data(bool *data, int *SueldoAnualProfesional, int *SueldoMes, int *SueldoLegajo, int *CostoHoraExtraCategoria, int *SalarioCategoria, int *TotalHorasExtra) // llenamos los datos
{
   int tmp_legajo;
   int tmp_categoria;
   int tmp_horas;
   int tmp_mes;

   int tmp_numero = 1;
   
   bool validated = true;
   
   while(tmp_numero <= EMPLEADOS) 
    {
    	//system("clear"); //system("cls");
    	printf("\nIntroduce los datos #%d:", tmp_numero);
    	printf("\nNumero de legajo: ");		           scanf("%d", &tmp_legajo); 
        if(tmp_legajo == SALIDA) { break; } 
        else if(tmp_legajo < 1) { 
            validated = false; }

     	printf("\nCategoria perteneciente: ");         scanf("%d", &tmp_categoria); 
        if(tmp_categoria < 1 || tmp_categoria > 6) { 
            validated = false; }

    	printf("\nHoras Extra trabajadas: ");          scanf("%d", &tmp_horas); 
        if(tmp_horas < 0) { 
            validated = false; }

    	printf("\nNumero del mes [1 - 12]: ");	       scanf("%d", &tmp_mes); 
        if(tmp_mes <= 0 || tmp_mes > 12) { 
            validated = false; }


        if(validated == true) 
        {
            int pago = SalarioCategoria[tmp_categoria] + (tmp_horas * CostoHoraExtraCategoria[tmp_categoria]);

            *data = true; // modificamos 'data' a travez de su puntero para poder habilitar el menu al terminar de introducir los datos

            tmp_numero += 1; // Aumentamos el numero actual en el orden del input (para tener un debug de cual nos tira error)

            SueldoAnualProfesional[tmp_legajo] += pago; // Definimos el sueldo anual de cada profesional
            SueldoMes[tmp_mes] += pago; // Definimos el total pagado por mes
            TotalHorasExtra[tmp_legajo] += tmp_horas;


            if(tmp_mes == 7 || tmp_mes == 12) {
                SueldoAnualProfesional[tmp_legajo] += pago / 2;
                SueldoMes[tmp_mes] += pago / 2;
            } // Agregamos aguinaldo a 'pagado por mes' y 'sueldo de cada profesional'


            getchar();
            system("clear"); //system("cls");
        }
        else 
        {   
            system("clear"); //system("cls");
            printf("Los datos de la introduccion #%d no han sido validados por favor vuelva a introducirlos.", tmp_numero);
            validated = true;
            getchar();
        }
    }
   
   //system("clear"); //system("cls");
}

short int menu_items() // menu separado para poder imprimirlo cuando lo necesite
{
   int menu_item;
   
   printf("Bienvenido al menu principal del programa.\n");
   printf("0) Introducir datos\n");
   printf("1) Sueldo anual\n");
   printf("2) Total pagado por mes\n");
   printf("3) Sueldos superando el promedio\n");
   printf("4) Imprimir sueldos anuales\n");
   printf("5) Salir\n");
   
   printf("Opcion: "); scanf("%d", &menu_item);
   
   return menu_item;
} 

void data_processing(int menu_item, int *Argument1 = 0, int *Argument2 = 0)
{
    switch(menu_item) 
    {
        case 1:
            printf("Sueldo anual de cada profesional:\n");
            for (int i = 0; i <= LEGAJO; i++) {
                if (Argument1[i] != 0)
                {
                    printf("Sueldo: %d$ | Legajo: #%d\n", Argument1[i], i);
                }
                
            } 

            break;

        case 2:
            printf("Total pagado por mes:\n");
            for (int i = 0; i <= MES; i++) {
                if (Argument1[i] != 0)
                {
                    printf("Total: %d$ | Mes: #%d\n", Argument1[i], i);
                }
                
            } 

            break;

        case 3:
            int tmp_avglegajo;

            for (int i = 0; i <= LEGAJO; i++) {
                if (Argument1[i] != 0)
                {
                    
                }
                
            }

            break;

        case 4:
            //falta mucha optimizacion en esta seccion
            int *LegajoOrdenadoSueldo = Argument1; //Creamos un vector igual al original para ordenarlo y sacar los index
            int LegajoIndexOrdenado[LEGAJO]; 
            for(int i = 0; i < LEGAJO; i++) { LegajoIndexOrdenado[i] = i; } //numeros de legajo en el orden correcto para llamar todos los datos por ese orden.
            int tmp_mem, c, d;


            for(c = 0; c < (LEGAJO - 1); c++) {
                for (d = 1; d < LEGAJO - c; d++) { 
                    if (LegajoOrdenadoSueldo[d] > LegajoOrdenadoSueldo[d - 1]) 
                    {
                        tmp_mem = LegajoOrdenadoSueldo[d];
                        LegajoOrdenadoSueldo[d] = LegajoOrdenadoSueldo[d - 1];
                        LegajoOrdenadoSueldo[d - 1] = tmp_mem;

                        tmp_mem = LegajoIndexOrdenado[d];
                        LegajoIndexOrdenado[d] = LegajoIndexOrdenado[d - 1];
                        LegajoIndexOrdenado[d - 1] = tmp_mem;
                    }
                }
            }

            for(int items = 0; items <= LEGAJO; items++)
            {
                int legajo = LegajoIndexOrdenado[items];

                if(LegajoOrdenadoSueldo[items] > 0)
                {
                    printf("Sueldo: %d\n", LegajoOrdenadoSueldo[items]);
                    printf("  Legajo: %d\n", legajo);
                    printf("  Horas extra: %d\n\n", Argument2[legajo]);
                }
            }     

            break;

    }
	
}
