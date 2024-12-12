

  PRESERVE8
  THUMB
		
	AREA RESET, DATA, READONLY
	EXPORT __Vectors

__Vectors DCD 0x20002000 
	DCD Reset_Handler
	
	ALIGN

	AREA MYCODE, CODE, READONLY
	ENTRY

	EXPORT Reset_Handler

Reset_Handler PROC
	;calls subroutine to configure PA5 to be output, PC13 as input button
    BL phase1
	
    ; counter for led toggles, 20 because it goes 10 on then off.
    MOV R2, #20             
Blink_Loop
    BL ledSw               ; turns the LED on/off
    BL Delay               ; the amount of time that the light stays on
    SUBS R2, R2, #1        ; decrement the loop counter
    BNE Blink_Loop         ; If R2 is not zero, repeat the loop
    BL button     
	ENDP


;PA5 green led
;PC13 blue button
;;PHASE 1
;RCC_APB2ENR is the register controlling the clock for certain parts of the STM, like enabling power to the GPIO port.
;0x40021018
;GPIOA_CRL for configs = 0x40010800

	ALIGN
phase1 PROC
    LDR R0, =0x40021018      
    LDR R1, [R0]
    ORR R1, R1, #0x4         ; Port A
    ORR R1, R1, #0x10        ; Port C, think of it like enabling to 1 
    STR R1, [R0]
	; bits 2 and 4 set to 1
	
    LDR R0, =0x40010800      
    LDR R1, [R0]
    BIC R1, R1, #0xF00000    ; bits 20-23 for PA5
    ORR R1, R1, #0x300000    ; Sets to mode 11 for activation
    STR R1, [R0]
    BX LR                     
	ENDP
				
;;PHASE 2
;GPIOA_ODR is for controlling output value 0x4001080C
	ALIGN
ledSw PROC
    LDR R0, = 0x4001080C     
    LDR R1, [R0]              
    EOR R1, R1, #0x20         ; Toggles bit 5 via XOR
    STR R1, [R0]             
    BX LR                     
	ENDP
		
	ALIGN
		

; determines how long the state will stay high or low
Delay PROC
    LDR R3, =0xFFFFF          
; the timing for the delay per blink, FFFF used cause its larger in count.

Delay_Loop
    SUBS R3, R3, #1           ; goes down by 1, essentially a timer
    BNE Delay_Loop            ; R3!= 0, repeat
    BX LR   
	ENDP

ALIGN
;PHASE 3: Polling button state
; GPIOC_IDR, Input Data Register, port C in this case (PC13 input)
; LED lights while button is pressed and turns off when released
button PROC
checkButton
    LDR R6, =0x40011008       
    LDR R0, [R6]              
    AND R0, R0, #0x2000       ; isolate bit 13

    CMP R0, #0                ; cmp 0 to check if a button is pressed
    BEQ ledOn                 ; button being pressed is low, jumps to turn on led if low
    B ledOff                  ; if not prssed, goes to off

ledOn
    LDR R0, =0x4001080C       ; GPIOA_ODR for controlling output
    LDR R1, [R0]
    ORR R1, R1, #0x20         ; bit 5 to on, so that the led is on
    STR R1, [R0]
    B checkButton            

ledOff
    LDR R0, =0x4001080C       ; GPIOA_ODR for controlling output
    LDR R1, [R0]
    BIC R1, R1, #0x20         ; clears the bit to turn it off 
    STR R1, [R0]
    B checkButton             ; to check button status
	ENDP
	END