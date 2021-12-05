MANDATORY_ROOT = mandatory
BONUS_ROOT = bonus

NAME = $(addprefix $(MANDATORY_ROOT)/, server client)
BONUS_NAME = $(addprefix $(BONUS_ROOT)/, server client)

$(NAME) :
	$(MAKE) -C $(MANDATORY_ROOT)  all

$(BONUS_NAME) : 
	$(MAKE) -C $(BONUS_ROOT) all

all : $(NAME)

bonus : $(BONUS_NAME)

clean :
	$(MAKE) -C $(MANDATORY_ROOT) clean
	$(MAKE) -C $(BONUS_ROOT) clean

fclean :
	$(MAKE) -C $(MANDATORY_ROOT) fclean
	$(MAKE) -C $(BONUS_ROOT) fclean

re : fclean all

re_bonus : fclean bonus

.PHONY : all bonus clean fclean re re_bonus