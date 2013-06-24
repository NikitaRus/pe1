#include <stdio.h>
#include <string.h>
#include <stdlib.h> //#include <conio> /*en windows...*/
#include <unistd.h> /*no se si esta en windows, buscar y borrar "sleep(2)"*/

char login_request();
/*
== Esta funcion solicita la introduccion de datos.
== Es llamada por main y devuelve 0 o el nombre de usuario
*/

int login_manager(char *, char *);
/*
== Se encarga de verificar si la autentificacion fue correcta o no
esta separada del bloque para hacer el proceso mas dinamico en caso
de tener una base de datos y se necesite que sea modular.
== Es llamada por login_request para verificar los datos introducidos.
== Retorna 0/1 dependiendo del resultado de la autentificacion.
*/

void menu_manager(char *, short int);
/* TO-DO: arreglar el tmp_login que recibe una sola letra
== Imprime las opciones que se pueden elegir en el menu.
== Como el ejercicio solicita poder volver al menu, viene muy util
tenerlo separado de todo el codigo principal.
== Es llamado por main pasandole el nombre de usuario devuelto por 
login_request y si ya se introdujeron los datos (despues de usar la
opcion 0 en el menu deberian desbloquearse los otros items.)
*/

void menu_validation(short int, short int, char *);
/*
== Verifica que items del menu se puede usar (en caso de que
no se introdujeran los datos desde el menu no te permite usar
ninguna otra opcion, y vice versa.)
== Es llamado por menu_manager
*/

void menu_options(short int);
/* TO-DO
== Implementacion de las opciones del menu. 
== Es llamado por menu_validation.
*/


// = MAIN
// ==================================================================
int main() {
	system("clear"); //system("cls")
	short int menu_valid_state = 0;
	char auth = login_request();
	if(auth != 0) {
		menu_manager(&auth, menu_valid_state); //Avanzar al menu si se logeo ->menu_manager
	} //Solicitud de los datos de usuario ->login_request<-login_manager

	return 0;
}

// = | = LOGIN REQUEST
// ==================================================================
char login_request() {
	short int r_times = 3; //Cuantas veces repetir el inicio de sesion
	short int menu_valid_state = 0; //Bloquear el menu hasta proximo aviso (introducir datos)	

	printf("Ingrese sus datos de usuario: \n");
	for(int r = 1; r <= r_times; r++) {		
		//Almacenamiento temporal
		char tmp_login[16];
		char tmp_paswd[32];

		//Pedimos los datos
		printf("Username: "); scanf("%s", &tmp_login);
		printf("Password: "); scanf("%s", &tmp_paswd);

		//Verificamos los datos ->login_manager
		if(login_manager(tmp_login, tmp_paswd) == 1) {
			printf("Logeado\n"); sleep(2); system("clear"); //system("cls")
			return *tmp_login; //Rompemos el loop del for si nos logeamos
			

		} else if(r == r_times) {
			printf("Autentificacion fallida.\n");
			return 0;

		} else {
			printf("Datos equivocados. Intento %d/%d\n", r, r_times);
		}
	}
}

// = | = | = LOGIN MANAGER
// ==================================================================
int login_manager(char *tmp_login, char *tmp_paswd) {
	//Lo correcto seria mudar los usuarios a archivos/db y sacarlos de ahi
	char login[16] = "Nikita";
	char paswd[32] = "1234";

	//!strcmp parte de string.h para comparar arrays de chars
	if(!strcmp(login, tmp_login) && !strcmp(paswd, tmp_paswd)) {
		return 1; //Logeado
	} else {
		return 0; //Fallo
	}
}

// = | = MENU MANAGER
// ==================================================================
void menu_manager(char *tmp_login, short int menu_valid_state) {
	int menu_item;
	//enum state valid_menu_items{TRUE, FALSE};
	printf("%s, bienvenido al menu principal del programa.\n", tmp_login);
	printf("\
0) Introducir datos\n\
1) punto1\n\
2) punto2\n\
3) punto3\n\
4) punto4\n\
5) punto5\n\
6) punto6\n\
7) punto7\n\
8) punto8\n\
9) punto9\n\
10) Salir\n");
	printf("Opcion: "); scanf("%d", &menu_item);

	menu_validation(menu_item, menu_valid_state, tmp_login); //Validar item seleccionado ->menu_validation
}

// = | = | = MENU VALIDATION
// ==================================================================
void menu_validation(short int menu_item, short int menu_valid_state, char *tmp_login) {
	//Usamos esto para reutilizar o modificar los permisos de los menus
	if (menu_valid_state == 0) {
		if(menu_item > 0 && menu_item < 10) {
			system("clear"); //system("cls")
			printf("Debes introducir datos antes de utilizar el menu\n\n");
			menu_manager(tmp_login, menu_valid_state);
		}
		else if(menu_item == 10) {
			menu_options(menu_item);
		}
		else if(menu_item == 0) {
			menu_options(menu_item);
		}
	} //Si no metimos datos al sistema solo podemos meter datos y salir

	else if(menu_valid_state == 1) {
		if(menu_item == 0) {
			system("clear"); //system("cls")
			printf("Se puede introducir datos solo una vez.\n");
			menu_manager(tmp_login, menu_valid_state);
		}
		else if(menu_item > 0 && menu_item <= 10) {
			menu_options(menu_item);
		}
	} //Si metimos datos al sistema accedenis al menu

	else {
		printf("Fallo super grave en la matrix...\n");
	} //Si se va todo al carajo
}


// = | = | = | = MENU OPTIONS
// ==================================================================
void menu_options(short int menu_item) {
	system("clear"); //system("cls")
	printf("Soy la opcion #%d\n", menu_item);
}