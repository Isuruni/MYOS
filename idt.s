global  load_idt

			; load_idt - Loads the interrupt descriptor table (IDT).
			; stack: [esp + 4] the address of the first entry in the IDT
			;        [esp    ] the return address		
	
load_idt:
mov ss, [esp + 16]  	; the stack segment selector we want for user mode
	mov esp,[esp + 12]  	; the user mode stack pointer
	mov eflags,[esp +  8] 	; the control flags we want to use in user mode
	mov cs, [esp +  4]  	; the code segment selector
	mov eip, [esp +  0]  	; the instruction pointer of user mode code to execute
        mov eax, [esp + 4]  	; load the address of the IDT into register eax
        lidt [eax]          	; load the IDT
        ret                 	; return to the calling function
        	
