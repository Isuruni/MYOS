#ifndef INCLUDE_INTERRUPTS
#define INCLUDE_INTERRUPTS

/* Typedefs, to standardise sizes across platforms.
 * These typedefs are written for 32-bit X86.
 */
typedef unsigned int u32int;
typedef int s32int;
typedef unsigned short u16int;
typedef short s16int;
typedef unsigned char u8int;
typedef char s8int;

/* Frame buffer supported color value */
#define FB_BLACK 0
#define FB_BLUE 1
#define FB_GREEN 2
#define FB_CYAN 3
#define FB_RED 4
#define FB_MAGENTA 5
#define FB_BROWN 6
#define FB_LIGHT_GREY 7
#define FB_DARK_GREY 8
#define FB_LIGHT_BLUE 9
#define FB_LIGHT_GREEN 10
#define FB_LIGHT_CYAN 11
#define FB_LIGHT_RED 12
#define FB_LIGHT_MAGENTA 13
#define FB_LIGHT_BROWN 14
#define FB_WHITE 15


struct IDT 
{
	unsigned short size;
	unsigned int address;
} __attribute__((packed));

struct IDTDescriptor {
	/* The lowest 32 bits */
	unsigned short offset_low; // offset bits 0..15
	unsigned short segment_selector; // a code segment selector in GDT or LDT
	
	/* The highest 32 bits */
	unsigned char reserved; // Just 0.
	unsigned char type_and_attr; // type and attributes
	unsigned short offset_high; // offset bits 16..31
} __attribute__((packed));

void interrupts_install_idt();

void load_idt(unsigned int idt_address);
void interrupt_handler_33();
void interrupt_handler_14();

//Interrupt Handler
typedef struct cpu_state {
  u32int edi;
  u32int esi;
  u32int ebp;
  u32int esp;
  u32int ebx;
  u32int edx;
  u32int ecx;
  u32int eax;
} cpu_state_t;

typedef struct stack_state {
  u32int int_no;
  u32int err_code;
  u32int eip;
  u32int cs;
  u32int eflags;
  u32int useresp;
  u32int ss;
} stack_state_t;

typedef struct registers {
  /* Data segment selector */
  u32int ds;
  /* Pushed by pusha */
  cpu_state_t cpu_registers;
  /* Interrupt number and error code (if applicable). Pushed by the processor
   * automatically.
   */
  stack_state_t stack_contents;
} registers_t;

typedef void (*isr_t)(registers_t);

void register_interrupt_handler(u8int n, isr_t handler);

void page_fault(registers_t regs);

void interrupt_handler(struct cpu_state cpu, unsigned int interrupt, struct stack_state stack);

#endif /* INCLUDE_INTERRUPTS */
