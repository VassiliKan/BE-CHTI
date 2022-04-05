

#include "DriverJeuLaser.h"
#include "GestionSon.h"

extern void callbackSon(void);
extern void StartSon(void);

int bouton=0;

int main(void)
{

// ===========================================================================
// ============= INIT PERIPH (faites qu'une seule fois)  =====================
// ===========================================================================

// Apr�s ex�cution : le coeur CPU est clock� � 72MHz ainsi que tous les timers
CLOCK_Configure();

// configuration du Timer 4 en d�bordement 100ms
Active_IT_Debordement_Timer(TIM4, 2, callbackSon);
	
PWM_Init_ff( TIM3, 3, 720 );
	
// Association de la fonction � ex�cuter lors de l'interruption : timer_callback
// cette fonction (si �crite en ASM) doit �tre conforme � l'AAPCS
Timer_1234_Init_ff(TIM4, 6552);

GPIO_Configure(GPIOB, 0, OUTPUT, ALT_PPULL);
	
	

//============================================================================	
	
	
while	(1)
	{
		// test StartSon
		/*if(bouton==1){
			StartSon();
			bouton=0;
		}*/
	}
}



