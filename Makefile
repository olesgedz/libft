NAME=libft.a

CC=gcc

CFLAGS= -O3 -Wall -Wextra -Werror

INCLUDES = -I$(HEADERS_DIRECTORY)
HEADERS_LIST =libft.h

DIRECTORY =  $(shell pwd)
HEADERS_DIRECTORY = includes/
HEADERS = $(addprefix $(HEADERS_DIRECTORY), $(HEADERS_LIST))

SOURCES_DIRECTORY = sources/

SOURCES_LIST=ft_memset.c ft_bzero.c ft_memcpy.c  ft_memccpy.c \
ft_memmove.c ft_memchr.c ft_memcmp.c ft_memalloc.c \
ft_memdel.c \
ft_strlen.c ft_strdup.c ft_strcpy.c ft_strncpy.c ft_strcat.c ft_strncat.c \
ft_strlcat.c ft_strchr.c ft_strrchr.c ft_strstr.c ft_strnstr.c \
ft_strcmp.c ft_strncmp.c ft_atoi.c \
ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
ft_toupper.c ft_tolower.c \
 ft_strnew.c ft_strdel.c ft_strclr.c ft_striter.c ft_striteri.c \
ft_strmap.c ft_strmapi.c ft_strequ.c ft_strnequ.c ft_strsub.c ft_strjoin.c \
ft_strtrim.c ft_strsplit.c \
ft_itoa.c \
ft_putchar.c ft_putstr.c ft_putendl.c ft_putnbr.c ft_putchar_fd.c \
ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
ft_lstadd.c ft_lstdel.c ft_lstdelone.c ft_lstiter.c ft_lstmap.c ft_lstnew.c \
ft_lstprint.c ft_arraymax.c ft_arraymin.c ft_swap_int.c ft_arrayprint.c \
ft_arraysort.c ft_lstdel_u.c ft_lstdelmid.c ft_ptr_free.c get_next_line.c \
ft_printmap.c ft_2darrayclean.c ft_2darraynew.c ft_point_new.c ft_lstcount.c \
ft_lstrev.c ft_is_space.c ft_countwords.c ft_strnewch.c  ft_sign.c\
ft_stack_print.c ft_stack_create.c ft_stack_push.c ft_stack_pop.c\
ft_stack_peek.c ft_lst2w_pushback.c ft_lst2w_new.c ft_memprint.c\
ft_print_node.c ft_btree_create_node.c ft_btree_apply_prefix.c ft_btree_apply_infix.c\
ft_btree_apply_suffix.c ft_btree_insert_data.c ft_btree_search_item.c ft_btree_level_count.c\
ft_queue_push.c ft_queue_pop.c ft_btree_apply_by_level.c ft_btree_print.c ft_rb_node_create.c\
ft_rb_insert.c ft_rb_node_print.c ft_realloc.c\
vector_add.c vector_delete.c vector_free.c vector_get.c vector_init.c vector_set.c vector_total.c vector_resize.c

SOURCES = $(addprefix $(SOURCES_DIRECTORY), $(SOURCES_LIST))

OBJECTS_DIRECTORY = objects/
OBJECTS_LIST = $(patsubst %.c, %.o, $(SOURCES_LIST))
OBJECTS	= $(addprefix $(OBJECTS_DIRECTORY), $(OBJECTS_LIST))

# COLORS

CLEAR_LINE	:= \033[2K
BEGIN_LINE	:= \033[A
COL_END		:= \033[0m
COL_RED		:= \033[1;31m
COL_GREEN	:= \033[1;32m
COL_YELLOW	:= \033[1;33m
COL_BLUE	:= \033[1;34m
COL_VIOLET	:= \033[1;35m
COL_CYAN	:= \033[1;36m
COL_WHITE	:= \033[1;37m

PREC = echo -ne "\r [`expr $(CURRENT_FILES) '*' 100 / $(TOTAL_FILES)`%]"

TOTAL_FILES := $(shell echo $(SOURCES_LIST) | wc -w | sed -e 's/ //g')
CURRENT_FILES = $(shell find $(DIRECTORY)/objects/ -type f 2> /dev/null | wc -l | sed -e 's/ //g')

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJECTS_DIRECTORY) $(OBJECTS)
	@ar rc $(NAME) $(OBJECTS)
	@ranlib $(NAME)
	@echo "$(CLEAR_LINE)[`expr $(CURRENT_FILES) '*' 100 / $(TOTAL_FILES)`%] $(COL_BLUE)[$(NAME)] $(COL_GREEN)Finished compilation. Output file : $(COL_VIOLET)$(PWD)/$(NAME)$(COL_END)"

$(OBJECTS_DIRECTORY):
	@mkdir -p $(OBJECTS_DIRECTORY)
	@echo "$(NAME): $(GREEN)$(OBJECTS_DIRECTORY) was created$(RESET)"

$(OBJECTS_DIRECTORY)%.o : $(SOURCES_DIRECTORY)%.c $(HEADERS)
	@$(CC) $(FLAGS) -c $(INCLUDES) $< -o $@
	@echo "$(CLEAR_LINE)[`expr $(CURRENT_FILES) '*' 100 / $(TOTAL_FILES)`%] $(COL_BLUE)[$(NAME)] $(COL_GREEN)Compiling file [$(COL_VIOLET)$<$(COL_GREEN)].($(CURRENT_FILES) / $(TOTAL_FILES))$(COL_END)$(BEGIN_LINE)"

clean:
	@rm -rf $(OBJECTS_DIRECTORY)

nu:
	@echo -ne "\r [`expr $(CURRENT_FILES) '*' 100 / $(TOTAL_FILES)`%]"

test: $(NAME) main.c
	@gcc -g $(NAME) main.c -I$(HEADERS_DIRECTORY) -o test

fclean: clean
	@rm -f test
	@rm -f $(NAME)
	@echo "$(NAME): $(RED)$(LIBFT) was deleted$(RESET)"

re:
	@$(MAKE) fclean
	@$(MAKE) all
