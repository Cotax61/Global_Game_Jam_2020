//Auteur : Alexia
//Rigid body (gravity)

#include <stdlib.h>
#include <stdio.h>
#include "libdragon.h"
#include "inventory.h"

void ungrab(inventory_t *inv, dg_entity_t *entity, dg_array_t **entities, int id)
{
    sfVector2u *pos = 0;
    sfVector2u *npos = (sfVector2u *)dg_entity_get_component(entity, "pos");

    if (id != 1) {
        pos = (sfVector2u *)dg_entity_get_component(inv->left, "pos");
        dg_arr_add_begin(entities, inv->left);
        inv->left = 0;
    } else {
        pos = (sfVector2u *)dg_entity_get_component(inv->right, "pos");
        dg_arr_add_begin(entities, inv->right);
        inv->right = 0;
    }
    pos->x = npos->x;
    pos->y = npos->y;
}

void grab(inventory_t *inv, dg_entity_t *entity, dg_array_t **entities, int id)
{
    int index = 0;
    void *data = 0;
    dg_array_t *tmp = *entities;

    for (; tmp && tmp->data != entity; tmp = tmp->next, index++);
    data = dg_arr_remove_at(entities, index);
    if (id == 1)
        inv->left = (dg_entity_t *)(data);
    else
        inv->right = (dg_entity_t *)(data);
}

static void component_destroy(void *data)
{
    inventory_t *ent = (inventory_t *)(data);

    dg_entity_destroy(ent->left);
    dg_entity_destroy(ent->right);
    free(ent);
}

dg_component_t *cpt_inventory(void)
{
    dg_cpt_destroy_t destroy = &component_destroy;
    inventory_t *inv = malloc(sizeof(inventory_t));
    dg_component_t *component = dg_component_create("inventory", inv, destroy);

    if (!inv || !component) {
        dprintf(2, "Error: inv not created.\n");
        return 0;
    }
    inv->left = 0;
    inv->right = 0;
    return component;
}
