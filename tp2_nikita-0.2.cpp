#include <stdio.h>
#include <string.h>
#include <stdlib.h> //#include <conio> /*en windows...*/
#include <unistd.h> /*no se si esta en windows, buscar y borrar "sleep(2)"*/
//#include <windows.h>

bool login_request();
bool login_manager(char *, char *);
void menu_manager(short int);
int menu_validation(short int, short int);


// = MAIN
// ==================================================================
int main() {
   system("cls"); //system("cls")
   short int menu_valid_state = 0;
   if(login_request()) {
      menu_manager(menu_valid_state); //Avanzar al menu si se logeo ->menu_manager
   } //Solicitud de los datos de usuario ->login_request<-login_manager
   
   return 0;
}

// = | = LOGIN REQUEST0
// ==================================================================
/*
== Esta funcion solicita la introduccion de datos.
== Es llamada por main y devuelve 0 o el nombre de usuario FIXME: devuelve una sola letra en vez del nombre completo
*/
bool login_request() {
   short int r_times = 3; //Cuantas veces repetir el inicio de sesion
   short int menu_valid_state = 0; //Bloquear el menu hasta proximo aviso (introducir datos)	
   
   printf("Ingrese sus datos de usuario: \n");
   for(int r = 1; r <= r_times; r++) {		
      //Almacenamiento temporal
      char tmp_login[16];
      char tmp_paswd[32];
      
      //Pedimos los datos
      printf("Username: "); gets(tmp_login);
      printf("Password: "); gets(tmp_paswd);
      
      //Verificamos los datos ->login_manager
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

// = | = | = LOGIN MANAGER
// ==================================================================
/*
 == Se encarga de verificar si la autentificacion fue correcta o no
 esta separada del bloque para hacer el proceso mas dinamico en caso
 de tener una base de datos y se necesite que sea modular.
 == Es llamada por login_request para verificar los datos introducidos.
 == Retorna 0/1 dependiendo del resultado de la autentificacion.
 */
bool login_manager(char *tmp_login, char *tmp_paswd) {
   //Lo correcto seria mudar los usuarios a archivos/db y sacarlos de ahi
   char login[16] = "Nikita";
   char paswd[32] = "1234";
   
   //!strcmp parte de string.h para comparar arrays de chars
   if(!strcmp(login, tmp_login) && !strcmp(paswd, tmp_paswd)) {
      return true; //Logeado
   } else {
      return false; //Fallo
   }
}

// = | = MENU MANAGER
// ==================================================================
/* TO-DO: arreglar el tmp_login que recibe una sola letra
 == Imprime las opciones que se pueden elegir en el menu.
 == Como el ejercicio solicita poder volver al menu, viene muy util
 tenerlo separado de todo el codigo principal.
 == Es llamado por main pasandole el nombre de usuario devuelto por 
 login_request y si ya se introdujeron los datos (despues de usar la
 opcion 0 en el menu deberian desbloquearse los otros items.)
 */
void menu_manager(short int menu_valid_state) {
   int menu_item;
   //enum state valid_menu_items{TRUE, FALSE};
   printf("Bienvenido al menu principal del programa.\n");
   printf("\
0) Introducir datos\n\
1) Sueldo anual\n\
2) Total pagado por mes\n\
3) Sueldos superando el promedio\n\
4) Imprimir sueldos anuales\n\
5) Salir\n");
   printf("Opcion: "); scanf("%d", &menu_item);
   
   //Datos a manejar en el menu
   
   //Validar item seleccionado ->menu_validation
   if(menu_validation(menu_item, menu_valid_state) == 0 && menu_item == 0) {
      int tmp_legajo;
      int tmp_categoria;
      int tmp_horas;
      int tmp_mes;
      
      while(tmp_legajo != 100) {
	 system("cls");	       
	 printf("Introduce los datos de empleado:");
	 printf("\nLegajo: ");		scanf("%d", &tmp_legajo); if(tmp_legajo == 100) { break; }
	 printf("\nCategoria: ");	scanf("%d", &tmp_categoria);
	 printf("\nHoras Extra: ");	scanf("%d", &tmp_horas);
	 printf("\nNumero de mes: ");	scanf("%d", &tmp_mes);
      }
      
   } else if(menu_validation(menu_item, menu_valid_state) == 1) {
      switch(menu_item) {
       case 1:
	 break;
       case 2:
	 break;
       case 3:
	 break;
       case 4:
	 break;
      }
   } else {
      printf("Saliendo del programa\n");
   }
   
}

// = | = | = MENU VALIDATION
// ==================================================================
/*
 == Verifica que items del menu se puede usar (en caso de que
 no se introdujeran los datos desde el menu no te permite usar
 ninguna otra opcion, y vice versa.)
 == Es llamado por menu_manager
 return 0 = introducir los datos
 return 1 = datos introducidos y solo se puede usar el rango 0< && <=5
 */
int menu_validation(short int menu_item, short int menu_valid_state) {
   //Usamos esto para reutilizar o modificar los permisos de los menus
  
}
