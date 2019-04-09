//Librerias
#include <iostream>
#include <iomanip>

using namespace std;

//FUNCIONES

	//Funcion para Bienvenida al sistema
void bienvenida()
{
	cout<<endl<<" 					     Universidad Metropolitana"<<endl;
	cout<<" 				     Un programa elaborado por Marcos De Andrade "<<endl<<endl;
	cout<<" 		<<<<<<<<<<<<<<<<<<<<  PROGRAMA DE CALCULO DEL \"ISLR\"  >>>>>>>>>>>>>>>>>>>>"<<endl<<endl;
	cout<<"  Bienvenido al programa de calculo del Impuesto Sobre la Renta (ISLR), a partir de las Unidades Tributarias (UT)."<<endl;
	cout<<"  Por favor siga las intrucciones, para poder proceder a la correcta informacion sobre el \"ISLR\" a pagar."<<endl<<endl;
	cout<<"  NOTA: Para una mejor visualizacion del programa ajuste el ancho de la ventena entrando a Propiedades, Diseno,"<<endl;
	cout<<"  y modificar en Tamano de Venta el Ancho a \"114\" y el Alto en \"44\". "<<endl<<endl;
	cout<<"  ATENCION: Una vez introducido el dato que se le pida presione la tecla \"Intro\"."<<endl<<endl;	
}

	//Funcion para Validar si una entrada es positiva (Usada para comprobar remuneracion y carga familiar)
void validarPositivo(float &numero)
{
	while(numero<0)
	{
		cout<<"	  Medida invalida. Por favor Introduzca un valor positivo"<<endl;
		cout<<"	  "; cin>>numero;
	}
}

	//Funcion para Validar si una entrada es mayor a 0 (Usada para comprobar cedula)
void validarMayor0(int &numero)
{
	while(numero<=0)
	{
		cout<<"	  Medida invalida. Por favor Introduzca un valor mayor a 0"<<endl;
		cout<<"	  "; cin>>numero;
	}
}

	//Funcion para Validar si una entrada es la letra requerida(Usada para comprobar respuesta)
void validacionLetra(char &respuesta)
{
	while((respuesta != 's') && (respuesta != 'S') && (respuesta != 'n') && (respuesta != 'N'))
	{
		cout<<endl<<"	  Respuesta invalida. Por favor Introduzca uno de los caracteres indicados"<<endl;
		cout<<endl<<"	  ";cin>>respuesta;
	}
}

	//Funcion para Entrada de Datos al Sistema
void entradaDatos(int &cedula, float &remuneracion, float &cargaFamiliar)
{
	cout<<"	* Introduzca la cedula del cliente: ";
	cin>>cedula;
	
		//Validar Codigo de Cliente
	validarMayor0(cedula);
		
	cout<<"	* Introduzca la remuneracion total al ano en Bs: ";
	cin>>remuneracion;
	
		//Validar Remuneracion
	validarPositivo(remuneracion);
		
	cout<<"	* Introduzca las cargas familiares: ";
	cin>>cargaFamiliar;
	
		//Validar Carga Familiar
	validarPositivo(cargaFamiliar);
	cargaFamiliar++;
}

	//Funcion para Calcular las Unidades Tributarias (UT) a partir de la remuneracion en Bolivares (Bs.)
float calcularUT(float remuneracion)
{
	return (remuneracion/300);
}

	//Funcion para Calcular el Descuento por Carga Familiar
float descuentoCargaFamiliar(float UT, float cargaFamiliar)
{
	return (UT-(cargaFamiliar*500));
}
	
	//Funcion para Calcular Ubicacion respecto al descuento en Unidades Tributarias
void ubicacionDescuentoUT(float FT, float &tasa, float &desUT, float &cont6,float &cont9,float &cont12,float &cont16,float &cont20,float &cont24,float &cont29, float &cont34)
{
	if(FT<=10000)
	{
		tasa 	= 0.06;
		desUT	= 0;
		cont6++;
	}
	else if(FT<=15000)
		{
			tasa	= 0.09;
			desUT	= 300;
			cont9++;
		}
		else if(FT<=20000)
			{
				tasa 	= 0.12;
				desUT 	= 750;
				cont12++;
			}
			else if(FT<=25000)
				{
					tasa	= 0.16;
					desUT   = 1550;
					cont16++;
				}
				else if(FT<=30000)
					{
						tasa	= 0.20;
						desUT	= 2550;
						cont20++;
					}
					else if(FT<=40000)
						{
							tasa	= 0.24;
							desUT	= 3750;
							cont24++;
						}
					else if(FT<=60000)
						{
							tasa	= 0.29;
							desUT   = 5750;
							cont29++;
						}
						else if(FT>60000)
							{
								tasa	= 0.34;
								desUT	= 8750;
								cont34++;
							}
}
	
	//Funcion para Calcular el decuento por Unidad Tributaria
