/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_token.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeyoon <jeyoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 17:37:09 by jeyoon            #+#    #+#             */
/*   Updated: 2022/06/26 00:55:31 by jeyoon           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

static int	add_quote_token(t_token_node **this_node, \
	int *idx, enum e_token_type type, char *line)
{
	char	quote;
	int		start;

	quote = line[*idx];
	(*this_node)->type = type;
	(*idx)++;
	start = *idx;
	while (line[*idx] != '\0' && line[*idx] != quote)
		(*idx)++;
	if (line[*idx] == '\0')
		return (parse_error(1));
	(*this_node)->token = ft_substr(line, start, *idx - start);
	return (TRUE);
}

static void	add_spacial_token2(t_token_node **this_node, enum e_token_type type)
{
	if (type == TO_REDIRIN)
		(*this_node)->token = ft_strdup("<");
	else if (type == TO_REDIROUT)
		(*this_node)->token = ft_strdup(">");
	else if (type == TO_HEREDOC)
		(*this_node)->token = ft_strdup("<<");
	else if (type == TO_APPEND)
		(*this_node)->token = ft_strdup(">>");
	else if (type == PIPE)
		(*this_node)->token = ft_strdup("|");
}

static int	add_spacial_token(t_token_node **token_head, \
	enum e_token_type type, int *idx, char *line)
{
	t_token_node	*this_node;
	int				temp;

	this_node = (t_token_node *)malloc(sizeof(t_token_node));
	if (this_node == NULL)
		return (FALSE);
	ft_memset(this_node, 0, sizeof(t_cmd_node));
	add_spacial_token2(&this_node, type);
	if (type == DQUOTE || type == QUOTE)
	{
		temp = *idx;
		if (add_quote_token(&this_node, idx, type, line) == FALSE)
		{
			free(this_node);
			this_node = 0;
			return (FALSE);
		}
		return (add_token(token_head, &this_node, type, temp));
	}
	else if (type == DOLLAR)
		this_node->token = ft_strdup("$");
	if (this_node->token == NULL)
		return (FALSE);
	return (add_token(token_head, &this_node, type, *idx));
}

static int	add_common_token(t_token_node **token_head, char *line, int *idx)
{
	t_token_node	*this_node;
	int				start;

	this_node = (t_token_node *)malloc(sizeof(t_token_node));
	if (this_node == NULL)
		return (FALSE);
	ft_memset(this_node, 0, sizeof(t_cmd_node));
	start = *idx;
	while (line[*idx] != '\0' && !(line[*idx] == ' ' || \
		line[*idx] >= 9 && line[*idx] <= 13) && \
		(get_token_type(line, *idx) == TO_COMMON))
		(*idx)++;
	this_node->token = ft_substr(line, start, (*idx - start));
	if (this_node->token == NULL)
		return (FALSE);
	return (add_token(token_head, &this_node, TO_COMMON, start));
}

int	make_token_list(t_token_node **token_head, char *line)
{
	int					idx;
	enum e_token_type	type;

	idx = 0;
	while (line[idx] != '\0')
	{
		while (line[idx] != '\0' && (line[idx] == ' ' || \
			line[idx] >= 9 && line[idx] <= 13))
			idx++;
		if (line[idx] == '\0')
			return (TRUE);
		type = get_token_type(line, idx);
		if (type == TO_APPEND || type == TO_HEREDOC)
			idx++;
		if (type != TO_COMMON)
		{
			if (add_spacial_token(token_head, type, &idx, line) == FALSE)
				return (FALSE);
			idx++;
		}
		else
			if (add_common_token(token_head, line, &idx) == FALSE)
				return (FALSE);
	}
	return (TRUE);
}
