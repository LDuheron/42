

//// MORE INF 

int	is_between_for_inf(t_list **stack_a, int bvalue, int i)
{
	t_list	*tmp;
	int		j;

	j = 0;
	tmp = (*stack_a);
	while (j < i)
	{
		tmp = tmp->next;
		j++;
	}
	j = i;
	while ((bvalue > tmp->content)
		&& (bvalue < ft_lstlast(*stack_a)->content))
	{
		j++;
		tmp = tmp ->next;
	}
	return (j);
}

int	algoplus_inf1(t_list **stack_a, int bvalue, int j)
{
	t_list	*tmp;
	int		i;

	i = 0;
	tmp = (*stack_a);
	while (tmp->content > bvalue)
	{
		i++;
		if ((j == i && bvalue < tmp->next->content)
			&& (bvalue < ft_lstlast(*stack_a)->content))
		{
			while (bvalue > tmp->next->content)
			{
				i++;
				tmp = tmp->next;
			}
			return (i);
		}
		if (strlenlistparam(*stack_a) == i)
			return (0);
		tmp = tmp->next;
	}
	return (i);
}

int	algoplus_inf(t_list **stack_a, int bvalue, int j)
{
	t_list	*tmp;
	int		i;

	i = algoplus_inf1(stack_a, bvalue, j);
	tmp = (*stack_a);
	j = 0;
	while (tmp && j < i)
	{
		j++;
		tmp = tmp->next;
	}
	if ((bvalue > tmp->content)
		&& (bvalue < ft_lstlast(*stack_a)->content))
	{
		j = is_between_for_inf(stack_a, bvalue, i);
		return (j);
	}
	if (bvalue > tmp->content)
		return (0);
	return (j);
}

int	algoplus(t_list **stack_a, int bvalue)
{
	t_list	*tmp;
	int		i;
	int		j;

	j = lowest(stack_a);
	i = 0;
	tmp = (*stack_a);
	if (tmp->content > bvalue)
		i = algoplus_inf(stack_a, bvalue, j);
	else if (bvalue > tmp->content)
		i = algoplus_sup(stack_a, bvalue);
	return (i);
}

////MORE SUP 

int	get_to_max(t_list **stack_a)
{
	t_list	*tmp;
	int		i;
	int		max;

	max = rankmax(stack_a);
	i = 0;
	tmp = (*stack_a);
	while (tmp->content != max)
	{
		tmp = tmp->next;
		i++;
	}
	if (tmp->content > ft_lstlast(*stack_a)->content)
		i++;
	return (i);
}

int	algoplus_sup(t_list **stack_a, int bvalue)
{
	t_list	*tmp;
	int		i;
	int		j;

	i = 0;
	j = rankmax(stack_a);
	tmp = (*stack_a);
	while (tmp && bvalue > tmp->content)
	{
		i++;
		tmp = tmp->next;
	}
	if (bvalue > j && j > ft_lstlast(*stack_a)->content)
		return (get_to_max(stack_a));
	if (i == strlenlistparam(*stack_a))
		return (0);
	return (i);
}