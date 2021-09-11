#ifndef INCLUDE_KHEAP_H
#define INCLUDE_KHEAP_H

#pragma once
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

/* set_physical_address_top:
 *  Set the top of physical address global variable. This is required to keep
 *  track of the memory thats allocated till now. Initially, this is set to top
 *  of address where kernel ends. We keep moving this as memory is allocated.
 *
 *  @param phyAddress Current Address End, we get this from linker script.
 */
void set_physical_address(u32int kerNelPhysicalStart, u32int kernelPhysicalEnd);

/* kmalloc_int:
 *  Allocate a chunk of memory, size in size. If align == 1,
 *  the chunk must be page-aligned. If pAddrPtr != 0, the physical
 *  location of the allocated chunk will be stored into phys.
 *
 *  @param size      Size of memory to be allocated
 *  @param align     Align allocated memory at 4kb address
 *  @param pAddrPtr  Store the physical address of the page
 */
u32int kmalloc_int(u32int size, u32int align, u32int *pAddrPtr);

/* kmalloc_a:
 *  Allocate a chunk of memory, size in size. The chunk must be
 *  page aligned.
 *
 *  @param size Size of memory to be allocated
 */
u32int kmalloc_a(u32int size);

/* kmalloc_p:
 *  Allocate a chunk of memory, size in size. The physical address
 *  is returned in pAddrPtr. pAddrPtr MUST be a valid pointer to u32int!
 *
 *  @param pAddrPtr  Pointer to store the physical address of
 *  the page
 */
u32int kmalloc_p(u32int sz, u32int *pAddrPtr);

/* kmalloc_p:
 *  Allocate a chunk of memory, size in size. The physical address
 *  is returned in pAddrPtr. It must be page-aligned.
 *
 *  @param size      Size of memory to be allocated
 *  @param pAddrPtr  Pointer to store the physical address of
 *  the page
 */
u32int kmalloc_ap(u32int size, u32int *pAddrPtr);

/* kmalloc:
 *  Generic function to allocate chunk of memory, size in size.
 *
 *  @param size  Size of memory to be allocated
 */
u32int kmalloc(u32int size);

#endif /* INCLUDE_KHEAP_H */
