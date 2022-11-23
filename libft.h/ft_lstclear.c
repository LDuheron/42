void ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list *p;
	
	while (*lst)
	{
		p=(*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = p;
	}
}
