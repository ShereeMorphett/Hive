void	print_stack(t_stack *stack_data)
{
	int	index;

	index = 0;
	ft_printf("stack_a size is: %i \n", stack_data->size);
	while (index < stack_data->size)
	{
		ft_putnbr_fd(stack_data->a[index], 1);
		ft_putchar_fd('\n', 1);
		index++;
	}
	index = 0;
	ft_printf("stack_b size is: %i \n", stack_data->stack_b_size);
	while (index < stack_data->stack_b_size)
	{
		ft_putnbr_fd(stack_data->b[index], 1);
		ft_putchar_fd('\n', 1);
		index++;
	}
}