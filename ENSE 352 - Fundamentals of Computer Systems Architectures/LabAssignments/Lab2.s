;;; Directives

  PRESERVE8

  THUMB  

;;; Equates


INITIAL_MSP    EQU        0x20001000    ; Initial Main Stack Pointer Value    Allocating

                                              ; 1000 bytes to the stack as it grows down.

                 

                                    

; Vector Table Mapped to Address 0 at Reset

; Linker requires __Vectors to be exported


  AREA    RESET, DATA, READONLY

  EXPORT  __Vectors


__Vectors    DCD        INITIAL_MSP            ; stack pointer value when stack is empty

            DCD        Reset_Handler        ; reset vector

            

  ALIGN


;The program

; Linker requires Reset_Handler


  AREA    MYCODE, CODE, READONLY




  ENTRY

  EXPORT    Reset_Handler


  ALIGN

Reset_Handler    PROC

	BL phase1

	BL factorialPhase 
	
	MOV R9, #0x0
	LDR R6, String1
	BL countVowels  
	
	MOV R9, #0x0
	LDR R6, String2
	BL countVowels 

	ENDP

phase1 PROC
                                
 ;phase 1
  MOV R0, #0x00001111 ;loads value 0x00001111 into R0
  PUSH{R0} ;pushes onto the stack

  MOV R1, #0x00002222 ;loads value 0x00002222 into R1
  PUSH{R1};pushes onto the stack

  MOV R2, #0x00003333 ;loads value 0x00003333 into R2
  PUSH{R2};pushes onto the stack
    
;STACK follows fifo
  POP{R3} ; the top of the stack gets popped off, in this case since R2 was the most recent one, it gets popped off.
  POP{R3} ; pops off R1
  POP{R3} ; pop off R0

  PUSH{R0,R1,R2} ;push the three values onto the stack at once
  POP{R0,R1,R2} ;pops them back.

  BX LR
  ENDP
      
 ;phase 2
 ;factorial logic: n! = n*(n-1)*(n-2) etc.
 
factorialPhase PROC ;start of a procedure/subroutine
  MOV R1, #4  ;register 1 loaded with the integer value of 4. (n)
  MOV R2, #1  ;register 2 set to 1, this is what temporarily will be used to store the factorial.
  PUSH {R1}
  CMP R1,#0 
  BEQ zeroCount
  
 
loop
  MUL R2,R1,R2 ;R2 *= R1 ->outputs a 4 in R2
  SUB R1, R1,#1 ; subtracts one from made up 'n' term, and holds it in R1, ie decreses it by 1.
  CMP R1,#0  ; compares R1 to 0, acts as a check to see if it should continue
  BNE loop ; branch if not equal, branches to loop if r1 is not equal to 0,
  BX LR ; branch to the link register address (R14)
  
zeroCount
  MOV R1,#1
  BX LR
  ;Notes:
  ;LR Contains the address that instructs the computer where it needs to go back to AFTER the function is completed.
  ;expected output for the case of 4 should be x18 (hex of 24)  
      
  ENDP
	  
	  
;phase 3
;Store two strings ”ENSE 352 is fun and I am learning ARM assembly!” and ”Yes I really love it!”

;each character in a string is stored as a byte, 8 bits.
;the stored value is corresponding to the conversion table.

String1 
	DCB "ENSE 352 is fun and I am learning ARM assembly!",0
String2 
	DCB "Yes I really love it!",0 
	

	
countVowels PROC
    MOV R8, #0            ; vowel count to r0
vowelLoop
    LDRB R9, [R6], #1     ; load bytes from string and increment r6
    CMP R9, #0            ; checks for null
    BEQ exitVowelCount    ; branch if equal/true

    ; Compare R9 with each vowel (both lowercase and uppercase)
    CMP R9, #'A'
    ADDEQ R8, R8, #1 ;addeq adds if comparison is true.
    
    CMP R9, #'a'
    ADDEQ R8, R8, #1

    CMP R9, #'E'
    ADDEQ R8, R8, #1
    
    CMP R9, #'e'
    ADDEQ R8, R8, #1

    CMP R9, #'I'
    ADDEQ R8, R8, #1
    
    CMP R9, #'i'
    ADDEQ R8, R8, #1

    CMP R9, #'O'
    ADDEQ R8, R8, #1
    
    CMP R9, #'o'
    ADDEQ R8, R8, #1

    CMP R9, #'U'
    ADDEQ R8, R8, #1
    
    CMP R9, #'u'
    ADDEQ R8, R8, #1

    CMP R9, #'Y'
    ADDEQ R8, R8, #1

    CMP R9, #'y'
    ADDEQ R8, R8, #1

    B vowelLoop           ; loops to next character

exitVowelCount
    BX LR                 ; link register.
  ENDP

  END