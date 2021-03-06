#ifndef ENTITY_H_
#define ENTITY_H_

#include "libdragon.h"
#include "inventory.h"

dg_entity_t *ent_player(int x, int y);
dg_entity_t *ent_decor(int x, int y, int id, dg_spritesheet_t *);
dg_entity_t *ent_object(char *, dg_spritesheet_t *, sfVector2f, sfVector2f);
dg_entity_t *ent_furret(int x, int y);
dg_entity_t *ent_music(char *path);
dg_entity_t *ent_warp_place(int x, int y);
dg_entity_t *ent_ladder(int x, int y, int size, dg_spritesheet_t *ss);
dg_entity_t *ent_box(char *, dg_spritesheet_t *, sfVector2f, sfVector2f);
dg_entity_t *ent_machine(sfVector2f pos);
dg_entity_t *ent_door(sfVector2f pos, dg_spritesheet_t *ss);

void grab(inventory_t *, dg_entity_t *, dg_array_t **, int);

void ungrab(inventory_t *, dg_entity_t *, dg_array_t **, int);

#endif /* !ENTITY_H_ */
