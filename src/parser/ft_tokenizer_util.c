/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tokenizer_util.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikim3 <mikim3@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 13:51:56 by kshim             #+#    #+#             */
/*   Updated: 2022/12/28 16:49:47 by mikim3           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_tokenizer.h"

int	ft_is_quote(char cha)
{
	if (cha == '\'' || cha == '\"')
		return (BOOL_TRUE);
	return (BOOL_FALSE);
}

int	ft_can_become_operator(char diff_target, char cha, int *oper_len)
{
	if (diff_target != '|' && diff_target == cha)
	{
		(*oper_len)++;
		return (BOOL_TRUE);
	}
	return (BOOL_FALSE);
}

int	ft_is_operator(char cha)
{
	if (cha == '<' || cha == '>' || cha == '|')
		return (BOOL_TRUE);
	return (BOOL_FALSE);
}

void	ft_free_tokenizer_list_and_token(t_list **token_list, t_tkn **token, int procedure)
{
	if (*token_list != 0)
		ft_lstclear(token_list, &ft_free_a_token_list_content);
	if (procedure == TKN_TKNIZE_FAIL)
	{
		if (*token != 0)
			ft_free_a_token_list_content((void *)*token);
	}
	return ;
}

void	ft_free_a_token_list_content(void *target)
{
	t_tkn *token;

	token = (t_tkn *)target;
	if (token == 0)
		return ;
	if (token->type != TKN_NULL)
	{
		free(token->str);
		token->str = 0;
	}
	token->type = 0;
	free(token);
	token = 0;
	return ;
}