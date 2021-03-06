#ifndef INCLUDE_PAGING_H
#define INCLUDE_PAGING_H


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

typedef struct page {
  /* Page is present in memory if set */
  u32int present : 1;

  /* Read-only if clear, readwrite if set */
  u32int rw : 1;

  /* Supervisor level only if clear */
  u32int user : 1;

  /* Page been accessed since last refresh if set */
  u32int accessed : 1;

  /* Page been written to since last refresh if set */
  u32int dirty : 1;

  /* Amalgamation of unused and reserved bits */
  u32int unused : 7;

  /* Frame address (shifted right 12 bits). Since the frames are aligned at 4kb
   * least 12 bits are always zero.
   */
  u32int frame : 20;
} page_t;

typedef struct page_table {
  page_t pages[1024];
} page_table_t;

typedef struct page_directory {
  /*
   * Array of pointers to pagetables.
   */
  page_table_t *tables[1024];

  /*
   * Array of pointers to the pagetables above, but gives their *physical*
   * location, for loading into the CR3 register.
   */
  u32int tablesPhysical[1024];

  /*
   * The physical address of tablesPhysical. This comes into play when we get
   * our kernel heap allocated and the directory may be in a different location
   * in virtual memory.
   */
  u32int physicalAddr;
} page_directory_t;

/*
 * Sets up the environment, page directories etc and enables paging.
 */
void init_paging(u32int kerNelPhysicalStart, u32int kernelPhysicalEnd);

/*
 * Causes the specified page directory to be loaded into the CR3 register.
 */
void switch_page_directory(page_directory_t *new);

/*
 * Retrieves a pointer to the page required. If make == 1, if the page-table in
 * which this page should reside isn't created, create it!
 */
page_t *get_page(u32int address, u8int make, page_directory_t *dir);

#endif /* INCLUDE_PAGING_H */
