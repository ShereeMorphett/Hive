#include "libft.h"
//lst:  The address of a pointer to a node.
//del:  The address of the function used to delete the content of the node.


void ft_lstclear(t_list **lst, void (*del)(void *))
{
	while (lst)
	{
		(*del)((*lst)->content);
		lst = &(*lst)->next;
	}
	lst = NULL;
}