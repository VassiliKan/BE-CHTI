#include "DriverJeuLaser.h"
#include <stdio.h>

extern int calculDFT(short*, int);
extern short LeSignal;

int tab[64];

int main(void)
{

// ===========================================================================
// ============= INIT PERIPH (faites qu'une seule fois)  =====================
// ===========================================================================

// Après exécution : le coeur CPU est clocké à 72MHz ainsi que tous les timers
CLOCK_Configure();
	
for(int i = 0; i < 64; i++){
	tab[i] = calculDFT(&LeSignal, i);
}

	
	

//============================================================================	
	
	
while	(1)
	{
	}
}

