#include <stdio.h>
#include <string.h>
#include <stdlib.h> //#include <conio> /*en windows...*/
#include <unistd.h> /*no se si esta en windows, buscar y borrar "sleep(2)"*/
//#include <windows.h>

	/*
	EN WINDOWS HAY QUE BUSCAR system("clear"); Y REMPLAZARLO POR system("cls");
	*/

#define LOGIN "Nikita"
#define PASSWORD "1234"

#define LEGAJO 10
#define CATEGORIA 6
#define DESCRIPCION 64
#define MES 12
#define EMPLEADOS 10

#define SALIDA 100

//
bool login_request();
bool login_validator(char *, char *);
void menu_data(bool *, float *, float *, int *);
short int menu_items();
void data_processing(int, float *, int *);
//

int main()
{
	float SueldoAnualProfesional[LEGAJO] = {0};
	float SueldoMes[MES + 1] = {0};
	int TotalHorasExtra[LEGAJO] = {0};
   
	bool validated = false;
	int menu_item;
   
	system("clear"); //system("cls")
	if(login_request()) // nos logeamos
	{
		while(menu_item != 5) // repetimos el switch hasta salir del menu
		{
			menu_item = menu_items(); // llamamos al menu para introducir items
		     
		 	if(validated == false && menu_item == 0) // opcion 0 usable solo si no introducimos nada
			{
				menu_data(&validated, SueldoAnualProfesional, SueldoMes, TotalHorasExtra); // introducimos datos
			}
			else if(validated == true) // si ya introducimos datos habilitamos las otras opciones
			{
				switch(menu_item) // opciones despues de introducir datos
				{
				case 0:
					system("clear"); //system("cls");
					getchar();
					printf("Solo se puede introducir los datos una vez\n");
					getchar();
					break;
				case 1:
					system("clear"); //system("cls");
					getchar();
					data_processing(menu_item, SueldoAnualProfesional, 0);
					break;
				case 2:
					system("clear"); //system("cls");
					getchar();
					data_processing(menu_item, SueldoMes, 0);
					break;
				case 3:
					system("clear"); //system("cls");
					getchar();
					data_processing(menu_item, SueldoAnualProfesional, 0);
					break;
				case 4:
					system("clear"); //system("cls");
					getchar();
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
				getchar();
				printf("Debes introducir los datos antes de usar el menu\n");
				getchar();
			}
		}
	}
	return 0;
}

bool login_request()
{
 	short int r_times = 3; //Cuantas veces repetir el inicio de sesion
 
 	system("clear"); //system("cls");
	printf("Ingrese sus datos de usuario: \n");
	for(int r = 1; r <= r_times; r++)
	{
		//Almacenamiento temporal
		char tmp_login[16];
		char tmp_paswd[32];
		
		//Pedimos los datos
		printf("Username: "); fflush(stdin); gets(tmp_login); // Compilador de Linux tirando warnings de que 'gets' no apto para el uso
		printf("Password: "); fflush(stdin); gets(tmp_paswd);
		
		if(login_validator(tmp_login, tmp_paswd))
		{
			printf("Logeado\n"); system("clear"); //system("cls")

		     	return true;
		     	break;
		}
		else if(r == r_times)
		{
		     	printf("Autentificacion fallida.\n");

		     	return false;
		     	break;
		}
		else
		{
		     	printf("Datos equivocados. Intento %d/%d\n", r, r_times);
		}
     	}
}

bool login_validator(char *tmp_login, char *tmp_paswd)
{
   	//Separado del resto de login_request para poder implementar en el futuro la lectura de datos
   	//de una fuente externa o desencriptacion de contrasena como funciones separadas.
	   
   	//Lo correcto seria mudar los usuarios a .ini/.dat/DB y leerlos de ahi encriptados
   	char login[16] = LOGIN;
   	char paswd[32] = PASSWORD;
	   
   	//!strcmp parte de string.h para comparar arrays de chars de manera que devuelven true o false y se autoverifican
   	if(!strcmp(login, tmp_login) && !strcmp(paswd, tmp_paswd))
     	{
		return true; //Logeado
     	}
   	else
     	{
		return false; //Fallo
     	}
}

void menu_data(bool *validated, float *SueldoAnualProfesional, float *SueldoMes, int *TotalHorasExtra) // llenamos los datos
{
	int tmp_legajo;
	int tmp_categoria;
	int tmp_horas;
	int tmp_mes;
	   
	char DescripcionCategoria[CATEGORIA][DESCRIPCION];
	float SalarioCategoria[CATEGORIA] = { 0 };
	int CostoHoraExtraCategoria[CATEGORIA] = { 0 };

	char tmp_descripcion_categoria[DESCRIPCION];
	int tmp_salario_categoria;
	int tmp_che_categoria;

	int tmp_numero_empleado = 1;
	int tmp_numero_categoria = 1; 
	   
	bool categorias = true;
	bool empleados = true;

	//== GET CATEGORIAS =========================================================
	while(categorias == true)
	{
		system("clear"); //system("cls");
		printf("Introduce los datos de categoria #%d\n", tmp_numero_categoria);


		//========= ASK ===================================== GET =============
		printf("\nDescripcion: "); fflush(stdin);				getchar(); gets(tmp_descripcion_categoria);
		if(sizeof(tmp_descripcion_categoria) > DESCRIPCION) 
		{
		    	categorias = false;
	    	}
	    	printf("\nSalario: "); 						scanf("%d", &tmp_salario_categoria); 
	    	if(tmp_salario_categoria < 1) 
	    	{
	    		categorias = false;
	    	}
		printf("\nValor de hora extra: "); 				scanf("%d", &tmp_che_categoria); 
		if(tmp_che_categoria < 1) 
		{
	 		categorias = false;
		}

		//== CATEGORIAS VALIDATION PASSED
		if(categorias == true)
		{
			*DescripcionCategoria[tmp_numero_categoria] = *tmp_descripcion_categoria;
	    		SalarioCategoria[tmp_numero_categoria] = tmp_salario_categoria;
	    		CostoHoraExtraCategoria[tmp_numero_categoria] = tmp_che_categoria;
			
			tmp_numero_categoria += 1;

			getchar();
		 	system("clear"); //system("cls");
		 }
	        	else
		{
			getchar();
			printf("Los datos de la introduccion #%d no han sido validados por favor vuelva a introducirlos.\n", tmp_numero_categoria);
			categorias = true;
			getchar();
			system("clear"); //system("cls");
		     
		}

		if (tmp_numero_categoria > CATEGORIA) { categorias = false; empleados = true; *validated = false; break; }

   	}

   	// == GET EMPLEADOS =====================================
	while(empleados == true)
     	{
		system("clear"); //system("cls");
		printf("Introduce los datos de empleado #%d:", tmp_numero_empleado);

		//====== ASK =========================== GET ======
		printf("\nNumero de legajo: ");			scanf("%d", &tmp_legajo);
		if(tmp_legajo == SALIDA && *validated == true) { break; }
	        	else if(tmp_legajo < 1 || tmp_legajo > LEGAJO)
		{
			empleados = false;
		}
		printf("\nCategoria perteneciente: ");		scanf("%d", &tmp_categoria);
	        	if(tmp_categoria < 1 || tmp_categoria > CATEGORIA)
		{
			empleados = false;
		}
		printf("\nHoras Extra trabajadas: ");		scanf("%d", &tmp_horas);
	        	if(tmp_horas < 0)
		{
			empleados = false;
		}
		printf("\nNumero del mes [1 - 12]: ");		scanf("%d", &tmp_mes);
	        	if(tmp_mes < 1 || tmp_mes > MES)
		{
			empleados = false;
		}
		

		// == EMPLEADOS VALIDATION PASSED ==
		if(empleados == true)
		{
			float pago = (float(SalarioCategoria[tmp_categoria]) + (float(tmp_horas) * float(CostoHoraExtraCategoria[tmp_categoria])));
		     
			if(tmp_mes == 7 || tmp_mes == 12)
			{
				pago += pago / 2;
			}
		       
			SueldoAnualProfesional[tmp_legajo] += pago; // Definimos el sueldo anual de cada profesional
			SueldoMes[tmp_mes] += pago; // Definimos el total pagado por mes
			TotalHorasExtra[tmp_legajo] += tmp_horas;
		     
			tmp_numero_empleado += 1; // Aumentamos el numero actual en el orden del input (para tener un debug de cual nos tira error)

			getchar();
			system("clear"); //system("cls");
		}
		else
		{
			getchar();
			printf("Los datos #%d no han sido validados o completos por favor vuelva a introducirlos.\n", tmp_numero_empleado);
			empleados = true;
			getchar();
			system("clear"); //system("cls");
		}
		if (SueldoAnualProfesional[tmp_legajo] > 0) { *validated = true; printf("Validado!\n"); } 
		if(tmp_numero_empleado > EMPLEADOS) { categorias = false; empleados = false; *validated = true; break; }
	}
}

short int menu_items() // menu separado para poder imprimirlo cuando lo necesite
{
	int menu_item;
   
	system("clear"); //system("cls");
    
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

void data_processing(int menu_item, float *Argument1, int *Argument2)
{
	switch(menu_item)
	{
	case 1:
		printf("Sueldo anual de cada profesional:\n");
	
		for (int i = 0; i < LEGAJO; i++)
		{
			if(Argument1[i] > 0)
			{
				printf("Legajo: #%d | Sueldo: %.2f$\n", i, Argument1[i]);
			}
		}
	
		getchar();
		break;
	
	case 2:
		printf("Total pagado por mes:\n");
		for (int i = 1; i <= MES; i++)
		{
			if(Argument1[i] > 0)
			{
				printf("Total: %.2f$ | Mes: #%d\n", Argument1[i], i);
			}
		}

		printf("\n");
	
		getchar();
		break;
	
	case 3:
		int tmp_avglegajo;
		int tmp_numbers;
		float average;

		tmp_numbers = 0;
		for(int i = 1; i <= LEGAJO; i++)
		{
			if(Argument1[i] > 0)
			{
				tmp_numbers += 1;
				tmp_avglegajo += Argument1[i];
			}
		}
	
		average = tmp_avglegajo / tmp_numbers;
	
		tmp_numbers = 0;
		for(int i = 1; i <= LEGAJO; i++)
		{
			if(Argument1[i] > average)
			{
				tmp_numbers += 1;
			}
		}
	
		printf("Cantidad de sueldos que superan el promedio: %d\n", tmp_numbers);
	
		getchar();
		break;
	
	case 4:
		int LegajoOrdenadoSueldo[LEGAJO]; //Creamos un vector igual al original para ordenarlo y sacar los index
		int LegajoIndexOrdenado[LEGAJO]; //Aca vienen las posiciones originales del vector sueldos ordenados (copia de la posicion de los sueldos desordenados)
		for(int i = 0; i < LEGAJO; i++) { LegajoIndexOrdenado[i] = i; } //numeros de legajo en el orden correcto para llamar todos los datos por ese orden.
		for(int i = 0; i < LEGAJO; i++) { LegajoOrdenadoSueldo[i] = Argument1[i]; } //copiamos los arrays
	
		int tmp_mem, c, d;

		for(c = 0; c < (LEGAJO - 1); c++) 
		{
			for (d = c + 1; d < LEGAJO; d++) 
			{ 
				if(LegajoOrdenadoSueldo[d] > LegajoOrdenadoSueldo[c]) 
				{
					// ORDENA LA COPIA DE SUELDO-ANUAL A SUELDO-ORDENADO
					tmp_mem = LegajoOrdenadoSueldo[d];
					LegajoOrdenadoSueldo[d] = LegajoOrdenadoSueldo[c];
					LegajoOrdenadoSueldo[c] = tmp_mem;

					// ORDENA LA REFERENCIA AL ORIGINAL DE LA COPIA ORDENADA
					tmp_mem = LegajoIndexOrdenado[d];
					LegajoIndexOrdenado[d] = LegajoIndexOrdenado[c];
					LegajoIndexOrdenado[c] = tmp_mem;
				}
			}
		}

		printf("Imprimiendo lista: \n");
		for(int items = 0; items < LEGAJO; items++)
		{
			int legajo = LegajoIndexOrdenado[items];
	
			if(Argument1[LegajoIndexOrdenado[items]] > 0)
			{
				printf("Sueldo: %.2f\n", Argument1[LegajoIndexOrdenado[items]]);
				printf("  Legajo: %d\n", legajo);
				printf("  Horas extra: %d\n\n", Argument2[LegajoIndexOrdenado[items]]);
			}
		}
	
		getchar();
		break;	
	} 
}