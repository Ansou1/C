NAME =		rt

SRC =		src/main.c \
		src/math/cubique.c \
		src/math/quartique.c \
		src/math/torus.c \
		src/math/quadratique.c \
		src/math/resolve_quart.c \
		src/get_next_line.c \
		src/use_postfx.c \
		src/xml/init_rndms.c \
		src/xml/parse.c \
		src/xml/utils.c \
		src/xml/others.c \
		src/xml/model.c \
		src/xml/objects.c \
		src/xml/compute.c \
		src/xml/clean_dtree.c \
		src/xml/objects_add.c \
		src/xml/torus.c \
		src/postfx/neg.c \
		src/postfx/grey.c \
		src/postfx/blurr.c \
		src/postfx/hcont.c \
		src/postfx/crazy.c \
		src/postfx/chuck.c \
		src/postfx/decomp.c \
		src/postfx/posterisation.c \
		src/postfx/parse_image.c \
		src/math/cylinder.c \
		src/math/depth.c \
		src/math/model.c \
		src/math/model_tools.c \
		src/math/limits.c \
		src/math/cone.c \
		src/math/sphere.c \
		src/math/plan.c \
		src/math/cube.c \
		src/math/func.c \
		src/math/utils.c \
		src/math/base.c \
		src/math/fog.c \
		src/math/load_pcv.c \
		src/math/calc_utils.c \
		src/lights/light_listing.c \
		src/lights/soft_shadows.c \
		src/lights/reflexion.c \
		src/lights/transparency.c \
		src/lights/normal.c \
		src/lights/normal_utils.c \
		src/lights/phong.c \
		src/lights/normal_model.c \
		src/lights/normal_torus.c \
		src/textures/background.c \
		src/textures/mod_light.c \
		src/textures/calc_color.c \
		src/textures/generate.c \
		src/textures/perlin.c \
		src/obj_utils.c \
		src/color_utils.c \
		src/intersect_utils.c \
		src/render_calc.c \
		src/render_start.c \
		src/render_finish.c \
		src/display_init.c \
		src/parsing_obj_file/parsing_object.c \
		src/parsing_obj_file/get_point_token.c \
		src/parsing_obj_file/get_normal_token.c \
		src/parsing_obj_file/get_tri_list_token.c \
		src/parsing_obj_file/count_tabtab.c \
		src/parsing_obj_file/my_get_double.c \
		src/parsing_obj_file/is_num.c \
		src/parsing_obj_file/corrupt_file.c \
		src/parsing_obj_file/fill_triangle_in_list.c \
		src/parsing_obj_file/destroy_all.c \
		src/save_image/save_image.c \
		src/save_image/fill_header_bitmap.c \
		src/save_image/x_write.c \
		src/utils/copy_session.c \
		src/utils/str_to_wt.c \
		src/utils/x_strdup.c \
		src/utils/my_strlen.c \
		src/utils/print_error.c \
		src/utils/my_atoi.c \
		src/utils/mem.c \
		src/utils/err.c \
		src/photon_mapping/launch_photons.c \
		src/photon_mapping/fill_photon_map.c \
		src/photon_mapping/launch_from_light.c \
		src/photon_mapping/sort_tab.c \
		src/photon_mapping/create_kdtree.c \
		src/photon_mapping/get_nearest_photons.c \
		src/photon_mapping/get_illumination.c \
		src/multi_thread.c

OBJ =		$(SRC:.c=.o)

CFLAGS +=	-I/usr/X11/include -I./include/ -Wall -Wextra -ansi -pedantic -g3

LIB =		-L/usr/X11/lib -L./lib/ -lmlx -lXext -lX11 -lm -pthread

all:		$(NAME)

$(NAME):	$(OBJ)
	cc $(CFLAGS) -o $(NAME) $(OBJ) $(LIB)

clean:
	@rm -f $(OBJ)

fclean:		clean
	@rm -f $(NAME)

re:	fclean $(NAME)

.PHONY:		all re clean fclean
