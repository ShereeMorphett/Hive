#include "libft.h"

//lst = the node to free
// del = the address of the function used to delete 


void ft_lstdelone(t_list *lst, void (*del)(void*))
{
	(*del)(lst->content);
	free(lst);
}