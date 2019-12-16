#include "../../lib/gl2d.h"

#include "health.h"

#include "../../resources/textures/hud/soul_heart_half.png.h"
#include "../../resources/textures/hud/soul_heart.png.h"
#include "../../resources/textures/hud/heart_half.png.h"
#include "../../resources/textures/hud/heart_empty.png.h"
#include "../../resources/textures/hud/heart.png.h"
#include "../../resources/textures/hud/eternal_heart.png.h"
#include "../../resources/textures/hud/black_heart_half.png.h"
#include "../../resources/textures/hud/black_heart.png.h"
#include "../../resources/textures/hud/soul_heart_half.png.h"



Health::Health(Texture *texture) {
    this->texture = texture;
}

const Health Health::HEART_CONTAINER = Health(&heart);
const Health Health::HEART_CONTAINER_HALF = Health(&heart_half);
const Health Health::SOUL_HEART = Health(&soul_heart);
const Health Health::SOUL_HEART_HALF = Health(&soul_heart_half);
const Health Health::BLACK_HEART = Health(&black_heart);
const Health Health::BLACK_HEART_HALF = Health(&black_heart_half);
const Health Health::ETERNAL_HEART = Health(&eternal_heart);