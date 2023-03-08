void quick_sort(t_stack *stack_data, int low, int high, char stack_name)
{
    int pivot;

    if (low < high)
    {
        pivot = partition(stack_data, low, high, stack_name);
        quick_sort(stack_data, low, pivot - 1, stack_name);
        quick_sort(stack_data, pivot + 1, high, stack_name);
    }
}

int partition(t_stack *stack_data, int low, int high, char stack_name)
{
    int pivot = stack_data->stack_a[high];
    int i = low - 1;
    int j;
	int temp;

    for (j = low; j <= high - 1; j++)
    {
        if (stack_data->stack_a[j] < pivot)
        {
            i++;
            temp = stack_data->stack_a[i];
            stack_data->stack_a[i] = stack_data->stack_a[j];
            stack_data->stack_a[j] = temp;
            if (stack_name == 'a')
                ft_putendl_fd("pb", 1);
            else
                ft_putendl_fd("pa", 1);
        }
    }
    temp = stack_data->stack_a[i + 1];
    stack_data->stack_a[i + 1] = stack_data->stack_a[high];
    stack_data->stack_a[high] = temp;
    if (stack_name == 'a')
        ft_putendl_fd("pb", 1);
    else
        ft_putendl_fd("pa", 1);
    return (i + 1);
}
