#include "DriverJeuLaser.h"

extern int calculReel(short*, int);
extern short LeSignal;

int tab[64];

int main(void)
{

// ===========================================================================
// ============= INIT PERIPH (faites qu'une seule fois)  =====================
// ===========================================================================

// Apr�s ex�cution : le coeur CPU est clock� � 72MHz ainsi que tous les timers
CLOCK_Configure();
	
for(int i = 0; i < 64; i++){
	tab[i] = calculReel(&LeSignal, i);
}

	
	

//============================================================================	
	
	
while	(1)
	{
	}
}

