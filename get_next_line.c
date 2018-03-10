//
// Created by Nikolay MIZIN on 1/28/18.
//
#include "libft.h"

t_list *f_multi_fd(int fd, t_list *str) {
	t_list *newnode;

	while (fd != (int)str->content_size && str) {
		if (fd != (int)str->content_size && str->next == NULL) {
			newnode = ft_lstnew("", 1);
			newnode->content_size = fd;
			str->next = newnode;
		}
		str = str->next;
	}
	return (str);
}


int f_sm_init(t_list *push, char **line)
{
	char *t;
	char *p;

	if ((p = ft_strchr(push->content, '\n')) != NULL)
	{
		*p = '\0';
		*line = ft_strdup(push->content);
		t = push->content;
		push->content = ft_strdup(p + 1);
		ft_memdel((void **)&t);
		return (1);
	}
	return (0);
}

int f_read(char *new, int fd, t_list *push, char **line)
{
	int		rd;
	char	*str;

	while ((rd = read(fd, new, BUFF_SIZE)) > 0)
	{
		new[rd] = '\0';
		str = ft_strjoin(push->content, new);
		ft_memdel((void **)&push->content);
		push->content = str;
		if (f_sm_init(push, line) == 1)
			return (1);
	}
	return ((rd == -1) ? -1 : 0);
}

int get_next_line(const int fd, char **line)
{
	char				new[BUFF_SIZE + 1];
	static	t_list		*main;
	t_list				*push;


	if (!line || fd < 0 || fd > 4096)
		return (-1);
	if(!main)
		main = ft_lstnew("", fd);
	push = f_multi_fd(fd, main);
	if (f_read(new, fd, push, line) == 1)
		return (1);
	if (f_read(new, fd, push, line) == -1)
		return (-1);
	if (!push->content || !ft_strlen(push->content))
	{
		ft_strclr(*line);
		return (0);
	}
	if (f_sm_init(push, line) == 1)
		return (1);
	*line = ft_strdup(push->content);
	ft_memdel((void **)&push->content);
	return (1);
}
