	PRESERVE8
	THUMB   
	
	include DriverJeuLaser.inc	

	EXPORT callback;
	
; ====================== zone de réservation de données,  ======================================
;Section RAM (read only) :
	area    mesdata,data,readonly


;Section RAM (read write):
	area    maram,data,readwrite
		

	
; ===============================================================================================
	
FlagCligno dcd 0

		
;Section ROM code (read only) :		
	area    moncode,code,readonly
; écrire le code ici		


callback
	push {lr}
	ldr r0, =FlagCligno
	ldr r1, [r0]
	push {r0}
	cmp r1, #1
	beq set
	mov r0, #1
	bl GPIOB_Clear
	mov r1, #1
	
fin
	pop {r0}
	str r1, [r0]
	pop {pc}
	; equivalent
	; pop {lr}	
	; bx lr
	
set
	mov r0, #1
	bl GPIOB_Set
	mov r1, #0	
	b fin
		
	END	