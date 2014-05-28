/**
 * @file gen-db.c
 * 
 * @brief Functions for interacting with the planet database
 * used for generating universes.
 */

#include "gen-db.h"

#include "space.h"
#include "toolkit.h"
#include "menu.h"
#include "dialogue.h"
#include "gui.h"

#define WND_WIDTH      600 
#define WND_HEIGHT     500 

#define BUTTON_WIDTH    80 
#define BUTTON_HEIGHT   30 

void gendb_dbscreen_close(unsigned int wnd);

/**
 * @brief Opens the load game menu.
 */
void gendb_loadDatabaseScreen (void){
   unsigned int wnd;

   wnd = window_create( "Planet/System Database (For Galaxy Generation)", -1, -1, WND_WIDTH, WND_HEIGHT );

   window_addList( wnd, 20, -50,
         WND_WIDTH-40-BUTTON_WIDTH-20, WND_HEIGHT-70,
         "lstPlanets", NULL, 0, 0, NULL );

   window_addButton( wnd, -20, 20, BUTTON_WIDTH, BUTTON_HEIGHT,
         "btnBack", "Back", gendb_dbscreen_close );
   window_addButton( wnd, -20, 20 + BUTTON_HEIGHT+20, BUTTON_WIDTH, BUTTON_HEIGHT,
         "btnDel", "Del", NULL );
   window_addButton( wnd, -20, 20 + 2 * (BUTTON_HEIGHT + 20), BUTTON_WIDTH, BUTTON_HEIGHT,
         "btnAdd", "Add", NULL );
}

void gendb_dbscreen_close(unsigned int wnd) {
   window_destroy(wnd);
}