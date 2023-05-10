
#include <stdio.h>																// Acesso as opercoes de entradas e/ou saidas.
#include <driver/adc.h>															// Modulo conversor ADC.
#include "geralv2r1.h"
#include "wifiv1r1.h"
                                                       





/// @brief 
/// @param valor 
/// @param buffer 
/// @param digi 


void adcIniciar(void)															// Inicializa o hardware do modulo conversor ADC.
{
	adc1_config_width(ADC_WIDTH_BIT_12); 										// Config. a resolucao do ADC para 12bits.
	adc1_config_channel_atten(ADC1_CHANNEL_0,ADC_ATTEN_DB_11); 					// Config. a atenuacao do Canal 0 (GPIO36).
	adc1_config_channel_atten(ADC1_CHANNEL_3,ADC_ATTEN_DB_11); 					// Config. a atenuacao do Canal 3 (GPIO39).
	/*
	Attenuation			Measurable input voltage range
	ADC_ATTEN_DB_0		100 mV ~ 950 mV
	ADC_ATTEN_DB_2_5	100 mV ~ 1250 mV
	ADC_ATTEN_DB_6		150 mV ~ 1750 mV
	ADC_ATTEN_DB_11 	150 mV ~ 2450 mV
	*/
}



void app_main(void)
{

	unsigned int umidade, temperatura;
	char vlrAsc2[]={"0000"};													// Var. para o valor em ASCII.
	char vlrAsc3[]={"0000"};

	wifi_init();
	
	
	

	while (1)
	{
		dhtxxIniciar();
		dhtxx(2,&umidade, &temperatura);
		int2Asc(umidade,vlrAsc2,4); 										// Converte o valor 'int' em ASCII.
		int2Asc(temperatura,vlrAsc3,4); 
		 printf("Umidade: %s%%, Temperatura: %sC\n", vlrAsc2, vlrAsc3); // Imprime os valores no terminal.
		vTaskDelay(100);
		   
	}
	


}