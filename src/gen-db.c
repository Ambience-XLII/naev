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

#define LOAD_WIDTH      600 /**< Load window width. */
#define LOAD_HEIGHT     500 /**< Load window height. */

#define BUTTON_WIDTH    80 /**< Button width. */
#define BUTTON_HEIGHT   30 /**< Button height. */

void gendb_dbscreen_close(unsigned int wnd);

/**
 * @brief Opens the load game menu.
 */
void gendb_loadDatabaseScreen (void){
   unsigned int wid;

   wid = window_create( "Planet/System Database (For Galaxy Generation)", -1, -1, LOAD_WIDTH, LOAD_HEIGHT );

   window_addList( wid, 20, -50,
         LOAD_WIDTH-40-BUTTON_WIDTH-20, LOAD_HEIGHT-70,
         "lstSaves", NULL, 0, 0, NULL );

   window_addButton( wid, -20, 20, BUTTON_WIDTH, BUTTON_HEIGHT,
         "btnBack", "Back", gendb_dbscreen_close );
   window_addButton( wid, -20, 20 + BUTTON_HEIGHT+20, BUTTON_WIDTH, BUTTON_HEIGHT,
         "btnLoad", "Del", NULL );
   window_addButton( wid, -20, 20 + 2 * (BUTTON_HEIGHT + 20), BUTTON_WIDTH, BUTTON_HEIGHT,
         "btnDelete", "Add", NULL );
}

void gendb_dbscreen_close(unsigned int wnd) {
   window_destroy(wnd);
}