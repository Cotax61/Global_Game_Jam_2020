#ifndef SYSTEM_H_
#define SYSTEM_H_

#include "libdragon.h"

void sys_set_pos_sprite(dg_entity_t *entity, dg_window_t *w, dg_array_t **entities, sfTime dt);
void sys_gravity(dg_entity_t *, dg_window_t *, dg_array_t **, sfTime);

#endif /* !SYSTEM_H_ */