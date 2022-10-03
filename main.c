#include "./header/header.h"
int	string_run(char *str);
int	check_sp_ch(char c);

int	main(int argc, char** argv, char **envp)
{
	char *str = "hey bro! how are you?";
	(void)argc;
	(void)argv;
	(void)envp;
	printf("res = %d\n", string_run(str));
	return (0);
}

int	string_run(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		printf("%c", str[i]);
		i++;
	}
	printf("\n");
	return (i);
}

int	check_sp_ch(char c)
{
	if (c == COM)
		return (COMINT);
	else if (c == COM2)
		return (COM2INT);
	else if (c == PIPE)
		return (PIPEINT);
	else if (c == DEL)
		return (DELINT);
	else if (c == REDG || c == REDL)
		return (REDINT);
	return (0);
}


// avaliable types:
// '  -  comma				com
// "  -  double comma		com2
// |  -  pipe				pipe
// < > << >> - redirection	redir
// all other - words 		word