#include <bn_core.h>
#include <bn_sprite_ptr.h>
#include <bn_sprite_animate_actions.h>

#include "bn_sprite_items_look.h"

int main()
{
    bn::core::init();

    const int frames = 6;

    bn::sprite_ptr looker = bn::sprite_items::look.create_sprite();
    // Set the animation frame to the second frame (frame 1)
    looker.set_tiles(bn::sprite_items::look.tiles_item(), 1);

    // Sprite animate loop
    bn::sprite_animate_action<frames> animation = bn::create_sprite_animate_action_forever(
        looker,
        10,
        bn::sprite_items::look.tiles_item(), 0, 1, 2, 3, 2, 1);

    while (true)
    {
        animation.update();
        bn::core::update();
    }
}