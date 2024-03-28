int	ft_handle_pipe(char **line_ptr, t_token **token_list)
{
	if (!ft_strncmp(*line_ptr, "|", 1))
	{
		return (ft_append_separator(TOKEN_PIPE, line_ptr, token_list) && 1);
	}
	return (0);
}


// int	ft_handle_pipe(char **line_ptr, t_token **token_list)
// {
// 	if (!ft_strncmp(*line_ptr, "|", 1))
// 	{
// 		*line_ptr += 1;
// 		return (ft_append_separator(TOKEN_PIPE, line_ptr, token_list));
// 	}
// 	return (0);
// }
