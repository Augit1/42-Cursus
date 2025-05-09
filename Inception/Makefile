##########################################################
## Makefile

####################
## Rules

all:
	docker-compose -f srcs/docker-compose.yml up --build

clean:
	docker-compose -f srcs/docker-compose.yml down -v

fclean:
	docker-compose -f srcs/docker-compose.yml down --rmi all --volumes --remove-orphans

re: fclean all

.PHONY: all clean fclean re
