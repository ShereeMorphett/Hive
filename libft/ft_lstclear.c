#include "libft.h"
//lst:  The address of a pointer to a node.
//del:  The address of the function used to delete the content of the node.


void ft_lstclear(t_list **lst, void (*del)(void *))
{
		t_list *tmp;

	if (lst)
	{
		while (*lst)
		{
			tmp = (*lst)->next;
			ft_lstdelone(*lst, del);
			(*lst) = tmp;
		}
	}
}