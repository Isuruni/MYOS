#include "framebuffer.h"
#include "serial_port.h"
#include "segmentation.h"
void kmain(){

    char msg[] = "MYOS";
   
   serial_write(0x3F8, msg, 4);
   fb_write(msg, 4);
   segments_install_gdt();
   
}
