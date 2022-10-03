#include "./header/header.h"
int	string_run(char *str);

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
