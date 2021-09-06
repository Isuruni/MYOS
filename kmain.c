#include "io.h"
#include "framebuffer.h"
#include "serial_port.h"
#include "segmentation.h"
#include "keyboard.h"
#include "interrupts.h"
#include "multiboot.h"
#include "paging.h"

int kmain(multiboot_info_t *mbinfo)
{
     // Test appel module 
        module_t* modules = (module_t*) mbinfo->mods_addr;       
	unsigned int address_of_module = modules->mod_start;     
	
	if((mbinfo -> mods_count)==1){
	
	typedef void (*call_module_t)(void);
	call_module_t start_program = (call_module_t) address_of_module;
    	start_program();
    	}else
    		return 0;
   
    //Intialize gdt
      segments_install_gdt();
    //Initialize idt
      interrupts_install_idt();
    
    //paging
    init_paging();
   return 0; 
}

   
