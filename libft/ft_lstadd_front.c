#include "libft.h"


void ft_lstadd_front(t_list **lst, t_list *new)
{
	//*lst = malloc(sizeof(t_list));
	if (new)
	{
		new->content = new;
		new->next = *lst;
		}
}