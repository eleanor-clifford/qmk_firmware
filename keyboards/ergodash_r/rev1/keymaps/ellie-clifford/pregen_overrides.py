import sys
sys.stdout = open("overrides.c", "w")

num_sym_maps = [
	["UK_EXLM", "UK_1"],
	["S(UK_3)", "UK_3"],
	["UK_PERC", "UK_5"],
	["UK_AMPR", "UK_7"],
	["UK_LBRC", "UK_9"],
	["UK_RBRC", "UK_0"],
	["UK_AT",   "UK_2"],
	["UK_DLR",  "UK_4"],
	["UK_CIRC", "UK_6"],
	["UK_ASTR", "UK_8"],
]

num_sym_maps_size = len(num_sym_maps)

overrides = []
mods = []

for i in range(num_sym_maps_size):

	# ko_make_with_layers_and_negmods(
		# MOD_MASK_SHIFT, // If shift is pressed
		# num_sym_maps[i][0], num_sym_maps[i][1],
		# 1<<_NORMAL, // In normal typing mode
		# MOD_MASK_CAG // Not if anything else is pressed
	# ); num_sym_overrides[2*i].suppressed_mods = MOD_MASK_SHIFT;
	overrides.append(f"ko_make_with_layers_and_negmods(MOD_MASK_SHIFT, {num_sym_maps[i][0]}, {num_sym_maps[i][1]}, 1<<_NORMAL, MOD_MASK_CAG)")
	mods.append(f"override{2*i}.suppressed_mods = MOD_MASK_SHIFT;")

	# ko_make_with_layers_negmods_and_options(
		# MOD_MASK_CAG, // If any modifiers are pressed
		# num_sym_maps[i][0], num_sym_maps[i][1],
		# 1<<_NORMAL, // In normal typing mode
		# 0,
		# ko_options_default | ko_option_one_mod // Only require one modifier to be pressed
	# ); num_sym_overrides[2*i+1].suppressed_mods = 0;
	overrides.append(f"ko_make_with_layers_negmods_and_options(MOD_MASK_CAG, {num_sym_maps[i][0]}, {num_sym_maps[i][1]}, 1<<_NORMAL, 0, ko_options_default | ko_option_one_mod)")
	mods.append(f"override{2*i+1}.suppressed_mods = 0;")

overrides += [
		# results in curly since shift is pressed
		"ko_make_with_layers(MOD_MASK_SHIFT,UK_LPRN, UK_LBRC, 1<<_NORMAL)",
		"ko_make_with_layers(MOD_MASK_SHIFT,UK_RPRN, UK_RBRC, 1<<_NORMAL)",
		# results in " since shift is pressed
		"ko_make_with_layers(MOD_MASK_SHIFT,UK_QUOT, UK_2, 1<<_NORMAL)",
	]
mods += [
		f"override{len(overrides)-3}.suppressed_mods = 0;",
		f"override{len(overrides)-2}.suppressed_mods = 0;",
		f"override{len(overrides)-1}.suppressed_mods = 0;",
	]

print('#include QMK_KEYBOARD_H')
print('#define _NORMAL 0')
print()
for i,o in enumerate(overrides):
	print(f"key_override_t override{i} = {o};")

print("\nconst key_override_t** key_overrides = (const key_override_t *[]){")

for i in range(len(overrides)):
	print(f"\t&override{i},")

print("\tNULL\n};")

print("void key_overrides_extra_setup(void) {")
for m in mods:
	print(f'\t{m}')
print('}')
