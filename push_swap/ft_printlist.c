#include <stdlib.h>
#include <stdio.h>
#include "libft.h"

void	ft_printlist(t_list *list)
{
	while (list)
	{
		printf("%s", list->content);
		list = list->next;
	}
}
static void	ft_del(void *content)
{
	free(content);
}

t_list	*add_link(t_list *list, char *str)
{
t_list *temp;

temp = malloc(sizeof(t_list));
	
if (temp)
{
	temp->content = str;
	temp->next = list;
}
	return (temp);
}

int main(void)
{
	t_list	*list;
	
	list = ft_lstnew("things\n");
	list = add_link(list, "go\n");
	list = add_link(list, "here\n");
	printf("%i\n", ft_lstsize(list));

	ft_printlist(list);

	
}