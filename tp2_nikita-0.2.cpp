#include <stdio.h>
#include <string.h>
#include <stdlib.h> //#include <conio> /*en windows...*/
#include <unistd.h> /*no se si esta en windows, buscar y borrar "sleep(2)"*/
//#include <windows.h>

bool login_request();
bool login_manager(char *, char *);
void menu_data(bool *);
short int menu_items();

int main() 
{
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
		  menu_data(&data); // introducimos datos
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
		       system("clear")
		       break;
		     case 2:
		       system("clear")
		       break;
		     case 3:
		       system("clear")
		       break;
		     case 4:
		       system("clear")
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

void menu_data(bool *data) // llenamos los datos
{
   int tmp_legajo;
   int tmp_categoria;
   int tmp_horas;
   int tmp_mes;
   
   while(tmp_legajo != 100) 
     {
	bool validated = true;
	system("clear"); //system("cls");
	printf("Introduce los datos de empleado:");
	printf("\nLegajo: ");		        scanf("%d", &tmp_legajo); if(tmp_legajo == 100) { break; } else if(tmp_legajo < 0) { validated = false; }
 	printf("\nCategoria: ");	        scanf("%d", &tmp_categoria); if(tmp_categoria < 0 || tmp_categoria > 6) { validated = false; }
	printf("\nHoras Extra: ");      	scanf("%d", &tmp_horas) if(tmp_horas < 0) { validated = false; };
	printf("\nNumero de mes [1 - 12]: ");	scanf("%d", &tmp_mes); if(tmp_mes <= 0 || tmp_mes > 12) { validated = false; }
     }
   
   if(validated == true)
     {
	*data = true; // modificamos 'data' a travez de su puntero para poder habilitar el menu al terminar de introducir los datos
     }
   else
     {
	printf("Los datos no han sido validados por no respetar el formato");
     }
   
   system("clear"); //system("cls");
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
   
