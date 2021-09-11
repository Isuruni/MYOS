#include "io.h"
#include "framebuffer.h"
#include "serial_port.h"
#include "segmentation.h"
#include "keyboard.h"
#include "interrupts.h"
#include "multiboot.h"
#include "paging.h"

int kmain(multiboot_info_t *mbinfo, u32int kernel_physical_start, u32int kernel_physical_end)
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
    
    //paging
   
   init_paging(kernel_physical_start, kernel_physical_end);

    //Intialize gdt
      segments_install_gdt();
    //Initialize idt
      interrupts_install_idt();
    
    
   return 0; 
}



   
   
   
