/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikim3 <mikim3@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 12:17:03 by mikim3            #+#    #+#             */
/*   Updated: 2022/12/29 18:13:04 by mikim3           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// https://wiki.kldp.org/HOWTO/html/Adv-Bash-Scr-HOWTO/internal.html
// unset 명령어는 쉘 변수를 효과적으로 널(null)로 세트를 해서 그 변수를 지우는 효과를 가져옵니다. 이 명령어는 위치 매개변수에 대해서 동작하지 않는 것에 주의하세요.


//// unset 135  처럼 숫자일 때
// 인자로 숫자가 들어오면 "bash: unset: `인자': not a valid identifier" 라는 오류를 출력한다.
// 인자는 여러개가 들어갈 수 있는데 한개라도 오류가 뜨면 echo $?했을때 1이 출력된다. 다른 명령어도 마찬가지다.

// 문자로 줬을때 없는 환경변수여도 그녕 오류없이 정상실행된다.

// unset $6  처럼 숫자 넣은 것도 해줘야 되나??? 특이하게 ex)  bash-3.2$ unset $35 의 결과가 bash: unset: `5': not a valid identifier 이다, 즉 

#include "../../include/ft_minishell.h"

void	ft_unset(t_tree_cmd *cmd, t_list *env, t_pipe *pipe_value)
{
	int		index;
	char	*key;

	index = -1;
	if (cmd->cmd_argv[1] == NULL)
		return ;
	while (cmd->cmd_argv[++index])
	{
		key = cmd->cmd_argv[++index];  // unset a
		if (check_env_key(key)) // 인자값이 unset가능한 인자값 인가??
		{
			env_key_error(key); // 키를 찾을수 없을때 에러문 출력 ex) bash: unset: `c====': not a valid identifier
		}
		else
			unset_env(&env, key); //  unset실제로 하기 
	}
	g_exit_code = 0;
}
