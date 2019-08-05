FLAGS = -Wall -Werror -Wextra

all: depend push_swap checker

depend:
	@make re -C libft

push_swap:
	@$(CC) $(FLAGS)  ./push_swap.c ./shared/*.c ./algorithms/*.c ./libft/libft.a -I./includes -I./libft -o push_swap
	@echo "push_swap OK!"

checker:
	@$(CC) ./visualizer.c ./checker.c ./shared/*.c ./algorithms/*.c ./libft/libft.a -I./includes -I./libft -lncurses -o checker
	@echo "checker OK!"

fclean:
	@$(RM) ./checker
	@$(RM) ./push_swap
	@$(RM) ./libft/libft.a
clean: fclean

re: fclean all