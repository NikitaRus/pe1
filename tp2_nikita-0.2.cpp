#include <stdio.h>
#include <string.h>
#include <stdlib.h> //#include <conio> /*en windows...*/
#include <unistd.h> /*no se si esta en windows, buscar y borrar "sleep(2)"*/
//#include <windows.h>

bool login_request();
bool login_manager(char *, char *);
void menu_data(bool *, int , int *, int *);
short int menu_items();
void data_processing();

int main() 
{
   int SueldoAnualProfesional[81]; for(int id = 0; id <= 81; id++) { SueldoAnualProfesional[id] = 0; }
   int SueldoMes[12]; for(int id = 0; id <= 12; id++) { SueldoMes[id] = 0; }
   int SueldoLegajo[81]; for(int id = 0; id <= 81; id++) { SueldoLegajo[id] = 0; }
   
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
		  menu_data(&data, SueldoAnualProfesional, SueldoMes, SueldoLegajo); // introducimos datos
	       }
	     else if(data == true) // si ya introducimos datos habilitamos las otras opciones
	       {
		  switch(menu_item) // opciones despues de introducir datos
		    {
		     case 0:
		       system("clear"); //system("cls");
		       printf("Solo se puede introducir los datos una vez\n");
		       break;
		       
		     case 1:
		      system("clear");
			     data_processing();
		       break;
		     case 2:
		       system("clear");
                
		       break;
		     case 3:
		       system("clear");
               
		       break;
		     case 4:
		       system("clear");
               
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
      
      if(login_manager(tmp_login, tmp_paswd)) {
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

bool login_manager(char *tmp_login, char *tmp_paswd) {
   //Lo correcto seria mudar los usuarios a .ini/.dat/DB y sacarlos de ahi
   char login[16] = "Nikita";
   char paswd[32] = "1234";
   
   //!strcmp parte de string.h para comparar arrays de chars de manera que devuelven true o false y se autoverifican
   if(!strcmp(login, tmp_login) && !strcmp(paswd, tmp_paswd)) {
      return true; //Logeado
   } else {
      return false; //Fallo
   }
}

void menu_data(bool *data, int SueldoAnualProfesional[81], int *SueldoMes, int *SueldoLegajo) // llenamos los datos
{
   int tmp_legajo;
   int tmp_categoria;
   int tmp_horas;
   int tmp_mes;
   
   int SueldoAnualProfesional[3] = 100;
   printf("%d\n", SueldoAnualProfesional[3]);

   int tmp_numero = 0;
   
   bool validated = true;
   
   while(tmp_legajo != 100) 
    {
    	//system("clear"); //system("cls");
    	printf("\nIntroduce los datos #%d:", tmp_numero);
    	printf("\nNumero de legajo: ");		        scanf("%d", &tmp_legajo); 
        if(tmp_legajo == 100) { break; } else if(tmp_legajo < 1) { 
            validated = false; }

     	printf("\nCategoria perteneciente: ");	        scanf("%d", &tmp_categoria); 
        if(tmp_categoria < 1 || tmp_categoria > 6) { 
            validated = false; }

    	printf("\nHoras Extra trabajadas: ");      	scanf("%d", &tmp_horas); 
        if(tmp_horas < 0) { 
            validated = false; }

    	printf("\nNumero del mes [1 - 12]: ");	scanf("%d", &tmp_mes); 
        if(tmp_mes <= 0 || tmp_mes > 12) { 
            validated = false; }



        if(validated == true) 
        {
            *data = true; // modificamos 'data' a travez de su puntero para poder habilitar el menu al terminar de introducir los datos
            tmp_numero += 1;
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

short int menu_items() // menu separado para poder imprimirlo cuando lo necesitemos
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

void data_processing()
{
   char descr[7][64] = 
     { {"Descr1"}, {"Descr2"}, {"Descr3"}, {"Descr4"}, {"Descr5"}, {"Descr6"} };
   int salary[7] =
     { 0, 100, 200, 300, 400, 500, 600 };
   int extra[7] = 
     { 0, 10, 20, 30, 40, 50, 60 };


    int menu_item =0;

    switch(menu_item) 
    {
        case 1:
        break;

        case 2:
        break;

        case 3:
        break;

        case 4:
        break;

    }
	
}
