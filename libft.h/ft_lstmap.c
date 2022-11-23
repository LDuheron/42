t_list *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list *p;
	t_list	*tmp;
	t_list	*content;
	
	if (!tmp)
	{
		if (del)
			(*del)(content)
		ft_lstclear(&p, tmp);
		lst = lst->next;
	}
	return (p);
}
