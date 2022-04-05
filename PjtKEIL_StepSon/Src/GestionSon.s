	PRESERVE8
	THUMB   
	
	include DriverJeuLaser.inc	
			
	extern Son
	extern LongueurSon
	
	EXPORT callbackSon
	EXPORT Index
	EXPORT SortieSon
	EXPORT StartSon
; ====================== zone de réservation de données,  ======================================
;Section RAM (read only) :
	area    mesdata,data,readonly


;Section RAM (read write):
	area    maram,data,readwrite
		

	
; ===============================================================================================
	

SortieSon dcd 0
Index dcd 0
		
;Section ROM code (read only) :		
	area    moncode,code,readonly
; écrire le code ici		

fin
	pop {pc, r7}
		
StartSon
	ldr r0, =Index
	ldr r1, [r0]
	mov r1, #0
	str r1, [r0]
	bx lr
		
callbackSon
	push {lr, R7}
	ldr r0, =Index
	ldr r1, [r0]
	ldr r2, =LongueurSon
	ldr r3, [r2]
	cmp r1, r3					; if (Index == LongueurSon){
	bge fin						; exi t
	
	ldr r2, =Son
	ldrsh r3, [r2, r1, lsl #1]  ; r3 = tabSon[Index * 2]
	  
	mov r7, #720
	mul r3, r3, r7
	asr r3, r3, #16				;  x * 720 / 2^16;
	add r3, r3, #360			; x += 360;
	ldr r12, =SortieSon
	str r3, [r12]				; SortieSon = x;
	; paramètres sortie son a set
	push {r0,r1}
	mov r0, r3
	bl PWM_Set_Value_TIM3_Ch3
	pop {r0,r1}
	
	add r1, #1					; index++;
	str r1, [r0]
	
	pop{pc,r7}
	
	end