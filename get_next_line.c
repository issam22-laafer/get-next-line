/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lissam <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 14:54:02 by lissam            #+#    #+#             */
/*   Updated: 2023/12/02 14:54:06 by lissam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *chayta(char *str)
{
	int i;
	int j;
	int lenght;
	char *lichat;

	if(!str)
		return (NULL);
	lenght = ft_strlen(str);
	i = 0;
	j = 0;
	while (str[i] != '\n')
		i++;
	i++;
	lichat = (char *)malloc(sizeof(char) * (lenght - i + 1));
	if (!lichat)
		return (NULL);
	while (str[i]!='\0')
	{
        lichat[j] = str[i];
        j++;
		i++;
    }
	lichat[j] = '\0';
	return lichat;
}
char *lighayban(char *str)
{
	int i;
	int j;
	char *the_line;

	if (!str)
		return (NULL);
	if(str[0] == '\n')
		return (ft_strdup("\n"));
	j = 0;
	while(str[j] != '\n')
		j++;
	the_line = malloc(j + 2);
	i = 0;
	while(str[i] != '\n')
	{
		the_line[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
	{
		the_line[i] = '\n';
		i++;
	}
	the_line[i] = '\0';
	return the_line;
}

char *next_line(int fd,char *str)
{
	char *line;
	int c;

	c = 1;
	line = malloc(BUFFER_SIZE + 1);
	if(!line)
		return (NULL);
	while(!ft_strchr(str,'\n') && c != 0)
	{
		c = read(fd,line,BUFFER_SIZE);
		if(c == -1)
		{
			free(line);
			free(str);
			return (NULL);
		}
		line[c] = '\0';
		str = ft_strjoin(str,line);
		if(!str)
			return (NULL);
	}
	free(line);
	return str;
}
char *get_next_line(int fd)
{
	static char *str;
	char *s;

	str = next_line(fd,str);
	if (!str)
		return (NULL);
	s = lighayban(str);
	str = chayta(str);
	return s;

}
int main()
{
	int fd;
	fd = open("issam.txt",O_RDONLY);
	printf("%s",get_next_line(fd));
	printf("%s",get_next_line(fd));
	printf("%s",get_next_line(fd));
	printf("%s",get_next_line(fd));
	printf("%s",get_next_line(fd));
	printf("%s",get_next_line(fd));
	printf("%s",get_next_line(fd));
	printf("%s",get_next_line(fd));
	printf("%s",get_next_line(fd));
	printf("%s",get_next_line(fd));
	printf("%s",get_next_line(fd));
	printf("%s",get_next_line(fd));
	printf("%s",get_next_line(fd));
	printf("%s",get_next_line(fd));
	printf("%s",get_next_line(fd));
	printf("%s",get_next_line(fd));
	printf("%s",get_next_line(fd));
	printf("%s",get_next_line(fd));
	return 0;
}