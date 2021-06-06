// vim: ft=c

/* only works for IS31FL3737 matrix */

RGB_MATRIX_EFFECT(vilebloom)

#ifdef RGB_MATRIX_CUSTOM_EFFECT_IMPLS

/* #define VB_BEIGE 0xf6,0xbd,0x9d */
/* #define VB_BEIGE 20, 36, 96 */
/* #define VB_PINK 0xff,0x80,0x8b */
/* #define VB_PINK 355, 50, 100 */
/* #define VB_PURPLE 0xcd,0x6c,0x8f */
/* #define VB_PURPLE 338, 47, 80 */
/* #define VB_BLUE 0x34,0x65,0x7f */
/* #define VB_BLUE 201, 59, 50 */

/* Base => Qwerty
 * ,-----------------------------------------------------------------------------------.
 * |   0  |   _  |   _  |      |   _  |   _  |      |   _  |   _  |   _  |   _  |   _  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |  12  |   _  |   _  |   _  |   _  |   _  |   _  |   _  |   _  |   _  |   _  |   _  |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |  24  |   _  |   _  |   _  |   _  |   _  |   _  |   _  |   _  |   _  |   _  |   _  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |  36  |   _  |   _  |      |   V  |      _      |   A  |   _  |   _  |   _  |   _  |
 * `-----------------------------------------------------------------------------------'
 */
static HSV vilebloom_math(HSV hsv, int16_t dx, int16_t dy, uint8_t dist, uint8_t time) {
    switch {
        case ((dy == 0) && (dx >= 0 && dx <= 4)):
        case ((dy == 1) && (dx >= 0 && dx <= 3)):
        case ((dy == 2) && (dx >= 0 && dx <= 2)):
        case ((dy == 3) && (dx >= 0 && dx <= 1)):
            hsv.h = 20; hsv.s = 36; hsv.v = 36;
            break;

        case ((dy == 0) && (dx >= 5 && dx <= 6)):
        case ((dy == 1) && (dx >= 4 && dx <= 5)):
        case ((dy == 2) && (dx >= 3 && dx <= 4)):
        case ((dy == 3) && (dx >= 2 && dx <= 3)):
            hsv.h = 355; hsv.s = 50; hsv.v = 100;
            break;

        case ((dy == 0) && (dx == 7)):
        case ((dy == 1) && (dx == 8)):
        case ((dy == 2) && (dx == 9)):
        case ((dy == 3) && (dx == 10)):
            hsv.h = 338; hsv.s = 47; hsv.v = 80;
            break;

        case ((dy == 0) && (dx <= 8)):
        case ((dy == 1) && (dx <= 9)):
        case ((dy == 2) && (dx <= 10)):
        case ((dy == 3) && (dx <= 11)):
            hsv.h = 201; hsv.s = 59; hsv.v = 50;
            break;
    }
    return hsv;
}

bool vilebloom(effect_params_t* params) {
    return effect_runner_dx_dy(params, &vilebloom_math);
}

#endif // RGB_MATRIX_CUSTOM_EFFECT_IMPLS
