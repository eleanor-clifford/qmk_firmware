#include QMK_KEYBOARD_H
#define _NORMAL 0

key_override_t override0 = ko_make_with_layers_and_negmods(MOD_MASK_SHIFT, UK_EXLM, UK_1, 1<<_NORMAL, MOD_MASK_CAG);
key_override_t override1 = ko_make_with_layers_negmods_and_options(MOD_MASK_CAG, UK_EXLM, UK_1, 1<<_NORMAL, 0, ko_options_default | ko_option_one_mod);
key_override_t override2 = ko_make_with_layers_and_negmods(MOD_MASK_SHIFT, S(UK_3), UK_3, 1<<_NORMAL, MOD_MASK_CAG);
key_override_t override3 = ko_make_with_layers_negmods_and_options(MOD_MASK_CAG, S(UK_3), UK_3, 1<<_NORMAL, 0, ko_options_default | ko_option_one_mod);
key_override_t override4 = ko_make_with_layers_and_negmods(MOD_MASK_SHIFT, UK_PERC, UK_5, 1<<_NORMAL, MOD_MASK_CAG);
key_override_t override5 = ko_make_with_layers_negmods_and_options(MOD_MASK_CAG, UK_PERC, UK_5, 1<<_NORMAL, 0, ko_options_default | ko_option_one_mod);
key_override_t override6 = ko_make_with_layers_and_negmods(MOD_MASK_SHIFT, UK_AMPR, UK_7, 1<<_NORMAL, MOD_MASK_CAG);
key_override_t override7 = ko_make_with_layers_negmods_and_options(MOD_MASK_CAG, UK_AMPR, UK_7, 1<<_NORMAL, 0, ko_options_default | ko_option_one_mod);
key_override_t override8 = ko_make_with_layers_and_negmods(MOD_MASK_SHIFT, UK_LBRC, UK_9, 1<<_NORMAL, MOD_MASK_CAG);
key_override_t override9 = ko_make_with_layers_negmods_and_options(MOD_MASK_CAG, UK_LBRC, UK_9, 1<<_NORMAL, 0, ko_options_default | ko_option_one_mod);
key_override_t override10 = ko_make_with_layers_and_negmods(MOD_MASK_SHIFT, UK_RBRC, UK_0, 1<<_NORMAL, MOD_MASK_CAG);
key_override_t override11 = ko_make_with_layers_negmods_and_options(MOD_MASK_CAG, UK_RBRC, UK_0, 1<<_NORMAL, 0, ko_options_default | ko_option_one_mod);
key_override_t override12 = ko_make_with_layers_and_negmods(MOD_MASK_SHIFT, UK_AT, UK_2, 1<<_NORMAL, MOD_MASK_CAG);
key_override_t override13 = ko_make_with_layers_negmods_and_options(MOD_MASK_CAG, UK_AT, UK_2, 1<<_NORMAL, 0, ko_options_default | ko_option_one_mod);
key_override_t override14 = ko_make_with_layers_and_negmods(MOD_MASK_SHIFT, UK_DLR, UK_4, 1<<_NORMAL, MOD_MASK_CAG);
key_override_t override15 = ko_make_with_layers_negmods_and_options(MOD_MASK_CAG, UK_DLR, UK_4, 1<<_NORMAL, 0, ko_options_default | ko_option_one_mod);
key_override_t override16 = ko_make_with_layers_and_negmods(MOD_MASK_SHIFT, UK_CIRC, UK_6, 1<<_NORMAL, MOD_MASK_CAG);
key_override_t override17 = ko_make_with_layers_negmods_and_options(MOD_MASK_CAG, UK_CIRC, UK_6, 1<<_NORMAL, 0, ko_options_default | ko_option_one_mod);
key_override_t override18 = ko_make_with_layers_and_negmods(MOD_MASK_SHIFT, UK_ASTR, UK_8, 1<<_NORMAL, MOD_MASK_CAG);
key_override_t override19 = ko_make_with_layers_negmods_and_options(MOD_MASK_CAG, UK_ASTR, UK_8, 1<<_NORMAL, 0, ko_options_default | ko_option_one_mod);
key_override_t override20 = ko_make_with_layers(MOD_MASK_SHIFT,UK_LPRN, UK_LBRC, 1<<_NORMAL);
key_override_t override21 = ko_make_with_layers(MOD_MASK_SHIFT,UK_RPRN, UK_RBRC, 1<<_NORMAL);
key_override_t override22 = ko_make_with_layers(MOD_MASK_SHIFT,UK_QUOT, UK_2, 1<<_NORMAL);

const key_override_t** key_overrides = (const key_override_t *[]){
	&override0,
	&override1,
	&override2,
	&override3,
	&override4,
	&override5,
	&override6,
	&override7,
	&override8,
	&override9,
	&override10,
	&override11,
	&override12,
	&override13,
	&override14,
	&override15,
	&override16,
	&override17,
	&override18,
	&override19,
	&override20,
	&override21,
	&override22,
	NULL
};
void key_overrides_extra_setup(void) {
	override0.suppressed_mods = MOD_MASK_SHIFT;
	override1.suppressed_mods = 0;
	override2.suppressed_mods = MOD_MASK_SHIFT;
	override3.suppressed_mods = 0;
	override4.suppressed_mods = MOD_MASK_SHIFT;
	override5.suppressed_mods = 0;
	override6.suppressed_mods = MOD_MASK_SHIFT;
	override7.suppressed_mods = 0;
	override8.suppressed_mods = MOD_MASK_SHIFT;
	override9.suppressed_mods = 0;
	override10.suppressed_mods = MOD_MASK_SHIFT;
	override11.suppressed_mods = 0;
	override12.suppressed_mods = MOD_MASK_SHIFT;
	override13.suppressed_mods = 0;
	override14.suppressed_mods = MOD_MASK_SHIFT;
	override15.suppressed_mods = 0;
	override16.suppressed_mods = MOD_MASK_SHIFT;
	override17.suppressed_mods = 0;
	override18.suppressed_mods = MOD_MASK_SHIFT;
	override19.suppressed_mods = 0;
	override20.suppressed_mods = 0;
	override21.suppressed_mods = 0;
	override22.suppressed_mods = 0;
}
