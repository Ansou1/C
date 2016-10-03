##
## Makefile for PiRaNhA in /home/cheval_y//Wolf3D
## 
## Made by franck chevallier
## Login   <cheval_y@epitech.net>
## 
## Started on  Thu Dec 13 09:27:33 2012 franck chevallier
## Last update Sun Jun  9 16:37:54 2013 jonathan racaud
##

NAME = rt

INC = ./includes/

DIR = ./sources/

DIR_LIB_FUNCTIONS = ./sources/lib_functions/

DIR_INTERSECTION = ./sources/intersection/

DIR_XML = ./sources/xml/

DIR_MLX_FUNCTIONS = ./sources/mlx_functions/

SRC 	= 	$(DIR)main.c \
		$(DIR)multi_thread.c \
		$(DIR)multi_thread_cpy_fcts.c \
		$(DIR)calc.c \
		$(DIR)lib2.c \
		$(DIR)rand.c \
		$(DIR)calc_light_vector.c \
		$(DIR)change_color.c \
		$(DIR)light.c \
		$(DIR)shadow.c \
		$(DIR)light_tools.c \
		$(DIR)lib.c \
		$(DIR)color_functions.c \
		$(DIR)vector_tools.c \
		$(DIR)do_rt.c \
		$(DIR)create_bmp_file.c \
		$(DIR)write_padding.c \
		$(DIR)find_intersection.c \
		$(DIR)create_video.c \
		$(DIR)video_copy.c \
		$(DIR_LIB_FUNCTIONS)manage_error.c \
		$(DIR_LIB_FUNCTIONS)my_getnbr.c \
		$(DIR_LIB_FUNCTIONS)my_putstr.c \
		$(DIR_LIB_FUNCTIONS)my_strlen.c \
		$(DIR_LIB_FUNCTIONS)my_strncmp.c \
		$(DIR_LIB_FUNCTIONS)my_strndup.c \
		$(DIR_INTERSECTION)calc_k.c \
		$(DIR_INTERSECTION)fill_result.c \
		$(DIR_INTERSECTION)inter_cone.c \
		$(DIR_INTERSECTION)inter_cylinder.c \
		$(DIR_INTERSECTION)inter_plan.c \
		$(DIR_INTERSECTION)inter_sphere.c \
		$(DIR_INTERSECTION)rotate.c \
		$(DIR_INTERSECTION)translate.c \
		$(DIR_XML)regex.c \
		$(DIR_XML)xml_stuff.c \
		$(DIR_XML)add_in_list.c \
		$(DIR_XML)cube.c \
		$(DIR_XML)conf_file.c \
		$(DIR_XML)elem_angle.c \
		$(DIR_XML)elem.c \
		$(DIR_XML)elem_bump.c \
		$(DIR_XML)elem_blur.c \
		$(DIR_XML)elem_rot.c \
		$(DIR_XML)elem_filter.c \
		$(DIR_XML)elem_video.c \
		$(DIR_XML)elem_threads.c \
		$(DIR_XML)elem_limit.c \
		$(DIR_XML)elem_bright.c \
		$(DIR_XML)elem_reflexion.c \
		$(DIR_XML)elem_spec.c \
		$(DIR_XML)elem_color.c \
		$(DIR_XML)elem_position.c \
		$(DIR_XML)elem_window.c \
		$(DIR_XML)elem_radius.c \
		$(DIR_XML)elem_anti_aliasing.c \
		$(DIR_XML)get_next_line.c \
		$(DIR_XML)my_epur_str.c \
		$(DIR_XML)pile.c \
		$(DIR_XML)xml.c \
		$(DIR_MLX_FUNCTIONS)manage_expose.c \
		$(DIR_MLX_FUNCTIONS)manage_key.c \
		$(DIR_MLX_FUNCTIONS)my_pixel_put_to_image.c

OBJ = $(SRC:.c=.o)

CFLAGS =   -ansi -W -Wall -Wextra -pedantic -I$(INC)

LIB =  -lm -L. -L. -lmlx_$(HOSTTYPE) -L/usr/lib64/X11 -lXext -lX11 -lpthread

all : $(NAME)

$(NAME) : $(OBJ)
	(cd minilibx; $(MAKE))
	cc -o $(NAME) $(OBJ) $(LIB) $(CFLAGS)
clean :
	(cd minilibx; $(MAKE) clean)
	rm -rf $(OBJ)

fclean: clean
	(cd minilibx; $(MAKE) fclean)
	rm -rf $(NAME) $(OBJ)

re: fclean all