float descuentoUnidadT(float UT, float tasa, float desUT )
{
	return ( (UT*tasa)-desUT);
}

	//Funcion para Calcular Bolivaresn (Bs) a partir de las Unidades Tributarias (UT)
float calcularBs(float UT)
{
	return (UT*300);
}

	//Funcion para Calcular Contribuyente Mayor.
void calcularMayorMenor( int cedula, float ISLR, int &cedulaMayor, int &cedulaMenor, float &contribuyenteMayor, float &contribuyenteMenor)
{
	if(ISLR>contribuyenteMayor)
	{
		cedulaMayor			= cedula;
		contribuyenteMayor	= ISLR;
	}	
	if (ISLR<contribuyenteMenor)
	{
		cedulaMenor			= cedula;
		contribuyenteMenor	= ISLR;
	}
}

	//Funcion para Reportar el Impuesto Sobre La Renta del Cliente
void reporteCliente(int cedula, float remuneracion, float cargaFamiliar,float tasa, float ISLR)
{
	cout<<fixed;
	
	cout<<endl<<endl<<"	------------------- REPORTE DEL CLIENTE ------------------- "<<endl<<endl;
	
	cout<<"	* La cedula del cliente es: "<<setprecision(0)<<cedula<<endl;
	cout<<"	* El Total de la remuneracion al ano es de: Bs."<<setprecision(2)<<remuneracion<<endl;
	cout<<"	* El numero de cargas familiares (incluye al contribuyente) es de: "<<setprecision(0)<<cargaFamiliar<<endl;
	cout<<"	* La tasa de impuestos a pagar es de: "<<setprecision(0)<<(tasa*100)<<"%"<<endl;
	cout<<"	* El MONTO a pagar de ISLR es de: Bs. "<<setprecision(2)<<ISLR<<endl;
}

	//Funcion Reporte Fin del Dia
void reporteFinDia(float contSinISLR, float cont6,float cont9,float cont12,float cont16,float cont20,float cont24,float cont29, float cont34, float remuneracionT, float descuentoT, float totalISLR, float contribuyenteMayor, float contribuyenteMenor, int cedulaMayor, int cedulaMenor)
{
	cout<<fixed;
	
	cout<<endl<<endl<<"	   ------------------- REPORTE FIN DEL DIA ------------------- "<<endl<<endl;
	
	cout<<"	  * La cantidad de contribuyentes que no pagaron impuesto es de: "<<setprecision(0)<<contSinISLR<<endl;
	cout<<"	  * La cantidad de contribuyentes con la tasa del  6%: " <<setprecision(0)<<cont6<<endl;
	cout<<"	  * La cantidad de contribuyentes con la tasa del  9%: " <<setprecision(0)<<cont9<<endl;
	cout<<"	  * La cantidad de contribuyentes con la tasa del 12%: "<<setprecision(0)<<cont12<<endl;
	cout<<"	  * La cantidad de contribuyentes con la tasa del 16%: "<<setprecision(0)<<cont16<<endl;
	cout<<"	  * La cantidad de contribuyentes con la tasa del 20%: "<<setprecision(0)<<cont20<<endl;
	cout<<"	  * La cantidad de contribuyentes con la tasa del 24%: "<<setprecision(0)<<cont24<<endl;
	cout<<"	  * La cantidad de contribuyentes con la tasa del 29%: "<<setprecision(0)<<cont29<<endl;
	cout<<"	  * La cantidad de contribuyentes con la tasa del 34%: "<<setprecision(0)<<cont34<<endl;
	cout<<"	  * El monto total de remuneraciones de los contribuyentes es de Bs: "<<remuneracionT<<endl;
	
	cout<<endl<<"	  * El contribuyente que pago mas impuesto"<<endl<<endl;
	cout<<"		 - Cedula del contribuyente: "<<setprecision(0)<<cedulaMayor<<endl;
	cout<<"		 - ISLR del contribuyente: Bs."<<setprecision(2)<<contribuyenteMayor<<endl;
	
	cout<<endl<<"	  * El contribuyente que pago menos impuesto"<<endl<<endl;
	cout<<"		 - Cedula del contribuyente: "<<setprecision(0)<<cedulaMenor<<endl;
	cout<<"		 - ISLR del contribuyente: Bs."<<setprecision(2)<<contribuyenteMenor<<endl<<endl;
	
	cout<<"	  * El monto toal de descuentos otorgados de UT es de: Bs."<<setprecision(2)<<descuentoT<<endl;
	cout<<"	  * El monto TOTAL de ISLR es de: Bs."<<setprecision(2)<<totalISLR<<endl;
	if((cont6+cont9+cont12+cont16+cont20+cont24+cont29+cont34)>0)
		cout<<"	  * El prodedio de pago de todos los contribuyentes es de: Bs."<<setprecision(2)<<(totalISLR/(cont6+cont9+cont12+cont16+cont20+cont24+cont29+cont34))<<endl;
	else
		cout<<"	  * El prodedio de pago de todos los contribuyentes es de: Bs."<<setprecision(2)<<0<<endl<<endl;
}

	//Funcion para Cierre y Despedida del Programa
