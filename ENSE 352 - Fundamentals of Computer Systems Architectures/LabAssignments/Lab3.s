

  PRESERVE8
  THUMB  

INITIAL_MSP EQU 0x20001000

  AREA RESET, DATA, READONLY
  EXPORT __Vectors

__Vectors DCD INITIAL_MSP
          DCD Reset_Handler
  ALIGN

  AREA MYCODE, CODE, READONLY

  ENTRY
  EXPORT Reset_Handler

  ALIGN

Reset_Handler PROC
    ; load 0x1000 into R0
    MOV R0, #2048
    BL bitcheck11

    ; load 0x00F0 into R0
    MOV R0, #0x00F0
    BL bitoperations

    ; load 0x1F into R0
    MOV R0, #0x1F
    BL bitcount

    ; load input value into R0
    LDR R0, =0x12345678
    ; set rotation parameters in R1
    MOV R1, #0x21
    ; call rotation function
    BL rotateleftright

    ; infinite loop to prevent the program from ending
    B .                          
	ENDP   
	
bitcheck11 PROC
    ; save registers
    PUSH {R1, R2, R3, LR}
    ; load 0x0800 into R2
    LDR R2, =0x0800
    ; check bit 11
    BL bitcheck
    ; restore registers
    POP {R1, R2, R3, PC}
	ENDP 

bitoperations PROC
    ; save registers
    PUSH {R1, R2, R3, LR}
    ; set bit 3
    BL set3rdbit
    ; clear bit 7
    BL clear7thbit
    ; restore registers
    POP {R1, R2, R3, PC}
	ENDP 

bitcount PROC
    ; save registers
    PUSH {R1, R2, R3, LR}
    MOV R1, #0
    ; move value in R0 to R3
    MOV R3, R0
    ; call counting loop
    BL count_bits
    ; restore registers
    POP {R1, R2, R3, PC}
	ENDP

bitcheck PROC
    ; save link register
    PUSH {LR}
    ; perform AND operation between R0 and R2
    AND R3, R0, R2
    CMP R3, #0
    MOVEQ R1, #0
    MOVNE R1, #1

	POP {PC}
	ENDP

set3rdbit PROC
    ; save link register
    PUSH {LR}
    ; load 0x0008 into R2
    LDR R2, =0x0008
    ; set bit 3 of R0
    ORR R0, R0, R2
    ; return
    POP {PC}
	ENDP 

clear7thbit PROC
    ; save link register
    PUSH {LR}
    ; load mask to clear bit 7
    LDR R2, =0xFF7F
    ; clear bit 7 of R0
    AND R0, R0, R2
    ; return
    POP {PC}
	ENDP 
	
count_bits PROC
    ; save link register
    PUSH {LR}
    ; initialize R2 to 0
    MOV R2, #0
bitloop
    ; AND the least significant bit with 1
    AND R1, R3, #1
    ; add result to R2
    ADD R2, R2, R1
    ; shift R3 right by 1 bit
    LSR R3, R3, #1
    ; compare R3 with 0
    CMP R3, #0
    ; repeat loop if R3 is not zero
    BNE bitloop
    ; move result to R1
    MOV R1, R2
    ; return
    POP {PC}
	ENDP 
 
rotateleftright PROC
    ; save registers
    PUSH {R2, R3, R4, LR}
    ; move R1 to R2
    MOV R2, R1
    ; mask R1 with 0x0F 15 in dec
    AND R1, R2, #0x0F
    CMP R1, #0
    BEQ restorevalue

    ; save original R0 in R3 and R4
    MOV R3, R0
    MOV R4, R0
    ; load mask into R6
	LDR R6, =0xFFFF
    ; mask R0
    AND R0, R0, R6
    ; move R4 to R5
    MOV R5, R4
    ; shift R4 right by 16 bits
    LSR R4, R5, #16

    ; check if direction is left
    CMP R2, #0
    BNE rotateleftshift
    BL rotaterightshift
	ENDP

rotateleftshift PROC
    ; shift R0 left by the rotate amount
    LSL R0, R0, R1
    ; shift R5 le\ft by 16 bits
    MOV R5, R4
    LSL R5, R5, #16
    ; OR R0 and R5
    ORR R0, R0, R5
    ; return
    BX LR
	ENDP
	
rotaterightshift PROC
    ; shift R0 right by the rotate amount
    LSR R0, R0, R1
    ; shift R5 right by 16 bits
    MOV R5, R4
    LSR R5, R5, #16
    ; OR R0 and R5
    ORR R0, R0, R5
    ; return
    BX LR
	ENDP

restorevalue PROC
    ; restore original R0 from R3
    MOV R0, R3
    ; restore registers
    POP {R2, R3, R4, PC}
	ENDP

finish PROC
    ; restore registers and return
    POP {R2, R3, R4, PC}
	ENDP
		
	ALIGN
	END
