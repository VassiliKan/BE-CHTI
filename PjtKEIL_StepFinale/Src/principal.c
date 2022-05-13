#include "DriverJeuLaser.h"
#include "Affichage_Valise.h"
#include <stdio.h>
#include "GestionSon.h"

extern void callbackSon(void);
extern void StartSon(void);
extern int DFT_ModuleAuCarre(short*, int);
extern short LeSignal;

short int dma_buf[64];
int tab[64];
int cycleLED[10] = {0, 1, 3, 0, 2, 3, 1, 3, 1, 3};
int bouton = 0;
int cpt = 0;

void callback(){
	Start_DMA1(64);
	Wait_On_End_Of_DMA1();
	Stop_DMA1;
/*for(int i = 0; i < 64; i++){
		tab[i] = DFT_ModuleAuCarre(dma_buf, i);
	}*/
	if(cpt % 700 == 0){
		cpt = 0;
		Prepare_Set_LED(cycleLED[1]);
		Prepare_Clear_LED(cycleLED[0]);
	}
	cpt++;
	Mise_A_Jour_Afficheurs_LED();
}

int main(void)
{

// ===========================================================================
// ============= INIT PERIPH (faites qu'une seule fois)  =====================
// ===========================================================================
	
// Après exécution : le coeur CPU est clocké à 72MHz ainsi que tous les timers
CLOCK_Configure();
	
Init_TimingADC_ActiveADC_ff( ADC1, 72 );
Single_Channel_ADC( ADC1, 2 );
Init_Conversion_On_Trig_Timer_ff( ADC1, TIM2_CC2, 225 );
Init_ADC1_DMA1( 0, dma_buf );
	
Systick_Period_ff( 360000 );
Systick_Prio_IT( 2, callback );
SysTick_On;	
SysTick_Enable_IT;	
	
Active_IT_Debordement_Timer(TIM4, 2, callbackSon);
PWM_Init_ff( TIM3, 3, 720 );
Timer_1234_Init_ff(TIM4, 6552);
GPIO_Configure(GPIOB, 0, OUTPUT, ALT_PPULL);
	
	

//============================================================================	
	
	
while	(1)
	{
		if(bouton==1){
			StartSon();
			bouton=0;
		}
	}
}

