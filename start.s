extern main

USER_MODE_CODE_SEGMENT_SELECTOR equ 0x18
USER_MODE_DATA_SEGMENT_SELECTOR equ 0x20

mov cs, USER_MODE_CODE_SEGMENT_SELECTOR | 0x3
mov ss, USER_MODE_DATA_SEGMENT_SELECTOR | 0x3

    section .text
        ; push argv
        ; push argc

call main
        ; main has returned, eax is return value
        jmp  $    ; loop forever
