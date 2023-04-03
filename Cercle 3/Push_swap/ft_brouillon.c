void	ft_sort_inf(t_list **stack_a, t_data *data)
{
	t_list	*tmp;
	int		i;

	i = 0;
	tmp = *stack_a;
	while (tmp->content > tmp->next->content)
	{
		ft_ra(stack_a, data);
		tmp = *stack_a;
		ft_sa(stack_a, data);
		tmp = *stack_a;
		i++;
	}
	while (i > 0)
	{
		ft_rra(stack_a, data);
		tmp = *stack_a;
		i--;
	}
}

void	ft_sort_sup2(t_list **stack_a, t_data *data)
{
	t_list	*tmp;
	t_list *tmp2;
	int		i;

	i = 0;
	tmp = *stack_a;
	tmp_
	while (tmp->content && tmp->content > tmp->next->content)
	{
		ft_rra(stack_a, data);
		tmp = *stack_a;
		ft_sa(stack_a, data);
		tmp = *stack_a;
		i++;
	}
	while (i > 0)
	{
		ft_ra(stack_a, data);
		tmp = *stack_a;
		i--;
	}
}


void	ft_sort_sup(t_list **stack_a, t_data *data)
{
	t_list	*tmp;
	int		i;

	i = 0;
	tmp = *stack_a;
	// ft_sa(stack_a, data);
	tmp = *stack_a;
	while (i < 2)
	{
		ft_rra(stack_a, data);
		tmp = *stack_a;
		ft_sa(stack_a, data);
		tmp = *stack_a;
		i++;
	}
	i++;
	while (i > 0)
	{
		ft_ra(stack_a, data);
		tmp = *stack_a;
		i--;
	}
}

void	insert_sort_five(t_list **stack_a, t_list **stack_b, t_data *data)
{
	t_list	*tmp;
	int		i;

	i = 0;
	ft_pa(stack_a, stack_b, data);
	tmp = *stack_a;
	if (ft_is_sorted(stack_a, data) == 0)
	{
		if (tmp->content == data->highest)
			ft_ra(stack_a, data);
		if (ft_find_rank_nb(data, tmp->content) < data->rank_m)
		{
			ft_sa(stack_a, data);
			if (ft_is_sorted(stack_a, data) == 0)
				ft_sort_inf(stack_a, data);
		}
		else
		{
			if (ft_is_sorted(stack_a, data) == 0)
				ft_sort_sup(stack_a, data);
		}
	}
}