void cierre()
{
	cout<<endl<<"	    Se procedera al cierre del programa."<<endl<<"	    Hasta Pronto :)"<<endl<<endl;
}


//PROCESO
main()
{
		//Declaracion de Variables
	int   cedula, cedulaMayor, cedulaMenor;
	float remuneracion, FT, UT, cargaFamiliar, desUT, tasa, ISLR, contribuyenteMayor, contribuyenteMenor;
	char  respuesta;
	
		//Contadores
	float contSinISLR, cont6, cont9, cont12, cont16, cont20, cont24, cont29, cont34, contAux;
	
		//Acumuladores
	float remuneracionT, descuentoT, totalISLR;
	
		//Inicializacion de variables
	tasa				=   0;
	respuesta			= 's';
	contSinISLR			= 	0;
	cont6				=	0;
	cont9				=	0;
	cont12				=	0;
	cont16				=	0;
	cont20				=	0;
	cont24				=	0;
	cont29				=	0;
	cont34				=	0;
	contAux				=	0;
	remuneracionT		=	0;
	descuentoT			=	0;
	totalISLR			=	0;
	contribuyenteMayor	= 	0;
	contribuyenteMenor	= 	99999999999;
	cedulaMayor			= 	0;
	cedulaMenor			= 	0;
	
		//Ciclo de Repeticion para Calcular otro Cliente
	do
	{
			//Inicializacion de Variables dentro del ciclo
		UT		= 0;
		tasa	= 0;
		desUT	= 0;
		
		bienvenida();
		entradaDatos(cedula, remuneracion, cargaFamiliar);
		UT = calcularUT(remuneracion);
	
		if(UT>=32000)
		{
			UT	= descuentoCargaFamiliar(UT, cargaFamiliar);			
			
			if(UT>=32000)
			{
					//FT es Fraccion Tributaria, variable para ubicar la tasa y el descuento en UT segun la tabla de datos
				FT				= UT-32000;
				remuneracionT 	= remuneracionT+remuneracion;
				
					//Ubica el Valor de Porcentaje y del Descuento en Unidades Tributarias (UT) a utilizar para la funcion desceuntoUT
				ubicacionDescuentoUT(FT, tasa, desUT, cont6, cont9, cont12, cont16, cont20, cont24, cont29, cont34);
				
				UT			= descuentoUnidadT(UT, tasa, desUT);
				descuentoT 	= descuentoT+desUT;
				ISLR		= calcularBs(UT);
				totalISLR	= totalISLR+ISLR;
				reporteCliente  (cedula, remuneracion, cargaFamiliar, tasa, ISLR);
				
			}
			else
			{
				ISLR = 0;
				contSinISLR++;
				reporteCliente  (cedula, remuneracion, cargaFamiliar,tasa, ISLR);
			}
				
		}
		else
		{
			ISLR = 0;
			tasa = 0;
			contSinISLR++;
			reporteCliente  (cedula, remuneracion, cargaFamiliar,tasa, ISLR);
		}
		
			//Calcular cual de los contribuyentes es el mayor y el menor
		calcularMayorMenor(cedula, ISLR, cedulaMayor, cedulaMenor, contribuyenteMayor, contribuyenteMenor);
	
			//Determinar si hay otro cliente a facturar
		cout<<endl<<"	  Desea facturar otro cliente? Si(S)  No(N)"<<endl;
		cout<<endl<<"	  ";cin>>respuesta;
		
			//Validar Respuesta
		validacionLetra(respuesta);
		system("cls");
	
	}while((respuesta == 's') || (respuesta == 'S'));
	
	descuentoT= calcularBs(descuentoT);
	reporteFinDia(contSinISLR, cont6, cont9, cont12, cont16, cont20, cont24, cont29, cont34, remuneracionT, descuentoT, totalISLR, contribuyenteMayor, contribuyenteMenor, cedulaMayor, cedulaMenor);
	system("pause");
	cierre();
	
	system("pause");
	
	return 0;
}
