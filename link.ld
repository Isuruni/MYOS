    ENTRY(loader)           /* the name of the entry symbol */

  kernel_virtual_start = . ;
  kernel_physical_start = . - 0xC0000000;  
  
OUTPUT_FORMAT("binary")    /* output flat binary */

SECTIONS {
       . = 0;                 /* relocate to address 0 */

    .text ALIGN (0x1000) :   /* align at 4 KB */
    {
    	 start.o(.text)     /* include the .text section of start.o */
        *(.text)             /* all text sections from all files */
    }

    .rodata ALIGN (0x1000) : /* align at 4 KB */
    {
        *(.rodata*)          /* all read-only data sections from all files */
    }

    .data ALIGN (0x1000) :   /* align at 4 KB */
    {
        *(.data)             /* all data sections from all files */
    }

    .bss ALIGN (0x1000) :    /* align at 4 KB */
    {
        *(COMMON)            /* all COMMON sections from all files */
        *(.bss)              /* all bss sections from all files */
    }

}

    kernel_virtual_end = .;
    kernel_physical_end = . - 0xC0000000;
