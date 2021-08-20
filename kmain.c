#include "framebuffer.h"
#include "serial_port.h"
#include "segmentation.h"
#include "keyboard.h"
#include "interrupts.h"

void kmain(){

    //char msg[] = "MYOS";
    
    unsigned char scancode,ascii;
    char asciicode[0];
    
    segments_install_gdt();
    //serial_write(0x3F8, msg, 4);
    //fb_write(msg, 4);
   
    interrupts_install_idt();
    scancode = keyboard_read_scan_code();
    ascii = keyboard_scan_code_to_ascii(scancode);
    asciicode[0] = ascii;
    serial_write(asciicode, sizeof(asciicode));
    //fb_write(asciicode, sizeof(asciicode));
   
}

