NAME= minishell 
CC= gcc
CFLAGS = -Wall -Wextra -Werror -I/opt/homebrew/opt/readline/include
LDFLAGS = -L/opt/homebrew/opt/readline/lib
LIBS = -lreadline -lncurses

RM = rm -fr  

LIBFT= libft/libft.a

SRCS= test/funcs_testingprints.c src/main.c src/L0_Sig.c src/L1_Exp.c src/L2_Token.c src/L3_Parse.c src/L4_Redir.c src/L5_Exec.c src/L6_BuiltIns.c src/L6_Utils.c src/L9_ExitClean.c

OBJ= $(SRCS:.c=.o) 

CYAN = \033[0;96m
DEF_COLOR = \033[0;49m

all: $(NAME)

$(NAME) : $(OBJ) 
	@echo "$(CYAN) ☕ EXECUTING MINISHELL... ☕ $(DEF_COLOR)"
	make all -C libft
	make clean -C libft
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(LDFLAGS) $(LIBS) -o $(NAME)
	make clean
	clear
	./minishell
	@echo "$(CYAN) ✨ ¡SUCCESS! ✨ $(DEF_COLOR)"

clean:
	@echo "$(CYAN) 🍩 ¡INIT CLEAN! 🍩 $(DEF_COLOR)"
	$(RM) $(OBJ)
	make clean -C libft

fclean: clean
	@echo "$(CYAN) 🍩 CLEANED 🍩 $(DEF_COLOR)"
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re