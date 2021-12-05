CC = clang
RM = rm -f
CFLAGS = -I$(HEADERS_ROOT) -Wall -Wextra -Werror
SERVER_NAME = server
CLIENT_NAME = client
NAME = $(SERVER_NAME) $(CLIENT_NAME)

HEADERS_ROOT = includes
LIBS_ROOT = libs
OBJS_ROOT = objs
SRCS_ROOT = srcs
LIBFT_ROOT = $(join $(SRCS_ROOT)/, libft)
LIBFT_NAME = $(LIBFT_ROOT)/libft.a
FT_PRINTF_ROOT = $(join $(SRCS_ROOT)/, ft_printf)
FT_PRINTF_NAME = $(FT_PRINTF_ROOT)/libftprintf.a
CLIENT_SRCS_ROOT = $(join $(SRCS_ROOT)/, client)
SERVER_SRCS_ROOT = $(join $(SRCS_ROOT)/, server)
COMMON_SRCS_ROOT = $(join $(SRCS_ROOT)/, common)

vpath %.c $(CLIENT_SRCS_ROOT) $(SERVER_SRCS_ROOT) $(COMMON_SRCS_ROOT) $(HEADERS_ROOT)
vpath %.h $(HEADERS_ROOT)

CONSTANTS_HEADER = $(HEADERS_ROOT)/constants.h
COMMON_OBJS := crc.o utils.o
COMMON_OBJS := $(addprefix $(OBJS_ROOT)/, $(COMMON_OBJS))
SERVER_OBJS := message_list.o receive.o server.o
SERVER_OBJS := $(addprefix $(OBJS_ROOT)/, $(SERVER_OBJS))
CLIENT_OBJS := client.o send.o
CLIENT_OBJS := $(addprefix $(OBJS_ROOT)/, $(CLIENT_OBJS))

all : $(NAME)

$(OBJS_ROOT)/%.o : %.c %.h
	@echo "[-] compile $<"
	@$(CC) $(CFLAGS) -c -o $@ $<

$(LIBFT_NAME) :
	@echo "[-] build libft"
	@$(MAKE) -s -C $(LIBFT_ROOT) all
	
$(FT_PRINTF_NAME) :
	@echo "[-] build ft_printf"
	@$(MAKE) -s -C $(FT_PRINTF_ROOT) all

$(SERVER_NAME) : $(COMMON_OBJS) $(SERVER_OBJS) $(FT_PRINTF_NAME) $(CONSTANTS_HEADER)
	@echo "[-] build server"
	@$(CC) $(CFLAGS) -o $@ $(COMMON_OBJS) $(SERVER_OBJS) $(FT_PRINTF_NAME)

$(CLIENT_NAME) : $(COMMON_OBJS) $(CLIENT_OBJS) $(LIBFT_NAME) $(FT_PRINTF_NAME) $(CONSTANTS_HEADER)
	@echo "[-] build client"
	@$(CC) $(CFLAGS) -o $@ $(COMMON_OBJS) $(CLIENT_OBJS) $(LIBFT_NAME) $(FT_PRINTF_NAME)

clean :
	@echo "[-] remove minitalk objs"
	@$(RM) $(COMMON_OBJS) $(SERVER_OBJS) $(CLIENT_OBJS)
	@echo "[-] remove libft objs"
	@$(MAKE) -s -C $(LIBFT_ROOT) clean
	@echo "[-] remove ft_printf objs"
	@$(MAKE) -s -C $(FT_PRINTF_ROOT) clean

fclean : clean
	@echo "[-] remove minitalk binary"
	@$(RM) $(SERVER_NAME) $(CLIENT_NAME)
	@echo "[-] remove libft binary"
	@$(MAKE) -s -C $(LIBFT_ROOT) fclean
	@echo "[-] remove ft_printf binary"
	@$(MAKE) -s -C $(FT_PRINTF_ROOT) fclean

re : fclean all

.PHONY : all clean fclean re